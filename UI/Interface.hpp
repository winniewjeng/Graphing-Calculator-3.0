
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

// Interface class controls all the sub UI classes
class Interface {
public:
    
    Interface();
    void run();
    void update();
    void processEvents();
    void render();
    void Draw();
    
private:
    
    bool mouseIn;
    Cursor cursor;
    
    // default values of the graph
    float xmin;
    float xmax;
    float grids;
    
    RenderWindow window;
    Graph graph;
    Sidebar sidebar;
    Equation equation;
    
    // user input function expression
    string infix_expression;
    
    int command;
};

string mouse_pos_string(RenderWindow& window);
string userinput(RenderWindow& window);
#endif /* Interface_hpp */
