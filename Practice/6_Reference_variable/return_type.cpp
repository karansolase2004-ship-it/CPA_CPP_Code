#include <cstdio>

int returns(){
    float n = 3.14;

    return n;
    // n हि value float या type ची असून ती int या type च्या variable मध्ये store करण्यसाठी compatible आहे म्हणजेच तिला compatible असलेल्या type मध्ये ती return करण्यात आलेली आहे.
}
int main (void){
    int n;
    n = returns();
    printf("%d\n", n);
}