#include<bits/stdc++.h>

struct tr
		{
			char l;
			char e;
			char dir;
			int pq;
		};

class St
{
	private:
		
		int gusting;
		tr trs[200000];
		bool f;
	public:
		St()
		{
			gusting=0;
			f = false;
		}
		int getGusting()
		{
			return gusting;
		}
		void setTr(char l, char e, char dir, int pq)
		{
			trs[gusting].l=l;
			trs[gusting].e=e;
			trs[gusting].dir=dir;
			trs[gusting].pq=pq;
			this->gusting++;
		}
		tr *getTr()
		{
			return trs;
		}
		void setF()
		{	
			f=true;
		}
		bool F()
		{
			return f;
		}
};

char ssi, ssj, dir, alfb[100], alfbf[100], sf[22], bb, strin[201];
St st[10];
int nst, ntr, si, d, aa, cc, n, st1, st2;
St sa;


bool teste(int cur, char stringe[], int idx, char cg, int prevdir)
{
	stringe[idx-(prevdir)]=cg;
	tr *vet=st[cur-1].getTr();
	if(st[cur].F())
	{
		//printf("c");
		*strin = *stringe;
		//printf("%s\n", stringe);
		return 1;
	}
	
	for(int i=0;i<st[cur-1].getGusting();i++)
	{
		//printf("%c       %c   %d    %d", stringe[idx], vet[i].l, vet[i].pq, idx);
		if(idx<(int)strlen(stringe) && idx >= 0) 
		{
			if(vet[i].l==stringe[idx])
			{
		
				if(vet[i].dir=='D')
				{

					if(teste(vet[i].pq,stringe,idx+1, vet[i].e,1) == 1)
					{
						
						return 1;
					}
				}
				else if(vet[i].dir=='E')
				{
					if(teste(vet[i].pq,stringe,idx-1, vet[i].e,-1) == 1)
					{
						return 1;
					}
				}
			}
		}	
	}
	//printf("b");
	//printf("%s\n", stringe);
	*strin = *stringe;
	return 0;
}

int main()
{
	scanf("%s", alfb);
	getchar();
	scanf("%s", alfbf);
	getchar();
	scanf("%d", &nst);
	scanf("%d", &si);
	scanf("%s", sf);
	getchar();
 	for(int i = 0; i < (int)strlen(sf);i+=2)
	{
		st[sf[i]-48].setF();
	}
	scanf("%d", &ntr);
	for(int i = 0; i < ntr; i++)
	{
		scanf("%d %c %c %c %d", &st1, &ssi, &ssj, &dir, &st2); 
		if(ssi=='$')
		{
			ssi='@';
		}
		if(ssj=='$')
		{
			ssj='@';
		}
		st[st1-1].setTr(ssi, ssj, dir, st2);
	}
	scanf("%d", &d);
	for(int i = 0;i<d;i++)
	{
		scanf("%s", strin);
		getchar();
		
		if(teste(si, strin, 0, '@', 0))
		{
			printf("%s\n", strin);
			printf("S\n");
		}
		else
		{
			printf("%s\n", strin);
			printf("N\n");
		}
	}
	
	
	return 0;
}
