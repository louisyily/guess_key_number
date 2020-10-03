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

Buffer 就是指输入的 s 字符串的首字母，其地址是 sp+1Ch，而后续的字符变

量 v2 是 sp+1Dh、v3 是 sp+1Fh、v4 是 sp+20h、v5 是 sp+24h。

由此可知：Buffer 是第一个数字字符，v2、v3、v4、v5 分别是第二、四、五、

九 个 字 符 。 所 以 判 断 的 逻 辑 就 是 ： 字 符 串 的 长 度 <=0x12=18 、 并 且

number[0]==number[1]、number[3]==number [4]、nmber[8]==57==’9’。

v0=v3-48，所以 v0 代表第四个数字。

判断 v0 的数值：

如果是 5，输出 VjdXJpdHl9；

如果是 7，输出 ZmxhZ3tpbmZv；

如果是 4，输出 cm1hdGlvbl9fc2；

可知这三个就是 key 的三个分段，尝试排列组合：

cm1hdGlvbl9fc2 ZmxhZ3tpbmZv VjdXJpdHl9

cm1hdGlvbl9fc2 VjdXJpdHl9 ZmxhZ3tpbmZv

ZmxhZ3tpbmZv VjdXJpdHl9 cm1hdGlvbl9fc2

ZmxhZ3tpbmZv cm1hdGlvbl9fc2 VjdXJpdHl9

VjdXJpdHl9 ZmxhZ3tpbmZv cm1hdGlvbl9fc2

VjdXJpdHl9 cm1hdGlvbl9fc2 ZmxhZ3tpbmZv

其中，ZmxhZ3tpbmZvcm1hdGlvbl9fc2VjdXJpdHl9 可以通过 base64 解码得到：

flag{information__security}

夺旗成功。

