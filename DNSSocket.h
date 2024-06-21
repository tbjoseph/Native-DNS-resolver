#pragma once

#ifndef DNS_SOCKET_H
#define DNS_SOCKET_H

#include "pch.h"

class DNSSocket {
    char* host; // current host
    int tx_id; // current ID
    u_short query_type; // DNS_A or DNS_PTR
    char packet [MAX_DNS_LEN]; // 512 bytes is max
    int recv_bytes;

    // bool Read(size_t max_download_size, bool printInfo = true);
    // bool Connect(const sockaddr_in& server, const char* host, const char* request, const char* method, const char* valid_codes, size_t max_download_size, bool asterisk, bool& isCodeValid, bool printInfo = true, LONG volatile* stats = nullptr);
    bool FlipIP(char* reversed_ip, int size);
    int CreateRequest();
    bool MakeDNSquestion(void* request_buf);
    __int64 ParseResponse();
    int ParseHost(char* buf, char* destination);
    bool ParseAnswer(char* &curr_pos, int count);

public:
    DNSSocket() : tx_id(1), recv_bytes(0) {};
    bool Write(char* input_host, char* input_server);
    
    // void Print();

};

#endif //DNS_SOCKET_H