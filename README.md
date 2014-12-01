[BUnit](http://github.com/buoto/BUnit)
=====
Ultra lightweight testing environment inspired by XUnit example from Kent's Beck "TDD" book.

#Installation
To install library simply type `sudo make install`.

#Usage

    #include <bunit/BUnit.h>

    class FooTestCase : public TestCase {
        private:
            void setUp() {
                // stuff done before test
            }
            void tearDown() {
                // stuff done after test
            }

        public:
            CLASSNAME(FootestCase)

            void barMethod() {
                // stuff
                assert(foo == bar);
            }

    }

    TESTS
    ADD(FooTestCase, barMethod)
    RUN

Remember to add `-lbunit` to your compile flags.

#Contents
- BUnit.h - header including test classes
- test.cpp - usage example
