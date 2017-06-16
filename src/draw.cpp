#include "draw.h"
#include <cairomm/context.h>

bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  // coordinates for the center of the window
  // int xc, yc;
  // xc = width / 2;
  // yc = height / 2;

  cr->set_line_width(7.5);
  cr->set_source_rgb(0.0, 0.0, 0.0); 

  for (int i = 0; i < vertices_; ++i) {
    for (const auto& edge : (*adjacencylist_)[i]) {
      if (edge.first < i) {
      	edge.second->DrawBorder(cr);
      }
    }
  }
  cr->stroke();

  return true;
}