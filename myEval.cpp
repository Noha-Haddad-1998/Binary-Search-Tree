//
// Created by Mohye on 06/06/2020.
//
#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include "myEval.h"
#include "myBST.h"
#include "myStack.h"
#include "regex"
#include <float.h>
#define SMALLEST 2.22507385850720138e-308

using namespace std;
BST myTree= BST();
void evaluateLine(string line)
{
    line=removeSpaces(line.data());
    int lineTest=testLine(line);
    switch (lineTest){
        case 0: //Printing Operation
        {int LHS=testRegex(line);
            switch (LHS){

                case -1:
                {
                    line=line.substr(2);
                    Node *mynode=myTree.searchBST(line.data());
                    if(!mynode)
                    {
                        cout << "\nError at ^" << endl;
                        return;
                    } else
                    {
                        myTree.insert(line,mynode->value-1); //Decrement Thing print
                        cout << mynode->key << " = " << mynode->value << endl;
                        return;
                    }
                }
                case -3:
                {line=line.substr(0,line.size()-2);
                    Node *mynode=myTree.searchBST(line.data());
                    if(!mynode)
                    {
                        cout << "\nError at ^" << endl;
                        return;
                    } else
                    {
                        cout << mynode->key << " = " << mynode->value << endl;; //Print then decrement
                        myTree.insert(line,mynode->value-1);
                        return;
                    }}
                case 1:
                {
                    line=line.substr(2);
                    Node *mynode=myTree.searchBST(line.data());
                    if(!mynode)
                    {
                        cout << "\nError at ^" << endl;
                        return;
                    } else
                    {
                        myTree.insert(line,mynode->value+1);    //Increment Then Print
                        cout << mynode->key << " = " << mynode->value << endl;
                        return;
                    }}
                case 3:
                {
                    line=line.substr(0,line.size()-2);
                    Node *mynode=myTree.searchBST(line.data());
                    if(!mynode)
                    {
                        cout << "\nError at ^" << endl;
                        return;
                    } else
                    {
                        cout << mynode->key << " = " << mynode->value << endl; //Print Then Increment
                        myTree.insert(line,mynode->value+1);
                        return;
                    }
                }
                case 4:
                {
                    Node *mynode=myTree.searchBST(line.data());
                    if(!mynode)
                    {
                        cout << "\nError at ^" << endl;
                        return;
                    } else
                    cout << mynode->key << " = " << mynode->value << endl;
                    return;
                }
                default:
                {
                    cout << "\nError at ^" << endl;
                    return;
                }

            }}
        case 1: // Regular Operation
        {
            vector<string> linesplit=splitLineAt(line,'=');
            string lhs=linesplit[0];
            string rhs=linesplit[1];
            int testRegexLHS=testRegex(lhs);
            switch (testRegexLHS)
            {
                case -2: // var-=
                {
                    rhs=lhs+rhs;
                    if(!pairParn(rhs))
                    {
                        cout << "\nError at ^" << endl;
                        break;
                    }
                    lhs=lhs.substr(0,lhs.size()-1);
                    double result;
                    try {
                        result = evaluateRHS(rhs, myTree);

                    }catch (...)
                    {
                        cout << "\nError at ^" << endl;
                        break;
                    }
                    myTree.insert(lhs,result);
                    break;

                }
                case 2: // var+=
                {
                    rhs=lhs+rhs;
                    if(!pairParn(rhs))
                    {
                        cout << "\nError at ^" << endl;
                        break;
                    }
                    lhs=lhs.substr(0,lhs.size()-1);
                    double result;
                    try {
                        result = evaluateRHS(rhs, myTree);

                    }catch (...)
                    {
                        cout << "\nError at ^" << endl;
                        break;
                    }
                    myTree.insert(lhs,result);
                    break;
                }
                case 4: // var =
                {
                    if(!pairParn(rhs))
                    {
                        cout << "\nError at ^" << endl;
                        break;
                    }

                    try {
                        double result = evaluateRHS(rhs, myTree);
                        if(result!=DBL_MIN)
                            myTree.insert(lhs,result);
                    }catch (...)
                    {
                        cout << "\nError at ^" << endl;
                        break;
                    }
                    break;
                }
                default:
                    cout << "\nError at ^" << endl;
                    break;
            }

        }

    }
}
//static inline void ltrim(std::string &s) {
//    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
//                                    std::not1(std::ptr_fun<int, int>(std::isspace))));
//}
//
//// trim from end (in place)
//static inline void rtrim(std::string &s) {
//    s.erase(std::find_if(s.rbegin(), s.rend(),
//                         std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
//}
//
//// trim from both ends (in place)
//static inline void trim(std::string &s) {
//    ltrim(s);
//    rtrim(s);
//}

vector<string> splitLineAt(string line, char delm) {
    int del =line.find_first_of(delm);
    string lhs= line.substr(0,del);
    string rhs= line.substr(del+1);
    vector<string> cont;
    cont.emplace_back(lhs);
    cont.emplace_back(rhs);
    if(lhs==rhs)
    {
        cont.pop_back();
    }
    return cont;
}

