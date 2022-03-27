#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <typename T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T	value_type;
		typedef Container	container_type;
		typedef std::size_t	size_type;
	
	protected:
		container_type _c;
	
	public:
		/* Constructors */
		explicit stack (const container_type& ctnr = container_type()) : _c(ctnr) {}

		/* Destructors */
		virtual ~stack(void) {}

		/* Member functions */
		bool empty(void) const { return this->_c.empty(); }

		size_type size(void) const { return this->_c.size(); }

		value_type& top(void) { return this->_c.back(); }

		const value_type& top(void) const { return this->_c.back(); }

		void push (const value_type& val) { this->_c.push_back(val); }

		void pop(void) { this->_c.pop_back(); }

		template <typename _T, typename _Container> friend bool operator==(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
		template <typename _T, typename _Container> friend bool operator<(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
	};
		
	/* Relational Operators */
	template <typename T, typename Container>
	bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs._c == rhs._c;
	}

	template <typename T, typename Container>
	bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T, typename Container>
	bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs._c < rhs._c;
	}

	template <typename T, typename Container>
	bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return !(rhs < lhs);
	}

	template <typename T, typename Container>
	bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return rhs < lhs;
	}

	template <typename T, typename Container>
	bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return !(lhs < rhs);
	}
}
#endif