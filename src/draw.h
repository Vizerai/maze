#ifndef GTKMM_EXAMPLE_DRAW_H
#define GTKMM_EXAMPLE_DRAW_H

#include <gtkmm/drawingarea.h>

#include "cellborder.h"

class MyArea : public Gtk::DrawingArea
{
public:
  MyArea() {}
  MyArea(int vertices, int startvertex, int endvertex, const std::vector<std::vector<std::pair<int, std::shared_ptr<CellBorder>>>> *adjacencylist) 
  		: vertices_(vertices), startvertex_(startvertex), endvertex_(endvertex), adjacencylist_(adjacencylist) {}
  virtual ~MyArea() {}

  void UpdateCellPath(const std::unordered_map<int, std::vector<int>> &cellmap);

  int vertices_;
  int startvertex_;
  int endvertex_;
  const std::vector<std::vector<std::pair<int, std::shared_ptr<CellBorder>>>> *adjacencylist_;
  std::unordered_map<int, std::vector<int>> cellmap_;

protected:
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

#endif // GTKMM_EXAMPLE_DRAW_H