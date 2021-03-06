#ifndef Guard_my_include_h
#define Guard_my_include_h

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <iterator>
#include <numeric>
#include <stdexcept>


using std::cin;
using std::cout;
using std::endl;
using std::back_inserter;
using std::ostream_iterator;
using std::isalpha;
using std::domain_error;

using std::string;
using std::vector;

using std::max;
using std::search;
using std::find_if;
using std::copy;
using std::remove;
using std::remove_copy_if;
using std::remove_copy;
using std::partition;
using std::swap;

using std::isspace;

using std::accumulate;


#define delim (string(20, '*') + '\n')


template <class T>
void print_vector_to_out(const vector<T>& v) {
    copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
    cout << endl;
}


#endif
