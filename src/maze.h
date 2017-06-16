#ifndef MAZE_H
#define MAZE_H

#include <memory>
#include <vector>

#include <gtkmm/application.h>
#include <gtkmm/window.h>

#include "cellborder.h"
#include "minimumspanningtreealgorithm.h"

class Maze {
 public:
  Maze(int = 0, int = 0, int = 1);
  void GenerateMaze(MinimumSpanningtreeAlgorithm*);
  void PrintMazeGnuplot(const std::string&) const;
  void PrintMazeSVG(const std::string&) const;
  void RemoveBorders(const std::vector<std::pair<int, int>>&);
  virtual void InitializeGraph() = 0;

  // Solving a maze is equivalent to finding a path in a graph
  int vertices_;
  int startvertex_, endvertex_;
  std::vector<std::vector<std::pair<int, std::shared_ptr<CellBorder>>>> adjacencylist_;
  
  std::vector<int> cells;
  unordered_map<int, std::vector<int>> cellmap;

 protected:
  virtual std::tuple<double, double, double, double> GetCoordinateBounds()
      const = 0;
};

#endif // MAZE_H
