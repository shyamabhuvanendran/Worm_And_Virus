#include <stdio.h>
#include <stdlib.h>

int main()
{

	static char a[1500]="hello";
	unsigned char q[10000];
	unsigned char p[10000];
	int i,iread, sread;
	FILE *ip, *source, *copy;
	int j;
	int size=0;
	char in;
	int pos=0;
	int sourceAdded=0;
	//printf("\n%s",a);
	for(j=5;j<1500;j++){
		a[j]='0';
	}

	ip = fopen("worm_1","rb");
	iread = fread(q,sizeof(unsigned char), sizeof(q)/sizeof(unsigned char), ip);
	fclose(ip);

	for( i=0; i< iread; i++)
	{
   		if( q[i] == 'h' && q[i+1] == 'e' && q[i+2] == 'l'){
			pos=i;
			j=0;
			printf("\nExecutable file doesn't contain source code. Creating executable with source code\n\n");
         		source=fopen("worm_1.c", "r");
                        while((in=fgetc(source))!=EOF){
                                size++;
                        }
                        rewind(source);

         		while((in=fgetc(source))!=EOF){
				q[i+j]=in;
				j++;
			}
			break;
		}
		if(q[i] == '#' && q[i+1]=='i' && q[i+2]=='n' && q[i+3]== 'c'){
			printf("\nExecutable file contains source code!!!\n\n");
                        sourceAdded=1;
                        break;
		}

	}
	if(sourceAdded==0){
		ip = fopen("worm_1.x","wb");
		fwrite(q,sizeof(unsigned char), iread, ip);
		fclose(ip);
		system("mv worm_1.x worm_1; chmod +x worm_1;");
	}

}
