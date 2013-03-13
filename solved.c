#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct ACMer
{
	char name[21];
	char solved_poj[8], solved_hdoj[8], solved_cf[8];
}a[123];

char url[123] = "\0";
char name_poj[21] = "\0", name_hdoj[21] = "\0", name_cf[21] = "\0";
FILE *name_solved;

void catch_hdoj()
{
	int i, flag = 0;
	char s[1234] = "\0", *p;
	FILE *catch_hdoj;
	if( (catch_hdoj=fopen("./catch_hdoj.txt", "r")) == NULL)
        {
                printf("*** can't open catch_hdoj\n");
        }
        flag = 0;
	for(i=1; ~fscanf(catch_hdoj, "%s", s); i++)
	{
		if(i > 430)
		{
			p = strstr(s, "Solved");
			if(p != NULL)
			{
				flag = 1;
				memset(s, 0, sizeof(s));
				fscanf(catch_hdoj, "%s", s);
				p = s+13;
				while('0' <= (*p) && (*p) <= '9')
				{
					fprintf(name_solved, "%c", *p);
					printf("%c", *p);
					p ++;
				}
				fprintf(name_solved, "\n");
				printf("\n");
				break;
			}
		}
		memset(s, 0, sizeof(s));
	}
	if(flag == 0)
	{
		printf("0\n");
		fprintf(name_solved, "0\n");
	}
}

void catch_poj()
{
	int i, flag = 0;
    	char s[1234] = "\0", *p;
	FILE *catch_poj;
	if( (catch_poj=fopen("./catch_poj.txt", "r")) == NULL)
    	{
		printf("*** can't open catch_poj\n");
    	}
   	flag = 0;
   	for(i=1; ~fscanf(catch_poj, "%s", s); i++)
    	{
		if(i>200)
       		{
			p = strstr(s, name_poj);
			if(p != NULL)
			{
                		flag = 1;
               			p += strlen(name_poj)+1;
                		while('0'<=(*p) && (*p)<='9')
                		{
                    			fprintf(name_solved, "%c", *p);
					printf("%c", *p);
                    			p ++;
                		}
                		fprintf(name_solved, " ");
				printf(" ");
                		break;
            		}
           	 	memset(s, 0, sizeof(s));
        	}
    	}
    	if(flag == 0)
    	{
        	fprintf(name_solved, "0 ");
    	}
    	fclose(catch_poj);
}

void make_url_cf()
{
	char x[1234] = "wget -O catch_cf.txt http://www.codeforces.com/profile/";
	int i, j;
    	memset(url, 0, sizeof(url));
    	for(i=0; x[i]; i++)
    	{
        	url[i] = x[i];
    	}
    	for(j=0; name_cf[j]; i++, j++)
    	{
        	url[i] = name_cf[j];
    	}
}

void make_url_poj()
{
    char x[1234] = "wget -O catch_poj.txt http://poj.org/userstatus?user_id=";
    int i, j;
    memset(url, 0, sizeof(url));
    for(i=0; x[i]; i++)
    {
        url[i] = x[i];
    }
    for(j=0; name_poj[j]; i++, j++)
    {
        url[i] = name_poj[j];
    }
}

void make_url_hdoj()
{
	char x[1234] = "wget -O catch_hdoj.txt http://acm.hdu.edu.cn/userstatus.php?user=";
	int i, j;
    	memset(url, 0, sizeof(url));
    	for(i=0; x[i]; i++)
    	{
        	url[i] = x[i];
    	}
    	for(j=0; name_hdoj[j]; i++, j++)
    	{
        	url[i] = name_hdoj[j];
    	}
}

int main()
{
	int i;
	FILE *name_oj;
	name_oj = fopen("./name_oj.txt", "r");
	if(name_oj == NULL)
	{
		printf("*** can't open name_oj.txt\n");
	}
	name_solved = fopen("./name_solved.txt", "w");
	if(name_solved == NULL)
	{
		printf("*** can't open name_solved.txt\n");
	}
	for(i=1; ~fscanf(name_oj, "%s %s %s", a[i].name, name_poj, name_hdoj, name_cf); i++)
	{
		//poj
		make_url_poj();
		system(url);
		printf("%s ", a[i].name);
		fprintf(name_solved, "%s ", a[i].name);
		catch_poj();
		
		//hdoj
		make_url_hdoj();
		system(url);
		catch_hdoj();

		//cf
		//make_url_cf();
		//system(url);
		//return 0;
		//printf("%s %s %s %s\n", a[i].name, name_poj, name_hdoj, name_cf);
	}
	return 0;
}



