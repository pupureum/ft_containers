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
void print(std::vector<int> &v)
{
	std::vector<int>::const_iterator it = v.begin();
	std::vector<int>::const_iterator ite = v.end();


	std::cout << COLOR_YELLOW;
	std::cout << "--------std--------|--------std--------|---diff---" << std::endl;
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
	std::vector<int> std_vector;
 	print(std_vector);
	std::vector<int> std_vector2(3);
 	print(std_vector);
	std::vector<int> std_vector3(std_vector2.begin(), std_vector2.end());
  	print(std_vector);
	std::vector<int> std_vector4(2, 7);
  	print(std_vector);
	std::vector<int> std_vector5(std_vector4);
 	print(std_vector);
	std_vector5.push_back(1);
	
	std::vector<int> std_vector6;

	std_vector6 = std_vector5;
 	print(std_vector);
}

void	resize(void)
{
	std::cout << BG_CYAN << "********************resize********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector(5);

	for (size_t i = 0; i < std_vector.size(); i++)
	{
		std_vector[i] = i;
	}
 	print(std_vector);
	std_vector.resize(8);
	 print(std_vector);
	std_vector.resize(3, 2);
	 print(std_vector);
	std_vector.resize(5, 5);
	 print(std_vector);
}

void	max_size(void)
{
	std::cout << BG_CYAN << "********************max_size**********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector;

	print(std_vector);
	std::cout << std::setw(3) << std_vector.max_size();
	std::cout << COLOR_NOMAL << std::endl;
}

void	empty(void)
{
	std::cout << BG_CYAN << "********************empty*************************" << COLOR_NOMAL << std::endl;
	std::vector<int> myvector;
	int std_sum(0);

	for (int i=1;i<=10;i++) myvector.push_back(i);
	while (!myvector.empty())
	{
		std_sum += myvector.back();
		myvector.pop_back();
	}
	print(myvector);
}

void	reserve(void)
{
	std::cout << BG_CYAN << "********************reserve***********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector(5);

	for (size_t i = 0; i < std_vector.size(); i++)
	{
		std_vector[i] = i + 1;
	}
	print(std_vector);
	std_vector.reserve(10);
	print(std_vector);
	std_vector.reserve(3);
	print(std_vector);
}

