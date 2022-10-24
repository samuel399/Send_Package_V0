#include <stdio.h>
#include <stdlib.h>
#include <Winsock2.h>

#define SERVER_PORT 5040
#define MAX_PENDDING 2

struct sockaddr_in server_address;
struct sockaddr_in client_address;
SOCKET server_s, client_s, new_s;




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

void Set_Server_Local_Socket(void)
{
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);
    memset(&(server_address.sin_zero),'\0', 8);
    return;
}

void Create_Server_Socket(void) // Cria a conexão com o socket e com a porta selecionada para o server
{
    server_s = socket(PF_INET, SOCK_STREAM, 0);
    if (server_s == INVALID_SOCKET)
    {
        printf("Socket creation falied!!\n");
        exit(1);
    }
    else
    {
        if (bind(server_s, (struct sockaddr *)&server_address, sizeof(server_address)) == SOCKET_ERROR)
        {
            printf("Binding socket error!!n");
            exit(1);
        }
        else
        {
            return;
        }
    }
}

void Accept_Server_Conection(void)
{
    int len = sizeof(client_address);
    new_s = accept(server_s, (struct sockaddr *)&client_address, &len);
    if (new_s == INVALID_SOCKET)
    {
        printf("Accepting connection falid!!\n");
        exit(1);
    }
    else 
    {
        return;
    }    
}

int Server_Creation(void)
{

    return 0;
}

int Client_Creation(void)
{
    return 0;
}


int main (void)
{
    Start_Conection();

    listen(server_s, MAX_PENDDING);

    return 0;
}