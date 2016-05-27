/* 
 * File:   main.cpp
 * Author: Ryan Kallicharran
 *
 * Created on December 19, 2015, 9:40 AM
 */

#include <iostream>
#include <queue>
#include <string>
#include "findPath.h"

using namespace std;

/*
 * Driver program
 */
int main(int argc, char** argv) {

    findPath test;
    //build graph 
    test.buildGraph(argv[1]);
    //compute shortest path
    test.runDijkstra(argv[2]);
    
    
    //continuous query
    bool finished = false;
    int target;
    do{
        //prompt user
        cout<<"Please enter a target vertex for their shortest path from :"<<argv[2]<<endl;
        cout<<"enter Target vertex = ";
        cin>> target;
         
        //search path
        test.printOnePath(target);
        
        //end or not end loop decided by user
        cout<< "Please enter 1 to continue or 0 to stop searches: "<<endl;
        cin >> finished;
        cout<<endl;
        cout<<endl;
    }while(finished);
    
    
    return 0;
}

