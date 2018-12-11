

#include "Interface.hpp"

// Interface contains god
Interface::Interface(): sidebar(GRAPH_PANEL, SIDE_BAR), graph() {
    
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Graphing Calculator");
    
    window.setFramerateLimit(60);
    
    xmin = -4;
    xmax = 4;
    ymin = -4;
    ymax = 4;
    
    equation.getCoords(xmin, xmax, ymin, ymax);
}

// process events/render
void Interface::run() {
    
    while (window.isOpen()) {
        
        processEvents();
        render(); //clear/draw/display
    }
}

// clicking & stuff
void Interface::processEvents() {
    
    Event event;
    while (window.pollEvent(event)) {
        if (event.Closed) {
            window.close();
        }
    }
}

//clear/draw/display
void Interface::render() {
    
    window.clear();
    Draw();
    window.display();
    
}

//draw graph->sidebar->equation
void Interface::Draw() {

    graph.Draw(window);
    sidebar.draw(window);
    equation.Draw(window);

}

