#include <iostream>
#include <iomanip>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <list>
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_NOMAL "\033[0m"
#define COLOR_BLUE "\033[34m"
#define COLOR_YELLOW "\033[33m"
#define BG_CYAN "\x1b[46m"

void print(ft::vector<int> &v, std::vector<int> &std_vector)
{
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

void operatePrint(std::vector<std::string> oper, std::vector<std::string> ft, std::vector<std::string> std)
{
	std::cout << COLOR_YELLOW;
	std::cout << "--oper--|------ft------|------std------|---diff--" << std::endl;
	std::cout << COLOR_NOMAL;

	for (size_t i = 0; i < oper.size(); i++)
	{
		std::cout << std::setw(4 + oper[i].size() / 2) << oper[i];
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(5 - oper[i].size() / 2) << "|";
		std::cout << COLOR_NOMAL;

		std::cout << std::setw(7 + ft[i].size() / 2) << ft[i];
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(8 - ft[i].size() / 2) << "|";
		std::cout << COLOR_NOMAL;

		std::cout << std::setw(7 + std[i].size() / 2) << std[i];
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(8 - std[i].size() / 2) << "|";
		std::cout << COLOR_NOMAL;

		std::cout << std::setw(11) << (ft[i] == std[i] ? COLOR_GREEN"OK" : COLOR_RED"KO")
			<< COLOR_NOMAL << std::endl;
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

	std::cout << BG_CYAN << "********************assign***********************" << COLOR_NOMAL << std::endl;
	std::vector<int>	std_vector;
	ft::vector<int>		ft_vector;	

	std_vector.assign(3, 3);
	ft_vector.assign(3, 3);
	print(ft_vector, std_vector);

	std::vector<int> std_vector2(3);
	ft::vector<int> ft_vector2(3);

	for (size_t i = 0; i < ft_vector2.size(); i++)
	{
		std_vector2[i] = i + 1;
		ft_vector2[i] = i + 1;
	}

	std::vector<int> std_vector3;
	ft::vector<int> ft_vector3;

	std_vector3.assign(std_vector2.begin(), std_vector2.end());
	ft_vector3.assign(ft_vector2.begin(), ft_vector2.end());
	print(ft_vector3, std_vector3);

	std::vector<int> std_vector4;
	ft::vector<int> ft_vector4;
	print(ft_vector4, std_vector4);

	std_vector4.assign(5, 5);
	ft_vector4.assign(5, 5);
	print(ft_vector4, std_vector4);
}

void	push_back_pop_back(void)
{
	std::cout << BG_CYAN << "********************push_back***********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector;
	ft::vector<int> ft_vector;

	std_vector.push_back(1);
	std_vector.push_back(2);
	std_vector.push_back(3);
	std_vector.push_back(4);
	std_vector.push_back(5);

	ft_vector.push_back(1);
	ft_vector.push_back(2);
	ft_vector.push_back(3);
	ft_vector.push_back(4);
	ft_vector.push_back(5);

	print(ft_vector, std_vector);	

	std::cout << BG_CYAN << "********************pop_back***********************" << COLOR_NOMAL << std::endl;

	ft_vector.pop_back();
	std_vector.pop_back();
	print(ft_vector, std_vector);

	ft_vector.pop_back();
	std_vector.pop_back();
	print(ft_vector, std_vector);

	ft_vector.pop_back();
	std_vector.pop_back();
	print(ft_vector, std_vector);
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

void	erase(void)
{
	std::cout << BG_CYAN << "********************erase***********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector;
	ft::vector<int> ft_vector;
	for (int i = 1; i < 6; i++)
	{
		std_vector.push_back(i);
		ft_vector.push_back(i);
	}
	print(ft_vector, std_vector);

	std_vector.erase(std_vector.begin());
	ft_vector.erase(ft_vector.begin());
	print(ft_vector, std_vector);

	std_vector.erase(std_vector.end() - 1);
	ft_vector.erase(ft_vector.end() - 1);
	print(ft_vector, std_vector);

	std_vector.erase(std_vector.begin(), std_vector.end());
	ft_vector.erase(ft_vector.begin(), ft_vector.end());
	print(ft_vector, std_vector);
}

void	swap(void)
{
	std::cout << BG_CYAN << "********************swap***********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector;
	ft::vector<int> ft_vector;
	std::vector<int> std_vector2;
	ft::vector<int> ft_vector2;

	for (int i = 1; i < 6; i++)
	{
		std_vector.push_back(i);
		ft_vector.push_back(i);
	}

	for (int i = 6; i < 11; i++)
	{
		std_vector2.push_back(i);
		ft_vector2.push_back(i);
	}
	print(ft_vector, std_vector);
	print(ft_vector2, std_vector2);

	std_vector.swap(std_vector2);
	ft_vector.swap(ft_vector2);
	print(ft_vector, std_vector);
	print(ft_vector2, std_vector2);
}

void	clear(void)
{
	std::cout << BG_CYAN << "********************clear***********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector;
	ft::vector<int> ft_vector;

	for (int i = 1; i < 6; i++)
	{
		std_vector.push_back(i);
		ft_vector.push_back(i);
	}
	print(ft_vector, std_vector);

	std_vector.clear();
	ft_vector.clear();
	print(ft_vector, std_vector);
}

void operTest(std::vector<int> &std_vector, std::vector<int> &std_vector2, ft::vector<int> &ft_vector, ft::vector<int> &ft_vector2)
{
	std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	std.push_back((std_vector == std_vector2 ? "true" : "false"));
	ft.push_back((ft_vector == ft_vector2 ? "true" : "false"));

	operStr.push_back("!=");
	std.push_back((std_vector != std_vector2 ? "true" : "false"));
	ft.push_back((ft_vector != ft_vector2 ? "true" : "false"));

	operStr.push_back("<");
	std.push_back((std_vector < std_vector2 ? "true" : "false"));
	ft.push_back((ft_vector < ft_vector2 ? "true" : "false"));

	operStr.push_back("<=");
	std.push_back((std_vector <= std_vector2 ? "true" : "false"));
	ft.push_back((ft_vector <= ft_vector2 ? "true" : "false"));

	operStr.push_back(">");
	std.push_back((std_vector > std_vector2 ? "true" : "false"));
	ft.push_back((ft_vector > ft_vector2 ? "true" : "false"));

	operStr.push_back(">=");
	std.push_back((std_vector >= std_vector2 ? "true" : "false"));
	ft.push_back((ft_vector >= ft_vector2 ? "true" : "false"));

	operatePrint(operStr, ft, std);
}

void oper(void)
{
	std::cout << BG_CYAN << "********************oper***********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector;
	ft::vector<int> ft_vector;
	std::vector<int> std_vector2;
	ft::vector<int> ft_vector2;

	for (int i = 1; i < 6; i++)
	{
		std_vector.push_back(i);
		ft_vector.push_back(i);
		std_vector2.push_back(i);
		ft_vector2.push_back(i);
	}
	print(ft_vector, std_vector);
	print(ft_vector2, std_vector2);
	operTest(std_vector, std_vector2, ft_vector, ft_vector2);

	std_vector2.push_back(10);
	ft_vector2.push_back(10);
	print(ft_vector, std_vector);
	print(ft_vector2, std_vector2);
	operTest(std_vector, std_vector2, ft_vector, ft_vector2);
}

void iterOperTest(std::vector<int>::iterator stdIter, ft::vector<int>::iterator ftIter)
{
	std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;
	std::string str;

	str.assign("0");

	operStr.push_back("i++");
	str[0] = *(stdIter++) + '0';
	std.push_back(str);
	str[0] = *(ftIter++) + '0';
	ft.push_back(str);

	operStr.push_back("++i");
	str[0] = *(++stdIter) + '0';
	std.push_back(str);
	str[0] = *(++ftIter) + '0';
	ft.push_back(str);

	operStr.push_back("i--");
	str[0] = *(stdIter--) + '0';
	std.push_back(str);
	str[0] = *(ftIter--) + '0';
	ft.push_back(str);

	operStr.push_back("--i");
	str[0] = *(--stdIter) + '0';
	std.push_back(str);
	str[0] = *(--ftIter) + '0';
	ft.push_back(str);

	operStr.push_back("it + n");
	str[0] = *(stdIter + 1) + '0';
	std.push_back(str);
	str[0] = *(ftIter + 1) + '0';
	ft.push_back(str);

	operStr.push_back("n + it");
	str[0] = *(1 + stdIter) + '0';
	std.push_back(str);
	str[0] = *(1 + ftIter) + '0';
	ft.push_back(str);

	stdIter++;
	ftIter++;
	operStr.push_back("it - n");
	str[0] = *(stdIter - 1) + '0';
	std.push_back(str);
	str[0] = *(ftIter - 1) + '0';
	ft.push_back(str);

	std::vector<int>::iterator stdTemp;
	ft::vector<int>::iterator ftTemp;

	stdTemp = stdIter + 1;
	ftTemp = ftIter + 1;

	operStr.push_back("it - it");
	str[0] = stdTemp - stdIter + '0';
	std.push_back(str);
	str[0] = ftTemp - ftIter + '0';
	ft.push_back(str);

	operStr.push_back("it += it");
	stdIter += 1;
	str[0] = *stdIter + '0';
	std.push_back(str);
	ftIter += 1;
	str[0] = *ftIter + '0';
	ft.push_back(str);

	operStr.push_back("it[n]");
	str[0] = stdIter[0] + '0';
	std.push_back(str);
	str[0] = ftIter[0] + '0';
	ft.push_back(str);


	operatePrint(operStr, ft, std);
}

void iterOper(void)
{
	std::cout << BG_CYAN << "********************iterOper***********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector;
	ft::vector<int> ft_vector;

	for (int i = 1; i < 4; i++)
	{
		std_vector.push_back(i * 3);
		ft_vector.push_back(i * 3);
	}

	iterOperTest(std_vector.begin(), ft_vector.begin());
}

void reverseIterTest(std::vector<int>::reverse_iterator stdIter, ft::vector<int>::reverse_iterator ftIter)
{
	std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;
	std::string str;

	str.assign("0");

	operStr.push_back("i++");
	str[0] = *(stdIter++) + '0';
	std.push_back(str);
	str[0] = *(ftIter++) + '0';
	ft.push_back(str);

	operStr.push_back("++i");
	str[0] = *(++stdIter) + '0';
	std.push_back(str);
	str[0] = *(++ftIter) + '0';
	ft.push_back(str);

	operStr.push_back("i--");
	str[0] = *(stdIter--) + '0';
	std.push_back(str);
	str[0] = *(ftIter--) + '0';
	ft.push_back(str);

	operStr.push_back("--i");
	str[0] = *(--stdIter) + '0';
	std.push_back(str);
	str[0] = *(--ftIter) + '0';
	ft.push_back(str);

	operStr.push_back("it + n");
	str[0] = *(stdIter + 1) + '0';
	std.push_back(str);
	str[0] = *(ftIter + 1) + '0';
	ft.push_back(str);

	operStr.push_back("n + it");
	str[0] = *(1 + stdIter) + '0';
	std.push_back(str);
	str[0] = *(1 + ftIter) + '0';
	ft.push_back(str);

	stdIter++;
	ftIter++;
	operStr.push_back("it - n");
	str[0] = *(stdIter - 1) + '0';
	std.push_back(str);
	str[0] = *(ftIter - 1) + '0';
	ft.push_back(str);

	std::vector<int>::reverse_iterator stdTemp;
	ft::vector<int>::reverse_iterator ftTemp;

	stdTemp = stdIter + 1;
	ftTemp = ftIter + 1;

	operStr.push_back("it - it");
	str[0] = stdTemp - stdIter + '0';
	std.push_back(str);
	str[0] = ftTemp - ftIter + '0';
	ft.push_back(str);

	operStr.push_back("it += it");
	stdIter += 1;
	str[0] = *stdIter + '0';
	std.push_back(str);
	ftIter += 1;
	str[0] = *ftIter + '0';
	ft.push_back(str);

	operStr.push_back("it[n]");
	str[0] = stdIter[0] + '0';
	std.push_back(str);
	str[0] = ftIter[0] + '0';
	ft.push_back(str);

	operStr.push_back("base");
	str[0] = *stdIter.base() + '0';
	std.push_back(str);
	str[0] = *ftIter.base() + '0';
	ft.push_back(str);

	operatePrint(operStr, ft, std);
}

void reverseIter(void)
{
	std::cout << BG_CYAN << "********************reverseIter***********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector;
	ft::vector<int> ft_vector;

	for (int i = 1; i < 4; i++)
	{
		std_vector.push_back(i * 3);
		ft_vector.push_back(i * 3);
	}

	reverseIterTest(std_vector.rbegin(), ft_vector.rbegin());
}

void stack_print(ft::stack<int> ft_s, std::stack<int> std_s)
{
	std::cout << COLOR_YELLOW;
	std::cout << "--------ft--------|--------std--------|---diff---" << std::endl;
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << ft_s.size();
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << std_s.size();
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_s.size() == std_s.size() ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;

	while (!ft_s.empty())
	{
		std::cout << std::setw(10) << ft_s.top();
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;
		std::cout << std::setw(10) << std_s.top();
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;
		std::cout << std::setw(10) << (ft_s.top() == std_s.top() ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;
		ft_s.pop();
		std_s.pop();
	}
}

void stack_print(ft::stack<int, ft::vector<int> > ft_s, std::stack<int, std::vector<int> > std_s)
{
	std::cout << COLOR_YELLOW;
	std::cout << "--------ft--------|--------std--------|---diff---" << std::endl;
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << ft_s.size();
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << std_s.size();
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_s.size() == std_s.size() ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;

	while (!ft_s.empty())
	{
		std::cout << std::setw(10) << ft_s.top();
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;
		std::cout << std::setw(10) << std_s.top();
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;
		std::cout << std::setw(10) << (ft_s.top() == std_s.top() ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;
		ft_s.pop();
		std_s.pop();
	}
}


void	stack_construct(void)
{
	std::cout << BG_CYAN << "********************constructor***********************" << COLOR_NOMAL << std::endl;
	std::stack<int> std_s;
	ft::stack<int> ft_s;

	for (size_t i = 1; i < 6; i++)
	{
		ft_s.push(i);
		std_s.push(i);
	}

	stack_print(ft_s, std_s);

	std::vector<int> std_v;
	ft::vector<int> ft_v;

	for (size_t i = 1; i < 5; i++)
	{
		std_v.push_back(i * 2);
		ft_v.push_back(i * 2);
	}
  
	std::stack<int, std::vector<int> > std_s2(std_v);
	ft::stack<int, ft::vector<int> > ft_s2(ft_v);
	stack_print(ft_s2, std_s2);
}

void stack_operTest(std::stack<int> &std_s, std::stack<int> &std_s2, ft::stack<int> &ft_s, ft::stack<int> &ft_s2)
{
	std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	std.push_back((std_s == std_s2 ? "true" : "false"));
	ft.push_back((ft_s == ft_s2 ? "true" : "false"));

	operStr.push_back("!=");
	std.push_back((std_s != std_s2 ? "true" : "false"));
	ft.push_back((ft_s != ft_s2 ? "true" : "false"));

	operStr.push_back("<");
	std.push_back((std_s < std_s2 ? "true" : "false"));
	ft.push_back((ft_s < ft_s2 ? "true" : "false"));

	operStr.push_back("<=");
	std.push_back((std_s <= std_s2 ? "true" : "false"));
	ft.push_back((ft_s <= ft_s2 ? "true" : "false"));

	operStr.push_back(">");
	std.push_back((std_s > std_s2 ? "true" : "false"));
	ft.push_back((ft_s > ft_s2 ? "true" : "false"));

	operStr.push_back(">=");
	std.push_back((std_s >= std_s2 ? "true" : "false"));
	ft.push_back((ft_s >= ft_s2 ? "true" : "false"));

	operatePrint(operStr, ft, std);
}

void stack_oper(void)
{
	std::cout << BG_CYAN << "********************oper***********************" << COLOR_NOMAL << std::endl;
	std::stack<int> std_v;
	std::stack<int> std_v2;
	ft::stack<int> ft_v;
	ft::stack<int> ft_v2;

	for (int i = 1; i < 4; i++)
	{
		std_v.push(i * 3);
		std_v2.push(i * 3);
		ft_v.push(i * 3);
		ft_v2.push(i * 3);
	}

	stack_print(ft_v, std_v);
	stack_print(ft_v2, std_v2);
	stack_operTest(std_v, std_v2, ft_v, ft_v2);

	std_v2.push(2);
	ft_v2.push(2);
	std_v.push(1);
	ft_v.push(1);
	stack_print(ft_v, std_v);
	stack_print(ft_v2, std_v2);
	stack_operTest(std_v, std_v2, ft_v, ft_v2);
}

void	stack_empty_pop(void)
{
	std::cout << BG_CYAN << "********************empty***********************" << COLOR_NOMAL << std::endl;
	std::stack<int> std_s;
	ft::stack<int> ft_s;

	for (int i = 1; i < 6; i++)
	{
		std_s.push(i);
		ft_s.push(i);
	}
	stack_print(ft_s, std_s);
	while(!ft_s.empty())
	{
		ft_s.pop();
	}
	while(!std_s.empty())
	{
		std_s.pop();
	}
	stack_print(ft_s, std_s);
}

void	stack_top(void)
{
	std::cout << BG_CYAN << "********************top***********************" << COLOR_NOMAL << std::endl;
	std::stack<int> std_s;
	ft::stack<int> ft_s;

	std_s.push(10);
	ft_s.push(10);
	std_s.push(20);
	ft_s.push(20);
	stack_print(ft_s, std_s);
	ft_s.top() -= 5;
	std_s.top() -= 5;
	stack_print(ft_s, std_s);
}

void printCount(int count)
{
	std::cout << std::setw(22) <<  "[" << count << "]" << std::endl;
}


void map_print(ft::map<int, std::string> &ft_m, std::map<int, std::string> &std_m)
{
	ft::map<int, std::string>::const_iterator it = ft_m.begin();
	ft::map<int, std::string>::const_iterator ite = ft_m.end();
	std::map<int, std::string>::const_iterator std_it = std_m.begin();

	std::cout << COLOR_YELLOW;
	std::cout << "--------ft--------|--------std--------|---diff---" << std::endl;
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << ft_m.size();
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << std_m.size();
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_m.size() == std_m.size() ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;

	for (; it != ite; it++)
	{
		//-------------- key ---------
		std::cout << std::setw(10) << it->first;
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;
		std::cout << std::setw(10) << std_it->first;
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;
		std::cout << std::setw(10) << (it->first == std_it->first ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;
		//------------- value ----------
		std::cout << std::setw(10) << it->second;
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;
		std::cout << std::setw(10) << std_it->second;
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;
		std::cout << std::setw(10) << (it->second == std_it->second ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;
		std_it++;

	}
}

void	map_construct(void)
{
	std::cout << BG_CYAN << "********************construct***********************" << COLOR_NOMAL << std::endl;
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));

	// ------------------- [0] ----------------------------------
	printCount(0);
	std::map<int, std::string> std_m(std_lst.begin(), std_lst.end());
	ft::map<int, std::string> ft_m(ft_lst.begin(), ft_lst.end());
	map_print(ft_m, std_m);

	// ------------------- [1] ----------------------------------
	std::map<int, std::string> std_m2(std_m);
	ft::map<int, std::string> ft_m2(ft_m);

	printCount(1);
	map_print(ft_m2, std_m2);

	// ------------------- [2] ----------------------------------
	std::map<int, std::string> std_m3;
	ft::map<int, std::string> ft_m3;

	std_m3 = std_m;
	ft_m3 = ft_m;
	printCount(2);
	map_print(ft_m2, std_m2);
}

static void map_printIter(std::map<int, std::string>::iterator &std_it, ft::map<int, std::string>::iterator &ft_it, std::map<int, std::string> &std_m, ft::map<int, std::string> &ft_m)
{
	std::string std_ret;
	std::string ft_ret;

	std_ret = (std_it != std_m.end() ? std_it->second : "not find");
	ft_ret = (ft_it != ft_m.end() ? ft_it->second : "not find");
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << ft_ret;
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << std_ret;
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(std_ret == ft_ret ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;
}

void	map_empty(void)
{
	std::cout << BG_CYAN << "********************empty***********************" << COLOR_NOMAL << std::endl;
	std::map<int, std::string> std_m;
	ft::map<int, std::string> ft_m;

	// --------------[0]----------------
	printCount(0);
	map_print(ft_m, std_m);
	std::cout << std::setw(10) << (ft_m.empty() == 1 ? "TRUE" : "FALSE");
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(11) << (std_m.empty() == 1 ? "TRUE" : "FALSE");
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(11) << (ft_m.empty() == std_m.empty() ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;

	// --------------[1]----------------
	std_m[1] = "hi";
	ft_m[1] = "hi";
	printCount(1);
	map_print(ft_m, std_m);
	std::cout << std::setw(10) << (ft_m.empty() == 1 ? "TRUE" : "FALSE");
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(11) << (std_m.empty() == 1 ? "TRUE" : "FALSE");
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(11) << (ft_m.empty() == std_m.empty() ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;

	// --------------[0]----------------
	std_m.clear();
	ft_m.clear();
	printCount(0);
	map_print(ft_m, std_m);
	std::cout << std::setw(10) << (ft_m.empty() == 1 ? "TRUE" : "FALSE");
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(11) << (std_m.empty() == 1 ? "TRUE" : "FALSE");
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(11) << (ft_m.empty() == std_m.empty() ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;
}

void	map_insert(void)
{
	std::cout << BG_CYAN << "********************insert***********************" << COLOR_NOMAL << std::endl;
	std::pair<std::map<int, std::string>::iterator, bool> std_ret;
	ft::pair<ft::map<int, std::string>::iterator, bool> ft_ret;

	std::map<int, std::string>::iterator std_it;
	ft::map<int, std::string>::iterator ft_it;

	std::map<int, std::string> std_m;
	ft::map<int, std::string> ft_m;

	// ------------------[0]--------------
	std_ret = std_m.insert(std::make_pair<int, std::string>(0, "insert"));
	ft_ret = ft_m.insert(ft::make_pair<int, std::string>(0, "insert"));

	printCount(0);
	map_print(ft_m, std_m);

	// ------------------[1]--------------
	std_ret = std_m.insert(std::make_pair<int, std::string>(0, "insert"));
	ft_ret = ft_m.insert(ft::make_pair<int, std::string>(0, "insert"));

	printCount(1);
	map_print(ft_m, std_m);

	// ------------------[2]--------------
	std_it = std_m.insert(std_m.begin(), std::make_pair<int, std::string>(10, "insert2"));
	ft_it = ft_m.insert(ft_m.begin(), ft::make_pair<int, std::string>(10, "insert2"));

	printCount(2);
	map_print(ft_m, std_m);

	// ------------------[3]--------------
	std_it = std_m.insert(std_m.begin(), std::make_pair<int, std::string>(4, "insert3"));
	ft_it = ft_m.insert(ft_m.begin(), ft::make_pair<int, std::string>(4, "insert3"));

	printCount(3);
	map_print(ft_m, std_m);

	// ------------------[4]--------------
	printCount(4);
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));

	ft_m.insert(ft_lst.begin(), ft_lst.end());
	std_m.insert(std_lst.begin(), std_lst.end());
	map_print(ft_m, std_m);
}

void	map_erase(void)
{
	std::cout << BG_CYAN << "********************erase***********************" << COLOR_NOMAL << std::endl;
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));

	std::map<int, std::string> std_m(std_lst.begin(), std_lst.end());
	ft::map<int, std::string> ft_m(ft_lst.begin(), ft_lst.end());

	// ----------------[0]---------------------
	printCount(0);
	map_print(ft_m, std_m);

	// ----------------[1]---------------------
	// hello delete
	printCount(1);
	std_m.erase(std_m.begin());
	ft_m.erase(ft_m.begin());
	map_print(ft_m, std_m);

	// ----------------[2]---------------------
	// tester delete
	printCount(2);
	std_m.erase(--std_m.end());
	ft_m.erase(--ft_m.end());
	map_print(ft_m, std_m);

	// ----------------[3]---------------------
	// none key delete
	printCount(3);
	size_t std_ret;
	size_t ft_ret;
	std_ret = std_m.erase(100);
	ft_ret = ft_m.erase(100);
	map_print(ft_m, std_m);

	// ----------------[4]---------------------
	// delete all
	printCount(4);
	std_m.erase(std_m.begin(), std_m.end());
	ft_m.erase(ft_m.begin(), ft_m.end());
	map_print(ft_m, std_m);
}

void	map_swap(void)
{
	std::cout << BG_CYAN << "********************swap***********************" << COLOR_NOMAL << std::endl;
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));

	std::map<int, std::string> std_m(std_lst.begin(), std_lst.end());
	ft::map<int, std::string> ft_m(ft_lst.begin(), ft_lst.end());
	std::map<int, std::string> std_m2(std_lst.begin(), ++(++std_lst.begin()));
	ft::map<int, std::string> ft_m2(ft_lst.begin(), ++(++ft_lst.begin()));

	// ------------------[0]--------------
	printCount(0);
	std::cout << std::setw(38) << "---------map 1----------" << std::endl;
	map_print(ft_m, std_m);
	std::cout << std::setw(38) << "---------map 2----------" << std::endl;
	map_print(ft_m2, std_m2);

	// ------------------[1]--------------
	printCount(1);
	std_m.swap(std_m2);
	ft_m.swap(ft_m2);
	std::cout << std::setw(38) << "---------map 1----------" << std::endl;
	map_print(ft_m, std_m);
	std::cout << std::setw(38) << "---------map 2----------" << std::endl;
	map_print(ft_m2, std_m2);
}

void	map_clear(void)
{
	std::cout << BG_CYAN << "********************clear***********************" << COLOR_NOMAL << std::endl;
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));

	std::map<int, std::string> std_m(std_lst.begin(), std_lst.end());
	ft::map<int, std::string> ft_m(ft_lst.begin(), ft_lst.end());
	// --------------[0]-------------
	printCount(0);
	map_print(ft_m, std_m);
	// --------------[1]-------------
	printCount(1);
	std_m.clear();
	ft_m.clear();
	map_print(ft_m, std_m);
}

void	find(void)
{
	std::cout << BG_CYAN << "********************find***********************" << COLOR_NOMAL << std::endl;
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));

	ft::map<int, std::string> ft_m(ft_lst.begin(), ft_lst.end());
	std::map<int, std::string> std_m(std_lst.begin(), std_lst.end());

	ft::map<int, std::string>::iterator ft_it;
	std::map<int, std::string>::iterator std_it;
	// -------------[0]--------------
	printCount(0);
	map_print(ft_m, std_m);
	// -------------[1]--------------
	// find map
	printCount(1);
	ft_it = ft_m.find(22);
	std_it = std_m.find(22);
	map_printIter(std_it, ft_it, std_m, ft_m);

	// -------------[2]--------------
	// not exist value
	printCount(2);
	ft_it = ft_m.find(100);
	std_it = std_m.find(100);
	map_printIter(std_it, ft_it, std_m, ft_m);
}

