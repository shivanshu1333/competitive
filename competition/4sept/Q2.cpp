    #include<iostream>
    #include<vector>
    // #include<climits>
    #include<algorithm>
    #include<string>
    // #include<stack>
    // #include<queue>

    using namespace std;

    int main(){
        int b,g,t;
        cin>>b>>g>>t;
        if(b==g){
            if(t==b){
                cout<<b+1<<endl;
            }
            else if(t>b){
                cout<<2*b-t+1<<endl;
            }
            else{
                cout<<t+1<<endl;
            }
        }
        else{
        int minN = min(b, g);
        int maxN = max(b, g);
        
        if(t>maxN && t>minN){
            if(maxN==minN){
                cout<<(maxN-minN+1)<<endl;
            }
        }
        else if(t<=maxN && t>minN){
            cout<<minN+1<<endl;
        }
        else if(t<maxN && t<=minN){
            cout<<t+1;
        }
        }
    }