#ifndef VECTOR_HPP
# define VECTOR_HPP
#include<vector>
# include <memory>
# include <stdexcept>
# include "random_access_iterator.hpp"
# include "nullptr.hpp"
# include "type_traits.hpp"

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T												value_type;
		typedef Alloc											allocator_type;
		typedef ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef allocator_type::size_type						size_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef ft::random_access_iterator<value_type>			iterator;
		typedef ft::random_access_iterator<const value_type>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;


	private:
		pointer _begin;
		pointer _end;
		pointer _end_cap;
		allocator_type _alloc;

	public:
		/* Constructor */
		explicit vector(const alloacator_type& alloc = alloacator_type())
			: _begin(ft_nullptr), _end(ft_nullptr), _end_cap(ft_nullptr), _alloc(alloc) {}
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = alloacator_type())
			: _begin(ft_nullptr), _end(ft_nullptr), _end_cap(ft_nullptr), _alloc(alloc)
			{
				if (n > 0)
				{
					vec_allocate(n);
					for (size_type i = 0; i < n; i++, _end++)
						_alloc.construct(this->_end, val);
				}
			}
		//?????????
		template <typename InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename enable_if<!is_integral<InputIterator>::value>::type* = ft_nullptr)
			: _begin(ft_nullptr), _end(ft_nullptr), _end_cap(ft_nullptr), _alloc(alloc)
			{
				if (n > 0)
				{
					vec_allocate(n);
					for (size_type i = 0; i < n; i++, _end++)
						_alloc.construct(this->_end, val);
				}
			}
		
		vector (const vector& x)
		: _begin(ft_nullptr), _end(ft_nullptr), _end_cap(ft_nullptr), _alloc(x.alloc)
		{
			size_type n = x.size();
			if (n > 0)
			{
				vec_allocate(n);
				for (const_iterator it = x.begin(); it != x.end(); it++, _end++)
					_alloc.construct(this->_end, *it);
			}
		}


		/* Destructor */
		virtual ~vector(void)
		{
			this->clear();
			_alloc.deallocate(this->_begin, this->capacity());
		}

		/* Assignment*/
		vector& operator=(const vectpr& x)
		{
			if (this != &x)
			{
				this->assign(x.begin(), x.end());
			}
			return (*this);
		}

		/* Iterators */
		iterator begin(void) { return (iterator(this->_begin)); }

		const_iterator begin(void) const { return (const_iterator(this->_begin)); }

		iterator end(void) { return (iterator(this->_end)); }

		const_iterator end(void) const { return (const_iterator(this->_end)); }
	
		reverse_iterator rbegin(void) { return (reverse_iterator(iterator(this->_end))); }

		const reverse_iterator rbegin(void) { return (reverse_iterator(iterator(this->_end()))); }

		reverse_iterator rend() { return (reverse_iterator(this->begin())); }

		const_reverse_iterator rend() const { return (const_reverse_iterator(this->begin())); }

		/* Capacity */
		size_type size(void) const { return (static_cast<size_type>(this->_end - this->_begin)); }
		size_type max_size(void) const { return (alloc.max_size()); }
		void resize(size_type n, value_type val = value_type())
		{
			if (n > this->max_size())
				throw std::length_error("vector");

			size_type s = this->size();
			if (s < n)
			{
				size_type j = n - s;
				if (static_cast<size_type>(this->_end_cap - this->_end) >= j)
				{
					for (size_type i = 0; i < j; i++, _end++)
						_alloc.construct(this->_end, val);
				}
				else
				{
					size_type temp_cap;
					if (this->capacity() == 0)
						temp_cap = 1;
					else if (this->capacity() * 2 > this->max_size())
						temp_cap = this->max_size();
					else
						temp_cap = this->capacity() * 2;
					size_type j = n - this->size();
					size_type new_cap = n > temp_cap ? n : temp_cap;
					this->reserve(new_cap);
					for (size_type i = 0; i < j; i++, _end++)
						_alloc.construct(this->_end, val);
				}
			}
			else if (s > n)
			{
				size_type j = s - n;
				for (size_type i = 0; i < j ; i++) 
					--_end; _alloc.destroy(this->_end);
			}
		}

		size_type capacity(void) const { return (static_cast<size_type>(this->_end_cap - this->_begin)); }

		bool empty(void) const ( return (this->size() == 0); )
	
		//??????
		void reserve (size_type n)
		{
			if (n > this->capacity())
			{

				if (static_cast<size_type>(n) > this->max_size())
					throw std::length_error("vector");

				pointer new_begin, new_end;
				new_begin = new_end = _alloc.allocate(n);
				for (iterator it = this->begin(); it != this->end(); it++, new_end++) {
					_alloc.construct(new_end, *it);
				}

				this->clear();
				_alloc.deallocate(this->_begin, this->capacity());
				
				this->_begin = new_begin;
				this->_end = new_end;
				this->_end_cap = new_begin + n;
			}
		}

		void vec_allocate(size_type n)
		{
			if (n > this->max_size())
				throw std::length_error("vector");
			this->_begin = this->_end = _alloc.allocate(n);
			this->_end_cap = this->_begin + n;
		}

		/* Element access */
		reference operator[] (size_type n)
		{
			if (n >= size())
				throw std::out_of_range("vector");
			return (*(this->_begin + n));
		}

		const_reference operator[] (size_type n) const
		{
			if (n >= size())
				throw std::out_of_range("vector");
			return (*(this->_begin + n));
		}

		reference at(size_type n)
		{
			if (n >= size())
				throw std::out_of_range("vector");
			return (*(this->_begin + n))
		}

		const_reference at(size_type n) const
		{
			if (n >= size())
				throw std::out_of_range("vector");
			return (*(this->_begin + n))
		}

		reference front(void) { return (*(this->_begin)); }

		const_reference front(void) const { return (*(this->_begin)); }

		reference back(void) { return (*(this->_end - 1)); }

		const_reference back(void) const { return (*(this->_end - 1)); }

		/* Modifiers */
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
			typename enable_if<!is_integral<InputIterator>::value>::type* = ft_nullptr)
		{
			//!!!!!!!!
			if (static_cast<size_type>(n) > this->max_size())
				throw std::length_error("vector");
			this->clear();
			size_type new_cap = distance(first, last);
			if (new_cap > this->capacity())
			{
				_alloc.deallocate(_begin, this->capacity());
				vec_allocate(new_cap);
			}
			for (InputIterator it = first; it != last; it++, _end++)
				_alloc.construct(this->_end, *it);
		}

		void assign(size_type n, const value_type& val)
		{
			if (static_cast<size_type>(n) > this->max_size())
				throw std::length_error("vector");
			if (n > this->capacity())
			{
				_alloc.deallocate(_begin, this->capacity());
				vallocate_(n);
			}
			for (size_type i = 0; i < n; i++, _end++)
				_alloc.construct(this->_end, val);
		}

		void push_back(const value_type& val)
		{
			if (this->_end == this->_end_cap)
			{
				if (this->size() == this->max_size())
					throw std::length_error("vector");
				size_type new_cap;
				if (this->capacity() == 0)
					new_cap = 1;
				else if (this->capacity() * 2 > this->max_size())
					new_cap = this->max_size();
				else
					new_cap = this->capacity() * 2;
				this->reserve(new_cap);
			}
			_alloc.construct(this->_end, val);
			_end++; //??? check
		}

		void pop_back()
		{
			if (this->_begin() != this->_end)
			{
				--_end;
				_alloc.destroy(this->_end);
			}
		}

		
	};

	
} // namespace ft

#endif