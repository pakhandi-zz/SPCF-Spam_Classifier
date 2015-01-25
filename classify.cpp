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

char alltoken[TOKENS]={' ', '.', ':', ',', '\t', '\n'};

int istoken(char ele)
{
    int i;
    fl(i,0,TOKENS)
    {
        if(ele==alltoken[i])
            return 1;
    }
    return 0;
}

void map_it_2(istream& stream)
{
    getline (stream,line);
    int i, limit=line.SZ();
    string curr;
    curr.clear();
    
    fl(i,0,limit)
    {
        if(istoken(line[i]))
            break;
        curr=curr+line[i];
    }
    nonspam_token[curr]=1;
    line.clear();
}

void make_map_2()
{ 
    ifstream myfile(NON_SPAM_DICT_FILE);
    if (myfile.is_open())
    {
        while (myfile.good())
        {
          map_it_2(myfile);
        }
        myfile.close();
    }
    else 
    {  
        cout << "Unable to open file"; 
    }
}

void map_it(istream& stream)
{
    getline (stream,line);
    int i, limit=line.SZ();
    string curr;
    curr.clear();
    
    fl(i,0,limit)
    {
        if(istoken(line[i]))
            break;
        curr=curr+line[i];
    }
    spam_token[curr]=1;
    line.clear();
}

void make_map()
{ 
    ifstream myfile (SPAM_DICT_FILE);
    if (myfile.is_open())
    {
        while (myfile.good())
        {
          map_it(myfile);
        }
        myfile.close();
    }
    else 
    {  
        cout << "Unable to open file"; 
    }
}


int main()
{
    freopen("classified.txt","w", stdout);
    make_map();
    make_map_2();
    string str1;
    while(cin>>str1)
    {
        if(spam_token[str1]>0)
            spamcount++;
        if(nonspam_token[str1]>0)
            nonspamcount++;
    }
    cout<<spamcount<<" "<<nonspamcount;
    nline;
	return 0;
}
