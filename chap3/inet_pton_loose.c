#include <arpa/inet.h>

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
            return inet_aton(strptr,(struct in_addr6*)addrptr);
        } else return ret;
    }
    return inet_pton(famliy,strptr,addrptr);
}