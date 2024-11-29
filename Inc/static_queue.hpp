#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stddef.h>

#ifdef STD_LIB_UNAVAILABLE
void *operator new(size_t size, void *ptr) {
  return ptr;
} // definition of placement new
#else
#include <new> // alternatively, placement new is already defined by the standard library
#endif

typedef size_t size_type;

template <typename T, size_type max_size> class static_queue {
public:
  static_queue() : start_idx(0), _size(0), data((T *)data_raw) {}
  bool empty() const { return size() == 0; }
  bool full() const { return size() == max_size; }
  void push(const T &val); // inserts a new element at the end of the queue if
                           // there is space
  T &front();              // accesses the oldest element in the queue
  void pop();              // removes the oldest element in the queue
  T &back();               // accesses the newest element in the queue
  size_type size() const { return _size; }

private:
  size_type start_idx;
  size_type _size;
  char data_raw[max_size * sizeof(T)];
  T *const data; // this should be replaced with a method
};

template <typename T, size_type max_size>
void static_queue<T, max_size>::push(const T &val) {
  if (full())
    return; // if there is no space, push() will do nothing
  _size++;
  new (&back()) T(val);
}

template <typename T, size_type max_size>
void static_queue<T, max_size>::pop() {
  if (empty())
    return; // it is safe to call pop() on an empty queue
  front().~T();
  _size--;
  start_idx = start_idx < max_size - 1 ? start_idx + 1 : 0;
}

// should not be called on an empty queue
template <typename T, size_type max_size>
T &static_queue<T, max_size>::front() {
  return data[start_idx];
}

// should not be called on an empty queue
template <typename T, size_type max_size> T &static_queue<T, max_size>::back() {
  size_type end_idx = start_idx + size() - 1;
  end_idx %= max_size;
  return data[end_idx];
}

#endif /* SLIMDRIVE_INC_STATIC_QUEUE_HPP_ */
