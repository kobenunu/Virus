
#include <iostream>
#include "Session.h"
#include "Tree.h"
#include "Graph.h"
#include <vector>
using namespace std;

//constructor
Tree::Tree(int rootLabel) : node(rootLabel), children(0){};

//destructor
Tree::~Tree() {clear();}
//copy constructor
Tree::Tree(const Tree &likeThis): node(likeThis.node), children(0){
    for(auto& elem: likeThis.children){
        addChild(elem->clone());
    }
}
//copy assignment operator
const Tree &Tree::operator=(const Tree &other) {
    if(this != &other) {
        clear();
        node = other.getNode();
        for (auto &i :other.getChildren()) {
            addChild(i->clone());
        }
    }
    return *this;
}

//move constructor
Tree::Tree(Tree &&other) {
    node = other.getNode();
    children = other.children;
    other.children.clear();
}

//move assignment operator
const Tree &Tree::operator=(Tree &&other) {
    clear();
    node = other.getNode();
    children = other.children;
    other.children.clear();
    return *this;
}


void Tree::clear() {
    for (auto & i : children) {
        delete i;
    }
    children.clear();
}

Tree * Tree::createTree(const Session &session, int rootLabel) {
    TreeType t = session.getTreeType();
    if (t==Root){
        RootTree *RT = new RootTree(rootLabel);
        return RT;
    }
    vector<vector<int>> vic = session.getGraph().getEdges();
    if(t==Cycle){

    }
    else{

    }
}
void Tree::addChild(Tree *child) {
    if(child != nullptr){
        children.push_back(child);
    }
}

void Tree::addChild(const Tree &child) {
    Tree* clone = child.clone();
    children.push_back(clone);
}

int Tree::getNode() const {
    return node;
}

vector<Tree *> Tree::getChildren() const{
    return children;
}



