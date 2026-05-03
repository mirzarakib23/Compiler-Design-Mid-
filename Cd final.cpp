#include <iostream>
using namespace std;

bool check(string s)
{
    int state = 0;

    for(int i=0; i<s.length(); i++)
    {
        char c = s[i];

        if(state == 0)
        {
            if(c == 'a')
                state = 1;
            else
                state = -1;
        }
        else if(state == 1)
        {
            if(c == 'b')
                state = 1;
            else if(c == 'a')
                state = 1;
            else
                state = -1;
        }

        if(state == -1)
            return false;
    }


    if(state == 1)
        return true;
    else
        return false;
}

int main()
{
    string test[5] = {"a", "ab", "abb", "b", "aba"};

    for(int i=0;i<5;i++)
    {
        cout << test[i] << " -> ";

        if(check(test[i]))
            cout << "Accepted";
        else
            cout << "Rejected";

        cout << endl;
    }

    return 0;
}
