#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *mac2, *mac3;
    char s[123] = "0", MAC[21] = "0", temp[123];
    mac2 = fopen("./mac2.txt", "r");
    mac3 = fopen("./mac3.txt", "w");
    while(fgets(s, 123, mac2))
    {
        if(s[0] == 'M')
        {
            sscanf(s, "%s%s%s", temp, temp, MAC);
            printf("%s\n", MAC);
            fprintf(mac3, "%s\n", MAC);
            memset(MAC, 0, sizeof(MAC));
        }
        memset(s, 0, sizeof(s));
    }
    fclose(mac2);
    fclose(mac3);
    return 0;
}

