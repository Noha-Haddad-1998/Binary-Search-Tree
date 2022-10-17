#include <iostream>
#include <string>
#include <string.h>
#include <stack>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include "myStack.h"
#include "myBST.h"
#include "myHeap.h"
#include "myEval.h"
#include <regex>
#include <exception>
using namespace std;


int main() {


//    string x="(3-2--24*6)/2*--2";
//    string x="x=-*x+3-32";
//    evaluateLine(x);
    string x;
    while (true){
    getline(cin,x);
    if(x.empty())
    {
        break;
    }
    evaluateLine(x);
//        try {
//            string post=infixToPostfix(x.data());
//            double result=evaluatePostfix(post.data());
//            cout << "Infix Notation : " << x << endl;
//            cout << "Postfix Notation : " << post << endl ;
//            cout << "Result =  "<< result << endl ;
//            cout << "Size = " << post.size() << endl;
//        }
//        catch (...)
//        {
//            cout << "Invalid Expression at ^" << endl;
//            continue;
//        }


    }
//    string x2="(20+10)*2^2.15+(4*5)";
//    string post2=infixToPostfix(x2.data());
//    double result2=evaluatePostfix(post2.data());
//    cout << "Infix Notation : " << x2 << endl;
//    cout << "Postfix Notation : " << post2 << endl ;
//    cout << "Result =  "<< result2 ;
//    cout << "\nSize = " << post2.size();
//BST tree1=BST();
//tree1.insert("Ahmad",10);
//tree1.insert("Zeyad",5);
//tree1.insert("Baher",20);
//tree1.insert("Camilo",20);
//tree1.insert("Daser",20);
//tree1.insert("Ahmad",999);
//tree1.inorderTrav(tree1.root);
//Heap heapy= Heap();
//heapy.BSTtoHeap(tree1);
//heapy.printElemnts();
//vector<pair<string, double>> mohye;
//mohye.emplace_back("koko",202.5);
//mohye.emplace_back("noha",10.5);
//cout << mohye[0].first << " " << mohye[0].second << endl;
//cout << mohye[1].first << mohye[1].second << endl;
//vector<int> k;
//k.emplace_back(4);
//k.emplace_back(5);
//cout<<k.size();
//*/

//    while (true) {
//        string line;
//        getline(cin, line);
//        if(line.empty())
//            break;
//        vector<string> l2 = splitLineAt(line, '=');
//        cout << l2[0] << " Size = " << l2[0].size() << endl;
////if(l2[0].find(" ")<l2[0].size())
////cout << l2[0].find(" ");
//        if (isdigit(l2[0][0])) {
//            cout << "Not Valid\n" << endl;
//        };
//        if (regex_match(l2[0], regex("([a-zA-Z_0-9]+)"))) {
//            cout << "Valid\n";
//        } else
//            cout << "Not Valid\n";
//        if(regex_match(l2[0],regex("++")))
//        {
//            cout << "Sure\n";
//        }
//
//    }
    return 0;
}