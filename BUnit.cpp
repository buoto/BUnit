#include "BUnit.h"

TestCase::TestCase(void (TestCase::*name)()) {
    this->name = name;
}

void TestSuite::add(TestCase* test) {
    this->tests.push_back(test);
}

int TestSuite::run() {
    int failedCounter = 0;
    for(auto it = this->tests.begin();
        it != this->tests.end(); it++) {

        try {
            (*it)->run();
            std::cout << '.';
        } catch (FailedAssertError* e) {
            std::string testName = parseTestName(e->function);
            std::cerr << std::endl << "\e[97m\e[41m[FAILED]\e[0m " << testName
                << " [" << e->file << ":" << e->line << "]" << std::endl
                << "\t" << e->condition << std::endl;
            ++failedCounter;
        }
    }

    if(failedCounter) {
        std::cerr << std::endl << "\e[97m\e[41m" << failedCounter << " test(s) failed\e[0m" << std::endl;
        return failedCounter;
    } else {
        std::cout << std::endl << "\e[97m\e[42mAll tests passed.\e[0m" << std::endl;
        return 0;
    }
}

std::string TestSuite::parseTestName(const std::string& prettyFunction) {
    size_t colons = prettyFunction.find("::");
    size_t begin = prettyFunction.rfind(' ', colons) + 1;
    size_t end = prettyFunction.rfind('(') - begin;

    return prettyFunction.substr(begin, end);
};
