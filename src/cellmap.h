#ifndef CELLMAP_H
#define CELLMAP_H

#include <cairomm/context.h>

class CellMap {
public:
	CellMap(const std::unordered_map<int, std::vector<int>> &map) : map_(map) {}

	void DrawEdge(int x1, int y1, int x2, int y2, const Cairo::RefPtr<Cairo::Context> &cr);
	const std::unordered_map<int, std::vector<int>>& Map() { return map_; }

private:
	std::unordered_map<int, std::vector<int>> map_;
};

#endif