/* 程序名：__hy__dcl__.h，此程序是hy框架公用函数和类的声明文件。
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

#ifndef __HY__DCL___H
#define __HY__DCL___H 1

// 求int整数的绝对值
int ABS(const int j);
// 求long整数的绝对值
long LABS(const long int j);

/* 用于把数字的字符转换为整数，chr为用字符方式表示的数字，函数的返回值为数字的整数。
   如果chr不是数字的字符，函数返回-1。  */
int ctoi(const char chr);

// 把字符串nptr转换为int整数
int ATOI(const char *nptr);
// 把字符串nptr转换为long整数
long ATOL(const char *nptr);

// 函数名称：createNoRepeatArray
// 函数功能：产生没有重复数字的整数数组（low～high）
// const int low：最小的随机数
// const int high：最大的随机数
// const int array：随机数组的名称
// 没有返回值
void createNoRepeatArray(const int low, const int high, int *array);

// 若ch是字母（'A'-'Z','a'-'z'）返回非0值，否则返回0。
int ISALPHA(int ch);
// 若ch是字母（'A'-'Z','a'-'z'）或数字（'0'-'9'），返回非0值,否则返回0。
int ISALNUM(int ch);
// 若ch是数字（'0'-'9'）返回非0值，否则返回0。
int ISDIGIT(int ch);
// 若ch是小写字母（'a'-'z'）返回非0值，否则返回0。
int ISLOWER(int ch);
// 若ch是大写字母（'A'-'Z'）返回非0值，否则返回0。
int ISUPPER(int ch);
// 若ch是大写字母（'A'-'Z'）返回相应的小写字母（'a'-'z'）。
int TOLOWER(int ch);
// 若ch是小写字母（'a'-'z'）返回相应的大写字母（'A'-'Z'）
int TOUPPER(int ch);
// chr为用字符方式表示的数字，函数的返回值为数字的整数。
int c09toi09(const char chr);
/*
 *****************************************************C语言浮点数****************************************************
 */
// 求双精度实数x的绝对值
double FABS(const double x);
// double舍小数，取整数
double RoundDecimal(const double x);
// double四舍五入
double ROUND(const double x);
// double向上取整数
double CEIL(const double x);
// double向下取整数
double FLOOR(const double x);
// 把双精度val分解成整数部分和小数部分，整数部分存放在ip所指的变量中，返回小数部分。
double MODF(double val, double *ip);
/*
 *****************************************************C语言字符串****************************************************
 */
// 实现strlen函数的功能。
size_t STRLEN(const char*  str);
// 实现strcpy函数的功能，下同。
// ???
char *STRCPY(char* dest, const char* src);
// 功能：把src前n字符的内容复制到dest中
// 返回值：dest字符串起始地址。
// 如果src字符串长度小于n，则拷贝完字符串后，在dest后追加0，直到n个。
// 如果src的长度大于等于n，就截取src的前n个字符，不会在dest后追加0。
// dest必须有足够的空间放置n个字符，否则可能会造成缓冲溢出的错误情况。
char *STRNCPY(char* dest, const char* src,size_t n);
// 功能：将src字符串拼接到dest所指的字符串尾部。
// 返回值：返回dest字符串起始地址。
// dest最后原有的结尾字符0会被覆盖掉，并在连接后的字符串的尾部再增加一个0。
// dest要有足够的空间来容纳要拼接的字符串，否则可能会造成缓冲溢出的错误情况。
char *STRCAT(char* dest, const char* src);
// 功能：将src字符串的前n个字符拼接到dest所指的字符串尾部。
// 返回值：返回dest字符串的起始地址。
// 如果n大于等于字符串src的长度，那么将src全部追加到dest的尾部，如果n大于字符串src的长度，只追加src的前n个字符。
// strncat会将dest字符串最后的0覆盖掉，字符追加完成后，再追加0。
// dest要有足够的空间来容纳要拼接的字符串，否则可能会造成缓冲溢出的错误情况。
char *STRNCAT(char* dest, const char* src,size_t n);
// 返回一个指向在字符串s中第一个出现c的位置，如果找不到，返回0。
char *STRCHR(const char *s, const int c);
// 返回一个指向在字符串s中最后一个出现c的位置，如果找不到，返回0。
char *STRRCHR(const char *s, const int c);
// 功能：比较str1和str2的大小;返回值：相等返回0，str1大于str2返回1，str1小于str2返回-1；
int STRCMP(const char *str1, const char *str2 );
// 功能：比较str1和str2的大小;
// 返回值：相等返回0，str1大于str2返回1，str1小于str2返回-1；
// 两个字符串比较的方法是比较字符的ASCII码的大小，从两个字符串的第一个字符开始，如果分不出大小，就比较第二个字符，
// 如果全部的字符都分不出大小，就返回0，表示两个字符串相等。
// 在实际开发中，程序员一般只关心字符串是否相等，不关心哪个字符串更大或更小。
int STRNCMP(const char *str1, const char *str2, const size_t n);
// 功能：检索子串在字符串中首次出现的位置。
// 返回值：返回字符串str中第一次出现子串substr的地址；如果没有检索到子串，则返回0。
char *STRSTR(const char* str, const char* substr);
// 丰富您的函数库，增加STRCPY、STRNCPY、STRCAT、STRNCAT四个安全的函数，弥补库函数的缺陷，解决dest的初始化和内存越界的问题，函数的声明如下：
// 注意，上述函数的第二个参数destsize是第一个参数dest占用内存的字节数。
char *SAFESTRCPY(char* dest, const size_t destsize, const char* src);
char *SAFESTRNCPY(char* dest, const size_t destsize, const char* src, size_t n);
char *SAFESTRCAT(char* dest, const size_t destsize, const char* src);
char *SAFESTRNCAT(char* dest, const size_t destsize, const char* src, size_t n);
// 删除字符串左边指定的字符
void DeleteLChar(char *str,const char in_char);
// 删除字符串右边指定的字符
void DeleteRChar(char *str,const char in_char);
// 删除字符串两边指定的字符
void DeleteLRChar(char *str,const char in_char);
// 删除字符串中间的字符串
void DeleteMStr(char *str,const char *in_str);
// 在字符串的左边补字符到指定长度
void LPad(char *str,const char in_char,unsigned int in_len);
// 在字符串的右边补字符到指定长度
void RPad(char *str,const char in_char,unsigned int in_len);
// 把小写转换成大写，忽略不是字母的字符
void ToUpper(char *str);
// 把大写转换成小写，忽略不是字母的字符
void ToLower(char *str);
// 判断内容是否全部是数字，0-是，-1-不是。
int  IsDigit(const char *str);
// 判断内容是否全部是大写字母，0-是，-1-不是。
int  IsUpper(const char *str);
// 判断内容是否全部是小写字母，0-是，-1-不是。
int  IsLower(const char *str);
// 判断内容是否全部是ASCII字符，0-是，-1-不是。
int  IsASCII(const char *str);
/*
 *****************************************************C语言格式化输出****************************************************
 */
