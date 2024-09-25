#include <stdio.h>

void DisplayStr(char arr[])
{
    printf("%s\n", arr);
}

int Length(char arr[])
{
    int len = 0;

    for (len = 0; arr[len] != '\0'; len++)
        ;

    return len;
}

void TitleCase(char arr[])
{
    if (arr[0] >= 'a' && arr[0] <= 'z')
        arr[0] = arr[0] - 32;
}

void UpperCase(char arr[])
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] >= 'a' && arr[i] <= 'z')
            arr[i] -= 32;
    }
}

void LowerCase(char arr[])
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] >= 'A' && arr[i] <= 'Z')
            arr[i] += 32;
    }
}

void main()
{
    char name[10] = "AYUSH";

    DisplayStr(name);

    LowerCase(name);

    DisplayStr(name);
}