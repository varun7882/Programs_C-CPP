#include<stdio.h>
#include<string.h>
int intvalue(char x)
{
    int y;
    if((int)x==48)
    {
        y=0;
    }
    else
    {
    y=1;
    }
    return y;
}
char charvalue(int x)
{
    char c;
    if((char)x==NULL)
    {
        c='0';
    }
    else
    {
        c='1';
    }
    return c;
}
int main()
{
    char msg[10000],rmsg[10100],crcg[100],crc[100],newmsga[10100];
    int i,msgn,crcgn,newmsgn,rmsgn,j,a,b,c,f=0,cf;
    printf("Enter the messesge in form 0's and 1's of length at max 1000 bits\n");
    scanf("%s",msg);
    printf("Enter the crc generator i.e. the key at max 100 bits\n");
    scanf("%s",crcg);
    msgn=strlen(msg);
    crcgn=strlen(crcg);
   // puts(msg);
    for(i=0;i<msgn+crcgn-1;i++)
		{
			if(i<msgn)
			{
			newmsga[i]=msg[i];
			}
			else
			{
				newmsga[i]='0';
			}
		}
		newmsga[i]='\0';
		//printf("new message is...");
		//puts(newmsga);
		newmsgn=strlen(newmsga);
		for(i=0;i<newmsgn-crcgn;i++)
		{
			if(newmsga[i]=='1')
			{
			for(j=0;j<crcgn;j++)
			{
				a=intvalue(crcg[j]);
				b=intvalue(newmsga[i+j]);
                b=a^b;
				newmsga[i+j]=charvalue(b);
			}
			}

		}
		printf("message 2...");
		puts(newmsga);
		newmsgn=strlen(newmsga);
		j=0;
		i=newmsgn-crcgn+1;
		while(i<newmsgn)
		{
		    crc[j++]=newmsga[i++];
		}
		crc[j]='\0';
		strcpy(newmsga,msg);
		strcat(newmsga,crc);
		printf("message to be send... ");
		puts(newmsga);
        printf("Enter the messesge recieved\n");
        scanf("%s",&rmsg);
        rmsgn=strlen(rmsg);
        if(rmsgn==newmsgn)
		{
		    cf=0;
		}
		else
		{
            cf=1;
		}
		i=0;
		c=0;
		for(i=0;i<rmsgn-crcgn;i++)
		{
			if(rmsg[i]=='1')
			{
			for(j=0;j<crcgn;j++)
			{
				a=intvalue(crcg[j]);
				b=intvalue(rmsg[i+j]);
                b=a^b;
				rmsg[i+j]=charvalue(b);
			}
			}

		}
		printf("processed message... ");
		puts(rmsg);
		rmsgn=strlen(rmsg);
        i=0;
		//printf("integer value %d ",(int)rmsg);
		//f=(int)rmsg-2273380;
            for(i=0;i<rmsgn;i++)
            {
                cf=cf+intvalue(rmsg[i]);
            }
		if(cf==0)
		{
		     printf("message successfully recieved\n");
		}
		else
		{
            printf("message corrupted\n");
		}
    return 0;
}
