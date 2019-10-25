#ifndef CSVREADER_H
#define CSVREADER_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class CSVReader
{
public:
    CSVReader(string input_path, int size_of_line);
    ~CSVReader() = default;

    void getNLineDate(int line, vector<double>& result);
    double getNdataOfLine(vector<double> temp_vec, int n);
    vector<vector<double>>& getAllData();
    long getAllLineSize();
    void stringToVec(string &temp_str, int size_of_line, vector<double>& temp_v);
    void display();

    //position is its index from 0;
    void processdata(int position, double coeffi);
    void saveToFile(string newName);

private:

    std::string temp_str;
    std::vector<double> temp_vec;
    std::vector<std::vector<double>>  data;
    std::ifstream read_f;
    std::ofstream write_f;
    int size_of_line;
    long all_line_size;

};

#endif // CSVREADER_H
