CXX ?= g++
CXXFLAGS = -W -Wall -Wno-unused-result -pthread -O2 -std=c++11 -fPIC

all: mazegen

# OBJECTS = breadthfirstsearch.o cellborder.o circularhexagonmaze.o \
# 	circularmaze.o depthfirstsearch.o hexagonalmaze.o honeycombmaze.o \
# 	kruskal.o main.o maze.o minimumspanningtreealgorithm.o rectangularmaze.o

WINDOW_OBJECTS = breadthfirstsearch.o cellborder.o circularhexagonmaze.o \
 	circularmaze.o depthfirstsearch.o hexagonalmaze.o honeycombmaze.o \
 	kruskal.o maze.o minimumspanningtreealgorithm.o rectangularmaze.o \
 	draw.o window_main.o

INCLUDES = `pkg-config --cflags glib-2.0 gtk+-3.0 gtkmm-3.0 glibmm-2.4`

LIBS = `pkg-config --libs glib-2.0 gtk+-3.0 gtkmm-3.0 glibmm-2.4`

window: $(WINDOW_OBJECTS)
	@echo "Building" $@
	@$(CXX) -o $@ $^ $(CXXFLAGS) $(INCLUDES) $(LIBS)

# mazegen: $(OBJECTS)
# 	@echo "Building" $@
# 	@$(CXX) -o $@ $^ $(CXXFLAGS)

%.o: %.cpp
	@echo "Compiling" $<
	@$(CXX) -o $@ -c $< $(CXXFLAGS) $(INCLUDES) $(LIBS)

.phony: clean
clean:
	@echo "Cleaning"
	@rm -f $(OBJECTS) $(WINDOW_OBJECTS) mazegen window