// 解析XML字符串的函数族，支持int、char *和double三种类型。
// 返回值：0-成功，-1-失败。
int GetXMLBuffer_Int(const char *in_XMLBuffer, const char *in_FieldName, int *out_Value);
int GetXMLBuffer_Str(const char *in_XMLBuffer, const char *in_FieldName, char *out_Value);
int GetXMLBuffer_Double(const char *in_XMLBuffer, const char *in_FieldName, double *out_Value);
/*
 *****************************************************C语言文件操作****************************************************
 */
// 实现文本文件复制的功能
// 返回值：0 - 拷贝失败
int CopyTextFile(FILE *src_text_file, FILE *dest_text_file);
// 实现二进制文件复制的功能
// 返回值：0 - 拷贝失败
int CopyBinaryFile(FILE *src_binary_file, FILE *dest_binary_file);
/*
 *****************************************************C语言时间操作****************************************************
 */
// 把整数的时间转换为字符串格式的时间
// "2019-02-08 12:05:08"
// 0 - 成功; -1 - 失败
int timetostr(const time_t ti, char *strtime);
int timetostr1(const time_t ti, char *strtime);
int timetostr2(const time_t ti, char *strtime);
// 把字符串格式的时间转换为整数的时间
// "2019-02-08 12:05:08"
// 0 - 成功; -1 - 失败
int strtotime(const char *strtime, time_t *ti);
int strtotime1(const char *strtime, time_t *ti);
int strtotime2(const char *strtime, time_t *ti);
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
void LocalTime(char *out_stime, const char *in_fmt, const int in_interval);
/*
 *****************************************************C++类的详解****************************************************
 */
// 实现printf函数的功能
int myprintf(const char *format, ...);
// 实现sprintf函数的功能
int mysprintf(char *str,const char *format, ...);
// 实现snprintf函数的功能
int mysnprintf(char *str,size_t size,const char *format, ...);
/*
 *****************************************************封装socket通信类****************************************************
 */
class CTcpServer
{
private:
    int g_server_listen_socket;
    int g_client_2_server_socket;    // The socket of the client.
public:
    char buffer[9999];

    CTcpServer();
   ~CTcpServer();
    int InitServer(int port = 8080);
    int Send();
    int Recv();
};
class CTcpClient
{
private:
    int g_client_socket;    // 第1步：创建客户端的socket。
public:
    char buffer[9999];

    CTcpClient();
   ~CTcpClient();
    int Connect2Server(const char *ip_addr, int port = 8080);
    int Send();
    int Recv();
};

#endif