# Contributing to ML Embedded Library

Thank you for your interest in contributing to the ML Embedded Library! We welcome all contributions, whether they are bug fixes, new features, documentation improvements, or anything else.

## How to Contribute

1. **Fork the repository**:
   - Go to the [repository page](https://github.com/<your-username>/my_ml_embedded_library).
   - Click the "Fork" button in the top-right corner.

2. **Clone your fork**:
   ```bash
   git clone https://github.com/<your-username>/my_ml_embedded_library.git
   cd my_ml_embedded_library
   ```

3. **Create a new branch**:
   Use a descriptive branch name related to your contribution:
   ```bash
   git checkout -b feature/your-feature-name
   ```

4. **Make your changes**:
   - Add or modify code in the appropriate files.
   - Write unit tests for new features or fixes.
   - Ensure all tests pass using `make` and `./test_*` executables.

5. **Commit your changes**:
   ```bash
   git add .
   git commit -m "Description of your changes"
   ```

6. **Push to your fork**:
   ```bash
   git push origin feature/your-feature-name
   ```

7. **Submit a Pull Request**:
   - Go to the original repository on GitHub.
   - Click "New Pull Request" and choose your branch.
   - Provide a clear description of the changes you've made.

## Guidelines for Contributions

- **Code Quality**: Follow the coding standards used in the repository (C++11, clear comments, modular structure).
- **Testing**: Ensure that all new code is covered by unit tests.
- **Documentation**: Update the `README.md` or other documentation files if your changes affect usage.
- **Discussions**: Use GitHub Discussions or Issues to discuss major changes before implementation.

Thank you for contributing!