#include <iostream>
#include<string>
#include<vector>
using namespace std;

bool areAnagram(string str1, string str2){
    int value = 0; 
    for (int i = 0; i < 10; i++) { 
        value = value ^ (int) str1[i]; 
        value = value ^ (int) str2[i]; 
    } 
    return value == 0;  
} 

int main(){
    int N;
    cin>>N;
    int n=N;
    vector<string> v;
    while(n--){
        string s;
        cin>>s;
        v.push_back(s);
    }
    int ans=0;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            // cout<<v[i]<<" "<<v[j]<<endl;
            if(areAnagram(v[i],v[j])){
                ans++;
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    cout<<ans<<endl;
}
