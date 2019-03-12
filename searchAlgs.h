#ifndef SEARCHALGS_H
#define SEARCHALGS_H

int *myItrTrnSearch(int *searchVal, int *first, int *last);

int *myItrLinSearch(int *searchVal, int *first, int *last);

int *myItrBinSearch(int *searchVal, int *first, int *last);


int *myRecTrnSearch(int *searchVal, int *first, int *last);

int *myRecLinSearch(int *searchVal, int *first, int *last);

int *myRecBinSearch(int *searchVal, int *first, int *last);


int *myJmpSearch(int *searchval, int *first, int *last, int jumpVal = 10);

#endif