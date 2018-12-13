//
//  Equation.hpp
//  Calculator3.0
//
//  Created by Winnie Jeng on 12/5/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#ifndef Equation_hpp
#define Equation_hpp

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Constants.hpp"
#include <string>
#include "ShuntingYard.hpp"

using namespace std;
using namespace sf;

class Equation {
    
public:
    // CTOR -- initializ the Shunting yard object to get the postfix-order of the funciton for plotting, init the scope (xmin, xmax, grids), etc..
    Equation(double xmin, double xmax, double grids) : yard(),
    postfix_queue(yard.getRPN()),_xmin(xmin), _xmax(xmax), _grids(grids) {
        //init the pixel coordinate of the VertexArray xyCoords
        xyCoords.setPrimitiveType(LinesStrip);
        xAxis.setPrimitiveType(LinesStrip);
        yAxis.setPrimitiveType(LinesStrip);
        
        // get the user input string by calling the Shunting yard object
        infix_expression = yard.getExpression();
        
        // init the background. (honestly this is trhe part where i think i can just kill the Graph class and let Equaiton class handles everything)
        _background.setFillColor(Color(50, 50, 50));
        _background.setPosition(0, 0); // align left
        _background.setSize(Vector2f(GRAPH_PANEL, WINDOW_HEIGHT));
    }
    // takes in a command type from EventProcess and change eqaution based on it
    void step(int command);
    
    // get a set of coordinates given the xy-range
    void getCoords();
    
    // get the X axis and Y axis based on their pixel location
    void getXAxis(double xpixel, double ypixel);
    void getYAxis(double xpixel, double ypixel);

    void Draw(RenderWindow& window);
    
    // pass user input expression to Interface CTOR so Sidebar can later draw it etc.
    string get_expression() {return infix_expression;}
    
    // set _xmin, _xmax, _grids
    void setXmin(double xmin) {_xmin = xmin;}
    void setXmax(double xmax) {_xmax = xmax;}
    void setGrids(double grids) {_grids = grids;}
    
    
private:
    // background box
    RectangleShape _background;

    // use Shunting yard object to get the postfix queue and user expression
    Shunting yard;
    Queue<Token*> postfix_queue;
    string infix_expression;
    
    // function and graphing materials stored in VertexArray
    VertexArray xyCoords;
    VertexArray xAxis;
    VertexArray yAxis;
    
    // scope of the graph
    double _xmin;
    double _xmax;
    double _grids;
    
    // off-set materials during pan/zoom
    double _ypixel;
    double SCALE = 1;
};

#endif /* Equation_hpp */
