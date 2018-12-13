//
//  Equation.cpp
//  Calculator3.0
//
//  Created by Winnie Jeng on 12/5/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include "Equation.hpp"

void Equation::step(int command) {
    
    if (command == PANRIGHT) {
        // this works too
        setXmin(_xmin + 1);
        setXmax(_xmax + 1);
        getCoords();
        
    } else if (command == PANLEFT) {
        setXmin(_xmin + 1);
        setXmax(_xmax + 1);
        getCoords();
        
    } else if (command == PANUP) {
        
        for (double xpixel = 0; xpixel <= GRAPH_PANEL; xpixel++) {
            xyCoords[xpixel].position.y += 100;
        }
        
    } else if (command == PANDOWN ) {
        
        for (double xpixel = 0; xpixel <= GRAPH_PANEL; xpixel++) {
            xyCoords[xpixel].position.y -= 100;
        }
        
    } else if (command == ZOOMIN) {
        
        setXmin(_xmin * 0.95);
        setXmax(_xmax * 0.95);
        getCoords();
        
    } else if (command == ZOOMOUT) {
        
        setXmin(_xmin * 1.05);
        setXmax(_xmax * 1.05);
        getCoords();
    }
    
}

void Equation::getCoords() {
    
    xyCoords.clear();
    
    //    cout << "Postfix: " << postfix_queue << endl;
    
    double xrange = _xmax - _xmin;
    
    for (double xpixel = 0; xpixel <= GRAPH_PANEL; xpixel++) {
        
        double xval = _xmin + (xpixel / GRAPH_PANEL) * xrange;
        // evaluate y
        double yval = yard.Eval(postfix_queue, xval);
        //        cout << "x: " << xval << "   y: " << yval << endl;
        // get y pixel
        
        _ypixel = (1 - (yval / _grids * 2) ) * WINDOW_HEIGHT / 2;
        // if yval == 0, use pixel to plot x-axis
        //        if (xval == 0) {
        //            getYAxis(xpixel, ypixel);
        //        }
        //        if (yval == 0) {
        //            getXAxis(xpixel, ypixel);
        //        }

        // store pixel location inside a vertex
        Vertex vertex;
        vertex.position = Vector2f(xpixel, _ypixel);
        // make the graph orange color
        vertex.color = Color(255, 150, 0);
        // append the vertex to xyCoords;
        xyCoords.append(vertex);
    }
}



void Equation::Draw(sf::RenderWindow& window)
{
    window.clear();
    window.draw(yAxis);
    window.draw(xAxis);
    window.draw(xyCoords);
    //    _graphDrawn = true;
}

void Equation::getXAxis(double xpixel, double ypixel) {
    Vertex xVertex[3];
    // left-most point is (xminPixel, ypixel)
    // middle point is (xpixel, ypixel)
    xVertex[0].position = Vector2f(0, ypixel);
    xVertex[0].color = Color::White;
    xAxis.append(xVertex[0]);
    xVertex[1].position = Vector2f(xpixel, ypixel);
    xVertex[1].color = Color::White;
    xAxis.append(xVertex[1]);
    xVertex[2].position = Vector2f(GRAPH_PANEL, ypixel);
    xVertex[2].color = Color::White;
    xAxis.append(xVertex[2]);
}

void Equation::getYAxis(double xpixel, double ypixel) {
    Vertex yVertex[3];
    yVertex[0].position = Vector2f(xpixel, 0);
    yVertex[0].color = Color::White;
    yAxis.append(yVertex[0]);
    yVertex[1].position = Vector2f(xpixel, ypixel);
    yVertex[1].color = Color::White;
    yAxis.append(yVertex[1]);
    yVertex[2].position = Vector2f(xpixel, WINDOW_HEIGHT);
    yVertex[2].color = Color::White;
    yAxis.append(yVertex[2]);
}