void	retPrint(size_t std_count, size_t ft_count)
{
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << (ft_count ? "TRUE" : "FALSE");
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << (std_count ? "TRUE" : "FALSE");
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_count == std_count ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;
}

void	count(void)
{
	std::cout << BG_CYAN << "********************count***********************" << COLOR_NOMAL << std::endl;
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;

	std_lst.push_back(std::make_pair<int, std::string>(2, "world"));
	std_lst.push_back(std::make_pair<int, std::string>(0, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "hi"));
	std_lst.push_back(std::make_pair<int, std::string>(10, "my"));
	std_lst.push_back(std::make_pair<int, std::string>(23, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(20, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "name"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));

	ft_lst.push_back(ft::make_pair<int, std::string>(2, "world"));
	ft_lst.push_back(ft::make_pair<int, std::string>(0, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "hi"));
	ft_lst.push_back(ft::make_pair<int, std::string>(10, "my"));
	ft_lst.push_back(ft::make_pair<int, std::string>(23, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(20, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "name"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));

	ft::map<int, std::string> ft_m;
	std::map<int, std::string> std_m;
	ft_m.insert(ft_lst.begin(), ft_lst.end());
	std_m.insert(std_lst.begin(), std_lst.end());
	//---------------[0]--------------
	printCount(0);
	map_print(ft_m, std_m);
	size_t std_count, ft_count;
	
	std_count = std_m.count(5);
	ft_count = ft_m.count(5);
	retPrint(std_count, ft_count);
	
	std_count = std_m.count(100);
	ft_count = ft_m.count(100);
	retPrint(std_count, ft_count);
}

void	bound(void)
{
	std::cout << BG_CYAN << "********************bound***********************" << COLOR_NOMAL << std::endl;
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));

	std::map<int, std::string> std_m;
	ft::map<int, std::string> ft_m;
	std::map<int, std::string>::iterator std_it;
	ft::map<int, std::string>::iterator ft_it;
	ft_m.insert(ft_lst.begin(), ft_lst.end());
	std_m.insert(std_lst.begin(), std_lst.end());

	// -------------[0]-------------
	printCount(0);
	map_print(ft_m, std_m);
	
	// -------------[1]-------------
	std::cout << std::setw(38) << "---------lower----------" << std::endl;
	printCount(1);
	std_it = std_m.lower_bound(-5);
	ft_it = ft_m.lower_bound(-5);
	map_printIter(std_it, ft_it, std_m, ft_m);

	// -------------[2]-------------
	printCount(0);
	std_it = std_m.lower_bound(2);
	ft_it = ft_m.lower_bound(2);
	map_printIter(std_it, ft_it, std_m, ft_m);

	// -------------[3]-------------
	printCount(3);
	std_it = std_m.lower_bound(22);
	ft_it = ft_m.lower_bound(22);
	map_printIter(std_it, ft_it, std_m, ft_m);

	// -------------[4]-------------
	printCount(4);
	std_it = std_m.lower_bound(100);
	ft_it = ft_m.lower_bound(100);
	map_printIter(std_it, ft_it, std_m, ft_m);


	// -------------[5]-------------
	std::cout << std::setw(38) << "---------upper----------" << std::endl;
	printCount(5);
	std_it = std_m.upper_bound(-5);
	ft_it = ft_m.upper_bound(-5);
	map_printIter(std_it, ft_it, std_m, ft_m);

	// -------------[6]-------------
	printCount(6);
	std_it = std_m.upper_bound(2);
	ft_it = ft_m.upper_bound(2);
	map_printIter(std_it, ft_it, std_m, ft_m);

	// -------------[7]-------------
	printCount(7);
	std_it = std_m.upper_bound(22);
	ft_it = ft_m.upper_bound(22);
	map_printIter(std_it, ft_it, std_m, ft_m);

	// -------------[8]-------------
	printCount(8);
	std_it = std_m.upper_bound(30);
	ft_it = ft_m.upper_bound(30);
	map_printIter(std_it, ft_it, std_m, ft_m);
}

