#ifndef BUNIT_H 
#define BUNIT_H

#include<iostream>
#include<cassert>
#include<vector>


class TestCase{
	protected:
		void (TestCase::*name)();
	    TestCase() { }
   
    public:
		TestCase(void (TestCase::*name)()) {
			this->name = name;
		}

        virtual void setUp(){}
		
		virtual void run() {
			this->setUp();
			(this->*name)();
			this->tearDown();
		}

		virtual void tearDown() {}
		virtual ~TestCase() {}
};

typedef void (TestCase::*CallbackType)();

class TestSuite : TestCase {
    protected:
        std::vector<TestCase*> tests;
    public:
        TestSuite() {}
        void add(TestCase* test) {
            this->tests.push_back(test);
        }
        
        void run() {
            for(auto it = this->tests.begin(); 
                it != this->tests.end(); it++) {
                (*it)->run();
            }
            std::cout << "All tests passed." << std::endl;
        }
};

#endif
