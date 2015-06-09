#include "array.hpp"
#include <algorithm> 

namespace cs303 {

  template<typename T> 
  array<T>::array(long int N){
    if (N < 0) {
      throw std::invalid_argument("Negative vector length specified.");
    }
    n = N;
    a = new T[n];

  }

  template<typename T> 
  array<T>::array(const array<T> &v){
    n = v.size();
    a = new T[n];
    for (long int i = 0; i < n; i++) {
      a[i] = v[i];
    }
  }

  template<typename T> 
  array<T>::~array(){
    delete[] a;
  }

  template<typename T>
  array<T>& array<T>::operator=(const array<T> &v){
    if (n != v.size()) {
      throw std::runtime_error("Vectors in call to array<T>::operator= are of unequal size!");
    }
    for (long int i = 0; i < n; i++) {
      a[i] = v[i];
    }

    return *this;
  }

  template<typename T>
  void array<T>::quicksort(){
    quicksort(0, size() - 1);

  }

  template<typename T>
  void array<T>::quicksort(long int lo, long int hi){
    if (hi <= lo){return;} 
   
    long int j = partition(lo, hi); // Partition (see page 291).
    quicksort(lo, j-1); // Sort left part a[lo .. j-1].
    quicksort(j+1, hi);
  }

  template<typename T>
  long int array<T>::partition(long int lo, long int hi)
  {
    long int i = lo, j = hi + 1; // left and right scan indices
    T pivot = a[lo]; // partitioning item
    T temp;
    while (true)
    { // Scan right, scan left, check for scan complete, and exchange.
      while (a[++i] < pivot){if (i == hi){ break;}}
      while (pivot < a[--j]){if (j == lo) {break;}} 
      if (i >= j){
        break; 
      }
      // swap(a, i, j);
      temp = a[j];
      a[j] = a[i];
      a[i] = temp;
    }
    // swap(a, lo, j); // Put pivot = a[j] into position
    temp = a[j];
    a[j] = a[lo];
    a[lo] = temp;
    return j;
  }

 
  
  template class array<double>;
}
