#include "cellmap.h"

void CellMap::DrawEdge(int x1, int y1, int x2, int y2, const Cairo::RefPtr<Cairo::Context> &cr) {
	cr->move_to(x1*40 + 70, y1*40 + 70);
	cr->line_to(x2*40 + 70, y2*40 + 70);
}