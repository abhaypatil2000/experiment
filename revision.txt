#include <limits>
	1. cout << numeric_limits<type>::min() << endl;
	2. cout << numeric_limits<type>::max() << endl;

#include <climits>
	1. INT_MIN, INT_MAX (U prefix for unsigned) -> (2 ^ 31), (2 * 10 ^ 9) // 32 bit
	2. LONG_MIN, LONG_MAX (U prefix for unsigned) -> (2 ^ 31), (2 * 10 ^ 9) // 32 bit
	3. LLONG_MIN, LLONG_MAX (U prefix for unsigned) -> (2 ^ 63), (9 * 10 ^ 18) // 64 bit

#include <cfloat>
	1. FLT_MIN, FLT_MAX
	2. DBL_MIN, DBL_MAX
	3. LDBL_MIN, LDBL_MAX

#include <cmath>
	1. double log(x) -> base e
	2. double log10(x) -> base 10
	3. double log2(x) -> base 2
	4. double pow(a, b) -> a ^ b
	5. double sqrt(x)
	6. ceil(x), floor(x)
	7. abs(x), fabs(x)
	8. min(x), max(x)

#include <cstdlib>
	1. atoi, atof, atol, atoll
	2. rand(), srand(x)
	3. malloc, free

#include <cstring>
	1. memset(ptr, value, size)
	2. strlen(ptr) // length of a c style string

#include <algorithm>
	1. find (inp_itr first, inp_itr last, val) // returns the first instance
	2. count (inp_itr first, inp_itr last, val)
	3. swap (a, b) swap these two objects (can be int, float, map, set, etc), of same type
	4. fill (fwd_itr first, fwd_itr last, value)
	5. remove (fwd_itr first, fwd_itr last, val) // removes those equal to val
	6. unique (fwd_itr first, fwd_itr last, pred) // pred check if two elements are equivalent // returns the pointer to the end of the container to resize
	7. rotate (fwd_itr first, fwd_itr middle, fwd_itr last, bool cmp)
	8. reverse (bidirect first, bidirect last)
	9. partition(fwd_itr first, fwd_itr last, bool unary_function(x)) // all true in first half, false in second half, returns itr to the first element in the false part
	10. stable_partition (bidirect first, bidirect last, bool unary_function(x))
	11. sort, stable_sort (rndm_itr first, rndm_itr last, bool comp()) // should v[i] be placed before v[j] (j > i)
	12. nth_element(fwd_itr first, fwd_itr middle, fwd_itr last, bool comp) // middle element in its sorted order, according to the comp
	13. lower_bound, upper_bound, binary_search (operator "<" or bool comp)
	14. make_heap(rndm_itr first, rndm_itr last, comp), push_heap, pop_heap, sort_heap (rndm_itr needed, operator "<" or bool comp, true if first number is of lesser priority than the second), need to use push_back() and pop_back() for push_heap and pop_heap resp.
	15. min, max, minmax (optional bool comp) (pair of min, max)
	16. min_element, max_element, minmax_element (optional bool comp) (pair of min_element, max_element) // returns itr to the element
	17. next_permutation, prev_permutation
	18. equal_range(fwd_itr first, fwd_itr last, value, bool comp) // returns a pair of iterators, lower_bound and upper_bound, comp is the function used to sort the container

#include <iterator>
	1. distance(first, last) -> if random iterator then O(1), else O(N)

#include <tuple>
	1. tuple<int, int, char> my_tuple = make_tuple(first, second, third);
	2. tie(a, b, c) = my_tuple
	3. int a = get<0>(my_tuple) || get<1>(my_tuple) = 2 // access it as lvalue or rvalue

#include <utility>
	1. make_pair
	2. pair data structure // not needed

#include <iomanip>
	1. cout << fixed << setprecision(10) << float/double << endl; // prints 10 decimal places, 0 if necessary
	2. cout << setprecision(10) << float/double << endl; // prints with 10 digits, no extra 0 added
	3. fixed / scientific / defaultfloat

#include <deque>
	1. dq.erase(itr position) || erase(const_itr first, const_itr last) // returns an iterator to the element after the last deleted element
	2. dq.insert(const_itr position, type val) || insert(const_itr position, #of_inserts, type val)
	3. front(), back(), push_back(), push_front(), pop_back(), pop_front(), size()

#include <list>
	1. ls.erase(const_itr position) || erase(const_itr first, const_itr last) // returns iterator to the element after the last deleted element
	2. ls.insert(const_itr position, type val) || insert(const_itr position, #of_inserts, type val) // points to the first newly inserted elements
	3. ls.remove(type val) // removes those nodes which is equal to val in O(n) time
	4. ls.reverse() // linear time
	5. ls.sort() || sort(bool comp) // '<' or comp, nlogn time
	6. ls.unique() || unique(pred) // to check whether two elements are same or not
	7. front(), back(), push_back(), push_front(), pop_back(), pop_front(), empty(), size()

#include <map>
	Map
	1. mape.count(val) // number of pairs with key == val (map has 0 or 1, multimap can have more than 1)
	2. mape.erase(iter position) || erase(iter first, iter second) || erase(val), key == val-> returns no. of elements removed
	3. mape.find(val) // returns the first position with key == val
	4. mape.lower_bound(val), mape.upper_bound(val) // return iterator to the lower_bound/upper_bound element when comparing keys
	5. mape.equal_range(val) // return upper_bound and lower_bound with key == val
	6. mape.insert(pair<key, value>) // returns an iterator to the inserted element, or and equivalent which already existed (2nd part not for multimap)

	Multimap
	1. mape.find(val) // any one of the multiple duplicates, use equal_range to get all of them

#include <queue>
	Priority_queue
	1. top(), push(val), pop(), size(), empty()
	For custom comparator, struct is needed
	priority_queue(int, vector<int>, comp()) pq;
	struct comp
	{
		bool operator() (const type &a, const type &b)
		{
			return a < b; // or something similar
		}
	}

	Queue
	1. back(), front(), empty(), push(val), pop(), size()

#include <set>
	Set
	1. sete.count(val) // number of nodes with value same as val (set has 0 or 1, multiset can have more than 1)
	2. sete.erase(iter position) || erase(iter first, iter second) || erase(val) -> returns no. of elements removed
	3. sete.find(val) // returns the first position with this values
	4. sete.lower_bound(val), sete.upper_bound(val)
	5. sete.equal_range(val) // return pair of iterators, lower_bound and upper_bound
	6. sete.insert(val) // returns an iterator to the inserted element, or and equivalent which already existed (2nd part not for multiset)

	Multiset
	1. sete.find(val) // any one of the multiple duplicates, use equal_range to get all of them
	rest same as above

#include <stack>
	1. top(), push(val), pop(), size(), empty()

#include <unordered_map>
	Unordered_map
	1. All same except lower_bound, upper_bound, which don't exist, however equal_range does exist, however dereferencing the second might give a segmentation fault (as it could also be the last element)

	Unordered_multimap
	1. mape.find(val) returns an iterator to any element with value == val
	rest same as unordered_map

#include <unordered_set>
	Unordered_set
	1. All same except lower_bound, upper_bound, which don't exist, however equal_range does exist, however dereferencing the second might give a segmentation fault (as it could also be the last element)

	Unordered_multiset
	1. sete.find(val) returns an iterator to any element with value == val, here order does not matter
	rest same as unordered_set

#include <vector>
	1. v.erase(iter position) || v.erase(first, last);
	2. v.insert(const_itr position, type val) // returns the itr to the first of the inserted elements
	2.1. v.insert(const_itr position, #of_inserts, type val) // similar to fill
	3. v.data() // returns the underlying c style array
