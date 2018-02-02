//
//  custom.h
//  GetShortestPath2
//
//  Created by hgl on 2018/2/2.
//  Copyright © 2018年 hgl. All rights reserved.
//

#ifndef custom_h
#define custom_h
#define MAX_VERT_NUM 10
typedef int Bool;
#define False 0
#define True 1
struct Graph{
    char verts[MAX_VERT_NUM];
    int edgs[MAX_VERT_NUM][MAX_VERT_NUM];
    int vertnum;
    int edgnum;
};
struct Graph init(void);
void printEdg(struct Graph g);
void ShortestPath_FLOYD(struct Graph g);
void ShortestPath_FLOYD(struct Graph g);
#endif /* custom_h */
