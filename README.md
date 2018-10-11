# FST
This is a generic Finite State Transducer written in C++.
# How to use:
1) Hash include the FST.h file in main.cpp
2) Make a node vector containing all of your nodes
3) For each node define its transitions i.e edges, you can optionally name the nodes.
4) Each edge has condtions and actions which are defined in the TransitionsConditions.h file
5) Make sure to pass in your input data to the FST object 
6) Run fst.simulate(n) where n is a integer number of steps
# Example:
```


#include <iostream>
#include "FST.h"
#include "TransitionConditions.h"

// The generic arguments are for the input data output data and input tracker
typedef Node<string,string,int> FstNode;//used this to avoid typing generics
int main(int argc, const char * argv[]) {
    vector<FstNode> nodes;
    
    FstNode startNode;
    FstNode clickIt;
    FstNode pickOneAtRandom;
    FstNode didItWork;
    FstNode askForHelp;
    FstNode googleIt;
    FstNode haveBeenTrying;
    FstNode youreDone;
    
    startNode.pushEdge(1,is1,outputFoundItem);//pushEdge takes the destination in the nodes vector
    startNode.pushEdge(5,is0,cantFindOne);
    clickIt.pushEdge(2,is1,terminate);
    clickIt.pushEdge(3,is0,outputNo);
    haveBeenTrying.pushEdge(4,is1,terminateAskForHelp);
    haveBeenTrying.pushEdge(0,is0,advance);
    pickOneAtRandom.pushEdge(1,is1,outputYes);
    pickOneAtRandom.pushEdge(6,is0,googleTheName);
    googleIt.pushEdge(2,is1,terminate);
    googleIt.pushEdge(3,is0,beenTrying);
    //note the last two parameters are the conditions and actions conditions are bool functions
    //conditions acts on input data and the input tracker
    //actions act on input data and output data as well as the input tracker
    
    nodes.push_back(startNode);//0
    nodes.push_back(clickIt);//1
    nodes.push_back(youreDone);//2
    nodes.push_back(haveBeenTrying);//3
    nodes.push_back(askForHelp);//4
    nodes.push_back(pickOneAtRandom);//5
    nodes.push_back(googleIt);//6

    FST<string,string,int> diagram(startNode,nodes,"1111");
    diagram.simulate(4);
    cout<<diagram.output<<endl;
    return 0;
}

```
The above code models the following FST diagram https://xkcd.com/627/ taking a binary string as input.
