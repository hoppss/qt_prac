#include <iostream>
#include <string>
#include <deque>
#include <mutex>
#include <assert.h>
#include <cmath>
#include <vector>


double toRad(double angle) {
    return angle / 180.0 * M_PI;
}


class Position {
public:
    Position() {
        x = y = yaw = 0.0;
    }

    Position(double _x, double _y, double _yaw): x(_x), y(_y), yaw(_yaw) {
    }

    double getX() {
        return x;
    }

    double getY() {
        return y;
    }

    double getYaw() {
        return yaw;
    }

private:
    double x;
    double y;
    double yaw;
};





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

  void push_front(const Position& d)
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

  Position front()
  {
    assert(buffer_.size()>0);

    //   std::unique_lock<std::mutex> lock;
    mx_.lock();
    Position ret = buffer_.front();
    mx_.unlock();

    return ret;
  }

  Position avg() {
    int size = buffer_.size();
    double sum_x = 0.0, sum_y = 0.0;
    double sum_yaw_cos =0.0, sum_yaw_sin = 0.0;
    for (auto it = buffer_.begin(); it != buffer_.end(); ++it) {
      sum_x+= (*it).getX();
      sum_y += (*it).getY();

      sum_yaw_cos += std::cos( (*it).getYaw() );
      sum_yaw_sin += std::sin( (*it).getYaw() );
    }

    return Position(sum_x / size, sum_y / size, std::atan2(sum_yaw_sin, sum_yaw_cos));
  }

  void print()
  {
    for (auto it = buffer_.begin(); it != buffer_.end(); ++it)
    {
      std::cout << (*it).getX() << " " << (*it).getY() <<" " << (*it).getYaw() <<", ";
    }
    std::cout << "____ " << buffer_.size() << std::endl;
  }

private:
  std::deque<Position> buffer_;
  int length_;
  std::recursive_mutex mx_;  // lock and unlock must be paired called
};

int main()
{

    std::vector<double> v1 = {toRad(2), toRad(-1),toRad(1), toRad(3)};
    std::vector<double> v2 = {toRad(175), toRad(-178),toRad(-176), toRad(-179)};


  CircleBuffer buffer;
  buffer.resize(3);

  for (int i = 0; i < 4; ++i)
  {
    buffer.push_front(Position(i, i, v1[i]));
    Position tmp = buffer.avg();
    std::cout << tmp.getX()  << ", " << tmp.getY()  << ", " << tmp.getYaw() << std::endl;
  }

  std::cout << std::endl;

  for (int i = 0; i < 4; ++i)
  {
    buffer.push_front(Position(i, i, v2[i]));
    Position tmp = buffer.avg();
    std::cout << tmp.getX()  << ", " << tmp.getY()  << ", " << tmp.getYaw() << std::endl;
  }
}
