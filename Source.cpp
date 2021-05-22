#include <iostream>
#include <memory>
#include "ClassRep.h"


int main()
{
	std::cout << "\n\n\t *** smart pointer demo ***\n\n";
	
	//std::unique_ptr<ClassRep> myRep = std::make_unique<ClassRep>();
	
	//PRO: The pointer is destroyed WHen the functen is destroyed
	//CON: Isnt as flexible as a unique pointer deprecated as of C++11
	std::auto_ptr<ClassRep> autoPTR(new ClassRep);
	autoPTR->Talk("Hello from auto pointer!");

	//PRO: This pointer cant be shared it is used were you need to allocate momory for one function
	//CON: cant be shared and dies with the function
	std::unique_ptr<ClassRep> uniquePTR = std::make_unique<ClassRep>();
	uniquePTR->Talk("Hello from unique pointer!");

	//PRO: a shared pointer can as the name implies can be shared with other functions 
	//CON: can cause issues in you dont need to share the pointer and you use a shared pointer. 
	std::shared_ptr<ClassRep> sharedPTR = std::make_shared<ClassRep>();
	sharedPTR->Talk("Hello from shared pointer!");

	//PRO: Does not add to ref count useful for non important things
	//CON: unlike a shared pointer it isnt kept alive
	std::weak_ptr<ClassRep> weakPTR = sharedPTR;
	//weakPTR->Talk("Hello From the weak pointer");

	return 0;
}