#include <stdio.h>
#include <windows.h>
#include <string>

int main(int argc, char* argv)
{
    printf("**input any number to guess 3 key segments**\n");
    while(1)
    {
        char key[MAX_PATH];
        printf("guess_key:");
        gets(key);
        if(strlen(key)>18)
        {
            printf("too long\n");
            continue;
        }
        if(key[0]==key[1]&&key[3]==key[4]&&key[8]=='9')
        {
            int num=int(key[4])-'0';
            switch(num)
            {
                case 4:printf("get a segment:cm1hdGlvbl9fc2\n");break;
                case 5:printf("get a segment:VjdXJpdHl9\n");break;
                case 7:printf("get a segment:ZmxhZ3tpbmZv\n");break;
                default:printf("wrong, try again...\n");break;
            }//ZmxhZ3tpbmZv cm1hdGlvbl9fc2 VjdXJpdHl9
        }
        else
        {
            printf("wrong, try again...\n");
        }
    }
    return 0;
}
