#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct A
{
	//acmer1.txt --->  mac name sum time
	char mac[21], name[21];
	int sum, time;
	//acmer3.txt --->  name sum online
	int online;
}a[123], temp;

int get_time()
{
	int result;
	time_t t;
	t = time(NULL);
	result = t;
	return (result/60);
}

int main()
{
	FILE *acmer1, *mac4;	//infile
	FILE *acmer2, *acmer3;	//outfile
	char MAC[21] = "0", s[123] = "0";
	int i, j, local_time, flag;
	int n; //n--->acmer数量
	
	local_time = get_time();//获取当前时间
	for(i=0; i<123; i++)
	{
		for(j=0; j<21; j++)
		{
			a[i].mac[j] = a[i].name[j] = 0;
		}
	}
	
	//读取acmer1.txt
	acmer1 = fopen("./acmer1.txt", "r");
	for(i=0; fgets(s, 123, acmer1); i++)
	{
		sscanf(s, "%s %s %d %d", a[i].mac, a[i].name, &a[i].sum, &a[i].time);
		//printf("%s %s %d %d\n", a[i].mac, a[i].name, a[i].sum, a[i].time);
		a[i].online = 0;
	}
	n = i;
	//printf("%d\n\n\n", n);
	fclose(acmer1);
	//return 0;
	mac4 = fopen("./mac4.txt", "r");
	while(~fscanf(mac4, "%s", MAC))
	{
		for(i=0; i<n; i++)
		{
			//printf("%s\n", a[i].mac);
			for(j=flag=0; j<15; j++)
			{
				if(MAC[j]!=a[i].mac[j])
				{
					flag = 1;
					break;
				}
			}
			if(strcmp(MAC, a[i].mac)==0 || flag == 0)
			{
				printf("%s\n", a[i].name);
				a[i].online = 1;
				//system("mplayer /var/www/2012.mp3");
				//if((local_time/10) > (a[i].time/10)+1)
				//{
				//	system("mplayer /var/www/2012.mp3");
				//}
				if(a[i].time/10 != local_time/10)
				{
					a[i].time = local_time;
					a[i].sum += 10;
				}
				break;
			}	
		}
		memset(MAC, 0, sizeof(MAC));
	}
	fclose(mac4);
	
	//printf("\nadwasd\n");
	//return 0;
	
	acmer2 = fopen("./acmer2.txt", "w");
	for(i=0; i<n; i++)
	{
		fprintf(acmer2, "%s %s %d %d\n", a[i].mac, a[i].name, a[i].sum, a[i].time);
	}
	fclose(acmer2);
	
	acmer3 = fopen("./acmer3.txt", "w");
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(a[j].sum > a[i].sum)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		fprintf(acmer3, "%s %d %d\n", a[i].name, a[i].sum, a[i].online);
	}
	fclose(acmer3);

	return 0;
}





