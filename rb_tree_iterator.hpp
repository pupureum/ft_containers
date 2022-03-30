#ifndef RB_TREE_ITERATOR_HPP
# define RB_TREE_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{
	enum rb_color { red = false, black = true };

	template <typename Val>
	struct node
	{
		Val* 			value; //pair only for map
		struct node* 	parent;
		struct node* 	left;
		struct node* 	right;
		rb_color 		color;
		node(): value(0), parent(0), left(0), right(0) {}
	};

	template <typename T>
	class rb_tree_iterator
	{
	public:
		typedef bidirectional_iterator_tag			iterator_category;
		typedef ptrdiff_t							difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef struct								node<value_type> node;
		typedef node*								node_pointer;
		typedef rb_tree_iterator<value_type>		iterator;

	private:
		node_pointer _cur;
		node_pointer _root;
		node_pointer _nil;

	public:
		rb_tree_iterator(void): _cur(0), _root(0), _nil(0) {}

		rb_tree_iterator(const node_pointer nil, const node_pointer root, const node_pointer x): _cur(x), _root(root), _nil(nil) {}

		rb_tree_iterator(const iterator& x): _cur(x._cur), _root(x._root), _nil(x._nil) {}

		virtual ~rb_tree_iterator(void) {}

		node_pointer cur(void) const { return (_cur); }

		node_pointer nil(void) const { return (_nil); }

		node_pointer root(void) const { return (_root); }
	
		node_pointer rb_tree_iterator_increment(node_pointer x)
		{
			if (_root == 0)
				return (0);
			if (x == _nil)
			{
				node_pointer t = _root;
				while (t->left != _nil)
					t = t->left;
				return (t);
			}
			if (x->right != _nil)
			{
				x = x->right;
				while (x->left != _nil)
					x = x->left;
			}
			else
			{
				node_pointer y = x->parent;
				while (x == y->right)
				{
					x = y;
					y = y->parent;
				}
				x = y;
			}
			return (x);
		}
		node_pointer rb_tree_iterator_decrement(node_pointer x)
		{
			if (_root == 0)
				return (0);
			if (x == _nil)
			{
				node_pointer t = _root;
				while (t->right != _nil)
					t = t->right;
				return (t);
			}
			if (x->left != _nil)
			{
				x = x->left;
				while (x->right != _nil)
					x = x->right;
			}
			else
			{
				node_pointer y = x->parent;
				while (x == y->left)
				{
					x = y;
					y = y->parent;
				}
				x = y;
			}
			return (x);
		}
		pointer operator->(void) const
		{
			return (_cur->value);
		}
		reference operator*(void) const
		{
			return (*_cur->value);
		}
		iterator& operator++(void)
		{
			_cur = rb_tree_iterator_increment(_cur);
			return (*this);
		}
		iterator operator++(int)
		{
			iterator tmp = *this;
			_cur = rb_tree_iterator_increment(_cur);
			return (tmp);
		}
		iterator& operator--(void)
		{
			_cur = rb_tree_iterator_decrement(_cur);
			return (*this);
		}
		iterator operator--(int)
		{
			iterator tmp = *this;
			_cur = rb_tree_iterator_decrement(_cur);
			return (tmp);
		}
		
		bool operator==(const iterator& rhs)
		{
			return (_cur == rhs._cur);
		}
		bool operator!=(const iterator& rhs)
		{
			return (_cur != rhs._cur);
		}
	};

	/* const iterator */
	template <typename T>
	class rb_tree_const_iterator
	{
	public:
		typedef bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T& reference;
		typedef const T* pointer;
		typedef struct node<value_type> node;
		typedef node* node_pointer;
		typedef rb_tree_iterator<value_type> iterator;
		typedef rb_tree_const_iterator<value_type> const_iterator;

	private:
		node_pointer _cur;
		node_pointer _root;
		node_pointer _nil;

	public:
		rb_tree_const_iterator(): _cur(0), _root(0), _nil(0) {}

		rb_tree_const_iterator(const node_pointer nil, const node_pointer root, const node_pointer x): _cur(x), _root(root), _nil(nil) {}

		rb_tree_const_iterator(const const_iterator& x): _cur(x._cur), _root(x._root), _nil(x._nil) {}

		rb_tree_const_iterator(const iterator& x): _cur(x.cur()), _root(x.root()), _nil(x.nil()) {}

		virtual ~rb_tree_const_iterator(void) {}

		node_pointer cur(void) const { return (_cur); }

		node_pointer nil(void) const { return (_nil); }

		node_pointer root(void) const { return (_root); }

		node_pointer rb_tree_iterator_increment(node_pointer x)
		{
			if (x->right != _nil)
			{
				x = x->right;
				while (x->left != _nil)
					x = x->left;
			}
			else
			{
				node_pointer y = x->parent;
				while (x == y->right)
				{
					x = y;
					y = y->parent;
				}
				x = y;
			}
			return (x);
		}

		node_pointer rb_tree_iterator_decrement(node_pointer x)
		{
			if (x == _nil)
			{
				node_pointer t = _root;
				while (t->right != _nil)
					t = t->right;
				return (t);
			}
			if (x->left != _nil)
			{
				x = x->left;
				while (x->right != _nil)
					x = x->right;
			}
			else
			{
				node_pointer y = x->parent;
				while (x == y->left)
				{
					x = y;
					y = y->parent;
				}
				x = y;
			}
			return (x);
		}

		pointer operator->(void) const
		{
			return (_cur->value);
		}
		reference operator*(void) const
		{
			return (*_cur->value);
		}
		const_iterator& operator++(void)
		{
			_cur = rb_tree_iterator_increment(_cur);
			return (*this);
		}
		const_iterator operator++(int)
		{
			const_iterator tmp = *this;
			_cur = rb_tree_iterator_increment(_cur);
			return (tmp);
		}
		const_iterator& operator--(void)
		{
			_cur = rb_tree_iterator_decrement(_cur);
			return (*this);
		}
		const_iterator operator--(int)
		{
			const_iterator tmp = *this;
			_cur = rb_tree_iterator_decrement(_cur);
			return (tmp);
		}
		friend bool operator==(const const_iterator& lhs, const const_iterator& rhs) { return (lhs._cur == rhs._cur); }

		friend bool operator!=(const const_iterator& lhs, const const_iterator& rhs) { return (lhs._cur != rhs._cur); }
	};

	/* rb reverse iterator */
	template <typename T>
	class rb_tree_iterator;

	template <typename T>
	class rb_tree_reverse_iterator
	{
	public:
		typedef bidirectional_iterator_tag		iterator_category;
		typedef ptrdiff_t						difference_type;
		typedef typename T::value_type			value_type;
		typedef typename T::pointer				pointer;
		typedef typename T::reference			reference;
		typedef struct node<value_type>			node;
		typedef node*							node_pointer;
		typedef typename T::iterator			iterator;
		typedef rb_tree_reverse_iterator<T>		reverse_iterator;
		typedef rb_tree_const_iterator<T>		const_iterator;

	private:
		node_pointer _cur;
		node_pointer _root;
		node_pointer _nil;

	public:
		rb_tree_reverse_iterator(void): _cur(0), _root(0), _nil(0) {}
	
		rb_tree_reverse_iterator(const node_pointer nil, const node_pointer root, const node_pointer x): _cur(x), _root(root), _nil(nil) {}

		rb_tree_reverse_iterator(const reverse_iterator& x): _cur(x._cur), _root(x._root), _nil(x._nil) {}

		rb_tree_reverse_iterator(const iterator& x): _cur(x.cur()), _root(x.root()), _nil(x.nil()) { _cur = rb_tree_iterator_decrement(_cur); }

		rb_tree_reverse_iterator(const const_iterator& x): _cur(x.cur()), _root(x.root()), _nil(x.nil()) { _cur = rb_tree_iterator_decrement(_cur); }

		virtual ~rb_tree_reverse_iterator(void) {}

		iterator base(void) const { return (iterator(_nil, _root, rb_tree_iterator_increment(_cur))); }

		node_pointer cur(void) const { return (_cur); }

		node_pointer root(void) const { return (_root); }

		node_pointer nil(void) const { return (_nil); }

		node_pointer rb_tree_iterator_increment(node_pointer x) const
		{
			if (x == _nil)
			{
				node_pointer t = _root;
				while (t->left != _nil)
					t = t->left;
				return (t);
			}
			if (x->right != _nil)
			{
				x = x->right;
				while (x->left != _nil)
					x = x->left;
			}
			else
			{
				node_pointer y = x->parent;
				while (x == y->right)
				{
					x = y;
					y = y->parent;
				}
				x = y;
			}
			return (x);
		}
	
		node_pointer rb_tree_iterator_decrement(node_pointer x) const
		{
			if (x == _nil)
			{
				node_pointer t = _root;
				while (t->right != _nil)
					t = t->right;
				return (t);
			}
			if (x->left != _nil)
			{
				x = x->left;
				while (x->right != _nil)
					x = x->right;
			}
			else
			{
				node_pointer y = x->parent;
				while (x == y->left)
				{
					x = y;
					y = y->parent;
				}
				x = y;
			}
			return (x);
		}
	
		pointer	operator->(void) const { return (_cur->value); }

		reference	operator*(void) const { return (*_cur->value); }

		reverse_iterator&	operator++(void) { _cur = rb_tree_iterator_decrement(_cur); return (*this); }

		reverse_iterator	operator++(int)
		{
			reverse_iterator tmp = *this;
			_cur = rb_tree_iterator_decrement(_cur);
			return (tmp);
		}

		reverse_iterator&	operator--(void)
		{
			_cur = rb_tree_iterator_increment(_cur);
			return (*this);
		}

		reverse_iterator	operator--(int)
		{
			reverse_iterator tmp = *this;
			_cur = rb_tree_iterator_increment(_cur);
			return (tmp);
		}

		bool	operator==(const reverse_iterator& rhs) const
		{ return (_cur == rhs._cur); }

		bool	operator!=(const reverse_iterator& rhs) const
		{ return (_cur != rhs._cur); }
	};

	template <typename T>
	class rb_tree_const_reverse_iterator
	{
	public:
		typedef bidirectional_iterator_tag			iterator_category;
		typedef ptrdiff_t							difference_type;
		typedef typename T::value_type				value_type;
		typedef typename T::pointer					pointer;
		typedef typename T::reference				reference;
		typedef struct node<value_type>				node;
		typedef node*								node_pointer;
		typedef typename T::iterator				iterator;
		typedef typename T::const_iterator			const_iterator;
		typedef rb_tree_reverse_iterator<iterator>	reverse_iterator;
		typedef rb_tree_const_reverse_iterator<T>	const_reverse_iterator;

	private:
		node_pointer _cur;
		node_pointer _root;
		node_pointer _nil;

	public:
		rb_tree_const_reverse_iterator(void): _cur(0), _root(0), _nil(0) {}

		rb_tree_const_reverse_iterator(const node_pointer nil, const node_pointer root, const node_pointer x): _cur(x), _root(root), _nil(nil) {}

		rb_tree_const_reverse_iterator(const const_reverse_iterator& x): _cur(x._cur), _root(x._root), _nil(x._nil) {}

		rb_tree_const_reverse_iterator(const reverse_iterator& x): _cur(x.cur()), _root(x.root()), _nil(x.nil()) {}

		rb_tree_const_reverse_iterator(const iterator& x): _cur(x.cur()), _root(x.root()), _nil(x.nil()) { _cur = rb_tree_iterator_decrement(_cur); }

		rb_tree_const_reverse_iterator(const const_iterator& x): _cur(x.cur()), _root(x.root()), _nil(x.nil()) { _cur = rb_tree_iterator_decrement(_cur); }

		virtual ~rb_tree_const_reverse_iterator(void) {}

		const_iterator base(void) const { return (const_iterator(_nil, _root, rb_tree_iterator_increment(_cur))); }

		node_pointer rb_tree_iterator_increment(node_pointer x) const
		{
			if (_root == 0)
				return (0);
			if (x == _nil)
			{
				node_pointer t = _root;
				while (t->left != _nil)
					t = t->left;
				return (t);
			}
			if (x->right != _nil)
			{
				x = x->right;
				while (x->left != _nil)
					x = x->left;
			}
			else
			{
				node_pointer y = x->parent;
				while (x == y->right)
				{
					x = y;
					y = y->parent;
				}
				x = y;
			}
			return (x);
		}

		node_pointer rb_tree_iterator_decrement(node_pointer x) const
		{
			if (_root == 0)
				return (0);
			if (x == _nil)
			{
				node_pointer t = _root;
				while (t->right != _nil)
					t = t->right;
				return (t);
			}
			if (x->left != _nil)
			{
				x = x->left;
				while (x->right != _nil)
					x = x->right;
			}
			else
			{
				node_pointer y = x->parent;
				while (x == y->left)
				{
					x = y;
					y = y->parent;
				}
				x = y;
			}
			return (x);
		}

		pointer operator->(void) const
		{
			return (static_cast<node_pointer>(_cur)->value);
		}

		reference operator*(void) const
		{
			return (*static_cast<node_pointer>(_cur)->value);
		}

		const_reverse_iterator& operator++(void)
		{
			_cur = rb_tree_iterator_decrement(_cur);
			return (*this);
		}

		const_reverse_iterator operator++(int)
		{
			const_reverse_iterator tmp = *this;
			_cur = rb_tree_iterator_decrement(_cur);
			return (tmp);
		}

		const_reverse_iterator& operator--(void)
		{
			_cur = rb_tree_iterator_increment(_cur);
			return (*this);
		}

		const_reverse_iterator operator--(int)
		{
			const_reverse_iterator tmp = *this;
			_cur = rb_tree_iterator_increment(_cur);
			return (tmp);
		}

		friend bool operator==(const const_reverse_iterator& lhs, const const_reverse_iterator& rhs) { return (lhs._cur == rhs._cur); }
	
		friend bool operator!=(const const_reverse_iterator& lhs, const const_reverse_iterator& rhs) { return (lhs._cur != rhs._cur); }
	};
}

#endif