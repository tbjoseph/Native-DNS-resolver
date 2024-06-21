// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#include <windows.h>
#include <iostream>

#pragma comment(lib, "wsock32.lib")


#define MAX_HOST_LEN		256
#define MAX_ATTEMPTS        3 
#define STATUS_OK           0x0 
#define DEPTH_LIMIT         (512 / 2)

/* DNS query types */
#define DNS_A 1 /* name -> IP */
#define DNS_NS 2 /* name server */
#define DNS_CNAME 5 /* canonical name */
#define DNS_PTR 12 /* IP -> name */
#define DNS_HINFO 13 /* host info/SOA */
#define DNS_MX 15 /* mail exchange */
#define DNS_AXFR 252 /* request for zone transfer */
#define DNS_ANY 255 /* all records */
#define MAX_DNS_LEN 512

/* query classes */
#define DNS_INET 1

/* flags */
#define DNS_QUERY (0 << 15) /* 0 = query; 1 = response */
#define DNS_RESPONSE (1 << 15)

#define DNS_STDQUERY (0 << 11) /* opcode - 4 bits */

#define DNS_AA (1 << 10) /* authoritative answer */
#define DNS_TC (1 << 9) /* truncated */
#define DNS_RD (1 << 8) /* recursion desired */
#define DNS_RA (1 << 7) /* recursion available */ 

#pragma pack(push,1)

struct QueryHeader {
    u_short type;
    u_short class_;
};

struct DNSanswerHdr {
    u_short type;
    u_short class_;
    u_int ttl;
    u_short len;
};

struct FixedDNSheader {
    u_short ID;
    u_short flags;
    u_short questions;
    u_short answers;
    u_short authority;
    u_short additional;
};

#pragma pack(pop) 

#endif //PCH_H
