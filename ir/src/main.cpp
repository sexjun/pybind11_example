#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include "flatbuffers/flatbuffers.h"
#include "cds_generated.h"

using namespace std;

string filePath = "./results.bin";

void serialization_data(string user_name, uint8_t user_age)
{
    flatbuffers::FlatBufferBuilder builder;
    auto name = builder.CreateString(user_name);
    dshengChen::Son son(0.1, 0.2, 0.3);
    auto m = dshengChen::CreateMonster(builder, &son, name, user_age, dshengChen::Color_Green);
    builder.Finish(m);
    // 获取 FlatBuffer 数据指针和大小
    const uint8_t *buffer = builder.GetBufferPointer();
    size_t size = builder.GetSize();
    std::ofstream outfile(filePath, std::ios::binary);
    std::vector<char> data(size);
    std::memcpy(data.data(), buffer, size);
    outfile.write(data.data(), size);
    outfile.close();
}

void deserialization_data()
{
    ifstream in_file(filePath, std::ios::binary);
    if (in_file.is_open())
    {
        in_file.seekg(0, std::ios::end);
        std::streamsize fileSize = in_file.tellg();
        in_file.seekg(0, std::ios::beg);
        // 读取文件内容到缓冲区
        std::vector<char> buffer(fileSize);
        in_file.read(buffer.data(), fileSize);
        using namespace dshengChen;
        auto parsed_person = GetMonster(buffer.data());
        int age = parsed_person->age();
        Color c = parsed_person->color();
        cout << "\t age is: " << age;
        cout << "\t name is: " << parsed_person->name()->c_str();
        cout << "\t color is: " << (int)c << endl;
    }
    // 关闭文件
    in_file.close();
}

bool test_flatbuffer()
{
    serialization_data("热爱学习", 12);
    deserialization_data();
    return true;
}

int main()
{
    test_flatbuffer();
    return 0;
}
