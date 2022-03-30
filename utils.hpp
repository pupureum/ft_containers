#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
	/* equal */
	template <typename InputIterator1, typename InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1; ++first2;
		}
		return (true);
	}

	template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1) {
			if (!pred(*first1, *first2))
				return (false);
			++first1; ++first2;
		}
		return (true);
	}


	/* lexicographical_compare */
	template <typename InputIterator1, typename InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1; ++first2;
		}
		return (first2 != last2);
	}

	template <typename InputIterator1, typename InputIterator2, typename Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return (false);
			else if (comp(*first1, *first2))
				return (true);
			++first1; ++first2;
		}
		return (first2 != last2);
	}

	/* pair */
	template <typename T1, typename T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair() : first(), second() {}
		pair(const first_type& a, const second_type& b) : first(a), second(b) {}
		
		template<class U, class V>
		pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {}

		pair& operator=(const pair& pr) {
			first = pr.first;
			second = pr.second;
			return (*this);
		}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& p1, const pair<T1,T2>& p2) {
		return (p1.first == p2.first && p1.second == p2.second);
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& p1, const pair<T1,T2>& p2) {
		return (!(p1 == p2));
	}

	template <class T1, class T2>
	bool operator<(const pair<T1,T2>& p1, const pair<T1,T2>& p2) {
		return ((p1.first < p2.first) || (!(p2.first < p1.first) && p1.second < p2.second));
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& p1, const pair<T1,T2>& p2) {
		return (!(p2 < p1));
	}

	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& p1, const pair<T1,T2>& p2) {
		return (p2 < p1);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& p1, const pair<T1,T2>& p2) {
		return (!(p1 < p2));
	}

	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 first, T2 second) {
		return ( pair<T1,T2>(first, second) );
	}

	template <typename Pair> //하나의 함수 템플릿 안에 하나의 인자만
	struct Select1st: public std::unary_function<Pair, typename Pair::first_type>
	{
	public:
		typename Pair::first_type operator()(Pair& x) const { return (x.first); }
		const typename Pair::first_type operator()(const Pair& x) const { return (x.first); }
	};

	template <typename L, typename R>
	struct is_same : public false_type {};
	template <typename T>
	struct is_same<T, T> : public true_type {};
}

#endif