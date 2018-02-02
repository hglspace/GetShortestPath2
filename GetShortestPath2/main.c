//
//  main.c
//  GetShortestPath2
//
//  Created by hgl on 2018/2/2.
//  Copyright © 2018年 hgl. All rights reserved.
//

#include <stdio.h>
#include "custom.h"

int main(int argc, const char * argv[]) {
    struct Graph g=init();
    printEdg(g);
    ShortestPath_FLOYD(g);
    return 0;
}
