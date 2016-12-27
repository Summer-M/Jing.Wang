
#include "Header.h"

//1
//Bank::Bank(const string Yourname, const string Youraccount, const long Yourmoney)
//{
//	name = Yourname;
//	account = Youraccount;
//	money = Yourmoney;
//}
//
//void Bank::Show()
//{
//	cout << name << endl;
//	cout << account << endl;
//	cout << money << endl;
//}
//
//void Bank::Add(long Yourmoney)
//{
//	cout << money + Yourmoney << endl;
//}
//
//void Bank::Gain(string Youraccount)
//{
//
//	cout << money << endl;
//}
//
//Bank::~Bank()
//{
//	//delete 
//}

//2
//person::person(const string &ln, const char *fn)
//{
//	person::lname = ln;
//	strcpy_s(person::fname,fn);															//!< warning
//}
//
//void person::show() const
//{
//	cout << person::fname;
//	cout << person::lname << endl;
//}
//
//void person::FormalShow() const
//{
//	cout << person::lname;
//	cout << person::fname << endl;
//}

//3
//golf::golf(const char *fullname, int hc)
//{
//	strcpy_s(golf::fullname,fullname);
//	golf::handicap = hc;
//}
//
//golf::golf(golf &g)
//{
//	// the assignment
//	(*this) = g;
//}
//
//void golf::handicap1(golf &g, int hc)
//{
//	g.handicap = hc;
//}
//
//void golf::showgolf()
//{
//	cout << golf::fullname << endl;
//	cout << golf::handicap << endl;
//}


//5
//Stack::Stack()
//{
//	top = 0;
//}
//
//Stack::~Stack()
//{
//	cout << "Over" << endl;
//}
//
//bool Stack::isempty() const
//{
//	return top == 0;
//}
//
//bool Stack::isfull() const
//{
//	return top == MAX;
//}
//
////push
//bool Stack::push(const Item &item)
//{
//	if (top < MAX)
//	{
//		items[top++] = item;
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
////pop
//bool Stack::pop(Item &item)
//{
//	if (top > 0)
//	{
//		item = items[--top];
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

//6

//Move::Move(double a = 0, double b = 0)
//{
//	x = a;
//	y = b;
//}
//
//void Move::showmove() const
//{
//	cout << x << endl;
//	cout << y << endl;
//}
//void Move::reset(double a = 0, double b = 0)
//{
//
//}
//
//Move add(const Move &m) const
//{
//
//}

//7
//Betel::Betel(const char *pl,const int c)
//{
//	strcpy_s( Betel::plorg, pl );
//	Betel::ci = c;
//}
//
//void Betel::newBetel(const Betel &b, const int c)
//{
//	strcpy_s(Betel::plorg, b.plorg);
//	Betel::ci = c;
//}
//
//void Betel::modfiy(const int c)
//{
//	Betel::ci = c;
//}
//
//void Betel::show()
//{
//	cout << Betel::plorg << endl;
//	cout << Betel::ci << endl;
//}

//8
//List::List()
//{
//	List::index = 0;
//}
//
//List::~List()
//{
//	//delete
//}
//
//void List::add(Item p)
//{	
//	if (!List::isfull())
//	{
//		List::item[index] = p;
//		index++;
//	}
//	else
//	{
//		cout << "The List is full" << endl;
//	}
//}
//
//bool List::isimpty()
//{
//	return List::index == 0;
//}
//
//bool List::isfull()
//{
//	return List::index == size;
//}
//
//void List::visit(void (*pf)(Item &))
//{
//	for (size_t i = 0; i < index; i++)
//	{
//		(*pf)(item[i]);
//	}
//}