int testRegex (string lhs)
{


    if(regex_match(lhs, regex("^\\-\\-[a-zA-Z_0-9]+")))
    {
        return -1; // Type 1 --variable
    } else if(regex_match(lhs, regex("[a-zA-Z_0-9]+\\-{1}$")))
    {
        return -2; // Type 2 variable- = ..
    }else if(regex_match(lhs, regex("[a-zA-Z_0-9]+\\-{2}$")))
    {
        return -3; // Type 3 variable-- no equal after
    }else if(regex_match(lhs, regex("^\\+\\+[a-zA-Z_0-9]+")))
    {
        return 1; // Type 1 ++variable
    } else if(regex_match(lhs, regex("[a-zA-Z_0-9]+\\+{1}$")))
    {
        return 2; // Type 2 variable+ = ..
    }else if(regex_match(lhs, regex("[a-zA-Z_0-9]+\\+{2}$")))
    {
        return 3; // Type 3 variable++ no equal after
    }else if( regex_match(lhs, regex("^[a-zA-z]+[a-zA-Z_0-9]*")))
    {
        return 4; // Type Regular Variable (x)
    }else if(  regex_match(lhs, regex("^[0-9]+\\.{0,1}[1-9]*")))
    {
        return 5; // Number
    }
    else
        return 0;
}

int testLine(string line)
{
    if(line.find_first_of("=")==string::npos)
    {
        return 0; // Priniting Operation
    }
    if(line.find_first_of("=")==line.find_last_of("=") )
    {
        return 1; // Regular Operation
    } else if (line.find_first_of("=")+1==line.find_last_of("=") )
    {
        return 2; // Boolean Operation
    } else
        return -1; // Invalid Equality
}
char *removeSpaces(char *str)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
    return str;
}
bool pairParn(string &s)
{
    int r=0;
    int l=0;
    for (auto it = s.cbegin() ; it != s.cend(); ++it) {
        if(*it == '(')
            r++;
        if(*it==')')
            l++;
    }
    return r == l;
}
//bool checkRHS(string &s)
vector<string> splitAtOperators(string str)
{
    vector<string> parts;
    int lastOperatorindex=-1;
    for (int i=0;i<=str.size();i++)
    {
        if (str[i] == '('|| str[i] == ')' || str[i] == '+' || str[i] == '-'|| str[i] == '*'|| str[i] == '/'|| str[i] == '^')
        {
            char x = str[i];
            if(i!=lastOperatorindex+1) //Element at the start
            {
                if(lastOperatorindex==-1)
                {
                    string s=str.substr(lastOperatorindex+1,i+lastOperatorindex+1);
                    parts.push_back(s);
                } else
                {string s=str.substr(lastOperatorindex+1,i-lastOperatorindex-1);
                    parts.push_back(s);}
            }
            string s(1, str[i]);
            parts.push_back(s);
            lastOperatorindex=i;
        }
    }
    if(lastOperatorindex!=str.size()-1)
    {
        string s=str.substr(lastOperatorindex+1);
        parts.push_back(s);}

    return parts;
}

double evaluateRHS(string rhs,BST tree)
{
    vector<string> v=splitAtOperators(rhs);
    /*
    for (int i=0 ; i<vectorizedRHS.size();i++ )
    {
           if(isOperator(vectorizedRHS[i][0]))
           {
               char op=vectorizedRHS[i][0];
               switch (op)
               {
                   case '(':
                   {
                       string nextEl=vectorizedRHS[i+1];

                       if(i==0)
                       {

                           if( (nextEl[0]!='(') && (testRegex(nextEl)!=4) || (nextEl[0]!='-')|| (testRegex(nextEl)!=5) || (nextEl[0]!='+'))
                           {
                               cout << "\nError at ^" << endl;
                               return NULL;
                           }
                       } else
                       {
                           string prevEl=vectorizedRHS[i-1];
                           if(!isOperator(prevEl[0]))
                           {
                               cout << "\nError at ^" << endl;
                               return NULL;
                           } else if (nextEl[0]!='-' && nextEl.size()==1)
                           {
                               cout << "\nError at ^" << endl;
                               return NULL;
                           }

                       }
                   }
                   case '-':
                   {
                       string nextEl=vectorizedRHS[i+1];
                       if(i==0)
                       {
                           if(((nextEl[0]!='-')&&(nextEl[0]!='+'))&&isOperator(nextEl[0]))
                           {
                               cout << "\nError at ^" << endl;
                               return NULL;
                           }
//                       }else
//                       {
//                           string prevEl=vectorizedRHS[i-1];
//                           if((((nextEl[0]!='-')||(nextEl[0]!='+')||(nextEl[0]!='+'))&&isOperator(nextEl[0]))||)
//                           {
//                               cout << "\nError at ^" << endl;
//                               return NULL;
//                           }
//
//                       }
                   }

               }

           }
    }



}*/
double result = DBL_MIN;
    for(int i=0;i<v.size();i++)
    {
        int regTest=testRegex(v[i]);

           if(v[i].size()==1&&isOperator(v[i][0])) //Operator;
        {
            continue;
           } else if(regTest==4)
           {
               Node* inTree=tree.searchBST(v[i].data());

               if(!inTree)
               {
                   throw "Error";
               } else
               {
                   v.at(i)=to_string(inTree->value);
               }

           }else if(regTest==5)
           {
               continue;
           } else
           {
               throw "Error";
           }

    }
    string RHSnew=accumulate(v.begin(), v.end(), string{});
    try {
        string post=infixToPostfix(RHSnew.data());
        result=evaluatePostfix(post.data());
        cout << "Infix Notation : " << RHSnew << endl;
        cout << "Postfix Notation : " << post << endl ;
        cout << "Result =  "<< result << endl ;

    }catch (...)
    {
        cout << "Invalid Expression at ^" << endl;
    }
    return result;

}
