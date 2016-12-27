#pragma once

#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

//1
//class Bank
//{
//private:
//	//enum {size = 20};
//	string name;
//	string account;
//	long money;
//public:
//	Bank::Bank(const string Yourname, const string Youraccount, const long Yourmoney);
//	void Bank::Show();
//	void Bank::Add(long Yourmoney);
//	void Bank::Gain(string Youraccount);
//	Bank::~Bank();
//};

//2
//class person
//{
//private:
//	static const int LIMIT = 25;
//	string lname;
//	char fname[LIMIT];
//public:
//	person() { lname = "NULL"; fname[0] = '\0'; }
//	person(const string &ln, const char *fn = "heyyou");
//	void show() const;
//	void FormalShow() const;
//};

//3
//class golf
//{
//private:
//	enum{Len = 40};
//	char fullname[Len];
//	int handicap;
//public:
//	golf(const char *fullname, int hc);
//	golf(golf &g);
//	void golf::handicap1(golf &g, int hc);
//	void golf::showgolf();
//	
//	golf::~golf()
//	{
//		std::cout << "Bye" << endl;
//	}
//};

//5
//struct custom
//{
//	char fullname[35];
//	double payment;
//};
//
//class Stack
//{
//	typedef custom Item;
//private:
//	enum {MAX=10};
//	Item items[MAX];
//	int top;
//public:
//	Stack();
//	~Stack();	
//	bool isempty() const;
//	bool isfull() const;
//	//push
//	bool push(const Item &item);
//	//pop
//	bool pop(Item &item);
//};

//6
//class Move
//{
//private:
//	double x;
//	double y;
//public:
//	Move(double a = 0, double b = 0);
//	void showmove() const;
//	Move add(const Move &m) const;
//	void reset(double a = 0, double b = 0);
//};

//7
//class Betel
//{
//private:
//	enum {size=19};
//	char plorg[size];
//	int  ci;
//public:
//	Betel::Betel(const char *pl, const int c);
//	Betel(){ strcpy_s(plorg, "plorga"); }
//	void newBetel(const Betel &b, const int c = 50);
//	void Betel::modfiy(const int c);
//	void show();
//};

//8
//struct mytype
//{
//	char listarray[100];
//	int  index;
//};
//
//class List
//{
//	typedef mytype Item;
//private:
//	enum {size=10};
//	Item item[size];
//	int index;
//public:
//	List();
//	~List();
//	void List::add( Item p);
//	bool isimpty();
//	bool isfull();
//	void List::visit(void(*pf)(Item &));
};