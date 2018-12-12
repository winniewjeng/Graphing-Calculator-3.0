
#ifndef Sidebar_hpp
#define Sidebar_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Constants.hpp"
#include "ShuntingYard.hpp"

using namespace std;
using namespace sf;

class Sidebar {
    
public:
    // CTOR -- set up the sidebar rectangle
    Sidebar();
    void draw(RenderWindow& window);
    // NOT YET IMPLEMENTED
    string& operator [](int index);
//    void eqn_str(string infix_expression) {_infix_expression = infix_expression;}
    void set_infix_expression(string infix_expression);
    void store_symbol_icons();
private:
    
    RectangleShape bar; //sidebar rectangle
    vector<string> icons; //strings to place on the sidebar
    Font font;
//    Text text; // strings on the window
    Text expression_text;
    Text symbol_icon;
};

#endif /* Sidebar_hpp */
