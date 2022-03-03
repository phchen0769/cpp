#include <iostream>
#include <string>

using namespace std;

void test7(), test8(), test9(), test10(),test11();
int main()
{
    // test7();
    // test8();
    // test9();
    // test10();
    test11();
    return 0;
}

void test7()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%10d\n", a);
    printf("%4c%6d\n", '+', b);
    printf("-----------\n");
    printf("%10d\n", a + b);
}

void test8()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", a * b);
}

void test9()
{
    int a;
    scanf("%d", &a);
    printf("%d\n", a * 300);
}

void test10(){
    int a;
    scanf("%d", &a);
    printf("%d\n", (a+1)*100+a*10+(a+1)*2);
}

void test11(){
    int a1,a2,a3,b1,b2,b3;
    scanf("%d%d%d%d%d%d", &a1,&a2,&a3,&b1,&b2,&b3);
    printf("%d\n", a1*b1+a2*b2+a3*b3);
}