#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_vect(vector<int> vect){
	cout<<vect.size();
	for (int i=0;i<vect.size();i++) cout<<vect[i]<<" ";
	cout<<endl;
}

int main(){
	vector<int> nums={9,3,5,7,2,1,0,6,8};
	
	print_vect(nums);
}
