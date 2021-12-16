#include <bits/stdc++.h>

using namespace std;

int main(){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++) cin>>a[i];

		int sz = 1<<n;
		vector<int> ans[sz];
		for(int i=0;i<sz;i++){
			vector<int> tmp;
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					tmp.push_back(a[j]);
				}
			}
			ans[i] = tmp;
		}

		for(int i=0;i<sz;i++){
			for(int j=0;j<ans[i].size();j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<"\n";
		}
	return 0;
}