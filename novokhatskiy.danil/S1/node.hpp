#ifndef NODE_HPP
#define NODE_HPP

#include <utility>

namespace novokhatskiy
{
  namespace detail
  {
    template < typename T >
    struct Node
    {
      T value_;
      Node* next_;
      Node(const T& value, Node* next = nullptr):
        value_(value),
        next_(next)
      {}
      Node(T&& value):
        value_(std::move(value)),
        next_(nullptr)
      {}
    };
  }
}

#endif
