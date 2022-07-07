#ifndef CSVWRITTER_H
#define CSVWRITTER_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class CSVWritter
{
public:
  CSVWritter(const std::string & input_path)
  : file_path_(input_path)
  {
    delimiter_ = ",";
    ofs_.open(input_path.c_str(), std::ios::out | std::ios::trunc);
  }
  ~CSVWritter() = default;

  bool write(const std::vector<double> & data)
  {
    for (auto it = data.begin(); it != data.end(); ++it) {
      ofs_ << *it << delimiter_;
    }
    ofs_ << std::endl;

    ++size_of_lines;
  }

  bool save()
  {
    ofs_.close();
  }

private:
  std::string file_path_;
  std::string delimiter_;
  std::ofstream ofs_;
  size_t size_of_lines;
};

#endif // CSVWritter_H


int main()
{
  CSVWritter ofs("/home/mi/csvw.csv");

  for (int i = 0; i < 10; ++i) {
    std::vector<double> line;
    for (int j = 0; j < 8; ++j) {
      line.push_back(i + j);
    }
    ofs.write(line);
  }

  ofs.save();

  return 0;
}
