/*
 *  This program is used to demonstrate the client of socket.
 */
#include "__hy__.h"

// struct GIRL_STRU
// {
//     char name[301];
//     int age;
//     int height;
//     char sc[301];
//     char yz[301];
// };

int main(int argc, char *argv[], char *envp[])
{
    if (2 != argc)
    {
        printf("eg: ./00client port\nport: 5051, 5052, 5053, 5054, 8080\n");
        return 0;
    }

    CTcpClient tcp_client;
    tcp_client.Connect2Server("192.168.1.106", ATOI(argv[1]));

    while (1)
    {
        printf("\n\n\n\t\033[31m📤 \033[0m");
        memset(tcp_client.buffer, 0, sizeof(tcp_client.buffer));
        scanf("%s", tcp_client.buffer);
        tcp_client.Send();

        memset(tcp_client.buffer, 0, sizeof(tcp_client.buffer));
        if (0 >= tcp_client.Recv())
        {
            break;
        }
        if (0 == strcmp(tcp_client.buffer, "\"bye\""))
        {
            break;
        }
        printf("\n\n\n📥 %s", tcp_client.buffer);
    }

    return 0;
}
    // // 第1步：创建客户端的socket。
    // int client_socket;
    // // for (int ii = 0; ii < 10000; ii++)
    // // {
    //     if (-1 == (client_socket = socket(AF_INET, SOCK_STREAM, 0)))
    //     {
    //         perror("socket");
    //         return -1;
    //     }
    // //     printf("ii = %d，client_socket = %d。\n", ii, client_socket);
    // // }

    // // 第2步：向服务器发起连接请求。
    // struct hostent *h;
    // if (0 == (h = gethostbyname("192.168.43.120")))    // 指定服务端的ip地址。（腾讯云：58.87.76.44    个人热点：192.168.43.120）
    // {
    //     printf("gethostbyname failed.\n");
    //     close(client_socket);
    //     return -1;
    // }
    // struct sockaddr_in server_addr;
    // memset(&server_addr, 0, sizeof(server_addr));
    // server_addr.sin_family = AF_INET;
    // server_addr.sin_port = htons(5051);    // 指定服务端的通信端口。
    // memcpy(&server_addr.sin_addr, h->h_addr, h->h_length);
    // if (0 != connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)))    // 向服务端发起连接请求。
    // {
    //     perror("connect");
    //     close(client_socket);
    //     return -1;
    // }
    // char buffer[1024];
    // struct GIRL_STRU girl;
    // memset(&girl, 0, sizeof(girl));
    // strcpy(girl.name, "西施");
    // girl.age = 22;
    // girl.height = 168;
    // strcpy(girl.sc, "火辣");
    // strcpy(girl.yz, "漂亮");

    // // 第3步：与服务端通信，发送一个报文后等待回复，然后再发下一个报文。
    // for (int ii = 0; ii < 3; ii++)
    // {
    //     int iret;
    //     memset(buffer, 0, sizeof(buffer));
    //     sprintf(girl.name, "西施%d", ii + 1);
    //     if (0 >= (iret = send(client_socket, &girl, sizeof(girl), 0)))    // 向服务端发送请求报文。
    //     {
    //         perror("send");
    //         break;
    //     }
    //     printf("iret = %d\n", iret);
    //     memset(buffer, 0, sizeof(buffer));
    //     if (0 >= (iret = recv(client_socket, buffer, sizeof(buffer), 0)))    // 接收服务端的回应报文。
    //     {
    //         printf("iret = %d\n", iret);
    //         // break;
    //     }
    //     printf("ret = %d，接收：%s\n", iret, buffer);
    // }

    // // 第4步：关闭socket，释放资源。
    // close(client_socket);

    // return 0;


    // Step 3: communicate with the server, send a message, wait for reply, and then send the next message.
    // for (int ii = 0; ii < 3; ii++)
    // {
    //     int iret;
    //     memset(buffer, 0, sizeof(buffer));
    //     sprintf(buffer, "This is the %d super girl, number %03d.", ii + 1, ii + 1);
    //     if (0 >= (iret = send(client_socket, buffer, strlen(buffer), 0)))
    //     // Send request message to server.
    //     {
    //         perror("send()");
    //         break;
    //     }
    //     printf("\033[31m\t->SENT\t%s -- %d Byte(s)\n\033[0m", buffer, iret);

    //     memset(buffer, 0, sizeof(buffer));
    //     if (0 >= (iret = recv(client_socket, buffer, sizeof(buffer), 0)))
    //     // Receive the response message from the server.
    //     {
    //         printf("iret = %d\n", iret);
    //         break;
    //     }
    //     printf("RECV\t%s -- %d Byte(s)\n", buffer, iret);
    // }
    // 实现点对点的聊天功能，用户在客户端输入一个字符串，然后发送给服务端，
    // 服务端收到客户端的报文后，也提示用户输入一个字符串，返回给客户端，
    // 如果服务端收到客户端的报文是“bye”通信结束。
    // CTcpClient tcp_client;
    // tcp_client.Connect2Server("192.168.1.106");
    // while (1)
    // {
    //     memset(tcp_client.buffer, 0, sizeof(tcp_client.buffer));
    //     printf("\n\t🏹");
    //     scanf("%s", tcp_client.buffer);
    //     if (0 >= tcp_client.Send())
    //     {
    //         perror("send()");
    //         break;
    //     }

    //     memset(tcp_client.buffer, 0, sizeof(tcp_client.buffer));
    //     if (0 >= tcp_client.Recv())
    //     {
    //         break;
    //     }
    //     if (0 == strcmp(tcp_client.buffer, "\"bye\""))
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         printf("\n📲%s", tcp_client.buffer);
    //     }
    // }


    // printf("本程序的进程编号是：%d。\n", getpid());
    // sleep(300);