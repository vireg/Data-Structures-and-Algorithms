#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <time.h>

void xstr(char*, char*, char*, int);
void calCRC(char*, char*, char*, char*);
void tx_err(char*,int);

int main()
{
    int i,j,k,timer = time(NULL);
      char str[50];        //change str1[length],xores[length]
      char divisor[5] = "1011";     //change divisor
      printf("Divisor: %s\n", divisor);
      while(1){
      printf("Enter dataword: ");
      gets(str);
      if (strlen(str)>50) printf("dataword limit: 50\n");
      else break;
      }
      int clen=strlen(str)+strlen(divisor);       //strlen(str)=k, strlen(divisor)=n-k+1, total n+1
      char augword[clen];
      char codeword[clen];
      char rcvword[clen];

      for(i=0;i<clen-1;i++)             //0:n-1 augment n-k 0s
      {
       if(i<strlen(str)) augword[i]=str[i];
       else augword[i]='0';
      }
      augword[i]='\0';
      printf("Augmented dataword: %s\n", augword);
      
      calCRC(str,augword,divisor,codeword);
      printf("Codeword: %s\n",codeword);
      printf("Received Codeword (without error): %s\n",codeword);
      calCRC(str,codeword,divisor,rcvword);
      printf("Decoded dataword: %s\n",rcvword);
      tx_err(codeword,clen-1);
      printf("Received Codeword (with error): %s\n",codeword);
      calCRC(str,codeword,divisor,rcvword);
    getch();
}

void xstr(char* str1, char* str2, char* str3, int lstr)
{
     int i;
   for(i=0;i<lstr;i++)
   {
                      if(str1[i]==str2[i])
                      str3[i]='0';
                      else str3[i]='1';
   }
   str3[i]='\0';
   //puts(str3);
}

void tx_err(char* codeword,int cwlen)   //Function to randomly corrupt 1 bit
{
     int timer = time(NULL);
     int cbit=timer%cwlen;
     if (codeword[cbit]=='1') codeword[cbit]='0';
     else codeword[cbit]='1';
}

void calCRC(char* str, char* augword, char* divisor, char* codeword)
{
     int i,j,k;
     int clen=strlen(str)+strlen(divisor);
     char str1[5],xores[5],remainder[4];
     for(i=0;i<4;i++) str1[i]=augword[i];  //change value '4' according to divisor
     if(str1[0]=='1')                      //first xoring done by checking first bit
      xstr(str1,divisor,xores,strlen(divisor));
      else xstr(str1,"0000",xores,strlen(divisor));       //change no. of zeroes, "0000" according to divisor
      k=0;
      while(augword[k+4]!='\0')                           ////change value '4' according to divisor
      {
      //store xored result in another string, discard first bit and shift in next bit from dataword
      for(i=1;i<4;i++) str1[i-1]=xores[i];  //change value '4' according to divisor
      str1[i-1]=augword[k+4];
      str1[i]='\0';
      //printf("\nstr1=%s\n",str1);
      if(str1[0]=='1'){
                        xstr(str1,divisor,xores,strlen(divisor));
                        k++;
                        }
                  else {
                       xstr(str1,"0000",xores,strlen(divisor));  //change no. of zeroes, "0000" according to divisor
                       k++;
                       }
      }
      //str is the original string, xores contains the final remainder
      for(i=0,j=1;i<clen-1;i++)
      if(i<strlen(str)) codeword[i]=str[i];
      else codeword[i]=xores[j++];
      codeword[i]='\0';
      
      for(i=0,j=1;j<strlen(xores);i++)
      remainder[i]=xores[j++];
      remainder[i]='\0';
      printf("Remainder = %s\n",remainder);
      //printf("\nxores=%s\n",xores);
}
