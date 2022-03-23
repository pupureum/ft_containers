#include <iostream>
#include <iomanip>
#include "vector.hpp"
#include <vector>
#include <string>
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_NOMAL "\033[0m"
#define COLOR_BLUE "\033[34m"
#define COLOR_YELLOW "\033[33m"
#define BG_CYAN "\x1b[46m"

void print(ft::vector<int> &v, std::vector<int> &std_vector)
{
//     ft::vector<int>::const_iterator it = v.begin();
// 	ft::vector<int>::const_iterator ite = v.end();
// 	std::vector<int>::const_iterator std_it = std_vector.begin();

// for (; it != ite; it++)
// 	{
// 		std::cout << std::setw(10) << "ft_vectorector: " << *it;
// 		std::cout << "/ std_vectorector: " << *std_it;
// 		std::cout << std::endl;
// 		std_it++;
// 	}

ft::vector<int>::const_iterator it = v.begin();
	ft::vector<int>::const_iterator ite = v.end();
	std::vector<int>::const_iterator std_it = std_vector.begin();

	std::cout << COLOR_YELLOW;
	std::cout << "--------ft--------|--------std--------|---diff---" << std::endl;
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << v.size();
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << std_vector.size();
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(v.size() == std_vector.size() ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;
	std::cout << std::setw(12) << "capacity : ";
	std::cout << std::setw(3) << v.capacity();
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(12) << "capacity : ";
	std::cout << std::setw(3) << std_vector.capacity();
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) << 
		(v.capacity() == std_vector.capacity() ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;

	for (; it != ite; it++)
	{
		std::cout << std::setw(10) << *it;
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;
		std::cout << std::setw(10) << *std_it;
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;
		std::cout << std::setw(10) << (*it == *std_it ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;
		std_it++;
	}
}

void construct(void)
{
	std::cout << BG_CYAN << "********************construct********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector;
	ft::vector<int> ft_vector;
	print(ft_vector, std_vector);
 
	std::vector<int> std_vector2(3);
	ft::vector<int> ft_vector2(3);
	print(ft_vector2, std_vector2);
 
	std::vector<int> std_vector3(std_vector2.begin(), std_vector2.end());
	ft::vector<int> ft_vector3(ft_vector2.begin(), ft_vector2.end());
	print(ft_vector3, std_vector3);
 
	std::vector<int> std_vector4(2, 7);
	ft::vector<int> ft_vector4(2, 7);
	print(ft_vector4, std_vector4);
 
	std::vector<int> std_vector5(std_vector4);
	ft::vector<int> ft_vector5(ft_vector4);
	print(ft_vector5, std_vector5);

	ft_vector5.push_back(1);
	std_vector5.push_back(1);
	std::vector<int> std_vector6;
	ft::vector<int> ft_vector6;
	std_vector6 = std_vector5;
	ft_vector6 = ft_vector5;
	print(ft_vector6, std_vector6);
}

void	resize(void)
{
	std::cout << BG_CYAN << "********************resize********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector(5);
	ft::vector<int> ft_vector(5);

	for (size_t i = 0; i < ft_vector.size(); i++)
	{
		std_vector[i] = i;
		ft_vector[i] = i;
	}
	print(ft_vector, std_vector);

	std_vector.resize(8);
	ft_vector.resize(8);
	print(ft_vector, std_vector);

	std_vector.resize(3, 2);
	ft_vector.resize(3, 2);
	print(ft_vector, std_vector);


	std_vector.resize(5, 5);
	ft_vector.resize(5, 5);
	print(ft_vector, std_vector);
}

void	max_size(void)
{
	std::cout << BG_CYAN << "********************max_size**********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector;
	ft::vector<int> ft_vector;

	print(ft_vector, std_vector);
	std::cout << std::setw(12) << "ft_max_size : ";
	std::cout << std::setw(3) << ft_vector.max_size();
	std::cout << COLOR_NOMAL << std::endl;
	std::cout << std::setw(12) << "std_max_size : ";
	std::cout << std::setw(3) << std_vector.max_size();
	std::cout << COLOR_YELLOW << std::setw(6) << " | ";
	std::cout << std::setw(10) << 
		(ft_vector.max_size() == std_vector.max_size() ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;
}

void	empty(void)
{
	std::cout << BG_CYAN << "********************empty*************************" << COLOR_NOMAL << std::endl;
	ft::vector<int> myvector;
	std::vector<int> std_vector;
	int ft_sum(0), std_sum(0);

	for (int i=1;i<=10;i++) myvector.push_back(i);
	while (!myvector.empty())
	{
		ft_sum += myvector.back();
		myvector.pop_back();
	}
	for (int i=1;i<=10;i++) std_vector.push_back(i);
	while (!std_vector.empty())
	{
		std_sum += std_vector.back();
		std_vector.pop_back();
	}

	print(myvector,std_vector);
	std::cout << std::setw(12) << "sum(1~10) : ";
	std::cout << std::setw(3) << ft_sum;
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(12) << "sum(1~10) : ";
	std::cout << std::setw(3) << std_sum;
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) << 
		(ft_sum == std_sum ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;
}

void	reserve(void)
{
	std::cout << BG_CYAN << "********************reserve***********************" << COLOR_NOMAL << std::endl;
	ft::vector<int> ft_vector(5);
	std::vector<int> std_vector(5);

	for (size_t i = 0; i < ft_vector.size(); i++)
	{
		std_vector[i] = i + 1;
		ft_vector[i] = i + 1;
	}
	print(ft_vector, std_vector);

	std_vector.reserve(10);
	ft_vector.reserve(10);
	print(ft_vector, std_vector);

	std_vector.reserve(3);
	ft_vector.reserve(3);
	print(ft_vector, std_vector);
}

void	at(void)
{
	std::cout << BG_CYAN << "***********************at************************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector(5);
	ft::vector<int> ft_vector(5);

	for (size_t i = 0; i < ft_vector.size(); i++)
	{
		std_vector[i] = i + 1;
		ft_vector[i] = i + 1;
	}

	print(ft_vector, std_vector);

	try
	{
		std::cout << "at(index 4) : " << ft_vector.at(4);
		std::cout << COLOR_YELLOW << std::setw(5) << " | " << COLOR_NOMAL;
		std::cout << "at(index 4) : " << std_vector.at(4);
		std::cout << COLOR_YELLOW << std::setw(5) << " | " << COLOR_NOMAL;
		std::cout << std::setw(10) << (ft_vector.at(1) == std_vector.at(1) ?  COLOR_GREEN"OK" :  COLOR_RED"KO") << std::endl;
		std::cout << COLOR_NOMAL;
		ft_vector.at(5);
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "ERROR : Out of Range! (" << e.what() << ")" << std::endl;
	}

	try
	{
		std_vector.at(5);
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "ERROR : Out of Range! (" << e.what() << ")" << std::endl;
	}
}

void	front(void)
{
	std::cout << BG_CYAN << "********************front***********************" << COLOR_NOMAL << std::endl;
	std::vector<int>	std_vector(3);
	ft::vector<int>		ft_vector(3);

	for (size_t i = 0; i < ft_vector.size(); i++)
	{
		std_vector[i] = (i + 1);
		ft_vector[i] = (i + 1);
	}

	print(ft_vector, std_vector);
	std::cout << std::setw(12) << "front : ";
	std::cout << std::setw(3) << ft_vector.front();
	std::cout << std::setw(10) << COLOR_YELLOW " | " << COLOR_NOMAL;
	std::cout << std::setw(12) << "front : ";
	std::cout << std::setw(3) << std_vector.front();
	std::cout << std::setw(10) << COLOR_YELLOW " | " << COLOR_NOMAL;
	std::cout << std::setw(10) << (ft_vector.front() == std_vector.front() ? COLOR_GREEN "OK" : COLOR_RED "KO") << std::endl;

	ft_vector.erase(ft_vector.begin());
	std_vector.erase(std_vector.begin());

	print(ft_vector, std_vector);
	std::cout << std::setw(12) << "front : ";
	std::cout << std::setw(3) << ft_vector.front();
	std::cout << std::setw(10) << COLOR_YELLOW " | " << COLOR_NOMAL;
	std::cout << std::setw(12) << "front : ";
	std::cout << std::setw(3) << std_vector.front();
	std::cout << std::setw(10) << COLOR_YELLOW " | " << COLOR_NOMAL;
	std::cout << std::setw(10) << (ft_vector.front() == std_vector.front() ? COLOR_GREEN "OK" : COLOR_RED "KO") << std::endl;
}

void	back(void)
{
	std::cout << BG_CYAN << "********************back***********************" << COLOR_NOMAL << std::endl;
	std::vector<int>	std_vector(3);
	ft::vector<int>		ft_vector(3);

	for (size_t i = 0; i < ft_vector.size(); i++)
	{
		std_vector[i] = i + 1;
		ft_vector[i] = i + 1;
	}
	
	print(ft_vector, std_vector);
	std::cout << std::setw(12) << "back : ";
	std::cout << std::setw(3) << ft_vector.back();
	std::cout << std::setw(10) << COLOR_YELLOW " | " << COLOR_NOMAL;
	std::cout << std::setw(12) << "back : ";
	std::cout << std::setw(3) << std_vector.back();
	std::cout << std::setw(10) << COLOR_YELLOW " | " << COLOR_NOMAL;
	std::cout << std::setw(10) << (ft_vector.back() == std_vector.back() ? COLOR_GREEN "OK" : COLOR_RED "KO") << std::endl;

	ft_vector.push_back(100);
	std_vector.push_back(100);

	print(ft_vector, std_vector);
	std::cout << std::setw(12) << "back : ";
	std::cout << std::setw(3) << ft_vector.back();
	std::cout << std::setw(10) << COLOR_YELLOW " | " << COLOR_NOMAL;
	std::cout << std::setw(12) << "back : ";
	std::cout << std::setw(3) << std_vector.back();
	std::cout << std::setw(10) << COLOR_YELLOW " | " << COLOR_NOMAL;
	std::cout << std::setw(10) << (ft_vector.back() == std_vector.back() ? COLOR_GREEN "OK" : COLOR_RED "KO") << std::endl;
}

void	assign(void)
{

}


void insert(void)
{
	std::cout << BG_CYAN << "********************insert***********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector(3);
	ft::vector<int> ft_vector(3);

	std_vector.clear();
	ft_vector.clear();
	for (size_t i = 1; i < 4; i++)
	{
		std_vector.insert(std_vector.begin(), i);
		ft_vector.insert(ft_vector.begin(), i);
		print(ft_vector, std_vector);
	}

	std_vector.insert(std_vector.end(), 10);
	ft_vector.insert(ft_vector.end(), 10);
	print(ft_vector, std_vector);

	std_vector.insert(std_vector.begin() + 2, 5);
	ft_vector.insert(ft_vector.begin() + 2, 5);
	print(ft_vector, std_vector);

	std_vector.insert(std_vector.begin(), 2, 0);
	ft_vector.insert(ft_vector.begin(), 2, 0);
	print(ft_vector, std_vector);

	std_vector.insert(std_vector.end(), 3, 20);
	ft_vector.insert(ft_vector.end(), 3, 20);
	print(ft_vector, std_vector);

	std_vector.	insert(std_vector.begin() + 5, 5, 30);
	ft_vector.insert(ft_vector.begin() + 5, 5, 30);
	print(ft_vector, std_vector);

	std_vector.clear();
	ft_vector.clear();

	for (int i = 1; i < 4; i++)
	{
		std_vector.push_back(i);
		ft_vector.push_back(i);
	}

	print(ft_vector, std_vector);
	std::vector<int> std_vector2;
	ft::vector<int> ft_vector2;

	std_vector2.insert(std_vector2.begin(), std_vector.begin(), std_vector.end());
	ft_vector2.insert(ft_vector2.begin(), ft_vector.begin(), ft_vector.end());
	print(ft_vector2, std_vector2);
}

int main(void)
{
	// construct();
	// resize();
	// max_size();
	// empty();
	// reserve();
	// at();
	// front();
	// back();

	assign();
	// push_back();
	// pop_back();
//	insert();
	// erase();
	// swap();
	// clear();
	// oper();
	// iterOper();
	// reverseIter();

	//  system("leaks test");
	return (0);
}




// #include <iomanip>
// #define COLOR_RED "\x1b[31m"
// #define COLOR_GREEN "\x1b[32m"
// #define COLOR_NOMAL "\033[0m"
// #define COLOR_BLUE "\033[34m"
// #define COLOR_YELLOW "\033[33m"


// // template <typename T>
// // void    display_std_vectorector(std::vector<T> &v)
// // {
// //     typename std::vector<T>::iterator it;
    
// //     std::cout << "std::vector->";
// //     for (it = v.begin(); it < v.end(); it++)
// //     {
// //         std::cout << " " << *it;
// //     }
// //     std::cout << "\n";
// // }

// // template <typename T>
// // void    display_ft_vectorector(ft::vector<T> &v)
// // {
// //     typename ft::vector<T>::iterator it;
    
// //     std::cout << " ft::vector->";
// //     for (it = v.begin(); it < v.end(); it++)
// //     {
// //         std::cout << " " << *it;
// //     }
// //     std::cout << "\n";
// // }

// void print(ft::vector<int> &v, std::vector<int> &std_vector)
// {
// 	ft::vector<int>::const_iterator it = v.begin();
// 	ft::vector<int>::const_iterator ite = v.end();
// 	std::vector<int>::const_iterator std_it = std_vector.begin();

// 	std::cout << COLOR_YELLOW;
// 	std::cout << "--------ft--------|--------std--------|---diff---" << std::endl;
// 	std::cout << COLOR_NOMAL;
// 	std::cout << std::setw(12) << "size : ";
// 	std::cout << std::setw(3) << v.size();
// 	std::cout << COLOR_YELLOW;
// 	std::cout << std::setw(5) << " | ";
// 	std::cout << COLOR_NOMAL;
// 	std::cout << std::setw(12) << "size : ";
// 	std::cout << std::setw(3) << std_vector.size();
// 	std::cout << COLOR_YELLOW;
// 	std::cout << std::setw(5) << " | " << std::setw(10) <<
// 		(v.size() == std_vector.size() ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;
// 	std::cout << std::setw(12) << "capacity : ";
// 	std::cout << std::setw(3) << v.capacity();
// 	std::cout << COLOR_YELLOW;
// 	std::cout << std::setw(5) << " | ";
// 	std::cout << COLOR_NOMAL;
// 	std::cout << std::setw(12) << "capacity : ";
// 	std::cout << std::setw(3) << std_vector.capacity();
// 	std::cout << COLOR_YELLOW;
// 	std::cout << std::setw(5) << " | " << std::setw(10) << 
// 		(v.capacity() == std_vector.capacity() ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;

// 	for (; it != ite; it++)
// 	{
// 		std::cout << std::setw(10) << *it;
// 		std::cout << COLOR_YELLOW;
// 		std::cout << std::setw(10) << " | ";
// 		std::cout << COLOR_NOMAL;
// 		std::cout << std::setw(10) << *std_it;
// 		std::cout << COLOR_YELLOW;
// 		std::cout << std::setw(10) << " | ";
// 		std::cout << COLOR_NOMAL;
// 		std::cout << std::setw(10) << (*it == *std_it ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;
// 		std_it++;
// 	}
// }

// int main(void)
// {
// 	//     {
//     //     std::cout << "------------------------------------------\n";
//     //     std::cout << "----------------Vector Test---------------\n";
//     //     std::cout << "------------------------------------------\n";
//     //     // int벡터 생성
//     //     std::cout << "\n-------------Create Empty Array-----------\n";
//     //     std::vector<int> std_vectorector;
//     //     ft::vector<int> ft_vectorector;
//     //     display_std_vectorector<int>(std_vectorector);
//     //     display_ft_vectorector<int>(ft_vectorector);
//     // }
//     // {
//     //     // int벡터 생성하고, 크기를 4만큼 할당되었습니다.
//     //     // 할당된 공간은 0으로 초기화됩니다.
//     //     std::cout << "\n---------------vector(4)-----------------\n";
//     //     std::vector<int> std_vectorector(4);
//     //     ft::vector<int> ft_vectorector(4);
//     //     display_std_vectorector<int>(std_vectorector);
//     //     display_ft_vectorector<int>(ft_vectorector);
//     // }


// 	std::vector<int> std_vector(3);
// 	ft::vector<int> ft_vector(3);
	
// 	for (size_t i = 0; i < ft_vector.size(); i++)
// 	{
// 		std_vector[i] = (i + 1) * 3;
// 		ft_vector[i] = (i + 1) * 3;
// 	}

// 	print(ft_vector, std_vector);
// 	ft_vector.pop_back();
// 	std_vector.pop_back();


// 	print(ft_vector, std_vector);
// 	ft_vector.pop_back();
// 	std_vector.pop_back();


// 	print(ft_vector, std_vector);
// 	ft_vector.pop_back();
// 	std_vector.pop_back();
// }





// #include <iostream>
// #include <string>

// #include <algorithm>    // std::lexicographical_compare
// #include <cctype>       // std::tolower

// #include <vector>
// #include "vector.hpp"
// #include "iterator.hpp"
// #include "utils.hpp"

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template <typename T>
// typename ft::enable_if<ft::is_integral<T>::value, T>::type	isInt(T t)
// {
// 	std::cout << t << " is Int!\n";
// 	return t;
// }



// int main()
// {
//     std::vector<int> std_vector;
// 	ft::vector<int> ft_vector;


// 	ft::vector<int> zeroVec;
// 	ft::vector<int> fiveVec(5);

// 	std::cout << zeroVec.size() << std::endl;
// 	std::cout << zeroVec.capacity() << std::endl;
// 	std::cout << std::endl;

// 	std::cout << fiveVec.size() << std::endl;
// 	std::cout << fiveVec.capacity() << std::endl;
// 	std::cout << std::endl;

// 	for (ft::vector<int>::iterator it = fiveVec.begin(); it != fiveVec.end(); it++)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
// 	std::cout << std::endl;

// 	fiveVec[0] = 1;
// 	fiveVec[1] = 2;
// 	fiveVec[2] = 3;
// 	fiveVec[3] = 4;
// 	fiveVec[4] = 5;

// 	for (ft::vector<int>::iterator it = fiveVec.begin(); it != fiveVec.end(); it++)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;

// 	ft::vector<int>::iterator begin = fiveVec.begin();
// 	std::cout << begin[2] << std::endl;


// 	ft::vector<int> copyIterVec(fiveVec.begin(), fiveVec.end());
// 	for (ft::vector<int>::iterator it = copyIterVec.begin(); it != copyIterVec.end(); it++)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
// 	std::cout << std::endl;

// 	copyIterVec[2] = 7;
// 	for (ft::vector<int>::iterator it = fiveVec.begin(); it != fiveVec.end(); it++)
// 	{ std::cout << *it << " "; }
// 	std::cout << std::endl;
// 	for (ft::vector<int>::iterator it = copyIterVec.begin(); it != copyIterVec.end(); it++)
// 	{ std::cout << *it << " "; }
// 	std::cout << std::endl;
// 	std::cout << std::endl;

// 	fiveVec[0] = -1;
// 	for (ft::vector<int>::iterator it = fiveVec.begin(); it != fiveVec.end(); it++)
// 	{ std::cout << *it << " "; }
// 	std::cout << std::endl;
// 	for (ft::vector<int>::iterator it = copyIterVec.begin(); it != copyIterVec.end(); it++)
// 	{ std::cout << *it << " "; }
// 	std::cout << std::endl;
// 	std::cout << std::endl;

// 	ft::vector<int> copyVec = copyIterVec;
// 	for (ft::vector<int>::iterator it = copyVec.begin(); it != copyVec.end(); it++)
// 	{ std::cout << *it << " "; }
// 	std::cout << std::endl;

// 	ft::vector<int> copycopyVec = fiveVec;
// 	for (ft::vector<int>::iterator it = copycopyVec.begin(); it != copycopyVec.end(); it++)
// 	{ std::cout << *it << " "; }
// 	std::cout << std::endl;
// 	std::cout << std::endl;

// 	const ft::vector<int> constFiveVec(5);
// 	ft::vector<int> constCopyVec = zeroVec;
// 	constCopyVec.resize(4, 100);
// 	constCopyVec.resize(6);
// 	// constCopyVec.resize(2);
// 	std::cout << constCopyVec.size() << " " << constCopyVec.capacity() << std::endl;
// 	constCopyVec.reserve(45);
// 	std::cout << constCopyVec.size() << " " << constCopyVec.capacity() << std::endl;
// 	for (ft::vector<int>::iterator it = constCopyVec.begin(); it != constCopyVec.end(); it++)
// 	{ std::cout << *it << " "; }
// 	std::cout << std::endl;
	
// 	std::cout << &(*constCopyVec.erase(constCopyVec.begin() + 1)) << std::endl;
	
// 	for (ft::vector<int>::iterator it = constCopyVec.begin(); it != constCopyVec.end(); it++)
// 	{ std::cout << *it << " "; }
// 	std::cout << std::endl;

// 	std::cout << *constCopyVec.insert(constCopyVec.begin() + 1, 17) << std::endl;
// 	constCopyVec.insert(constCopyVec.begin() + 5, 10, 59);
// 	constCopyVec.insert(constCopyVec.begin(), fiveVec.begin(), fiveVec.end());
	
// 	for (ft::vector<int>::iterator it = constCopyVec.begin(); it != constCopyVec.end(); it++)
// 	{ std::cout << *it << " "; }
// 	std::cout << std::endl;


// 	std::cout << zeroVec.max_size() << std::endl;
// 	std::cout << fiveVec.max_size() << std::endl;
// 	std::cout << constCopyVec.max_size() << std::endl;
// 	std::cout << constFiveVec[3] << std::endl;
// 	std::cout << constFiveVec[4] << std::endl;

// 	try
// 	{
// 		std::cout << constFiveVec[6] << std::endl;
// 		/* code */
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
	
// 	ft::vector<int> noneVec;
// 	std::cout << noneVec.size() << " " << noneVec.capacity() << std::endl;
// 	noneVec.reserve(5);
// 	std::cout << noneVec.size() << " " << noneVec.capacity() << std::endl;
// 	// while (1);
// 	return (0);
// }