

#include "Interface.hpp"

// Interface contains god
Interface::Interface(): sidebar(GRAPH_PANEL, SIDE_BAR), graph() {
    
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Graphing Calculator");
    window.setFramerateLimit(60);
    
    xmin = -10;
    xmax = 10;
    ymin = -10;
    ymax = 10;
    equation.getCoords(xmin, xmax, ymin,ymax);

    
}

void Interface::Draw() {

    graph.Draw(window);
    sidebar.draw(window);
    equation.Draw(window);

}

void Interface::render() {

    window.clear();
    Draw();
    window.display();

}

void Interface::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.Closed) {
            window.close();
        }
    }
}

void Interface::run() {
    while (window.isOpen()) {
        processEvents();
        render(); //clear/draw/display
    }
}
