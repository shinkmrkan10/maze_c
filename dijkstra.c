#include <stdio.h>
#define INF 1000000000
#define NUMBER 10
int dist[NUMBER][NUMBER];
int cost[NUMBER];
char used[NUMBER];

void dijkstra(int cost[], char used[], int dist[NUMBER][NUMBER], int g)
{
 int x, y, min;
 min = INF;
 for(x = 0; x < NUMBER; x++){
//  cost[x] = INF;
//  used[x] = 0;
 }
// cost[g] = 0;
 while(1){
  min = INF;
  for(x = 0; x < NUMBER; x++){
   if(!used[x] && min > cost[x])
    min = cost[x];
    used[x] = 1;
  }
  if(min == INF)
   break;
  for(y = 0; y < NUMBER; y++){
   if(cost[y] == min){
    for(x = 0; x < NUMBER; x++){
     if(cost[x] > dist[x][y] + cost[y])
      cost[x] = dist[x][y] + cost[y];
    }
//    used[y] = 1;
   }
//    used[x] = 1;
  }
 }
}

int main(void){
 int i, j, k;

// 距離の初期化
 for(i = 0; i < NUMBER; i++){
  for(j = 0; j < NUMBER; j++){
   dist[i][j] = INF;
  }
  dist[i][i] = 0;
 }
 for(i = 0; i < NUMBER -1; i++){
   dist[i][(NUMBER + i -  1) % NUMBER] = i % 5 + 1;
   dist[(NUMBER + i - 1) % NUMBER][i] = i % 5 + 1;
   dist[i][(NUMBER + i + 1) % NUMBER ] = i % 6 + 1;
   dist[(NUMBER + i + 1) % NUMBER ][i] = i % 6 + 1;
 }
// 距離の表示
 for(i = 0; i < NUMBER; i++){
  for(j = 0; j < NUMBER; j++){
   printf("%d ",dist[i][j]);
  }
  printf("\n");
 }
    printf("\n");
// コストの初期化 
 for(i = 0; i < NUMBER; i++){
  cost[i] = INF;
  used[i] = 0;
 }
  cost[0] = 0;

for(  k = 0; k < 2; k++){

 for(i = 0; i < NUMBER; i++){
    dijkstra(cost, used, dist, 0);
  for(j = 0; j < NUMBER; j++){
    printf("%d ",cost[j]);
 }
    printf("\n");
}
    printf("\n");
}
 return 0;

}

