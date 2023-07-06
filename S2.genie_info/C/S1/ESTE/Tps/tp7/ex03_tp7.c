#include<stdio.h>
int main(){
    int arr[10] = {10,1,2,3,5,7,8,9,0};
    int *p = arr;
        printf("*p=%d\n", *p);//*p=10
    ++*p;
        printf("*p=%d\n", *p);//*p=11
    p += 2;
        printf("*p=%d\n", *p);//*p=2
        
    int*ptr=p;
    while(ptr<p+5){
        printf("*ptr=%d\t", *ptr);//*ptr=2  *ptr=3  *ptr=5  *ptr=7  *ptr=8
        ptr++;}
 return 0;
}




