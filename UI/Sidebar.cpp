
#include "Sidebar.hpp"


Sidebar::Sidebar() {
    // set the bar to gray color
    bar.setFillColor(Color(200,200,200));
    // sidebar align right
    bar.setPosition(Vector2f(GRAPH_PANEL, 0));
    bar.setSize(Vector2f(SIDE_BAR, WINDOW_HEIGHT));
}

void Sidebar::draw(RenderWindow& window) {
    window.draw(bar);
}

