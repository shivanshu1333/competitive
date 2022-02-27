//is possible (a, b) -> (a+b, b)
//(a, b) -> (a, a+b)

int gcd(int a, int b){
    if(b==0) retun a;
    return gcd(b, a%b);
}

char* isPossible(int a, int b, int c, int d){
    int g = gcd(a, b);
    if(d%g==0 && c%g==0 && gcd(d,c)==g && d>=b && c>=a){
        return "Yes";
    }
    else return "No";
}