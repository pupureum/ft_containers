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
	
	private:
		iterator_type _current;
	
	public:
		/* Constructor */
		vector_iterator() : _current() {}
		vector_iterator(const vector_iterator& vec_it) : _current(vec_it.base()) {}
		vector_iterator(iterator_type it) : _current(it) {}
		template <class Iter>vector_iterator(const vector_iterator<Iter>& vec_iter) : _current(vec_iter.base()) {}
	
		/* Assignment Operator */
		vector_iterator& operator=(const vector_iterator& vec_rhs)
		{
			this->_base = vec_rhs._base;
			return (*this);
		}

		/* Destrcutor */
		~vector_iterator() {}

		/* Member function */
		iterator_type base() const { return (_current); }

		/* Member function Operators */
		reference operator*() const { return (*_current); }
		pointer operator->() const { return &(this->operator*()); }
		vector_iterator& operator++() { ++_current; return (*this); }
		vector_iterator operator++(int) { vector_iterator temp(*this); ++(*this); return (temp); }
		vector_iterator& operator--() { --_current; return (*this); }
		vector_iterator operator--(int) { vector_iterator temp(*this); --(*this); return (temp); }
		vector_iterator operator+(difference_type n) const { vector_iterator temp(*this); temp += n; return (temp); }
		vector_iterator operator+=(difference_type n) { _current += n; return (*this); }
		vector_iterator operator-(difference_type n) { vector_iterator temp(*this); temp -= n; return (*this); }
		vector_iterator operator-=(difference_type n) { *this += -n; return (*this); }

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
			iterator_type	_base;

	public:
			/* Constructor */
			reverse_iterator() : _base() {}
			explicit reverse_iterator(iterator_type it) : _base(it) {}
			//check
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it) : _base(rev_it.base()) { }

			/* Assignment Operator */
			template <class Iter>
			reverse_iterator	&operator=(const reverse_iterator<Iter>& rhs)
			{
				this->_base = rhs._base;
				return (*this);
			}

			/* Destrcutor */
			~reverse_iterator() {}

			/* Member function */
			iterator_type base() const { return (this->_base); }

			/* Member function Operators 정방향 반복자는 가리키는 원소의 value를 참조하지만 역방향 반복자는 가리키는 다음 원소의 value를 참조한다*/ 
			reference operator*() const { Iterator temp = _base; return (*--temp); }
			pointer operator->() const { return (&(operator*())); }
			reverse_iterator& operator++() { --_base; return (*this); }
			reverse_iterator operator++(int) { reverse_iterator temp(*this); ++(*this); return (temp); }
	};


}

#endif