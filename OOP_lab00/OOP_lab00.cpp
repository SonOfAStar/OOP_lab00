// OOP_lab00.cpp : This file contains the 'main' function. Program execution begins and ends there.
//variant №6

#include <cstdlib>
#include "pch.h"
#include "Triangle.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"


int main() {

	char c

	std::cout << "Please, type in five points in std coordinate system. Do not forget the order!!" << std::endl;
	Figure *penta_ptr = new Pentagon(std::cin);
	penta_ptr->Print();
	std::cout << penta_ptr->Square() << std::endl;
	delete penta_ptr;

	std::cout << "Please, type in six points in std coordinate system. Do not forget the order!!" << std::endl;
	Figure *hexa_ptr = new Hexagon(std::cin);
	hexa_ptr->Print();
	std::cout << hexa_ptr->Square() << std::endl;
	delete hexa_ptr;

	std::cout << "Please, type in eight points in std coordinate system. Do not forget the order!!" << std::endl;
	Figure *octa_ptr = new Octagon(std::cin);
	octa_ptr->Print();
	std::cout << octa_ptr->Square() << std::endl;
	delete octa_ptr;

	return 0;
}