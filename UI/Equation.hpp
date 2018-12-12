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
    // CTOR -- initializes Shunting yard object, postfix_queue of token queue, & xyCoords of vertex array as LinesStrip primitive type
//    Equation() : yard(), postfix_queue(yard.getRPN()) {
//        xyCoords.setPrimitiveType(LinesStrip);
//        xAxis.setPrimitiveType(LinesStrip);
//        yAxis.setPrimitiveType(LinesStrip);
////        _graphDrawn = false;
//
//        infix_expression = yard.getExpression();
//    }
    Equation(double xmin, double xmax, double grids) : yard(),
    postfix_queue(yard.getRPN()),_xmin(xmin), _xmax(xmax), _grids(grids) {
        xyCoords.setPrimitiveType(LinesStrip);
        xAxis.setPrimitiveType(LinesStrip);
        yAxis.setPrimitiveType(LinesStrip);
        //        _graphDrawn = false;
        
        infix_expression = yard.getExpression();
    }
    void step(int command);
    // get a set of coordinates given the xy-range
//    void getCoords(double xmin, double xmax, double grids);
    void getCoords();

    void Draw(RenderWindow& window);
//    bool graphDrawn() {return _graphDrawn;}
    void getXAxis(double xpixel, double ypixel);
    void getYAxis(double xpixel, double ypixel);
    string get_expression() {return infix_expression;}
    // set _xmin, _xmax, _grids
    void setXmin(double xmin) {_xmin = xmin;}
    void setXmax(double xmax) {_xmax = xmax;}
    void setGrids(double grids) {_grids = grids;}
    
    
private:
//    string infix_expression;
    Shunting yard;
    Queue<Token*> postfix_queue;
    VertexArray xyCoords;
    
    VertexArray xAxis;
    VertexArray yAxis;
    
    string infix_expression;
    
    double _xmin;
    double _xmax;
    double _grids;

};

#endif /* Equation_hpp */