static void	map_printIter(std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> &std_pr, ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> &ft_pr,
		std::map<int, std::string> &std_m, ft::map<int, std::string> &ft_m)
{
	std::string std_ret;
	std::string ft_ret;

	std_ret = (std_pr.first != std_m.end() ? std_pr.first->second : "not find");
	ft_ret = (ft_pr.first != ft_m.end() ? ft_pr.first->second : "not find");
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << ft_ret;
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << std_ret;
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_ret == std_ret ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;


	std_ret = (std_pr.second != std_m.end() ? std_pr.second->second : "not find");
	ft_ret = (ft_pr.second != ft_m.end() ? ft_pr.second->second : "not find");
	std::cout << std::setw(8) << "ret2 : ";
	std::cout << std::setw(7) << ft_ret;
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(8) << "ret2 : ";
	std::cout << std::setw(7) << std_ret;
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_ret == std_ret ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;
}

void	equal_range(void)
{
	std::cout << BG_CYAN << "********************equal_range***********************" << COLOR_NOMAL << std::endl;
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;
	std::map<int, std::string> std_m;
	ft::map<int, std::string> ft_m;
	std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> std_pr;
	ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> ft_pr;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));

	ft_m.insert(ft_lst.begin(), ft_lst.end());
	std_m.insert(std_lst.begin(), std_lst.end());

	// -----------[0]------------
	printCount(0);
	map_print(ft_m, std_m);
	
	// -----------[1]------------
	printCount(1);
	std_pr = std_m.equal_range(-1);
	ft_pr = ft_m.equal_range(-1);
	map_printIter(std_pr, ft_pr, std_m, ft_m);
	
	// -----------[2]------------
	printCount(2);
	std_pr = std_m.equal_range(2);
	ft_pr = ft_m.equal_range(2);
	map_printIter(std_pr, ft_pr, std_m, ft_m);
	
	// -----------[3]------------
	printCount(3);
	std_pr = std_m.equal_range(15);
	ft_pr = ft_m.equal_range(15);
	map_printIter(std_pr, ft_pr, std_m, ft_m);
	
	// -----------[4]------------
	printCount(4);
	std_pr = std_m.equal_range(30);
	ft_pr = ft_m.equal_range(30);
	map_printIter(std_pr, ft_pr, std_m, ft_m);
	
	// -----------[5]------------
	printCount(5);
	std_pr = std_m.equal_range(100);
	ft_pr = ft_m.equal_range(100);
	map_printIter(std_pr, ft_pr, std_m, ft_m);
}

