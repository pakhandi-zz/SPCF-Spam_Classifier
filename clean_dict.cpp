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

#define SPAM_DICT_FILE "spam_dict.txt"
#define NON_SPAM_DICT_FILE "nonspam_dict.txt"

string line, fname;

map<string,int> spam_token, nonspam_token;

#define TOKENS 6

int spamcount, nonspamcount;

string allletters="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int isletter(char ele)
{
    int i;
    int limit = allletters.SZ();
    fl(i,0,limit)
    {
        if(ele == allletters[i])
            return 1;
    }
    return 0;
}

map<string, int> mp;

int main()
{
    string str1;
    int i;
    while(cin>>str1)
    {
        int inlimit = str1.SZ();
        fl(i,0,inlimit)
        {
            if(isletter(str1[i]))
            {
                str1[i]=(char)(int(str1[i])+32);
            }
        }
        mp[str1]=1;
    }
    map<string,int>::const_iterator itr = mp.begin();
    for( ; itr!=mp.end(); itr++)
    {
        cout<<itr->first;
        nline;
    }
	return 0;
}
