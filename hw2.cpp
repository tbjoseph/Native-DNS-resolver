// hw2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "DNSSocket.h"

int main(int argc, char** argv)
{
    if (argc != 3) {
        printf("Usage: hw2.exe [lookup_string] [dns_server_ip]\n\n");
        printf("[lookup_string]\tThe hostname or IP address you want to look up.\n");
        printf("[dns_server_ip]\tThe IP address of the DNS server to query.\n\n");

        return 0;
    }

    WSADATA wsaData;
    WORD wVersionRequested = MAKEWORD(2, 2);
    if (WSAStartup(wVersionRequested, &wsaData) != 0)
    {
        printf("WSAStartup error %d\n", WSAGetLastError());
        WSACleanup();
        return -1;
    }

    DNSSocket socket;
    socket.Write(argv[1], argv[2]);

    
    WSACleanup();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
