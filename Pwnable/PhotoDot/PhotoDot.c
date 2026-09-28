// Name: photoDot.c
// Compile: gcc -o photoDot photoDot.c -fno-stack-protector -no-pie -zexecstack

#include <stdio.h>
#include <string.h>

void dotty(char* mem){
    char filter[100];

    strcpy(filter,mem);

    int i;
    for(i = 0; i < 100; i++) {
      
      if(filter[i]=='\0'){
        break;
      }

      if(filter[i] != '\x20' && filter[i] != '\x0A') {
        filter[i] = '.';
      }
      printf("%c",filter[i]);
    }
    printf("\n\n");
    printf("Dot Filter Applied!!\n");
}

void hidden(){
  printf("###########################################\n");
  printf("############# id : Jaeho Jeon #############\n");
  printf("############# pw : qwer1234 ###############\n");
  printf("###########################################\n");
  fflush(stdout);
}

int main(){

    char img_content[200];
      
    printf("Press Enter to read data...\n");

    getchar(); // Wait for Enter key press

    FILE* file = fopen("image","r");

    if(file == NULL) {
        printf("No File!\n");
        return 0;
    }

    fread(img_content, 1, 200, file);
    
    fclose(file);

    dotty(img_content);
    

    printf("App Exit~\n");
      
    return 0;
}