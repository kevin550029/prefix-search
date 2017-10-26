
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bench.h"
#define IN_FILE "cities.txt"
#define WRDMAX 256
#define LMAX 1024
#define SAMPLES 10000

double tvgetf()
{
    struct timespec ts;
    double sec;

    clock_gettime(CLOCK_REALTIME, &ts);
    sec = ts.tv_nsec;
    sec /= 1e9;
    sec += ts.tv_sec;

    return sec;
}


int bench_test(const tst_node *root, char *output_file)
{

    char word[SAMPLES][WRDMAX];
    char prefix[3] = "";
    char *sgl[LMAX] = {NULL};

    int sidx=0, count=0;

    //Load some city name as samples for prefic search
    FILE *prefixF = fopen(IN_FILE,"r");
    for (int i=0; i < SAMPLES; i++) {
        fscanf(prefixF, "%s", word[i]);
    }
    fclose(prefixF);


    double t1, t2;
    FILE *fp = fopen(output_file,"w");
    for (int i=0; i < SAMPLES; i++) {
        if (strlen(word[i]) < 3) continue;
        strncpy(prefix, word[i], 3);

        t1 = tvgetf();
        tst_search_prefix(root, prefix, sgl, &sidx, LMAX);
        t2 = tvgetf();

        fprintf(fp, "%d %.6f sec\n", count, t2 - t1);
        count++;

    }
    fclose(fp);

    //t1 = tvgetf();
    //res = tst_search_prefix(root, word, sgl, &sidx, LMAX);
    //t2 = tvgetf();
    return 0;
}

