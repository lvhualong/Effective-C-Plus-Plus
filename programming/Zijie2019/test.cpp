
#include <iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> sum(vector<int> a, vector<int> b){
    stack<int> sumStack;
    vector<int> sum;
    unsigned int  aLength = a.size();
    unsigned int  bLength = b.size();
    while(aLength-- ||  bLength--)
    {

        sumStack.push(a.front()+b.front());
        cout << sumStack.top() << " ";

    }
    for(int i=0; i< sumStack.size(); i++) {
        sum.push_back(sumStack.top());
        sumStack.pop();
    }

    return sum;
}
int main() {
    vector<int> a{1,2,3};
    vector<int> b{2,0};
    vector<int> sum_value;
    sum_value = sum(a,b);
    cout << "Hello World!" << endl;
    for(auto value:sum_value)
        cout << value << " ";


    return 0;
}