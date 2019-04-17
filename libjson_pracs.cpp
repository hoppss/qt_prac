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

int main(int argc, char *argv[])
{
        readStrJson();
        cout << "___________\n";

        readStrProJson();

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
        Json::Value value;

        if (reader.parse(strValue, value))
        {
                string out = value["name"].asString();
                cout << out << endl;
                const Json::Value arrayObj = value["array"];
                for (unsigned int i = 0; i < arrayObj.size(); i++)
                {
                        if (!arrayObj[i].isMember("cpp"))
                                continue;
                        out = arrayObj[i]["cpp"].asString();
                        cout << out;
                        if (i != (arrayObj.size() - 1))

                                cout << endl;

                }
        }

}
