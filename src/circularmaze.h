#ifndef CIRCULARMAZE_H
#define CIRCULARMAZE_H

#include "maze.h"

class CircularMaze : public Maze {
 public:
  CircularMaze(int);
  virtual void InitializeGraph();

 protected:
  int size_;
  std::vector<int> ringnodecount_, ringnodeprefixsum_;

  std::tuple<double, double, double, double> GetCoordinateBounds() const;
};

#endif /* end of include guard: CIRCULARMAZE_H */
