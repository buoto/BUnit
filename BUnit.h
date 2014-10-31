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
		TestCase(void (TestCase::*name)());

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
        void add(TestCase* test);
        void run();

};

#endif
