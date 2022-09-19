int x, y;
int extend_gcd(int a, int b){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int g = extend_gcd(b, a%b);
    int tmp = x;
    x = y;
    y = tmp - (a/b)*y;
    return g;
}