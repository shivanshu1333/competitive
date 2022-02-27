int i=0;
while(i<n){
    int elin = arr[i]-1;
    if(arr[i]<=0){
        i++;
        continue;
    }
    if(arr[elin]>0){
        arr[i]=arr[elin];
        arr[elin]=-1;
    }
    else{
        arr[i]=0;
        arr[elin]--;
    }
}
//for i+1, freq is abs(arr[i])