#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{
	/* enable_if : 벡터 생성자의 인자로 들어온것이 iterator인지 아닌지 체크*/
	template <bool B, typename T = void>
	struct enable_if {};

	template<typename T>
	struct enable_if<true, T> { typedef T type; };	


	/* is_integral */
	template <typename T, T v>
	// struct integral_constant
	// {
	// 	typedef T value_type;
	// 	typedef integral_constant<T, v> type;
	// 	static const T value = v;
	// 	operator T() { return v; }
	// };
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T,value> type;
		operator value_type() const { return value; }
		value_type operator ()() const { return value; }
	};

}

#endif