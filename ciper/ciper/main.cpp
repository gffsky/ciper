#include<iostream>
//#include<fstream>
#include<vector>
#include<string>
using namespace std;

vector <string> premsg;
class INFO
{
public:
	unsigned int ai_len;
	vector <unsigned int> key;
	unsigned int repeat_num;
	string premsg;
	string codemsg;
	void do_encode();

};
void INFO ::do_encode()
{
	unsigned int i=0;
	codemsg.resize(ai_len);
	string buff;
	buff.resize(ai_len);
	codemsg.assign(ai_len,' ');
	for(i=0;i<premsg.size();i++)
	{
		codemsg[key[i]]=premsg[i];
		//cout<<premsg[i]<<endl;
		//cout<<key[i]<<endl;
		//cout<<codemsg[key[i]]<<endl;
	}
	repeat_num--;
	if(repeat_num != 0)
	{
		while(repeat_num--)
		{
			buff.assign(ai_len,' ');
			for(i=0;i<ai_len;i++)
			{
				if(codemsg[i] != ' ')
					buff[key[i]]=codemsg[i];
			}
			buff.swap(codemsg);
		}
	}
	for(i=0;i<ai_len;i++)
	{
		cout<<codemsg[i];
	}
	cout<<endl;
}

int main()
{
	INFO info;
	unsigned int buff = 0;
	unsigned int i = 0;
	//freopen("input.txt","r",stdin);
	while(cin>>buff)
	{
		if(buff==0)
			break;
		info.ai_len=buff;   //get key nnumber
		for(i=0;i<info.ai_len;i++)
		{
			cin>>buff;
			info.key.push_back(buff-1);    //get key value
		}
		while(cin>>buff)   
		{
			if(buff == 0)
				break;
			info.repeat_num=buff;     //get repeat number
			cin.get();                //ignoar space
			getline(cin,info.premsg); // get message
			info.do_encode();         // encode message
		}
		


		
	}

	return 0;
}