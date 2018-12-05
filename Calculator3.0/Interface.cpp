//
//  Interface.cpp
//  Calculator3.0
//
//  Created by Winnie Jeng on 12/3/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include "Interface.hpp"

Interface::Interface(): sidebar(GRAPH_PANEL, SIDE_BAR), graph() {

    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Graphing Calculator");
    window.setFramerateLimit(1);
    
    
    //    Queue<Token*> input;
    //
    //    input.push(new Operand(3.0));
    Queue<sf::CircleShape*> c;
    c.push(new sf::CircleShape(3));
    c.push(new sf::CircleShape(4));
    int i = 20;
    while (!c.empty()) {
        c.top()->setFillColor(sf::Color::Magenta);
        c.top()->setPosition(i,i);
        i += 100;
        window.draw(*c.top());
        c.pop();
    }
    
    dot = sf::CircleShape(5);
    dot.setFillColor(sf::Color::Magenta);
//    dot.setPosition(10,10);
//    window.draw(dot);
//    Queue<sf::Vector2f> g = graph.getPixelCoords(10, -10, 20);
    
    sf::CircleShape* dt = new sf::CircleShape(20);
    dt->setFillColor(sf::Color::Cyan);
    dt->setPosition(100,100);
    d.push(dt);
    
    sf::CircleShape* dn = new sf::CircleShape(20);
    dn->setFillColor(sf::Color::Green);
    dn->setPosition(400, 400);
    d.push(dn);
    
    sf::CircleShape* dk = new sf::CircleShape(20);
    dk->setFillColor(sf::Color::Blue);
    dk->setPosition(250, -200);
    d.push(dk);
    
//    window.draw(*dn);
    
//    while (!d.empty()) {
//        window.draw(*d.top());
//        d.pop();
//    }
//    d.push(dt);
//    dot.setPosition(100,100);
    
//    window.draw(dot);
//
//    while (!g.empty()) {
//        cout << g.top().x << " ";
//        cout << g.top().y << endl;
//        dot.setPosition(g.top().x, g.top().y);
//        window.draw(dot);
//        g.pop();
//    }
    
    //this is not great
//    Plot();
    
}

void Interface::Draw() {

    graph.Draw(window);
    sidebar.draw(window);
    
    //this is working
    window.draw(dot);
//    while (!d.empty()) {
//        window.draw(*d.top());
//        d.pop();
//    }
    

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

// UNDER CONSTRUCTION
void Interface::Plot() {
    
    Queue<sf::Vector2f> pixelDot = graph.getPixelCoords(-10, 10, 20);

    dot = sf::CircleShape(50);
    
//    while(!pixelCoords.empty()) {
//        dot.setPosition(pixelCoords.top()); //set the position of the dot as the pixelCoord
//        cout << pixelCoords.top().x << " ";
//
//        pixelCoords.pop();
//    }
    
    while(!pixelDot.empty()) {
        dot.setPosition(pixelDot.top().x, pixelDot.top().y);
        window.draw(dot);
        cout << pixelDot.top().x << " ";
        cout << pixelDot.top().y << endl;
        pixelDot.pop();
    }
    

}

//Queue<sf::Vector2f> Interface::getCoords(double xlow, double xhigh, int num_grids) {
//    _num_grids = num_grids;
//    // get an equation
//    Shunting yard;
//    // make the equation postfix
//    Queue<Token*> equation = yard.getRPN();
//    // get a container for coordinates
//    Queue<sf::Vector2f> coords;
//    // initialize xval to xlow
//    double xval = xlow;
//    // get the distance between each grid based on range and num grids
//    double grid_distance = (xhigh - xlow) / num_grids;
//    
//    for (int i = 0; i <= num_grids; i++) {
//        // evaluate y from xlow to xhigh
//        double yval = yard.Eval(equation, xval);
//        // push xval and yval into the coords container
//        coords.push(sf::Vector2f(xval, yval));
//        // increment the value of xval
//        xval += grid_distance;
//    }
//    return coords;
//}
//
//Queue<sf::Vector2f> Interface::getPixelCoords(double xlow, double xhigh, int num_grids) {
//    
//    Queue<sf::Vector2f> xyCoords = getCoords(xlow, xhigh, num_grids);
//    Queue<sf::Vector2f> pixelCoords;
//    double xPixel = 0;
//    double yPixel;
//    //        double xAxis = 0;
//    //        double yAxis = WINDOW_HEIGHT/2;
//    double x_screen_unit = WINDOW_WIDTH/num_grids;
//    double y_screen_unit = WINDOW_HEIGHT/num_grids;
//    
//    while(!xyCoords.empty()) {
//        //transform the x and y into screen pixel coordinates
//        xPixel += x_screen_unit;
//        yPixel = -1 * (xyCoords.top().y * y_screen_unit) + WINDOW_HEIGHT/2;
//        pixelCoords.push(sf::Vector2f(xPixel, yPixel));
//        
//        xyCoords.pop();
//    }
//    
//    return pixelCoords;
//}
//
//void Interface::test_coords() {
//    Queue<sf::Vector2f> coords = getCoords(-4, 4, 8);
//    
//    while (!coords.empty()) {
//        cout << coords.top().x << " ";
//        cout << coords.top().y;
//        cout << endl;
//        coords.pop();
//    }
//}
//
//void Interface::test_pixel_coords() {
//    Queue<sf::Vector2f> coords = getPixelCoords(-4, 4, 8);
//    
//    while (!coords.empty()) {
//        cout << coords.top().x << " ";
//        cout << coords.top().y;
//        cout << endl;
//        coords.pop();
//    }
//    
//}
