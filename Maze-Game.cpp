#include <iostream>
#include <cstdint>
#include <vector>
#include <stack>
#include <ctime>

#include "Maze.h"

int main(void) {
	Maze m = Maze(21);  // Use an odd number for better maze generation
	m.generateMaze(1, 1);  // Start at (1, 1)
	m.display();
	return 0;
}