void	at(void)
{
	std::cout << BG_CYAN << "***********************at************************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector(5);

	for (size_t i = 0; i < std_vector.size(); i++)
	{

		std_vector[i] = i + 1;
	}
	print(std_vector);
	try
	{
		std::cout << "at(index 4) : " << std_vector.at(4);
		std::cout << COLOR_YELLOW << std::setw(5) << " | " << COLOR_NOMAL;
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
	std::vector<int>		std_vector(3);

	for (size_t i = 0; i < std_vector.size(); i++)
	{
		std_vector[i] = (i + 1);
	}
	print(std_vector);
	std::cout << std::setw(3) << std_vector.front();
	std::cout << std::setw(10) << COLOR_YELLOW " | " << COLOR_NOMAL;

	std_vector.erase(std_vector.begin());
	std::cout << std::setw(3) << std_vector.front();
	print(std_vector);	
}

void	back(void)
{
	std::cout << BG_CYAN << "********************back***********************" << COLOR_NOMAL << std::endl;

	std::vector<int>		std_vector(3);

	for (size_t i = 0; i < std_vector.size(); i++)
	{
		std_vector[i] = i + 1;
	}
	
	print(std_vector);	
	std::cout << std::setw(3) << std_vector.back();

	std_vector.push_back(100);
	print(std_vector);
	std::cout << std::setw(3) << std_vector.back();
}

void	assign(void)
{

	std::cout << BG_CYAN << "********************assign***********************" << COLOR_NOMAL << std::endl;
	std::vector<int>		std_vector;	

	std_vector.assign(3, 3);
	print(std_vector);
	std::vector<int> std_vector2(3);

	for (size_t i = 0; i < std_vector2.size(); i++)
	{
		std_vector2[i] = i + 1;
	}

	std::vector<int> std_vector3;


	std_vector3.assign(std_vector2.begin(), std_vector2.end());
	print(std_vector);	
	std::vector<int> std_vector4;
	print(std_vector);	
	std_vector4.assign(5, 5);
	print(std_vector);
}

void	push_back_pop_back(void)
{
	std::cout << BG_CYAN << "********************push_back***********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector;


	std_vector.push_back(1);
	std_vector.push_back(2);
	std_vector.push_back(3);
	std_vector.push_back(4);
	std_vector.push_back(5);
	print(std_vector);

	std::cout << BG_CYAN << "********************pop_back***********************" << COLOR_NOMAL << std::endl;

	std_vector.pop_back();
	print(std_vector);	
	std_vector.pop_back();
	print(std_vector);	
	std_vector.pop_back();
	print(std_vector);
}

void insert(void)
{
	std::cout << BG_CYAN << "********************insert***********************" << COLOR_NOMAL << std::endl;

	std::vector<int> std_vector(3);


	std_vector.clear();
	for (size_t i = 1; i < 4; i++)
	{
		std_vector.insert(std_vector.begin(), i);
		print(std_vector);
	}


	std_vector.insert(std_vector.end(), 10);
	print(std_vector);	
	std_vector.insert(std_vector.begin() + 2, 5);
	print(std_vector);
	std_vector.insert(std_vector.begin(), 2, 0);
	print(std_vector);	
	std_vector.insert(std_vector.end(), 3, 20);
	print(std_vector);	
	std_vector.insert(std_vector.begin() + 5, 5, 30);
	print(std_vector);	
	std_vector.clear();
	for (int i = 1; i < 4; i++)
	{
		std_vector.push_back(i);
	}
	print(std_vector);
	std::vector<int> std_vector2;

	std_vector2.insert(std_vector2.begin(), std_vector.begin(), std_vector.end());
	print(std_vector2);
}

void	erase(void)
{
	std::cout << BG_CYAN << "********************erase***********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector;
	for (int i = 1; i < 6; i++)
	{
		std_vector.push_back(i);
	}
	print(std_vector);

	std_vector.erase(std_vector.begin());
	print(std_vector);
	std_vector.erase(std_vector.end() - 1);
	print(std_vector);
	std_vector.erase(std_vector.begin(), std_vector.end());
	print(std_vector);
}

void	swap(void)
{
	std::cout << BG_CYAN << "********************swap***********************" << COLOR_NOMAL << std::endl;
	
	std::vector<int> std_vector;
	std::vector<int> std_vector2;

	for (int i = 1; i < 6; i++)
	{

		std_vector.push_back(i);
	}

	for (int i = 6; i < 11; i++)
	{
	
		std_vector2.push_back(i);
	}
	print(std_vector);
	std_vector.swap(std_vector2);
	print(std_vector);
}

void	clear(void)
{
	std::cout << BG_CYAN << "********************clear***********************" << COLOR_NOMAL << std::endl;

	std::vector<int> std_vector;

	for (int i = 1; i < 6; i++)
	{
		
		std_vector.push_back(i);
	}
	print(std_vector);	
	std_vector.clear();
	print(std_vector);
}

void operTest(std::vector<int> &std_vector, std::vector<int> &std_vector2)
{
	std::vector<std::string> std;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	
	std.push_back((std_vector == std_vector2 ? "true" : "false"));

	operStr.push_back("!=");
	
	std.push_back((std_vector != std_vector2 ? "true" : "false"));

	operStr.push_back("<");
	
	std.push_back((std_vector < std_vector2 ? "true" : "false"));

	operStr.push_back("<=");
	
	std.push_back((std_vector <= std_vector2 ? "true" : "false"));

	operStr.push_back(">");
	
	std.push_back((std_vector > std_vector2 ? "true" : "false"));

	operStr.push_back(">=");
	std.push_back((std_vector >= std_vector2 ? "true" : "false"));

}

void oper(void)
{
	std::cout << BG_CYAN << "********************oper***********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector;

	std::vector<int> std_vector2;

	for (int i = 1; i < 6; i++)
	{

		std_vector.push_back(i);
		std_vector2.push_back(i);
	}
	print(std_vector);	
	operTest(std_vector, std_vector2);

	
	std_vector2.push_back(10);
	print(std_vector);	
	operTest(std_vector, std_vector2);
}

void iterOperTest(std::vector<int>::iterator stdIter)
{
	std::vector<std::string> std;
	std::vector<std::string> operStr;
	std::string str;

	str.assign("0");

	operStr.push_back("i++");

	str[0] = *(stdIter++) + '0';
	std.push_back(str);

	operStr.push_back("++i");

	str[0] = *(++stdIter) + '0';
	std.push_back(str);

	operStr.push_back("i--");

	str[0] = *(stdIter--) + '0';
	std.push_back(str);

	operStr.push_back("--i");

	str[0] = *(--stdIter) + '0';
	std.push_back(str);

	operStr.push_back("it + n");

	str[0] = *(stdIter + 1) + '0';
	std.push_back(str);

	operStr.push_back("n + it");

	str[0] = *(1 + stdIter) + '0';
	std.push_back(str);

	
	stdIter++;
	operStr.push_back("it - n");

	str[0] = *(stdIter - 1) + '0';
	std.push_back(str);

	std::vector<int>::iterator stdTemp;

	stdTemp = stdIter + 1;

	operStr.push_back("it - it");

	str[0] = stdTemp - stdIter + '0';
	std.push_back(str);

	operStr.push_back("it += it");

	stdIter += 1;
	str[0] = *stdIter + '0';
	std.push_back(str);

	operStr.push_back("it[n]");
	str[0] = stdIter[0] + '0';
	std.push_back(str);

}

void iterOper(void)
{
	std::cout << BG_CYAN << "********************iterOper***********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector;


	for (int i = 1; i < 4; i++)
	{
		std_vector.push_back(i * 3);
	}

	iterOperTest(std_vector.begin());
}

void reverseIterTest( std::vector<int>::reverse_iterator stdIter)
{
	std::vector<std::string> std;
	std::vector<std::string> operStr;
	std::string str;

	str.assign("0");

	operStr.push_back("i++");

	str[0] = *(stdIter++) + '0';
	std.push_back(str);

	operStr.push_back("++i");

	str[0] = *(++stdIter) + '0';
	std.push_back(str);

	operStr.push_back("i--");
	str[0] = *(stdIter--) + '0';
	std.push_back(str);

	operStr.push_back("--i");

	str[0] = *(--stdIter) + '0';
	std.push_back(str);

	operStr.push_back("it + n");
	str[0] = *(stdIter + 1) + '0';
	std.push_back(str);

	operStr.push_back("n + it");
	str[0] = *(1 + stdIter) + '0';
	std.push_back(str);

	stdIter++;
	operStr.push_back("it - n");
	std.push_back(str);
	str[0] = *(stdIter - 1) + '0';
	std.push_back(str);

	std::vector<int>::reverse_iterator stdTemp;

	stdTemp = stdIter + 1;

	operStr.push_back("it - it");
	std.push_back(str);
	str[0] = stdTemp - stdIter + '0';
	std.push_back(str);

	operStr.push_back("it += it");
	std.push_back(str);
	stdIter += 1;
	str[0] = *stdIter + '0';
	std.push_back(str);

	operStr.push_back("it[n]");
	std.push_back(str);
	str[0] = stdIter[0] + '0';
	std.push_back(str);

	operStr.push_back("base");
	std.push_back(str);
	str[0] = *stdIter.base() + '0';
	std.push_back(str);

}

void reverseIter(void)
{
	std::cout << BG_CYAN << "********************reverseIter***********************" << COLOR_NOMAL << std::endl;
	std::vector<int> std_vector;

	for (int i = 1; i < 4; i++)
	{
		std_vector.push_back(i * 3);
	}

	reverseIterTest(std_vector.rbegin());
}

void stack_print(std::stack<int> std_s)
{
	std::cout << COLOR_YELLOW;
	std::cout << "--------std--------|--------std--------|---diff---" << std::endl;
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << std_s.size();
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;
	std::cout << std::endl;

	while (!std_s.empty())
	{
		std::cout << std::setw(10) << std_s.top();
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;
		std::cout << std::setw(10) << std_s.top();
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;
		std::cout << std::setw(10) << (std_s.top() == std_s.top() ? COLOR_GREEN"OK" : COLOR_RED"KO") << COLOR_NOMAL << std::endl;
		std_s.pop();
		std::cout << std::endl;
	}
}

void stack_print(std::stack<int, std::vector<int> > std_s)
{
	std::cout << COLOR_YELLOW;
	std::cout << "--------std--------|--------std--------|---diff---" << std::endl;
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << std_s.size();
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;

	while (!std_s.empty())
	{
		std::cout << std::setw(10) << std_s.top();
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << COLOR_NOMAL;
		std::cout << std::endl;
		std_s.pop();
	}
	std::cout << std::endl;
}
void	stack_construct(void)
{
	std::cout << BG_CYAN << "********************constructor***********************" << COLOR_NOMAL << std::endl;

	std::stack<int> std_s;

	for (size_t i = 1; i < 6; i++)
	{
		std_s.push(i);
	}
	stack_print(std_s);
	
	std::vector<int> std_v;

	for (size_t i = 1; i < 5; i++)
	{
		std_v.push_back(i * 2);
	}
  
	
	std::stack<int, std::vector<int> > std_s2(std_v);
	stack_print(std_s);
}
void operatePrint(std::vector<std::string> oper, std::vector<std::string> std)
{
	std::cout << COLOR_YELLOW;
	std::cout << "--oper--|------std------|------std------|---diff--" << std::endl;
	std::cout << COLOR_NOMAL;

	for (size_t i = 0; i < oper.size(); i++)
	{
		std::cout << std::setw(4 + oper[i].size() / 2) << oper[i];
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(5 - oper[i].size() / 2) << "|";
		std::cout << COLOR_NOMAL;

		std::cout << std::setw(7 + std[i].size() / 2) << std[i];
		std::cout << COLOR_YELLOW;
		std::cout << std::setw(8 - std[i].size() / 2) << "|";
		std::cout << COLOR_NOMAL;
		std::cout << std::endl;

	}
	std::cout << std::endl;
}

void stack_operTest(std::stack<int> &std_s, std::stack<int> &std_s2)
{

	std::vector<std::string> std;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	std.push_back((std_s == std_s2 ? "true" : "false"));

	operStr.push_back("!=");
	
	std.push_back((std_s != std_s2 ? "true" : "false"));

	operStr.push_back("<");

	std.push_back((std_s < std_s2 ? "true" : "false"));

	operStr.push_back("<=");
	
	std.push_back((std_s <= std_s2 ? "true" : "false"));

	operStr.push_back(">");
	
	std.push_back((std_s > std_s2 ? "true" : "false"));

	operStr.push_back(">=");
	std.push_back((std_s >= std_s2 ? "true" : "false"));

	operatePrint(operStr, std);
}

void stack_oper(void)
{
	std::cout << BG_CYAN << "********************oper***********************" << COLOR_NOMAL << std::endl;
	std::stack<int> std_v;
	std::stack<int> std_v2;

	for (int i = 1; i < 4; i++)
	{
		std_v.push(i * 3);
		std_v2.push(i * 3);
	}
	stack_print(std_v);
	stack_print(std_v2);
	stack_operTest(std_v, std_v2);


	std_v2.push(2);

	std_v.push(1);
	stack_print(std_v);
	stack_print(std_v2);
	stack_operTest(std_v, std_v2);
}

void	stack_empty_pop(void)
{
	std::cout << BG_CYAN << "********************empty***********************" << COLOR_NOMAL << std::endl;

	std::stack<int> std_s;

	for (int i = 1; i < 6; i++)
	{

		std_s.push(i);
	}
	stack_print(std_s);
	while(!std_s.empty())
	{
		std_s.pop();
	}
	stack_print(std_s);
}

void	stack_top(void)
{
	std::cout << BG_CYAN << "********************top***********************" << COLOR_NOMAL << std::endl;

	std::stack<int> std_s;

	std_s.push(10);

	std_s.push(20);
	stack_print(std_s);
	std_s.top() -= 5;
	stack_print(std_s);

}

void printCount(int count)
{
	std::cout << std::setw(22) <<  "[" << count << "]" << std::endl;
}


void map_print(std::map<int, std::string> &std_m)
{
	std::map<int, std::string>::const_iterator it = std_m.begin();
	std::map<int, std::string>::const_iterator ite = std_m.end();


	std::cout << COLOR_YELLOW;
	std::cout << "--------std--------|--------std--------|---diff---" << std::endl;
	std::cout << COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << std_m.size();
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
	std::list<std::pair<int, std::string> > std_lst;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));

	// ------------------- [0] ----------------------------------
	printCount(0);

	std::map<int, std::string> std_m(std_lst.begin(), std_lst.end());
	map_print(std_m);

	// ------------------- [1] ----------------------------------

	std::map<int, std::string> std_m2(std_m);

	printCount(1);
	map_print(std_m2);

	// ------------------- [2] ----------------------------------
	std::map<int, std::string> std_m3;

	std_m3 = std_m;
	printCount(2);
	map_print(std_m2);
}

