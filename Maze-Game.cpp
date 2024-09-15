#include <iostream>
#include <cstdint>

class Cell {
private:
	uint8_t xCoord;

	uint8_t yCoord;

public:
	void setCoords(uint8_t x, uint8_t y) { xCoord = x; yCoord = y; }

	uint8_t getX() const { return xCoord; }

	uint8_t getY() const { return yCoord; }
};

int main(void) {
	Cell c = Cell(); // Initialize the Cell object
	c.setCoords(1, 1);
	std::cout << (int)c.getX();
	return 0;
}