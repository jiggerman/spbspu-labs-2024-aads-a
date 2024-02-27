#include <iostream>
#include <string>
#include "list.hpp"
#include "input_list.hpp"
#include "output_list.hpp"

int main()
{
  using namespace nikitov;
  try
  {
    List< std::pair< std::string, List< size_t > > > pairsList;
    inputList(pairsList, std::cin);
    outputList(pairsList, std::cout);
  }
  catch (const std::invalid_argument& e)
  {
    std::cout << 0 << '\n';
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

  return 0;
}
