#include <bits/stdc++.h>
using namespace std;

struct job{
	int id;
	int dead;
	int profit;
};

bool cmp(job a, job b){
	return a.profit > b.profit;
}

bool cid(job a, job b){
	return a.id < b.id;
}

int main(){
	int n;
	cin>>n;
	vector<job> v(n);
	for(int i=0;i<n;i++){
		int id,de,pr;
		cin>>id>>de>>pr;
		v[i].id = id;
		v[i].dead = de;
		v[i].profit = pr;
	}
	int deadsize = 0;
	for(int i=0;i<n;i++){
		deadsize = max(deadsize, v[i].dead);
	}
	deadsize++;
	int slot[deadsize] = {0};
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n;i++){
		for(int j=v[i].dead;j>=1;j--){
			if(slot[j] == 0){
				slot[j] = v[i].id;
				break;
			}
		}
	}
	sort(v.begin(),v.end(),cid);
	int ct = 0;
	int pro = 0;
	for(int i=1;i<deadsize;i++){
		if(slot[i] != 0){
			ct++;
			pro += v[slot[i] - 1].profit;
		}
	}
	for(int i=0;i<deadsize;i++){
		cout<<slot[i]<<" ";
	}
	cout<<endl;
	cout<<ct<<" "<<pro;
	return 0;
}
/*
Input:
17
1 56 288
2 27 435
3 67 401
4 64 368
5 94 248
6 54 361
7 43 108
8 96 167
9 73 251
10 96 170
11 14 156
12 78 184
13 61 370
14 77 424
15 68 397
16 40 375
17 36 218

Output:
17 4921
*/