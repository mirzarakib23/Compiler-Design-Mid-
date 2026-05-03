#include <iostream>
#include <fstream>
using namespace std;

bool isKeyword(string s)
{
    string keywords[] = {"int","return","cout","float","double","char","if","else","while"};
    for(int i=0;i<9;i++)
    {
        if(s == keywords[i])
            return true;
    }
    return false;
}


bool isNumber(string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(!(s[i] >= '0' && s[i] <= '9'))
            return false;
    }
    return true;
}

bool isIdentifier(string s)
{
    if((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') || s[0]=='_')
        return true;
    return false;
}

bool isPunctuation(char c)
{
    char p[]={'(',')','{','}',';',','};
    for(int i=0;i<6;i++)
    {
        if(c==p[i])
            return true;
    }
    return false;
}

bool isOperator(char c)
{
    char op[]={'=','+','-','*','/'};
    for(int i=0;i<5;i++)
    {
        if(c==op[i])
            return true;
    }
    return false;
}

int main()
{
    ifstream file("myFile.txt");
    string line;
    int lineNo = 1;

    while(getline(file,line))
    {
        cout<<"Line "<<lineNo<<": ";

        string word = "";

        for(int i=0;i<line.length();i++)
        {
            char ch = line[i];

         
            if(ch == ' ')
            {
                if(word != "")
                {
                    if(isKeyword(word))
                        cout<<"keyword ";
                    else if(isNumber(word))
                        cout<<"constant ";
                    else if(isIdentifier(word))
                        cout<<"identifier ";

                    word = "";
                }
                continue;
            }

          
            if(isPunctuation(ch))
            {
                cout<<"punctuation ";
            }
        
            else if(isOperator(ch))
            {
                cout<<"operator ";
            }
            else
            {
                word = word + ch; 
            }
        }


        if(word != "")
        {
            if(isKeyword(word))
                cout<<"keyword ";
            else if(isNumber(word))
                cout<<"constant ";
            else if(isIdentifier(word))
                cout<<"identifier ";
        }

        cout<<endl;
        lineNo++;
    }

    file.close();
}
