#pragma once
#include <iostream>
#include <string>
#include <vector>
//создание базового класса для наследования
class Languages {
protected:
	std::string m_extension;
public:
	Languages() {
		std::cout << "Base class: CONSTRUCTOR" << std::endl;
	};
	virtual ~Languages() {
		std::cout << "Base class: DESTRUCTOR" << std::endl;
	};

	virtual std::string someRelatedThing() = 0;

};
