#ifndef MAP_HPP
# define MAP_HPP

# include "utils.hpp"
# include "rb_tree.hpp"

namespace ft
{
	template <typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<pair<const Key, T> > >
	class map
	{
	public:
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef pair<const key_type, mapped_type>	value_type;
		typedef Compare								key_compare;
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
		private:
			Compare comp;
		public:
			value_compare(Compare c): comp(c){}
			bool operator()(const value_type& x, const value_type& y) const { return (comp(x.first, y.first)); }
		};
		typedef Alloc																				allocator_type;
		typedef typename allocator_type::reference													reference;
		typedef typename allocator_type::const_reference											const_reference;
		typedef typename allocator_type::pointer													pointer;
		typedef typename allocator_type::const_pointer												const_pointer;
		typedef rb_tree<key_type, value_type, Select1st<value_type>, key_compare, allocator_type>	tree;
		typedef typename tree::iterator																iterator;
		typedef typename tree::const_iterator														const_iterator;
		typedef typename tree::reverse_iterator														reverse_iterator;
		typedef typename tree::const_reverse_iterator												const_reverse_iterator;
		typedef typename tree::difference_type														difference_type;
		typedef typename tree::size_type															size_type;

	private:
		tree _container;
		key_compare _comp;
		allocator_type _alloc;

	public:
		/* Constructor */
		map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _container(tree()), _comp(comp), _alloc(alloc) {}
		
		template <typename Iter>
		map(typename ft::enable_if<!ft::is_same<typename Iter::iterator_category, void>::value, Iter>::type first,
				Iter last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _container(tree()), _comp(comp), _alloc(alloc)
		{
			for (Iter cur = first; cur != last; ++cur)
				insert(*cur);
		}

		map(const map& x): _container(x._container), _comp(x._comp), _alloc(x._alloc) {}

		/* Assignment*/
		map& operator=(const map& x)
		{
			_container = x._container;
			_comp = x._comp;
			_alloc = x._alloc;
			return (*this);
		}
		
		/* Destructor */
		virtual ~map(void) { _container.clear(); }

		/* Iterators */
		iterator begin(void) { return (_container.begin()); }

		const_iterator begin(void) const { return (_container.begin()); }

		iterator end(void) { return (_container.end()); }

		const_iterator end(void) const { return (_container.end()); }

		reverse_iterator rbegin(void) { return (_container.rbegin()); }

		const_reverse_iterator rbegin(void) const { return (_container.rbegin()); }

		reverse_iterator rend(void) { return (_container.rend()); }

		const_reverse_iterator rend(void) const { return (_container.rend()); }

		/* Capacity */
		bool empty(void) const { return (_container.size() == 0); }

		size_type size(void) const { return (_container.size()); }

		size_type max_size(void) const { return (_container.max_size()); }

		/* Element access */
		mapped_type& operator[](const key_type& k) { return ((_container.insert(ft::make_pair(k, mapped_type()))).first)->second; }

		/* Modifiers */
		pair<iterator, bool> insert(const value_type& val) { return (_container.insert(val)); }

		iterator insert(iterator position, const value_type& val) { (void)position; return (insert(val).first); }

		template <class Iter>
		void insert(typename ft::enable_if<!ft::is_same<typename Iter::iterator_category, void>::value, Iter>::type first, Iter last)
		{
			for (; first != last; ++first)
				insert(*first);
		}

		void erase(iterator position) { _container.erase(position); }

		void erase(const_iterator position) { _container.erase(position); }

		size_type erase(const key_type& k) { return (_container.erase(k)); }

		void erase(iterator first, iterator last) { _container.erase(first, last); }

		void swap(map& x)
		{
			_container.swap(x._container);
			key_compare keyTemp = this->_comp;
			allocator_type allocTemp = this->_alloc;
			x._comp = keyTemp;
			x._alloc = allocTemp;
		}

		void clear(void) { _container.clear(); }

		/* Observers */
		key_compare key_comp(void) const { return (_comp); }

		value_compare value_comp(void) const { return (value_compare(_comp)); }

		/* Operations */
		iterator find(const key_type& k) { return (_container.find(k)); }

		const_iterator find(const key_type& k) const { return (_container.find(k)); }

		size_type count(const key_type& k) const { return (_container.count(k)); }

		iterator lower_bound(const key_type& k) { return (_container.lower_bound(k)); }

		const_iterator lower_bound(const key_type& k) const { return (_container.lower_bound(k)); }

		iterator upper_bound(const key_type& k) { return (_container.upper_bound(k)); }

		const_iterator upper_bound(const key_type& k) const { return (_container.upper_bound(k)); }

		pair<iterator, iterator> equal_range(const key_type& k) { return (_container.equal_range(k)); }

		pair<const_iterator, const_iterator> equal_range(const key_type& k) const { return (_container.equal_range(k)); }

		/* Allocator */
		allocator_type get_allocator() const { return (_alloc); }
	};

	template <typename Key, typename T, typename Comp, typename Alloc>
	bool operator==(const map<Key, T, Comp, Alloc>& l, const map<Key, T, Comp, Alloc>& r)
	{
		if (l.size() != r.size())
			return false;
		typename map<Key, T, Comp, Alloc>::const_iterator i = l.begin(), j = r.begin();
		for (; i != l.end() && j != r.end(); ++i, ++j)
			if (*i != *j)
				break;
		return (*i == *j);
	}
	
	template <typename Key, typename T, typename Comp, typename Alloc>
	bool operator!=(const map<Key, T, Comp, Alloc>& l, const map<Key, T, Comp, Alloc>& r)
	{ return (!(l == r)); }

	template <typename Key, typename T, typename Comp, typename Alloc>
	bool operator<(const map<Key, T, Comp, Alloc>& l, const map<Key, T, Comp, Alloc>& r)
	{
		typename map<Key, T, Comp, Alloc>::const_iterator i = l.begin(), j = r.begin();
		for (; i != l.end() && j != r.end(); ++i, ++j)
			if (*i != *j)
				break;
		return (*i < *j);
	}

	template <typename Key, typename T, typename Comp, typename Alloc>
	bool operator<=(const map<Key, T, Comp, Alloc>& l, const map<Key, T, Comp, Alloc>& r)
	{ return !(r < l); }
	
	template <typename Key, typename T, typename Comp, typename Alloc>
	bool operator>(const map<Key, T, Comp, Alloc>& l, const map<Key, T, Comp, Alloc>& r)
	{ return (r < l); }

	template <typename Key, typename T, typename Comp, typename Alloc>
	bool operator>=(const map<Key, T, Comp, Alloc>& l, const map<Key, T, Comp, Alloc>& r)
	{ return (!(l < r)); }

	template <typename Key, typename T, typename Compare, typename Alloc>
	void swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) { x.swap(y); }
};

#endif