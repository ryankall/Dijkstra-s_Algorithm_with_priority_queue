/* 
 * File:   findPath.cpp
 * Author: Ryan Kallicharran
 * 
 * Created on December 19, 2015, 7:32 PM
 */

#include "findPath.h"
#include <stdlib.h>
#include <sstream>
#include <string>
#include <fstream>
#include <stack>

//deafult constructor
findPath::findPath() {}

void findPath::buildGraph(char* fileName){
    
    //opens file we are reading
    std::ifstream myFile;
    myFile.open(fileName, std::ios_base::in);
    
    //check if file exists
    if(!myFile.good()){
        std::cout<<"Error: file does not exist"<<std::endl;
        exit(1);
    }

    //takes the first value in file as the number of vertex
    string firstLine;
    int numVertex;
    getline(myFile, firstLine);
    
    //converts to string to int
    istringstream( firstLine) >> numVertex;
    numberVertex = numVertex;
    
    //calls start build to resize adjacency list
    AdjList.startBuild(numVertex);
    
    int srcV;
    
    //Build the adjacency list
    while(!myFile.eof()){
       
        //index on the adj list
        myFile >> srcV;
        
        //destination and weight variable
        int destV;
        double edgeWeight;
        
        //filling up adjacency list
        while ( true ){
            myFile >> destV;
            
            //stop loop if we see -1
            if( destV == -1)
                break;
            else{
                myFile >> edgeWeight;
            }
            
            //add to adjacency list
            AdjList.addEdge(srcV, destV, edgeWeight );
        }
    }//end while  
    //close file
    myFile.close(); 
}

void findPath::runDijkstra(  char* sVer){
  
    //convert argument to string to int
    string a(sVer);
    int holdStart;
    std::istringstream ss(a);
    ss >> holdStart;
    intialVertex = holdStart;
    //convert finish
    
    if(intialVertex >= numberVertex){
        cout<<"Invalid start vertex, please review the graph"<<endl;
        exit(1);
    }
    
    //our queue
    std::priority_queue<Edge, std::vector<Edge>, Edge > my_min_heap;
      
    //set the start vertex to cost to 0
    AdjList.getCosts()[holdStart] = 0;
    
    //vertex that is being analyzed
    Edge *v = new Edge(holdStart, 0); //vertex that is being analyzed
    my_min_heap.push(*v);
 
    while(!my_min_heap.empty()){

        //put min distance in v
        *v = my_min_heap.top();
        //remove min from queue
        my_min_heap.pop();
        AdjList.getKnown()[v->Edest] = true;
        
        /*
         This if is necessary because when all the vertices are 
         "known" v->weight would always be MAX_INT and the while
         */
        if (v->Eweight <= AdjList.getCosts()[v->Edest]) {
            
            // it is the adjacent vertices
            for (vector<Edge>::iterator it = AdjList.getList()[v->Edest].begin(); it != AdjList.getList()[v->Edest].end(); ++it){
                
                if(AdjList.getKnown()[it->Edest] == false){
                    if (AdjList.getCosts()[it->Edest] > AdjList.getCosts()[v->Edest] + it ->Eweight){
                        
                        AdjList.getCosts()[it->Edest] = AdjList.getCosts()[v->Edest] + it->Eweight;
                        AdjList.getPath()[it->Edest] = v->Edest;
                        
                        Edge*temp = new Edge(it->Edest,AdjList.getCosts()[it->Edest]);
                        my_min_heap.push(*temp);
                    }
                }
            }
        }
    }
                
}

/*
 Print path to a specified vertex
 */
void findPath::printOnePath( int targetPath){
    
    if(targetPath >= numberVertex){
        cout<< "Vertex does not exist in graph, please review the graph."<<endl;
        return;
    }
    //in case we are looking to print the start vertex 
    if(targetPath == intialVertex){
        cout<< "Path:: To self is always 0 cost"<<endl;
        return;
    }
    
    int cost = targetPath;
    
    //start vertex
    //cout<< "Path:: "<< intialVertex<<" -----> ";
    std::stack<int> printQ;
    
    //backtrack to find path in our path vector
    do{
        
        printQ.push(targetPath);
        targetPath = AdjList.getPath()[targetPath];
        if(targetPath == -1){
            cout<< "Path does not exists from "<< intialVertex <<" to "<< cost <<endl;
            return;
        }
               
    }while( targetPath != intialVertex );
    
    printQ.push(intialVertex);
     
    //print stack in correct order
    cout<<"Path:: ";
    while(!printQ.empty()){
    
        cout<< printQ.top();
        printQ.pop();
        
        if(!printQ.empty()){
          cout<<" -----> ";        
        }
            
    }
    cout<<":: [Cost of Path: "<< AdjList.getCosts()[cost]<<" ]"<<endl;

}
