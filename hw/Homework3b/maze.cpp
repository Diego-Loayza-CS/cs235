#include <iostream>
using std::cout, std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream, std::ofstream;

#include "Grid.h"

bool find_maze_path(Grid& grid, int row, int col, int level, vector<vector<int>>& solution) {
    if (row < 0 || col < 0 || level < 0 || row >= grid.height() || col >= grid.width() || level >= grid.depth()) {
        return false;
    }

    if (grid.at(row, col, level) != 1) {
        return false;
    }

    vector<int> coords = {row, col, level};
    solution.push_back(coords);

    if (row == grid.height()-1 && col == grid.width()-1 && level == grid.depth()-1) {
        return true;
    }

    grid.at(row, col, level) = 2;

    if (find_maze_path(grid, row + 1, col, level, solution) ||
            find_maze_path(grid, row - 1, col, level, solution) ||
            find_maze_path(grid, row, col + 1, level, solution) ||
            find_maze_path(grid, row, col - 1, level, solution) ||
            find_maze_path(grid, row, col, level + 1, solution) ||
            find_maze_path(grid, row, col, level - 1, solution)) {
        return true;
    }
    else {
        solution.pop_back();
        return false;
    }


}



int main(int argc, char* argv[]) {
    Grid maze;
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    in >> maze;
    vector<vector<int>> path;

    if (find_maze_path(maze, 0, 0, 0, path)) {
        out << "SOLUTION" << endl;
        for (const auto& coords : path) {
            out << coords[0] << " " << coords[1] << " " << coords[2] << endl;
        }
    } else {
        out << "NO SOLUTION" << endl;
    }



    return 0;
}
