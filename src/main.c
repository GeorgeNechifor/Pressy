#include <stdio.h>
#include<stdlib.h>
#include"../include/pressy.h"

int main(int argc , char * argv[]) {


    pressy * app = createpressy();
    run(argc , argv , app);
    clearmemo(app);

    return 0;
}
