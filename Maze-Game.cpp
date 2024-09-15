#include <iostream>
#include <cstdint>
#include <vector>

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
	bool isWalkable() const { return isWalkable; }

	//setter for isWalkable flag
	void setWalkable(bool walk) { walkable = walk; }

	//setter for isVisited flag
	void setVisited(bool visit) { visited = visit; }

};

class Maze {
private:
	uint8_t size; //size of the maze using 1 bit
	std::vector<std::vector<Cell>> maze; //2D grid of cell objects

public:
	//constructor to initialize the maze
	Maze(uint8_t s) : size(s) {
		//initialize the maze with cells
		for (uint8_t i = 0; i < size; i++) {
			std::vector<Cell> row;
			for (uint8_t j = 0; j < size; j++) { row.push_back(Cell(i, j)); }
			maze.push_back(row);
		}
	}

	void display() {
		for (uint8_t i = 0; i < size; i++) {
			for (uint8_t j = 0; j < size; j++) {
				std::cout << (maze[i][j].isWalkable() ? " " : "#");
			}
		}
	}

	//getter for the size of the maze
	uint8_t getSize() const { return size; }
};

int main(void) {
	Cell c = Cell(1, 1); // Initialize the Cell object
	std::cout << (int)c.getX() << " " << (int)c.getY();
	Maze m = Maze(9);
	std::cout << (int)m.getSize();
	return 0;
}