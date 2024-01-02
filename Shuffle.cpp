//-----------------------------------------------------------------------------
// Name: Lia Cui
// CRUZID: ljcui
// Assignment Name: PA5
//
//-----------------------------------------------------------------------------


#include<iostream>
#include<string>
#include<stdexcept>
#include <cstdlib>
#include "List.h"

using namespace std;

void shuffle(List& D){
    int count = 0;
    int i, num = D.length();
    int mfloor = (int)(num/2);

    List A, B, M;

    bool inloop = true;

    M = D;
    while(inloop){
        M.moveFront();
        for(i = 0; i < mfloor; i++){
            A.insertBefore(M.moveNext());
        }
        for(i = mfloor; i < num; i++){
            B.insertBefore(M.moveNext());
        }

        A.moveFront();
        B.moveFront();
        M.clear();
        for(i = 0; i < mfloor; i++){
            M.insertBefore(B.moveNext());
            M.insertBefore(A.moveNext());
        }
        if(num == (2 * mfloor + 1)){
            M.insertBefore(B.moveNext());
        }

        A.clear();
        B.clear();

        if(D == M){
            inloop = false;
        }
        count++;
    }

    // fprintf(stdout, " %-5d          %-d\n", D.length(), count);
    cout << " " + std::to_string(D.length());
    cout.width(16);
    cout << std::to_string(count) << endl;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        //fprintf(stderr, "Usage: %s input\n", argv[0]);
        cout << "Usage: " + string(argv[0]) + " input" << endl;
        exit(1);
    }

    int num = atoi(argv[1]);

    int i;
    List D;
    int j;

    cout << "deck size       shuffle count" << endl;
    cout << "------------------------------" << endl;

    // fprintf(stdout, "deck size      shuffle count\n");
    // fprintf(stdout, "------------------------------\n");

    for(j = 1; j <= num; j++){
        D.clear();
        for(i = 0; i < j; i++){
            D.insertBefore(i);
        }

        shuffle(D);
    }

    return(EXIT_SUCCESS);
}

