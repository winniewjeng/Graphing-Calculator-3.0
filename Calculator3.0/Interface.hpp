//
//  Interface.hpp
//  Calculator3.0
//
//  Created by Winnie Jeng on 12/1/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#ifndef Interface_hpp
#define Interface_hpp

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Constants.hpp"
#include "Graph.hpp"
#include "Sidebar.hpp"
#include <string>
#include "ShuntingYard.hpp"

class Interface {
public:
    Interface();
    void run();
    
//    // get a set of coordinates given the range and number of screen units
//    Queue<sf::Vector2f> getCoords(double xlow, double xhigh, int num_grids);
//    // get a set of pixel coordinates given the range
//    Queue<sf::Vector2f> getPixelCoords(double xlow, double xhigh, int num_grids);
    
    // plot the pixel coordinates on graph panel
    void Plot();
    
    // plot axes -- testing stage
    
    // plotting
    void processEvents();
    void render();
    void Draw();
private:
    sf::RenderWindow window;
    sf::CircleShape dot;
    Graph graph;
    Sidebar sidebar;
    
    Queue<sf::CircleShape*> d;
};

#endif /* Interface_hpp */
