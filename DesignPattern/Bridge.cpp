//============================================================================
// Name        : DesignPatterns.cpp
// Author      : Pratik Mhatre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Movement{
public:
	virtual void makeMove()=0;
};
class fly:public Movement{
public:
	void makeMove()
	{
		cout<<"Flying..\n";
	}
};
class walk:public Movement{
public:
	void makeMove()
	{
		cout<<"Walking..\n";
	}
};
class swim:public Movement{
public:
	void makeMove()
	{
		cout<<"Swimming..\n";
	}
};

class Animal{
protected:
	Movement* mv;
public:
	Animal(Movement* m):mv{m}{}
	virtual void howIMove()=0;
};

class Human:public Animal{
public:
	Human(Movement* m):Animal(m){}
	void howIMove()
	{
		mv->makeMove();
	}
};
class Bird:public Animal{
public:
	Bird(Movement* m):Animal(m){}
	void howIMove()
	{
		mv->makeMove();
	}
};
class Fish:public Animal{
public:
	Fish(Movement* m):Animal(m){}
	void howIMove()
	{
		mv->makeMove();
	}
};


int main() {

	Movement* f=new fly();
	Movement* w=new walk();
	Movement* s=new swim();

	Animal* fish=new Fish(s);
	Animal* human=new Human(w);
	Animal* bird=new Bird(f);

	fish->howIMove();
	human->howIMove();
	bird->howIMove();


	return 0;
}
