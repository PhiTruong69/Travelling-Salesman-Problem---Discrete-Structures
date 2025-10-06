#include "bellman.h"

void BF(int graph[][30], int Numver, char start, int BellmanFordValue[], int BellmanFordPrevious[])
{
 int dinh = start - 'A';
       int newvalue[30];
       BellmanFordValue[dinh] = 0;
       for (int i = 0; i < Numver; i++)
       {
              if (BellmanFordValue[i] == -1)
                     BellmanFordValue[i] = 2147483647;
              newvalue[i] = BellmanFordValue[i];
       }
          
       for (int i = 0; i < Numver; i++)
       {
              if (BellmanFordValue[i] < 2147483647)
              {
                     for (int j = 0; j < Numver; j++)
                     {
                            if (graph[i][j] != 0)
                            {
                                   if (BellmanFordValue[i] + graph[i][j] < newvalue[j])
                                   {
                                          newvalue[j] = BellmanFordValue[i] + graph[i][j];
                                          BellmanFordPrevious[j] = i;
                                   }
                            }
                     }
              }
       }
       for (int i = 0; i < Numver; i++)
       {
              if (newvalue[i] ==2147483647)
                     BellmanFordValue[i] = -1;
              else
                     BellmanFordValue[i] = newvalue[i];
       }
}
string BF_Path(int graph[][30], int num, char arv, char des){
   
    int value[num];
    int pre[num];
     int start =arv -'A';
    int end =des -'A';
    for (int i =0; i <num; ++i){
        value[i] =-1;
        pre[i] =-1;
    }
    
    for (int i =0; i <num; ++i){
        BF(graph, num, arv, value, pre);
    }


    string kq;
    while (end !=start){
        kq +=end +'A';
        kq +=' ';
        end =pre[end];
    }
    kq +=start +'A'; //* thiếu đỉnh đầu tiên. 
    reverse(kq.begin(), kq.end()); //*đổi thứ tự. 
    return kq;
}
