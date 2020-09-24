/* 程序名：__hy__.h，此程序是hy框架公用函数和类的声明文件。
   作者：何岩(imheyan@163.com) 日期：20210807。

   hy开源许可协议正文如下：
         版权所有 (c) 2008-2020，何岩（imheyan@163.com）。
         特此向任何得到本软件副本或相关文档的人授权：被授权人有权使用、复制、修改、
      合并、出版、发布、散布、再授权和/或贩售软件及软件的副本，及授予被供应人同等
      权利，只需服从以下义务：
         在软件和软件的所有副本中都必须包含以上版权声明和本许可声明。
         如果违返，无论在本软件的使用上或其他买卖交易中是否涉及合同，都属于侵权行为，
     我们保留追究的权利。
   hy开源许可协议正文结束。  */
#include "__hy__.h"

// 求int整数的绝对值
int ABS(const int j)
{
	if (j < 0)
	{
		return (-1) * j;
	}
	else
	{
		return j;
	}
}
// 求long整数的绝对值
long LABS(const long int j)
{
	if (j < 0)
	{
		return (-1) * j;
	}
	else
	{
		return j;
	}
}

/* 用于把数字的字符转换为整数，chr为用字符方式表示的数字，函数的返回值为数字的整数。
   如果chr不是数字的字符，函数返回-1。  */
int ctoi(const char chr)
{
	switch (chr)
	{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return -1;
	}
}
long POW(int x, int y)
{
    long power = 1;

    for (int i = 0; i < y; i++)
    {
        power *= x;
    }

    return power;
}
// 把字符串nptr转换为int整数
int ATOI(const char *nptr)
{
	// "12305"
	//  1 * (10 ^ (len - 1 - i)) +
	//   2 * (10 ^ (len - 1 - i)) +
	//    3 * (10 ^ (len - 1 - i)) +
	//     0 * (10 ^ (len - 1 - i)) +
	//      5 * (10 ^ (len - 1 - i))
	int sum = 0;
	int tmp = 0;
	int len = strlen(nptr);

	for (int i = 0; i < len; i++)
	{
		tmp = ctoi(nptr[i]);
		if ((0 <= tmp) && (9 >= tmp))
		{
			sum += tmp * (POW(10, len - 1 - i));
		}
	}
	if (nptr[0] == '-')
	{
		return (-1) * sum;
	}
	return sum;
}
// 把字符串nptr转换为long整数
long ATOL(const char *nptr)
{
	// "12305"
	//  1 * (10 ^ (len - 1 - i)) +
	//   2 * (10 ^ (len - 1 - i)) +
	//    3 * (10 ^ (len - 1 - i)) +
	//     0 * (10 ^ (len - 1 - i)) +
	//      5 * (10 ^ (len - 1 - i))
	long sum = 0;
	int tmp = 0;
	int len = strlen(nptr);

	for (int i = 0; i < len; i++)
	{
		tmp = ctoi(nptr[i]);
		if ((0 <= tmp) && (9 >= tmp))
		{
			sum += tmp * (POW(10, len - 1 - i));
		}
	}
	if (nptr[0] == '-')
	{
		return (-1) * sum;
	}
	return sum;
}
// 把字符串nptr转换为double小数
double ATOD(const char *nptr)
{
    return 0;
}
// 函数名称：createNoRepeatArray
// 函数功能：产生没有重复数字的整数数组（low～high）
// const int low：最小的随机数
// const int high：最大的随机数
// const int array：随机数组的名称
// 没有返回值
void createNoRepeatArray(const int low, const int high, int *array)
{
    int len = high - low + 1;
    
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
A:
        array[i] = rand() % len + low;
        for (int j = 0; j < i; j++)
        {
            if (array[i] == array[j])
            {
                goto A;
            }
        }
    }
}

// 若ch是字母（'A'-'Z','a'-'z'）返回非0值，否则返回0。
int ISALPHA(int ch)
{
    if (((ch <= 'Z') && (ch >= 'A')) || ((ch <= 'z') && (ch >= 'a')))
    {
        return 1024;
    }
    return 0;
}
// 若ch是字母（'A'-'Z','a'-'z'）或数字（'0'-'9'），返回非0值,否则返回0。
int ISALNUM(int ch)
{
    if (((ch <= 'Z') && (ch >= 'A')) || ((ch <= 'z') && (ch >= 'a')) || ((ch <= '9') && (ch >= '0')))
    {
        return 1024;
    }
    return 0;
}
// 若ch是数字（'0'-'9'）返回非0值，否则返回0。
int ISDIGIT(int ch)
{
    if ((ch <= '9') && (ch >= '0'))
    {
        return 1024;
    }
    return 0;
}
// 若ch是小写字母（'a'-'z'）返回非0值，否则返回0。
int ISLOWER(int ch)
{
    if ((ch <= 'z') && (ch >= 'a'))
    {
        return 1024;
    }
    return 0;
}
// 若ch是大写字母（'A'-'Z'）返回非0值，否则返回0。
int ISUPPER(int ch)
{
    if ((ch <= 'Z') && (ch >= 'A'))
    {
        return 1024;
    }
    return 0;
}
// 若ch是大写字母（'A'-'Z'）返回相应的小写字母（'a'-'z'）。
int TOLOWER(int ch)
{
    if ((ch <= 'Z') && (ch >= 'A'))
    {
        return ch + 32;
    }
    return 0;
}
// 若ch是小写字母（'a'-'z'）返回相应的大写字母（'A'-'Z'）
int TOUPPER(int ch)
{
    if ((ch <= 'z') && (ch >= 'a'))
    {
        return ch - 32;
    }
    return 0;
}
// chr为用字符方式表示的数字，函数的返回值为数字的整数。
int c09toi09(const char chr)
{
    return chr - '0';
}
/*
 *****************************************************C语言浮点数****************************************************
 */
