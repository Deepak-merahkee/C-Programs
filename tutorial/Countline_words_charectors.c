#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000
void  count_lines(char *file_name);
void  count_words(char *file_name);
void count_all(char *filename);
int main() {
    count_lines("      ");
    count_words("text.txt");
  //  count_all("text.txt");
    return 0;
}
void count_all(char *filename){
   FILE *fileptr;
   char ch;
   int linecount = 0;
   int wordcount = 0;
   int charcount = 0;

   fileptr = fopen(filename,"r");
    if (fileptr){
    while ((ch=getc(fileptr)) != EOF) {
         //count charector
     if (ch != ' ' && ch != '\n') {
            ++charcount;
          }
          //count words
     if (ch == ' ' || ch == '\n') {
             ++wordcount;
          }
          //Count lines
     if (ch == '\n') {
            ++linecount;
           }
    }

   if (charcount > 0) {
  linecount++;
  wordcount++;
    }
       printf("Number of charectors=%d\n",charcount );
       printf("Number of words=%d\n",wordcount );
       printf("Number of linecount=%d\n",linecount );
    }
}
/**
Checks weather the file is present of not
**/
void check_file_present(FILE *fileptr){
  if(fileptr == NULL){
      printf("File not found\n");
  }
}
/**
Counts the number of lines in the file
**/
void  count_lines(char *file_name){
    char line[MAX_SIZE];
    int count=0;
    FILE *fileptr =fopen(file_name,"r");
    check_file_present(fileptr);
    while(fgets(line, sizeof(line), fileptr) != NULL){
        count++;
    }
  printf("Number of lines= %d \n", count);
  fclose(fileptr);
}
/**
Counts the number of words in a file
**/
void count_words(char *file_name){
  int count=0;
  char ch;
  FILE *fileptr =fopen(file_name,"r");
  check_file_present(fileptr);
  while ((ch=fgetc(fileptr)) !=EOF) {
    if(ch==' ' || ch == '\n'){
      count++;
    }
  }
  printf("Number of words= %d\n",count );
}
