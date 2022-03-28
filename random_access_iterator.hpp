#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator.hpp"
# include "nullptr.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
	public:
		typedef typename iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;
		typedef typename iterator<random_access_iterator_tag, T>::value_type		value_type;
		typedef typename iterator<random_access_iterator_tag, T>::difference_type	difference_type;
		typedef typename iterator<random_access_iterator_tag, T>::pointer			pointer;
		typedef typename iterator<random_access_iterator_tag, T>::reference			reference;
	
	protected:
		pointer _i;
	
	public:
		/* Constructor */
		random_access_iterator() : _i(ft_nullptr) {}

		random_access_iterator(pointer ptr) : _i(ptr) {}
	
		random_access_iterator(const random_access_iterator<T>& vec_rhs) : _i(vec_rhs._i) {}
	
		/* Assignment Operator */
		random_access_iterator& operator=(const random_access_iterator& vec_rhs)
		{
			if (this != &vec_rhs)
				this->_i = vec_rhs._i;
			return (*this);
		}

		/* Conversion operator */
		operator random_access_iterator<const value_type> () const { return (random_access_iterator<const value_type>(this->_i));}
		
		/* Destrcutor */
		virtual ~random_access_iterator(void) {}

		/* Member function */
		pointer base(void) const { return (_i); }

		/* Member function Operators */
		reference operator*() const { return (*_i); }
	
		pointer operator->() const { return &(this->operator*()); }
	
		random_access_iterator operator+(difference_type n) const { return (random_access_iterator(this->_i + n)); }
	
		random_access_iterator& operator++(void) { ++_i; return (*this); }
	
		random_access_iterator operator++(int) { random_access_iterator temp(*this); ++_i; return (temp); }
	
		random_access_iterator operator-(difference_type n) const { return (random_access_iterator(this->_i - n)); }
	
		random_access_iterator& operator--(void) { --_i; return (*this); }
	
		random_access_iterator operator--(int) { random_access_iterator temp(*this); --_i; return (temp); }
	
		random_access_iterator& operator+=(difference_type n) { this->_i += n; return (*this); }
	
		random_access_iterator& operator-=(difference_type n) { this->_i -= n; return (*this); }
	
		reference operator[](difference_type n) const { return (_i[n]); }
	};

	/*random은 vector안에서 iterator 위치끼리 같은지 비교, + - 연산은 reverse처럼 data + iterator 인 경우를 위해*/
	/*Relational operators*/
	template <typename Iter1, typename Iter2>
	bool operator==(const random_access_iterator<Iter1>& lhs, const random_access_iterator<Iter2>& rhs)
	{ return (lhs.base() == rhs.base()); }

	template <typename Iter1, typename Iter2>
	bool operator!=(const random_access_iterator<Iter1>& lhs, const random_access_iterator<Iter2>& rhs)
	{ return (lhs.base() != rhs.base()); }

	template <typename Iter1, typename Iter2>
	bool operator<(const random_access_iterator<Iter1>& lhs, const random_access_iterator<Iter2>& rhs)
	{ return !(lhs.base() < rhs.base()); }

	template <typename Iter1, typename Iter2>
	bool operator<=(const random_access_iterator<Iter1>& lhs, const random_access_iterator<Iter2>& rhs)
	{ return !(lhs.base() <= rhs.base()); }

	template <typename Iter1, typename Iter2>
	bool operator>(const random_access_iterator<Iter1>& lhs, const random_access_iterator<Iter2>& rhs)
	{ return !(lhs.base() > rhs.base()); }
	
	template <typename Iter1, typename Iter2>
	bool operator>=(const random_access_iterator<Iter1>& lhs, const random_access_iterator<Iter2>& rhs)
	{ return !(lhs.base() >= rhs.base()); }

	template <typename Iter>
	// random_access_iterator(random_access)는 vec안에 iter위치끼리 비교!
	random_access_iterator<Iter> operator+(
			typename random_access_iterator<Iter>::difference_type n, const random_access_iterator<Iter>& iter)
	{ return (iter + n); }

	template <typename Iter1, typename Iter2>
	typename random_access_iterator<Iter1>::difference_type operator-(
			const random_access_iterator<Iter1>& lhs, const random_access_iterator<Iter2>& rhs)
	{ return lhs.base() - rhs.base(); }

//한쪽은 const형 iter 한쪽은 그냥 iter알때 를 위해서 iter1, iter2 나눔! 
//+는 숫자와 iter 더할 수 있지만 -는 iter끼리만 가능하므로!

}

#endif