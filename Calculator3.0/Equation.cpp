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
        
        double ypixel = (1 - (yval/yrange)) * WINDOW_HEIGHT/2;
        sf::Vertex vertex;
        vertex.position = sf::Vector2f(i, ypixel);
        vertex.color = sf::Color::Red;
        //Push x and y pixel as vector2f to xyCoords;
        xyCoords.append(vertex);
    }
}
