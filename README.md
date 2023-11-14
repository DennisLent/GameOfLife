# Game of Life

This project implements Conway's Game of Life, a cellular automaton devised by the mathematician John Conway. The game consists of a grid of cells where each cell can be in one of two possible states, alive or dead, based on simple rules.

## Getting Started

### Prerequisites

- C Compiler (e.g., GCC)
- SDL2 Library

### Building and Running

1. Clone the repository:

    ```bash
    git clone git@github.com:DennisLent/GameOfLife.git
    ```

2. Navigate to the project directory:

3. Make a build folder and build the project:

    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

4. Run the executable inside the build folder:

    ```bash
    ./GameOfLife -d <dimension> -p <pattern>
    ```

   Replace `<dimension>` with the desired grid size and `<pattern>` with the pattern path (located in the `files` directory).
   **Example:** ```./GameOfLife -d 100 -p "../files/corder.lif"```

## Patterns

Place pattern files (`.lif`) in the `files` directory to load different initial configurations.
