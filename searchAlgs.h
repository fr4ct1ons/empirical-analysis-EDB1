#ifndef SEARCHALGS_H
#define SEARCHALGS_H

int *myTrnSearch(int *searchVal, int *first, int *last);
int *myLinSearch(int *searchVal, int *first, int *last);
int *myBinSearch(int *searchVal, int *first, int *last);
int *myJmpSearch(int *searchval, int *first, int *last, int jumpVal = 10);

#endif