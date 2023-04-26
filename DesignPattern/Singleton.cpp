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

class DatabaseConnection{
	static DatabaseConnection* dbconn;
	string User;
	string Password;
	int Port;
	string DB;

	DatabaseConnection(string user,string pass,int port, string db){
		User=user;
		Password=pass;
		Port=port;
		DB=db;
	}
public:

	static DatabaseConnection* getConnection(){
		if(dbconn==NULL)
		{
			//mutex.lock
			//if(dbconn==NULL)
				dbconn= new DatabaseConnection("root","12345",4207,"SQL");
	  		//mutex unlock
		}

		return dbconn;
	}

	vector<int> Select(string query){
		vector<int> v;
		cout<<"Triggering "<<query<<endl;
		v.push_back(10);
		v.push_back(20);
		return v;
	}
};
DatabaseConnection* DatabaseConnection::dbconn=NULL;

int main() {

	DatabaseConnection* conn=DatabaseConnection::getConnection();
	vector<int> v=conn->Select("select * from employee");
	cout<<"Result of query:\n";
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl;

	return 0;
}
