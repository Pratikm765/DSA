//============================================================================
// Name        : DesignPatterns.cpp
// Author      : Pratik Mhatre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
using namespace std;

enum carType{
	petrol=0,
	diesel,
	electric
};

string getTypeString(carType t)
{
	switch(t){
	case petrol:
		return "Petrol";
	case diesel:
		return "Diesel";
	case electric:
		return "Electric";
	default:
		return "Unknown";
	}
}
enum countries{
	india=0,
	us
};

string getCountryString(countries c){
	switch(c){
	case india:
		return "INDIA";
	case us:
		return "United States of America";
	default:
		return "Global";
	}
}

class Car{
carType carModel;
countries location;
int MfgYear;

public:

	Car(carType CarModel,countries Location){
		carModel=CarModel;
		location=Location;
	}

	virtual void AssembleCar()=0;
	
	virtual void GetParts()=0;

	void setYear(int year){
		MfgYear=year;
	}

	void printDetails()
	{
		cout<<"Your Car is Ready. Here are the Details :\n";
		cout<<"Model: "<< getTypeString(carModel)<<endl;
		cout<<"Manufactured Year: " << MfgYear << endl;
		cout<<"Manufactured Country: "<<getCountryString(location)<<endl;
	}
};

class Petrol:public Car{
public:
	Petrol(countries c):Car(petrol,c){

	}
	void GetParts(){
		cout<<"Petrol Cars manufacturing\n";
	}
	
	void AssembleCar(){
	    cout<<"Assembling petrol car\n";
	}

};
class Diesel:public Car{
public:
	Diesel(countries c):Car(diesel,c){

	}
	void GetParts(){
		cout<<"Diesel Cars manufacturing\n";
	}
	
	void AssembleCar(){
	    cout<<"Assembling diesel car\n";
	}

};
class Electric:public Car{
public:
	Electric(countries c):Car(electric,c){

	}
	void GetParts(){
		cout<<"Electric Cars manufacturing\n";
	}
	
	void AssembleCar(){
	    cout<<"Assembling electric car\n";
	}

};

class CarFactory{
public:
	virtual Car* buildCars(carType type) = 0;
};

class IndiaFactory: public CarFactory{
public:
    Car* buildCars(carType c) override{
		Car* car=NULL;

		switch(c){
		case petrol:
			car=new Petrol(india);
			break;
		case diesel:
			car=new Diesel(india);
			break;
		case electric:
			car=new Electric(india);
			break;
		default:
			break;
		}
		return car;
	}
};

class usaFactory: public CarFactory{
public:
	Car* buildCars(carType c) override{
		Car* car=NULL;

		switch(c){
		case petrol:
			car=new Petrol(us);
			break;
		case diesel:
			car=new Diesel(us);
			break;
		case electric:
			car=new Electric(us);
			break;
		default:
			break;
		}
		return car;
	}
};

void ClientCode(CarFactory* factory, carType c){
    std::time_t t = std::time(nullptr);
    std::tm *const pTInfo = std::localtime(&t);
  
    Car* car = factory->buildCars(c);
    car->GetParts();
    car->AssembleCar();
    car->setYear(1900 + pTInfo->tm_year);
    car->printDetails();
    delete car;
}

int main() {
    IndiaFactory* factory1 = new IndiaFactory();
    ClientCode(factory1,electric);
    delete factory1;
    
    usaFactory* factory2 = new usaFactory();
    ClientCode(factory2,diesel);
    delete factory2;
	return 0;
}

/*
#include <iostream>
using namespace std;

enum carType{
	petrol=0,
	diesel,
	electric
};

string getTypeString(carType t)
{
	switch(t){
	case petrol:
		return "Petrol";
	case diesel:
		return "Diesel";
	case electric:
		return "Electric";
	default:
		return "Unknown";
	}
}
enum countries{
	india=0,
	us
};

string getCountryString(countries c){
	switch(c){
	case india:
		return "INDIA";
	case us:
		return "United States of America";
	default:
		return "Global";
	}
}

class Car{
carType carModel;
countries location;

public:

	Car(carType CarModel,countries Location){
		carModel=CarModel;
		location=Location;
	}

	virtual void buildCar()=0;

	carType getCarModel(){
		return carModel;
	}

	void setCarModel(carType CarModel){
		carModel=CarModel;
	}

	countries getLocation(){
		return location;
	}

	void setLocation(countries Location){
		location=Location;
	}

	void printDetails()
	{
		cout<<"CarDetails\n";
		cout<<"Model: "<< getTypeString(carModel)<<endl;
		cout<<"Manufactured in: "<<getCountryString(location)<<endl;
	}
};

class Petrol:public Car{
public:
	Petrol(countries c):Car(petrol,c){

	}
	void buildCar(){
		cout<<"Petrol Car manufacturing\n";
	}

};
class Diesel:public Car{
public:
	Diesel(countries c):Car(diesel,c){

	}
	void buildCar(){
		cout<<"Diesel Car manufacturing\n";
	}

};
class Electric:public Car{
public:
	Electric(countries c):Car(electric,c){

	}
	void buildCar(){
		cout<<"Electric Car manufacturing\n";
	}

};

class IndiaFactory{
public:
	static Car* buildCar(carType c){
		Car* car=NULL;

		switch(c){
		case petrol:
			car=new Petrol(india);
			break;
		case diesel:
			car=new Diesel(india);
			break;
		case electric:
			car=new Electric(india);
			break;
		default:
			break;
		}
		return car;
	}
};

class usaFactory{
public:
	static Car* buildCar(carType c){
		Car* car=NULL;

		switch(c){
		case petrol:
			car=new Petrol(us);
			break;
		case diesel:
			car=new Diesel(us);
			break;
		case electric:
			car=new Electric(us);
			break;
		default:
			break;
		}
		return car;
	}
};

class CarFactory{
public:
	static Car* buildFactory(carType type)
		{
	        Car* car = NULL;
	        countries location = us;

	        switch(location)
	        {
	            case us:
	                car = usaFactory::buildCar(type);
	                break;

	            case india:
	                car = IndiaFactory::buildCar(type);
	                break;

	            default:
	                //car = DefaultCarFactory.buildCar(type);
	            	break;
	        }
	        return car;
	    }
};


int main() {

	Car* car=CarFactory::buildFactory(electric);
	car->buildCar();
	car->printDetails();
	delete car;
	return 0;
}
*/