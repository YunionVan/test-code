#include <stdio.h>

#define LENGTH 100

int num[LENGTH], n, k ,i;
void swap(int i, int j)
{
	int tmp=num[i];
	num[i] = num[j];
	num[j] = tmp;
}

int findNumber(int l, int u, int k){
	int i=l, j=u+1;
	if(l>u)return -1;
	if(l==u){return num[l];}
	while(1){
		do{
			i++;
		}while(i<u && num[i]<num[l]);
		do{
			j--;
		}while(num[j]>num[l]);
		if(i>j)break;
		swap(i, j);                                                                                                                                                                 
	}
	swap(l, j);
	if(j-l == k-1)return num[j];
	else if(j-l > k-1){
		return findNumber(l, j-1, k);
	}
	else{
		return findNumber(j+1, u, k-(j-l+1));
	}
}

int main(){
	char c = 'y', ret;
	while(c=='y'){
		printf("array length:");
		scanf("%d", &n);
		printf("array element:");
		for(i=0; i<n; i++){
			scanf("%d", &num[i]);
		}	
		printf("find K:");
		scanf("%d", &k);
		if(k>n || k<1){
			printf("wrong input for k.\n");
		}
		else{
			ret = findNumber(0, n-1, k);
			printf("ret: %d\n", ret);
		}
		printf("y or n:");
		scanf(" %c", &c);
	}
	return 0;
}