static void map_printIter(std::map<int, std::string>::iterator &std_it, std::map<int, std::string> &std_m)
{
	std::string std_ret;


	std_ret = (std_it != std_m.end() ? std_it->second : "not find");
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << std_ret;
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;

	std::cout << std::endl;

}

void	map_empty(void)
{
	std::cout << BG_CYAN << "********************empty***********************" << COLOR_NOMAL << std::endl;
	std::map<int, std::string> std_m;

	// --------------[0]----------------
	printCount(0);
	map_print(std_m);
	std::cout << std::setw(10) << (std_m.empty() == 1 ? "TRUE" : "FALSE");
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << COLOR_NOMAL;
	
	// --------------[1]----------------

	std_m[1] = "hi";
	printCount(1);
	map_print(std_m);
	std::cout << std::setw(10) << (std_m.empty() == 1 ? "TRUE" : "FALSE");
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << COLOR_NOMAL;
	std::cout << std::endl;

	// --------------[0]----------------

	std_m.clear();
	printCount(0);
	map_print(std_m);
	std::cout << std::setw(10) << (std_m.empty() == 1 ? "TRUE" : "FALSE");
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << COLOR_NOMAL;
	std::cout << std::endl;
}

void	map_insert(void)
{
	std::cout << BG_CYAN << "********************insert***********************" << COLOR_NOMAL << std::endl;
	std::pair<std::map<int, std::string>::iterator, bool> std_ret;

	
	std::map<int, std::string>::iterator std_it;

	std::map<int, std::string> std_m;

	// ------------------[0]--------------

	std_ret = std_m.insert(std::make_pair<int, std::string>(0, "insert"));

	printCount(0);
	map_print(std_m);

	// ------------------[1]--------------
	std_ret = std_m.insert(std::make_pair<int, std::string>(0, "insert"));

	printCount(1);
	map_print(std_m);

	// ------------------[2]--------------

	std_it = std_m.insert(std_m.begin(), std::make_pair<int, std::string>(10, "insert2"));

	printCount(2);
	map_print(std_m);

	// ------------------[3]--------------
	
	std_it = std_m.insert(std_m.begin(), std::make_pair<int, std::string>(4, "insert3"));

	printCount(3);
	map_print(std_m);

	// ------------------[4]--------------
	printCount(4);
	std::list<std::pair<int, std::string> > std_lst;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));

	std_m.insert(std_lst.begin(), std_lst.end());
	
	map_print(std_m);
}

