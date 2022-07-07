#include <iostream>
#include <string>
#include <vector>
#include <eigen3/Eigen/Eigen>

static int LENGTH = 10;

class LineModel {
  public:
    LineModel():init_model_(false) {}

    LineModel(const int& x1, const int& y1, const int& x2, const int& y2)
    {
       A = y2 - y1;
       B = x1 - x2;
       C = x2 * y1 - x1 * y2;

       k = (y2 - y1) / (x2 - x1);
       m = (y1 * x2 - y2 * x1) / (x2 - x1);

       init_model_ = true;
    }

    void setPoint(const int& x1, const int& y1, const int& x2, const int& y2) {
       A = y2 - y1;
       B = x1 - x2;
       C = x2 * y1 - x1 * y2;

       k = (y2 - y1) / (x2 - x1);
       m = (y1 * x2 - y2 * x1) / (x2 - x1);

       init_model_ = true;
    }

    float distanceToLine(const int& px, const int& py) {
       if(!init_model_) {
         throw std::runtime_error("line model is not initialized");
       }

       float norm = A * A * 1.0 + B * B * 1.0;
       if(norm == 0.0) {
           throw std::runtime_error("distance_to_line norm == 0");
       }
       return std::fabs(A * px + B * py + C) / std::sqrt(norm);
    }

  private:
    bool init_model_;
    float k;
    float m;  // y = K * x + m
    float A;  // Ax + By + c = 0
    float B;
    float C;
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
    LineModel model(9,9, 19, 19);

    for(size_t i = 0; i < grid.size(); ++i) {
        for(size_t j = 0; j < grid[0].size(); ++j) {
            info[i][j] = model.distanceToLine(i, j);
        }
    }

    show(info);

    return 0;
}

// 这里的效果是点到直线的距离，不是点到线段的距离；
// 所以从中心到右下角 能看出上下， 首末 是对称居中
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


// 0	0.707107	1.41421	2.12132	2.82843	3.53553	4.24264	4.94975	5.65685	6.36396
// 0.707107	0	0.707107	1.41421	2.12132	2.82843	3.53553	4.24264	4.94975	5.65685
// 1.41421	0.707107	0	0.707107	1.41421	2.12132	2.82843	3.53553	4.24264	4.94975
// 2.12132	1.41421	0.707107	0	0.707107	1.41421	2.12132	2.82843	3.53553	4.24264
// 2.82843	2.12132	1.41421	0.707107	0	0.707107	1.41421	2.12132	2.82843	3.53553
// 3.53553	2.82843	2.12132	1.41421	0.707107	0	0.707107	1.41421	2.12132	2.82843
// 4.24264	3.53553	2.82843	2.12132	1.41421	0.707107	0	0.707107	1.41421	2.12132
// 4.94975	4.24264	3.53553	2.82843	2.12132	1.41421	0.707107	0	0.707107	1.41421
// 5.65685	4.94975	4.24264	3.53553	2.82843	2.12132	1.41421	0.707107	0	0.707107
// 6.36396	5.65685	4.94975	4.24264	3.53553	2.82843	2.12132	1.41421	0.707107	0