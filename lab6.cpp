#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int t;
    cin>>t;
    int userdata[n]={0};
    int max=-1;
    while(t--){
        int code;
        cin>>code;
        if(code==1){
            long id,recharge;
            cin>>id>>recharge;
            userdata[id-1]+=recharge;
            if(max == -1){
                max = id;
            }else if(userdata[id-1]>userdata[max]){
                max = id;
            }
        }else if(code == 2){
            if(max != -1){
                cout<<max<<'\n';
            }else{
                cout<<"No data available"<<'\n';
            }
        }else{
            cout<<"INVALID OPERATOR"<<'\n';
        }
    }
    return 0;
}
