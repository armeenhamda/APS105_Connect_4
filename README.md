# Connect Four C Implementation
A modular, terminal-based implementation of the classic Connect Four game. This project demonstrates core systems-level programming in C, including 2D matrix manipulation, pointer-based state management, automated build systems via Make, and robust win-condition algorithms for grid-based environments.

# Project Overview
This implementation features a 6x6 game arena where two players (Red and Yellow) compete to align four tokens. The program utilizes a coordinate-based input system with real-time validation to ensure game integrity. It is designed to be lightweight, cross-platform, and easily extensible for future AI or network-based modules.

# Features
| Feature | Description |
|:---|:---|
| **Dual-Player Mode** | Local turn-based gameplay between Red (R) and Yellow (Y) |
| **Dynamic Win Logic** | Robust checking for horizontal, vertical, and diagonal (both axes) connections |
| **Input Validation** | Handles out-of-bounds indices and prevents overflows in full columns |
| **Grid Rendering** | Real-time terminal board updates after every successful move |
| **State Persistence** | Uses a 2D character array to maintain board integrity across turns |
| **Automated Build** | Custom Makefile configuration for streamlined compilation on Unix-like systems |

## Technical Specifications

### Development Environment

| Parameter | Specification |
|:---|:---|
| **Language** | C (C11 Standard) |
| **Compiler** | GCC |
| **Build Tool** | Make |
| **Target OS** | macOS / Linux / Windows (via MinGW) |
| **Grid Size** | 6 rows × 6 columns |
| **Memory Model** | Static stack allocation for board state |

### Compilation and Execution

The project includes a `Makefile` to simplify the build process.

```bash
# To compile the project
make

# To execute the game
./connect4

# To clean build files
make clean
```

## Future Enhancements

- **Artificial Intelligence**: Implement a Minimax algorithm for single-player mode.
- **Dynamic Sizing**: Allow users to define custom row/column counts at runtime.
- **GUI Integration**: Transition from terminal-based UI to a graphical interface using GTK-3.
- **Persistent Stats**: Save win/loss records to a local `.txt` file.
- **Color Support**: Use ANSI escape codes to render tokens in actual red and yellow text in the terminal.

## References

- [C11 Standard Documentation](https://www.iso.org/standard/74528.html)
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)
- [University of Toronto - Engineering Standards](https://www.engineering.utoronto.ca/)

## License

This project was developed for educational purposes as part of first-year engineering coursework at the University of Toronto.
