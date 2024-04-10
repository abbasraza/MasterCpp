
#ifndef ARGVPARSER_H
#define ARGVPARSER_H
/*
The `Parser` class template is designed to provide a reusable command-line argument parser for a given configuration struct `ConfigStruct`.
It helps in parsing command-line arguments and populating the configuration struct with the provided values.

The main purpose of this class template is to simplify the process of handling command-line arguments and provide a consistent interface
for parsing and accessing the values. By using this class template, you can avoid writing repetitive code for argument parsing and focus
on the logic specific to your application.

To use the `Parser` class template, you need to provide the `ConfigStruct` type as a template parameter. This struct should contain
the necessary fields to store the parsed values from the command-line arguments.

The `Parser` class template provides the following functionality:

1. Parsing command-line arguments: It uses the `getopt_long` function to parse the command-line arguments based on the provided options
and arguments. It iterates over the arguments and calls the corresponding parser/assigner function based on the option.

2. Generating the optstring: The `getOptString` function generates the optstring required by the `getopt_long` function based on the
options defined in the `s_long_options` array.

3. Printing usage information: The `usage` function prints the usage information, including the executable name, options, and their
corresponding documentation strings. It is called when there is an error in parsing the arguments or when the user requests the usage information.

4. File stat failure handling: The `usageIfFileStatFailure` function checks if a specified file exists using the `stat` function.
If the file doesn't exist, it prints an error message and calls the `usage` function.

To use this class template, you need to define the `s_long_options` array, which contains the long options and their corresponding
short options, argument requirements, and assigner functions. You also need to define the `s_argumentsAndDocStrings` array, which
contains the documentation strings for each option.

By using this `Parser` class template, you can easily handle command-line arguments in a reusable and consistent manner, making
your code more maintainable and easier to understand.
*/
#include <string> // std::string
#include <cstdio>
#include <stdint.h>
#include <getopt.h> // struct option
#include <cstdlib>	// exit()
#include <errno.h>
#include <string.h> // strerror

// Uncomment this to cause ctor to print out config structure elements after parsing and exit()
// #define DEBUG_COMMAND_LINE_OPTIONS

namespace Util
{
	template <class ConfigStruct>
	class Parser
	{
	public:
		Parser(int argc, char *argv[]);
		ConfigStruct getConfig() const { return m_config; };

	private:
		std::string getOptString();
		void usage();
		void usageIfFileStatFailure(const std::string &filename);
		void parseCommandLineParams(int argc, char *argv[]);
		ConfigStruct m_config;
		std::string m_execName;
		static struct option s_long_options[];
		static std::string s_argumentsAndDocStrings[][2];
		static bool (*s_assignFuncs[])(char *, ConfigStruct *); // OMG, s_assignFuncs is an array of pointers to function taking char* and ConfigStruct* returning bool
	};
	template <class ConfigStruct>
	Parser<ConfigStruct>::Parser(int argc, char *argv[])
		: m_config(),
		  m_execName(argv[0])
	{
		// strip basename from argv[0] to get executable name
		m_execName = m_execName.substr(m_execName.find_last_of('/') + 1);

		parseCommandLineParams(argc, argv);

#ifdef DEBUG_COMMAND_LINE_OPTIONS
		m_config.print();
		exit(0);
#endif
	}
	// forms optstring to be used in getopt_long() call, based on values in static s_long_options structure
	template <class ConfigStruct>
	std::string Parser<ConfigStruct>::getOptString()
	{
		std::string optstring;
		for (uint32_t i = 0; i < sizeof(s_long_options) / sizeof(struct option); ++i)
		{
			optstring += s_long_options[i].val;
			if (s_long_options[i].has_arg == required_argument)
				optstring += ":";
			else if (s_long_options[i].has_arg == optional_argument)
				optstring += "::";
		}
		return optstring;
	}
	// prints usage string and exits. Usage string is based on values in static variables s_long_options and argumentsAndDocStrings
	template <class ConfigStruct>
	void Parser<ConfigStruct>::usage()
	{
		printf("\n%s - Main Application for first-class Labrinth devices.\n", m_execName.c_str());
		printf("USAGE:\n\t%s [OPTION]...\n", m_execName.c_str());
		printf("OPTIONS:\n");
		printf("\tMandatory Options to long options are mandatory for short options too.\n\n");
		for (uint32_t i = 0; i < (sizeof(s_long_options) / sizeof(struct option)) - 1; ++i)
		{
			printf("\t-%c, --%s%s\n%s", s_long_options[i].val, s_long_options[i].name, s_argumentsAndDocStrings[i][0].c_str(), s_argumentsAndDocStrings[i][1].c_str());
		}
		exit(0);
	}
	// helper func to stat a file and call usage() if the specified file doesn't exist
	template <class ConfigStruct>
	void Parser<ConfigStruct>::usageIfFileStatFailure(const std::string &filename)
	{
		struct stat stFileInfo;
		int statResult = stat(filename.c_str(), &stFileInfo);
		if (0 != statResult)
		{
			printf("could not stat %s\n", filename.c_str());
			printf(" (reason = %s)\n", strerror(errno));
			usage();
		}
	}
	template <class ConfigStruct>
	void Parser<ConfigStruct>::parseCommandLineParams(int argc, char *argv[])
	{
		// parse command line args to determine simulation parameters
		while (1)
		{
			int option_index = 0;
			int opt = getopt_long(argc, argv, getOptString().c_str(), s_long_options, &option_index);
			if (opt == -1)
				break;

			// Find index into arrays in order to call parser/assigner function
			int index = -1;
			for (uint32_t i = 0; i < (sizeof(s_long_options) / sizeof(struct option)) - 1; ++i)
			{
				if (opt == s_long_options[i].val)
				{
					index = i;
					break;
				}
			}
			// Call parser/assigner func if found
			if (index >= 0 && s_assignFuncs[index])
			{
				bool ok = s_assignFuncs[index](optarg, &m_config);
				if (!ok)
					usage();
			}
			// If none found, default behavior:
			else
				usage();
		}

		if (optind < argc)
		{
			usage();
		}
	}
} // namespace Util

#endif // ARGVPARSER_H
