#include <arpa/inet.h>
#include <stdio.h>
#include <memory.h>
#include "inet_pton_loose.h"

int inet_pton_loose(int famliy, const char* strptr, void* addrptr)
{
    if (famliy == AF_INET){
        int ret = inet_pton(famliy,strptr,addrptr);
        if (ret==0){
            return inet_aton(strptr,(struct in_addr *)addrptr);
        } else return ret;
    }
    if (famliy == AF_INET6){
        int ret = inet_pton(famliy,strptr,addrptr);
        if (ret==0){
            int ipv4v[4];
            if (sscanf(strptr,"%d.%d.%d.%d",&ipv4v[0],&ipv4v[1],&ipv4v[2],&ipv4v[3])<0){
                return -1;
            } else {
                struct in6_addr* ptr = addrptr;
                memset((void *)ptr,0,sizeof(ptr));
                ptr->__in6_u.__u6_addr8[15]=ipv4v[3];
                ptr->__in6_u.__u6_addr8[14]=ipv4v[2];
                ptr->__in6_u.__u6_addr8[13]=ipv4v[1];
                ptr->__in6_u.__u6_addr8[12]=ipv4v[0];
                ptr->__in6_u.__u6_addr8[11]=255;
                ptr->__in6_u.__u6_addr8[10]=255;
                return 1;
            }
        } else return ret;
    }
    return inet_pton(famliy,strptr,addrptr);
}

int main()
{
    struct in6_addr addr6;
    struct in_addr addr4;
    char buff[100];
    int ret = inet_pton_loose(AF_INET,"0xe",&addr4);
    printf("%d %d %s\n",(int)addr4.s_addr, ret, inet_ntop(AF_INET,(const void*)&addr4,buff,INET_ADDRSTRLEN));
    ret = inet_pton_loose(AF_INET,"007",&addr4);
    printf("%d %d %s\n",(int)addr4.s_addr, ret, inet_ntop(AF_INET,(const void*)&addr4,buff,INET_ADDRSTRLEN));
    ret = inet_pton_loose(AF_INET6,"10.214.148.125",&addr6);
    printf("%d %s\n", ret, inet_ntop(AF_INET6,(const void*)&addr6,buff,INET6_ADDRSTRLEN));
}
