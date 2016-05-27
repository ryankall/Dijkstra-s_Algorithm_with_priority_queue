
/*
 The graph is implemented unsing a Adjecency List, which is a 
 vector of a vector of Edge. The other fields: costs, paths, 
 and known, are utilize to keep track of the shortest cost, the path,
 and  whether or not that node had been visited, respectively.
 */
#ifndef __Graph__
#define __Graph__

#include <stdio.h>
#include <vector>
#include "Edge.h"
#include <list>
#include <string>
#include <iostream>
#include <cmath> //for INFINITY
using namespace std;


class Graph{
public:
    /*
     *It takes the number of vertices as an argument 
     *(nrVetices). It resizes the adjacency list to
     *nrVetices, and pushes nrVertices times
     *INFINITY, -1, and false, into costs, path, and
     *known, respectively
     * @param nrVertices
     */
    void startBuild(int nrVertices);
    
    //default constructor
    Graph();
    
    /*
     *addEdge adds an EdgeNode to the adjList. It
     *takes as a parameter, start, end and weight.
     *The node's fields dest and weight are given
     *end and weight and it is inserted in 
     *adjList[start].
     * 
     * @param start
     * @param end
     * @param weight
     */
    void addEdge(int start, int end, double weight);
    

    /*
     Accesor method that returns costs.
     */
    vector<double>& getCosts();
    
    /*
     Accesor method that returns path.
     */
    
    vector<int>& getPath();
    
    /*
     Accesor method that returns known.
     */
    vector<bool>& getKnown();
    
    /*
     Setter method for Known
     */
    vector<bool>& setKnown(int ver);
    /*
     Accesor method that returns adjList.
     */
    vector< vector<Edge> >& getList();
      

private:
    /*
     *adjList is an adjacency list made of a vector of a 
     *vector of edgeNodes. Each entry in the vector 
     *represents a vertices, and each of the edgeNodes 
     *represent the edges that are connected to each vertex.
     *If the cost of vertex i is MAX_INT, path does not exist
    */
    vector< vector<Edge> > adjList;
    
    /*
     *costs is used to keep track of the lowest cost to get
     *to each of the vertices from the initial vertex.
     */
    vector<double> costs;
    
    /*
     *path is a vector of integers that keeps track of the
     *shortest path to get to each of the vertices.
     */
    vector<int> path;
    
    /*
     *known is used to indicate whether a vertex in the 
     *graph has been visited or not. If known is true, it 
     *means that the shortest cost and the appropriate path
     *of that vertex is known.
     */
    vector<bool> known;
    
    
};
#include "Graph.cpp"
#endif 
