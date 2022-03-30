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

namespace timeTool
{
	static double stime;
	static double etime;
	void setStartTime() { stime = clock(); }
	void setEndTime() { etime = clock(); }
	double getDeltaTime() { return etime - stime; }
}
void print(ft::vector<int> &v)
{
	ft::vector<int>::const_iterator it = v.begin();
	ft::vector<int>::const_iterator ite = v.end();


	std::cout << COLOR_YELLOW;
	std::cout << "--------ft--------|--------std--------|---diff---" << std::endl;
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << v.size();
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;
	
	std::cout << std::setw(12) << "capacity : ";
	std::cout << std::setw(3) << v.capacity();
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;
	

	for (; it != ite; it++)
	{
		std::cout << std::setw(10) << *it;
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;
	}
	std::cout << std::endl;
}

void construct(void)
{
	std::cout << BG_CYAN << "********************construct********************" << COLOR_NOMAL << std::endl;
	ft::vector<int> ft_vector;
 	print(ft_vector);
	ft::vector<int> ft_vector2(3);
 	print(ft_vector);
	ft::vector<int> ft_vector3(ft_vector2.begin(), ft_vector2.end());
  	print(ft_vector);
	ft::vector<int> ft_vector4(2, 7);
  	print(ft_vector);
	ft::vector<int> ft_vector5(ft_vector4);
 	print(ft_vector);
	ft_vector5.push_back(1);
	
	ft::vector<int> ft_vector6;

	ft_vector6 = ft_vector5;
 	print(ft_vector);
}

void	resize(void)
{
	std::cout << BG_CYAN << "********************resize********************" << COLOR_NOMAL << std::endl;
	ft::vector<int> ft_vector(5);

	for (size_t i = 0; i < ft_vector.size(); i++)
	{
		ft_vector[i] = i;
	}
 	print(ft_vector);
	ft_vector.resize(8);
	 print(ft_vector);
	ft_vector.resize(3, 2);
	 print(ft_vector);
	ft_vector.resize(5, 5);
	 print(ft_vector);
}

void	max_size(void)
{
	std::cout << BG_CYAN << "********************max_size**********************" << COLOR_NOMAL << std::endl;
	ft::vector<int> ft_vector;

	print(ft_vector);
	std::cout << std::setw(3) << ft_vector.max_size();
	std::cout << COLOR_NOMAL << std::endl;
}

void	empty(void)
{
	std::cout << BG_CYAN << "********************empty*************************" << COLOR_NOMAL << std::endl;
	ft::vector<int> myvector;
	int ft_sum(0);

	for (int i=1;i<=10;i++) myvector.push_back(i);
	while (!myvector.empty())
	{
		ft_sum += myvector.back();
		myvector.pop_back();
	}
	print(myvector);
}

void	reserve(void)
{
	std::cout << BG_CYAN << "********************reserve***********************" << COLOR_NOMAL << std::endl;
	ft::vector<int> ft_vector(5);

	for (size_t i = 0; i < ft_vector.size(); i++)
	{
		ft_vector[i] = i + 1;
	}
	print(ft_vector);
	ft_vector.reserve(10);
	print(ft_vector);
	ft_vector.reserve(3);
	print(ft_vector);
}

void	at(void)
{
	std::cout << BG_CYAN << "***********************at************************" << COLOR_NOMAL << std::endl;
	ft::vector<int> ft_vector(5);

	for (size_t i = 0; i < ft_vector.size(); i++)
	{

		ft_vector[i] = i + 1;
	}
	print(ft_vector);
	try
	{
		std::cout << "at(index 4) : " << ft_vector.at(4);
		std::cout << COLOR_YELLOW << std::setw(5) << " | " << COLOR_NOMAL;
		ft_vector.at(5);
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "ERROR : Out of Range! (" << e.what() << ")" << std::endl;
	}
}

void	front(void)
{
	std::cout << BG_CYAN << "********************front***********************" << COLOR_NOMAL << std::endl;
	ft::vector<int>		ft_vector(3);

	for (size_t i = 0; i < ft_vector.size(); i++)
	{
		ft_vector[i] = (i + 1);
	}
	print(ft_vector);
	std::cout << std::setw(3) << ft_vector.front();
	std::cout << std::setw(10) << COLOR_YELLOW " | " << COLOR_NOMAL;

	ft_vector.erase(ft_vector.begin());
	std::cout << std::setw(3) << ft_vector.front();
	print(ft_vector);	
}

