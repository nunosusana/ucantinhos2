/*********************************************
 *
 *	 UCantinhos 2
 *
 ********************************************/

#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX_TIME 100001
#define MAX_EVENT 10001

typedef struct{
    int val, duration, deadline;
}event;

event events[MAX_EVENT];

int n_events,i,j,ant,act,tmp,max_deadline;
int DP[2][MAX_TIME];

int compare_func (const void * a, const void * b){
  return(((event *)a)->deadline - ((event *)b)->deadline);
}

int bottom_up(){
    for(j=0;j<=max_deadline;j++)
        DP[0][j]=DP[1][j]=0;
    ant=1;
    act=0;
    for(i=1;i<=n_events;i++){
        act=ant;
        ant=!ant;
        for(j=1;j<=max_deadline;j++){
            if(j<events[i].duration){
                DP[act][j]=DP[ant][j];
            }else if(j<events[i].deadline){
                DP[act][j]=max(DP[ant][j],DP[ant][j-events[i].duration]+events[i].val);
            }else{
                DP[act][j]=DP[act][j-1];
            }
        }
    }
    return DP[act][max_deadline];
}

int main(){
    cin >> n_events;
    max_deadline=0;
    for(i=1;i<=n_events;i++){
        cin >> events[i].deadline >> events[i].duration >> events[i].val;
        max_deadline=max_deadline<events[i].deadline?events[i].deadline:max_deadline;
    }
    qsort(events, n_events+1, sizeof(event), compare_func);
    cout << bottom_up() << endl;
    return 0;
}


