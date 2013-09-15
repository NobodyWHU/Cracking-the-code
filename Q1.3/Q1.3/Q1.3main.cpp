#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "";
	//cin>>str;
	int len = str.length();
	if(len <=1) 
		return true;
	for (int i = 0; i < len; i++)
	{
		int j = i+1;
		for(;j < len;j++)
		{
			if(str[i] == str[j])
			{
				str[j] = '\0';
			}
		}

	}
	cout<<str<<endl;
	return true;
}