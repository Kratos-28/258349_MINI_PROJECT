
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define MAX_LENGTH 1024;
//structure to store content of file 
struct sorting{
    char *Name_of_sorting;
    char *execution_time;

};
struct sorting sort[1024];
int  store_file();
int  store_file(){
    FILE *fp;
    char *buf = malloc(1024);
    char *tmp; 
    if (buf == NULL) {
        printf ("No memory\n");
        return 1;
    }
     if( ( fp = fopen( "rough.csv", "r" ) ) == NULL ) //Reading a file
    {
        printf( "File could not be opened.\n" );
        return 0;
    }
    int i = 0;
    char *name;
    char *min=NULL;
    int index;
    while (fgets(buf, 255, fp) != NULL)
    {
        if ((strlen(buf)>0) && (buf[strlen (buf) - 1] == '\n'))
            buf[strlen (buf) - 1] = '\0';       

        tmp = strtok(buf, ",");
        sort[i].Name_of_sorting = strdup(tmp);

        tmp = strtok(NULL, ",");
        sort[i].execution_time = strdup(tmp);
        if(min==NULL){
            min=sort[i].execution_time;
        }
        else{
            if(atof(sort[i].execution_time)<atof(min)){
                index=i;
                min=sort[i].execution_time;
            }
        }
   
    //printf("exectuion time:%f\n",atof(sort[i].execution_time));
        i++;
    }
    printf("\n  -----------------*****RESULT OF THE PROGRAM*****----------------------\n");
    printf("\n  The best algortihtm is: %s \t Exectuion time: %s\n",sort[index].Name_of_sorting,sort[index].execution_time);
    printf("\n  -----------------*****END OF THE PROGRAM*****----------------------");
    //free(buf);
    fclose(fp);
    return 0;

}

