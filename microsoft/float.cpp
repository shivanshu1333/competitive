#include<bits/stdc++.h>
using namespace std;

void reverse(char* str, int len){
    int i=0, j=len-1, temp;
    while(i<j){
        temp = str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
}

int int_to_str(int x, char str[], int d){
    int i=0;
    while(x){
        str[i++] = (x%10)+'0';
        x = x/10;
    }
    while(i<d) str[i++] = '0';
    reverse(str, i);
    str[i]='\0';
    return i;
}

void dts(double n, char* res, int aft){
    int ip = (int)n;
    double dp = n- (double)ip;
    int i = int_to_str(ip, res, 0);

    if(aft != 0){
        res[i] = '.';
        dp = dp *pow(10, aft)+0.5;
        int_to_str((int)dp, res+i+1, aft);
    }
}

int main(){
    double n;
    cin>>n;
    char res[20];
    dts(n, res, 2);
    cout<<res<<endl;
}



#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef double dd;

void reverse(char* str, int len){
    int i=0, j=len-1, temp;
    while(i<j){
        temp = str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
}

int int_to_str(int x, char str[], int d){
    int i=0;
    while(x){
        str[i++] = (x%10)+'0';
        x = x/10;
    }
    while(i<d) str[i++] = '0';
    reverse(str, i);
    str[i]='\0';
    return i;
}

void dts(double n, char* res, int aft){
    int ip = (int)n;
    double dp = n- (double)ip;
    int i = int_to_str(ip, res, 0);
    if(aft != 0){
        res[i] = '.';
        dp = dp *pow(10, aft)+0.5;
        int_to_str((int)dp, res+i+1, aft);
    }
}

char* del(int input1, int input2, vector<vector<int>> input3){
    dd speed = input1;
    int n = input2;
    vector<vector<dd>> loc;
    for(int i=0;i<n;i++) loc.pb({(dd)input3[i][0], (dd)input3[i][1]});
    sort(loc.begin(), loc.end());
    dd mv = 0, val;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            val = sqrt( pow((loc[i][0]-loc[j][0]),2) + pow((loc[i][1]-loc[j][1]),2) );
            if(mv < val) mv = val;
        }
    }
    double ans = mv/speed;
    char *res = new char[20];
    dts(ans, res, 6);
    return res;
}

int main(){
    int input1, input2;
    vector<vector<int>> input3;
    cin>>input1>>input2;
    for(int i=0;i<input2;i++){
        int x,y;
        cin>>x>>y;
        input3.pb({x,y});
    }
    char *ans = del(input1, input2, input3);
    cout<<ans<<endl;
}