/*
 *  This program is used to demonstrate the server of socket communication.
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
    return 0;
}
    // // 第1步：创建服务端的socket。
    // int server_listen_socket;
    // if (-1 == (server_listen_socket = socket(AF_INET, SOCK_STREAM, 0)))
    // {
    //     perror("socket");
    //     return -1;
    // }

    // // 第2步：把服务端用于通信的地址和端口绑定到socket上。
    // struct sockaddr_in server_addr;    // 服务端地址信息的数据结构。
    // memset(&server_addr, 0, sizeof(server_addr));
    // server_addr.sin_family = AF_INET;    // 协议族，在socket编程中只能是AF_INET。
    // // server_addr.sin_addr.s_addr = htonl(INADDR_ANY);    // 任意ip地址。
    // server_addr.sin_addr.s_addr = inet_addr("192.168.43.120");    // 指定ip地址。
    // server_addr.sin_port = htons(5051);    // 指定通信端口。
    // if (0 != bind(server_listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)))
    // {
    //     perror("bind");
    //     close(server_listen_socket);
    //     return -1;
    // }

    // // 第3步：把socket设置为监听模式。
    // if (0 != listen(server_listen_socket, 5))
    // {
    //     perror("listen");
    //     close(server_listen_socket);
    //     return -1;
    // }

    // // 第4步：接受客户端的连接。
    // int server_client_socket;    // 客户端的socket。
    // int socket_len = sizeof(struct sockaddr_in);    // struct sockaddr_in的大小
    // struct sockaddr_in client_addr;    // 客户端的地址信息。
    // // printf("accept函数开始等待...\n");
    // server_client_socket = accept(server_listen_socket, (struct sockaddr *)&client_addr, (socklen_t *)&socket_len);
    // // printf("accept函数结束等待。\n");
    // printf("客户端（%s）已连接。\n", inet_ntoa(client_addr.sin_addr));
    // // close(server_listen_socket);
    // // close(server_client_socket);
    // // return -1;

    // // 第5步：与客户端通信，接收客户端发过来的报文后，回复received。
    // char buffer[1024];
    // struct GIRL_STRU girl;
    // memset(&girl, 0, sizeof(girl));
    // while (1)
    // {
    //     int iret;
    //     memset(buffer, 0, sizeof(buffer));
    //     if (0 >= (iret = recv(server_client_socket, &girl, sizeof(girl), 0)))    // 接收客户端的请求报文。
    //     {
    //         printf("iret = %d\n", iret);
    //         break;
    //     }
    //     printf("ret = %d，接收：%s\n", iret, girl.name);
    //     strcpy(buffer, "sent");
    //     if (0 >= (iret = send(server_client_socket, buffer, strlen(buffer), 0)))    // 向客户端发送响应结果。
    //     {
    //         perror("send");
    //         break;
    //     }
    //     printf("iret = %d，发送：%s。\n", iret, buffer);
    // }

    // // 第6步：关闭socket，释放资源。
    // close(server_listen_socket);
    // close(server_client_socket);

    // return 0;


    // Step 5: communicate with the client.
    // After receiving the message from the client, reply OK.
    // char buffer[1024];
    // while (1)
    // {
    //     int iret;
    //     memset(buffer, 0, sizeof(buffer));
    //     if (0 >= (iret = recv(client_2_server_socket, buffer, sizeof(buffer), 0)))
    //     // Receive the request message from the client.
    //     {
    //         printf("recv() returns %d\n", iret);
    //         break;
    //     }
    //     printf("RECV\t%s -- %d Byte(s)\n", buffer, iret);

    //     strcpy(buffer, "ok");
    //     if (0 >= (iret = send(client_2_server_socket, buffer, strlen(buffer), 0)))
    //     // Send the response results to the client.
    //     {
    //         perror("send()");
    //         break;
    //     }
    //     printf("\033[31m\t->SENT\t%s -- %d Byte(s)\n\033[0m", buffer, iret);
    // }
    // 实现点对点的聊天功能，用户在客户端输入一个字符串，然后发送给服务端，
    // 服务端收到客户端的报文后，也提示用户输入一个字符串，返回给客户端，
    // 如果服务端收到客户端的报文是“bye”通信结束。
    // CTcpServer tcp_server;
    // tcp_server.InitServer();
    // while (1)
    // {
    //     memset(tcp_server.buffer, 0, sizeof(tcp_server.buffer));
    //     if (0 >= tcp_server.Recv())
    //     {
    //         break;
    //     }
    //     if (0 == strcmp(tcp_server.buffer, "\"bye\""))
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         printf("\n📲%s", tcp_server.buffer);
    //     }

    //     memset(tcp_server.buffer, 0, sizeof(tcp_server.buffer));
    //     printf("\n\t🏹");
    //     scanf("%s", tcp_server.buffer);
    //     if (0 >= tcp_server.Send())
    //     {
    //         perror("send()");
    //         break;
    //     }
    // }