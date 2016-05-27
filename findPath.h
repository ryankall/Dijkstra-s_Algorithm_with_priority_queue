/* 
 * File:   findPath.h
 * Author: Ryan Kallicharran
 *
 * Created on December 19, 2015, 7:32 PM
 */

#ifndef FINDPATH_H
#define	FINDPATH_H

#include <fstream>
#include <iostream>
#include <string>
#include "Graph.h"
#include <queue>
#include "Edge.h"
#include <functional>

using namespace std;

class findPath {
public:
    //default constructor
    findPath();
     
    /*
     * fills the adjacency list with a given file name
     * if it exist
     * @param file name from argument 1
     */
    void buildGraph( char* filename);
    
    /*
     * computes the shortest path to all vertex from a give start
     * vertex
     * @param argument 2 as start vertex
     * 
     */
    void runDijkstra( char* sVer );
    
    /**
     * Print a path to a given target vertex
     * @param targetPath
     */
    void printOnePath( int targetPath );
private:
    
    Graph AdjList;
    int intialVertex;
    int numberVertex;  
};

#include "findPath.cpp"
#endif	/* FINDPATH_H */

