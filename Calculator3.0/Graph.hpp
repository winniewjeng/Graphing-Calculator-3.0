//
//  Graph.hpp (System.hpp)
//  Calculator3.0
//
//  Created by Winnie Jeng on 12/3/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <vector>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "LinkedList.hpp"
#include "Queue.hpp"
#include "ShuntingYard.hpp"

using namespace std;
class Graph {
public:
    Graph();
    
    //plot the coordinate axes
    sf::VertexArray PlotXAxis();
    sf::VertexArray PlotYAxis();
    
//    Queue<sf::Vector2f> plot(float xhigh, float xlow, float num_grids);
    
    // get a set of coordinates given the range and number of screen units
    Queue<sf::Vector2f> getCoords(double xlow, double xhigh, int num_grids);
    // get a set of pixel coordinates given the range
    Queue<sf::Vector2f> getPixelCoords(double xlow, double xhigh, int num_grids);
    
//    void setXAxis() {
//        xAxis.setPrimitiveType(sf::LineStrip);
////        sf::LinesStrip, 3);
//    }
    
    // for testing purpose only
    void test_pixel_coords();
    void test_coords();
    
    void Draw(sf::RenderWindow& widnow);
    
private:
    sf::CircleShape shape;
    sf::VertexArray xAxis;
    sf::VertexArray yAxis;
    
    sf::RectangleShape graph_window;
    int _num_grids;
};

#endif /* Graph_hpp */