// 求双精度实数x的绝对值
double FABS(const double x)
{
    if (x < 0)
    {
        return (-1) * x;
    }
    return x;
}
// double舍小数，取整数
double RoundDecimal(const double x)
{
    return (int)x;
}
// double四舍五入
double ROUND(const double x)
{
    double dd = FABS(x);
    double ddd = RoundDecimal(dd);

    if (dd - RoundDecimal(dd) >= 0.5)
    {
        ddd = RoundDecimal(dd) + 1;
    }

    return (x >= 0) ? ddd : (-1) * ddd;
}
// double向上取整数
double CEIL(const double x)
{
    return 1 + RoundDecimal(x);
}
// double向下取整数
double FLOOR(const double x)
{
    return -1 + RoundDecimal(x);
}
// 把双精度val分解成整数部分和小数部分，整数部分存放在ip所指的变量中，返回小数部分。
double MODF(double val, double *ip)
{
    *ip = RoundDecimal(val);
    return FABS(val - *ip);
}
/*
 *****************************************************C语言字符串****************************************************
 */
// 实现strlen函数的功能。
size_t STRLEN(const char*  str)
{
    unsigned long ul;

    for (ul= 0; str[ul] != '\0'; ul++)
    {
        ;
    }

    return ul;
}
// 实现strcpy函数的功能，下同。
// ???
char *STRCPY(char* dest, const char* src)
{
    unsigned long ul;

    for (ul = 0; src[ul] != '\0'; ul++)
    {
        dest[ul] = src[ul];
    }
    dest[ul] = '\0';

    return dest;
}
// 功能：把src前n字符的内容复制到dest中
// 返回值：dest字符串起始地址。
// 如果src字符串长度小于n，则拷贝完字符串后，在dest后追加0，直到n个。
// 如果src的长度大于等于n，就截取src的前n个字符，不会在dest后追加0。
// dest必须有足够的空间放置n个字符，否则可能会造成缓冲溢出的错误情况。
char *STRNCPY(char* dest, const char* src,size_t n)
{
    unsigned long ul;
    
    for (ul = 0; src[ul] != '\0' && ul < n; ul++)
    {
        dest[ul] = src[ul];
    }
    if (ul < n)
    {
        dest[ul] = '\0';
        ul++;
    }
    return dest;
}
// 功能：将src字符串拼接到dest所指的字符串尾部。
// 返回值：返回dest字符串起始地址。
// dest最后原有的结尾字符0会被覆盖掉，并在连接后的字符串的尾部再增加一个0。
// dest要有足够的空间来容纳要拼接的字符串，否则可能会造成缓冲溢出的错误情况。
char *STRCAT(char* dest, const char* src)
{
    unsigned long ul;
    unsigned long uld;

    for (uld = 0; dest[uld] != '\0'; uld++)
    {
        ;
    }

    for (ul = 0;src[ul] != '\0'; uld++, ul++)
    {
        dest[uld] = src[ul];
    }

    return dest;
}
// 功能：将src字符串的前n个字符拼接到dest所指的字符串尾部。
// 返回值：返回dest字符串的起始地址。
// 如果n大于等于字符串src的长度，那么将src全部追加到dest的尾部，如果n大于字符串src的长度，只追加src的前n个字符。
// strncat会将dest字符串最后的0覆盖掉，字符追加完成后，再追加0。
// dest要有足够的空间来容纳要拼接的字符串，否则可能会造成缓冲溢出的错误情况。
char *STRNCAT(char* dest, const char* src,size_t n)
{
    unsigned long uld;
    for (uld = 0; dest[uld] != '\0'; uld++)
    {
        ;
    }

    unsigned long ul;
    for(ul = 0; src[ul] != '\0' && ul < n; uld++, ul++)
    {
        dest[uld] = src[ul];
    }

    if (ul < n)
    {
        dest[uld] = 0;
        ul++;
    }

    return dest;
}
// 返回一个指向在字符串s中第一个出现c的位置，如果找不到，返回0。
char *STRCHR(const char *s, const int c)
{
    unsigned long ul;

    for (ul = 0; s[ul] != 0; ul++)
    {
        if (c == s[ul])
        {
            return (char *)s + ul;
        }
    }

    if (s[ul] == 0)
    {
        return 0;
    }

    return 0;
}
// 返回一个指向在字符串s中最后一个出现c的位置，如果找不到，返回0。
char *STRRCHR(const char *s, const int c)
{
    long ul;

    for (ul = 0; s[ul] != 0; ul++)
    {
        ;
    }
    // printf("ul = %d。\n", ul);

    for (ul = ul - 1; s[ul] != c && ul >= 0; ul--)
    {
        ;
    }

    if (c == s[ul] && ul >= 0)
    {
        return (char *)s + ul;
    }

    return 0;
}
// 功能：比较str1和str2的大小;返回值：相等返回0，str1大于str2返回1，str1小于str2返回-1；
int STRCMP(const char *str1, const char *str2 )
{
    unsigned long ul1;
    unsigned long ul2;
    unsigned long ul3;

    for (ul1 = 0; str1[ul1] != '\0'; ul1++)
    {
        ;
    }
    for (ul2 = 0; str2[ul2] != '\0'; ul2++)
    {
        ;
    }

    ul3 = 0;
    while (ul3 < (ul1 < ul2 ? ul1 : ul2))
    {
        if (str1[ul3] - str2[ul3] > 0)
        {
            return 1;
        }
        if (str1[ul3] - str2[ul3] < 0)
        {
            return -1;
        }
        ul3++;
    }
    if (ul1 > ul2)
    {
        return 1;
    }
    else if (ul1 < ul2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
// 功能：比较str1和str2的大小;
// 返回值：相等返回0，str1大于str2返回1，str1小于str2返回-1；
// 两个字符串比较的方法是比较字符的ASCII码的大小，从两个字符串的第一个字符开始，如果分不出大小，就比较第二个字符，
// 如果全部的字符都分不出大小，就返回0，表示两个字符串相等。
// 在实际开发中，程序员一般只关心字符串是否相等，不关心哪个字符串更大或更小。
int STRNCMP(const char *str1, const char *str2, const size_t n)
{
    if (n == 0)
    {
        return 0;
    }

    unsigned long uli = 0;

    for (; str1[uli] == str2[uli] && uli < n; uli++)
    {
        ;
    }
    if (str1[uli] != str2[uli] && uli < n)
    {
        return str1[uli] - str2[uli];
    }
    if (uli == n)
    {
        return 0;
    }

    return 0;
}
// 功能：检索子串在字符串中首次出现的位置。
// 返回值：返回字符串str中第一次出现子串substr的地址；如果没有检索到子串，则返回0。
char *STRSTR(const char* str, const char* substr)
{
    unsigned long str_len;
    unsigned long substr_len;
    unsigned long ull;

    for (str_len = 0; str[str_len] != '\0'; str_len++)
    {
        ;
    }
    for (substr_len = 0; substr[substr_len] != '\0'; substr_len++)
    {
        ;
    }

    if (substr_len > str_len)
    {
        // 子串较长
        return 0;
    }
    else if (substr_len == str_len)
    {
        // 长度相等
        for (ull = 0; ull < substr_len; ull++)
        {
            if (substr[ull] != str[ull])
            {
                return 0;
            }
        }
        if (ull == substr_len)
        {
            return (char *)str;
        }
    }
    else
    {
        // 子串的长度较小
        for (ull = 0; ull <= str_len - substr_len; ull++)
        {
            if (STRNCMP(str + ull, substr, substr_len) == 0)
            {
                return (char *)str + ull;
            }
        }
        if (ull > str_len - substr_len)
        {
            return 0;
        }
    }

    return 0;
}
// 丰富您的函数库，增加STRCPY、STRNCPY、STRCAT、STRNCAT四个安全的函数，弥补库函数的缺陷，解决dest的初始化和内存越界的问题，函数的声明如下：
// 注意，上述函数的第二个参数destsize是第一个参数dest占用内存的字节数。
char *SAFESTRCPY(char *dest, const size_t destsize, const char *src)
{
    if (dest == 0)
    {
        return 0;
    }
    if (src == 0)
    {
        return 0;
    }
    unsigned long ulmin = 0;
    ulmin = (destsize - 1) < strlen(src) ? (destsize - 1) : strlen(src);

    memset(dest, 0, destsize);
    strncpy(dest, src, ulmin);

    dest[ulmin + 1] = '\0';

    return dest;
}
char *SAFESTRNCPY(char* dest, const size_t destsize, const char* src, size_t n)
{
    unsigned long ul;
    unsigned long src_len;

    for (src_len = 0; src[src_len] != '\0'; src_len++)
    {
        ;
    }

    if (n >= src_len)
    {
        for (ul = 0; ul < (src_len < destsize - 1 ? src_len : destsize - 1); ul++)
        {
            dest[ul] = src[ul];
        }
    }
    else
    {
        for (ul = 0; ul < (n < destsize - 1 ? n : destsize - 1); ul++)
        {
            dest[ul] = src[ul];
        }
    }

    return dest;
}
char *SAFESTRCAT(char* dest, const size_t destsize, const char* src)
{
    unsigned long dest_len;
    unsigned long src_len;
    unsigned long delta;
    unsigned long min;
    unsigned long ul;

    for (dest_len = 0; dest[dest_len] != '\0'; dest_len++)
    {
        ;
    }
    for (src_len = 0; src[src_len] != '\0'; src_len++)
    {
        ;
    }
    delta = destsize - dest_len;
    delta--;

    min = delta < src_len ? delta : src_len;
    for (ul = 0; ul < min; ul++)
    {
        dest[dest_len] = src[ul];
        dest_len++;
    }

    return dest;
}
char *SAFESTRNCAT(char* dest, const size_t destsize, const char* src, size_t n)
{
    unsigned long dest_len;
    unsigned long src_len;
    unsigned long delta;
    unsigned long min;
    unsigned long ul;

    for (dest_len = 0; dest[dest_len] != '\0'; dest_len++)
    {
        ;
    }
    for (src_len = 0; src[src_len] != '\0'; src_len++)
    {
        ;
    }
    src_len = src_len < n ? src_len : n;
    delta = destsize - dest_len;
    delta--;

    min = delta < src_len ? delta : src_len;
    for (ul = 0; ul < min; ul++)
    {
        dest[dest_len] = src[ul];
        dest_len++;
    }

    return dest;
}
// 删除字符串左边指定的字符
void DeleteLChar(char *str,const char in_char)
{
    unsigned long ul;
    unsigned long str_len;

    for (str_len = 0; str[str_len] != '\0'; str_len++)
    {
        ;
    }

    for (ul = 0; str[ul] != in_char && ul < str_len; ul++)
    {
        ;
    }
    
    if (ul == str_len)
    {
        ;
    }
    else
    {
        while (ul < str_len - 1)
        {
            str[ul] = str[ul + 1];
            ul++;
        }
        str[str_len - 1] = '\0';
    }
}
// 删除字符串右边指定的字符
void DeleteRChar(char *str,const char in_char)
{
    unsigned long ul;
    unsigned long str_len;

    for (str_len = 0; str[str_len] != '\0'; str_len++)
    {
        ;
    }

    for (ul = str_len - 1; str[ul] != in_char && ul >= 0; ul--)
    {
        ;
    }
    
    if (ul == -1)
    {
        ;
    }
    else
    {
        while (ul < str_len - 1)
        {
            str[ul] = str[ul + 1];
            ul++;
        }
        str[str_len - 1] = '\0';
    }
}
// 删除字符串两边指定的字符
void DeleteLRChar(char *str,const char in_char)
{
    unsigned long left;
    unsigned long right;
    unsigned long str_len;
    long left_index;
    long right_index;

    for (str_len = 0; str[str_len] != '\0'; str_len++)
    {
        ;
    }

    left = 0;
    right = str_len - 1;
    left_index = -1;
    right_index = -1;

    while (left <= right)
    {
        if (str[left] == in_char)
        {
            // 左边已经找到
            left_index = left;
        }
        if (str[right] == in_char)
        {
            // 右边已经找到
            right_index = right;
        }
        if (left_index == -1)
        {
            left++;
        }
        if (right_index == -1)
        {
            right--;
        }
        if (left_index != -1 && right_index != -1)
        {
            break;
        }
    }

    if (left > right)
    {
        ;
    }
    else if (left_index == right_index && str[left_index] == in_char)
    {
        for (; str[left_index] != '\0'; left_index++)
        {
            str[left_index] = str[left_index + 1];
        }
        str[left_index - 1] = '\0';
    }
    else
    {
        DeleteLChar(str, in_char);
        DeleteRChar(str, in_char);
    }
}
// 删除字符串中间的字符串
void DeleteMStr(char *str, const char *in_str)
{
    unsigned long str_len;
    unsigned long in_str_len;
    unsigned long ul;
    char *str1 = 0;


    for (str_len = 0; str[str_len] != '\0'; str_len++)
    {
        ;
    }
    for (in_str_len = 0; in_str[in_str_len] != '\0'; in_str_len++)
    {
        ;
    }
    str1 = STRSTR(str, in_str);
    if (0 == str1)
    {
        ;
    }
    else
    {
        for (ul = 0; str1[ul + in_str_len] != '\0'; ul++)
        {
            str1[ul] = str1[ul + in_str_len];
        }
        str[str_len - in_str_len] = '\0';
    }
}
// 在字符串的左边补字符到指定长度
void LPad(char *str, const char in_char, unsigned int in_len)
{
    unsigned long str_len;
    long ul;

    for (str_len = 0; str[str_len] != '\0'; str_len++)
    {
        ;
    }
    
    if (in_len <= str_len)
    {
        ;
    }
    else
    {
        for (ul = str_len - 1; ul >= 0; ul--)
        {
            str[ul + in_len - str_len] = str[ul];
        }
        for (ul = 0; ul < in_len - str_len; ul++)
        {
            str[ul] = in_char;
        }
    }
}
// 在字符串的右边补字符到指定长度
void RPad(char *str,const char in_char,unsigned int in_len)
{
    unsigned long str_len;
    unsigned long ul;

    for (str_len = 0; str[str_len] != '\0'; str_len++)
    {
        ;
    }

    if (in_len <= str_len)
    {
        ;
    }
    else
    {
        for (ul = 0; ul < in_len - str_len; ul++)
        {
            str[str_len + ul] = in_char;
        }
    }
}
// 把小写转换成大写，忽略不是字母的字符
void ToUpper(char *str)
{
   unsigned long ul;

   for (ul = 0; str[ul] != '\0'; ul++)
   {
      if (str[ul] >= 'a' && str[ul] <= 'z')
      {
         str[ul] = str[ul] - 32;
      }
   }
}
// 把大写转换成小写，忽略不是字母的字符
void ToLower(char *str)
{
   unsigned long ul;

   for (ul = 0; str[ul] != '\0'; ul++)
   {
      if (str[ul] >= 'A' && str[ul] <= 'Z')
      {
         str[ul] = str[ul] + 32;
      }
   }
}
// 判断内容是否全部是数字，0-是，-1-不是。
int  IsDigit(const char *str)
{
   unsigned long ul;

   for (ul = 0; str[ul] != '\0'; ul++)
   {
      if (str[ul] < '0' || str[ul] > '9')
      {
         return -1;
      }
   }

   return 0;
}
// 判断内容是否全部是大写字母，0-是，-1-不是。
int  IsUpper(const char *str)
{
   unsigned long ul;

   for (ul = 0; str[ul] != '\0'; ul++)
   {
      if (str[ul] < 'A' || str[ul] > 'Z')
      {
         return -1;
      }
   }

   return 0;
}
// 判断内容是否全部是小写字母，0-是，-1-不是。
int  IsLower(const char *str)
{
    unsigned long ul;

   for (ul = 0; str[ul] != '\0'; ul++)
   {
      if (str[ul] < 'a' || str[ul] > 'z')
      {
         return -1;
      }
   }

   return 0;
}
// 判断内容是否全部是ASCII字符，0-是，-1-不是。
int  IsASCII(const char *str)
{
    unsigned long ul;

    for (ul = 0;str[ul] != '\0'; ul++)
    {
        if (str[ul] < 0 || str[ul] > 127)
        {
            return -1;
        }
    }

    return 0;
}
/*
 *****************************************************C语言格式化输出****************************************************
 */
// 解析XML字符串的函数族，支持int、char *和double三种类型。
// 返回值：0-成功，-1-失败。
int GetXMLBuffer_Int(const char *in_XMLBuffer,const char *in_FieldName,int *out_Value)
{
    // 生成标签
    char left_label[301];
    char right_label[301];

    memset(left_label, 0, sizeof(left_label));
    memset(right_label, 0, sizeof(right_label));

    sprintf(left_label, "<%s>", in_FieldName);
    sprintf(right_label, "</%s>", in_FieldName);

    // printf("搜寻%s和%s之间的内容，请稍候...\n", left_label, right_label);

    // 查找标签
    char *left_label_pointer = 0;
    char *right_label_pointer = 0;
    long int left_label_ind = -1;
    long int right_label_ind = -1;
    // '<'age>
    left_label_pointer = STRSTR(in_XMLBuffer, left_label);
    // '<'/age>
    right_label_pointer = STRSTR(in_XMLBuffer, right_label);
    // printf("left_label_star_pointer：%p...\nright_label_start_pointer：%p...\n", left_label_pointer, right_label_pointer);
    // left
    if ((left_label_pointer == 0) || (right_label_pointer == 0))
    {
        return -1;
    }
    left_label_ind = left_label_pointer - (char *)in_XMLBuffer;
    // printf("left_label_ind：%ld...\n", left_label_ind);
    left_label_ind = left_label_ind + 1 + STRLEN(in_FieldName);
    // right
    right_label_ind = right_label_pointer - (char *)in_XMLBuffer;
    // printf("right_label_ind：%ld...\n", right_label_ind);

    // 输出
    // printf("left_label_end_ind：%ld...\nright_label_start_ind：%ld...\n", left_label_ind, right_label_ind);
    char digits[301];
    memset(digits, 0, sizeof(digits));
    unsigned long ul = 0;
    if (left_label_ind + 1 == right_label_ind)
    {
        return -1;
    }
    for (left_label_ind++; left_label_ind < right_label_ind; left_label_ind++, ul++)
    {
        // printf("%c", in_XMLBuffer[left_label_ind]);
        // STRCAT(digits, in_XMLBuffer[left_label_ind]);
        digits[ul] = in_XMLBuffer[left_label_ind];
    }
    digits[ul] = '\0';

    // 转换
    // int ATOI(const char *nptr)
    *out_Value = ATOI(digits);

    return 0;
}
int GetXMLBuffer_Str(const char *in_XMLBuffer,const char *in_FieldName,char *out_Value)
{
    // 生成标签
    char left_label[301];
    char right_label[301];

    memset(left_label, 0, sizeof(left_label));
    memset(right_label, 0, sizeof(right_label));

    sprintf(left_label, "<%s>", in_FieldName);
    sprintf(right_label, "</%s>", in_FieldName);

    // printf("搜寻%s和%s之间的内容，请稍候...\n", left_label, right_label);

    // 查找标签
    char *left_label_pointer = 0;
    char *right_label_pointer = 0;
    long int left_label_ind = -1;
    long int right_label_ind = -1;
    // '<'age>
    left_label_pointer = STRSTR(in_XMLBuffer, left_label);
    // '<'/age>
    right_label_pointer = STRSTR(in_XMLBuffer, right_label);
    // printf("left_label_star_pointer：%p...\nright_label_start_pointer：%p...\n", left_label_pointer, right_label_pointer);
    // left
    if ((left_label_pointer == 0) || (right_label_pointer == 0))
    {
        return -1;
    }
    left_label_ind = left_label_pointer - (char *)in_XMLBuffer;
    // printf("left_label_ind：%ld...\n", left_label_ind);
    left_label_ind = left_label_ind + 1 + STRLEN(in_FieldName);
    // right
    right_label_ind = right_label_pointer - (char *)in_XMLBuffer;
    // printf("right_label_ind：%ld...\n", right_label_ind);

    // 输出
    // printf("left_label_end_ind：%ld...\nright_label_start_ind：%ld...\n", left_label_ind, right_label_ind);
    char digits[301];
    memset(digits, 0, sizeof(digits));
    unsigned long ul = 0;
    if (left_label_ind + 1 == right_label_ind)
    {
        return -1;
    }
    for (left_label_ind++; left_label_ind < right_label_ind; left_label_ind++, ul++)
    {
        // printf("%c", in_XMLBuffer[left_label_ind]);
        // STRCAT(digits, in_XMLBuffer[left_label_ind]);
        out_Value[ul] = in_XMLBuffer[left_label_ind];
    }
    out_Value[ul] = '\0';

    return 0;
}
int GetXMLBuffer_Double(const char *in_XMLBuffer,const char *in_FieldName,double *out_Value)
{
    // 生成标签
    char left_label[301];
    char right_label[301];

    memset(left_label, 0, sizeof(left_label));
    memset(right_label, 0, sizeof(right_label));

    sprintf(left_label, "<%s>", in_FieldName);
    sprintf(right_label, "</%s>", in_FieldName);

    // printf("搜寻%s和%s之间的内容，请稍候...\n", left_label, right_label);

    // 查找标签
    char *left_label_pointer = 0;
    char *right_label_pointer = 0;
    long int left_label_ind = -1;
    long int right_label_ind = -1;
    // '<'age>
    left_label_pointer = STRSTR(in_XMLBuffer, left_label);
    // '<'/age>
    right_label_pointer = STRSTR(in_XMLBuffer, right_label);
    // printf("left_label_star_pointer：%p...\nright_label_start_pointer：%p...\n", left_label_pointer, right_label_pointer);
    // left
    if ((left_label_pointer == 0) || (right_label_pointer == 0))
    {
        return -1;
    }
    left_label_ind = left_label_pointer - (char *)in_XMLBuffer;
    // printf("left_label_ind：%ld...\n", left_label_ind);
    left_label_ind = left_label_ind + 1 + STRLEN(in_FieldName);
    // right
    right_label_ind = right_label_pointer - (char *)in_XMLBuffer;
    // printf("right_label_ind：%ld...\n", right_label_ind);

    // 输出
    // printf("left_label_end_ind：%ld...\nright_label_start_ind：%ld...\n", left_label_ind, right_label_ind);
    char digits[301];
    memset(digits, 0, sizeof(digits));
    unsigned long ul = 0;
    if (left_label_ind + 1 == right_label_ind)
    {
        return -1;
    }
    for (left_label_ind++; left_label_ind < right_label_ind; left_label_ind++, ul++)
    {
        // printf("%c", in_XMLBuffer[left_label_ind]);
        // STRCAT(digits, in_XMLBuffer[left_label_ind]);
        digits[ul] = in_XMLBuffer[left_label_ind];
    }
    digits[ul] = '\0';

    // 转换
    // double atof(const char *nptr)
    *out_Value = atof(digits);

    return 0;
}
/*
 *****************************************************C语言文件操作****************************************************
 */
// 实现文本文件复制的功能
// 返回值：-1 - 拷贝失败
int CopyTextFile(FILE *src_text_file, FILE *dest_text_file)
{
    char str[1024];
    bzero(str, sizeof(str));
    
    if (src_text_file == 0)
    {
        return -1;
    }
    if (dest_text_file == 0)
    {
        return -1;
    }

    // char *fgets(char *s, int size, FILE *stream);
    while (1)
    {
        bzero(str, sizeof(str));
        if (0 == fgets(str, 1024, src_text_file))
        {
            break;
        }
        else
        {
            // int fprintf(FILE *stream, const char *format, ...);
            fprintf(dest_text_file, "%s", str);
        }
    }

    return 0;
}
// 实现二进制文件复制的功能
// 返回值：-1 - 拷贝失败
int CopyBinaryFile(FILE *src_binary_file, FILE *dest_binary_file)
{
    char str[1024];
    bzero(str, sizeof(str));

    if (src_binary_file == 0)
    {
        return -1;
    }
    if (dest_binary_file == 0)
    {
        return -1;
    }

    // size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
    while (1)
    {
        bzero(str, sizeof(str));
        // if (0 == fread(？？？, 1, ？？？, src_bin_file))
        {
            break;
        }
        // else
        {
            // size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
            // fwrite(？？？, 1, ？？？, dest_binary_file);
        }
    }

    return 0;
}
/*
 *****************************************************C语言时间操作****************************************************
 */
// 把整数的时间转换为字符串格式的时间
// "2019-02-08 12:05:08"
// 0 - 成功; -1 - 失败
int timetostr(const time_t ti, char *strtime)
{
    if (strtime == 0)
    {
        return -1;
    }
    // struct tm *localtime(const time_t *timep);
    struct tm *now;

    now = 0;
    now = localtime(&ti);

    sprintf(strtime, "%d-%02d-%02d %d:%02d:%02d", \
                     now->tm_year + 1900, \
                     now->tm_mon + 1, \
                     now->tm_mday, \
                     now->tm_hour, \
                     now->tm_min, \
                     now->tm_sec);

    return 0;
}
// 把整数的时间转换为字符串格式的时间
// "2019年02月08日12时05分08秒"
// 0 - 成功; -1 - 失败
int timetostr1(const time_t ti, char *strtime)
{
    if (strtime == 0)
    {
        return -1;
    }
    // struct tm *localtime(const time_t *timep);
    struct tm *now;

    now = 0;
    now = localtime(&ti);

    sprintf(strtime, "%d年%02d月%02d日%d时%02d分%02d秒", \
                     now->tm_year + 1900, \
                     now->tm_mon + 1, \
                     now->tm_mday, \
                     now->tm_hour, \
                     now->tm_min, \
                     now->tm_sec);

    return 0;
}
// 把整数的时间转换为字符串格式的时间
// "2019-02-08"
// 0 - 成功; -1 - 失败
int timetostr2(const time_t ti, char *strtime)
{
    if (strtime == 0)
    {
        return -1;
    }
    // struct tm *localtime(const time_t *timep);
    struct tm *now;

    now = 0;
    now = localtime(&ti);

    sprintf(strtime, "%d-%02d-%02d", \
                     now->tm_year + 1900, \
                     now->tm_mon + 1, \
                     now->tm_mday);

    return 0;
}
// 把字符串格式的时间转换为整数的时间
// "2019-02-08 12:05:08"
// 0 - 成功; -1 - 失败
int strtotime(const char *strtime, time_t *ti)
{
    if (strtime == 0)
    {
        return -1;
    }
    if (ti == 0)
    {
        return -1;
    }

    // time_t mktime(struct tm *tm);
    time_t up_to_now;
    up_to_now = 0;
    struct tm time;
    bzero(&time, sizeof(struct tm));
    char tmp[5];

    bzero(tmp, sizeof(tmp));
    strncpy(tmp, strtime, 4);       // 2019
    time.tm_year = atoi(tmp) - 1900;
    bzero(tmp, sizeof(tmp));
    strncpy(tmp, strtime + 5, 2);   // 02
    time.tm_mon = atoi(tmp) - 1;
    bzero(tmp, sizeof(tmp));
    strncpy(tmp, strtime + 8, 2);   // 08
    time.tm_mday = atoi(tmp);
    bzero(tmp, sizeof(tmp));
    strncpy(tmp, strtime + 11, 2);  // 12
    time.tm_hour = atoi(tmp);
    bzero(tmp, sizeof(tmp));
    strncpy(tmp, strtime + 14, 2);  // 05
    time.tm_min = atoi(tmp);
    bzero(tmp, sizeof(tmp));
    strncpy(tmp, strtime + 17, 2);  // 08
    time.tm_sec = atoi(tmp);

    (*ti) = mktime(&time);

    return 0;
}
// 把字符串格式的时间转换为整数的时间
// "2019   02   08   12   05   08   "
// 0 - 成功; -1 - 失败
int strtotime1(const char *strtime,time_t *ti)
{
    if (strtime == 0)
    {
        return -1;
    }
    if (ti == 0)
    {
        return -1;
    }

    struct tm tm;
    bzero(&tm, sizeof(struct tm));

    char str[5];

    bzero(str, sizeof(str));
    tm.tm_year = atol(strncpy(str, strtime, 4)) - 1900;
    bzero(str, sizeof(str));
    tm.tm_mon = atol(strncpy(str, strtime + 7, 2)) - 1;
    bzero(str, sizeof(str));
    tm.tm_mday = atol(strncpy(str, strtime + 12, 2));
    bzero(str, sizeof(str));
    tm.tm_hour = atol(strncpy(str, strtime + 17, 2));
    bzero(str, sizeof(str));
    tm.tm_min = atol(strncpy(str, strtime + 22, 2));
    bzero(str, sizeof(str));
    tm.tm_sec = atol(strncpy(str, strtime + 27, 2));

    // time_t mktime(struct tm *tm);
    (*ti) = mktime(&tm);

    return 0;
}
// 把字符串格式的时间转换为整数的时间
// "2019-02-08"
// 0 - 成功; -1 - 失败
int strtotime2(const char *strtime,time_t *ti)
{
    if (strtime == 0)
    {
        return -1;
    }
    if (ti == 0)
    {
        return -1;
    }

    struct tm tm;
    bzero(&tm, sizeof(struct tm));

    char str[5];

    bzero(str, sizeof(str));
    tm.tm_year = atol(strncpy(str, strtime, 4)) - 1900;
    bzero(str, sizeof(str));
    tm.tm_mon = atol(strncpy(str, strtime + 5, 2)) - 1;
    bzero(str, sizeof(str));
    tm.tm_mday = atol(strncpy(str, strtime + 8, 2));

    // time_t mktime(struct tm *tm);
    (*ti) = mktime(&tm);

    return 0;
}
// out_stime是输出结果，格式由fmt决定。
// in_interval是偏移常量，单位是秒。
// in_fmt指定了out_stime的格式，取值如下：
// 常用的时间格式
// yyyy-mm-dd hh24:mi:ss
// yyyymmddhh24miss
// yyyy-mm-dd
// yyyymmdd
// hh24:mi:ss
// hh24miss
// hh24:mi
// hh24mi
// hh24
// mi
void LocalTime(char *out_stime, const char *in_fmt, const int in_interval)
{
    if (out_stime == 0)
    {
        return;
    }
    if (in_fmt == 0)
    {
        return;
    }

    struct tm *ti;
    ti = 0;

    if (strcmp(in_fmt, "yyyy-mm-dd hh24:mi:ss") == 0)
    {
        // struct tm *localtime(const time_t *timep);
        time_t timi;
        timi = 0;
        timi = time(0) + in_interval;
        ti = localtime(&timi);
        sprintf(out_stime, "%04d-%02d-%02d %02d:%02d:%02d", \
                           ti->tm_year + 1900, \
                           ti->tm_mon + 1, \
                           ti->tm_mday, \
                           ti->tm_hour, \
                           ti->tm_min, \
                           ti->tm_sec);
    }

    if (strcmp(in_fmt, "hh24:mi:ss") == 0)
    {
        // struct tm *localtime(const time_t *timep);
        time_t timi;
        timi = 0;
        timi = time(0) + in_interval;
        ti = localtime(&timi);
        sprintf(out_stime, "%02d:%02d:%02d", \
                           ti->tm_hour, \
                           ti->tm_min, \
                           ti->tm_sec);
    }
}
/*
 *****************************************************C++类的详解****************************************************
 */
// 实现printf函数的功能
int myprintf(const char *format, ...)
{
    int rt;
    va_list arg;
    va_start(arg, format);
    // 输出的屏幕
    rt = vprintf(format, arg);
    va_end(arg);

    return rt;
}
// 实现sprintf函数的功能
int mysprintf(char *str,const char *format, ...)
{
    int rt;
    va_list arg;
    va_start(arg, format);
    // 输出到字符串
    rt = vsprintf(str, format, arg);

    return rt;
}
// 实现snprintf函数的功能
int mysnprintf(char *str,size_t size,const char *format, ...)
{
    int rt;
    va_list arg;
    va_start(arg, format);
    // 输出到字符串，第二个参数指定了输出结果的长度，类似snprintf函数。
    rt = vsnprintf(str, size, format, arg);
    va_end(arg);

    return rt;
}
/*
 *****************************************************封装socket通信类****************************************************
 */
CTcpServer::CTcpServer()
{
    memset(buffer, 0, sizeof(buffer));
    g_server_listen_socket = 0;
    g_client_2_server_socket = 0;    // The socket of the client.
}
int CTcpServer::InitServer(int port)
{


    // Step 1: create the server socket.
    if (-1 == (g_server_listen_socket = socket(AF_INET, SOCK_STREAM, 0)))
    {
        perror("socket()");
        return -1;
    }


    // Step 2: bind the server's address and port for communication to socket.
    struct sockaddr_in server_addr;    // The data structure of server address information.
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;    // Protocol family, in socket programming can only be AF_ INET.
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);    // Any IP address.
    // server_addr.sin_addr.s_addr = inet_addr("192.168.1.106");    // Specify IP address.
    server_addr.sin_port = htons(port);    // Specify the communication port.
    if (0 != bind(g_server_listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)))
    {
        perror("bind()");
        close(g_server_listen_socket);
        return -1;
    }


    // Step 3: Set socket to listening mode.
    if (0 != listen(g_server_listen_socket, 5))
    {
        perror("listen()");
        close(g_server_listen_socket);
        return -1;
    }


    // Step 4: Accept client connections.
    int socket_len = sizeof(struct sockaddr_in);    // The size of struct sockaddr_in
    struct sockaddr_in client_addr;    // Address information of the client.
    g_client_2_server_socket = accept(g_server_listen_socket,\
                                    (struct sockaddr *)&client_addr,\
                                    (socklen_t *)&socket_len);
    // printf("\n\n\n\t-- Server --\n\n\n");

    return 0;
}
int CTcpServer::Send()
{
    return send(g_client_2_server_socket, buffer, strlen(buffer), 0);
}
int CTcpServer::Recv()
{
    return recv(g_client_2_server_socket, buffer, sizeof(buffer), 0);
}
CTcpServer::~CTcpServer()
{
    memset(buffer, 0, sizeof(buffer));
    if (0 != g_server_listen_socket)
    {
        close(g_server_listen_socket);
    }
    if (0 != g_client_2_server_socket)
    {
        close(g_client_2_server_socket);
    }
}
CTcpClient::CTcpClient()
{
    memset(buffer, 0, sizeof(buffer));
    g_client_socket = 0;
}
int CTcpClient::Connect2Server(const char *ip_addr, int port)
{
    if (-1 == (g_client_socket = socket(AF_INET, SOCK_STREAM, 0)))
    {
        perror("socket()");
        return -1;
    }


    // 第2步：向服务器发起连接请求。
    struct hostent *h;
    if (0 == (h = gethostbyname(ip_addr)))    // Specify the IP address of the server.
    {
        printf("gethostbyname() failed.\n");
        close(g_client_socket);
        return -1;
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);    // Specify the communication port of the server.
    memcpy(&server_addr.sin_addr, h->h_addr, h->h_length);
    if (0 != connect(g_client_socket,\
                     (struct sockaddr *)&server_addr,\
                     sizeof(server_addr)))
    // Send a connection request to the server.
    {
        perror("connect()");
        close(g_client_socket);
        return -1;
    }
    // printf("\n\n\n\t-- Client --\n\n\n");

    return 0;
}
int CTcpClient::Send()
{
    return send(g_client_socket, buffer, strlen(buffer), 0);
}
int CTcpClient::Recv()
{
    return recv(g_client_socket, buffer, sizeof(buffer), 0);
}
CTcpClient::~CTcpClient()
{
    memset(buffer, 0, sizeof(buffer));
    if (0 != g_client_socket)
    {
        close(g_client_socket);
    }
}