void operatorTest(std::map<int, std::string> std_m, std::map<int, std::string> std_m2, ft::map<int, std::string> ft_m, ft::map<int, std::string> ft_m2)
{
	std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	std.push_back((std_m == std_m2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_m == ft_m2 ? "TRUE" : "FALSE"));

	operStr.push_back("!=");
	std.push_back((std_m != std_m2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_m != ft_m2 ? "TRUE" : "FALSE"));

	operStr.push_back("<");
	std.push_back((std_m < std_m2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_m < ft_m2 ? "TRUE" : "FALSE"));

	operStr.push_back("<=");
	std.push_back((std_m <= std_m2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_m <= ft_m2 ? "TRUE" : "FALSE"));

	operStr.push_back(">");
	std.push_back((std_m > std_m2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_m > ft_m2 ? "TRUE" : "FALSE"));

	operStr.push_back(">=");
	std.push_back((std_m >= std_m2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_m >= ft_m2 ? "TRUE" : "FALSE"));

	operatePrint(operStr, ft, std);
}

void mapOperator()
{
	std::cout << BG_CYAN << "********************operators***********************" << COLOR_NOMAL << std::endl;
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;
	std::map<int, std::string> std_m;
	ft::map<int, std::string> ft_m;
	std::map<int, std::string> std_m2;
	ft::map<int, std::string> ft_m2;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));

	ft_m.insert(ft_lst.begin(), ft_lst.end());
	std_m.insert(std_lst.begin(), std_lst.end());
	ft_m2.insert(ft_lst.begin(), ft_lst.end());
	std_m2.insert(std_lst.begin(), std_lst.end());

	// ---------------[0]----------------
	printCount(0);
	map_print(ft_m, std_m);
	map_print(ft_m2, std_m2);
	operatorTest(std_m, std_m2, ft_m, ft_m2);

	// ---------------[1]----------------
	printCount(1);
	std_m.erase(++std_m.begin());
	ft_m.erase(++ft_m.begin());
	map_print(ft_m, std_m);
	map_print(ft_m2, std_m2);
	operatorTest(std_m, std_m2, ft_m, ft_m2);

	// ---------------[2]----------------
	printCount(2);
	std_m2.erase(std_m2.begin());
	ft_m2.erase(ft_m2.begin());
	map_print(ft_m, std_m);
	map_print(ft_m2, std_m2);
	operatorTest(std_m, std_m2, ft_m, ft_m2);
}

