//
// Created by Mohye on 05/06/2020.
//

#include "myHeap.h"
#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;





void heapSort(vector<pair<string,double>> &vector)
{
    int i;
    int size= vector.size();
    size=size-1;
    for(i=size;i>1;i--)
    {
        Heap::Delete(vector,i);
    }
}


void insert(vector<pair<string,double>> &A, int n){
    pair<string,double> temp;
    int i=n;

    temp = A[n]; //store the element here

    while (i>1 && temp.second>A[i/2].second)//int dev
    {
        A[i]=A[i/2];
        i=i/2;
    }

    A[i]=temp;
}




void createHeap(vector<pair<string,double>> &A,int size)
{
    int i;
    for(i=2;i<size;i++)
    {
        insert(A,i);
    }
}




pair<string,double> Delete(vector<pair<string,double>> &A,int n)
{
    int i,j;
    pair<string,double> x;
    pair<string,double> val=A[1];
    x= A[n];
    A[1]=A[n];
    A[n]=val;
    i=1;//parent
    j=2*i;//left

    while (j<n-1)
    {
        //check which is greater l or R
        if(A[j+1]>A[j])
            j=j+1;//right

        if(A[i].second<A[j].second)
        {
            swap(A[i],A[j]);
            i=j;
            j=2*j;
        }
        else
        {break;}
    }
    return val;
}


pair<string, double> Heap::NodeToPair(Node *node) {
    pair<string,double> pair;
    string key=node->key;
    double val=node->value;
    pair.first=key;
    pair.second=val;
    return pair;
}

void Heap::BSTtoVector(Node *root) {
    /*
    while (root) {
        BSTtoHeap(root->left);
        if(arr.size()==1)
        {
            arr.emplace_back(NodeToPair(root));
            arr[0].second++;
        } else
        {
            arr.emplace_back(NodeToPair(root));
            arr[0].second++;
            int i= arr.size();
            while (i>1 && arr.back().)
        }

        BSTtoHeap(root->right); */
          if(root) {
              BSTtoVector(root->left);
              arr.emplace_back(Heap::NodeToPair(root));
              arr[0].second++;
              BSTtoVector(root->right);
          }

}


void Heap::BSTtoHeap(BST tree) {
    BSTtoVector(tree.root);
    createHeap(arr,arr.size());
}


Heap::Heap() {
    arr.emplace_back("Number of Elements",0);

}

pair<string ,double> Heap::getParent(int i) {
    return  arr[i/2];
}
pair<string ,double> Heap::getlChild(int i) {
    return  arr[2*i];
}
pair<string ,double> Heap::getrChild(int i) {
    return  arr[2*i+1];
}



void Heap::SwapPairs(pair<string, double> *p1, pair<string, double> *p2) {
    string onekey=p1->first;
    double oneval=p1->second;
    p1=p2;
    p2->first=onekey;
    p2->second=oneval;
}

void Heap::printElemnts() {
    cout << arr[0].first << " = " << arr[0].second << endl;
for (int i =1 ; i<arr.size() ; i++)
{
    cout << arr[i].first << " =  " <<arr[i].second << endl;

}
}

// not complete
/*
void heapify(int A[], int size)
{
    size=size-1;
    vector<int> v(size);
    v.insert(v.begin(),A,A+10);

    int levels=floor(log2(size));
    int exp=levels;
    int num = pow(2,(double)exp)-1;

    int temp=v[(int)num];
    int j=num*2;

    while(num>0)
    {
        if(v[j+1]>v[j])
            j=j+1;

        if(v[j]>temp)
        {
            swap(v[j],v[(int)num]);
        }
        num--;
        j=num*2;
    }
    int k;
    printf("\n");
    for(k=0;k<v.size();k++)
    {
        cout <<v[k];
    }
}*/