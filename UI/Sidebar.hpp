
#ifndef Sidebar_hpp
#define Sidebar_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Constants.hpp"
#include "Equation.hpp"

using namespace std;
using namespace sf;

class Sidebar {
    
public:
    // CTOR -- set up the sidebar rectangle
    Sidebar();
    void draw(RenderWindow& window);
    // NOT YET IMPLEMENTED
    string& operator [](int index);
    void eqn_str(string infix_expression) {_infix_expression = infix_expression;}
    
private:
    
    RectangleShape bar; //sidebar rectangle
    vector<string> items; //strings to place on the sidebar
    Font font;
    Text text; // strings on the window
    
//    float _left;
//    float _width;
    
    string _infix_expression;
};

#endif /* Sidebar_hpp */
