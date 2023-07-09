#include <stdio.h>
#include <string.h>
#define BUFFERSIZE 256
int main();
void insertMode() {
  FILE *ptr = fopen("temp.txt","w");
  char buffer[BUFFERSIZE];
  fgets(buffer,BUFFERSIZE,stdin);
  scanf("%256[^\n]", buffer);
  fputs(buffer,ptr);
  fclose(ptr);
}
void write(char filename[BUFFERSIZE]) {
  rename("temp.txt",filename);
}
int start(){
  char c[BUFFERSIZE];
  char filename[BUFFERSIZE];
  scanf("%s",c);  
  if(strcmp(c,"a")== 0) {
    insertMode();
    main();
  }
  else if(strcmp(c,"q")== 0) {
    printf("quitting..");
    remove("temp.txt");
  }
  else if(strcmp(c,"w") == 0 ) {
    printf("Enter file name: ");
    scanf("%s",filename);
    write(filename);
    main();
  }
  else {
    printf("?");
    main();
  }


}

int main() {
  while (1==1)
  {
    start();
    return 0;
  }
}
