#include<iostream>
#include<string>
using namespace std;

//my_method but code block has an issue with to_string
string countAndSay(int A) {
    string str = "11";
    int count = 1;
    string ss="";

    if(A == 1){
        return "1";
    }

    while(A != 2){
        count = 1;
        for(int i = 0; i < str.size(); i++){
            if(i+1 != str.size()){
                if(str[i] == str[i+1]){
                    count++;
                }
                else{
                    ss+=to_string(count);
                    ss+=str[i];
                    count = 1;
                }
            }
            else{
                    ss+=to_string(count);
                    ss+=str[i];
            }
        }
        str = ss;
        cout<<str<<endl;
        ss="";
        A--;
    }

    return str;
}
//using streams
// declaration stringstream ss;
// set value ss.str("string u wanna set");
//extract value string s=ss.str();
//append values ss<<value;
string Solution::countAndSay(int A) {
    string str = "11";
    int count = 1;
    stringstream ss; //decl

    if(A == 1){
        return "1";
    }

    while(A != 2){
        count = 1;
        for(int i = 0; i < str.size(); i++){
            if(i+1 != str.size()){
                if(str[i] == str[i+1]){
                    count++;
                }
                else{
                    ss << count << str[i];//appending
                    count = 1;
                }
            }
            else{
                ss << count << str[i];
            }
        }
        str = ss.str(); //extracting
        ss.str(""); //resetting
        A--;
    }

    return str;
}

int main()
{
    int n=4;
    string a=countAndSay(n);
    cout<<a;;
}

