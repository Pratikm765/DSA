//============================================================================
// Name        : DesignPatterns.cpp
// Author      : Pratik Mhatre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
using namespace std;

class IBackpack{
public:
	virtual void assemble()=0;
	virtual ~IBackpack(){}
};

class PlainBackpack: public IBackpack{
public:
	virtual void assemble(){
		cout<<"Main Compartment and Shoulder Strap ";
	}
};

class DecoratorBackpack: public IBackpack{
IBackpack* m_Backpack;
public:
	DecoratorBackpack(IBackpack* decorator): m_Backpack(decorator){}

	virtual void assemble(){
		m_Backpack->assemble();
	}
};

class LaptopSlot: public DecoratorBackpack{
public:
	LaptopSlot(IBackpack* decorator): DecoratorBackpack(decorator){}
	virtual void assemble(){
		DecoratorBackpack::assemble();
		cout<<"+ Laptop slot";
	}
};

class USBSlot: public DecoratorBackpack{
public:
	USBSlot(IBackpack* decorator): DecoratorBackpack(decorator){}
	virtual void assemble(){
		DecoratorBackpack::assemble();
		cout<<"+ USB PowerBank Slot";
	}
};

class BottleSlot: public DecoratorBackpack{
public:
	BottleSlot(IBackpack* decorator): DecoratorBackpack(decorator){}
	virtual void assemble(){
		DecoratorBackpack::assemble();
		cout<<"+ Water Bottle Slot";
	}
};


int main() {
	//  ---> PlainBackpack ---> IBackpack
	//  |
	//  DecoratorBackpack ---> IBackpack
	//  |
	//  LaptopSlot ---> DecoratorBackpack ---> IBackpack
	//  |
	//  USBSlot ---> DecoratorBackpack ---> IBackpack
	//  |	 
	//  BottleSlot ---> DecoratorBackpack ---> IBackpack

	IBackpack* backpack= new BottleSlot(new USBSlot(new LaptopSlot(new DecoratorBackpack(new PlainBackpack))));
	backpack->assemble();
	delete backpack;
	return 0;
}
