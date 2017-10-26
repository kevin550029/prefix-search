#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define WRDMAX 256
int main()
{

    char filename[30];
    printf("File Name: ");
    scanf("%s/n",filename);
    FILE *inputF = fopen (filename,"r");

    char word[WRDMAX];
    int count=0;
    char *token;
    int cnt=10;
    double time=0,standard=0,sum=0,sigma=0,ave=0,value=0;

    while(fgets(word,255,inputF) !=NULL ) {
        token = strtok(word," ");
        time= atof(strtok(NULL," "));
        sum += time;
        count++;
    }
    ave=sum/count;
    fclose(inputF);

    FILE *inputFF = fopen (filename,"r");
    while(fgets(word,255,inputFF) !=NULL ) {
        token = strtok(word," ");
        time = atof(strtok(NULL," "));
        standard = time - ave;
        standard *= standard;
        sigma += standard;
    }
    fclose(inputFF);

    sigma /= count;
    value = sqrt(sigma);

    printf("Mean: %f\n", ave);
    printf("Number: %d\n",count);
    printf("Standard Deviation:%f\n",value);
    return 0;
}
