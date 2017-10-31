#include<iostream>
using namespace std;

//an array of numbers in order
int numbers[101];
int mid=50,str=0,end=101,search_num;

void newMidStrEnd(int search_num){
    if(search_num<mid)str = mid; 
    if(search_num>mid)end = mid;
    mid  = ((end-str)/2)+str;
}

main(){
    cout<<"Enter search_num: ";
    cin>>search_num;
    if(search_num != numbers[mid])newMidStrEnd(search_num);
    cout<<numbers[mid];
}


