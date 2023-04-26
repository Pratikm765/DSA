#include<bits/stdc++.h>
using namespace std;

class Shape{
public:
    virtual void draw() = 0;
};

class Circle: public Shape{
int x;
int y;
int radius;
string color;
public:
    Circle( string Color){
        color = Color;
    }

    void setX(int X){
        x = X;
    }

    int getX(){
        return x;
    }

    void setY(int Y){
        y = Y;
    }

    int getY(){
        return y;
    }

    void setRadius(int R){
        radius = R;
    }

    int getRadius(){
        return radius;
    }

    void draw(){
        cout << "Drawing " << color <<  " Circle At position (" 
            << x << "," << y << ") with radius " << radius << endl;
    }
};

class Shapefactory{
unordered_map<string,Circle*> CircleMap;
public:
    Circle* getCircle(string color){
        Circle* c = CircleMap[color];
        if(c == NULL)
        {
            c = new Circle(color);
            CircleMap[color] = c;
            cout << "creating a circle of " << color << endl;
        }
        return c;
    }
};

int main(){
    string colors[5] = {"Red","Green","Yellow","Blue","Orange"};

    Shapefactory* sf = new Shapefactory();

    for(int i = 0; i < 20; i++){
        string color = colors[rand() % 5];
        int x = rand() % 100;
        int y = rand() % 100;
        int radius = rand() % 10;

        Circle* c = sf->getCircle(color);
        c->setX(x);
        c->setY(y);
        c->setRadius(radius);

        c->draw();
    }
}