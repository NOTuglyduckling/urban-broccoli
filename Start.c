#include "Start.h"

long TailleRepCour(){
    long oct=0;
    struct stat infos;
    DIR* current = opendir(".");
    struct dirent* element;
    if (current == NULL){
        perror(".");
        return -1;
    }
    while ((element = readdir(current)) != NULL){
        if (lstat(element->d_name, &infos) == -1){
            perror(element->d_name);
        } else if (S_ISREG(infos.st_mode)){ 
            oct += infos.st_size;
        }
    }
    closedir(current);
    return oct;
}

void namesrep(char nomRep[], int *num,int * size){
    struct stat infos;
    DIR* current = opendir(nomRep);
    if (current == NULL){
        perror(nomRep);
        return;
    }
    struct dirent* element;
    char designation[512];
    
    while ((element = readdir(current)) != NULL){
        if (strcmp(element->d_name, ".") && strcmp(element->d_name, "..")){
            strncpy(designation, nomRep, 511);
            strcat(designation, "/");
            strncat(designation, element->d_name, 511);
            if (lstat(designation, &infos) == -1)
                perror(designation);
            *size+=infos.st_size;
            (*num)++; 
            if (S_ISREG(infos.st_mode)){
                printf("%s\n", designation); 
            } else if(S_ISDIR(infos.st_mode)){    
                namesrep(designation, num,size);}
        }
    }
    closedir(current);
}


