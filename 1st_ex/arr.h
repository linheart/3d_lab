#ifndef ARR_H  // ARR_H
#define ARR_H

#include <cassert>

class Array {
 public:
  Array(std::size_t initialCapacity = 10)
      : data(new std::string[initialCapacity]),
        capacity(initialCapacity),
        length(0) {}

  ~Array() { delete[] data; }

  void append(const std::string &value) {
    if (length >= capacity) {
      resize(capacity * 2);
    }
    data[length++] = value;
  }

  void remove(std::size_t index) {
    assert(index < length);

    for (std::size_t i = index; i < length - 1; i++) {
      data[i] = data[i + 1];
    }

    length--;
  }

  std::size_t size() const { return length; }

  void print() const {
    for (std::size_t i = 0; i < length; i++) {
      std::cout << data[i] << std::endl;
    }
  }

  std::string &operator[](std::size_t index) {
    assert(index < capacity);
    return data[index];
  }

 private:
  std::string *data{};
  std::size_t capacity{};
  std::size_t length{};

  void resize(std::size_t newCapacity) {
    std::string *newData = new std::string[newCapacity];
    for (std::size_t i = 0; i < length; i++) {
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
  }
};

#endif  // ARR_H