# Sudoku Solver using DLX Algorithm

This project implements a Sudoku solver using the Dancing Links (DLX) algorithm. The DLX algorithm is used to efficiently solve the exact cover problem, which is applied here to solve Sudoku puzzles.

## Project Structure

The project consists of the following files:

- `exactcover.cpp`: Converts the Sudoku grid into an exact cover matrix.
- `dlx.cpp`: Implements the DLX algorithm, including search and covering/uncovering operations.
- `node.cpp`: Defines the `Node` and `Column_Node` classes used in the DLX algorithm.
- `print_sol.cpp`: Contains the function to print out the solution(s) to the Sudoku puzzle.
- `valid.cpp`: Checks whether a given Sudoku puzzle is valid.
- `main.cpp`: The main file that ties everything together, handling input and output.

## Dependencies

This project is written in C++ and requires a C++ compiler like `g++`. Additionally, the code includes standard libraries such as `<vector>`, `<iostream>`, and `<unordered_map>`.

## How to Compile and Run

1. **Create a Shell Script:**

   A shell script `script.sh` is used to compile and run the project. 

   ```bash
   #!/bin/bash

   # Compile all the files
   g++ -o sudoku_solver main.cpp exactcover.cpp dlx.cpp node.cpp print_sol.cpp valid.cpp

   # Run the compiled program
   ./sudoku_solver
