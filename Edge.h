/* 
 * File:   edge.h
 * Author: Ryan Kallicharran
 *
 * Created on December 19, 2015, 7:59 PM
 */

#ifndef EDGE_H
#define	EDGE_H


struct Edge{
    /*
     The constructor creates an Edge taking as parameters
     the destination (dest) and weight. It restores
     the parameters in their respective fields.
     */
    
public:
    

    double Eweight;
    int Edest;
   
   Edge(){ Eweight = 0; Edest = 0;} 
    /*
     * set the variables
     */
    Edge(int dest, double weight){  Eweight = weight;  Edest = dest;}
    
   
    bool operator()(const Edge& l, const Edge& r)  
    {   return l.Eweight > r.Eweight;   }  
    
    Edge &operator =( const Edge &rhs){
        this->Edest = rhs.Edest;
        this->Eweight = rhs.Eweight;
        
       return *this;
    }
  
};


#endif	/* EDGE_H */

