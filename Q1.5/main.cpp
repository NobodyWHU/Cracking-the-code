#include <iostream>
#include <cstring>
using namespace std;

void ReplaceBlank(char* str)
{
    if(str == NULL) return ;
    int length = strlen(str);
    if (length == 0) return ;
    int spaceCount = 0, newLength, i = 0;
    for(i =0; i<length; i++)
    {
        if(str[i] == ' ')
        {
            spaceCount++;
        }
    }
    newLength = length+spaceCount*2;
    str[newLength--] = '\0';
    for(i =length-1; i>=0; i--)
    {
        if(str[i] == ' ')
        {
            str[newLength] = '0';
            str[newLength-1] = '2';
            str[newLength-2] = '%';
            newLength = newLength-3;
        }
        else
        {
            str[newLength] = str[i];
            newLength = newLength-1;
        }
    }
}

int main()
{
    char str[100] = "2 2 35 ";
//    cin>>str;
    ReplaceBlank(str);
    cout<<str<<endl;
    return 0;
}