void	map_erase(void)
{
	std::cout << BG_CYAN << "********************erase***********************" << COLOR_NOMAL << std::endl;

	std::list<std::pair<int, std::string> > std_lst;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));


	std::map<int, std::string> std_m(std_lst.begin(), std_lst.end());

	// ----------------[0]---------------------
	printCount(0);
	map_print(std_m);

	// ----------------[1]---------------------
	// hello delete
	printCount(1);
	std_m.erase(std_m.begin());
	map_print(std_m);

	// ----------------[2]---------------------
	// tester delete
	printCount(2);
	std_m.erase(--std_m.end());
	map_print(std_m);

	// ----------------[3]---------------------
	// none key delete
	printCount(3);
	size_t std_ret;
	std_ret = std_m.erase(100);
	map_print(std_m);

	// ----------------[4]---------------------
	// delete all
	printCount(4);
	std_m.erase(std_m.begin(), std_m.end());
	map_print(std_m);
}

void	map_swap(void)
{
	std::cout << BG_CYAN << "********************swap***********************" << COLOR_NOMAL << std::endl;

	std::list<std::pair<int, std::string> > std_lst;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));


	std::map<int, std::string> std_m(std_lst.begin(), std_lst.end());
	std::map<int, std::string> std_m2(std_lst.begin(), ++(++std_lst.begin()));

	// ------------------[0]--------------
	printCount(0);
	std::cout << std::setw(38) << "---------map 1----------" << std::endl;
	map_print(std_m);
	std::cout << std::setw(38) << "---------map 2----------" << std::endl;
	map_print(std_m2);

	// ------------------[1]--------------
	printCount(1);

	std_m.swap(std_m2);
	std::cout << std::setw(38) << "---------map 1----------" << std::endl;
	map_print(std_m);
	std::cout << std::setw(38) << "---------map 2----------" << std::endl;
	map_print(std_m2);
}

