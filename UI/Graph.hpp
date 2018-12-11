//
//  Graph.hpp (System.hpp)
//  Calculator3.0
//
//  Created by Winnie Jeng on 12/3/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <vector>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "LinkedList.hpp"
#include "Queue.hpp"
#include "ShuntingYard.hpp"

using namespace std;
using namespace sf;
class Graph {
public:
    Graph();
    
//    //plot the coordinate axes
//    VertexArray PlotXAxis();
//    VertexArray PlotYAxis();
    // get the xy-axes on the graph (or not) given the xy-range
//    void getXAxis(double xmin, double xmax);
    void getXAxis(double xmin, double xmax) {
        
        xAxis.setPrimitiveType(LinesStrip);
        
        for (double xpixel = 0; xpixel <= GRAPH_PANEL; xpixel++) {
            if ( xmin <= 0 && xmax >= 0) {
                
            }
        }
    }
    void Draw(RenderWindow& widnow);
    
private:
    VertexArray xAxis;
//    VertexArray yAxis;
    RectangleShape graph_window;
    int _num_grids;
    
};

#endif /* Graph_hpp */
