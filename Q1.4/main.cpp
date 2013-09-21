#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool isAnagram(string s1, string s2)
{
    if(s1 == "" || s2 == "") return false;
    if(s1.length() != s2.length()) return false;
    sort(&s1[0], &s1[0]+s1.length());
    sort(&s2[0], &s2[0]+s2.length());
    if(s1 == s2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isAnagram_2(string s1, string s2)
{
    if(s1 == "" || s2 == "") return false;
    if(s1.length() != s2.length()) return false;
    int len = s1.length();
    int flags[256];
    memset(flags, 0, sizeof(flags));
    for(int i =0; i<len; i++)
    {
        ++flags[(int)s1[i]];
        --flags[(int)s2[i]];
    }
    for(int i=0;i<256; i++)
    {
        if(flags[i] != 0)
            return false;
    }
    return true;

}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(isAnagram_2(s1, s2))
    {
        cout<<"they are anagram"<<endl;
    }
    else
    {
        cout<<"they are not anagram"<<endl;
    }
    return 0;
}
