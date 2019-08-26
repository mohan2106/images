#include<bits/stdc++.h>
#include<cctype>
using namespace std;
struct data
{
    string info;
    struct data *left;
    struct data *right;
};
typedef struct data node;

int pres(char ch){
    switch(ch){
        case '^':
            return 4;
        case '*':
            return 2;
        case '/':
            return 3;
        case '+':
            return 1;
        case '-':
            return 1;
        default:
            return 0;
    }
}
bool isOperator(char ch){
    switch(ch){
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
            return true;
        default:
            return false;
    }
}
bool isOperator2(char ch){
    switch(ch){
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            return true;
        default:
            return false;
    }
}

vector<string> postfix(vector<string> str){
    vector<string> pf,resu;
    stack<char> st;
    st.push('M');
    int len = str.size();
    // cout<<len;
    for(int i=0;i<len;i++){
        // cout<<str[i]<<"\t";
        if(!isOperator(str[i][0])){
            pf.push_back(str[i]);
        }
        else if(str[i][0] == '('){
            st.push('(');
        }else if(str[i][0] == ')'){
            while(st.top() != '(' && st.top() != 'M'){
                // cout<<st.top();
                char d=st.top();
                string x="";
                x.push_back(d);
                pf.push_back(x);
                st.pop();
            }
            if(st.top() == '('){
                st.pop();
            }
       } else{
            // cout<<"got "<<str[i][0]<<endl;
            if(st.top() != '(' && str[i][0]!='^'){
                while(st.top() != 'M' && pres(str[i][0])<=pres(st.top())){
                    char d=st.top();
                    string x="";
                    x.push_back(d);
                    pf.push_back(x);
                    st.pop();
                }
            }else if(st.top() != '(' && str[i][0]=='^'){
                while(st.top() != 'M' && pres(str[i][0])<pres(st.top())){
                    char d=st.top();
                    string x="";
                    x.push_back(d);
                    pf.push_back(x);
                    st.pop();
                }
            }
            st.push(str[i][0]);
        }
    }
    while(st.top()!='M'){
        char d=st.top();
        string x="";
        x.push_back(d);
        pf.push_back(x);
        st.pop();
    }
    for(auto at=pf.begin();at!=pf.end();at++){
        string s=*at;
        if(s[0] != '\0'){
            resu.push_back(s);
            // cout<<*at<<'\t';
        }
    }
    return resu;
    // cout<<pf.size()<<'\n';

}
node *createNode(string v){
    node *n=(node *)malloc(sizeof(node));
    n->left = NULL;
    n->right = NULL;
    n->info = v;
    return n;
}

long long int convertInt(string str){
    if(str[0]!='-'){
        long long int res=0;
        for(int i=0;i<str.length();i++){
            res = res*10 + (str[i]-'0');
        }
        return res;
    }else{
        long long int res=0;
        for(int i=1;i<str.length();i++){
            res = res*10 + (str[i]-'0');
        }
        return res*(-1);
    }
    
}

node *generateTree(vector<string> v){
    stack<node *> st;
    node *t,*t1,*t2;
    for(int i=0;i<v.size();i++){
        if(!isOperator(v[i][0])){
            t= createNode(v[i]);
            st.push(t);
        }
        else{
            // int da = convertInt(v[i]);
            t = createNode(v[i]); 
            t1 = st.top(); 
            st.pop();   
            t2 = st.top(); 
            st.pop(); 
            t->right = t1; 
            t->left = t2; 
            st.push(t); 
        }
    }
    t=st.top();
    st.pop();
    return t;
}
string eval(string str1,string str2,char ch){
    // cout<<'\n';

    long long int a = convertInt(str1);
    long long int b = convertInt(str2);
    // cout<<str1<<"= "<<a<<'\t'<<str2<<"= "<<b<<'\n';
    long long int t;
    if(ch == '^'){
        t = floor(pow(a,b));
    }
    switch(ch){
        case '^':
            return to_string(t);
        case '*':
            return to_string(a*b);
        case '/':
            return to_string(a/b);
        case '+':
            return to_string(a+b);
        case '-':
            return to_string(a-b);
        default:
            cout<<"Cant be evaluated";
            return "-1";
    }
}

