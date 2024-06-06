#ifndef TEST_SORTINGS_HPP
#define TEST_SORTINGS_HPP

#include <ostream>
#include <cstddef>
#include <vector>
#include <list>
#include <deque>
#include <functional>
#include <forward_list.hpp>
#include "shell_sort.hpp"
#include "generate_numbers.hpp"
#include "selection_sort.hpp"

template< class Iter >
void printData(Iter first, Iter last, std::ostream & out)
{
  auto temp = first;
  ++temp;
  for (; temp != last; ++temp)
  {
    out << *first << " ";
    ++first;
  }
  out << *first << "\n";
}

template< class T >
struct Comparator
{
public:
  explicit Comparator(const std::string & order):
    order_(order)
  {}
  bool operator()(T a, T b) const
  {
    if (order_ == "ascending")
    {
      return std::less< T >()(a, b);
    }
    else if (order_ == "descending")
    {
      return std::greater< T >()(a, b);
    }
    else
    {
      throw std::invalid_argument("Wrong type of order");
    }
  }
private:
  std::string order_;
};

namespace namestnikov
{
  template< class T, class Compare >
  void testSortings(std::ostream & out, size_t size)
  {
    std::vector< T > data(size);
    std::generate(data.begin(), data.end(), std::bind(generateNumber< T >, -1000, 1000));
    printData(data.begin(), data.end(), out);
    Compare compare;
    ForwardList< T > forwardlistSelection;
    for (size_t i = 0; i < size; ++i)
    {
      forwardlistSelection.push_front(data[i]);
    }
    std::list< T > listSelection(data.begin(), data.end());
    std::list< T > listShell(data.begin(), data.end());
    std::deque< T > dequeSelection(data.begin(), data.end());
    std::deque< T > dequeShell(data.begin(), data.end());
    std::deque< T > dequeNormal(data.begin(), data.end());
    doSelectionSort(forwardlistSelection.begin(), size, compare);
    doSelectionSort(listSelection.begin(), size, compare);
    doShellSort(listShell.begin(), size, compare);
    doSelectionSort(dequeSelection.begin(), size, compare);
    doShellSort(dequeShell.begin(), size, compare);
    std::sort(dequeNormal.begin(), dequeNormal.end(), compare);
    printData(forwardlistSelection.begin(), forwardlistSelection.end(), out);
    printData(listSelection.begin(), listSelection.end(), out);
    printData(listShell.begin(), listShell.end(), out);
    printData(dequeSelection.begin(), dequeSelection.end(), out);
    printData(dequeShell.begin(), dequeShell.end(), out);
    printData(dequeNormal.begin(), dequeNormal.end(), out);
  }
}

#endif
