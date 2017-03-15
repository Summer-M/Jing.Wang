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
#define SortType  int
#define RECTANGULAR_SPACE  10
#define RECTANGULAR_NUMBER 80

//! the statement
static unsigned int	BaseNumber(37);
static unsigned int StepInNormal(0);
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

#define  TOP		  0
#define  LEFT		  0

#define  PICBOX1BELOW		400 
#define  PICBOX1RIGHT		570

#define  PICBOX2BELOW		400 
#define  PICBOX2RIGHT		570

/*
	Draw the basic warrior
*/
#define Circlesize	180
#define CircleW		25
#define CircleH		25
