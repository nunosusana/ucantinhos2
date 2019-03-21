void print_events(){
    for(i=1;i<=n_events;i++){
        cout << events[i].deadline << " " << events[i].duration <<  " " << events[i].val <<  endl;
    }
}

void print_dp(){
    for(j=0;j<=max_deadline;j++)
        cout << DP[act][j] << " ";
    cout << endl;
}

void bubble_sort(){
	int i, j;
	event tmp;
	for (i = 0; i < n_events; i++){
    	for (j = 0; j < n_events-i; j++){
        	if (events[j].deadline > events[j+1].deadline){
				tmp=events[j];
				events[j]=events[j+1];
				events[j+1]=tmp;
            }
		}
	}
}

