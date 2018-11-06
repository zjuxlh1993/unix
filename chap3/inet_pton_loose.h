//#define INET_PTON_LOOSE_MAIN

#ifndef INET_PTON_LOOSE
#define INET_PTON_LOOSE
/*
 * function name: inet_pton_loose
 * summary: convert presentation to numeric, support ipv6 input ipv4 output ipv6, input 0xe, 00e...
 * parameters:
 *  family: AF_INET AF_INET6...
 *  strptr: presentation string
 *  addrptr: numeric
 * 
*/
int inet_pton_loose(int famliy, const char* strptr, void* addrptr);

#endif