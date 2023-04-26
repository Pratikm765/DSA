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

class WaiterSubSystem{
public:
	void TakeOrder(){
		cout<<"Whats Your Order Sir?"<<endl;
	}
	void SendToKitchen(){
		cout<<"One Fried Rice on Table No. 10"<<endl;
	}
	void ServeCustomer(){
		cout<<"Sir, Here is your order"<<endl;
	}
};

class CookSubSystem{
public:
	void CookFood(){
		cout<<"Cooking Fried Rice"<<endl;
	}
	void CallWaiter(){
		cout<<"Fried Rice is Ready"<<endl;
	}
};

class HelperSubSystem{
public:
	void PreparingIngredients(){
		cout<<"Cutting Vegetables and Chicken"<<endl;
	}
	void WashDishes(){
		cout<<"Washing Dishes"<<endl;
	}
};

class OrderFacade{
	WaiterSubSystem waiter;
	CookSubSystem cook;
	HelperSubSystem helper;
public:

	void Order(){
		waiter.TakeOrder();
		waiter.SendToKitchen();
		helper.PreparingIngredients();
		cook.CookFood();
		cook.CallWaiter();
		waiter.ServeCustomer();
		helper.WashDishes();
	}
};


int main() {

	OrderFacade order;
	order.Order();
	return 0;
}