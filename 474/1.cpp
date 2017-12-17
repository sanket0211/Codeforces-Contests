#include <bits/stdc++.h>
using namespace std;

string s,dir,t="qwertyuiopasdfghjkl;zxcvbnm,./";
int i,p;

main(){
	cin>>dir;
	if(dir=="L")p=1;
	else p=-1;
	cin>>s;
	for(i=0; i<s.size(); i++)
		cout<<t[t.find(s[i])+p];
}