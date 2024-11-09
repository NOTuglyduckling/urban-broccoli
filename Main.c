#include "Start.h"

int main(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage %s directory\n", argv[0]);
        exit(1);
    }
    int size=0;
    struct stat inode;
    if(lstat(argv[1], &inode) == -1){
        perror(argv[1]);
        exit(2);
    }
    printf("taille rep courant : %ld octets.\n", TailleRepCour());

    int num = 0;  // Initialisation de num comme entier
    namesrep(argv[1], &num,&size);  // Passage de l'adresse de num à la fonction
    printf("nombre de trucs : %d\n", num);  // Affichage correct du compteur

    printf("%s ", argv[1]);
    printf("%d octets, ", size);
    printf("dernière modification %s\n", ctime(&inode.st_mtime));

    return 0;
}