#include <stdio.h>
#define INF 1000000000
#define NUMBER 15
int dist[NUMBER][NUMBER];
int cost[NUMBER];
char used[NUMBER];

void dijkstra(int cost[], char used[], int dist[NUMBER][NUMBER])
{
 int x, y, min;
 while(1){
  min = INF;
  for(x = 0; x < NUMBER; x++){
   if(!used[x] && min > cost[x]){
    min = cost[x];
    used[x] = 1;
   }
  }
  if(min == INF){
   break;
  }
  for(y = 0; y < NUMBER; y++){
   if(cost[y] == min){
    for(x = 0; x < NUMBER; x++){
     if(cost[x] > dist[x][y] + cost[y])
      cost[x] = dist[x][y] + cost[y];
    }
   }
  }
 }
}

int main(void){
 int i, j;

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
   dist[i][(NUMBER + i + 7) % NUMBER ] = i % 9 + 1;
   dist[(NUMBER + i + 7) % NUMBER ][i] = i % 9 + 1;
 }

// 距離の表示
 for(i = 0; i < NUMBER; i++){
  for(j = 0; j < NUMBER; j++){
    if(dist[i][j] == INF){
      printf("X ");
    }
    else{
   printf("%d ",dist[i][j]);
  }
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

// ダイクストラ法
 dijkstra(cost, used, dist);

// 最短距離計算結果の表示
 for(i = 0; i < NUMBER; i++){
    printf("%3d : %d \n", i, cost[i]);
 }

 return 0;

}