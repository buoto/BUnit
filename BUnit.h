#ifndef BUNIT_H
#define BUNIT_H

#define CLASSNAME(x) x(void (x::*name)()) : TestCase(static_cast<void (TestCase::*)()>(name)) { }

#define TESTS int main() { TestSuite suite;
#define ADD(cl, t) suite.add(new cl(&cl::t));
#define RUN return suite.run();}

#define assert(x) this->assert_(x, #x, __PRETTY_FUNCTION__, __FILE__, __LINE__)

#include<iostream>
#include<vector>

struct FailedAssertError {
    std::string condition;
    std::string function;
    std::string file;
    int line;
};

class TestSuite;

class TestCase {
    friend class TestSuite;

    protected:
        void (TestCase::*name)();
        TestCase() { }

    public:
        TestCase(void (TestCase::*name)());

        virtual void setUp(){}

        virtual void run() {
            this->setUp();
            (this->*name)();
            this->tearDown();
        }

        virtual void tearDown() {}
        virtual ~TestCase() {}

    protected:
        virtual void assert_(bool cond, std::string condStr, std::string prettyFunction, std::string file, int line) {
            if(!cond) {
                throw new FailedAssertError{condStr, prettyFunction, file, line};
            }
        }
};

typedef void (TestCase::*CallbackType)();

class TestSuite {
    protected:
        std::vector<TestCase*> tests;
    public:
        TestSuite() {}
        void add(TestCase* test);
        int run();
    private:
        std::string parseTestName(const std::string& prettyFunction);

};

#endif
