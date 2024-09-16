#ifndef MAZE_H
#define MAZE_H

#include <cstdint>
#include <stack>
#include <vector>

#include "Cell.h"

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
			for (uint8_t j = 0; j < size; j++) { row.push_back(Cell(j, i)); }
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

		maze[wallY][wallX].setWalkable(true); // Corrected the order to [y][x]
	}

	void generateMaze(uint8_t startX, uint8_t startY) {
		//initialize all cells first as walls
		for (uint8_t i = 0; i < size; i++) {
			for (uint8_t j = 0; j < size; j++) {
				maze[i][j].setWalkable(false);
			}
		}

		//this makes the maze random each time you run the program
		srand(time(0));

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
				//random unvisited neighbor
				Cell* neighbor = neighbors[rand() % neighbors.size()];

				removeWall(*current, *neighbor);

				neighbor->setVisited(true);
				neighbor->setWalkable(true);

				stack.push(neighbor);
			}
			else {//if there are no unvisited neighbors, go back
				stack.pop();
			}
		}

		//unvisiting the cells to prepare for solving
		for (uint8_t i = 0; i < size; i++) {
			for (uint8_t j = 0; j < size; j++) {
				if (maze[j][i].isWalkable()) {
					maze[j][i].setVisited(false);
				}
			}
		}
	}

	bool isValidMove(uint8_t x, uint8_t y) {
		return (x < size && y < size && maze[y][x].isWalkable() && !maze[y][x].isVisited());
	}

	bool solveMaze(uint8_t currentX, uint8_t currentY, uint8_t endX, uint8_t endY) {
		//if we reached destination cell
		if (currentX == endX && currentY == endY) {
			maze[currentY][currentX].setVisited(true);
			return true;
		}

		//set current cell as visited
		maze[currentY][currentX].setVisited(true);

		//find neighbors
		if (isValidMove(currentX + 1, currentY) && solveMaze(currentX + 1, currentY, endX, endY))
			return true;
		if (isValidMove(currentX - 1, currentY) && solveMaze(currentX - 1, currentY, endX, endY))
			return true;
		if (isValidMove(currentX, currentY + 1) && solveMaze(currentX, currentY + 1, endX, endY))
			return true;
		if (isValidMove(currentX, currentY - 1) && solveMaze(currentX, currentY - 1, endX, endY))
			return true;

		//if no valid positions, backtrack
		maze[currentY][currentX].setVisited(false);
		return false;
	}

	//display function that does what it says
	void display() {
		for (uint8_t i = 0; i < size; i++) {
			for (uint8_t j = 0; j < size; j++) {
				if (maze[i][j].isVisited()) { std::cout << "."; }
				else
					std::cout << (maze[i][j].isWalkable() ? " " : "#");
			}
			std::cout << std::endl;
		}
	}

	//getter for the size of the maze
	uint8_t getSize() const { return size; }
};
#endif
