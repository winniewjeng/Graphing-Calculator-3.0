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

//void Graph::getXAxis(double xmin, double xmax) {
//    xAxis.clear();
//
//}
//VertexArray Graph::PlotXAxis() {
//
//    xAxis = VertexArray(sf::LinesStrip, 3);
//    xAxis[0].position = sf::Vector2f(0, WINDOW_HEIGHT/2);
//    xAxis[0].color = sf::Color::Black;
//    xAxis[1].position = sf::Vector2f(GRAPH_PANEL/2, WINDOW_HEIGHT/2);
//    xAxis[1].color = sf::Color::White;
//    xAxis[2].position = sf::Vector2f(GRAPH_PANEL, WINDOW_HEIGHT/2);
//    xAxis[2].color = sf::Color::Black;
//
//    return xAxis;
//}
//
//VertexArray Graph::PlotYAxis() {
//
//    yAxis = sf::VertexArray(sf::LinesStrip, 3);
//    yAxis[0].position = sf::Vector2f(GRAPH_PANEL/2, 0);
//    yAxis[0].color = sf::Color::Black;
//    yAxis[1].position = sf::Vector2f(GRAPH_PANEL/2, WINDOW_HEIGHT/2);
//    yAxis[1].color = sf::Color::White;
//    yAxis[2].position = sf::Vector2f(GRAPH_PANEL/2, WINDOW_HEIGHT);
//    yAxis[2].color = sf::Color::Black;
//
//    return yAxis;
//}

void Graph::Draw(sf::RenderWindow& window){
    window.clear();
    window.draw(graph_window);
//    window.draw(PlotYAxis());
//    window.draw(PlotXAxis());
}



