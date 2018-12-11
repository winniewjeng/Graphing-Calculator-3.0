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
    for (int xpixel = 0; xpixel <= GRAPH_PANEL; xpixel++) {
        //
        double xval = xmin + (xpixel / GRAPH_PANEL) * xrange;
        // evaluate y
        double yval = yard.Eval(postfix_queue, xval);
        // get y pixel
        double ypixel = (1 - (yval/yrange)) * WINDOW_HEIGHT/2;
        
        Vertex vertex;
        
        vertex.position = Vector2f(xpixel, ypixel);
        vertex.color = Color(255, 150, 0); // orange color
        
        //Push x and y pixel as vector2f to xyCoords;
        xyCoords.append(vertex);
    }
}
