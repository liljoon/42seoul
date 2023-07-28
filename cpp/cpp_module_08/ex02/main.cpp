#include <iostream>
#include <stack>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> myStack;

	myStack.push(10);
	myStack.push(20);
	myStack.push(30);

	// top() 함수를 이용하여 스택의 최상위 원소에 접근
	int &topRef = myStack.top(); // topRef는 최상위 원소에 대한 레퍼런스
	std::cout << "Top element: " << topRef << std::endl;

	// 최상위 원소를 변경
	topRef = 50;
	std::cout << "Top element after modification: " << myStack.top() << std::endl;

	// const 버전의 top() 함수를 이용하여 상수 스택의 최상위 원소에 접근
	// const int &constTopRef = myStack.top();
	// std::cout << "Top element in constant stack: " << constTopRef << std::endl;

	return 0;
}
