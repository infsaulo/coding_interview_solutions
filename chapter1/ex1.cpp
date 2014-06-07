// Considering ASCII encoded strings
#include <string>
#include <iostream>
#include <vector>

#define AMOUTR_ASCII_CHARS 128

using namespace std;

bool isUniqueCharString(string str)
{
    vector<bool> alreadyHaveChar(128, false);

    for(int index=0; index < str.size(); index++)
    {
        if(alreadyHaveChar[(int)str[index]])
        {
            return false;
        }
        
        alreadyHaveChar[(int)str[index]] = true;
    }

    return true;
}

int main()
{
    string str;
    cin >> str;
    cout << isUniqueCharString(str);

    return 0;
}
