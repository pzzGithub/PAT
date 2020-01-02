#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int ascii[128] = {0};
    char str1[81], str2[81];
    scanf("%s", str1);
    scanf("%s", str2);

    //change lowercase letters to uppercase
    for (int i = 0; i < strlen(str1); i++)
        str1[i] = toupper(str1[i]);
    for (int i = 0; i < strlen(str2); i++)
        str2[i] = toupper(str2[i]);

    //第一轮，正确的字符串，每出现一个字符，该字符ascii码为索引的数组的值+1
    for (int i = 0; i < strlen(str1); i++)
        ascii[toupper(str1[i])]++;

    //第二轮，真实的字符串，每出现一个字符，该字符ASCII码为索引的数组的值-1
    for (int i = 0; i < strlen(str2); i++)
        ascii[toupper(str2[i])]--;

    //按原始字符串的顺序，逐个确定该ASCII数组的值，大于0则缺键
    for (int i = 0; i < strlen(str1); i++)
    {
        if (ascii[str1[i]] > 0) {
            printf("%c", str1[i]);
            ascii[str1[i]] = 0;
        }
    }

    return 0;
}