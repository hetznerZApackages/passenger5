/*
 * This is a simple program for executing either one of the Ruby versions installable
 * by APT. This is necessary because Debian 6 and Debian 8 (among others) do not install
 * /usr/bin/ruby upon installing one of the versioned Ruby packages (e.g. apt-get
 * install ruby2.1). Commands such as 'passenger-status' are supposed to be run under
 * the system Ruby interpreter, but we can't just set the shebang line to
 * '#!/usr/bin/ruby'. This problem is solved by setting the shebang line to
 * '#!/usr/bin/passenger_system_ruby'.
 *
 * Unlike passenger_free_ruby, passenger_system_ruby doesn't use the 'ruby'
 * in PATH. This is because tools like 'passenger-status' behave the same
 * no matter which Ruby version is used (e.g. they don't depend on
 * user-installed gems or user-provided code), so there is no reason to
 * allow them to be run under arbitrary Ruby interpters. We run a well-known
 * Ruby version in order to reduce risk: the arbitrary user-installed version
 * might be broken.
 */

#define PROGRAM_NAME "passenger_system_ruby"
#include "passenger_ruby_utils.c"

int
main(int argc, const char *argv[]) {
			try_exec("/usr/bin/ruby1.8", argc, argv);
			try_exec("/usr/bin/ruby1.9.1", argc, argv);
			try_exec("/usr/bin/ruby2.0", argc, argv);
			try_exec("/usr/bin/ruby2.1", argc, argv);
			try_exec("/usr/bin/ruby2.2", argc, argv);
			try_exec("/usr/bin/ruby2.4", argc, argv);
			try_exec("/usr/bin/ruby2.5", argc, argv);
			try_exec("/usr/bin/ruby2.6", argc, argv);
			try_exec("/usr/bin/ruby2.7", argc, argv);
			try_exec("/usr/bin/ruby2.8", argc, argv);
			try_exec("/usr/bin/ruby2.9", argc, argv);
			try_exec("/usr/bin/ruby2.3", argc, argv);
	
	fprintf(stderr, "passenger_system_ruby: cannot find suitable Ruby interpreter\n");
	return 1;
}
