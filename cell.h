#ifndef CELL_H
#define CELL_H

#include <cstdint>

class Cell {
private:
	uint8_t xCoord; //cordinate x of the cell using 1 byte
	uint8_t yCoord; //coordinate y of the cell using 1 byte
	bool visited : 1; //1 bit for visited flag
	bool walkable : 1; //1 bit for walkable flag

public:
	//constructor to initialize the cell
	Cell(uint8_t x, uint8_t y) : xCoord(x), yCoord(y), visited(false), walkable(false) {}

	//getters for x and y coordinates
	uint8_t getX() const { return xCoord; }
	uint8_t getY() const { return yCoord; }

	//function to check if the cell has been visited
	bool isVisited() const { return visited; }

	//function to check if the cell is walkable(a.k.a not a wall)
	bool isWalkable() const { return walkable; }

	//setter for isWalkable flag
	void setWalkable(bool walk) { walkable = walk; }

	//setter for isVisited flag
	void setVisited(bool visit) { visited = visit; }
};

#endif
