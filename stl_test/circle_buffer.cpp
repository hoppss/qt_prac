#include <iostream>
#include <string>
#include <deque>
#include <mutex>

// use deque and mutex protect
// deque can not get container data by index
class CircleBuffer
{
public:
  CircleBuffer()
  {
    buffer_.clear();
  }

  void resize(int length) {
      length_ = length;
  }

  ~CircleBuffer()
  {
    std::cout << "Deconstruct" << std::endl;
    buffer_.clear();
  }

  void clear() {
      buffer_.clear();
  }

  void push_front(int d)
  {
    //   std::unique_lock<std::mutex> lock;
    mx_.lock();
    while (buffer_.size() > length_ - 1)
    {
      buffer_.pop_back();
    }

    buffer_.push_front(d);  // new_data insert to head pos

    print();

    mx_.unlock();
  }

  int front()
  {
    if (buffer_.empty())
    {
      std::cerr << "empty no data" << std::endl;  // exception
      return 0.0;
    }

    //   std::unique_lock<std::mutex> lock;
    mx_.lock();
    int ret = buffer_.front();
    mx_.unlock();

    return ret;
  }

  void print()
  {
    for (auto it = buffer_.begin(); it != buffer_.end(); ++it)
    {
      std::cout << *it << " ";
    }
    std::cout << "____ " << buffer_.size() << " ____; front " << front() << std::endl;
  }

private:
  std::deque<int> buffer_;
  int length_;
  std::recursive_mutex mx_;  // lock and unlock must be paired called
};

int main()
{
  CircleBuffer buffer;
  buffer.resize(3);

  for (int i = 0; i < 20; ++i)
  {
    buffer.push_front(i);
  }
}
