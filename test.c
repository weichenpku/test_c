#include<iostream>
#include<string>
#include<vector>
using namespace std;

    int max_cell(int a,int b){
        if (a<b) return max_cell(b,a);
        if (a%b==0) return b;
        return max_cell(b,a%b);
    }
    void revert(vector<int> &nums){
	if (nums.size()==0) return;
	int len=nums.size();
	int minval=nums[0];	
	int minidx=0;
	for (int i=0;i<nums.size();i++){
		if (nums[i]<minval){ minval=nums[i]; minidx=i;}	
	}
	if (minidx==0) return;
	int my_max_cell = max_cell(len,minidx);
	for (int i=0;i<my_max_cell;i++){
		int ori_pos = i;
		int current = ori_pos;
		int next = (ori_pos+minidx)%len;
		while (next!=ori_pos){
			int tmp=nums[current];
			nums[current]=nums[next];
			nums[next]=tmp;
			current=next;
			next=(current+minidx)%len;
		}
	}
    }


    void rotateString(string &str, int offset) {
        // write your code here
        if (offset==0) return;
        int len=str.length();
        int my_max_cell = max_cell(len,offset);
        for (int i=0;i<my_max_cell;i++){
            int ori_pos = i;
            int current = ori_pos;
            int next = (ori_pos+len-offset)%len;
	    bool start=false;
            while (next!=ori_pos || start==false){
		start= true;
                string tmp=str.substr(current,1);
                string tmp2=str.substr(next,1);
                str.replace(current,1,tmp2);
                str.replace(next,1,tmp);
		cout<<str<<endl;
                current=next;
                next=(next+len-offset)%len;
            }
        }
    }

	vector <string> f(int n){
		vector<string> dict;
		string digit="0";
		string fizz="fizz";
		string buzz="buzz";
		string fizzbuzz="fizz buzz";
		dict.insert(dict.end(),digit);
		dict.insert(dict.end(),digit);
		dict.insert(dict.end(),fizz);
		dict.insert(dict.end(),digit);
		dict.insert(dict.end(),buzz);
		dict.insert(dict.end(),fizz);
		dict.insert(dict.end(),digit);
		dict.insert(dict.end(),digit);
		dict.insert(dict.end(),fizz);
		dict.insert(dict.end(),buzz);
		dict.insert(dict.end(),digit);
		dict.insert(dict.end(),fizz);
		dict.insert(dict.end(),digit);
		dict.insert(dict.end(),digit);
		dict.insert(dict.end(),fizzbuzz);
		return dict;
	
			
	}
int main(){
	string str("abcdefg");
	//cout<<str<<endl;
	rotateString(str,3);
	//cout<<str<<endl;

	vector<string> strf=f(3);
	//for (int i=1;i<14;i++) {cout<<strf[i]<<endl;}

	vector <int> nums;
	nums.insert(nums.end(),4);
	nums.insert(nums.end(),5);
	nums.insert(nums.end(),1);
	nums.insert(nums.end(),2);
	nums.insert(nums.end(),3);
	revert(nums);
	for (int i=0;i<nums.size();i++){ cout<<nums[i]<<endl;}
}