void	map_clear(void)
{
	std::cout << BG_CYAN << "********************clear***********************" << COLOR_NOMAL << std::endl;
	std::list<std::pair<int, std::string> > std_lst;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));


	std::map<int, std::string> std_m(std_lst.begin(), std_lst.end());
	// --------------[0]-------------
	printCount(0);
	map_print(std_m);
	// --------------[1]-------------
	printCount(1);
	std_m.clear();
	map_print(std_m);
}

void	find(void)
{
	std::cout << BG_CYAN << "********************find***********************" << COLOR_NOMAL << std::endl;
	std::list<std::pair<int, std::string> > std_lst;


	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));

	std::map<int, std::string> std_m(std_lst.begin(), std_lst.end());
	
	std::map<int, std::string>::iterator std_it;
	// -------------[0]--------------
	printCount(0);
	map_print(std_m);
	// -------------[1]--------------
	// find map
	printCount(1);
	std_it = std_m.find(22);
	map_printIter(std_it, std_m);

	// -------------[2]--------------
	// not exist value
	printCount(2);
	std_it = std_m.find(100);
	
	map_printIter(std_it, std_m);
}

void	retPrint( size_t std_count)
{
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << (std_count ? "TRUE" : "FALSE");
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;
}

void	count(void)
{
	std::cout << BG_CYAN << "********************count***********************" << COLOR_NOMAL << std::endl;
	std::list<std::pair<int, std::string> > std_lst;


	std_lst.push_back(std::make_pair<int, std::string>(2, "world"));
	std_lst.push_back(std::make_pair<int, std::string>(0, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "hi"));
	std_lst.push_back(std::make_pair<int, std::string>(10, "my"));
	std_lst.push_back(std::make_pair<int, std::string>(23, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(20, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "name"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));

	std::map<int, std::string> std_m;
	std_m.insert(std_lst.begin(), std_lst.end());
	//---------------[0]--------------
	printCount(0);
	map_print(std_m);
	size_t std_count;
	
	std_count = std_m.count(5);
	retPrint( std_count);
	

	std_count = std_m.count(100);
	retPrint( std_count);
}

void	bound(void)
{
	std::cout << BG_CYAN << "********************bound***********************" << COLOR_NOMAL << std::endl;
	std::list<std::pair<int, std::string> > std_lst;


	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));


	std::map<int, std::string> std_m;

	std::map<int, std::string>::iterator std_it;
	std_m.insert(std_lst.begin(), std_lst.end());

	// -------------[0]-------------
	printCount(0);
	map_print(std_m);
	
	// -------------[1]-------------
	std::cout << std::setw(38) << "---------lower----------" << std::endl;
	printCount(1);
	std_it = std_m.lower_bound(-5);
	map_printIter(std_it, std_m);

	// -------------[2]-------------
	printCount(0);
	std_it = std_m.lower_bound(2);
	map_printIter( std_it, std_m);

	// -------------[3]-------------
	printCount(3);
	std_it = std_m.lower_bound(22);
	map_printIter(std_it, std_m);

	// -------------[4]-------------
	printCount(4);

	std_it = std_m.lower_bound(100);
	map_printIter( std_it, std_m);


	// -------------[5]-------------
	std::cout << std::setw(38) << "---------upper----------" << std::endl;
	printCount(5);
	
	std_it = std_m.upper_bound(-5);
	map_printIter( std_it, std_m);

	// -------------[6]-------------
	printCount(6);

	std_it = std_m.upper_bound(2);
	map_printIter(std_it, std_m);

	// -------------[7]-------------
	printCount(7);
	
	std_it = std_m.upper_bound(22);
	map_printIter(std_it,  std_m);

	// -------------[8]-------------
	printCount(8);

	std_it = std_m.upper_bound(30);
	map_printIter( std_it, std_m);
}

