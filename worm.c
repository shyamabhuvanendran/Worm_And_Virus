#include <stdio.h>
#include <stdlib.h>

int main()
{

	static char a[2500]="hello";
	unsigned char q[10000];
	unsigned char p[10000];
	int i,iread, sread;
	FILE *ip, *source, *copy;
	int j;
	int size=0;
	char in;
	int pos=0;
	int sourceAdded=0;

	printf("\nSTARTING NEW WORM PROCESS\n");

	for(j=5;j<2500;j++){
			a[j]='0';
	}

	ip = fopen("worm","rb");
	iread = fread(q,sizeof(unsigned char), sizeof(q)/sizeof(unsigned char), ip);
	fclose(ip);
	for( i=0; i< iread; i++)
	{
   		if( q[i] == 'h' && q[i+1] == 'e' && q[i+2] == 'l'){
			pos=i;
			j=5;
			if(q[i+5]=='#'){
            printf("\nExecutable file containing source running!\n");
            sourceAdded=1;
            //Update size to the character count of worm.c
				    size=2367;
            break;
      }
      source=fopen("worm.c", "r");
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

	}
	if(sourceAdded==0){
		      ip = fopen("worm.x","wb");
		      fwrite(q,sizeof(unsigned char), iread, ip);
		      fclose(ip);
		      system("mv worm.x worm; chmod +x worm;");
	}
	copy=fopen("worm_source.c","wb");
	ip = fopen("worm","rb");
	iread = fread(p,sizeof(unsigned char), sizeof(p)/sizeof(unsigned char), ip);

	for(i=0;i<iread;i++){
		      if(p[i]=='h' && p[i+1]=='e' && p[i+2]=='l'){
			           pos=i+5;
			           break;
		      }
	}

	size=pos+size-2;
	for(i=pos;i<=size;i++){
		    fputc(p[i],copy);
	}
	printf("\nWORM STOPPED EXECUTION!!\n");
	fclose(ip);
	fclose(copy);
	system("gcc worm_source.c -o worm1; sleep 2s; chmod +x worm1;./worm1");
}
