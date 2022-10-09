#include <bits/stdc++.h>
using namespace std;
#define V 4

// implementation of traveling Salesman Problem
int tsp_dis(int graph[][V][2], int s)
{
    // store all vertex apart from source vertex
    vector<int> vertex;
    int route[4]={0,0,0,0},i;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
 
    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do {
 
        // store current Path weight(cost)
        int current_pathweight = 0;
 
        // compute current path weight
        int k = s;
        for ( i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]][0];
            k = vertex[i];          
        }
        current_pathweight += graph[k][s][0];

        if(min_path>current_pathweight){
           for ( int j= 0; j < 4; j++)
           {
            route[j]=vertex[j];
            // cout<<route[j]<<endl;
           }      
        }
         
        // update minimum
        min_path = min(min_path, current_pathweight);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
        
        //printing best route for minimum distance 
        cout<<"The best route for minimum distance is : "<<endl;
        cout<<"1";
        for ( i = 0; i < 4; i++)
        {
            cout<<"-->";
            cout<<route[i]+1;
        }
 
    return min_path;
}

int tsp_time(int graph[][V][2], int s)
{
    // store all vertex apart from source vertex
    vector<int> vertex;
    int route[4]={0,0,0,0},i;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
 
    // store minimum time Hamiltonian Cycle.
    int min_time = INT_MAX;
    do {
 
        // store current Path time
        int current_time = 0;
 
        // compute current path time
        int k = s;
        for ( i = 0; i < vertex.size(); i++) {
            current_time += graph[k][vertex[i]][1];
            k = vertex[i];          
        }
        current_time += graph[k][s][1];

        if(min_time>current_time){
           for ( int j= 0; j < 4; j++)
           {
            route[j]=vertex[j];
           }      
        }
         
        // update minimum
        min_time = min(min_time, current_time);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));

        //printing best route for minimum time
        cout<<"The best route for minimum time is : "<<endl;
        cout<<"1";
        for ( i = 0; i < 4; i++)
        {
            cout<<"-->";
            cout<<route[i]+1;
        }
 
    return min_time;
}
 
void tsp_avvg_dist_time(int graph[][V][2], int s)
{
    // store all vertex apart from source vertex
    vector<int> vertex;
    int route[4]={0,0,0,0},i;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
 
    // store minimum time Hamiltonian Cycle.
    int min_value = INT_MAX;
    do {
 
        // store current Path time
        int current_value = 0;
 
        // compute current path time
        int k = s;
        for ( i = 0; i < vertex.size(); i++) {
            current_value += (graph[k][vertex[i]][1]*graph[k][vertex[i]][0]);
            k = vertex[i];          
        }
        current_value += (graph[k][s][1]*graph[k][s][0]);

        if(min_value>current_value){
           for ( int j= 0; j < 4; j++)
           {
            route[j]=vertex[j];
           }      
        }
         
        // update minimum
        min_value = min(min_value, current_value);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));

        //printing best route for minimum time
        cout<<"The best route for average distance and time is : "<<endl;
        cout<<"1";
        for ( i = 0; i < 4; i++)
        {
            cout<<"-->";
            cout<<route[i]+1;
        }

        //calculating avg cost and avg time
        /*int avg_cost=0,avg_time=0;
        for ( i = 0; i < 4; i++)
        {
         cout<<"\n"<<route[i];
         if (i=3)
         {
            
         avg_cost+=graph[route[i]][route[1]][0];
         cout<<"\n"<<graph[route[i]][route[1]][0]<<endl;
         avg_time+=graph[route[i]][route[1]][1];
         }
         else{         
         avg_cost+=graph[route[i]][route[i+1]][0];
         cout<<graph[route[i]][route[1]][0]<<endl;
         avg_time+=graph[route[i]][route[i+1]][1];
        }
      }*/
      // cout<<"\nThe average cost for this route = "<<avg_cost<<endl<<"The average time for this route = "<<avg_time;

}

int main(){
    
int graph[4][V][2] = { { {0,0}, {9,4},{4,3} , {6,4} },
                       { {7,6},{0,0},{3,15},{2,3} },
                       {{10,3},{6,9},{0,0},{9,10}},
                       {{12,10},{15,8},{6,7},{0,0}}
                     };

int s = 0;
    cout<<"CASE 1 ==> "<<endl;
    cout <<"\nTotal cost of path is : "<<tsp_dis(graph, s) << endl;

    cout<<"\n\nCASE 2 ==> "<<endl;
    cout<<"\nTotal time of path is : "<<tsp_time(graph,s)<<endl;

    cout<<"\n\nCASE 3 ==> "<<endl;
    tsp_avvg_dist_time( graph,  s);

    return 0;
}     