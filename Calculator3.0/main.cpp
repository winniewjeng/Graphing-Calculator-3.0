
#include "Interface.hpp"
#include "ShuntingYard.hpp"
#include <iostream>
#include <string>
#include "Interface.hpp"
#include <SFML/Graphics.hpp>


using namespace std;

int main(int, char const**)
{
//    sf::RenderWindow window;
//    window.create(sf::VideoMode(1920,1080), "test");
//    window.setFramerateLimit(1);
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.Closed) {
//                window.close();
//            }
//        }
//        window.clear();
//
//        window.display();
//    }
    Interface p;
    p.run();
//////    run();
//    test_shunting();
    return 0;
}
