#pragma once
#include <string>
#include <list>
#include "Edge.h"
#include <iostream>
using namespace std;

template<class Data>
class Node{
    private:
    string id;
    string name;
    list<Edge<Data>> edges; 
    public:
    static unsigned int count;

    Node(){
        count++;
        id = "N" + to_string(count);
        name = "";
    }
    
    ~Node(){
        count--;
    }
    string getID(){
        return id;
    }
    string getName(){
        return name;
    }
    void setName(string name){
        this->name = name;
    }
    bool operator ==(const Node& rhs){
        return this->id == rhs.id;
    }
    void operator =(const Node<Data>&rhs){
        this->id = rhs.id;
        this->edges = rhs.edges;
    }
    void pushEdge(int destinationIndex,Condition<Data> expression,Action<Data> action){
        edges.push_back(Edge(this->id,destinationIndex,expression,action));
    }
    friend ostream& operator<<(ostream& os,Node node){
        os<<node.id;
        return os;
    }    
};
template<class Data>
unsigned int Node<Data>::count = 0;
