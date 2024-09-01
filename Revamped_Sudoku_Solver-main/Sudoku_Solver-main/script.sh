rm *.o
rm *exe
g++ -c main.cpp
g++ -c valid.cpp
g++ -c ConvertToExactCover.cpp
g++ -c DLX.cpp
g++ -c print_sol.cpp
g++ -o sudoku_exe main.o valid.o ConvertToExactCover.o DLX.o print_sol.o
./sudoku_exe
