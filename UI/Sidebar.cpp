
#include "Sidebar.hpp"

//using namespace sf;

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

