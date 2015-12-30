//period 思想蛮有意思
#include <stdio.h>
#include <limits.h>

int myAtoi(char *str) {
    char src[1000];
	long long ret = 0;
	int per = 1;
	char flag = 0;
	sscanf(str, "%s", src);
	str = src;
	while(*str != '\0'){
		if(ret > INT_MAX || ret < INT_MIN)break;

		if(per == 1){
			if(*str == '+' || *str == '-'){
				if(flag == 0)flag = *str;
				else break;
			}
			else if(*str >= '0' && *str <= '9'){
				per = 2;
				ret = ret*10 + *str - '0';
			}
			else break;
		}
		else if(per == 2){
			if(*str >= '0' && *str <= '9'){
				per = 2;
				ret = ret*10 + *str - '0';
			}
			else break;
		}
		str++;
	}
	if(flag == '-')ret *= -1;

	if(ret > INT_MAX) return INT_MAX;
	else if(ret < INT_MIN) return INT_MIN;
	return (int)ret;
	
}


int main(){
	char x[] = "9223372036854775809";
	printf("%d\n", myAtoi(x));
	return 0;
}