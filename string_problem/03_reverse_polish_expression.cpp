//
// Created by LAB540 on 2019/8/27.
//

#include <vector>
#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

template<typename T>
class Stack {
public:
	void pop() {
		if (empty())
			return ;
		data.pop_back();
		--topstack;
	}
	const T& top() {
		return data[topstack];
	}
	void push(const T& item) {
		data.push_back(item);
		++topstack;
	}
	bool empty() {
		return topstack == -1 ? true : false;
	}

private:
	vector<T> data;
	int topstack = -1;
};

long str_to_num(const string& s) {  //字符串转长整形
	istringstream str(s);
	long num;
	str >> num;
	return num;
}

//把输入的字符串整理一下，放入到vector中
// 数字直接取出，负号去掉括号
// 运算符直接取出
// 如果其他指定优先级的括号，先保留
void expression(vector<string> &vec ,const string& s){
	string num;
	bool neg = false;               //判定是否负数
	for (auto iter = s.begin(); iter != s.end(); ) {

	    //操作数数字
		if (*iter >= '0' && *iter<='9') {
			num += *iter;
			++iter;
		}
		//加减乘除操作
		else if (*iter == '+' || *iter == '-' || *iter == '*' || *iter == '/') {
			if (num.size() != 0)
				vec.push_back(num);
			num = *iter;
			vec.push_back(num);
			num = "";//清空
			++iter;
		}
		//
		else if (*iter == '(') {                  //处理负数情况
			if (num.size() != 0) {
				vec.push_back(num);
				num = "";
			}
			if (*(++iter) == '-') {
				neg = true;
				num += '-';
				++iter;
			}
			else
				vec.push_back("(");
		}
		else if (*iter == ')') {
			if (num.size() != 0) {
				vec.push_back(num);
				if (!neg)
					vec.push_back(")");
				num = "";
				++iter;
			}
		}
		else ++iter;
	}
	if (num.size() != 0)
		vec.push_back(num);
}

/*
 * 中序表达式转换为 后序表达式
 * 输入 vec 中序
 * 输出 p_vec 后序
 *
 * （1）对于操作数和左括号“（”，直接放入栈中
 * （2）对于操作符“+”、“-”，弹出栈内元素直至栈为空或者遇到“（”，           将操作符放入栈中
 *  (3) 对于操作符“*”、“/”，弹出栈内元素直至栈为空或者遇到“+”、“-”、“（”， 将操作符放入栈中
 *  （4）对于右括号“）”，弹出栈内元素直至遇到左括号“（”
*/
void postfix_exp(vector<string> &p_vec, vector<string> &vec) {
	stack<string> sta;
	//对于每一个操作符 操作数处理
	for (auto &oper : vec) {
		if (oper == "+" || oper == "-") {                    //对于加号和减号
			while (true) {
				if (sta.empty() || sta.top() == "(")
					break;
				p_vec.push_back(sta.top());
				sta.pop();
			}
			sta.push(oper);
		}

		else if (oper == "*" || oper == "/") {                //对于乘号和除号
			while (true) {
				if (sta.empty() || sta.top() == "+" ||
					sta.top() == "-" || sta.top() == "(")
					break;
				p_vec.push_back(sta.top());
				sta.pop();
			}
		    sta.push(oper);
		}
		else if (oper == ")") {                                  //对于右括号
			while (true) {
				if (sta.top() == "(") {
					sta.pop();
					break;
				}
				p_vec.push_back(sta.top());
				sta.pop();
			}
		}
		else sta.push(oper);
	}
	while (!sta.empty()) {
		p_vec.push_back(sta.top());
		sta.pop();
	}
	cout << "The postfix-expression is : ";
	for (auto &row : p_vec)
		cout << row<<" ";
	cout << endl;
}

/*
 * 对后缀表达式进行运算
 *
 */
const long count(vector<string> &vec) {
	stack<long> sta;
	for (auto &oper : vec) {
		long lhs = 0, rhs = 0;
		if (oper=="+") {
			rhs = sta.top();
			sta.pop();
			lhs = sta.top();
			sta.pop();
			sta.push(lhs + rhs);
		}
		else if (oper == "-") {
			rhs = sta.top();
			sta.pop();
			lhs = sta.top();
			sta.pop();
			sta.push(lhs - rhs);
		}
		else if (oper == "*") {
			rhs = sta.top();
			sta.pop();
			lhs = sta.top();
			sta.pop();
			sta.push(lhs * rhs);
		}
		else if (oper == "/") {
			rhs = sta.top();
			sta.pop();
			lhs = sta.top();
			sta.pop();
			sta.push(lhs / rhs);
		}
		else
			sta.push(str_to_num(oper)); //操作数 放入栈中
	}
	if (!sta.empty())
		return sta.top();
	else
		return 0;
}

int main() {

		string str{"3 + (2 + 1) + (-4) * (-5) + 1"};
//		cin >> str;
//		if (str == "q")
//			break;
		vector<string> exp;
		vector<string> p_exp;
		expression(exp, str);
		cout << "the input string: " << str << endl;
		cout << "the exp string: " ;
		for(auto exp_i:exp)
		  cout << exp_i << " ";
		cout << endl;
		postfix_exp(p_exp, exp);
		cout << "The result is : " << count(p_exp) <<"."<< endl<<endl;

}
