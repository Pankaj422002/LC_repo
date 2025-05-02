// ImplementationOfStack.cpp
#include<bits/stdc++.h>

using namespace std;

class myStack{
	vector<int> st;
public: 
	void push(int ele){
		st.push_back(ele);
	}
	void pop(){
		st.pop_back();
	}
	bool isempty(){
		return st.size()==0?true:false;
	}
	int top(){
		if(st.empty()){
			cout<<"stack is empty"<<endl;
			return -1;
		}
		return st.back();
	}
};

int main(){

#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif

	myStack s;
	s.push(1);
	s.push(21);
	s.push(11);
	s.push(13);

	while(!s.isempty()){
		cout<<s.top()<<endl;
		s.pop();
	}

	return 0;
}