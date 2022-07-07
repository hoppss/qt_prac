#include <iostream>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/algorithms/transform.hpp>
#include <boost/geometry/geometries/point_xy.hpp>


using namespace boost;

namespace trans = boost::geometry::strategy::transform;
typedef boost::geometry::model::d2::point_xy<double> point_type;   // 模板不能用 namespace


int main() {


    point_type p1(1.0, 3.0);
    point_type p2, p3;
    
    trans::translate_transformer<double, 2, 2> translate(1.5, 1.5);
    boost::geometry::transform(p1, p2, translate);

    trans::translate_transformer<double, 2, 2> translate2(1.5, 0);
    boost::geometry::transform(p1, p3, translate2);


    std::cout
        << "p1: x: " << p1.x() << " y: " << p1.y() << std::endl
        << "p2: x: " << p2.x() << " y: " << p2.y() << std::endl
        << "p3: x: " << p3.x() << " y: " << p3.y() << std::endl;

    // 本质是平移加法
    // p1: x: 1 y: 3
    // p2: x: 2.5 y: 4.5
    // p3: x: 2.5 y: 3


    return 0;
}