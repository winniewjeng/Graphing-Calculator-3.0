//
//  Equation.cpp
//  Calculator3.0
//
//  Created by Winnie Jeng on 12/5/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include "Equation.hpp"

void Equation::Draw(sf::RenderWindow& window)
{
    window.draw(xyCoords);
}

void Equation::getCoords(double xmin, double xmax, double ymin, double ymax) {
    
    xyCoords.clear();
    cout << postfix_queue << endl;
    // get a container for coordinates
    
    double xrange = xmax - xmin;
    double yrange = ymax - ymin;
//    cout << postfix_queue << " inside getcoords\n";
//    cout << postfix_queue.empty() << endl;
    for (int i = 0; i <= GRAPH_PANEL; i++) {
        
        double xval = xmin + (i / GRAPH_PANEL) * xrange;
        // evaluate y
//        cout << xval << " is xval before val\n";
//        cout << postfix_queue << " is postfixqueue vbefore eval\n";
        double yval = yard.Eval(postfix_queue, xval);
        
        double ypixel = (1 - (yval/yrange)) * WINDOW_HEIGHT;
        sf::Vertex vertex;
        vertex.position = sf::Vector2f(i, ypixel);
        vertex.color = sf::Color::Red;
        //Push x and y pixel as vector2f to xyCoords;
        xyCoords.append(vertex);
    }
}

//Queue<sf::Vector2f> Equation::getPixelCoords(double xlow, double xhigh, int num_grids) {
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

//void Equation::test_coords() {
//
//    Queue<sf::Vector2f> coords = getCoords(-4, 4, 8);
//    cout << "Get Coordinates\n";
//    while (!coords.empty()) {
//        cout << coords.top().x << " ";
//        cout << coords.top().y;
//        cout << endl;
//        coords.pop();
//    }
//}
//
//void Equation::test_pixel_coords() {
//
//    Queue<sf::Vector2f> coords = getPixelCoords(-4, 4, 8);
//    cout << "Get Pixel Coordinates\n";
//    while (!coords.empty()) {
//        cout << coords.top().x << " ";
//        cout << coords.top().y;
//        cout << endl;
//        coords.pop();
//    }
//
//}
