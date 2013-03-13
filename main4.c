#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ACMer
{
	char name[21];
	int sum, online;
	
	int num, up_down, solved_poj, solved_hdoj, result;
}a[123], temp;

int main()
{
	FILE *acmer4, *name_solved1, *acmer6;
	FILE *acmer5;
	char name[123] = "\0";
	int solved_poj, solved_hdoj;
	int i, j, n;
	
	if((acmer4 = fopen("./acmer4.txt", "r") ) == NULL)
	{
		printf("*** can't open acmer4.txt\n");
	}

	if((name_solved1 = fopen("./name_solved1.txt", "r") ) == NULL)
	{
		printf("*** can't open name_solved1.txt\n");
	}
	if((acmer6 = fopen("./acmer6.txt", "r") ) == NULL)
	{
		printf("*** can't open acmer6.txt\n");
	}
	
	for(i=1; ~fscanf(acmer4, "%s %d %d", a[i].name, &a[i].sum, &a[i].online); i++)
	{
		a[i].result = a[i].sum;
		a[i].solved_poj = a[i].solved_hdoj = a[i].up_down = 0;
	}
	n = i-1;
	fclose(acmer4);
	for(i=1; ~fscanf(name_solved1, "%s %d %d", name, &solved_poj, &solved_hdoj); i++)
	{
		printf("*** %s %d %d\n", name, solved_poj, solved_hdoj);
		for(j=1; j<=n; j++)
		{
			if(strcmp(name, a[j].name) == 0)
			{
				
				a[j].solved_poj = solved_poj;
				a[j].solved_hdoj = solved_hdoj;
				a[j].result = a[j].sum + a[j].solved_poj*100 + a[j].solved_hdoj*100;
				break;
			}
		}
		memset(name, 0, sizeof(name));
	}
	fclose(name_solved1);

	for(i=1; i<=n; i++)
	{
		for(j=i+1; j<=n; j++)
		{
			if(a[j].result > a[i].result)
			{
				temp = a[j], a[j] = a[i], a[i] = temp;
			}
		}
		a[i].num = i;
		printf("%d %s %d %d %d %d %d %d\n", a[i].num, a[i].name, a[i].online, a[i].sum, a[i].solved_poj, a[i].solved_hdoj, a[i].result, a[i].up_down);
	}
	printf("\n\n\n");
	for(i=1; ~fscanf(acmer6, "%d %s %d %d %d %d %d %d", &a[0].num, a[0].name, &a[0].online, &a[0].sum, &a[0].solved_poj, &a[0].solved_hdoj, &a[0].result, &a[0].up_down); i++)
	{
		for(j=1; j<=n; j++)
		{
			//printf("%d %d\n", i, j);
			if(strcmp(a[0].name, a[j].name) == 0)
			{
				if(a[j].num == a[0].num)
				{
					a[j].up_down = a[0].up_down;
				}
				else
				{
					if(a[j].num < a[0].num)
					{
						a[j].up_down = 1;
					}
					else
					{
						a[j].up_down = -1;
					}
				}
				break;
			}
		}
		memset(a[0].name, 0, sizeof(a[0].name));
	}

	fclose(acmer6);
	//return 0;
	
	if((acmer5 = fopen("./acmer5.txt", "w") ) == NULL)
	{
		printf("can't open acmer5.txt\n");
	}

	for(i=1; i<=n && fprintf(acmer5, "%d %s %d %d %d %d %d %d\n", a[i].num, a[i].name, a[i].online, a[i].sum, a[i].solved_poj, a[i].solved_hdoj, a[i].result, a[i].up_down); i++);

	fclose(acmer5);
	
	system("mv acmer5.txt acmer6.txt");


	return 0;
}
