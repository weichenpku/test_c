#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *src="abcdaabcab";
int next[20]; // if src(i) not match, use src(next[i]) to match
//1. src(0..next[i]-1) should be same with src(.. i-1)
//2. src(next[i]) should be different from src(i)

int main(){
	int len1=strlen(src);

	int p=0;
	int k=-1;
	next[p]=k;
	while(p<len1-1){
		if (k==-1 || src[p]==src[k]){ //src[-1] can match anything
			p++;
			k++;
			if (src[p]!=src[k]){  
				next[p]=k; 
				//if src[p] not match, try src[k], because src[k]!=src[p]
			}
			else{  
				next[p]=next[k]; 
				//if src[p] not match, try src[next[k]], because src[next[k]]!=src[k]=src[p]
			}
		}
		else{ // src[p] not match src[k], try src[next[k]]
			k=next[k];
		}
	}
	for (int i=0;i<len1;i++) printf("%c %d \n",src[i],next[i]);
}
