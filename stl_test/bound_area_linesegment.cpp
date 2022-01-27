#include <iostream>
#include <string>
#include <vector>
#include <eigen3/Eigen/Eigen>

static int LENGTH = 10;

class SegementModel {
  public:
    SegementModel():init_model_(false) {}

    SegementModel(const int& _x1, const int& _y1, const int& _x2, const int& _y2)
    {
       x1 = _x1;
       x2 = _x2;

       y1 = _y1;
       y2 = _y2;

       init_model_ = true;
    }

    void setPoint(const int& _x1, const int& _y1, const int& _x2, const int& _y2)
    {
       x1 = _x1;
       x2 = _x2;

       y1 = _y1;
       y2 = _y2;

       init_model_ = true;
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

  private:
    bool init_model_;
    float x1;  // line start
    float y1;

    float x2;  // line end
    float y2;
};

template<class T>
void show(std::vector<std::vector<T>>& grid) {
    for(size_t i = 0; i< grid.size(); ++i) {
        for(size_t j = 0; j < grid[0].size(); ++j) {
            std::cout << grid[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
};


int main () {
    std::vector<std::vector<int>> grid;    // grid world
    std::vector<std::vector<float>> info;  // distance info to a line segment

    grid.resize(LENGTH);
    info.resize(LENGTH);

    // init grid
    for(size_t i = 0; i< LENGTH; ++i) {
        grid[i].resize(LENGTH);
        info[i].resize(LENGTH);
        for(size_t j = 0; j < LENGTH; ++j) {
            grid[i][j] = i+j;
            info[i][j] = 0.0;
        }
    }


    show(grid);

    //
    SegementModel model(5,5, 9, 9);

    for(size_t i = 0; i < grid.size(); ++i) {
        for(size_t j = 0; j < grid[0].size(); ++j) {
            info[i][j] = model.distanceToLine(i, j);
        }
    }

    show(info);

    return 0;
}



// 0	1	2	3	4	5	6	7	8	9
// 1	2	3	4	5	6	7	8	9	10
// 2	3	4	5	6	7	8	9	10	11
// 3	4	5	6	7	8	9	10	11	12
// 4	5	6	7	8	9	10	11	12	13
// 5	6	7	8	9	10	11	12	13	14
// 6	7	8	9	10	11	12	13	14	15
// 7	8	9	10	11	12	13	14	15	16
// 8	9	10	11	12	13	14	15	16	17
// 9	10	11	12	13	14	15	16	17	18


// 7.07107	6.40312	5.83095	5.38516	5.09902	5	5.09902	5.38516	5.83095	6.40312
// 6.40312	5.65685	5	4.47214	4.12311	4	4.12311	4.47214	5	5.65685
// 5.83095	5	4.24264	3.60555	3.16228	3	3.16228	3.60555	4.24264	5
// 5.38516	4.47214	3.60555	2.82843	2.23607	2	2.23607	2.82843	3.60555	4.24264
// 5.09902	4.12311	3.16228	2.23607	1.41421	1	1.41421	2.23607	2.82843	3.60555
// 5	4	3	2	1	0	1	1.41421	2.23607	2.82843
// 5.09902	4.12311	3.16228	2.23607	1.41421	1	0	1	1.41421	2.23607
// 5.38516	4.47214	3.60555	2.82843	2.23607	1.41421	1	0	1	1.41421
// 5.83095	5	4.24264	3.60555	2.82843	2.23607	1.41421	1	0	1
// 6.40312	5.65685	5	4.24264	3.60555	2.82843	2.23607	1.41421	1	0