

#include "Interface.hpp"

Interface::Interface(): sidebar(), graph() {
    
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Graphing Calculator");
    
    window.setFramerateLimit(100);
    
    mouseIn = true;
    
    if (cursor.loadFromSystem(sf::Cursor::Hand))
    window.setMouseCursor(cursor);
    
    xmin = - 2 * 3.14 ;
    xmax = 2 * 3.14;
    //grid nums
    grids = 7;
    
    equation.getCoords(xmin, xmax, grids);
    string eqn = equation.get_expression();
    sidebar.eqn_str(eqn);
    
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
                
                //                case::Event::MouseButtonReleased:
                //                mouseX = event.mouseButton.x;
                //                mouseY = event.mouseButton.y;
                //                // if mouse is clicked inside bar, get user input and print eqn str
                //                if (mouseX >= GRAPH_PANEL && mouseX <= WINDOW_WIDTH) {
                //                    cout << "click\n";
                //                } else {
                //                    cout << "huh?\n";
                //                }
                //
                //                if (event.mouseButton.button == Mouse::Right) {
                //                    sidebar[5] = "RIGHT CLICK " + mouse_pos_string(window);
                //                } else {
                //                    sidebar[5] = "LEFT CLICK " +
                //                    mouse_pos_string(window);
                //                }
                //                break;
                
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

string mouse_pos_string(RenderWindow& window){
    return "(" +
    to_string(Mouse::getPosition(window).x) +
    ", " +
    to_string(Mouse::getPosition(window).y) +
    ")";
}

string key_to_string(RenderWindow& window) {
    string str = " | ";
    if (Keyboard::isKeyPressed(Keyboard::Num0)) {
        str += Keyboard::Num0;
    } else if (Keyboard::isKeyPressed(Keyboard::Num1)) {
        str += Keyboard::Num1;
    } else if (Keyboard::isKeyPressed(Keyboard::Num2)) {
        str += Keyboard::Num2;
    } else if (Keyboard::isKeyPressed(Keyboard::Num3)) {
        str += Keyboard::Num3;
    } else if (Keyboard::isKeyPressed(Keyboard::Num4)) {
        str += Keyboard::Num4;
    } else if (Keyboard::isKeyPressed(Keyboard::Num5)) {
        str += Keyboard::Num5;
    } else if (Keyboard::isKeyPressed(Keyboard::Num6)) {
        str += Keyboard::Num6;
    } else if (Keyboard::isKeyPressed(Keyboard::Num7)) {
        str += Keyboard::Num7;
    } else if (Keyboard::isKeyPressed(Keyboard::Num8)) {
        str += Keyboard::Num8;
    } else if (Keyboard::isKeyPressed(Keyboard::Num9)) {
        str += Keyboard::Num9;
    } else if (Keyboard::isKeyPressed(Keyboard::Add)) {
        str += Keyboard::Add;
    } else if (Keyboard::isKeyPressed(Keyboard::Subtract)) {
        str += Keyboard::Subtract;
    } else if (Keyboard::isKeyPressed(Keyboard::Divide)) {
        str += Keyboard::Divide;
    } else if (Keyboard::isKeyPressed(Keyboard::Multiply)) {
        str += Keyboard::Multiply;
    } else if (Keyboard::isKeyPressed(Keyboard::Space)) {
        str += Keyboard::Space;
    } else if (Keyboard::isKeyPressed(Keyboard::Subtract)) {
        str += Keyboard::Subtract;
    } else if (Keyboard::isKeyPressed(Keyboard::Subtract)) {
        str += Keyboard::Subtract;
    } else if (Keyboard::isKeyPressed(Keyboard::Subtract)) {
        str += Keyboard::Subtract;
    }
    //    } else if (Keyboard::isKeyPressed(Keyboard::)) {
    //        str += Keyboard::Subtract;
    //    }
    
    return str;
}

