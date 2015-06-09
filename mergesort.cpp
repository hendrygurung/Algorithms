#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

using std::cin;  // using (namespaces): pg 35, 482
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::min;

#include "mergesort.hpp"
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

//The actual merging code
template <typename T>
void mergeIter(vector<T> &v, int first, int mid, int last,vector<T> &tempVector){
  int i = first;
  int j = mid + 1;
  for (int k = first; k <= last; k++) { 
      tempVector[k] = v[k];
  }
  for (int k = first; k <= last; k++) { 
	if (i > mid) 
		v[k] = tempVector[j++];
	else if (j > last )
		 v[k] = tempVector[i++];
	else if (tempVector[j] < tempVector[i])
		 v[k] = tempVector[j++];
	else 
		v[k] = tempVector[i++];
  }
}

//recursive call including first and last 
template <typename T>
void mergeRecursive(vector<T> &a, int first, int last,vector<T> &tempVector){
	if (last <= first){
	  return;
	}
      int mid = first + (last - first) / 2;      
      mergeRecursive(a, first, mid, tempVector);
      mergeRecursive(a, mid+1, last, tempVector);
      mergeIter(a, first, mid, last, tempVector);
    
}


template <typename T> // template, typename: pg 419
void recursive_mergesort (vector<T> &a) { // vector: pg 1012; & (reference): pg 383
  vector<T> tempVector(a.size());
  int first, last;
  first = 0;		
  last = a.size() - 1;

  mergeRecursive(a,first,last, tempVector);

}


template <typename T>
void iterative_mergesort (vector<T> &a){	
	vector<T> tempVector(a.size());
	int i, j;
	int n = a.size();
	int left, mid, right;

	for(i = 1; i < n ; i = i + i){
		for(j = 0; j < n - i; j += i + i){
			left = j;
			mid = j+i - 1;
			right = MIN(j + i + i - 1, n-1);
			mergeIter(a, left, mid, right, tempVector);
		}
	}
}

// Provoke the instantiation of various classes (explicit instantiation of template function: pg 429).
//
// The preceding templates are just that---templates.  We still need to bring specific instances into existence (this
// is one instance of <<instantiation>>.
//
// The references below refer to specific instances of the template functions above.  This causes the appropriate code
// to be generated automagically by the compiler.
//
// If you want to learn more about how g++ handles template instantiation, see 
// https://gcc.gnu.org/onlinedocs/gcc/Template-Instantiation.html

template void recursive_mergesort<char>(vector<char>&);
template void recursive_mergesort<int>(vector<int>&);
template void recursive_mergesort<unsigned short int>(vector<unsigned short int>&);
template void recursive_mergesort<unsigned int>(vector<unsigned int>&);
template void recursive_mergesort<long int>(vector<long int>&);
template void recursive_mergesort<unsigned long int>(vector<unsigned long int>&);
template void recursive_mergesort<double>(vector<double>&);
template void recursive_mergesort<long double>(vector<long double>&);
template void recursive_mergesort<float>(vector<float>&);
template void recursive_mergesort<unsigned char>(vector<unsigned char>&);
template void recursive_mergesort<signed char>(vector<signed char>&);

template void iterative_mergesort<unsigned char>(vector<unsigned char>&);
template void iterative_mergesort<signed char>(vector<signed char>&);
template void iterative_mergesort<char>(vector<char>&);
template void iterative_mergesort<int>(vector<int>&);
template void iterative_mergesort<unsigned short int>(vector<unsigned short int>&);
template void iterative_mergesort<unsigned int>(vector<unsigned int>&);
template void iterative_mergesort<long int>(vector<long int>&);
template void iterative_mergesort<unsigned long int>(vector<unsigned long int>&);
template void iterative_mergesort<double>(vector<double>&);
template void iterative_mergesort<long double>(vector<long double>&);
template void iterative_mergesort<float>(vector<float>&);
