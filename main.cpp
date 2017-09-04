#include <iostream>
#include <cmath>
#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

//Variables
const int WIDTH = 100, HEIGHT = 100;
float scale = 4.0f;
int factor = 1;
sf::Image grid;
sf::Texture draw;
sf::Sprite print;
sf::RenderWindow window;

int main(int argc, char** argv) {
    cout << "Overpopulation" << endl;
    
    //Initialization
    if (!draw.create(WIDTH, HEIGHT)) {return -1;}
    grid.create(WIDTH, HEIGHT, sf::Color(255, 255, 255));
    
    window.create(sf::VideoMode(WIDTH*scale, HEIGHT*scale), "Overpopulation", sf::Style::Titlebar | sf::Style::Close);
    
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int k = rand() % 24 + 1;
            //int l = rand() % 10;
            //if (l == 1)
            grid.setPixel(i,j, sf::Color(k*10,k*10,k*10));
        }
    }
    
    sf::Event event;
    sf::Clock clock;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        
        sf::Time elapsed = clock.getElapsedTime();
        //cout << elapsed.asMicroseconds() << endl;
        if (elapsed >= sf::seconds(0.01f)) {clock.restart(); cout << "update" << endl;
            for (int i = 1; i < WIDTH-1; i++) {
                for (int j = 1; j < HEIGHT-1; j++) {
                    
                    int xn, yn;
                    sf::Color pixel = grid.getPixel(i,j);
                    for (int k = i-factor; k<i+factor; k++){ for (int l = j-factor; l<j+factor; l++){
                        if(grid.getPixel(k,l).r > pixel.r) {pixel = grid.getPixel(k,l); xn = k; yn = j;}
                    }}
                    if (pixel.r > grid.getPixel(i,j).r) {
                        pixel.r = pixel.r - 10;
                        pixel.g = pixel.g - 10;
                        pixel.b = pixel.b - 10;
                        pixel = sf::Color(grid.getPixel(xn,yn).r + 10,grid.getPixel(xn,yn).g + 10,grid.getPixel(xn,yn).b + 10);
                        grid.setPixel(xn, yn, pixel);
                        cout << "!22!" << endl;
                    } 
                    
                }
            }
        }
        
        draw.update(grid);
        window.clear();
        print.setTexture(draw, false);
        print.setScale(scale,scale);
        window.draw(print);
        
        //window.clear(sf::Color(30, 30, 30));
        window.display();
    }
    return 0;
}

