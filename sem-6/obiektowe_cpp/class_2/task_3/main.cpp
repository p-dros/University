#include<iostream> 
#include <string>
#include <vector>

template <typename Iterator>
typename std::iterator_traits<Iterator>::value_type accumulate(Iterator begin, Iterator end) {
    typename std::iterator_traits<Iterator>::value_type sum = typename std::iterator_traits<Iterator>::value_type();
    for (Iterator it = begin; it != end; ++it) {
        sum += *it;
    }
    
    return sum;
}

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  auto sum = accumulate(v.begin(), v.end());
  std::cout << "Sum: " << sum << std::endl;
  
  return 0;
}