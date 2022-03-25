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
	// assign();
	// push_back_pop_back();
	// insert();
	// erase();
	// swap();
	// clear();
	// oper();
	// iterOper();
	reverseIter();

	//  system("leaks test");
	// while(1){};
	return (0);
}