void	back(void)
{
	std::cout << BG_CYAN << "********************back***********************" << COLOR_NOMAL << std::endl;

	ft::vector<int>		ft_vector(3);

	for (size_t i = 0; i < ft_vector.size(); i++)
	{
		ft_vector[i] = i + 1;
	}
	
	print(ft_vector);	
	std::cout << std::setw(3) << ft_vector.back();

	ft_vector.push_back(100);
	print(ft_vector);
	std::cout << std::setw(3) << ft_vector.back();
}

void	assign(void)
{

	std::cout << BG_CYAN << "********************assign***********************" << COLOR_NOMAL << std::endl;
	ft::vector<int>		ft_vector;	

	ft_vector.assign(3, 3);
	print(ft_vector);
	ft::vector<int> ft_vector2(3);

	for (size_t i = 0; i < ft_vector2.size(); i++)
	{
		ft_vector2[i] = i + 1;
	}

	ft::vector<int> ft_vector3;


	ft_vector3.assign(ft_vector2.begin(), ft_vector2.end());
	print(ft_vector);	
	ft::vector<int> ft_vector4;
	print(ft_vector);	
	ft_vector4.assign(5, 5);
	print(ft_vector);
}

void	push_back_pop_back(void)
{
	std::cout << BG_CYAN << "********************push_back***********************" << COLOR_NOMAL << std::endl;
	ft::vector<int> ft_vector;


	ft_vector.push_back(1);
	ft_vector.push_back(2);
	ft_vector.push_back(3);
	ft_vector.push_back(4);
	ft_vector.push_back(5);
	print(ft_vector);

	std::cout << BG_CYAN << "********************pop_back***********************" << COLOR_NOMAL << std::endl;

	ft_vector.pop_back();
	print(ft_vector);	
	ft_vector.pop_back();
	print(ft_vector);	
	ft_vector.pop_back();
	print(ft_vector);
}

void insert(void)
{
	std::cout << BG_CYAN << "********************insert***********************" << COLOR_NOMAL << std::endl;

	ft::vector<int> ft_vector(3);


	ft_vector.clear();
	for (size_t i = 1; i < 4; i++)
	{
		ft_vector.insert(ft_vector.begin(), i);
		print(ft_vector);
	}


	ft_vector.insert(ft_vector.end(), 10);
	print(ft_vector);	
	ft_vector.insert(ft_vector.begin() + 2, 5);
	print(ft_vector);
	ft_vector.insert(ft_vector.begin(), 2, 0);
	print(ft_vector);	
	ft_vector.insert(ft_vector.end(), 3, 20);
	print(ft_vector);	
	ft_vector.insert(ft_vector.begin() + 5, 5, 30);
	print(ft_vector);	
	ft_vector.clear();
	for (int i = 1; i < 4; i++)
	{
		ft_vector.push_back(i);
	}
	print(ft_vector);
	std::vector<int> std_vector2;
	ft::vector<int> ft_vector2;

	ft_vector2.insert(ft_vector2.begin(), ft_vector.begin(), ft_vector.end());
	print(ft_vector);
}

void	erase(void)
{
	std::cout << BG_CYAN << "********************erase***********************" << COLOR_NOMAL << std::endl;
	ft::vector<int> ft_vector;
	for (int i = 1; i < 6; i++)
	{
		ft_vector.push_back(i);
	}
	print(ft_vector);

	ft_vector.erase(ft_vector.begin());
	print(ft_vector);
	ft_vector.erase(ft_vector.end() - 1);
	print(ft_vector);
	ft_vector.erase(ft_vector.begin(), ft_vector.end());
	print(ft_vector);
}

void	swap(void)
{
	std::cout << BG_CYAN << "********************swap***********************" << COLOR_NOMAL << std::endl;
	
	ft::vector<int> ft_vector;
	ft::vector<int> ft_vector2;

	for (int i = 1; i < 6; i++)
	{

		ft_vector.push_back(i);
	}

	for (int i = 6; i < 11; i++)
	{
	
		ft_vector2.push_back(i);
	}
	print(ft_vector);
	ft_vector.swap(ft_vector2);
	print(ft_vector);
}

