#include <stdio.h>
#include <string.h>
char s1[105], s2[105];
int a1[105], a2[105], b1[210], b2[210], b[210];
void jf(int b1[], int b2[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (b1[i] >= b2[i])
            b[i] = b1[i] - b2[i];
        else
        {
            b[i] = b1[i] + 10 - b2[i];
            b1[i + 1] -= 1;
        }
    }
    for (i = len - 1; i >= 0; i--)
    {
        if (b[i] == 0)
            len -= 1;
        else
            break;
    }
    for (i = len - 1; i >= 0; i--)
    {
        printf("%d", b[i]);
    }
}
int main()
{
    scanf("%s\n%s", s1, s2);
    int i, j;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (s1[0] == '-')
    {
        len1 -= 1;
        for (i = 0; i < len1; i++)
        {
            s1[i] = s1[i + 1];
        }
    }
    if (s2[0] == '-')
    {
        len2 -= 1;
        for (i = 0; i < len2; i++)
        {
            s2[i] = s2[i + 1];
        }
    }
    for (i = 0; i < len1; i++)
    {
        a1[i] = s1[len1 - 1 - i] - '0';
    }
    for (i = 0; i < len2; i++)
    {
        a2[i] = s2[len2 - 1 - i] - '0';
    }
    int k = 0;
    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len1 || k; j++)
        {
            int t = b1[i + j] + a1[i] * a1[j] + k;
            b1[i + j] = t % 10;
            k = t / 10;
        }
    }
    int len3 = i + j - 1;
    k = 0;
    for (i = 0; i < len2; i++)
    {
        for (j = 0; j < len2 || k; j++)
        {
            int t = b2[i + j] + a2[i] * a2[j] + k;
            b2[i + j] = t % 10;
            k = t / 10;
        }
    }
    int len4 = i + j - 1;
    if (len3 > len4)
    {
        jf(b1, b2, len3);
        return 0;
    }
    else if (len3 < len4)
    {
        printf("-");
        jf(b2, b1, len4);
        return 0;
    }
    else
    {
        for (i = len3 - 1; i >= 0; i--)
        {
            if (b1[i] == b2[i])
            {
                continue;
            }
            else if (b1[i] > b2[i])
            {
                jf(b1, b2, len3);
                return 0;
            }
            else
            {
                printf("-");
                jf(b2, b1, len3);
                return 0;
            }
        }
        if (i < 0)
        {
            printf("0");
        }
    }
    return 0;
}