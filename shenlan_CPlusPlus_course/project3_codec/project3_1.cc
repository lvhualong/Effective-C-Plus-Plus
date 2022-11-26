#include <chrono>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>
#include <fstream>

namespace
{

} // namespace

struct Codec
{
    Codec(const std::string &key) : key_secret(key) {}
    bool Encrypt_str(const std::string &input, std::string &output);
    bool Decrypt_str(const std::string &input, std::string &output);

  private:
    std::string key_secret;
};

bool Codec::Encrypt_str(const std::string &input, std::string &output)
{
    output.clear();
    for (const auto &char_x : input)
    {
        if (char_x >= 'a' && char_x <= 'z')
        {
            output.push_back(key_secret[char_x - 'a']);
        }
        else
        {
            output.push_back(char_x);
        }
    }
}

bool Codec::Decrypt_str(const std::string &input, std::string &output) {
    output.clear();
    for (const auto& char_x : input) {
        if (char_x >= 'a' && char_x <= 'z') {
            std::string::size_type pos = key_secret.find(char_x);
            if (pos != key_secret.npos) {
                output.push_back('a' + pos);
            }
        } else {
            output.push_back(char_x);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        std::cout << "input args error" << std::endl;
        std::cout << argv[0] << " [key_secret] [input_file] [output_file]" << std::endl;
        return 1;
    }

    std::ifstream key_file(argv[1]);
    std::string key_secret;
    key_file >> key_secret;

    std::ifstream input_file(argv[2]);
    std::ofstream output_file(argv[3]);
    std::vector<std::string> input_string;
    if (input_file)
    {
        std::string line;
        while (getline(input_file, line))
        {
            input_string.emplace_back(line);
        }
    }
    else
    {
        std::cout << "open file failed, please check file path again!" << std::endl;
        return 2;
    }

    std::cout << "key secret: " << key_secret << std::endl;
    Codec codec(key_secret);
    std::vector<std::string> output_string;
    std::cout << "---------------------- encode --------------" << std::endl;
    std::cout << "input string : " << std::endl;
    // encode
    for (const auto &string_x : input_string)
    {
        std::cout << string_x << std::endl;
        std::string temp_string;
        codec.Encrypt_str(string_x, temp_string);
        temp_string += '\n';
        output_string.push_back(temp_string);
        output_file.write(temp_string.c_str(), temp_string.size());
    }
    std::cout << "output string : " << std::endl;
    for (const auto& line : output_string) {
        std::cout << line;
    }
    std::cout << std::endl;
    input_file.close();
    output_file.close();

    // decode
    std::cout << "---------------------- decode --------------" << std::endl;
    std::ifstream encode_file(argv[3]);
    std::vector<std::string> decode_string;
    std::string line;
    std::string decode_line;
    std::cout << "input string : " << std::endl;
    while (getline(encode_file, line))
    {
        codec.Decrypt_str(line, decode_line);
        std::cout << line << std::endl;
        decode_line += '\n';
        decode_string.push_back(decode_line);
    }
    std::cout << "output string : " << std::endl;
    for (const auto& line : decode_string) {
        std::cout << line;
    }
    std::cout << std::endl;
    encode_file.close();

    return 0;
}