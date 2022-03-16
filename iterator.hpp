#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>

namespace ft
{
	/* Iterator_Category를 이루는 tag들 (각 반복자 종류를 구분하기 위함) */

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};


	/* Iterator (타입 정보만 갖고 있음)*/
	/* 반복자는 아래 자신만의 5가지 정보를 가짐 */

	template <typename Category,
						typename T,
						typename Distance = std::ptrdiff_t,
						typename Pointer = T*,
						typename Reference = T&>
	
	struct iterator
	{
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};


	/* Iterator Traits (반복자 형식을 확인하기 위한 특징 정보 클래스)*/

	template <typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	template <typename T>
	struct iterator_traits<T*>
	{
		typedef typename random_access_iterator_tag		iterator_category;
		typedef typename T								value_type;
		typedef typename std::ptrdiff_t					difference_type;
		typedef typename T*								pointer;
		typedef typename T&								reference;
	};

	template <typename T>
	struct iterator_traits<const T*>
	{
		typedef typename random_access_iterator_tag		iterator_category;
		typedef typename T								value_type;
		typedef typename std::ptrdiff_t					difference_type;
		typedef typename T*								pointer;
		typedef typename T&								reference;
	};

	/*####################*/
	/*# Reverse Iterator #*/
	/*####################*/

	template <typename Iterator>
	class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
											typename iterator_traits<Iterator>::value_type,
											typename iterator_traits<Iterator>::difference_type,
											typename iterator_traits<Iterator>::pointer,
											typename iterator_traits<Iterator>::reference>
	{
	public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

	protected:
			iterator_type	_current;

	public:
			/* Constructor */
			reverse_iterator() : _current() {}
			explicit reverse_iterator(iterator_type it) : _current(it) {}
			//check
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it) : _current(rev_it.base()) { }

			/* Assignment Operator */
			template <class Iter>
			reverse_iterator	&operator=(const reverse_iterator<Iter>& rhs)
			{
				this->_current = rhs._current;
				return (*this);
			}

			/* Destrcutor */
			~reverse_iterator() {}

			/* Member function */
			iterator_type base() const { return (this->_current); }

			/* Member function Operators 정방향 반복자는 가리키는 원소의 value를 참조하지만 역방향 반복자는 가리키는 다음 원소의 value를 참조한다*/ 
			reference operator*() const { Iterator temp = _current; return (*--temp); }
			pointer operator->() const { return (&(operator*())); }
			reverse_iterator& operator++() { --_current; return (*this); }
			reverse_iterator operator++(int) { reverse_iterator temp(*this); ++(*this); return (temp); } // 윗줄에서 만들어놓은 ++이 호출되어 연산되므로 ++ 해준다!
			reverse_iterator operator--() { ++_current; return (*this); }
			reverse_iterator operator--(int) { reverse_iterator temp(*this); --(*this); return(temp); }
			reverse_iterator operator+(difference_type n) const { return (reverse_iterator(_current - n)); }
			reverse_iterator operator+=(difference_type n) { _current -= n; return (*this); }
			reverse_iterator operator-(difference_type n) const { return (reverse_iterator(_current + n)); }
			reverse_iterator operator-=(difference_type n) { _current += n; return (*this); }
			reference operator[](difference_type n) const { return (*this + n); }
			
	};


	/*Relational operators*/
	template <typename Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (lhs.base() == rhs.base()); }

	template <typename Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (lhs.base() != rhs.base()); }

	template <typename Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return !(lhs.base() < rhs.base()); }

	template <typename Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return !(lhs.base() <= rhs.base()); }

	template <typename Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return !(lhs.base() > rhs.base()); }
	
	template <typename Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return !(lhs.base() >= rhs.base()); }

	template <typename Iterator>
	// (ex) ft::reverse_iterator temp; temp + 2;와 같이 이터레이터 뒤에 +연산 나오는 경우 기존의 클래스안의 멤버함수 +연산 오버로딩
	//이 호출되지만! temp = 2 + temp; 와 같이 숫자 먼저 나오고 + 이터레이터 인 경우를 위해 필요.
	//매개변수 보면 difference_type 먼저 받고 이터레이터 들어온다. 그러면 기존의 멤버함수 오버로딩+가 다시 호출되어 연산.
	reverse_iterator<Iterator> operator+(
			typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{ return reverse_iterator<Iterator>(rev_it.base() + n); }

	template <typename Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
			const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return rhs.base() - lhs.base(); }

	/*###################*/
	/*# Vector Iterator #*/
	/*###################*/

	template <typename Iterator>
	class vector_iterator
	{
	public:
		typedef Iterator													iterator_type;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type			value_type;
		typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename iterator_traits<iterator_type>::pointer			pointer;
		typedef typename iterator_traits<iterator_type>::reference			reference;
	
	protected:
		iterator_type _i;
	
	public:
		/* Constructor */
		vector_iterator() : _i() {}
		vector_iterator(const vector_iterator& vec_it) : _i(vec_it.base()) {}
		vector_iterator(iterator_type it) : _i(it) {}
		template <class Iter>vector_iterator(const vector_iterator<Iter>& vec_iter) : _i(vec_iter.base()) {}
	
		/* Assignment Operator */
		vector_iterator& operator=(const vector_iterator& vec_rhs)
		{
			this->_current = vec_rhs._current;
			return (*this);
		}

		/* Destrcutor */
		~vector_iterator() {}

		/* Member function */
		iterator_type base() const { return (_i); }

		/* Member function Operators */
		reference operator*() const { return (*_i); }
		pointer operator->() const { return &(this->operator*()); }
		vector_iterator& operator++() { ++_i; return (*this); }
		vector_iterator operator++(int) { vector_iterator temp(*this); ++(*this); return (temp); }
		vector_iterator& operator--() { --_i; return (*this); }
		vector_iterator operator--(int) { vector_iterator temp(*this); --(*this); return (temp); }
		vector_iterator operator+(difference_type n) const { return (vector_iterator((this->_i) + n); }
		vector_iterator operator+=(difference_type n) { _i += n; return (*this); }
		vector_iterator operator-(difference_type n) { return (vector_iterator((this->_i) - n); }
		vector_iterator operator-=(difference_type n) { *this += -n; return (*this); }
		reference operator[](difference_type n) const { return (i[n]); }
	};

	/*random은 vector안에서 iterator 위치끼리 같은지 비교, + - 연산은 reverse처럼 data + iterator 인 경우를 위해*/
	/*Relational operators*/
	template <typename Iter1, typename Iter2>
	bool operator==(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
	{ return (lhs.base() == rhs.base()); }

	template <typename Iter1, typename Iter2>
	bool operator!=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
	{ return (lhs.base() != rhs.base()); }

	template <typename Iter1, typename Iter2>
	bool operator<(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
	{ return !(lhs.base() < rhs.base()); }

	template <typename Iter1, typename Iter2>
	bool operator<=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
	{ return !(lhs.base() <= rhs.base()); }

	template <typename Iter1, typename Iter2>
	bool operator>(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
	{ return !(lhs.base() > rhs.base()); }
	
	template <typename Iter1, typename Iter2>
	bool operator>=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
	{ return !(lhs.base() >= rhs.base()); }

	template <typename Iter>
	// vector_iterator(random_access)는 vec안에 iter위치끼리 비교!
	vector_iterator<Iter> operator+(
			typename vector_iterator<Iter>::difference_type n, const vector_iterator<Iter>& v_it)
	{ return (v_it + n); }

	template <typename Iter1, typename Iter2>
	typename vector_iterator<Iter1>::difference_type operator- (
			const vector_iterator<Iter1>& lhs, const vector_iterator<Iter2>& rhs)
	{ return lhs.base() - rhs.base(); }

}

#endif