void	clear(void)
{
	std::cout << BG_CYAN << "********************clear***********************" << COLOR_NOMAL << std::endl;

	ft::vector<int> ft_vector;

	for (int i = 1; i < 6; i++)
	{
		
		ft_vector.push_back(i);
	}
	print(ft_vector);	
	ft_vector.clear();
	print(ft_vector);
}

void operTest(ft::vector<int> &ft_vector, ft::vector<int> &ft_vector2)
{
	// std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	
	ft.push_back((ft_vector == ft_vector2 ? "true" : "false"));

	operStr.push_back("!=");
	
	ft.push_back((ft_vector != ft_vector2 ? "true" : "false"));

	operStr.push_back("<");
	
	ft.push_back((ft_vector < ft_vector2 ? "true" : "false"));

	operStr.push_back("<=");
	
	ft.push_back((ft_vector <= ft_vector2 ? "true" : "false"));

	operStr.push_back(">");
	
	ft.push_back((ft_vector > ft_vector2 ? "true" : "false"));

	operStr.push_back(">=");
	ft.push_back((ft_vector >= ft_vector2 ? "true" : "false"));

}

void oper(void)
{
	std::cout << BG_CYAN << "********************oper***********************" << COLOR_NOMAL << std::endl;
	ft::vector<int> ft_vector;

	ft::vector<int> ft_vector2;

	for (int i = 1; i < 6; i++)
	{

		ft_vector.push_back(i);
		ft_vector2.push_back(i);
	}
	print(ft_vector);	
	operTest(ft_vector, ft_vector2);

	
	ft_vector2.push_back(10);
	print(ft_vector);	
	operTest(ft_vector, ft_vector2);
}

void iterOperTest(ft::vector<int>::iterator ftIter)
{
	std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;
	std::string str;

	str.assign("0");

	operStr.push_back("i++");

	str[0] = *(ftIter++) + '0';
	ft.push_back(str);

	operStr.push_back("++i");

	str[0] = *(++ftIter) + '0';
	ft.push_back(str);

	operStr.push_back("i--");

	str[0] = *(ftIter--) + '0';
	ft.push_back(str);

	operStr.push_back("--i");

	str[0] = *(--ftIter) + '0';
	ft.push_back(str);

	operStr.push_back("it + n");

	str[0] = *(ftIter + 1) + '0';
	ft.push_back(str);

	operStr.push_back("n + it");

	str[0] = *(1 + ftIter) + '0';
	ft.push_back(str);

	
	ftIter++;
	operStr.push_back("it - n");

	str[0] = *(ftIter - 1) + '0';
	ft.push_back(str);

	ft::vector<int>::iterator ftTemp;

	ftTemp = ftIter + 1;

	operStr.push_back("it - it");

	str[0] = ftTemp - ftIter + '0';
	ft.push_back(str);

	operStr.push_back("it += it");

	ftIter += 1;
	str[0] = *ftIter + '0';
	ft.push_back(str);

	operStr.push_back("it[n]");
	str[0] = ftIter[0] + '0';
	ft.push_back(str);

}

void iterOper(void)
{
	std::cout << BG_CYAN << "********************iterOper***********************" << COLOR_NOMAL << std::endl;
	// std::vector<int> std_vector;
	ft::vector<int> ft_vector;

	for (int i = 1; i < 4; i++)
	{
		//std_vector.push_back(i * 3);
		ft_vector.push_back(i * 3);
	}

	iterOperTest(ft_vector.begin());
}

