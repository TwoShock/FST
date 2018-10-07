#pragma once
#include <string>
using namespace std;

template<class Data>
class Edge{
    public:
    string sourceID;
    int destinationIndex;

    typedef bool(*Condition)(Data& data);
    typedef void(*Action)(Data& data);
    Condition exp;
    Action act;

    Edge(string sourceID,int destinationIndex,Condition exp,Action act){
        this->sourceID = sourceID;
        this->destinationIndex = destinationIndex;
        this->exp = exp;
        this->act = act;
    }
    Edge(){
        sourceID = "";
        destinationIndex = -1;
    }
    void operator =(const Edge& rhs){
        this->sourceID = rhs.sourceID;
        this->destinationIndex = rhs.destinationIndex;
        this->exp = rhs.exp;
        this->act = rhs.act;
    }
    bool isNull(){
        return (sourceID == "") && (destinationIndex == -1);
    }
};
