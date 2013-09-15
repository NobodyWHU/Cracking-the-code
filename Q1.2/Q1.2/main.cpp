#include <iostream>
#include <string>

using namespace std;


void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	string str;
	cin>>str;
	int len = str.length();
	for (int i = 0, j = len-1; i < j; i++, j--)
	{
		swap(str[i], str[j]);
	}
	cout<<str<<endl;
	return 0;
}