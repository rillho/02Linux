#include "__hy__.h"

// int global_ii = 1998;
// int global_jj = 1127;
// int global_array[1024][1024];

// void fatchfunc()
// {
//     printf("我是老子，我喜欢孩子他娘。\n");
// }
// void childfunc()
// {
//     printf("我是儿子，我喜欢西施。\n");
// }
// int CreatSubprocess()
// {
//     if (0 == fork())
//     {
//         return getpid();
//     }

//     return -1;
// }
int main(int argc, char *argv[], char *envp[])
{
    if (0 < fork())
    {
        // Parent process
        CTcpServer tcp_server;
        tcp_server.InitServer(5051);

        while (1)
        {
            memset(tcp_server.buffer, 0, sizeof(tcp_server.buffer));
            if (0 >= tcp_server.Recv())
            {
                break;
            }
            if (0 == strcmp(tcp_server.buffer, "\"bye\""))
            {
                break;
            }
            printf("\n\n\n📥 %s", tcp_server.buffer);

            printf("\n\n\n\t\033[31m📤 \033[0m");
            memset(tcp_server.buffer, 0, sizeof(tcp_server.buffer));
            scanf("%s", tcp_server.buffer);
            tcp_server.Send();
        }
    }
    else
    {
        // 5052端口
        CTcpServer tcp_server2;
        if (-1 == tcp_server2.InitServer(5052) &&
            -1 == tcp_server2.InitServer(5053) &&
            -1 == tcp_server2.InitServer(5054) &&
            -1 == tcp_server2.InitServer(8080))
        {
            return 0;
        }
        else
        {
            while (1)
            {
                memset(tcp_server2.buffer, 0, sizeof(tcp_server2.buffer));
                if (0 >= tcp_server2.Recv())
                {
                    break;
                }
                if (0 == strcmp(tcp_server2.buffer, "\"bye\""))
                {
                    break;
                }
                printf("\n\n\n📥 %s", tcp_server2.buffer);

                printf("\n\n\n\t\033[31m📤 \033[0m");
                memset(tcp_server2.buffer, 0, sizeof(tcp_server2.buffer));
                scanf("%s", tcp_server2.buffer);
                tcp_server2.Send();
            }
        }
    }

    return 0;
}
    // printf("本程序的进程编号是：%d。\n", getpid());
    // sleep(30);


    // printf("本程序的进程编号是：%d。\n", getpid());
    // int ipid = fork();
    // sleep(1);    // sleep()等待进程的生成。
    // printf("ipid = %d。\n", ipid);
    // if (0 != ipid)
    // {
    //     printf("父进程编号是：%d。\n", getpid());
    // }
    // else
    // {
    //     printf("子进程编号是：%d。\n", getpid());
    // }
    // sleep(300);


    // if (0 < fork())
    // {
    //     printf("这是父进程，将调用fatchfunc()函数。\n");
    //     fatchfunc();
    // }
    // else
    // {
    //     printf("这是子进程，将调用childfunc()函数。\n");
    //     childfunc();
    // }
    // sleep(1);
    // printf("父子进程执行完自己的函数后都来这里。\n");


    // // 验证子进程是复制父进程的内存变量，还是父子进程共享内存变量？
    // int main_ii = 410526;
    // int main_jj = 19981127;

    // if (0 < fork())
    // {
    //     printf("这是父进程！\n");
    //     global_ii++;
    //     global_jj--;
    //     printf("预测global_ii将是1999，实际也是：%d。\n", global_ii);
    //     printf("预测global_jj将是1126，实际也是：%d。\n", global_jj);
    //     main_ii++;
    //     main_jj--;
    //     printf("预测main_ii将是410527，实际也是：%d。\n", main_ii);
    //     printf("预测main_jj将是19981126，实际也是：%d。\n", main_jj);
    // }
    // else
    // {
    //     printf("这是子进程！\n");
    //     global_ii++;
    //     global_jj--;
    //     printf("预测global_ii将是1999，实际也是：%d。\n", global_ii);
    //     printf("预测global_jj将是1126，实际也是：%d。\n", global_jj);
    //     main_ii++;
    //     main_jj--;
    //     printf("预测main_ii将是410527，实际也是：%d。\n", main_ii);
    //     printf("预测main_jj将是19981126，实际也是：%d。\n", main_jj);
    // }


    // 由父进程生成10个子进程，在子进程中显示它是第几个子进程和子进程本身的进程编号。
    // printf("parent_process\t\t\t%d\n", getpid());

    // int tmp = -2;
    // if (-1 != (tmp = CreatSubprocess()))
    // {
    //     printf("subprocess  %2d\t\t\t%d\n", 1, tmp);
    //     exit(0);
    // }
    // tmp = -2;
    // if (-1 != (tmp = CreatSubprocess()))
    // {
    //     printf("subprocess  %2d\t\t\t%d\n", 2, tmp);
    //     exit(0);
    // }
    // tmp = -2;
    // if (-1 != (tmp = CreatSubprocess()))
    // {
    //     printf("subprocess  %2d\t\t\t%d\n", 3, tmp);
    //     exit(0);
    // }
    // if (-1 != (tmp = CreatSubprocess()))
    // {
    //     printf("subprocess  %2d\t\t\t%d\n", 4, tmp);
    //     exit(0);
    // }
    // tmp = -2;
    // if (-1 != (tmp = CreatSubprocess()))
    // {
    //     printf("subprocess  %2d\t\t\t%d\n", 5, tmp);
    //     exit(0);
    // }
    // tmp = -2;
    // if (-1 != (tmp = CreatSubprocess()))
    // {
    //     printf("subprocess  %2d\t\t\t%d\n", 6, tmp);
    //     exit(0);
    // }
    // tmp = -2;
    // if (-1 != (tmp = CreatSubprocess()))
    // {
    //     printf("subprocess  %2d\t\t\t%d\n", 7, tmp);
    //     exit(0);
    // }
    // tmp = -2;
    // if (-1 != (tmp = CreatSubprocess()))
    // {
    //     printf("subprocess  %2d\t\t\t%d\n", 8, tmp);
    //     exit(0);
    // }
    // tmp = -2;
    // if (-1 != (tmp = CreatSubprocess()))
    // {
    //     printf("subprocess  %2d\t\t\t%d\n", 9, tmp);
    //     exit(0);
    // }
    // tmp = -2;
    // if (-1 != (tmp = CreatSubprocess()))
    // {
    //     printf("subprocess  %2d\t\t\t%d\n", 10, tmp);
    //     exit(0);
    // }

    // sleep(300);


    // 由父进程生成子进程，
    // 子进程再生成孙进程，
    // 共生成第10代进程，
    // 在各级子进程中显示它是第几代子进程和子进程本身的进程编号。
    // if (0 < fork())
    // {
    //     // parent process
    //     printf("Parent process\t\t\t%d\n", getpid());
    //     sleep(300);
    //     exit(0);
    // }
    // else
    // {
    //     // subprocess
    //     printf("Subprocess  %2d\t\t\t%d\n", 1, getpid());
    //     if (0 == fork())
    //     {
    //         printf("Subprocess  %2d\t\t\t%d\n", 2, getpid());
    //         if (0 == fork())
    //         {
    //             printf("Subprocess  %2d\t\t\t%d\n", 3, getpid());
    //             if (0 == fork())
    //             {
    //                 printf("Subprocess  %2d\t\t\t%d\n", 4, getpid());
    //                 if (0 == fork())
    //                 {
    //                     printf("Subprocess  %2d\t\t\t%d\n", 5, getpid());
    //                     if (0 == fork())
    //                     {
    //                         printf("Subprocess  %2d\t\t\t%d\n", 6, getpid());
    //                         if (0 == fork())
    //                         {
    //                             printf("Subprocess  %2d\t\t\t%d\n", 7, getpid());
    //                             if (0 == fork())
    //                             {
    //                                 printf("Subprocess  %2d\t\t\t%d\n", 8, getpid());
    //                                 if (0 == fork())
    //                                 {
    //                                     printf("Subprocess  %2d\t\t\t%d\n", 9, getpid());
    //                                     if (0 == fork())
    //                                     {
    //                                         printf("Subprocess  %2d\t\t\t%d\n", 10, getpid());
    //                                         sleep(300);
    //                                         exit(0);
    //                                     }
    //                                     sleep(300);
    //                                     exit(0);
    //                                 }
    //                                 sleep(300);
    //                                 exit(0);
    //                             }
    //                             sleep(300);
    //                             exit(0);
    //                         }
    //                         sleep(300);
    //                         exit(0);
    //                     }
    //                     sleep(300);
    //                     exit(0);
    //                 }
    //                 sleep(300);
    //                 exit(0);
    //             }
    //             sleep(300);
    //             exit(0);
    //         }
    //         sleep(300);
    //         exit(0);
    //     }
            // if (0 == fork())
            // {
            //     printf("Subprocess  %2d\t\t\t%d\n", 3, getpid());
            //     sleep(300);
            //     exit(0);
            //     if (0 == fork())
            //     {
            //         printf("Subprocess  %2d\t\t\t%d\n", 4, getpid());
            //         sleep(300);
            //         exit(0);
            //         if (0 == fork())
            //         {
            //             printf("Subprocess  %2d\t\t\t%d\n", 5, getpid());
            //             sleep(300);
            //             exit(0);
            //             if (0 == fork())
            //             {
            //                 printf("Subprocess  %2d\t\t\t%d\n", 6, getpid());
            //                 sleep(300);
            //                 exit(0);
            //                 if (0 == fork())
            //                 {
            //                     printf("Subprocess  %2d\t\t\t%d\n", 7, getpid());
            //                     sleep(300);
            //                     exit(0);
            //                     if (0 == fork())
            //                     {
            //                         printf("Subprocess  %2d\t\t\t%d\n", 8, getpid());
            //                         sleep(300);
            //                         exit(0);
            //                         if (0 == fork())
            //                         {
            //                             printf("Subprocess  %2d\t\t\t%d\n", 9, getpid());
            //                             sleep(300);
            //                             exit(0);
            //                             if (0 == fork())
            //                             {
            //                                 printf("Subprocess  %2d\t\t\t%d\n", 10, getpid());
            //                                 sleep(300);
            //                                 exit(0);
            //                             }
            //                         }
            //                     }
            //                 }
            //             }
            //         }
            //     }
            // }
    //     sleep(300);
    //     exit(0);
    // }


    // return 0;
    // while (1)
    // {
    //     fork();
    //     printf("Hello, world!\n");
    // }


    // printf("%d\n", getpid());
    // for (int ii = 0; ii < 1000; ii++)
    // {
    //     if (0 < fork())
    //     {
    //         // Parent
    //         // sleep(1);
    //         // sleep(300);
    //         // return 0;
    //     }
    //     else
    //     {
    //         // Sub
    //         printf("这是第%d代进程（%d）。\n", ii + 1, getpid());
    //         // return 0;
    //     }
    // }

    // sleep(300);