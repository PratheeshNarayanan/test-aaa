#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void main()
{
 char opcode[10],operand[10],label[10],code[10][10],ch; 
 char mnemonic[10][10]={"START","LDA","STA","LDCH","STCH","END"};
 int locctr,start,len,i=0,j=0;
 FILE *fp1,*fp2,*fp3;
// Opening 3 files for source pg, symtab and intermediate file
 fp1=fopen("INPUT.txt","r");
 fp2=fopen("SYMTAB.txt","w");
 fp3=fopen("INTERMED.txt","w");
//checking for valid file pointer
if(fp1==NULL)
   {
       printf("Error!");
       
    }
// reading the first instruction statement from source code
    fscanf(fp1,"%s%s%s",label,opcode,operand);

//checking the opcode is about to start the program
if(strcmp(opcode,"START")==0)
   {
   start=atoi(operand);// change the opernad address to integer
   locctr=start;//initilaizing location counter value as oeprnad address
   fprintf(fp3,"%s\t%s\t%s\n",label,opcode,operand);// write the line into intermediate file
   fscanf(fp1,"%s%s%s",label,opcode,operand);// scan the second instruction statement
  }
 else
  locctr=0;//if no operand value set starting address as 0

// process each instruction statement until it reaches the END
 while(strcmp(opcode,"END")!=0)
  {
    fprintf(fp3,"%d",locctr);// intialize intermediate file with location counter value
// Enter the symbol and location value in symtab
   if(strcmp(label,"--")!=0)
     fprintf(fp2,"%s\t%d\n",label,locctr);

// check for valid opcode
   strcpy(code[i],mnemonic[j]);
//perform location counter processing for each instruction statements by adding 3 bytes
   while(strcmp(mnemonic[j],"END")!=0)
    	{
    	 	if(strcmp(opcode,mnemonic[j])==0)  
     		{
     	 		locctr+=3;
     			 break;
     		}
     		strcpy(code[i],mnemonic[j]);
     		j++;

   	 }
   if(strcmp(opcode,"WORD")==0)
    locctr+=3;
   else if(strcmp(opcode,"RESW")==0)
    locctr+=(3*(atoi(operand)));
   else if(strcmp(opcode,"RESB")==0)
    locctr+=(atoi(operand));
   else if(strcmp(opcode,"BYTE")==0)
    ++locctr;
  fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);
  fscanf(fp1,"%s%s%s",label,opcode,operand);
  }

  fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
  fcloseall();
  printf("\n\nThe contents of Input Table :\n\n");
  fp1=fopen("INPUT.txt","r");
  ch=fgetc(fp1);


  while(ch!=EOF)
   {
    printf("%c",ch);
    ch=fgetc(fp1);
   }
  printf("\n\nThe contents of Output Table :\n\n\t");
  fp3=fopen("OUT.txt","w");
  ch=fgetc(fp3);


  while(ch!=EOF)
   {
    printf("%c",ch);
    ch=fgetc(fp3);
   }
  len=locctr-start;
  printf("\nThe length of the program is %d.\n\n",len);


  printf("\n\nThe contents of Symbol Table :\n\n");
  fp2=fopen("SYMTAB.txt","r");
  ch=fgetc(fp2);
  while(ch!=EOF)
   {
    printf("%c",ch);
    ch=fgetc(fp2);
   }
  fcloseall();
 


printf("\n**");}


