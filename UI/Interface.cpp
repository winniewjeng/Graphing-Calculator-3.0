

#include "Interface.hpp"

Interface::Interface(): sidebar(), graph() {
    
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Graphing Calculator");
    
    window.setFramerateLimit(60);
    cout << GRAPH_PANEL << " X " << WINDOW_HEIGHT << endl;
    
    xmin = -4;
    xmax = 4;
    ymin = -4;
    ymax = 4;
    
    //   graph.getAxes(xmin, xmax, ymin, ymax);
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

