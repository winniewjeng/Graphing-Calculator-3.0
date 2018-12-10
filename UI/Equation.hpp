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
class Equation {
    
public:
    Equation() : yard(), postfix_queue(yard.getRPN()) {
        
        xyCoords.setPrimitiveType(sf::LinesStrip);
    }
    
//    //get the expression for calculation from user input
//    void userInput();
    
    // get a set of coordinates given the range and number of screen units
    void getCoords(double xmin, double xmax, double ymin, double ymax);
    // get a set of pixel coordinates given the range
//    Queue<sf::Vector2f> getPixelCoords(double xlow, double xhigh, int num_grids);
    // for testing purpose only
    void test_pixel_coords();
    void test_coords();
    void Draw(sf::RenderWindow& window);
    
    
private:
    string infix_expression;
    Shunting yard;
    Queue<Token*> postfix_queue;
    sf::VertexArray xyCoords;
    
};

#endif /* Equation_hpp */
