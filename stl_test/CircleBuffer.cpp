#ifndef __CB__
#define __CB__
#include <iostream>
#include <string>
#include <vector>


class CircleBuffer {
public:
    CircleBuffer(size_t size):length_(size){
    }

    ~CircleBuffer(){
        std::cout << "CircleBuffer Deconstruct " << std::endl;
        if( data_.size() !=0 ){
            data_.clear();
        }
    }
    void push(double d){
        if(data_.size() < length_){
            data_.push_back(d);
        }else {
            std::cout << "exchange data" << std::endl;

            for(size_t i =0; i< length_-1; ++i){
                data_[i] = data_[i+1];
            }
            data_[length_-1] = d;
        }

        showData();
    }
    void showData(){
        for(size_t i=0; i< data_.size();++i ){
            std::cout << data_[i] << " ";
        }

        std::cout <<  data_.size() << " length %d " << length_ << " mean " << getMean()<<  std::endl;
    }

    double getMean(){
        double mean = 0.0;
        for(size_t i=0; i< data_.size();++i ){
            mean += data_[i];
        }
        mean = mean / data_.size();
        return mean;
    }

private:
    std::vector<double> data_;
    size_t length_;
};
#endif



int main(int argc, char** argv){

    CircleBuffer buffer(5);
    for(auto i = 0; i < 1000; ++i){
        buffer.push(i);
        buffer.showData();
    }


    return 0;
}
