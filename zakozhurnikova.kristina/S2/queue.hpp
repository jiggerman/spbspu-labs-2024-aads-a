#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <list.hpp>

namespace zakozhurnikova
{
  template< class T >
  class Queue
  {
  public:
    Queue() = default;
    Queue(const Queue< T >& rhs) = default;
    Queue(Queue< T >&& rhs) noexcept;
    ~Queue() = default;

    Queue< T >& operator=(const Queue< T >& rhs) = default;
    Queue< T >& operator=(Queue< T >&& rhs) noexcept;

    void push(const T& rhs);
    void drop();
    T& pop();
    size_t size() const noexcept;
    bool empty() const noexcept;

  private:
  List< T > queue_;
  };

  template< class T >
  Queue< T >::Queue(Queue< T >&& rhs) noexcept:
    queue_(std::move(rhs.queue_))
  {}


  template< class T >
  Queue< T >& Queue< T >::operator=(Queue< T >&& rhs) noexcept
  {
    if (std::addressof(rhs) != this)
    {
      queue_ = std::move(rhs.queue_);
    }
    return *this;
  }

  template< class T >
  void Queue< T >::push(const T& rhs)
  {
    queue_.push_front(rhs);
  }

  template< class T >
  void Queue< T >::drop()
  {
    queue_.pop_front();
  }

  template< class T>
  T& Queue< T >::pop()
  {
    T data = queue_.head_->data_;
    return data;
  }

  template< class T >
  size_t Queue< T >::size() const noexcept
  {
    return queue_.size();
  }

  template< class T >
  bool Queue< T >::empty() const noexcept
  {
    return queue_.empty();
  }

}
#endif
