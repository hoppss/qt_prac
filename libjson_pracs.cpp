#include <string>
#include "json/json.h"
//#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>

using namespace std;
#if 0
sudo apt-get install libjson-dev
/usr/include/jsoncpp
/usr/lib/x86_64_linux/libjsoncpp.so
#endif


void readStrJson(); //从字符串中读取JSON
void readStrProJson(); //从字符串中读取JSON（内容复杂些）
void jsonStr2File();

void generateJsonArray();
void array1();
void array2();
void translateArray1();
void translateArray2();

int main(int argc, char *argv[])
{
        readStrJson();
        cout << "___________\n";

        readStrProJson();
        cout << "___________\n";

        generateJsonArray();
        cout << "___________\n";


        jsonStr2File();
        cout << "___________\n";

        array1();
        array2();
        translateArray1();
        translateArray2();


        return 0;
}

//从字符串中读取JSON
void readStrJson()
{
        //字符串
  const char* str =
      "{\"praenomen\":\"Gaius\",\"nomen\":\"Julius\",\"cognomen\":\"Caezar\","
      "\"born\":100,\"update\":44}";
  /*
  //json内容如下：
  {
                "praenomen":"Gaius",
                "nomen":"Julius",
                "cognomen":"Caezar",
                "born":-100,
                "died":-44
        }
  */
  Json::Reader reader;
  Json::Value root;

  //从字符串中读取数据
  if(reader.parse(str,root))
  {
      string praenomen = root["praenomen"].asString();
      std::cout << "root[\"praenomen\"]" << praenomen << std::endl;

      string nomen = root["nomen"].asString();
      std::cout << "root[\"nomen\"]" << nomen << std::endl;

      string cognomen = root["cognomen"].asString();
      std::cout << "root[\"cognomen\"]" << cognomen << std::endl;

      int born = root["born"].asInt();
      std::cout << "root[\"born\"]" << born << std::endl;

      int died = root["update"].asInt();
      std::cout << "root[\"update\"]" << died << std::endl;

      cout << praenomen + " " + nomen + " " + cognomen
           << " was born in year " << born
           << ", died in year " << died << endl;
  }

  // json write to cpp
  Json::StyledWriter sw;
  std::string strr = sw.write(root);

  std::cout <<"\n\n json write to string : \n" << strr << std::endl;

}


//从字符串中读取JSON（内容复杂）
void readStrProJson()
{
        string strValue = "{\"name\":\"json\",\"array\":[{\"cpp\":\"jsoncpp\"},{\"java\":\"jsoninjava\"},{\"php\":\"support\"}]}";
        /*
        //json内容如下：
        {
    "name": "json″,
    "array": [
        {
            "cpp": "jsoncpp"
        },
        {
            "java": "jsoninjava"
        },
        {
            "php": "support"
        }
    ]
        }
        */

        Json::Reader reader;
        //    Json::Reader *readerinfo = new Json::Reader(Json::Features::strictMode());

        Json::Value value;

        if (reader.parse(strValue, value))
        {
                string out = value["name"].asString();
                cout << out << endl;
                const Json::Value arrayObj = value["array"];
                for (unsigned int i = 0; i < arrayObj.size(); i++)
                {
                        if (!arrayObj[i].isMember("cpp"))   //"cpp" is a key
                                continue;
                        out = arrayObj[i]["cpp"].asString();
                        cout << out;
                        if (i != (arrayObj.size() - 1))

                                cout << endl;

                }
        }
        bool isArray = value["array"].isArray();
        std::cout << "judge json element is or not array  " << (int)isArray << std::endl;
}

void generateJsonArray(){
    Json::Value root;
    root["id"]=1244235;
    root["describe"]="how SB you are";
    root["Arry"].append("123");
    root["Arry"].append("213");
    root["Arry"].append("321");
    Json::StyledWriter sw;
    std::string res_str = sw.write(root);
    std::cout << "json array : \n" << res_str << std::endl;

    bool isArray = root["Arry"].isArray();
    std::cout << "judge json element is or not array  " << (int)isArray << std::endl;
};

void jsonStr2File(){
    Json::Value root;
    root["name"] = "hopps";
    root["age"] = 18;
    root["gende"] = "male";
    cout << endl << root << endl;

    Json::StyledWriter writer;
    ofstream os;
    os << writer.write(root);
    os.close();

    bool isArray = root.isArray();  // flase
    std::cout << "judge json element is or not array  " << (int)isArray << std::endl;
}


void array1(){
    std::cout << "\n  array1 \n";

    Json::Value  arrayObj;
    for(int i=0; i<3; ++i){
        Json::Value new_item;
        new_item["id"] = i;
        new_item["name"] = "hope";
        arrayObj.append(new_item);
    }
    Json::FastWriter sw;
    std::string out = sw.write(arrayObj);
    std::cout << out << std::endl;
}
void array2(){
    std::cout << "\n  array2 \n";
    Json::Value  arrayObj;
    for(int i=0; i<3; ++i){
        Json::Value new_item;
        new_item["id"] = i;
        new_item["name"] = "hope";
        arrayObj["array"].append(new_item);
    }
    Json::FastWriter sw;
    std::string out = sw.write(arrayObj);
    std::cout << out << std::endl;

}

void translateArray2(){
    std::string  str = "{\"array\":[{\"id\":0,\"name\":\"hope\"},{\"id\":1,\"name\":\"hope\"},{\"id\":2,\"name\":\"hope\"}]}";

    Json::Reader *readerInfo = new Json::Reader(Json::Features::strictMode());
    Json::Value  root;

    if(readerInfo->parse(str,root)){
        if(root["array"].isArray()){
            int nArraySize = root["array"].size();
            for(int i=0; i<nArraySize; ++i){
                int nId = root["array"][i]["id"].asInt();
                std::string strName = root["array"][i]["name"].asString();
                std::cout << "id " << nId << " name " << strName << std::endl;

            }
        }
    }

    ::delete readerInfo;
    readerInfo = nullptr;
}

void translateArray1(){
    std::string  str = "[{\"id\":0,\"name\":\"hope\"},{\"id\":1,\"name\":\"hope\"},{\"id\":2,\"name\":\"hope\"}]";

    Json::Reader *readerInfo = new Json::Reader(Json::Features::strictMode());
    Json::Value  root;

    if(readerInfo->parse(str,root)){
        if(root.isArray()){
            int nArraySize = root.size();
            for(int i=0; i<nArraySize; ++i){
                int nId = root[i]["id"].asInt();
                std::string strName = root[i]["name"].asString();
                std::cout << "id " << nId << " name " << strName << std::endl;
            }
        }
    }

    ::delete readerInfo;
    readerInfo = nullptr;
}


