#include<bits/stdc++.h>

class St
{
	private:
		struct tr
		{
			char s;
			int pq;
		};
		int gusting;
		tr trs[11];
		bool f;
	public:
		St()
		{
			gusting=0;
			f = false;
		}
		void setTr(char s, int pq)
		{
			trs[gusting].s=s;
			trs[gusting].pq=pq;
			this->gusting++;
		}
		int Transition(char s)
		{
			for(int i=0;i<gusting;i++)
			{
				if(trs[i].s==s)
				{
					return trs[i].pq;
				}
			}
			return -1;
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

char alfb[100], sf[22], bb;
St st[10];
int nst, si, d, aa, cc, n;
St sa;

bool teste()
{
	char tst[201];
	int pq;
	scanf("%s", tst);
	
	for(int i=1; i<(int)strlen(tst)-1;i++)
	{
			pq = sa.Transition(tst[i]);
			if(pq>=0)
			{
				sa = st[pq-1];
			}
			else
			{
				sa = st[si-1];
				printf("N\n");
				return 0;
			}
	}
	if(sa.F())
	{
		printf("S\n");
	}
	else
	{
		printf("N\n");
	}
	sa = st[si-1];
	return 0;
}

int main()
{

	scanf("%s", alfb);

	scanf("%d", &nst);

	scanf("%d", &si);

	getchar();
	scanf("%[^\n]s", sf);
	for(int i=0; i<(int)strlen(sf);i+=2)
	{
		st[sf[i]-49].setF();
	}

	scanf("%d", &d);
	for(int i=0; i<d;i++)
	{
		scanf("%d %c %d", &aa, &bb, &cc);
		st[aa-1].setTr(bb, cc);
	}
	sa = st[si-1];
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		teste();
	}
	return 0;
}
