# cpptools
General tools written in C++

The project structure here was chosen to follow the Unix Filesystem Hierarchy
Standard [FHS](https://refspecs.linuxfoundation.org/FHS_3.0/fhs/index.html).

- bin - Generated executable files.
- build - Object files generated from source.
- include - Header files for corresponding project source code files.
- lib - Compiled library files from project and third party (vendor) source.
- share - Shared data (architecture-independent), includes documentation.
- src - Project source code.
- test - Testing files for source code.
- vendor - Third party (non standard) libraries source code (git submodules).

# Convention and style
The stylistic approach here is taken from the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html),
while coding implementation and convention is take from the
[C++ Core Guidelines](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines). Also included here is the C++ linter from the [Google C++ style guide Github repo](https://github.com/google/styleguide/tree/gh-pages/cpplint) cpplint.py.

# Build system
This repository uses GNU make to compile source and tests. The make targets try
to follow the standard target conventions laid out by the
[GNU Coding Standards](https://www.gnu.org/prep/standards/html_node/Standard-Targets.html).

## Clone and set-up.
```
git clone https://github.com/dclark87/cpptools
git submodule update --init
```

## Make and test
`make clean test`