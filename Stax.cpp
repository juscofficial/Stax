#include <bits/stdc++.h>
using namespace std;

char s[2][4]={{'0','0','0','0'}, {'0','0','0','0'}};
int top[2]={0};

void stax(char giv[], char ran[])
{
	int i=0, j=0, k;
	while(j<2)
	{
		s[j][top[j]] = ran[i];
		if(ran[i]==giv[0] || i==3)	j++;						
		else	top[j]++;
		i++;
	}
	i=1, j=0, k=2;	
	ran[3] = s[0][top[0]--];
	while(i<4)
	{
		if(s[0][top[0]]==giv[i] && top[0]>=0)
		{
			ran[k]=s[0][top[0]--];			
			k--;
			i++;
		}		
		else if(s[1][top[1]]==giv[i] && top[1]>=0)
		{
			ran[k]=s[1][top[1]--];			
			k--;
			i++;
		}
		else
		{
			if(top[0]>0)	s[1][++top[1]]=s[0][top[0]--];
			else if(top[1]>0)	s[0][++top[0]]=s[1][top[1]--];
		}
	}
}

int main()
{
	char giv[]="gbyr", ran[]="ygrb";
	stax(giv, ran);
	puts(ran);
	return 0;
}
