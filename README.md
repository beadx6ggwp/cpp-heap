# C++ Heap with Gitflow Practice

This project implements a flexible C++ Heap (Max-Heap/Min-Heap) with a customizable comparison function, designed for practicing Git, Gitflow, unit testing with Google Test, and CI/CD with GitHub Actions.

## Project Goals
- Implement a templated C++ Heap with operations (`push`, `pop`, `top`, etc.).
- Practice Gitflow workflow using Git CLI (feature branches, hotfixes, conflict resolution).
- Write unit tests using Google Test.
- Set up CI/CD with GitHub Actions.

## Prerequisites
- **Git**: For version control.
- **CMake**: Version 3.14 or higher.
- **C++ Compiler**: Supporting C++17 (e.g., GCC, Clang, MSVC).
- **Optional for Windows**: MSYS2 or WSL for a Unix-like environment.

## Setup Instructions
1. **Clone the Repository**:
   ```bash
   git clone <repository-url>
   cd cpp-heap
   ```

2. **Create Build Directory**:
   ```bash
   mkdir build
   cd build
   ```

3. **Configure with CMake**:
   ```bash
   cmake ..
   ```
   - This automatically downloads Google Test.
   - On Windows, use `cmake -G "MSYS Makefiles" ..` if using MSYS2.

4. **Build the Project**:
   ```bash
   make
   ```
   - On Windows with MSVC, use `cmake --build .`.

5. **Run Tests**:
   ```bash
   ctest
   ```
   - Or run the test executable directly: `./test_heap`.

## Project Structure
```
cpp-heap/
├── include/
│   └── heap.hpp        # Heap header
├── src/
│   └── heap.cpp        # Heap implementation
├── tests/
│   └── test_heap.cpp   # Unit tests
├── .github/
│   └── workflows/ci.yml # GitHub Actions CI
├── CMakeLists.txt       # CMake configuration
├── README.md            # This file
└── .gitignore           # Git ignore file
```

## Gitflow Workflow
- **Branches**:
  - `main`: Production-ready code.
  - `develop`: Integration branch for new features.
  - `feature/*`: New features (e.g., `feature/add-logging`).
  - `hotfix/*`: Urgent fixes for `main`.
- **Development Process**:
  1. Create a feature branch:
     ```bash
     git checkout develop
     git branch feature/<feature-name>
     git checkout feature/<feature-name>
     ```
  2. Commit changes:
     ```bash
     git add .
     git commit -m "Implement <feature-name>"
     ```
  3. Push and create a Pull Request:
     ```bash
     git push origin feature/<feature-name>
     ```
  4. Merge to `develop` after review:
     ```bash
     git checkout develop
     git merge feature/<feature-name>
     git push origin develop
     ```
- **Conflict Resolution**:
  - If a merge conflict occurs, edit the conflicting files, then:
    ```bash
    git add .
    git commit
    ```

## Running Tests
- Tests are written using Google Test and located in `tests/`.
- After building, run:
  ```bash
  ctest
  ```
  or `ctest -C Debug --rerun-failed --output-on-failure`
- Add new tests in `tests/test_heap.cpp`.

## CI/CD
- **GitHub Actions**: Automatically builds and runs tests on pushes to `main` or `develop`, and on Pull Requests.
- Check the "Actions" tab in the GitHub repository for CI results.

## Contributing
1. Fork or clone the repository.
2. Create a feature branch following the Gitflow workflow.
3. Write code or tests, ensuring all tests pass (`ctest`).
4. Submit a Pull Request to `develop` with a clear description.
5. Resolve any conflicts during PR review.

## Troubleshooting
- **CMake Errors**: Ensure CMake 3.14+ is installed and your compiler supports C++17.
- **Google Test Not Found**: The `FetchContent` module downloads it automatically; check your internet connection.
- **Windows Issues**: Use MSYS2 or WSL for a smoother experience.

For questions, contact the team or open an issue on GitHub.
