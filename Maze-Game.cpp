#include <iostream>
#include <cstdint>
#include <vector>
#include <stack>
#include <ctime>

#include "Maze.h"

int main() {
	Maze m(21);  // Create a 21x21 maze
	srand(time(0));  // Seed for randomness
	m.generateMaze(1, 1);  // Generate maze starting from (1, 1)

	// Solve the maze from the top-left (1, 1) to the bottom-right (19, 19)
	if (m.solveMaze(1, 1, 19, 19)) {
		std::cout << "Maze Solved!" << std::endl;
	}
	else {
		std::cout << "No solution found." << std::endl;
	}

	m.display();  // Display the maze with the solution path
	return 0;
}