void reverseIterTest( ft::vector<int>::reverse_iterator ftIter)
{
	std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;
	std::string str;

	str.assign("0");

	operStr.push_back("i++");

	str[0] = *(ftIter++) + '0';
	ft.push_back(str);

	operStr.push_back("++i");

	str[0] = *(++ftIter) + '0';
	ft.push_back(str);

	operStr.push_back("i--");
	str[0] = *(ftIter--) + '0';
	ft.push_back(str);

	operStr.push_back("--i");

	str[0] = *(--ftIter) + '0';
	ft.push_back(str);

	operStr.push_back("it + n");
	str[0] = *(ftIter + 1) + '0';
	ft.push_back(str);

	operStr.push_back("n + it");
	str[0] = *(1 + ftIter) + '0';
	ft.push_back(str);

	ftIter++;
	operStr.push_back("it - n");
	std.push_back(str);
	str[0] = *(ftIter - 1) + '0';
	ft.push_back(str);

	//std::vector<int>::reverse_iterator stdTemp;
	ft::vector<int>::reverse_iterator ftTemp;

	ftTemp = ftIter + 1;

	operStr.push_back("it - it");
	std.push_back(str);
	str[0] = ftTemp - ftIter + '0';
	ft.push_back(str);

	operStr.push_back("it += it");
	std.push_back(str);
	ftIter += 1;
	str[0] = *ftIter + '0';
	ft.push_back(str);

	operStr.push_back("it[n]");
	std.push_back(str);
	str[0] = ftIter[0] + '0';
	ft.push_back(str);

	operStr.push_back("base");
	std.push_back(str);
	str[0] = *ftIter.base() + '0';
	ft.push_back(str);

}

void reverseIter(void)
{
	std::cout << BG_CYAN << "********************reverseIter***********************" << COLOR_NOMAL << std::endl;
	ft::vector<int> ft_vector;

	for (int i = 1; i < 4; i++)
	{
		ft_vector.push_back(i * 3);
	}

	reverseIterTest(ft_vector.rbegin());
}

void stack_print(ft::stack<int, ft::vector<int> > ft_s)
{
	std::cout << COLOR_YELLOW;
	std::cout << "--------ft--------|--------std--------|---diff---" << std::endl;
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << ft_s.size();
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;

	while (!ft_s.empty())
	{
		std::cout << std::setw(10) << ft_s.top();
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;
		std::cout << std::endl;
		ft_s.pop();
	}
	std::cout << std::endl;
}
void	stack_construct(void)
{
	std::cout << BG_CYAN << "********************constructor***********************" << COLOR_NOMAL << std::endl;

	ft::stack<int> ft_s;

	for (size_t i = 1; i < 6; i++)
	{
		ft_s.push(i);
	}
	stack_print(ft_s);
	
	ft::vector<int> ft_v;

	for (size_t i = 1; i < 5; i++)
	{
		ft_v.push_back(i * 2);
	}
  
	
	ft::stack<int, ft::vector<int> > ft_s2(ft_v);
	stack_print(ft_s);
}
void operatePrint(std::vector<std::string> oper, std::vector<std::string> ft)
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
		std::cout << std::endl;

	}
	std::cout << std::endl;
}

void stack_operTest(ft::stack<int> &ft_s, ft::stack<int> &ft_s2)
{
	std::vector<std::string> ft;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	ft.push_back((ft_s == ft_s2 ? "true" : "false"));

	operStr.push_back("!=");
	
	ft.push_back((ft_s != ft_s2 ? "true" : "false"));

	operStr.push_back("<");

	ft.push_back((ft_s < ft_s2 ? "true" : "false"));

	operStr.push_back("<=");
	
	ft.push_back((ft_s <= ft_s2 ? "true" : "false"));

	operStr.push_back(">");
	
	ft.push_back((ft_s > ft_s2 ? "true" : "false"));

	operStr.push_back(">=");
	ft.push_back((ft_s >= ft_s2 ? "true" : "false"));

	operatePrint(operStr, ft);
}

void stack_oper(void)
{
	std::cout << BG_CYAN << "********************oper***********************" << COLOR_NOMAL << std::endl;

	ft::stack<int> ft_v;
	ft::stack<int> ft_v2;

	for (int i = 1; i < 4; i++)
	{
		ft_v.push(i * 3);
		ft_v2.push(i * 3);
	}
	stack_print(ft_v);
	stack_print(ft_v2);
	stack_operTest(ft_v, ft_v2);


	ft_v2.push(2);

	ft_v.push(1);
	stack_print(ft_v);
	stack_print(ft_v2);
	stack_operTest(ft_v, ft_v2);
}

