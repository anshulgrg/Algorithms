#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d\n" , &t);
    while(t != 0 )
    {
        char c ;
        char str[100] ;
        int i=0;
        while ((c = getchar()) != '\n')
        {
            str[i] = c;
            i++;
        }
        str[i] = '\n';
        printf("%s" , str);
        int n =  strlen(str);
        int j ;
        for( j = n-1 ; j >= 0 ; j--)
        {
            if(str[j] > str[j-1])
            {
                char t;
                t = str[j];
                str[j] = str[j-1];
                str[j-1] = t;
                            
            }
        }
        printf("%s" , str);
        t--; 
    }
    return 0;
}
