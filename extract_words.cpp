//Author : pakhandi
//
using namespace std;

#include<bits/stdc++.h>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; i++)
#define rev(i,a,b) for(i=a; i>=b; i--)
#define scan(n) scanf("%d", &n)
#define scans(s) scanf("%s", s)
#define scanc(c) scanf("%c", &c)
#define scanp(f) scanf("%f", &f)
#define print(n) printf("%d\n", n)
#define prints(s) printf("%s\n", s)
#define printc(c) printf("%c\n", c)
#define printp(f) printf("%f\n", f)
#define nline printf("\n")
#define mclr(strn) strn.clear()
#define ignr cin.ignore()
#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int

#define PB push_back
#define SZ size

string line;

#define TOKENS 6

map<string, int> taken;


char alltoken[TOKENS]={' ', '.', ':', ',', '\t', '\n'};

string universal_set="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";


int istoken(char ele)
{
    int i;
    int flag=0;
    //cout<<ele<<" ";
    fl(i,0,TOKENS)
    {
        if(ele==alltoken[i])
            return 1;
    }

    fl(i,0,universal_set.SZ())
    {
        //cout<<universal_set[i];
        if(ele==universal_set[i])
            flag=1;
    }
    if(!flag)
        return 1;
    return 0;
}

void stream_reader(string line)
{
    int i;
    int limit=line.SZ();
    string curr;
    curr.clear();
    fl(i,0,limit)
    {
        //cout<<line[i]<<" "<<istoken(line[i]);
        //nline;
        if(curr.SZ()==0 && istoken(line[i]))
            continue;
        if(i==limit-1)
        {
            curr=curr+line[i];
            if(taken[curr]>0)
            {
                ;
            }
            else
            {
                cout<<curr; nline;
                taken[curr]++;
            }
            curr.clear();
            continue;
        }
        if(istoken(line[i]))
        {
            if(taken[curr]>0)
            {
                ;
            }
            else
            {
                cout<<curr; nline;
                taken[curr]++;
            }
            curr.clear();
            continue;
        }
        curr=curr+line[i];

    }
}


int main()
{
    nline;
	string str1;
    while(cin>>str1)
    {
        stream_reader(str1);
    }
	return 0;
}
