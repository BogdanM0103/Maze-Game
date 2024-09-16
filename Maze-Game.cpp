#include <iostream>
#include <cstdint>
#include <vector>
#include <stack>

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

	//get unvisited neighbors of a cell
	std::vector<Cell*> getUnvisitedNeighbors(uint8_t x, uint8_t y) {
		std::vector<Cell*> neighbors;
		if (x > 1 && !maze[y][x - 2].isVisited()) neighbors.push_back(&maze[y][x - 2]);  // Left
		if (x < size - 2 && !maze[y][x + 2].isVisited()) neighbors.push_back(&maze[y][x + 2]);  // Right
		if (y > 1 && !maze[y - 2][x].isVisited()) neighbors.push_back(&maze[y - 2][x]);  // Up
		if (y < size - 2 && !maze[y + 2][x].isVisited()) neighbors.push_back(&maze[y + 2][x]);  // Down
		return neighbors;
	}

	//remove wall between 2 cells
	void removeWall(Cell& current, Cell& neighbor) {
		uint8_t x1 = current.getX();
		uint8_t x2 = neighbor.getX();
		uint8_t y1 = current.getY();
		uint8_t y2 = neighbor.getY();

		//coords of the wall
		uint8_t wallX = (x1 + x2) / 2;
		uint8_t wallY = (y1 + y2) / 2;

		maze[wallX][wallY].setWalkable(true);
	}

	void generateMaze(uint8_t startX, uint8_t startY) {
		//initialize all cells first as walls
		for (uint8_t i = 0; i < size; i++) {
			for (uint8_t j = 0; j < size; j++) {
				maze[i][j].setWalkable(false);
			}
		}

		//stack for holding cells
		std::stack<Cell*> stack;

		//initialize starting cell for generation
		Cell& start = maze[startX][startY];
		start.setWalkable(true);
		start.setVisited(true);
		stack.push(&start);

		//maze generation loop
		while (!stack.empty()) {
			//get current cell
			Cell* current = stack.top();
			//get current cell's neighbors
			std::vector<Cell*> neighbors = getUnvisitedNeighbors(current->getX(), current->getY());

			//if there are uninvisited neighbors
			if (!neighbors.empty()) {

			}
			else {//if there are no unvisited neighbors, go back
				stack.pop();
			}
		}
	}

	//display function that does what it says
	void display() {
		for (uint8_t i = 0; i < size; i++) {
			for (uint8_t j = 0; j < size; j++) {
				std::cout << (maze[i][j].isWalkable() ? " " : "#");
			}
			std::cout << std::endl;
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