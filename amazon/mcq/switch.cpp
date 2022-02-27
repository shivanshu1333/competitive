// three, error dupplicate case value
// case f will be reached only when v is f and condition is true
#include<bits/stdc++.h>
using namespace std;
int main(){
//     int i=3;
//     switch(i){
//         default:printf("zero");
//         case 1: printf("one");
//                 break;
//         case 2:printf("two");
//                 break;
//         case 3:printf("three");
//                 break;
                
//     }

        // switch(10){
        //         case 10:
        //                 cout<<"1"<<endl;
        //                 break;
        //         case 10:
        //                 cout<<"2"<<endl;
        // }

        int i=4;
        switch(i){
                case 1:cout<<"1";
                break;
                if(i>3){
                        case 4: cout<<"4";
                        cout<<"here bawa";
                        break;
                }
                case 5: cout<<"5";
                break;
                default: cout<<"def";
                break;
        }

    return 0;
}