string inorder(node *t) 
{ 

    if(t) 
    { 
        string c = t->info;
        if(!isOperator(c[0])){
            return c;
        }else{
            string str1 = inorder(t->left);
            string str2 = inorder(t->right);
            return eval(str1,str2,c[0]);
        }
    }else{
        return "0";
    } 
} 

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<char,string> var;
        while(n--){
            node *root = NULL;
            string str;
            cin>>str;
            string temp="";
            vector<string> ne;
            int k=0;
            if(isalpha(str[0])){
                if(str[1]=='='){
                    for(int i=2;i<str.length();i++){
                        if(!isOperator(str[i])){
                            if(isalpha(str[i])){
                                auto it = var.find(str[i]);
                                if(it!=var.end()){
                                    temp = var[str[i]];
                                }else{
                                    cout<<"CANT BE EVALUATED"<<'\n';
                                    goto terminate;
                                }
                            }else{
                                temp.push_back(str[i]);
                            }
                        }
                        else{
                            if((ne.size() == 0 || temp.length() == 0) && str[i]=='-' ){
                                string d= "";
                                d.push_back('0');
                                ne.push_back(d);
                            }
                            if(temp.length()!=0){
                                ne.push_back(temp);
                            }
                            string d= "";
                            d.push_back(str[i]);
                            ne.push_back(d);
                            temp="";
                        }
                    }
                    ne.push_back(temp);
                    // for(auto it= ne.begin();it!=ne.end();it++){
                    //     cout<<*it<<"\t";
                    // }
                    // cout<<'\n';
                    ne= postfix(ne);
                    root = generateTree(ne);
                    string result = inorder(root); 
                    var[str[0]] = result;
                }else{
                    for(int i=0;i<str.length();i++){
                        if(!isOperator(str[i])){
                            if(isalpha(str[i])){
                                auto it = var.find(str[i]);
                                if(it!=var.end()){
                                    temp = var[str[i]];
                                }else{
                                    cout<<"CANT BE EVALUATED"<<'\n';
                                    goto terminate;
                                }
                            }else{
                                temp.push_back(str[i]);
                            }
                        }
                        else{
                            if((ne.size() == 0 || temp.length() == 0) && str[i]=='-' ){
                                string d= "";
                                d.push_back('0');
                                ne.push_back(d);
                            }
                            if(temp.length()!=0){
                                ne.push_back(temp);
                            }
                            string d= "";
                            d.push_back(str[i]);
                            ne.push_back(d);
                            temp="";
                        }
                    }
                    ne.push_back(temp);
                    // for(auto it= ne.begin();it!=ne.end();it++){
                    //     cout<<*it<<"\t";
                    // }
                    // cout<<'\n';
                    ne= postfix(ne);
                    root = generateTree(ne);
                    string result = inorder(root); 
                    cout<<result<<'\n';
                }
            }else{
                for(int i=0;i<str.length();i++){
                    if(!isOperator(str[i])){
                        if(isalpha(str[i])){
                            auto it = var.find(str[i]);
                            if(it!=var.end()){
                                temp = var[str[i]];
                            }else{
                                cout<<"CANT BE EVALUATED"<<'\n';
                                goto terminate;
                            }
                        }else{
                            temp.push_back(str[i]);
                        }
                    }
                    else{
                        if((ne.size() == 0 || temp.length() == 0) && str[i]=='-' ){
                            string d= "";
                            d.push_back('0');
                            ne.push_back(d);
                        }
                        if(temp.length()!=0){
                            ne.push_back(temp);
                        }
                        string d= "";
                        d.push_back(str[i]);
                        ne.push_back(d);
                        temp="";
                    }
                }
                ne.push_back(temp);
                ne= postfix(ne);
                root = generateTree(ne);
                string result = inorder(root); 
                cout<<result<<'\n';
            }
            terminate:
                int mohan=4;
        }
    }
}