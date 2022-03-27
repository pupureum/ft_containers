#ifndef NULLPTR_HPP
# define NULLPTR_HPP

namespace ft
{
static const
class {
public:
	template <typename T>
	operator T*() const {return (0);}

	template <typename C, typename T>
	operator T C::*() const {return (0);}

private:
	void operator&() const;
} ft_nullptr = {};
}

#endif