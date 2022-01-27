#include <iostream>
#include <string>
#include <vector>
#include <eigen3/Eigen/Eigen>

static int LENGTH = 10;

class SegementGrid {
  public:
    SegementGrid():init_model_(false) {}

    SegementGrid(const int& _x1, const int& _y1, const int& _x2, const int& _y2, const int& _size)
    {
       x1 = _x1;
       x2 = _x2;

       y1 = _y1;
       y2 = _y2;

       width_= _size;
       initGrid();
       calculateDistance();  // calculate and save in grid

       init_model_ = true;
    }

    void setPoint(const int& _x1, const int& _y1, const int& _x2, const int& _y2, const int& _size)
    {
       x1 = _x1;
       x2 = _x2;

       y1 = _y1;
       y2 = _y2;

       width_= _size;
       initGrid();
       calculateDistance();  // calculate and save in grid

       init_model_ = true;
    }

    void initGrid() {
        grid.clear();
        grid.resize(width_* width_);
        grid.assign(width_* width_, 0.0);

        std::cout << "init Grid" << std::endl;
        show();
    }

    void show() {
        for(size_t i = 0; i< grid.size(); ++i) {
            std::cout << grid[i] << '\t';
            if(i % width_== width_- 1) std::cout << std::endl;
        }
        std::cout << std::endl << std::endl;
    }

    // Find closest Point(px,py) to this Linesegment,
    // return distance
    float distanceToLine(const int& x, const int& y) {
        // find closest point coordinate at segment
       float closest_x = 0.0;
       float closest_y = 0.0;

       float dx = x2 - x1;
       float dy = y2 - y1;

       float sq_norm = dx * dx + dy * dy;

       if(sq_norm == 0.0) {
         closest_x = x1;    // start == end, this is a  point
         closest_y = y1;

         return distance(x, y, closest_x, closest_y);
       } else {
            float u = ((x - x1) * dx + (y - y1)*dy) / sq_norm;

            if(u <=0) {
                closest_x = x1;  // return line start
                closest_y = y1;
            } else if( u >=1) {
                closest_x = x2;  // return line end
                closest_y = y2;
            } else {
                closest_x = x1 + dx * u;
                closest_y = y1 + dy * u;
            }

            return distance(x,y, closest_x, closest_y);
       }
    }

    float distance (const int& x_s, const int& y_s, const int& x_e, const int& y_e) {
        float dx = x_e - x_s;
        float dy = y_e - y_s;

        if(dx ==0.0 && dy == 0.0) return 0.0;
        return std::sqrt(dx * dx + dy*dy);
    }

    void calculateDistance() {
       for(size_t i = 0; i < width_; ++i) {
           for(size_t j = 0; j < width_; ++j) {
                grid[i + j * width_] = distanceToLine(i, j);
           }
       }

       std::cout << "distance result ->" << std::endl;
       show();
    }

    float operator[] (const int& index) const {
        return grid[index];
    }

    float getValue(const int& x, const int& y) const {
        return grid[x + y * width_];
    }

  private:
    bool init_model_;
    float x1;  // line start
    float y1;

    float x2;  // line end
    float y2;

    std::vector<float> grid;   // save all info
    int width_;  // squared grid
};

// template<class T>
// void show(std::vector<std::vector<T>>& grid) {
//     for(size_t i = 0; i< grid.size(); ++i) {
//         for(size_t j = 0; j < grid[0].size(); ++j) {
//             std::cout << grid[i][j] << '\t';
//         }
//         std::cout << std::endl;
//     }
//     std::cout << std::endl << std::endl;
// };


int main () {

    SegementGrid model(5,5, 5, 9, 10);

    return 0;
}