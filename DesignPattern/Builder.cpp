//============================================================================
// Name        : DesignPatterns.cpp
// Author      : Pratik Mhatre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Plane{
	string _plane;
	string _body;
	string _engine;

public:
	Plane(string planetype):_plane{planetype}{
	}
    void setEngine(string type) { _engine = type; }
    void setBody(string body)   { _body = body;   }
    string getEngine()          { return _engine; }
    string getBody()            { return _body;   }

    void show() {
    	cout << "Plane Type: " <<_plane << endl
    		 << "Body Type: " <<_body << endl
    		 << "Engine Type: "<<_engine << endl << endl;
    }
};

class PlaneBuilder{
protected:
    Plane* plane;
public:
    virtual void getPartsDone()=0;
    virtual void buildBody()=0;
    virtual void buildEngine()=0;

    Plane* getPlane()
    {
    	return plane;
    }
};

class PropellerBuilder:public PlaneBuilder{
public:
    void getPartsDone()
    {
    	plane=new Plane("Propeller Plane");
    }
    void buildBody()
    {
    	plane->setBody("Propeller Body");
    }
    void buildEngine()
    {
    	plane->setEngine("Propeller Engine");
    }
};

class JetBuilder:public PlaneBuilder{
public:
    void getPartsDone()
    {
    	plane=new Plane("Jet Plane");
    }
    void buildBody()
    {
    	plane->setBody("Jet Body");
    }
    void buildEngine()
    {
    	plane->setEngine("Jet Engine");
    }
};

class Director{
	//PlaneBuilder* planebuilder;
public:
	Plane* createPlane(PlaneBuilder* planebuilder)
	{
		planebuilder->getPartsDone();
		planebuilder->buildBody();
		planebuilder->buildEngine();
		return planebuilder->getPlane();
	}
};


int main() {
	Director d;
	JetBuilder jb;
	PropellerBuilder pb;

	Plane* jet=d.createPlane(&jb);
	Plane* pro=d.createPlane(&pb);

	jet->show();
	pro->show();

	delete jet;
	delete pro;

	return 0;
}
