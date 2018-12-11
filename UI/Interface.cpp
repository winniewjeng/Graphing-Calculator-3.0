

#include "Interface.hpp"

Interface::Interface(): sidebar(), graph() {
    
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Graphing Calculator");
    
    window.setFramerateLimit(60);
    cout << GRAPH_PANEL << " X " << WINDOW_HEIGHT << endl;
    
    xmin = - 2 * 3.14 ;
    xmax = 2 * 3.14;
    //grid nums
    grids = 7;
    
    equation.getCoords(xmin, xmax, grids);

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
    float mouseX, mouseY;
    while (window.pollEvent(event)) {
        
        switch (event.type) {
                case Event::Closed:
                window.close();
                    break;
                case Event::KeyPressed:
                switch(event.key.code) {
                        case::Keyboard::Q:
                        window.close();
                        break;
                        case::Keyboard::Escape:
                        window.close();
                        break;
                }
        }
        
//        if (event.Closed) {
//
//            window.close();
//
//        }
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

