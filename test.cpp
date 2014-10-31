#include"BUnit.h"

class WasRun : public TestCase {
		bool wasRun;
		bool wasSetUp;
		bool wasTearDown;
	public:
		WasRun(void (WasRun::*name)())
		: TestCase(static_cast<void (TestCase::*)()>(name)) {
			wasSetUp = false;
		}
		
		void testMethod() {
			wasRun = true;
		}
		
		void setUp(){
			wasSetUp = true;
			wasRun = false;
			wasTearDown = false;
		}

		void tearDown() {
			wasTearDown = true;
		}

		bool getWasRun() {
			return wasRun;
		}
		
		bool getWasSetUp() {
			return wasSetUp;
		}

		bool getWasTearDown() {
			return wasTearDown;	
		}
};

class TestCaseTest : public TestCase {
	private:
		WasRun* test;

		void setUp() {
			test = new WasRun(&WasRun::testMethod);	
		}
		
		void tearDown(){
			delete(test);
		}		
	public:
		TestCaseTest(void (TestCaseTest::*name)()) 
		: TestCase(static_cast<void (TestCase::*)()>(name)) {
		}
		
		void testRunning() {
			assert(false == test->getWasRun());
			test->run();
			assert(true == test->getWasRun());
		}

		void testSetUp() {
			test->run();
			assert(true == test->getWasSetUp());
		}
		void testTearDown() {
			test->run();
			assert(true == test->getWasTearDown());
		}

};




int main() {
    TestSuite suite;
    suite.add(new TestCaseTest(&TestCaseTest::testSetUp));
    suite.add(new TestCaseTest(&TestCaseTest::testTearDown));
    suite.run();
    return 0;
}
