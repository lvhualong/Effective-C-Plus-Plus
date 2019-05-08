
#include <iostream>
#include <vector>

using namespace std;

void gift(unsigned int gift_num, unsigned int child_k,int cur_gift, int cur_k, vector<int>& out, vector<vector<int>>& res){
    if(cur_k==child_k){
        int num = gift_num - cur_gift;
        out.push_back(num);
        res.push_back(out);
        out.pop_back();
        return;
    }

    for (int i = cur_gift; i <= gift_num; ++i) {
        int num = i - cur_gift;
        out.push_back(num);
        gift(gift_num,child_k,i,cur_k+1,out,res);
        out.pop_back();
    }
}

int main(){
    unsigned int n,k;
    cin>>n>>k;
    vector<vector<int>> res;
    vector<int> out;
    gift(n,k,0,1,out,res);

    for (auto& subres:res){
        for (int i = 0; i < subres.size(); ++i) {
            for (int j = 0; j <subres[i] ; ++j) {
                cout<<"*";
            }
            if(i!=subres.size()-1){
                cout<<'|';
            }
        }
        cout<<endl;
    }

    return 0;
}