#include <chrono>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

namespace
{
constexpr char OperatorType[] = {'+', '-', '*', '/'};
struct ArithmeticNumber
{
    int first = 0;
    int second = 1;
};

ArithmeticNumber GenerateArithmeticNumber(){
    ArithmeticNumber number;
    number.first = 1 + std::rand() % 99;
    number.second = 1 + std::rand() % 99;
    return number;
}

int GenerateIntegerAddition(ArithmeticNumber &number){
    while (number.first + number.second >= 100) {
        number = GenerateArithmeticNumber();
    }
    return number.first + number.second;
}

int GenerateIntegerSubtraction(ArithmeticNumber &number)
{
    while (number.first < number.second) {
        number = GenerateArithmeticNumber();
    }
    return number.first - number.second;
}

int GenerateIntegerMultiplication(ArithmeticNumber &number)
{
    while (number.first * number.second >= 100) {
        number = GenerateArithmeticNumber();
    }
    return number.first * number.second;
}

int GenerateIntegerDivision(ArithmeticNumber &number)
{
    while (number.first % number.second != 0) {
        number = GenerateArithmeticNumber();
    }
    return number.first / number.second;
}

} // namespace

int main()
{
    // 1. Program prompt message
    std::cout << "---Program prompt message---" << std::endl;
    std::cout << "This is a 100 less than the basic arithmetic problems test program." << std::endl;
    std::cout << "Before you start testing, please set the number and difficulty of the arithmetic problems first." << std::endl;

    // 2. Input the number of the arithmetic problems
    std::cout << "Please input the number of the arithmetic problems: (0~50)" << std::endl;
    int problem_number = 0;
    while (std::cin >> problem_number && (problem_number <= 0 || problem_number > 50)) {
        std::cout << "Illegal input, please input again!" << std::endl;
    }
    std::cout << "Set the number arithmetic problems: " << problem_number << std::endl;

    // 3. Input the difficulty of the arithmetic problems
    std::cout << "Please input the difficulty of the arithmetic problems: " << std::endl;
    std::cout << "1 is easy" << std::endl;
    std::cout << "2 is difficult" << std::endl;
    int problem_difficulty = 1;
    while (std::cin >> problem_difficulty && (problem_difficulty != 1 && problem_difficulty != 2)) {
        std::cout << "Illegal input, please input again!" << std::endl;
    }
    std::cout << "Set the difficulty arithmetic problems: " << (problem_difficulty == 1 ? "easy" : "difficult") << std::endl;
    std::cout << "Start Test" << std::endl;

    std::srand(666);
    int correct_answer_count = 0;
    std::vector<std::string> right_expressions;
    std::vector<double> compute_times;
    for (int i = 1; i <= problem_number; ++i) {
        std::cout << "Test " << i << std::endl;
        // 4. Determined arithmetic type [+ - * /]
        int arithmetic_type = 0;
        if (1 == problem_difficulty) {
            arithmetic_type = std::rand() % 2; // + or -
        }
        else {
            arithmetic_type = std::rand() % 4; // + or - or * or /
        }

        // 5. Determined arithmetic number
        ArithmeticNumber arithmetic_num = GenerateArithmeticNumber();
        int target_result = 0;

        switch (arithmetic_type) {
        case 0:
            target_result = GenerateIntegerAddition(arithmetic_num);
            break;
        case 1:
            target_result = GenerateIntegerSubtraction(arithmetic_num);
            break;
        case 2:
            target_result = GenerateIntegerMultiplication(arithmetic_num);
            break;
        case 3:
            target_result = GenerateIntegerDivision(arithmetic_num);
            break;

        default:
            std::cout << "Illegal arithmetic type!" << std::endl;
            return 1;
        }

        std::ostringstream expression;
        expression << arithmetic_num.first << " "
                   << OperatorType[arithmetic_type] << " "
                   << arithmetic_num.second << " = ";
        std::cout << expression.str() << std::endl;
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();

        // 5. User input the arithmetic result
        int user_result = 0;
        std::cin >> user_result;
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        std::chrono::duration<double> time_span = (end_time - start_time);
        compute_times.emplace_back(time_span.count());
        if (user_result == target_result) {
            correct_answer_count++;
        } else {
            expression << target_result;
            right_expressions.emplace_back(expression.str());
        }
    }
    std::cout << "Correct answer rate: " << correct_answer_count << "/" << problem_number << std::endl;
    std::cout << "Score: " << static_cast<double>(correct_answer_count) / static_cast<double>(problem_number) * 100 << std::endl;
    if (!right_expressions.empty()) {
        std::cout << "Correct answers:" << std::endl;
    }
    for (const auto &expression : right_expressions) {
        std::cout << expression << std::endl;
    }

    // User time statistics
    double total_time = 0;
    double mean_time = 0;
    double min_time = std::numeric_limits<float>::max();

    for (const auto &time : compute_times) {
        total_time += time;
        if (time < min_time) {
            min_time = time;
        }
    }
    std::cout << "Accumulate time:" << total_time << std::endl;
    std::cout << "Mean time:" << total_time / problem_number << std::endl;
    std::cout << "Min time:" << min_time << std::endl;

    return 0;
}