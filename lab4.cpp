#include<bits/stdc++.h>
using namespace std;

long generateS(int l){
    int x =8;
    long res=9;
    for(int i=1;i<l;i++){
        res = res*10 + x;
        x--;
    }
    return res;
}
long generateL(int l){
    l=l+1;
    if(l==2){
        return 10;
    }else{
        int x =2;
        long res=10;
        for(int i=2;i<l;i++){
            res = res*10 + x;
            x++;
        }
        return res;
    }
    
}
// bool check(long x){
//     long temp = x;
//     int l=0;
//     while(temp>0){
//         l++;
//         temp /= 10;
//     }
//     set<int> t;
//     long z=10;
//     while(temp >0){
//         t.insert(temp%10);
//         temp /= 10;
//     }
//     if(t.size() != l){
//         return false;
//     }else{
//         return true;
//     }

// }

int main(){
    long l,r;
    cin>>l>>r;
    long temp = l;
    int lenl = 0,lenr = 0;
    while(temp>0){
        lenl++;
        temp /= 10;
    }
    temp = r;
    while(temp>0){
        lenr++;
        temp /= 10;
    }
    if(lenl<lenr){
        long x = generateS(lenl);
        long y = generateL(lenl);
        if(x<l && y>r){
            cout<<"-1\n";
        }else if(x>= l){
            cout<<x<<'\n';
        }else if(y<=r){
            cout<<y<<'\n';
        }
    }else{
        long no = r-l;
        int t=0;
        int z=1;
        for(int i=1;i<lenl;i++){
            z*=10;
        }
        int i=0;
        while(l/z == r/z){
            z /= 10;
            i++;
        }
        z *= 10;
        temp = l/z;
        set<int> diff;
        // long z=10;
        while(temp >0){
            diff.insert(temp%10);
            temp /= 10;
        }
        if(diff.size() != i){
            cout<<"-1\n";
        }else{
            long nl = l%z;
            long nr = r%z;

        }
    }
    
    return 0;
}
