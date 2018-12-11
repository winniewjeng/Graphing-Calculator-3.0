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
    void Draw(RenderWindow& widnow);
    
private:
    
    RectangleShape graph_window;
};

#endif /* Graph_hpp */
