#include "csvreader.h"

CSVReader::CSVReader(string input_path, int size_of_line)
{
    this->size_of_line = size_of_line;
    this->all_line_size = 0;

    read_f.open(input_path,ios::in);
    if(read_f.is_open()){

        while(getline(read_f,temp_str)){
            temp_vec.clear();
            stringToVec(temp_str, size_of_line,temp_vec);
            this->data.push_back(temp_vec);

            ++all_line_size;
        }

        cout << "read files finished" << endl;
    }
    else{
        std::cerr << "file: " << input_path << " open failed " << endl;
    }
}


void CSVReader::stringToVec(string &temp_str, int size_of_line, vector<double>& temp_v){
    std::stringstream tmp_ss(temp_str);
    temp_v.clear();

    std::string tmp_s;
    int cnt = 0;
    while(std::getline(tmp_ss, tmp_s, ',') && cnt < size_of_line) {
        temp_v.push_back(std::stod(tmp_s));
        cnt++;
    }

}

long  CSVReader::getAllLineSize(){
    return this->all_line_size;
}

void CSVReader::getNLineDate(int line, vector<double>& result){
    result = this->data[line];
}

vector<vector<double>>& CSVReader::getAllData(){
    return this->data;
}

void CSVReader::display(){
    cout << "\n\ndisplay function\n\n ";

    for(int i = 0; i < all_line_size; i++){
        for(int j = 0; j < size_of_line; j++){
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

void CSVReader::processdata(int position, double coeffi){
    for(int i = 0; i < this->all_line_size; i++){
        std::cout << "original " << this->data[i][position] << " | new " <<this->data[i][position]* coeffi ;
    }
    cout << endl << endl << endl;

    for(int j = 0; j < this->all_line_size; ++j){
        this->data[j][position] = this->data[j][position] * coeffi;
    }
};
void CSVReader::saveToFile(string newName){
    ofstream out(newName,ios::out);

    if(out.fail()){
        std::cerr << "ofstream failed " << std::endl;
        return;
    }

    for(int i = 0; i < this->all_line_size; ++i){
        for(int j = 0; j < this->size_of_line; ++j){
            out << data[i][j] << ",";
        }
        out << 0.0 << "," << 0.0 << "," << 0.0 << "," << 0.0 << "," << std::endl; // a line is standard 34 data
    }
    out.close();

};
