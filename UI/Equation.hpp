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
    Equation() : yard(), postfix_queue(yard.getRPN()) {
        xyCoords.setPrimitiveType(LinesStrip);
        xAxis.setPrimitiveType(LinesStrip);
        yAxis.setPrimitiveType(LinesStrip);
    }
    // get a set of coordinates given the xy-range
    void getCoords(double xmin, double xmax, double ymin, double ymax);
    void Draw(RenderWindow& window);
    
    
private:
    string infix_expression;
    Shunting yard;
    Queue<Token*> postfix_queue;
    VertexArray xyCoords;
    
    VertexArray xAxis;
    VertexArray yAxis;
};

#endif /* Equation_hpp */
