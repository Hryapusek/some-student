#include <stdio.h>

int main()
{
    FILE *fp;
    char str[60];

    fp = fopen("file_example.txt", "w+");
    fputs("This is an example for fwrite...\n", fp);
    fclose(fp);

    fp = fopen("file_example.txt", "r");
    while (fgets(str, sizeof(str), fp) != NULL)
    {
        printf("%s", str);
    }
    fclose(fp);
}
