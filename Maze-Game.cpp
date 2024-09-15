#include <iostream>
#include <cstdint>
#include <vector>

class Cell {
private:
	uint8_t xCoord;

	uint8_t yCoord;

	bool isVisited;

	bool isWalkable;

public:
	Cell(uint8_t x, uint8_t y) : xCoord(x), yCoord(y), isVisited(false), isWalkable(false) {}

	uint8_t getX() const { return xCoord; }

	uint8_t getY() const { return yCoord; }

	bool isVisited() const { return isVisited; }

	bool isWalkable() const { return isWalkable; }
};

class Maze {
private:
	uint8_t size;

	std::vector<std::vector<Cell>> maze;

public:
	Maze(uint8_t s) : size(s) {}

	uint8_t getSize() const { return size; }
};

int main(void) {
	Cell c = Cell(1, 1); // Initialize the Cell object
	std::cout << (int)c.getX() << " " << (int)c.getY();
	Maze m = Maze(9);
	std::cout << (int)m.getSize();
	return 0;
}