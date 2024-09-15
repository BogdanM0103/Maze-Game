#include <iostream>
#include <cstdint>
#include <vector>

class Cell {
private:
	uint8_t xCoord;

	uint8_t yCoord;

public:
	Cell(uint8_t x, uint8_t y) : xCoord(x), yCoord(y) {}

	uint8_t getX() const { return xCoord; }

	uint8_t getY() const { return yCoord; }
};

class Maze {

};

int main(void) {
	Cell c = Cell(1, 1); // Initialize the Cell object
	std::cout << (int)c.getX() << " " << (int)c.getY();
	return 0;
}