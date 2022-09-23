#include "../inc/header.h"

int mx_atoi(const char *str) {
    int i=0;
    int neg=1;
    
    while(mx_isspace(str[i])) {
        i++;
    }
    if(str[i]=='-') {
        i++;
        neg=-1;
    }else if(str[i]=='+'){
    	i++;
    }
    int res=0;
    while(mx_isdigit(str[i])) {
        res*=10;
        res+=str[i]-'0';
        i++;
    }
    return res*neg;
}

