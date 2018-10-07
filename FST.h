#pragma once
#include "Node.h"
#include <vector>

template  <class Data>
class FST{
    private:
    Edge<Data> getValidEdge(Node<Data>& n){
        auto it = n.edges.begin();
        while (it != n.edges.end()) {
            if (it->sourceID == n.getID() && it->exp(input)) {
                return *it;
            }
            it++;
        }
        return Edge<Data>();
    }
    public:
    vector<Node<Data>> nodes;
    Node<Data> currentNode;
    Node<Data> intialNode;
    Data input;
    FST(Node<Data> intialNode,vector<Node<Data>> nodes,Data input){
        this->intialNode = intialNode;
        this->nodes = nodes;
        this->input = input;
        currentNode = this->intialNode;
    }
    int transition(){
        Edge<Data> validEdge = getValidEdge(currentNode);
        if (validEdge.isNull()) {
            cout<<"FST is deadlocked\n";
            return -1;
        }
        validEdge.act(input);
        currentNode = nodes[validEdge.destinationIndex];
        return 0;
    }
    void simulate(unsigned int n){
        
        for(int i = 0; i < n; i++){
            cout<<i<<":"<<currentNode.getID()<<endl;
            int count = transition();
            if (count == -1) {
                return;
            }
        }
        
    }
    
};