static void	map_printIter(  std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> &std_pr,
	 std::map<int, std::string> &std_m)
{

	std::string std_ret;

	std_ret = (std_pr.first != std_m.end() ? std_pr.first->second : "not find");
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << std_ret;
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;


	std_ret = (std_pr.second != std_m.end() ? std_pr.second->second : "not find");
	std::cout << std::setw(8) << "ret2 : ";
	std::cout << std::setw(7) << std_ret;
	std::cout << COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << COLOR_NOMAL;

}

void	equal_range(void)
{
	std::cout << BG_CYAN << "********************equal_range***********************" << COLOR_NOMAL << std::endl;

	std::list<std::pair<int, std::string> > std_lst;

	std::map<int, std::string> std_m;
	
	std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> std_pr;
	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));

	std_m.insert(std_lst.begin(), std_lst.end());

	// -----------[0]------------
	printCount(0);
	map_print(std_m);
	
	// -----------[1]------------
	printCount(1);
	
	std_pr = std_m.equal_range(-1);
	map_printIter(std_pr,std_m);
	
	// -----------[2]------------
	printCount(2);

	std_pr = std_m.equal_range(2);
	map_printIter( std_pr,  std_m);
	
	// -----------[3]------------
	printCount(3);
	
	std_pr = std_m.equal_range(15);
	map_printIter( std_pr, std_m);
	
	// -----------[4]------------
	printCount(4);

	std_pr = std_m.equal_range(30);
	map_printIter( std_pr, std_m);
	
	// -----------[5]------------
	printCount(5);

	std_pr = std_m.equal_range(100);
	map_printIter( std_pr, std_m);
}

