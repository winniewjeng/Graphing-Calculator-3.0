//
//  Graph.cpp
//  Calculator3.0
//
//  Created by Winnie Jeng on 12/3/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include "Graph.hpp"

Graph::Graph() {
    //set up the graph rectangle:
    graph_window.setFillColor(Color(50, 50, 50));
    graph_window.setPosition(0, 0); // align left
    graph_window.setSize(Vector2f(GRAPH_PANEL, WINDOW_HEIGHT));
}

void Graph::Draw(sf::RenderWindow& window){
    window.clear();
    window.draw(graph_window);
}