void operTest(std::map<int, std::string>::iterator std_iter, std::map<int, std::string>::iterator std_iter2, ft::map<int,std::string>::iterator ft_iter, ft::map<int, std::string>::iterator ft_iter2)
{
	std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	std.push_back((std_iter == std_iter2 ? "true" : "false"));
	ft.push_back((ft_iter == ft_iter2 ? "true" : "false"));

	operStr.push_back("!=");
	std.push_back((std_iter != std_iter2 ? "true" : "false"));
	ft.push_back((ft_iter != ft_iter2 ? "true" : "false"));

	operatePrint(operStr, ft, std);
}

void r_operTest(std::map<int, std::string>::reverse_iterator std_iter, std::map<int, std::string>::reverse_iterator std_iter2, ft::map<int,std::string>::reverse_iterator ft_iter, ft::map<int, std::string>::reverse_iterator ft_iter2)
{
	std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	std.push_back((std_iter == std_iter2 ? "true" : "false"));
	ft.push_back((ft_iter == ft_iter2 ? "true" : "false"));

	operStr.push_back("!=");
	std.push_back((std_iter != std_iter2 ? "true" : "false"));
	ft.push_back((ft_iter != ft_iter2 ? "true" : "false"));

	operatePrint(operStr, ft, std);
}

