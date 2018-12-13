//
//  Equation.cpp
//  Calculator3.0
//
//  Created by Winnie Jeng on 12/5/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include "Equation.hpp"

// Interface update() calls step to make necessary changes in user pan or zoom situation
void Equation::step(int command) {
    
    if (command == PANRIGHT) {

        setXmin(_xmin + 1);
        setXmax(_xmax + 1);
        getCoords();
//        for (double xpixel = 0; xpixel <= GRAPH_PANEL; xpixel++) {
////            xyCoords[xpixel].position.x -= 100;
//        }
//        yAxis.clear();
//        getYAxis(yAxis[0].position.x - 100, yAxis[0].position.y);
        
    } else if (command == PANLEFT) {
        
        setXmin(_xmin - 1);
        setXmax(_xmax - 1);
        getCoords();
//        for (double xpixel = 0; xpixel <= GRAPH_PANEL; xpixel++) {
//            xyCoords[xpixel].position.x += 100;tan ( X + 3 )
//        }
//        yAxis.clear();
//        getYAxis(yAxis[0].position.x + 100, yAxis[0].position.y);
//
        
    } else if (command == PANUP) {
        
        for (double xpixel = 0; xpixel <= GRAPH_PANEL; xpixel++) {
            xyCoords[xpixel].position.y += 100;
        }
        xAxis.clear();
        getXAxis(xAxis[0].position.x, xAxis[0].position.y + 100);
        
    } else if (command == PANDOWN) {

        for (double xpixel = 0; xpixel <= GRAPH_PANEL; xpixel++) {
            xyCoords[xpixel].position.y -= 100;
        }
        xAxis.clear();
        getXAxis(xAxis[0].position.x, xAxis[0].position.y - 100);
        
    } else if (command == ZOOMIN) {
        
        setXmin(_xmin * 0.95);
        setXmax(_xmax * 0.95);
        SCALE *= 1.05;
        getCoords();

    } else if (command == ZOOMOUT) {
        
        setXmin(_xmin * 1.05);
        setXmax(_xmax * 1.05);
        getCoords();
        SCALE*=0.95;
    }
    
}

// The function transforms (x, y) and plot them as (pixelX, pixelY) on window
void Equation::getCoords() {
    
    // clear the xyCoords VertexArray
    xyCoords.clear();
    // cout << "Postfix: " << postfix_queue << endl;
    
    double xrange = _xmax - _xmin;
    //variables for tracking the xy-Axes; initialized to somehting ridiculous
    double last_xval = 999;
    double last_yval = 999;
    double last_ypixel = 999;
    
    for (double xpixel = 0; xpixel <= GRAPH_PANEL; xpixel++) {
        
        double xval = _xmin + (xpixel / GRAPH_PANEL) * xrange;
        // get y by calling the shunting yard Eval funciton
        double yval = yard.Eval(postfix_queue, xval)*SCALE;
        
        //        cout << "x: " << xval << "   y: " << yval << endl;
        
        // get y pixel -- # of _ypixel based on # of yval, which is based on # of xval
        _ypixel = (1 - (yval / _grids * 2) ) * WINDOW_HEIGHT / 2;
        
        // if yOrigin detected, plot y axis at midway between last_xval and xval
        if (last_xval <= 0 && xval >=0) {
            getYAxis(xpixel, _ypixel);
        }
        // if xOrigin detected, plot x axis at midway between last_yval and yval
        if (last_yval <=0 && yval >=0) {
            getXAxis(xpixel, (_ypixel + last_ypixel) / 2);
        }
        
        // store pixel location inside a vertex
        Vertex vertex;
        vertex.position = Vector2f(xpixel, _ypixel);
        // make the function orange color
        vertex.color = Color(255, 150, 0);
        // append the vertex to xyCoords;
        xyCoords.append(vertex);
        
        // get the last yval and current yval to see if plotting x-axis
        last_xval = xval;
        last_yval = yval;
        last_ypixel = _ypixel;
    }
}



void Equation::Draw(sf::RenderWindow& window)
{
    window.clear();
    window.draw(_background);
    window.draw(yAxis);
    window.draw(xAxis);
    window.draw(xyCoords);
}

// plot x Axis
void Equation::getXAxis(double xpixel, double ypixel) {
    xAxis.clear();
    Vertex xVertex[3];
    // left-most point is (xminPixel, ypixel)
    // middle point is (xpixel, ypixel)
    xVertex[0].position = Vector2f(0, ypixel);
    xVertex[0].color = Color(200,200,200); //beige
    xAxis.append(xVertex[0]);
    xVertex[1].position = Vector2f(xpixel, ypixel);
    xVertex[1].color = Color(200,200,200);
    xAxis.append(xVertex[1]);
    xVertex[2].position = Vector2f(GRAPH_PANEL, ypixel);
    xVertex[2].color = Color(200,200,200);
    xAxis.append(xVertex[2]);
}

// plot y axis
void Equation::getYAxis(double xpixel, double ypixel) {
    yAxis.clear();
    Vertex yVertex[3];
    yVertex[0].position = Vector2f(xpixel, 0);
    yVertex[0].color = Color(200,200,200);
    yAxis.append(yVertex[0]);
    yVertex[1].position = Vector2f(xpixel, ypixel);
    yVertex[1].color = Color(200,200,200);
    yAxis.append(yVertex[1]);
    yVertex[2].position = Vector2f(xpixel, WINDOW_HEIGHT);
    yVertex[2].color = Color(200,200,200);
    yAxis.append(yVertex[2]);
}
