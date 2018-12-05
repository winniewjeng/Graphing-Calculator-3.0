//
//  Graph.cpp
//  Calculator3.0
//
//  Created by Winnie Jeng on 12/3/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include "Graph.hpp"

Graph::Graph() {}

Queue<sf::Vector2f> Graph::getCoords(double xlow, double xhigh, int num_grids) {
    
    _num_grids = num_grids;
    // get an equation
    Shunting yard;
    // make the equation postfix -- PRIVATE MEMBER VAR OF GRAPH CLASS 
    Queue<Token*> equation = yard.getRPN();
    // get a container for coordinates
    Queue<sf::Vector2f> coords;
    // initialize xval to xlow
    double xval = xlow;
    // get the distance between each grid based on range and num grids
    double grid_distance = (xhigh - xlow) / num_grids;
    
    for (int i = 0; i <= num_grids; i++) {
        // evaluate y from xlow to xhigh
        double yval = yard.Eval(equation, xval);
        // push xval and yval into the coords container
        coords.push(sf::Vector2f(xval, yval));
        // increment the value of xval
        xval += grid_distance;
    }
    return coords;
}

Queue<sf::Vector2f> Graph::getPixelCoords(double xlow, double xhigh, int num_grids) {
    Queue<sf::Vector2f> xyCoords = getCoords(xlow, xhigh, num_grids);
    Queue<sf::Vector2f> pixelCoords;
    double xPixel = 0;
    double yPixel;
    //        double xAxis = 0;
    //        double yAxis = WINDOW_HEIGHT/2;
    double x_screen_unit = WINDOW_WIDTH/num_grids;
    double y_screen_unit = WINDOW_HEIGHT/num_grids;
    
    while(!xyCoords.empty()) {
        //transform the x and y into screen pixel coordinates
        xPixel += x_screen_unit;
        yPixel = -1 * (xyCoords.top().y * y_screen_unit) + WINDOW_HEIGHT/2;
        pixelCoords.push(sf::Vector2f(xPixel, yPixel));
        
        xyCoords.pop();
    }
    
    return pixelCoords;
}

void Graph::test_coords() {
    
    Queue<sf::Vector2f> coords = getCoords(-4, 4, 8);
    cout << "Get Coordinates\n";
    while (!coords.empty()) {
        cout << coords.top().x << " ";
        cout << coords.top().y;
        cout << endl;
        coords.pop();
    }
}

void Graph::test_pixel_coords() {
    
    Queue<sf::Vector2f> coords = getPixelCoords(-4, 4, 8);
    cout << "Get Pixel Coordinates\n";
    while (!coords.empty()) {
        cout << coords.top().x << " ";
        cout << coords.top().y;
        cout << endl;
        coords.pop();
    }
    
}

sf::VertexArray Graph::PlotXAxis() {
    
    xAxis = sf::VertexArray(sf::LinesStrip, 3);
    xAxis[0].position = sf::Vector2f(0, WINDOW_HEIGHT/2);
    xAxis[0].color = sf::Color::White;
    xAxis[1].position = sf::Vector2f(GRAPH_PANEL/2, WINDOW_HEIGHT/2);
    xAxis[1].color = sf::Color::Cyan;
    xAxis[2].position = sf::Vector2f(GRAPH_PANEL, WINDOW_HEIGHT/2);
    xAxis[2].color = sf::Color::White;
    
    return xAxis;
}

sf::VertexArray Graph::PlotYAxis() {
    
    yAxis = sf::VertexArray(sf::LinesStrip, 3);
    yAxis[0].position = sf::Vector2f(GRAPH_PANEL/2, 0);
    yAxis[0].color = sf::Color::Red;
    yAxis[1].position = sf::Vector2f(GRAPH_PANEL/2, WINDOW_HEIGHT/2);
    yAxis[1].color = sf::Color::Yellow;
    yAxis[2].position = sf::Vector2f(GRAPH_PANEL/2, WINDOW_HEIGHT);
    yAxis[2].color = sf::Color::White;
    
    return yAxis;
}

void Graph::Draw(sf::RenderWindow& window){
    window.clear();
    window.draw(graph_window);
    window.draw(PlotYAxis());
    window.draw(PlotXAxis());
    
}



