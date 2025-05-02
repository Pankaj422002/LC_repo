// infix_expression.cpp
#include<bits/stdc++.h>

using namespace std;

int operation(int a, int b, char ch){
	if(ch=='+')return a+b;
	if(ch=='-')return a-b;
	if(ch=='*')return a*b;
	if(ch=='/')return a/b;
	if(ch=='^')return a^b;
}

unordered_map<char, int> priority = {
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2}
};

int evaluateInfix(string str){
	stack<char> s1;
	stack<char> s2;

	int n=str.length();
	for(int i=n-1;i>=0;i--){
		char ch = str[i];

		if(ch>='0' and ch<='9')s1.push(ch);
		else{
			if(ch=='(')s2.push(ch);
			else if(ch==')'){
				while(s2.top()!='('){
					char curr_op = s2.top();s2.pop();
					char first=s1.top();s1.pop();
					char second=s1.top();s1.pop();

					int temp = operation(second-'0',first-'0',curr_op);
					s1.push('0'+temp);
				}
			}else{
				if(s2.empty() or (!s2.empty() and priority[ch]>=priority[s2.top()])){
					s2.push(ch);
				}else{
					while(!s2.empty() and (s2.top()!='(' and priority[s2.top()]>priority[ch])){
						char curr_op = s2.top();s2.pop();
						char first=s1.top();s1.pop();
						char second=s1.top();s1.pop();

						int temp = operation(second-'0',first-'0',curr_op);
						s1.push('0'+temp);
					}
					s2.push(ch);
				}
			}
		}
	}

	while(!s2.empty()){
		char curr_op = s2.top();s2.pop();
		char first=s1.top();s1.pop();
		char second=s1.top();s1.pop();

		int temp = operation(first-'0', second-'0',curr_op);
		s1.push('0'+temp);
	}
	return s1.top()-'0';
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif
	string str; cin >> str;

	cout << evaluateInfix(str) << endl;

	return 0;
}