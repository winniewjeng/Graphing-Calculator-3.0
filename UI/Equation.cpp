//
//  Equation.cpp
//  Calculator3.0
//
//  Created by Winnie Jeng on 12/5/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include "Equation.hpp"

void Equation::getCoords(double xmin, double xmax, double ymin, double ymax) {
    
    xyCoords.clear();
    
    cout << "Postfix: " << postfix_queue << endl;
    
    double xrange = xmax - xmin;
    double yrange = ymax - ymin;
    cout << "xrange: " << xrange << endl;
    cout << "yrange: " << yrange << endl;
    
    for (int xpixel = 0; xpixel <= GRAPH_PANEL; xpixel++) {
        
        double xval = xmin + (xpixel / GRAPH_PANEL) * xrange;
        // evaluate y
        double yval = yard.Eval(postfix_queue, xval);
        
        cout << "(" << xval << ", " << yval << ")\n";
        
        // get y pixel
        double ypixel = (1 - (yval / yrange * 2) ) * WINDOW_HEIGHT / 2;
        cout << "<" << xpixel << ", " << ypixel << ">\n\n";
        //        cout << "(" << xval << ", " << yval << ")\n";
        //if yval == 0, use pixel to plot x-axis
        //        if (xval == 0) {
        //            cout << "(" << xval << ", " << yval << ")\n";
        //            cout << "y == 0!\n";
        //            Vertex xVertex[3];
        //            // left-most point is (xminPixel, ypixel)
        //            // middle point is (xpixel, ypixel)
        //            xVertex[0].position = Vector2f(0, ypixel);
        //            xVertex[0].color = Color::White;
        //            xAxis.append(xVertex[0]);
        //            xVertex[1].position = Vector2f(xpixel, ypixel);
        //            xVertex[1].color = Color::White;
        //            xAxis.append(xVertex[1]);
        //            xVertex[2].position = Vector2f(GRAPH_PANEL, ypixel);
        //            xVertex[2].color = Color::White;
        //            xAxis.append(xVertex[2]);
        //        }
        //store pixel location inside a vertex
        Vertex vertex;
        vertex.position = Vector2f(xpixel, ypixel);
        // make the graph orange color
        vertex.color = Color(255, 150, 0);
        // append the vertex to xyCoords;
        xyCoords.append(vertex);
    }
}

void Equation::Draw(sf::RenderWindow& window)
{
    window.draw(xAxis);
    window.draw(xyCoords);
}

