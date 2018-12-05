//
//  Sidebar.cpp
//  Calculator3.0
//
//  Created by Winnie Jeng on 12/3/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include "Sidebar.hpp"

Sidebar::Sidebar(float left, float width):_left(left), _width(width) {
    
    //set up the sidebar rectangle:
    bar.setFillColor(sf::Color(171,194,207));  // grayish blue
//    bar.setFillColor(sf::Color(170, 177, 206));
    bar.setPosition(sf::Vector2f(WINDOW_WIDTH-SIDE_BAR, 0)); // sidebar align left
    bar.setSize(sf::Vector2f(width, WINDOW_HEIGHT));
}

void Sidebar::draw(sf::RenderWindow& window) {
    window.draw(bar);
}

