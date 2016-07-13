# lowertriad

lowertriad is a game IDE attempt.

unlike most game IDEs, this one uses C++ for scripting, and compiles games using CMake and a C++ compiler.

## Dependencies
SDL2 (2.0.4) and SDL2_ttf

CMake 2.8 or later

Visual Studio 2015 or later (on Windows)

## Compiling
### Linux and OS X
install dependencies, then clone this repository and
```
mkdir build
cd build
cmake ..
make
```

### Windows

#### Warning: Due to asprintf (and Microsoft's compiler), Windows is not supported. Maybe next week.

install CMake and Visual Studio 2015, then clone this repository and
```
mkdir build
cd build
cmake ..
```

then open resulting solution in VS and Build > Build Solution.
