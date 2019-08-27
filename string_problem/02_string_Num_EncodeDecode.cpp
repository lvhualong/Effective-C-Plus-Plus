

/*
 * 输入一个火星文编码的数字1~99，十位在左，个位，
 * 需要你对数组重新组合，输出一个尽可能小的火星文
 *
 * 测试用例
 *
 * 输入： VI
 * 输出： IV
 *
 * 输入： LXI
 * 输出： LIX
 */
#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<string>  ones{"I", "II", "III","IV","V","VI","VII","VIII", "IX"};
vector<string>  tens{"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};


void change_ten(string one, string ten, string result)
{
   if(one == "I")
   {
     cout << ten;
      if(ten=="XX" || ten=="XXX" || ten=="LX" || ten=="LXX" || ten=="LXXX")
      {
        ten = ten.erase('X');
        one = "IX";
      }
      result =  ten+one;
      if(ten == "X")
        result = "IX";

      cout << result << endl;
   }
}

void change_one( string result)
{
   if(result == "VI")
   {
     result == "IV";
   }

   cout << result << endl;
}

bool  findOneAndTen(string& input, string& one, string& ten)
{

   for(int i=tens.size()-1;i>=0; i--)
   {
     //find ten
     if(input.find(tens[i]) != -1)
     {
       int pos = input.find(tens[i]);
       ten = tens[i];
       string temp_input = input;
       temp_input = temp_input.erase(pos, ten.size());
       //find one
       for(int j=ones.size()-1;j>=0; j--)
       {
         if(temp_input == ones[j])
         {
           one = ones[j];
//           cout << "one:" <<  one <<endl;
//           cout << "input" << input << "ten+one "<< ten+one << endl;
         change_ten(one, ten, input);
         }
       }



     }
   }
  return  false;
}




int main()
{
  string input ;//= "XXXI";
  cin >> input;
  if(input.empty())
    return false;
  string one;
  string ten;
  //先判断是否有十位
  if(input.front() == 'X' || input.front()=='L') {
    findOneAndTen(input, one, ten);

  }
  else
    change_one(input);




    return 0;
}


