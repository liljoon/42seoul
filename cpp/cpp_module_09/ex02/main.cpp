#include "PmergeMe.hpp"
#include <vector>

int main()
{
	std::vector<int> v;

	v.push_back(2);
	v.push_back(4);
	v.push_back(1);
	v.push_back(3);
	v.push_back(7);
	v.push_back(10);
	v.push_back(9);
	v.push_back(8);
	v.push_back(100);

	PmergeMe<int, 15>::sort_v(v);

	for(size_t i = 0;i < v.size();i++)
		std::cout << v[i] << std::endl;
}

// #include <iostream>

// // 템플릿 재귀를 이용한 팩토리얼 계산 함수
// template <int N>
// struct Factorial
// {
// 	static const int value = N * Factorial<N - 1>::value;
// };

// // 템플릿 재귀의 기저조건(Basis case)
// template <>
// struct Factorial<0>
// {
// 	static const int value = 1;
// };

// int main()
// {
// 	const int result = Factorial<5>::value;
// 	std::cout << "Factorial of 5 is: " << result << std::endl;
// 	return 0;
// }
