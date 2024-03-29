#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include "random_access_iterator.hpp"
# include "nullptr.hpp"
# include "type_traits.hpp"
# include "utils.hpp"

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T															value_type;
		typedef Alloc														allocator_type;
		typedef typename allocator_type::size_type							size_type;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;
		typedef ft::random_access_iterator<value_type>						iterator;
		typedef ft::random_access_iterator<const value_type>				const_iterator;
		typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;

	private:
		pointer _begin;
		pointer _end;
		pointer _end_cap;
		allocator_type _alloc;

	public:
		/* Constructor */
		explicit vector(const allocator_type& alloc = allocator_type())
			: _begin(ft_nullptr), _end(ft_nullptr), _end_cap(ft_nullptr), _alloc(alloc) {}
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _begin(ft_nullptr), _end(ft_nullptr), _end_cap(ft_nullptr), _alloc(alloc)
			{
				if (n > 0)
				{
					vec_allocate(n);
					for (size_type i = 0; i < n; i++, _end++)
						_alloc.construct(this->_end, val);
				}
			}

		template <typename InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!is_integral<InputIterator>::value>::type* = ft_nullptr)
			: _begin(ft_nullptr), _end(ft_nullptr), _end_cap(ft_nullptr), _alloc(alloc)
			{
				difference_type n = last - first;
				if (n > 0)
				{
					vec_allocate(n);
					for (InputIterator i = first; i != last; i++, _end++)
						_alloc.construct(this->_end, *i);
				}
			}
		
		vector (const vector& x)
		: _begin(ft_nullptr), _end(ft_nullptr), _end_cap(ft_nullptr), _alloc(x._alloc)
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
		vector& operator=(const vector& x)
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

		const reverse_iterator rbegin(void) const { return (reverse_iterator(iterator(this->_end()))); }

		reverse_iterator rend() { return (reverse_iterator(this->begin())); }

		const_reverse_iterator rend() const { return (const_reverse_iterator(this->begin())); }

		/* Capacity */
		size_type size(void) const { return (static_cast<size_type>(this->_end - this->_begin)); }

		size_type max_size(void) const { return (_alloc.max_size()); }

		void resize(size_type n, value_type val = value_type())
		{
			if (n > this->max_size())
				throw std::length_error("vector");

			size_type s = this->size();
			if (s < n)
			{
				size_type diff = n - s;
				if (static_cast<size_type>(this->_end_cap - this->_end) >= diff)
				{
					for (size_type i = 0; i < diff; i++, _end++)
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
					size_type diff = n - this->size();
					size_type new_cap = n > temp_cap ? n : temp_cap;
					this->reserve(new_cap);
					for (size_type i = 0; i < diff; i++, _end++)
						_alloc.construct(this->_end, val);
				}
			}
			else if (s > n)
			{
				size_type diff = s - n;
				for (size_type i = 0; i < diff ; i++) 
					--_end; _alloc.destroy(this->_end);
			}
		}

		size_type capacity(void) const { return (static_cast<size_type>(this->_end_cap - this->_begin)); }

		bool empty(void) const { return (this->size() == 0); }
	
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
			return (*(this->_begin + n));
		}

		const_reference at(size_type n) const
		{
			if (n >= size())
				throw std::out_of_range("vector");
			return (*(this->_begin + n));
		}

		reference front(void) { return (*(this->_begin)); }

		const_reference front(void) const { return (*(this->_begin)); }

		reference back(void) { return (*(this->_end - 1)); }

		const_reference back(void) const { return (*(this->_end - 1)); }

		/* Modifiers */
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
			typename ft::enable_if<!is_integral<InputIterator>::value>::type* = ft_nullptr)
		{
			this->clear();
			difference_type new_cap = last - first;
			if (static_cast<size_type>(new_cap) > this->capacity())
			{
				_alloc.deallocate(_begin, this->capacity());
				vec_allocate(new_cap);
			}
			for (InputIterator it = first; it != last; it++, _end++)
				_alloc.construct(this->_end, *it);
		}

		void assign(size_type n, const value_type& val)
		{
			if (n > this->capacity())
			{
				_alloc.deallocate(_begin, this->capacity());
				vec_allocate(n);
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
			_end++;
		}

		void pop_back()
		{
			_alloc.destroy(--_end);
		}

		iterator insert(iterator position, const value_type& val)
		{
			pointer pos = this->_begin + (position - this->begin());
			if (this->_end < this->_end_cap)
			{
				for (pointer p = this->_end; p != pos; p--)
				{
					_alloc.construct(p, *(p - 1));
					_alloc.destroy(p - 1);
				}
				_alloc.construct(pos, val); _end++;
			}
			else
			{
				size_type new_cap;
				if (this->capacity() == 0) { new_cap = 1; }
				else if (this->capacity() * 2 > this->max_size()) { new_cap = this->max_size(); }
				else { new_cap = this->capacity() * 2; }

				pointer new_begin, new_end;
				new_begin = new_end = _alloc.allocate(new_cap);
				for (pointer p = this->_begin; p != pos; p++, new_end++) {
					_alloc.construct(new_end, *p);
				}
				_alloc.construct(new_end, val); new_end++;
				for (pointer p = pos; p != this->_end; p++, new_end++) {
					_alloc.construct(new_end, *p);
				}

				this->clear();
				_alloc.deallocate(this->_begin, this->capacity());
				
				this->_begin = new_begin;
				this->_end = new_end;
				this->_end_cap = new_begin + new_cap;
			}
			return iterator(pos);
 		 }

		void insert (iterator position, size_type n, const value_type& val)
		{
			if (n > 0)
			{
				if (this->size() + static_cast<size_type>(n) > this->max_size())
					throw std::length_error("vector");
				
				pointer pos = this->_begin + (position - this->begin());
				if (this->_end + n < this->_end_cap)
				{
					for (pointer p = this->_end - 1 + n; p - n + 1 != pos; p--)
					{
						_alloc.construct(p, *(p - n));
						_alloc.destroy(p - n);
					}
					for (size_type s = 0; s < n; s++)
					{
						_alloc.construct(pos + s, val);
						_end++;
					}
				}
				else
				{
					size_type temp_cap;
					if (this->capacity() == 0) { temp_cap = 1; }
					else if (this->capacity() * 2 > this->max_size()) { temp_cap = this->max_size(); }
					else { temp_cap = this->capacity() * 2; }
					size_type new_cap = this->size() + n > temp_cap ? this->size() + n : temp_cap;

					pointer new_begin, new_end;
					new_begin = new_end = _alloc.allocate(new_cap);

					for (pointer p = this->_begin; p != pos; p++, new_end++)
					{
						_alloc.construct(new_end, *p);
					}
					for (size_type s = 0; s < n; s++, new_end++)
					{
						_alloc.construct(new_end, val);
					}
					for (pointer p = pos; p != this->_end; p++, new_end++)
					{
						_alloc.construct(new_end, *p);
					}

					this->clear();
					_alloc.deallocate(this->_begin, this->capacity());
					
					this->_begin = new_begin;
					this->_end = new_end;
					this->_end_cap = new_begin + new_cap;
				}
			}
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!is_integral<InputIterator>::value>::type* = nullptr)
		{
			difference_type n = last - first;
			if (n > 0)
			{
				if (this->size() + static_cast<size_type>(n) > this->max_size())
					throw std::length_error("vector");
				
				pointer pos = this->_begin + (position - this->begin());
				if (this->_end + n < this->_end_cap)
				{
					for (pointer p = this->_end - 1 + n; p - n + 1 != pos; p--)
					{
						_alloc.construct(p, *(p - n));
						_alloc.destroy(p - n);
					}
					for (InputIterator it = first; it != last; it++, pos++)
					{
						_alloc.construct(pos, *it); _end++;
					}
				}
				else
				{
					size_type temp_cap;
					if (this->capacity() == 0) { temp_cap = 1; }
					else if (this->capacity() * 2 > this->max_size()) { temp_cap = this->max_size(); }
					else { temp_cap = this->capacity() * 2; }
					size_type new_cap = this->size() + n > temp_cap ? this->size() + n : temp_cap;

					pointer new_begin, new_end;
					new_begin = new_end = _alloc.allocate(new_cap);

					for (pointer p = this->_begin; p != pos; p++, new_end++)
					{
						_alloc.construct(new_end, *p);
					}
					for (InputIterator it = first; it != last; it++, new_end++)
					{
						_alloc.construct(new_end, *it);
					}
					for (pointer p = pos; p != this->_end; p++, new_end++)
					{
						_alloc.construct(new_end, *p);
					}

					this->clear();
					_alloc.deallocate(this->_begin, this->capacity());
					
					this->_begin = new_begin;
					this->_end = new_end;
					this->_end_cap = new_begin + new_cap;
				}
			}
		}

		iterator erase (iterator position) {
			pointer pos = &(*position);
			for (pointer p = pos; p + 1 != this->_end; p++)
			{
				_alloc.destroy(p);
				_alloc.construct(p, *(p + 1));
			}
			--_end;
			_alloc.destroy(this->_end);
			return (iterator(pos));
		}

		iterator erase (iterator first, iterator last)
		{
			pointer p_first = &(*first);
			pointer p_last = &(*last);
			difference_type diff = p_last - p_first;

			for (pointer p = p_first; p + diff != this->_end; p++)
			{
				_alloc.destroy(p);
				_alloc.construct(p, *(p + diff));
			}
			for (size_type s = 0; s < static_cast<size_type>(diff); s++)
			{
				--_end;
				_alloc.destroy(this->_end);
			}
			return (iterator(p_first));
		}

		void swap (vector& x)
		{
			if (this == &x)
				return;
			
			pointer temp_begin = x._begin;
			pointer temp_end = x._end;
			pointer temp_end_cap = x._end_cap;
			allocator_type &temp_alloc = x._alloc;

			x._begin = this->_begin;
			x._end = this->_end;
			x._end_cap = this->_end_cap;
			x._alloc = this->_alloc;
			this->_begin = temp_begin;
			this->_end = temp_end;
			this->_end_cap = temp_end_cap;
			this->_alloc = temp_alloc;
		}

		void clear(void)
		{
			size_type n = this->size();
			for (size_type i = 0; i < n; i++)
			{
				--_end;
				_alloc.destroy(this->_end);
			}
		}
	};

	/* Relational Operators */
	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (!(lhs == rhs)); }

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (rhs < lhs); }

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (!(lhs < rhs)); }

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (!(rhs < lhs)); }

	/* Swap */
	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }
	
} // namespace ft

#endif