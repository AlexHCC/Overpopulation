#include <iostream>
#include <cmath>
#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

//Variables
const int WIDTH = 400, HEIGHT = 400;
sf::RenderWindow window;

int main(int argc, char** argv) {
    cout << "Overpopulation" << endl;
    
    window.create(sf::VideoMode(WIDTH, HEIGHT), "Overpopulation", sf::Style::Titlebar | sf::Style::Close);
    
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(30, 30, 30));
        window.display();
    }
    return 0;
}