void	stack_empty_pop(void)
{
	std::cout << BG_CYAN << "********************empty***********************" << COLOR_NOMAL << std::endl;

	ft::stack<int> ft_s;

	for (int i = 1; i < 6; i++)
	{

		ft_s.push(i);
	}
	stack_print(ft_s);
	while(!ft_s.empty())
	{
		ft_s.pop();
	}
	stack_print(ft_s);
}

void	stack_top(void)
{
	std::cout << BG_CYAN << "********************top***********************" << COLOR_NOMAL << std::endl;

	ft::stack<int> ft_s;

	ft_s.push(10);

	ft_s.push(20);
	stack_print(ft_s);
	ft_s.top() -= 5;
	stack_print(ft_s);

}

void printCount(int count)
{
	std::cout << std::setw(22) <<  "[" << count << "]" << std::endl;
}


void map_print(ft::map<int, std::string> &ft_m)
{
	ft::map<int, std::string>::const_iterator it = ft_m.begin();
	ft::map<int, std::string>::const_iterator ite = ft_m.end();


	std::cout << COLOR_YELLOW;
	std::cout << "--------ft--------|--------std--------|---diff---" << std::endl;
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << ft_m.size();
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;

	for (; it != ite; it++)
	{
		//-------------- key ---------
		std::cout << std::setw(10) << it->first;
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;

		//------------- value ----------
		std::cout << std::setw(10) << it->second;
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	map_construct(void)
{
	std::cout << BG_CYAN << "********************construct***********************" << COLOR_NOMAL << std::endl;
	std::list<ft::pair<int, std::string> > ft_lst;

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));

	// ------------------- [0] ----------------------------------
	printCount(0);

	ft::map<int, std::string> ft_m(ft_lst.begin(), ft_lst.end());
	map_print(ft_m);

	// ------------------- [1] ----------------------------------

	ft::map<int, std::string> ft_m2(ft_m);

	printCount(1);
	map_print(ft_m2);

	// ------------------- [2] ----------------------------------
	ft::map<int, std::string> ft_m3;

	ft_m3 = ft_m;
	printCount(2);
	map_print(ft_m2);
}

static void map_printIter(ft::map<int, std::string>::iterator &ft_it, ft::map<int, std::string> &ft_m)
{
	std::string ft_ret;


	ft_ret = (ft_it != ft_m.end() ? ft_it->second : "not find");
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << ft_ret;
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;
	

	std::cout << std::endl;

}

void	map_empty(void)
{
	std::cout << BG_CYAN << "********************empty***********************" << COLOR_NOMAL << std::endl;
	ft::map<int, std::string> ft_m;

	// --------------[0]----------------
	printCount(0);
	map_print(ft_m);
	std::cout << std::setw(10) << (ft_m.empty() == 1 ? "TRUE" : "FALSE");
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << COLOR_NOMAL;
	
	// --------------[1]----------------

	ft_m[1] = "hi";
	printCount(1);
	map_print(ft_m);
	std::cout << std::setw(10) << (ft_m.empty() == 1 ? "TRUE" : "FALSE");
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << COLOR_NOMAL;
	std::cout << std::endl;

	// --------------[0]----------------

	ft_m.clear();
	printCount(0);
	map_print(ft_m);
	std::cout << std::setw(10) << (ft_m.empty() == 1 ? "TRUE" : "FALSE");
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << COLOR_NOMAL;
	std::cout << std::endl;
}

void	map_insert(void)
{
	std::cout << BG_CYAN << "********************insert***********************" << COLOR_NOMAL << std::endl;
	ft::pair<ft::map<int, std::string>::iterator, bool> ft_ret;

	
	ft::map<int, std::string>::iterator ft_it;

	ft::map<int, std::string> ft_m;

	// ------------------[0]--------------

	ft_ret = ft_m.insert(ft::make_pair<int, std::string>(0, "insert"));

	printCount(0);
	map_print(ft_m);

	// ------------------[1]--------------
	ft_ret = ft_m.insert(ft::make_pair<int, std::string>(0, "insert"));

	printCount(1);
	map_print(ft_m);

	// ------------------[2]--------------

	ft_it = ft_m.insert(ft_m.begin(), ft::make_pair<int, std::string>(10, "insert2"));

	printCount(2);
	map_print(ft_m);

	// ------------------[3]--------------
	
	ft_it = ft_m.insert(ft_m.begin(), ft::make_pair<int, std::string>(4, "insert3"));

	printCount(3);
	map_print(ft_m);

	// ------------------[4]--------------
	printCount(4);
	std::list<ft::pair<int, std::string> > ft_lst;

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));

	ft_m.insert(ft_lst.begin(), ft_lst.end());
	
	map_print(ft_m);
}

