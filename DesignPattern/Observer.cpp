//============================================================================
// Name        : DesignPatterns.cpp
// Author      : Pratik Mhatre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;
class Observer;

class Car{
	int position;
	vector<Observer*> ObserverList;
public:
	int getPosition()
	{
		return position;
	}
	int setPosition(int p)
	{
		position=p;
		notify();
	}

	void attach(Observer* o){
		ObserverList.push_back(o);
	}

	void notify();
};

class Observer{
	Car* _car;
public:
	Observer(Car* c){
		_car=c;
		_car->attach(this);
	}
	virtual void update()=0;
protected:
	Car* getCar()
	{
		return _car;
	}
};

class LeftObserver: public Observer{
public:
	LeftObserver(Car* c):Observer(c){}
	void update()
	{
		int pos=getCar()->getPosition();
		if(pos<0)
			cout<<"Left Side\n";
	}
};

class RightObserver: public Observer{
public:
	RightObserver(Car* c):Observer(c){}
	void update()
	{
		int pos=getCar()->getPosition();
		if(pos>0)
			cout<<"Right Side\n";
	}
};

class MiddleObserver: public Observer{
public:
	MiddleObserver(Car* c):Observer(c){}
	void update()
	{
		int pos=getCar()->getPosition();
		if(pos==0)
			cout<<"Straight\n";
	}
};

void Car::notify()
{
	for(int i=0;i<ObserverList.size();i++)
		ObserverList[i]->update();
}


int main() {

	Car* car=new Car();
	LeftObserver lo(car);
	RightObserver ro(car);
	MiddleObserver mo(car);

	bool drive=true;
	while(drive)
	{
		cout<<"Where to go: ";
		char c;
		cin>>c;

		switch(c)
		{
		case 'l':
			car->setPosition(-1);
			break;
		case 'r':
			car->setPosition(1);
			break;
		case 'm':
			car->setPosition(0);
			break;
		case 'b':
			drive=false;
			break;

		}

	}
	cout<<"Parking..";
	return 0;
}
