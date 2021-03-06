//
//  GraphOpera.c
//  GetShortestPath2
//
//  Created by hgl on 2018/2/2.
//  Copyright © 2018年 hgl. All rights reserved.
//

#include <stdio.h>
#include "custom.h"
#include <stdlib.h>
#define MAXDISTANCE 9999//假如两个顶点没有 直接 的路径，它们之间的权值就用这个来表示

/*
  选用邻接矩阵存储图的关系，i和j两个顶点间如没有直接路径，那么arcs[i][j]=9999
 */
struct Graph init(void){
    struct Graph g;
    int i,j,k1,k2,weight;
    char data1,data2;
    int locateVert(struct Graph g,char data);
    printf("请输入图的顶点数:");
    scanf("%d",&g.vertnum);
    printf("请输入图的边数:");
    scanf("%d",&g.edgnum);
    for(i=0;i<g.vertnum;i++){
        printf("请输入第%d个顶点:",i+1);
        scanf(" %c",&g.verts[i]);
    }
    for(i=0;i<g.vertnum;i++){
        for(j=0;j<g.vertnum;j++){
            g.edgs[i][j]=MAXDISTANCE;//先给边赋上最大的权值
        }
    }
    for(j=0;j<g.edgnum;j++){
        printf("请输入第%d条边的起点:",j+1);
        scanf(" %c",&data1);
        printf("请输入第%d条边的终点:",j+1);
        scanf(" %c",&data2);
        printf("请输入第%d条边的权值:",j+1);
        scanf("%d",&weight);
        k1=locateVert(g,data1);
        k2=locateVert(g,data2);
        g.edgs[k1][k2]=weight;//对边进行赋权值
    }
    return g;
}

/*
 根据顶点信息求顶点的位置
 */
int locateVert(struct Graph g,char data){
    int i;
    for(i=0;g.verts[i]!=data;i++);
    if(i>g.vertnum-1){
        printf("输入的顶点有误");
        exit(1);
    }
    return i;
}

/*
 打印该图的边的权值
 */
void printEdg(struct Graph g){
    int i,j;
    for(i=0;i<g.vertnum;i++){
        for(j=0;j<g.vertnum;j++){
            printf("%d\t",g.edgs[i][j]);
            if(j==g.vertnum-1){
                printf("\n");
            }
        }
    }
}

/*
   弗洛伊德(Floyd)算法求每一对顶点之间的最短路径
 */
void ShortestPath_FLOYD(struct Graph g){
    int D[MAX_VERT_NUM][MAX_VERT_NUM];//表示两点之间的最短路径权值和
    Bool p[MAX_VERT_NUM][MAX_VERT_NUM][MAX_VERT_NUM];//若p[v][w][u]为True，则u是从v到w当前求得最短路径上的顶点
    int i,v,w,u;
    for(v=0;v<g.vertnum;v++){//初始化D[v][w] 和p[v][w][u]
        for(w=0;w<g.vertnum;w++){
            if(w==v){
                D[w][v]=0;
            }else{
                D[v][w] = g.edgs[v][w];
            }
            for(u=0;u<g.vertnum;u++){
                p[v][w][u]=False;//初始化三维数组
            }
            if(D[v][w]<MAXDISTANCE){//从v到w有直接路径 说明v顶点肯定能到达w顶点，那么w和v一定是v到w顶点路径上的顶点
                p[v][w][v]=True;
                p[v][w][w]=True;
            }
        }
    }
    for(u=0;u<g.vertnum;u++){
        for(v=0;v<g.vertnum;v++){
            for(w=0;w<g.vertnum;w++){
                if(D[v][u]+D[u][w]<D[v][w]){//从v经u到w的一条路径更短
                    D[v][w]=D[v][u]+D[u][w];
                    for(i=0;i<g.vertnum;i++){
                        if(p[v][u][i] || p[u][w][i]){//把v到u和u到w的路径上的顶点就置为True
                            p[v][w][i]=True;
                        }
                    }
                }
            }
        }
    }
    //打印出每一对顶点间的最短路径
    for(v=0;v<g.vertnum;v++){
        for(w=0;w<g.vertnum;w++){
            if(w==v){
                continue;
            }
            if(D[v][w]<MAXDISTANCE && D[v][w]>0){
                printf("%c",g.verts[v]);
                for(i=0;i<g.vertnum;i++){
                    if(i==v || i==w){
                        continue;
                    }
                    if(p[v][w][i]){
                       printf("->%c",g.verts[i]);
                    }
                }
                printf("->%c\t",g.verts[w]);
                printf("最短距离为:%d\n",D[v][w]);
            }
        }
    }
}
