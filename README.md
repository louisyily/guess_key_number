# guess_key_number

程序要求输入任何数字去猜测 key 的 3 个分段。

使用 IDA 打开，F5 反编译：


    void __noreturn sub_401C10()
    {
        int v0; // eax@8
        char Buffer; // [sp+1Ch] [bp-108h]@2
        char v2; // [sp+1Dh] [bp-107h]@3
        char v3; // [sp+1Fh] [bp-105h]@4
        char v4; // [sp+20h] [bp-104h]@4
        char v5; // [sp+24h] [bp-100h]@7

        sub_4018F0();
        puts("**input any number to guess 3 key segments**");
        while ( 1 )
        {
            while ( 1 )
            {
                while ( 1 )
                {
                    printf("guess_key:");
                    gets(&Buffer);
                    if ( strlen(&Buffer) <= 0x12 )
                        break;
                    puts("too long");
                }
                if ( Buffer == v2 && v3 == v4 && v5 == 57 )
                    break;
                LABEL_5:
                puts("wrong, try again...");
            }
            v0 = v3 - 48;
            if ( v0 == 5 )
            {
                puts("get a segment:VjdXJpdHl9");
            }
            else if ( v0 == 7 )
            {
                puts("get a segment:ZmxhZ3tpbmZv");
            }
            else
            {
                if ( v0 != 4 )
                    goto LABEL_5;
                puts("get a segment:cm1hdGlvbl9fc2");
            }
        }
    }

Buffer就是指输入的s字符串的首字母，其地址是sp+1Ch，而后续的字符变量v2是sp+1Dh、v3是sp+1Fh、v4是sp+20h、v5是sp+24h。

由此可知：Buffer是第一个数字字符，v2、v3、v4、v5分别是第二、四、五、九个字符。所以判断的逻辑就是：字符串的长度<=0x12=18、并且number[0]==number[1]、number[3]==number [4]、nmber[8]==57==’9’。

v0=v3-48，所以v0代表第四个数字。

判断v0的数值：

如果是5，输出VjdXJpdHl9；
如果是7，输出ZmxhZ3tpbmZv；
如果是4，输出cm1hdGlvbl9fc2；

可知这三个就是key的三个分段，尝试排列组合：

cm1hdGlvbl9fc2  ZmxhZ3tpbmZv  VjdXJpdHl9

cm1hdGlvbl9fc2  VjdXJpdHl9  ZmxhZ3tpbmZv

ZmxhZ3tpbmZv  VjdXJpdHl9  cm1hdGlvbl9fc2

ZmxhZ3tpbmZv  cm1hdGlvbl9fc2  VjdXJpdHl9

VjdXJpdHl9  ZmxhZ3tpbmZv  cm1hdGlvbl9fc2

VjdXJpdHl9  cm1hdGlvbl9fc2  ZmxhZ3tpbmZv

其中，ZmxhZ3tpbmZvcm1hdGlvbl9fc2VjdXJpdHl9可以通过base64解码得到：
flag{information__security}

夺旗成功。

