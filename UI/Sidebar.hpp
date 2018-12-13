
#ifndef Sidebar_hpp
#define Sidebar_hpp

#include "SFML/Graphics.hpp"
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
    // overload operator to access UI icon vector
    // interactive design not yet implemented
    string& operator [](int index);
    void store_symbol_icons();
    // get the user input function string and draw in sidebar
    void set_infix_expression(string infix_expression);
    
private:
    
    RectangleShape bar; //sidebar rectangle
    vector<string> icons; //strings to place on the sidebar
    Font font;
//    Text text; // strings on the window
    Text expression_text;
    Text symbol_icon;
};

#endif /* Sidebar_hpp */