void	map_iterOper(void)
{
	std::cout << BG_CYAN << "********************iterator***********************" << COLOR_NOMAL << std::endl;
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;
	std::map<int, std::string> std_m;
	ft::map<int, std::string> ft_m;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));

	ft_m.insert(ft_lst.begin(), ft_lst.end());
	std_m.insert(std_lst.begin(), std_lst.end());

	// ------------------[0]-----------------
	printCount(0);
	operTest(std_m.begin(), std_m.begin(), ft_m.begin(), ft_m.begin());

	// ------------------[1]-----------------
	printCount(1);
	operTest(std_m.end(), std_m.end(), ft_m.end(), ft_m.end());

	// ------------------[2]-----------------
	printCount(2);
	r_operTest(std_m.rbegin(), std_m.rbegin(), ft_m.rbegin(), ft_m.rbegin());

	// ------------------[3]-----------------
	printCount(3);
	r_operTest(std_m.rend(), std_m.rend(), ft_m.rend(), ft_m.rend());
}

int main(void)
{
	std::cout << COLOR_RED "VECTOR" << COLOR_NOMAL << std::endl;
	construct();
	resize();
	max_size();
	empty();
	reserve();
	at();
	front();
	back();
	assign();
	push_back_pop_back();
	insert();
	erase();
	swap();
	clear();
	oper();
	iterOper();
	reverseIter();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << COLOR_RED "STACK" << COLOR_NOMAL << std::endl;
	stack_construct();
	stack_oper();
	stack_empty_pop();
	stack_top();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << COLOR_RED "MAP" << COLOR_NOMAL << std::endl;
	map_construct();
	map_empty();
	map_insert();
	map_erase();
	map_swap();
	map_clear();
	find();
	count();
	bound();
	equal_range();
	mapOperator();
	map_iterOper();
	// system("leaks test");
	// while(1){};
	return (0);
}
