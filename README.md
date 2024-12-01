# Algorithm and Data Structures Course

This repository contains practical implementations and examples used in the Algorithm and Data Structures course. All code is implemented in modern C++23 to leverage the latest language features and best practices.

## Technical Requirements

- Modern C++ compiler with C++23 support:
  - GCC 13.0 or higher
  - Clang 16.0 or higher
  - MSVC 19.35 or higher
- Meson build system (version 1.0.0 or higher)
- Ninja build backend

## Compilation Options

### 1. Local Development with Meson (Recommended)

To build any section of the course:
1. Install Meson and a compatible C++ compiler
2. Clone this repository
3. Navigate to any section's directory
4. Compile:
   ``` meson build -C .\builddir```
   where the `builddir` is the build directory.
5. To run, go to the build directory and execute the executables.

### 2. Using web compiler

Copy the code and run it on web compiler.

## License

This project is licensed under the MIT-NC License - see the [LICENSE](LICENSE) file for details.
This means you can freely use and modify the code for non-commercial purposes.
