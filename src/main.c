#include <stdio.h>
#include <stdlib.h>
#include <Winsock2.h>

#define SERVER_PORT 5040

struct sockaddr_in server_address;
struct sockaddr_in client_address;
SOCKET s, new_s;




void Start_Conection(void)
{
    WSADATA info;

    if (WSAStartup(MAKEWORD(1,1), &info) != 0)
    {
        printf("Winsock Statup falied\n");
        exit(1);
    }    
    return;
}

void Set_Local_Socket(void)
{
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);
    memset(&(server_address.sin_zero),'\0', 8);
    return;
}


int main (void)
{
    Start_Conection();
    return 0;
}