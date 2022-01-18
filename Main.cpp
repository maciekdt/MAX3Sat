#include "Max3SatProblem.h"
#include <iostream>
#include <fstream> 
#include <sstream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    /*char str[] = "- This, a sample string.";
    char* pch;
    printf("Splitting string \"%s\" into tokens:\n", str);
    pch = strtok(str, " ,.-");
    while (pch != NULL)
    {
        printf("%s\n", pch);
        pch = strtok(NULL, " ,.-");
    }*/
    return 0;
    */
    Max3SatProblem* test = new Max3SatProblem;
    test->load("m3s_50_0.txt");
    return 0;
>>>>>>> 1e16e2222070ea4da98dfc99f742f91fa812e4b7

}
