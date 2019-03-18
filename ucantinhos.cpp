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

int n_events,i,j,ant,act,tmp,max_deadline;
int DP[2][MAX_TIME];
int val[MAX_EVENT];
int duration[MAX_EVENT];
int deadline[MAX_EVENT];

void bubble_sort(){
	int i, j,tmp0,tmp1,tmp2;
	for (i = 0; i < n_events; i++){
    	for (j = 0; j < n_events-i; j++){
        	if (deadline[j] > deadline[j+1]){
				tmp0=val[j];
				tmp1=duration[j];
				tmp2=deadline[j];
				val[j]=val[j+1];
                duration[j]=duration[j+1];
                deadline[j]=deadline[j+1];
				val[j+1]=tmp0;
				duration[j+1]=tmp1;
                deadline[j+1]=tmp2;
            }
		}
	}
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
            if(j<duration[i]){
                DP[act][j]=DP[ant][j];
            }else if(j<deadline[i]){
                DP[act][j]=max(DP[ant][j],DP[ant][j-duration[i]]+val[i]);
            }else{
                DP[act][j]=DP[act][j-1];
            }
        }
    }
    return DP[act][max_deadline];
}

void print_events(){
    for(i=1;i<=n_events;i++){
        cout << deadline[i] << " " << duration[i] <<  " " << val[i] <<  endl;
    }
}

void print_dp(){
    for(j=0;j<=max_deadline;j++)
        cout << DP[act][j] << " ";
    cout << endl;
}

int main(){
    cin >> n_events;
    max_deadline=0;
    for(i=1;i<=n_events;i++){
        cin >> deadline[i] >> duration[i] >> val[i];
        max_deadline=max_deadline<deadline[i]?deadline[i]:max_deadline;
    }
    bubble_sort();
    cout << bottom_up() << endl;
    return 0;
}


