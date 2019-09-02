#include<bits/stdc++.h>
#include<string>

using namespace std;

int main(){
    int n;
    cin>>n;
    map<long,long> data;
    int max=-1;
    while(n--){
        int code;
        cin>>code;
        if(code==1){
            long id,recharge;
            cin>>id>>recharge;
            data[id]+=recharge;
            if(max == -1){
                max = id;
            }else if(data[id]>data[max]){
                max = id;
            }
        }else if(code == 2){
            if(data.size()>0){
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