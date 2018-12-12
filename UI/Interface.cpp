

#include "Interface.hpp"

Interface::Interface(): xmin(- 2 * 3.14), xmax(2 * 3.14), grids(7), sidebar(), graph(), equation(xmin, xmax, grids) {
    
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Graphing Calculator");
    
    window.setFramerateLimit(100);
    
    mouseIn = true;
    
    if (cursor.loadFromSystem(sf::Cursor::Hand))
        window.setMouseCursor(cursor);
    
//    xmin = - 2 * 3.14 ;
//    xmax = 2 * 3.14;
//    //grid nums
//    grids = 7;
//
     // recently added
    equation.getCoords();
//    equation.getCoords(xmin, xmax, grids);
    
    infix_expression = equation.get_expression();
    sidebar.set_infix_expression(infix_expression);
    //    cout << infix_expression << endl;
    
}

// process events/update/render
void Interface::run() {
    
    while (window.isOpen()) {
        
        processEvents();
        update();
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
                        // user wants to quit program
                    case::Keyboard::Q:
                        window.close();
                        break;
                        //user wants to close program
                    case::Keyboard::Escape:
                        window.close();
                        break;
                        // user wants to pan right
                    case::Keyboard::Right:
                        command = PANRIGHT;
                        break;
                        // user wants to pan left
                    case::Keyboard::Left:
                        command = PANLEFT;
                        break;
                        // user wants to pan up
                        // user wants to pan down
                }
            case Event::MouseEntered:
                mouseIn = true;
                break;
                
            case Event::MouseLeft:
                mouseIn = false;
                break;
                
            case Event::MouseMoved:
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
                //cout << mouseX << " " << mouseY << endl;
                // if mouseMoved in the sidebar, change cursor to text
                if (mouseX >= GRAPH_PANEL && mouseX <= WINDOW_WIDTH) {
                    if (cursor.loadFromSystem(sf::Cursor::Text))
                        window.setMouseCursor(cursor);
                    // if mouse is pressed inside sidebar, get user input
                } else {
                    if (cursor.loadFromSystem(sf::Cursor::Hand))
                        window.setMouseCursor(cursor);
                }
                break;
                
                
        }
        
    }
}

void Interface::update(){
    //cause changes to the data for the next frame
    equation.step(command);
    command = 0;
    
    //    if (mouseIn){
    //        //mousePoint red dot:
    //        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
    //                               sf::Mouse::getPosition(window).y-5);
    //
    //        //mouse location text for sidebar:
    //        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);
    //    }
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
    equation.Draw(window);
    sidebar.draw(window);
    
}

string mouse_pos_string(RenderWindow& window){
    return "(" +
    to_string(Mouse::getPosition(window).x) +
    ", " +
    to_string(Mouse::getPosition(window).y) +
    ")";
}