void	map_erase(void)
{
	std::cout << BG_CYAN << "********************erase***********************" << COLOR_NOMAL << std::endl;

	std::list<ft::pair<int, std::string> > ft_lst;

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));


	ft::map<int, std::string> ft_m(ft_lst.begin(), ft_lst.end());

	// ----------------[0]---------------------
	printCount(0);
	map_print(ft_m);

	// ----------------[1]---------------------
	// hello delete
	printCount(1);
	ft_m.erase(ft_m.begin());
	map_print(ft_m);

	// ----------------[2]---------------------
	// tester delete
	printCount(2);
	ft_m.erase(--ft_m.end());
	map_print(ft_m);

	// ----------------[3]---------------------
	// none key delete
	printCount(3);
	size_t ft_ret;
	ft_ret = ft_m.erase(100);
	map_print(ft_m);

	// ----------------[4]---------------------
	// delete all
	printCount(4);
	ft_m.erase(ft_m.begin(), ft_m.end());
	map_print(ft_m);
}

void	map_swap(void)
{
	std::cout << BG_CYAN << "********************swap***********************" << COLOR_NOMAL << std::endl;

	std::list<ft::pair<int, std::string> > ft_lst;

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));


	ft::map<int, std::string> ft_m(ft_lst.begin(), ft_lst.end());
	ft::map<int, std::string> ft_m2(ft_lst.begin(), ++(++ft_lst.begin()));

	// ------------------[0]--------------
	printCount(0);
	std::cout << std::setw(38) << "---------map 1----------" << std::endl;
	map_print(ft_m);
	std::cout << std::setw(38) << "---------map 2----------" << std::endl;
	map_print(ft_m2);

	// ------------------[1]--------------
	printCount(1);

	ft_m.swap(ft_m2);
	std::cout << std::setw(38) << "---------map 1----------" << std::endl;
	map_print(ft_m);
	std::cout << std::setw(38) << "---------map 2----------" << std::endl;
	map_print(ft_m2);
}

void	map_clear(void)
{
	std::cout << BG_CYAN << "********************clear***********************" << COLOR_NOMAL << std::endl;
	std::list<ft::pair<int, std::string> > ft_lst;

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));


	ft::map<int, std::string> ft_m(ft_lst.begin(), ft_lst.end());
	// --------------[0]-------------
	printCount(0);
	map_print(ft_m);
	// --------------[1]-------------
	printCount(1);
	ft_m.clear();
	map_print(ft_m);
}

void	find(void)
{
	std::cout << BG_CYAN << "********************find***********************" << COLOR_NOMAL << std::endl;
	std::list<ft::pair<int, std::string> > ft_lst;


	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));

	ft::map<int, std::string> ft_m(ft_lst.begin(), ft_lst.end());
	
	ft::map<int, std::string>::iterator ft_it;
	// -------------[0]--------------
	printCount(0);
	map_print(ft_m);
	// -------------[1]--------------
	// find map
	printCount(1);
	ft_it = ft_m.find(22);
	map_printIter(ft_it, ft_m);

	// -------------[2]--------------
	// not exist value
	printCount(2);
	ft_it = ft_m.find(100);
	
	map_printIter(ft_it, ft_m);
}

void	retPrint( size_t ft_count)
{
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << (ft_count ? "TRUE" : "FALSE");
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;
}

void	count(void)
{
	std::cout << BG_CYAN << "********************count***********************" << COLOR_NOMAL << std::endl;
	std::list<ft::pair<int, std::string> > ft_lst;


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
	//---------------[0]--------------
	printCount(0);
	map_print(ft_m);
	size_t ft_count;
	
	ft_count = ft_m.count(5);
	retPrint( ft_count);
	

	ft_count = ft_m.count(100);
	retPrint( ft_count);
}

