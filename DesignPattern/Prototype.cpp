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

class TravelTicket{
protected:
	int id;
	string name;
	int age;
	long mobileNo;
public:
	TravelTicket(int i):id{i}{
		name = "";
		age = 0;
		mobileNo = 0;
	}
	virtual TravelTicket* clone()=0;
	virtual void print()=0;
	virtual void changeType()=0;
	void addDetails(const string str, int a, long m){
		name= string(str);
		age = a;
		mobileNo = m;
	}
};

// If you have pointers in your properties for ex: String* name_ ,
// you will need to implement the Copy-Constructor to make sure 
// you have a deep copy from the clone method

class TrainTicket:public TravelTicket{
	int tier;
public:
	TrainTicket(int i,int t):tier(t),TravelTicket(i){}
	TravelTicket* clone()
	{
		return new TrainTicket(*this);
	}
	void changeType()
	{
	    int t;
	    cout << "Enter Tier: ";
	    cin >> t;
		tier = t;
	}
	void print()
	{
		cout<<"Train Ticket Needed..\n";
		cout<<"Ticket id : "<<id;
		string temp; 
		if(tier == 0) 
		    temp = "SL";
		else if(tier == 1)   
		    temp = "First AC";
		else if(tier == 2)
		    temp = "Second AC";
		else
		    temp = "Third AC";
		cout<<" Tier: "<< temp<<endl;
		cout<<"Details : \n";
		cout<<"Name: " << name<<endl;
		cout<<"Age: " << age<<endl;
		cout<<"Mobile: " << mobileNo<<endl; 
	}
};

class FlightTicket:public TravelTicket{
	char _class; 
public:
	FlightTicket(int i,char c):_class(c),TravelTicket(i){}
	TravelTicket* clone()
	{
		return new FlightTicket(*this);
	}
	void changeType()
	{
	    char c;
	    cout << "Enter Class: ";
	    cin >> c;
		_class = c;
	}
	void print()
	{
		cout<<"Flight Ticket Needed..\n";
		cout<<"Ticket id : "<<id;
		cout<<" Class: "<<(_class == 'e' ? "Economy":"Business")<<endl;
		cout<<"Details : \n";
		cout<<"Name: " << name<<endl;
		cout<<"Age: " << age<<endl;
		cout<<"Mobile: " << mobileNo<<endl; 
	}
};

class BusTicket:public TravelTicket{
	string type;
public:
	BusTicket(int i,string pu):type(pu),TravelTicket(i){}
	TravelTicket* clone()
	{
		return new BusTicket(*this);
	}
	void changeType()
	{
	    string s;
	    cout << "Enter Type: ";
	    cin >> s;
		type = s;
	}
	void print()
	{
		cout<<"Bus Ticket Needed..\n";
		cout<<"Ticket id : "<<id<<;
		cout<<" Type: "<<type<<endl;
		cout<<"Details : \n";
		cout<<"Name: " << name<<endl;
		cout<<"Age: " << age<<endl;
		cout<<"Mobile: " << mobileNo<<endl; 
	}
};

class TicketCounter{
	static vector<TravelTicket*> ticketList;
public:
	TicketCounter(){
		ticketList.push_back(new TrainTicket(100,3));
		ticketList.push_back(new FlightTicket(101,'e'));
		ticketList.push_back(new BusTicket(102,"sleeper"));
	}

	~TicketCounter(){
	    for(auto ticket : ticketList)
    	    delete ticket;
    	ticketList.clear();		
	}

	TravelTicket* getTicket(int choice){
		return ticketList[choice]->clone();
	}
};
vector<TravelTicket*> TicketCounter::ticketList;

void ClientCode(TicketCounter& tcounter){
	// int ticketType; cin >> ticketType;
	// TravelTicket* ticket=tcounter.getTicket(ticketType);
	while(true){
		int t;
		cout << "Which Ticket do you want\n";
		cout << "Enter 0 for Train\n";
		cout << "Enter 1 for Flight\n";
		cout << "Enter 2 for Bus\n";
		cout << "Enter 3 to exit \n";
		cin >> t;

		if(t == 3)
			break;

		TravelTicket* ticket=tcounter.getTicket(t);
		ticket->addDetails("John",40,9876543210);
		ticket->changeType();
		ticket->print();
		delete ticket;
	}

}

int main() {

	TicketCounter* tcounter = new TicketCounter();
	ClientCode(*tcounter);

	delete tcounter;
	return 0;
}
/* 
class TravelTicket{
protected:
	int id;
public:
	TravelTicket(int i):id{i}{}
	virtual ~TravelTicket(){}
	virtual TravelTicket* clone()=0;
	virtual void print()=0;
};



class TrainTicket:public TravelTicket{
public:
	TrainTicket(int i):TravelTicket(i){}
	~TrainTicket(){}
	TravelTicket* clone()
	{
		return new TrainTicket(*this);
	}
	void print()
	{
		cout<<"Train Ticket Needed..\n";
		cout<<"Ticket id : "<<id<<endl;
	}
};

class FlightTicket:public TravelTicket{
public:
	FlightTicket(int i):TravelTicket(i){}
	~FlightTicket(){}
	TravelTicket* clone()
	{
		return new FlightTicket(*this);
	}
	void print()
	{
		cout<<"Flight Ticket Needed..\n";
		cout<<"Ticket id : "<<id<<endl;
	}
};

class BusTicket:public TravelTicket{
public:
	BusTicket(int i):TravelTicket(i){}
	~BusTicket(){}
	TravelTicket* clone()
	{
		return new BusTicket(*this);
	}
	void print()
	{
		cout<<"Bus Ticket Needed..\n";
		cout<<"Ticket id : "<<id<<endl;
	}
};

class TicketCounter{
	static vector<TravelTicket*> ticketList;
public:
	static TravelTicket* getTicket(int choice){
		return ticketList[choice]->clone();
	}
	static void clearTickets(){
	    for(auto ticket : ticketList)
    	    delete ticket;
    	ticketList.clear();
	}
};
vector<TravelTicket*> TicketCounter::ticketList 
        = {new TrainTicket(100),new FlightTicket(101),new BusTicket(102)};

int main() {
	TravelTicket* ticket=TicketCounter::getTicket(1);
	ticket->print();
	
	delete ticket;
	TicketCounter::clearTickets();
	
	return 0;
}
*/
