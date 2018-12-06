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
#include "Equation.hpp"

class Interface {
public:
    
    Interface();
    void run();
    // plot the pixel coordinates on graph panel
    void Plot();
    // plotting
    void processEvents();
    void render();
    void Draw();
    
private:
    
    sf::RenderWindow window;
    sf::CircleShape dot;
    Graph graph;
    Sidebar sidebar;
    Equation equation;
    
    Queue<sf::CircleShape*> d;
    
    float xmin, xmax, ymin, ymax;
};

#endif /* Interface_hpp */
