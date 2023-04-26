//============================================================================
// Name        : DesignPatterns.cpp
// Author      : Pratik Mhatre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

enum VegetableType{
	onion=0,
	potato,
	garlic,
	tomato
};

class Vegetable{
public:
	virtual void printVegetable()=0;
	static Vegetable* Produce(int type);
};

class Onion:public Vegetable{
public:
	void printVegetable()
	{
		cout<<" Pack 1KG Onions "<<endl;
	}
};

class Potato:public Vegetable{
public:
	void printVegetable()
	{
		cout<<" Pack 1KG Potatoes "<<endl;
	}
};

class Garlic:public Vegetable{
public:
	void printVegetable()
	{
		cout<<" Pack 1KG Garlic "<<endl;
	}
};

class Tomato:public Vegetable{
public:
	void printVegetable()
	{
		cout<<" Pack 1KG Tomatoes "<<endl;
	}
};

Vegetable* Vegetable::Produce(int type){
	switch(type)
	{
	case onion:
		return new Onion;
	case potato:
		return new Potato;
	case garlic:
		return new Garlic;
	case tomato:
		return new Tomato;
	default:
		return NULL;
	}
}

class Client{
public:
	Client(int type){
		vegetable=Vegetable::Produce(type);
	}
	~Client(){
		if(vegetable){
			delete vegetable;
		}
	}
	Vegetable* getVeggie(){
		return vegetable;
	}
private:
	Vegetable *vegetable;
};

int main() {
	while(true){
		int type;
		cout<<"What you need Sir..?"<<endl;
		cin >>type;
		if(type==5)
			break;

		Client* cli=new Client(type);
		Vegetable* veggie= cli->getVeggie();
		veggie->printVegetable();
		delete cli;
	}
	return 0;
}