void	bound(void)
{
	std::cout << BG_CYAN << "********************bound***********************" << COLOR_NOMAL << std::endl;
	std::list<ft::pair<int, std::string> > ft_lst;


	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));


	ft::map<int, std::string> ft_m;

	ft::map<int, std::string>::iterator ft_it;
	ft_m.insert(ft_lst.begin(), ft_lst.end());

	// -------------[0]-------------
	printCount(0);
	map_print(ft_m);
	
	// -------------[1]-------------
	std::cout << std::setw(38) << "---------lower----------" << std::endl;
	printCount(1);
	ft_it = ft_m.lower_bound(-5);
	map_printIter(ft_it, ft_m);

	// -------------[2]-------------
	printCount(0);
	ft_it = ft_m.lower_bound(2);
	map_printIter( ft_it, ft_m);

	// -------------[3]-------------
	printCount(3);
	ft_it = ft_m.lower_bound(22);
	map_printIter(ft_it, ft_m);

	// -------------[4]-------------
	printCount(4);

	ft_it = ft_m.lower_bound(100);
	map_printIter( ft_it, ft_m);


	// -------------[5]-------------
	std::cout << std::setw(38) << "---------upper----------" << std::endl;
	printCount(5);
	
	ft_it = ft_m.upper_bound(-5);
	map_printIter( ft_it, ft_m);

	// -------------[6]-------------
	printCount(6);

	ft_it = ft_m.upper_bound(2);
	map_printIter(ft_it, ft_m);

	// -------------[7]-------------
	printCount(7);
	
	ft_it = ft_m.upper_bound(22);
	map_printIter(ft_it,  ft_m);

	// -------------[8]-------------
	printCount(8);

	ft_it = ft_m.upper_bound(30);
	map_printIter( ft_it, ft_m);
}

static void	map_printIter(  ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> &ft_pr,
	 ft::map<int, std::string> &ft_m)
{

	std::string ft_ret;

	ft_ret = (ft_pr.first != ft_m.end() ? ft_pr.first->second : "not find");
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << ft_ret;
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;


	ft_ret = (ft_pr.second != ft_m.end() ? ft_pr.second->second : "not find");
	std::cout << std::setw(8) << "ret2 : ";
	std::cout << std::setw(7) << ft_ret;
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;

}

void	equal_range(void)
{
	std::cout << BG_CYAN << "********************equal_range***********************" << COLOR_NOMAL << std::endl;

	std::list<ft::pair<int, std::string> > ft_lst;

	ft::map<int, std::string> ft_m;
	
	ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> ft_pr;
	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));

	ft_m.insert(ft_lst.begin(), ft_lst.end());

	// -----------[0]------------
	printCount(0);
	map_print(ft_m);
	
	// -----------[1]------------
	printCount(1);
	
	ft_pr = ft_m.equal_range(-1);
	map_printIter(ft_pr,ft_m);
	
	// -----------[2]------------
	printCount(2);

	ft_pr = ft_m.equal_range(2);
	map_printIter( ft_pr,  ft_m);
	
	// -----------[3]------------
	printCount(3);
	
	ft_pr = ft_m.equal_range(15);
	map_printIter( ft_pr, ft_m);
	
	// -----------[4]------------
	printCount(4);

	ft_pr = ft_m.equal_range(30);
	map_printIter( ft_pr, ft_m);
	
	// -----------[5]------------
	printCount(5);

	ft_pr = ft_m.equal_range(100);
	map_printIter( ft_pr, ft_m);
}

void operatorTest( ft::map<int, std::string> ft_m, ft::map<int, std::string> ft_m2)
{

	std::vector<std::string> ft;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	
	ft.push_back((ft_m == ft_m2 ? "TRUE" : "FALSE"));

	operStr.push_back("!=");
	
	ft.push_back((ft_m != ft_m2 ? "TRUE" : "FALSE"));

	operStr.push_back("<");
	
	ft.push_back((ft_m < ft_m2 ? "TRUE" : "FALSE"));

	operStr.push_back("<=");

	ft.push_back((ft_m <= ft_m2 ? "TRUE" : "FALSE"));

	operStr.push_back(">");

	ft.push_back((ft_m > ft_m2 ? "TRUE" : "FALSE"));

	operStr.push_back(">=");

	ft.push_back((ft_m >= ft_m2 ? "TRUE" : "FALSE"));

	operatePrint(operStr, ft);
}

