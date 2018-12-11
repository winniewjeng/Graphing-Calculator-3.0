
#ifndef Interface_hpp
#define Interface_hpp

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Constants.hpp"
#include "Graph.hpp"
#include "Sidebar.hpp"
#include "ShuntingYard.hpp"
#include "Equation.hpp"

using namespace sf;

class Interface {
public:
    
    Interface();
    void run();
    void processEvents();
    void render();
    void Draw();
    
private:
    
    float xmin;
    float xmax;
    float grids;
    RenderWindow window;
    Graph graph;
    Sidebar sidebar;
    Equation equation;
};

#endif /* Interface_hpp */
