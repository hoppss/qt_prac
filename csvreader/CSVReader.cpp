#ifndef CSVREADER_H
#define CSVREADER_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class CSVReader
{
public:
    CSVReader(const std::string& input_path, int size_of_per_line): file_path_(input_path), size_of_per_line_(size_of_per_line), lines_(0) {
    }

    ~CSVReader() = default;

    bool read() {
        ifs_.open(file_path_.c_str(), std::ios::in);
        if(ifs_.is_open()){
            std::string temp_str;
            std::vector<double> temp_vec;
            while(getline(ifs_,temp_str)){
                temp_vec.clear();
                stringToVec(temp_str, size_of_per_line_,temp_vec);
                this->data_.push_back(temp_vec);

                ++lines_;
            }

            std::cout << "read files finished, lines " << lines_ << std::endl;
        }
        else{
            std::cerr << "file: " << file_path_ << " open failed " << std::endl;
            return false;
        }

        ifs_.close();

        return true;
    }

    std::vector<std::vector<double>>& getAllData() {
        return this->data_;
    }

    size_t getAllLinesSize() {
        return lines_;
    }

    void stringToVec(std::string &temp_str, int size_of_per_line, std::vector<double>& temp_v) {

        std::stringstream tmp_ss(temp_str);
        temp_v.clear();

        std::string tmp_s;
        int cnt = 0;
        while(std::getline(tmp_ss, tmp_s, ',') && cnt < size_of_per_line) {
            temp_v.push_back(std::stod(tmp_s));
            cnt++;
        }

    }

    void display(){
        std::cout << "\n\ndisplay function\n\n ";

        for(int i = 0; i < lines_; i++){
            for(int j = 0; j < size_of_per_line_; j++){
                std::cout << data_[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:

    std::string file_path_;
    std::vector<std::vector<double>>  data_;
    std::ifstream ifs_;
    int size_of_per_line_;
    size_t lines_;

};

#endif // CSVREADER_H

int main() {
    CSVReader ios("/home/mi/csvw.csv", 8);   // 读取前八个数据
    ios.read();
    ios.display();
}