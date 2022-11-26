
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctype.h>
#include <algorithm>

namespace
{

class BigNumber
{

public:
  BigNumber(){};
  BigNumber(std::string input_string, int decimal);

  bool Initialize();
  void DecimalConvert(int output_decimal);
  int length() { return value_.size(); }
  int sign() { return is_negative_ ? -1 : 1; }
  int decimal() { return decimal_; }
  void set_negative() { is_negative_ = true; }
  void set_input_string(const std::string & str) { input_string_ = str; }
  void set_value(const std::vector<int> & value) { value_ = value; }
  std::vector<int> value() { return value_; }

private:
  bool is_valid_char(char char_num);

  std::string input_string_;
  bool is_initialized_ = false;
  bool is_negative_ = false;
  int decimal_ = 10;
  std::vector<int> value_;
};

void PromptSummaryInfo()
{
  std::cout << "Input invalid!" << std::endl;
  std::cout << "Please input an InputFile path, such as input_file.txt" << std::endl;
  std::cout << "Please input an scale of input number, default is 10" << std::endl;
  std::cout << "Please input an scale of output number, default is 10" << std::endl;
}

int char2value(char char_num)
{
  if (std::islower(char_num) || std::isupper(char_num))
  {
    char_num = std::tolower(char_num);
    return (char_num - 'a' + 10);
  }
  else
  {
    return std::stoi(&char_num);
  }
}

char value2char(int value_num)
{
  int abs_value = std::abs(value_num);
  if (abs_value < 10)
  {
    return std::to_string(abs_value).front();
  }
  else
  {
    return 'a' + abs_value - 10;
  }
}

bool Comperation(BigNumber &num_a, BigNumber &num_b) {
  std::vector<int> num_a_value = num_a.value();
  std::vector<int> num_b_value = num_b.value();
  if (num_a_value.size() > num_b_value.size()) {
    return true;
  } else if (num_a_value.size() == num_b_value.size()) {
     for(int i = 0; i < num_b_value.size(); ++i) {
       if (std::abs(num_a_value.at(i)) != std::abs(num_b_value.at(i))) {
         return std::abs(num_a_value.at(i)) >  std::abs(num_b_value.at(i));
       }
     }
     return num_a_value.front() > num_b_value.front();
  } else {
    return false;
  }
}

BigNumber Addition(BigNumber &num_a, BigNumber &num_b)
{
  BigNumber result;
  std::vector<int> temp_value;
  std::string temp_string;
  int decimal = num_a.decimal();
  int length = (num_a.length() > num_b.length() ? num_a.length() : num_b.length());
  int result_sign = Comperation(num_a, num_b) ? num_a.sign() : num_b.sign();

  std::vector<int> num_a_value = num_a.value();
  std::vector<int> num_b_value = num_b.value();

  std::vector<int>::reverse_iterator a_ptr = num_a_value.rbegin();
  std::vector<int>::reverse_iterator b_ptr = num_b_value.rbegin();
  int carry_flag = 0;
  int a_value = 0;
  int b_value = 0;
  for (int i = 0; i < length; ++i)
  {
    if (a_ptr < num_a_value.rend()) {
      a_value = *(a_ptr++);
    } else{
      a_value = 0;
    }
    if (b_ptr < num_b_value.rend()) {
      b_value = *(b_ptr++);
    } else {
      b_value = 0;
    }
    int temp = a_value + b_value + carry_flag;
    // 同号运算
    if (num_a.sign() * num_b.sign() > 0) {
      if (temp >= decimal) {
        carry_flag = 1;
        temp_value.emplace_back(temp - decimal);
      } else if (temp <= decimal * (-1)) {
        carry_flag = -1;
        temp_value.emplace_back(temp + decimal);
      } else {
        carry_flag = 0;
        temp_value.emplace_back(temp);
      }
    } else {
      if (result_sign * temp >= 0) {
        temp_value.emplace_back(temp);
      } else {
        temp_value.emplace_back(temp + decimal * result_sign);
        carry_flag = -1 * result_sign;
      }
    }
  }
  if (carry_flag == result_sign) {
    temp_value.emplace_back(carry_flag);
  }
  if (temp_value.back() == 0) {
    temp_value.pop_back();
  }
  std::reverse(temp_value.begin(), temp_value.end());
  result.set_value(temp_value);
  if (temp_value.front() < 0 ) {
    result.set_negative();
    temp_string.push_back('-');
  }
  for (const auto& result_i : temp_value) {
    std::cout << " " << result_i;
    temp_string.push_back(value2char(result_i));
  }
  result.set_input_string(temp_string);
  std::cout << std::endl;
  std::cout << "result: " << temp_string << std::endl;
  return result;
}

BigNumber::BigNumber(std::string input_string, int decimal)
    : input_string_(input_string), decimal_(decimal) {}

bool BigNumber::Initialize()
{
  if (input_string_.empty())
  {
    return false;
  }
  char first_char = input_string_.front();
  if (first_char == '-')
  {
    is_negative_ = true;
  }
  else if (first_char == '+' || first_char == '0')
  {
    is_negative_ = false;
  }
  else if (is_valid_char(first_char))
  {
    value_.emplace_back(char2value(first_char) * sign());
  }
  else
  {
    std::cout << "first char number is invalid!" << std::endl;
    return false;
  }

  for (int i = 1; i < input_string_.size(); ++i)
  {
    if (is_valid_char(input_string_[i]))
    {
      value_.emplace_back(char2value(input_string_[i]) * sign());
    }
    else
    {
      std::cout << "invalid number in position " << i << std::endl;
      return false;
    }
  }
  std::cout << "input value: " << input_string_ << std::endl;
  for(const auto& tmp : value_) {
    std::cout << " " << tmp;
  }
  std::cout << std::endl;
  return true;
}

void BigNumber::DecimalConvert(int output_decimal) {
  std::vector<int> temp_value;
  int carry_flag = 0;
  for (auto iter = value_.rbegin(); iter < value_.rend(); ++iter) {
    if (*iter * sign() + carry_flag < output_decimal) {
      temp_value.emplace_back(*iter);
      carry_flag = 0;
    } else {
      temp_value.emplace_back(*iter - sign() * output_decimal);
      carry_flag = 1;
    }
  }
  if (carry_flag) {
    temp_value.emplace_back(carry_flag * sign());
  }
  if (temp_value.size() && temp_value.back() == 0) {
    temp_value.pop_back();
  }
  std::reverse(temp_value.begin(), temp_value.end());
  value_ = temp_value;
  decimal_ = output_decimal;
  input_string_.clear();
  if (is_negative_) {
    input_string_.push_back('-');
  }
  for (const auto& result_i : temp_value) {
    // std::cout << " " << result_i;
    input_string_.push_back(value2char(result_i));
  }
  // std::cout << "result decimal: " << decimal_ << std::endl;
  // std::cout << "result value: " << input_string_ << std::endl;
}

bool BigNumber::is_valid_char(char char_num)
{
  if (!std::isalnum(char_num))
  {
    return false;
  }
  if (std::islower(char_num) || std::isupper(char_num))
  {
    char_num = std::tolower(char_num);
    return decimal_ > (char_num - 'a' + 10);
  }
  else
  {
    return decimal_ > (std::stoi(&char_num));
  }
}

} // namespace

