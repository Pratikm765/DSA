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

class IndianSocket{
public:
	virtual void indianCharge(int type)=0;
};

class UsaSocket{
public:
	void usaCharge(){
		cout<<"Charging in USA socket\n";
	}
};

class EuropeanSocket{
public:
	void europeanCharge(){
		cout<<"Charging in European socket\n";
	}
};

class socketAdapter: public IndianSocket, public UsaSocket,public EuropeanSocket{
public:
	void indianCharge(int type){
		switch(type)
		{
		case 1:
			usaCharge();
			break;
		case 2:
			europeanCharge();
			break;
		}
	}
};

int main() {
	unique_ptr<IndianSocket> sAdapter= make_unique<socketAdapter> ();
	sAdapter->indianCharge(1);
	sAdapter->indianCharge(2);

	return 0;
}
