#include<bits/stdc++.h>

struct tr
{
	char s;
	char pq;
};

class St
{
	private:
		
		int gusting;
		tr trs[50];
	public:
		St()
		{
			gusting=0;
		}
		void setTr(char s, char pq)
		{
			trs[gusting].s=s;
			trs[gusting].pq=pq;
			this->gusting++;
		}
		tr *getTr()
		{
			return trs;
		}
		int getGusting()
		{
			return gusting;
		}
};

char alfb[100], sts[30], aa, bb, cc, si, strin[200], prod[10];
St st[50];
int np, ns;

bool teste(char cur, char *stringe, int idx)
{
	tr *vet = st[cur-65].getTr();
	for(int i=0;i<st[cur-65].getGusting();i++)
	{
		if(vet[i].s==stringe[idx])
		{
			if(vet[i].pq=='#')
			{
				if(stringe[idx+1]=='@')
					return 1;
			}
			else if(teste(vet[i].pq,stringe,idx+1) == 1)
			{
				return 1;
			}
		}
		else if(vet[i].s=='#')
		{
			if(stringe[idx]=='@')
				return 1;
		}
	}
	return 0;		
}

int main()
{
	scanf("%s", sts);
	getchar();
	scanf("%s", alfb);
	getchar();
	scanf("%c", &si);
	getchar();
	scanf("%d", &np);
	for(int i=0;i<np;i++)
	{
		getchar();
		scanf("%[^\n]s", prod);

		aa=prod[0];
		bb=prod[5];
		if(prod[6]==0)
		{
			cc='#';
		}
		else
		{
			cc=prod[6];
		}
	
		st[aa-65].setTr(bb,cc);
	}	
	
	scanf("%d", &ns);
	for(int i=0;i<ns;i++)
	{
		scanf("%s", strin);
		getchar();
		if(teste(si,strin,1))
		{
			printf("S\n");
		}
		else
		{
			printf("N\n");
		}
	}
	return 0;
}