void operatorTest( std::map<int, std::string> std_m, std::map<int, std::string> std_m2)
{

	std::vector<std::string> std;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	
	std.push_back((std_m == std_m2 ? "TRUE" : "FALSE"));

	operStr.push_back("!=");
	
	std.push_back((std_m != std_m2 ? "TRUE" : "FALSE"));

	operStr.push_back("<");
	
	std.push_back((std_m < std_m2 ? "TRUE" : "FALSE"));

	operStr.push_back("<=");

	std.push_back((std_m <= std_m2 ? "TRUE" : "FALSE"));

	operStr.push_back(">");

	std.push_back((std_m > std_m2 ? "TRUE" : "FALSE"));

	operStr.push_back(">=");

	std.push_back((std_m >= std_m2 ? "TRUE" : "FALSE"));

	operatePrint(operStr, std);
}

void mapOperator()
{
	std::cout << BG_CYAN << "********************operators***********************" << COLOR_NOMAL << std::endl;

	std::list<std::pair<int, std::string> > std_lst;
	
	std::map<int, std::string> std_m;

	std::map<int, std::string> std_m2;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));

	std_m.insert(std_lst.begin(), std_lst.end());
	
	std_m2.insert(std_lst.begin(), std_lst.end());
	

	// ---------------[0]----------------
	printCount(0);
	map_print(std_m);
	map_print(std_m2);
	operatorTest( std_m, std_m2);

	// ---------------[1]----------------
	printCount(1);

	std_m.erase(++std_m.begin());
	map_print(std_m);
	map_print(std_m2);
	operatorTest( std_m, std_m2);

	// ---------------[2]----------------
	printCount(2);
	
	std_m2.erase(std_m2.begin());
	map_print(std_m);
	map_print(std_m2);
	operatorTest(std_m, std_m2);
}

void operTest(std::map<int,std::string>::iterator std_iter, std::map<int, std::string>::iterator std_iter2)
{
	
	std::vector<std::string> std;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	
	std.push_back((std_iter == std_iter2 ? "true" : "false"));

	operStr.push_back("!=");
	
	std.push_back((std_iter != std_iter2 ? "true" : "false"));

	operatePrint(operStr, std);
}

void r_operTest(std::map<int,std::string>::reverse_iterator std_iter, std::map<int, std::string>::reverse_iterator std_iter2)
{

	std::vector<std::string> std;
	std::vector<std::string> operStr;

	operStr.push_back("==");

	std.push_back((std_iter == std_iter2 ? "true" : "false"));

	operStr.push_back("!=");

	std.push_back((std_iter != std_iter2 ? "true" : "false"));

	operatePrint(operStr, std);
}

void	map_iterOper(void)
{
	std::cout << BG_CYAN << "********************iterator***********************" << COLOR_NOMAL << std::endl;

	std::list<std::pair<int, std::string> > std_lst;
	std::map<int, std::string> std_m;

	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(30, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "this"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(2, "hi"));

	std_m.insert(std_lst.begin(), std_lst.end());

	// ------------------[0]-----------------
	printCount(0);
	operTest( std_m.begin(), std_m.begin());

	// ------------------[1]-----------------
	printCount(1);
	operTest(std_m.end(), std_m.end());

	// ------------------[2]-----------------
	printCount(2);
	r_operTest( std_m.rbegin(), std_m.rbegin());

	// ------------------[3]-----------------
	printCount(3);
	r_operTest( std_m.rend(), std_m.rend());
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