int main(int argc, char *argv[])
{
  // 1. input args check
  if (argc < 2)
  {
    PromptSummaryInfo();
    return 1;
  }
  int input_decimal = 10;
  int output_decimal = 10;
  if (argc >= 3 && std::stoi(argv[2]))
  {
    input_decimal = std::stoi(argv[2]);
    if (input_decimal <= 1 || input_decimal > 36)
    {
      std::cout << "input decimal is invalid, please input 2~36" << std::endl;
      return 2;
    }
  }
  if (argc >= 4 && std::stoi(argv[3]))
  {
    output_decimal = std::stoi(argv[3]);
    if (output_decimal <= 1 || output_decimal > 36)
    {
      std::cout << "output decimal is invalid, please input 2~36" << std::endl;
      return 3;
    }
  } else {
    output_decimal = input_decimal;
  }
  std::cout << "Input file" << argv[1] << std::endl;
  std::cout << "Input decimal: " << input_decimal << std::endl;
  std::cout << "Output decimal: " << output_decimal << std::endl;

  // 2. read input file
  std::vector<std::string> input_big_number;
  std::ifstream input_file(argv[1]);
  if (input_file)
  {
    std::string line;
    while (getline(input_file, line))
    {
      input_big_number.emplace_back(line);
    }
  }
  else
  {
    std::cout << "open file failed, please check file path again!" << std::endl;
    return 4;
  }
  if (input_big_number.size() < 2)
  {
    std::cout << "input file should contain two numbers!" << std::endl;
    return 5;
  }

  auto first_number = BigNumber(input_big_number[0], input_decimal);
  auto second_number = BigNumber(input_big_number[1], input_decimal);

  if (first_number.Initialize() && second_number.Initialize()) {
    std::cout << "Init succeed!" << std::endl;
    BigNumber result = Addition(first_number, second_number);
    if (output_decimal != input_decimal) {
    result.DecimalConvert(output_decimal);
    }
  } else {
    std::cout << "Big number initialized failed!" << std::endl;
    return 6;
  }

  return 0;
}