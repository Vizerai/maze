#include <cstring>
#include <iostream>
#include <map>
#include <string>

#include <gtkmm/application.h>
#include <gtkmm/window.h>

#include "draw.h"
#include "breadthfirstsearch.h"
#include "circularhexagonmaze.h"
#include "circularmaze.h"
#include "depthfirstsearch.h"
#include "hexagonalmaze.h"
#include "honeycombmaze.h"
#include "kruskal.h"
#include "rectangularmaze.h"

int main(int argc, char** argv)
{
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

	Gtk::Window win;
	win.set_title("DrawingArea");
	win.set_default_size(1024,1024);

	Maze *maze;
	MinimumSpanningtreeAlgorithm *algorithm;
	maze = new RectangularMaze(20,20);
	algorithm = new Kruskal;
    // algorithm = new DepthFirstSearch;
    // algorithm = new BreadthFirstSearch;

	std::cout << "Initialising graph..." << std::endl;
	maze->InitializeGraph();
	std::cout << "Generating maze..." << std::endl;
	maze->GenerateMaze(algorithm);

	MyArea area(maze->vertices_, maze->startvertex_, maze->endvertex_, &maze->adjacencylist_);
	win.add(area);
	area.show();

	return app->run(win);
}