#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void gen_key_secret(std::vector<int> &secret)
{
    while (secret.size() < 4)
    {
        int random_num = 1 + std::rand() % 9;
        auto iter = std::find(secret.begin(), secret.end(), random_num);
        if (iter == secret.end())
        {
            secret.push_back(random_num);
        }
    }
}

int main(int argc, char *argv[])
{
    std::ofstream output_file("key_secret_2.txt");
    std::string temp;
    std::stringstream ss;
    for (int i = 255; i > 0; --i)
    {
        ss << i << " ";
    }
    output_file.write(ss.str().c_str(), ss.str().size());
}