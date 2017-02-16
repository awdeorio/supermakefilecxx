# supermakefilecxx
A flexible Makefile for C++ programs, including testing, debugging, leak checking, profiling, and coverage.

Andrew DeOrio <awdeorio@umich.edu>

# Quickstart
Download the latest version of this `Makefile` into your own project:
```
wget --no-check-certificate https://raw.githubusercontent.com/awdeorio/supermakefilecxx/master/Makefile -O Makefile
make test
```

A few assumptions to check:
- All files are in one directory
- Top level application is in `main.cpp`
- Unit tests are in `*test*.cpp`
- System tests (diff tests) input files are `*.in` and output files are `*.out.correct`
- Custom tests are `*test*.sh`

# Published examples
Download a copy of the repository and try it out using provided C++ source code.
```
wget --no-check-certificate https://github.com/awdeorio/supermakefilecxx/tarball/master -O master.tar.gz
tar -xvzf master.tar.gz
cd awdeorio-supermakefilecxx-<COMMIT_HASH>/
make test
```

# Usage
Build the top level executable
```
make
```

Regression testing
```
make unittest                   # Run unit tests
make systemtest                 # Run system tests
make customtest                 # Run custom tests
make test                       # Run regression (unit, system and custom) tests
make Forward_list_test.out      # Run one unit test
less Forward_list_test.out      # See output of one unit test 
make test00.diff.txt            # Run one system test
less test00.out                 # See output of one system test
less test00.diff.txt            # See differences from one system test
```

Debugging
```
make clean                      # Remove files built without debug flags
make debug Forward_list_test    # Build one unit test with debug flags
gdb Forward_list_test           # Debug one unit test
make debug main                 # Build "main" application with debug flags
gdb main                        # Debug "main" application
make debug test                 # Run regression test with debug flags
```

Faster compilation using parallel processes, works with any call to make.  This command will run all tests using 4 parallel processes.
```
make -j4 test
```

Checking for memory leaks
```
make clean
make valgrind test
make valgrind test00.valgrind.out
less test00.valgrind.out
make valgrind Forward_list_test.valgrind.out
less Forward_list_test.valgrind.out
```

Profiling
```
make clean
make profile test00.out
less analysis.txt
make profile test00.out test01.out  # Don't do this
make profile Forward_list_test      # Don't do this
```

Coverage
```
make coverage test00.out
make coverage Forward_list_test
make coverage test
make coverage unittest
```

Distribution
```
make distclean
make dist
```

Customizing the compiler from the shell.  This code assume bash shell.
```
CXX=g++-5.1 make                                            # One time
export CXX=g++-5.1                                          # Until you log out
echo "export CXX=g++-5.1" >> ~/.bashrc && source ~/.bashrc  # Forever
```
