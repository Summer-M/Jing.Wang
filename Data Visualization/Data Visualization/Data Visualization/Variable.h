#pragma once

#include <iostream>
#include <vector>

using namespace std;

//! \file
//! This file define the global variable
//! The rule of use:
//! 1): Don't frequent use of global variables.
//! 2): Naming conventions,Keep the habit.
//! 3): The global variables Maybe is just a temporary strategy,as far as possible to avoid the use of global variables.
//! 4): Check when using global variables or the name of the namespace.
//! 5): Must have a comment about global variables.
//! 6): Others.


// --------------------------------------------------------------------
//|							 About Sort								   |
// --------------------------------------------------------------------

//! template
//template <typename T,int n>
//class InSort
//{
//public:
//	static std::vector<T> IArraysize;
//};
//
//template<typename T,int n>
//T InSort<T,n>::IArraysize;

//! define
#define SortType  long long
#define RECTANGULAR_SPACE  60
#define RECTANGULAR_NUMBER 13

//! the statement
static std::vector<SortType> IArraysize;
static vector<SortType> Every_Step_Of_The_Change;
static vector< vector<SortType> > Every_Step_Of_The_Value;
// --------------------------------------------------------------------
//|					      About LinkedList						       |
// --------------------------------------------------------------------

// --------------------------------------------------------------------
//|					      About Tree							       |
// --------------------------------------------------------------------

// --------------------------------------------------------------------
//|					      About Algorithm						       |
// --------------------------------------------------------------------

/*
	Draw the area
*/
#
#define  BELOW		665 
#define  TOP		  0
#define  LEFT		  0
#define  RIGHT		585

/*
	Draw the basic warrior
*/
#define Circlesize	40
#define CircleW		5
#define CircleH		5





