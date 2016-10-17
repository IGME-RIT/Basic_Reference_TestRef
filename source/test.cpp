/*
	Multithreading Issues
	(c) 2016
	original authors: David I. Schwartz
	Written under the supervision of David I. Schwartz, Ph.D., and
	supported by a professional development seed grant from the B. Thomas
	Golisano College of Computing & Information Sciences
	(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or (at
	your option) any later version.
	This program is distributed in the hope that it will be useful, but
	WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.

	* This tutorial illustrates concept of reference, initialization 
	reference variable, the difference between reference and operator &, const
	reference.
*/



#include <iostream>
using namespace std;

int main() {

#pragma region Basic references

	// make refToX refer to x:
	// https://msdn.microsoft.com/en-us/library/dz43scw4.aspx
	cout << "Test 1:" << endl; // output: Test 1:
	int x = 1;                 // x gets 1
	int& refToX = x;           // refToX refers to x		
	cout << &x << endl;        // address of x (operator)	output: 005DFD34
	cout << refToX << endl;    // value of refToX			output: 1
	cout << &refToX << endl;   // address of refToX			output: 005DFD34
							   // (msdn)A reference stores the address of an object located elsewhere in memory
	
	// what happens after changing refToX?
	cout << "Test 2:" << endl; // output: Test 2:
	refToX++;                  // are we changing refToX or X? 
	cout << refToX << endl;    // output: 2
	cout << x << endl;         // output: 2

	// attempt to reseat refToX:
	// http://msdn.microsoft.com/en-us/library/szywdw8k.aspx
	cout << "Test 3:" << endl; // output: Test 3:
	int y = 3;                 // y gets 3
	refToX = y;                // change refToX to y
	y *= 2;                    // y gets twice the original (y get 6 now)
	cout << refToX << endl;    // output: 3
	cout << x << endl;         // output: 3
	cout << y << endl;         // output: 6

	// attempt to assign a ref:
	//int& z = 10;             // ?? (initial value of reference must be a lvalue)

	// attempt to dereference a ref:
	cout << "Test 4:" << endl;  // output: Test 4:
	int a = 10;                 // a gets 10
	int& r1 = a;                // r1 refers to a 
	//cout << *r1 << endl;      // OK? no. can not deference a reference
	//cout << r1 << endl;       // OK? yes.
	// reason? reference is an alias not a pointer

	// mixing up reference and address operators?
	// http://msdn.microsoft.com/en-us/library/w7049scy.aspx
	int b1 = 10;               // b1 gets 10
	//int& b2 = &b1;           // ? illegal. b2 should refer to an int variable
	//int& b2 = (int&)(&b1);   // ? illegal. the address of b1 is not a lvalue

	// reference to reference?
	int v1 = 10;              // initialize int variable v1, give it value 10
	int& rr1 = v1;            // initialize reference rr1, refers to v1
	// (int&)& rr2 = &r1;     // illegal

	// references and pointers?
	// http://msdn.microsoft.com/en-us/library/1sf8shae.aspx
	cout << "Test 5:" << endl;  // output: Test 5:
	int v2 = 20;                // v2 gets 20
	int* p1 = &v2;              // initialize a pointer p1 which points to a int type, put the address of v2 to p1
	cout << &p1 << endl;		// output: 00C4FAA8 (random)
	//int&* p2 = &v2;           // illegal: a pointer to reference is not allowed
	int*& p2 = p1;              // initialize a reference refers to a pointer, put p1 to p2 
	cout << &p2 << endl;        // output: 00C4FAA8 (the same address number as p1)
	cout << *p2 << endl;        // output: 20  (p2 is the alias of the pointer p1 and points to the same adress)
	int v3 = 30;                // initialize integer variable v3. put 30 to v3.
	p2 = &v3;                   // put the adress of v3 to p2, now p2 points to v3
	cout << *p1 << endl;        // output: 30  (print out the dereference of p1) p1 is also changed.

	// references and NULL?
	cout << "Test 6:" << endl;  // output: Test 6:
	int* p3 = nullptr;          // initialize null pointer p3
	int& r0 = *p3;              // initialize reference r0 refers to a int type, put the derefernce of p3 to r0
	cout << p3 << endl;         // output: 00000000
	//cout << *p3 << endl;      // not allowed to dereference a null pointer 
	//cout << r0 << endl;       // not allowed to print out the reference refers to the null pointer
								// see: http://stackoverflow.com/questions/6793262/why-dereferencing-a-null-pointer-is-undefined-behaviour

	// const
	cout << "Test 7:" << endl;  // output: Test 7:
	int c = 10;                 // initialize integer variable c. put 10 to c.
	const int& refC = c;        // initialize a const reference refC refers to an integer. put c to refC
	int d = 30;                 // initialize integer variable d. put 30 to d.
	cout << refC << endl;       // output: 10
	c = 20;                     // put 20 to c
	//refC = d;                 // illegal (can not assign to a const variable)
	//int& const refD = d;      // legal
	//int const& refD = d;      // legal
	

#pragma endregion
}