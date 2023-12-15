#include <iostream>
#include <string>
#include <filesystem>

using namespace std;

int main()
{
    cout << "thk" << endl;
    std::string cmd = "flatc --version";
    int status = system(cmd.c_str());
    if (status)
    {
        cout << "error to find flatc";
    }

    std::string cpp_cmd = "flatc --cpp -o output ";
    std::filesystem::path ir_path = std::filesystem::current_path().append("schema/example.fbs");
    cpp_cmd += ir_path.string();
    cout << "execute cmd: " << cpp_cmd;
    // system(cpp_cmd.c_str());
    cout << "generate on : output";

    return 0;
}
