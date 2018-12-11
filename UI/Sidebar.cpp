
#include "Sidebar.hpp"

Sidebar::Sidebar(float left, float width):_left(left), _width(width) {
    
    //set up the sidebar rectangle:
    bar.setFillColor(Color(200,200,200));  // grayish blue
//    bar.setFillColor(sf::Color(170, 177, 206));
    bar.setPosition(Vector2f(WINDOW_WIDTH-SIDE_BAR, 0)); // sidebar align left
    bar.setSize(Vector2f(width, WINDOW_HEIGHT));
}

void Sidebar::draw(RenderWindow& window) {
    window.draw(bar);
}

