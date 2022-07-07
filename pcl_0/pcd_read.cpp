#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>


int main(){
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    if(pcl::io::loadPCDFile<pcl::PointXYZ> ("test_pcd.pcd", *cloud) == -1){
        PCL_ERROR("read file error\n");
        return -1;
    }

    std::cout << "Loaded " << cloud->width * cloud->height << "data points from test_pcd.pcd with following fields " \
              << std::endl;

    for(size_t i =0; i < cloud->points.size(); ++i){
        std::cout << " " << cloud->points[i].x << " " << cloud->points[i].y << " " << cloud->points[i].z << std::endl;
    }

    pcl::visualization::CloudViewer viewer("pcd viewer");//给显示窗口命名，CloudViewer
    viewer.showCloud(cloud);//定义要显示的对象,showCloud
    sleep(1000);
    return 0;
}
