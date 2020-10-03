#include <iostream>
using namespace std;
int main(){
	{int q=0;
	for (int i=0; i<100; i++){
		q++;
		int p=12;
	}
	int p=1;
	}
	cout<<"Type characters:"<<endl;
	while(char c=cin.get()!='q'){
		cout<<c<<" wasn't it"<<endl;
		if(char x=c=='a'||c=='b')
			cout<<"You typed a or b"<<endl;
		else
			cout<<"You typed "<<x<<endl;
	}
	cout<<"Type A,B,or C"<<endl;
	switch(int i=cin.get()){
		case 'A':cout<<"Snap"<<endl; break;
		case 'B':cout<<"Crackle"<<endl; break;
		case 'C':cout<<"Pop"<<endl; break;
		default:cout<<"Not A, B or C!"<<endl;
	}
}