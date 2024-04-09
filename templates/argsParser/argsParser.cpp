/**
 * @file argsParser.cpp
 * @brief This file contains the implementation of a template class `Util::Parser` and its usage in the `main` function.
 * 
 * The `Util::Parser` template class is used for command line parameter parsing. It provides a convenient way to define and parse command line options.
 * 
 * The `UnitTestConfig` struct holds the configuration for the command line parameters. It contains a `tests` string and a vector of `testnames`.
 * 
 * The `Util::Parser` template class is specialized for the `UnitTestConfig` struct. It defines the long options and their corresponding short options, as well as the argument strings and documentation strings for each option.
 * 
 * The `parseTests` function is a helper function used to parse the `tests` option. It assigns the option value to the `tests` member of the `config` object and also populates the `testnames` vector by tokenizing the option value.
 * 
 * The `testUnits` function is a thread function that takes a `thread_args` object as an argument. It prints the command line parameters stored in the `cmdLineParams` member of the `thread_args` object.
 * 
 * The `main` function creates an instance of the `Util::Parser` class and parses the command line arguments. It then creates a thread and passes the `UnitTestConfig` object as an argument to the `testUnits` function.
 * 
 * @note This code assumes the presence of the `ArgvParser.h` header file.
 */
#include <cstdio>       // printf and ilk for cmd line param parsing
#include <cstdlib>      // exit()
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <memory>       // std::unique_ptr
#include <ctime>
#include <stdlib.h>     // system(), rand_r
#include <time.h>       // std::ctime(), et al
#include "ArgvParser.h"
#include <vector>

#include <iostream>

struct UnitTestConfig;
struct thread_args
{
	char * name;
	UnitTestConfig *cmdLineParams;
};

//-----------------------------------------------------------------------------
// Stuff for command line parameters and ArgvParser template.
// Arrays must be in corresponding order; see ArgvParser.cpp for details.
struct UnitTestConfig
{
	UnitTestConfig()
    : tests("")
    {}
    void print() {
        printf("CommandLineParams:\n");
        printf("\ttests = %s\n", tests.c_str());
    }
    std::string tests;
    std::vector<std::string> testnames;
};

// format is {long-option-name, [required_argument, optional_argument, no_argument], 0, single-letter-option-character}
template <>
struct option Util::Parser<UnitTestConfig>::s_long_options[] = {
    {"tests", required_argument, 0, 't'},
    {0, 0, 0, 0}
};

// format is {argument-string-to-appear-after-param-name, documentation-string}
template <>
std::string Util::Parser<UnitTestConfig>::s_argumentsAndDocStrings[][2] = {
    {"=TEST_NAMES", "\t\t run the specified top-level tests. Use double-quotes and space, tab, or comma separation for multiple tests, e.g. ""-t BosFastTestSuite BlockTestSuite""\n\n"},
};

static bool parseTests( char* optionVal, UnitTestConfig* config )
{
    std::cout << __func__ << std::endl;
    config->tests.assign(optionVal);

    // Parse the options using strtok, we need to make a copy because this will modify the string
    std::unique_ptr<char[]> tokens = std::make_unique<char[]>( strlen(optionVal) + 1 );
    strcpy(tokens.get(), optionVal);
    char* nextToken = strtok(tokens.get(), "\t ,");
    while(nullptr != nextToken) {
        config->testnames.push_back(nextToken);
        nextToken = strtok(nullptr, "\t ,");
    }

    return true;
}
// Format is a series of C-style functions which handle parsing/assigning a particular option.
// Order counts - order must match previous arrays
template <>
bool (*Util::Parser<UnitTestConfig>::s_assignFuncs[])(char*,UnitTestConfig*) = {parseTests};

void *testUnits(void *vargs)
{
    thread_args * args = static_cast<thread_args *>(vargs);
    args->cmdLineParams->print();

}

int main(int argc, char *argv[]) {
	Util::Parser<UnitTestConfig> parser(argc, argv);
	UnitTestConfig cmdLineParams = parser.getConfig();

	pthread_t tUnitTests;
    char name[] = "UnitTest thread";
    thread_args args = {name, &cmdLineParams};
    if (pthread_create(&tUnitTests, NULL, testUnits, &args) != 0)
    {
        // Failed to create the thread.
        return -1;
    }

    int retval;
    pthread_join(tUnitTests, (void **)&retval);
    return retval;
}