void mapOperator()
{
	std::cout << BG_CYAN << "********************operators***********************" << COLOR_NOMAL << std::endl;

	std::list<ft::pair<int, std::string> > ft_lst;
	
	ft::map<int, std::string> ft_m;

	ft::map<int, std::string> ft_m2;

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));

	ft_m.insert(ft_lst.begin(), ft_lst.end());
	
	ft_m2.insert(ft_lst.begin(), ft_lst.end());
	

	// ---------------[0]----------------
	printCount(0);
	map_print(ft_m);
	map_print(ft_m2);
	operatorTest( ft_m, ft_m2);

	// ---------------[1]----------------
	printCount(1);

	ft_m.erase(++ft_m.begin());
	map_print(ft_m);
	map_print(ft_m2);
	operatorTest( ft_m, ft_m2);

	// ---------------[2]----------------
	printCount(2);
	
	ft_m2.erase(ft_m2.begin());
	map_print(ft_m);
	map_print(ft_m2);
	operatorTest(ft_m, ft_m2);
}

void operTest(ft::map<int,std::string>::iterator ft_iter, ft::map<int, std::string>::iterator ft_iter2)
{
	
	std::vector<std::string> ft;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	
	ft.push_back((ft_iter == ft_iter2 ? "true" : "false"));

	operStr.push_back("!=");
	
	ft.push_back((ft_iter != ft_iter2 ? "true" : "false"));

	operatePrint(operStr, ft);
}

void r_operTest(ft::map<int,std::string>::reverse_iterator ft_iter, ft::map<int, std::string>::reverse_iterator ft_iter2)
{

	std::vector<std::string> ft;
	std::vector<std::string> operStr;

	operStr.push_back("==");

	ft.push_back((ft_iter == ft_iter2 ? "true" : "false"));

	operStr.push_back("!=");

	ft.push_back((ft_iter != ft_iter2 ? "true" : "false"));

	operatePrint(operStr, ft);
}

void	map_iterOper(void)
{
	std::cout << BG_CYAN << "********************iterator***********************" << COLOR_NOMAL << std::endl;

	std::list<ft::pair<int, std::string> > ft_lst;
	ft::map<int, std::string> ft_m;

	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(30, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "this"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(2, "hi"));

	ft_m.insert(ft_lst.begin(), ft_lst.end());

	// ------------------[0]-----------------
	printCount(0);
	operTest( ft_m.begin(), ft_m.begin());

	// ------------------[1]-----------------
	printCount(1);
	operTest(ft_m.end(), ft_m.end());

	// ------------------[2]-----------------
	printCount(2);
	r_operTest( ft_m.rbegin(), ft_m.rbegin());

	// ------------------[3]-----------------
	printCount(3);
	r_operTest( ft_m.rend(), ft_m.rend());
}

int main(void)
{
	std::cout << "-----< VECTOR TEST >----" << std::endl;
	timeTool::setStartTime();

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

	timeTool::setEndTime();
	std::cout << " > Time = " << timeTool::getDeltaTime() << "ms" << std::endl;
	std::cout << "---------------------" << std::endl << std::endl;

	std::cout << "-----< STACK TEST >----" << std::endl;
	timeTool::setStartTime();

	std::cout << COLOR_RED "STACK" << COLOR_NOMAL << std::endl;
	stack_construct();
	stack_oper();
	stack_empty_pop();
	stack_top();

	timeTool::setEndTime();
	std::cout << " > Time = " << timeTool::getDeltaTime() << "ms" << std::endl;
	std::cout << "---------------------" << std::endl << std::endl;

	std::cout << "-----< MAP TEST >----" << std::endl;
	timeTool::setStartTime();

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
	timeTool::setEndTime();
	std::cout << " > Time = " << timeTool::getDeltaTime() << "ms" << std::endl;
	std::cout << "---------------------" << std::endl << std::endl;
	return (0);
}
