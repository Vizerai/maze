#ifndef MAZE_H
#define MAZE_H

#include <memory>
#include <vector>
#include <unordered_map>

#include <gtkmm/application.h>
#include <gtkmm/window.h>

#include "cellborder.h"
#include "cellmap.h"
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
  
  std::vector<int> cells_;
  CellMap cellmap_;

 protected:
  virtual std::tuple<double, double, double, double> GetCoordinateBounds()
      const = 0;
};

#endif // MAZE_H
