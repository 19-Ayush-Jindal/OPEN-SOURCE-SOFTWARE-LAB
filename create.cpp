#include<iostream>
#include <vector>
using namespace std;
vector<int>segment_tree;
int create_segment_tree(int index,int l,int r,vector<int>arr){
    if(l==r){
        return segment_tree[index]=arr[l];
    }
int m=(l+r)/2;
int a=create_segment_tree(2*index+1,l,m,arr);
int b=create_segment_tree(2*index+2,m+1,r,arr);
return segment_tree[index]=a+b;

}

void update(int index,int l,int r,int val){
    if(l==r){
        segment_tree[index]=val;return;
    }
    int m=(l+r)/2;
    if(index<=m){
        update(index,l,m,val);
    }
    else{
        update(index,m+1,r,val);
    }
    segment_tree[index]=segment_tree[2*index+1]+segment_tree[2*index+2];
}

int query(int index,int l,int r,int s,int e){
    if(s<=l && e<=r || s>=l && e>=r){
        return 0;
    }
    if(s>=l && e<=r){
        return segment_tree[index];
    }
    int m=(l+r)/2;
    int a=query(2*index+1,l,m,s,e);
    int b=query(2*index+2,m+1,r,s,e);
    return a+b;
}
int main(){
    vector<int>arr(5);
    int x=0;
    for(int i=0;i<5;i++){
        arr[i]=++x;
    }
    
    segment_tree.assign(10,0);
    create_segment_tree(0,0,4,arr);
    update(1,0,4,100);
    cout<<segment_tree[1];
    return 0;
}