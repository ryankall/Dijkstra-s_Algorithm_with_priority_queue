


#include "Graph.h"
#include <list>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;

//Public Functions--------------------------------------------

/*
 The constructor of the graph
 pre condition: none
 post condition: 
 adjList.size() = nrVetices
 costs.size() = nrVertices
 path.size() = nrVertices
 known.size() = nrVertices
 */
Graph::Graph(){}

void Graph::startBuild(int nrVertices){
    adjList.resize(nrVertices);
    for(int i = 0; i < nrVertices; i++){//input initial conditions
        costs.push_back(INFINITY);
        path.push_back(-1);
        known.push_back(false);
    }
}



/*
 return costs
 */
vector<double>& Graph::getCosts() {
    return costs;
}

/*
 returns path
 */
vector<int>& Graph::getPath() {
    return path;
}

/*
 returns known
 */
vector<bool>& Graph::getKnown() {
    return known;
}



/*
 returns adjList
 */

vector< vector<Edge> >& Graph::getList(){
    return adjList;
}



/*
 Adds an edge to the adjecency list
 pre condition: none
 post condition:
 adjList[start].size() increases by one
 */
void Graph::addEdge(int start, int end, double weight){
    
    adjList[start].push_back( Edge(end, weight) );
}



  

