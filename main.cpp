

#include <iostream>
#include "FST.h"
int main(int argc, const char * argv[]) {
    
    vector<Node<int>> nodes;
    Node<int> startNode;
    Node<int> clickIt;
    Node<int> googleIt;
    Node<int> askForHelp;
    Node<int> youreDone;
    
    //startNode.pushEdge(1,);
    FST<int> fst(startNode,nodes,2);
    fst.simulate(2);
    
    return 0;
}
