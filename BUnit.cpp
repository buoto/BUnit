#include "BUnit.h"

TestCase::TestCase(void (TestCase::*name)()) {
    this->name = name;
}

void TestSuite::add(TestCase* test) {
    this->tests.push_back(test);
}

void TestSuite::run() {
    for(auto it = this->tests.begin();
        it != this->tests.end(); it++) {
        (*it)->run();
    }
    std::cout << "All tests passed." << std::endl;
}

