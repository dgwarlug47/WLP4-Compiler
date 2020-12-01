//
// Created by User on 10/22/2020.
//
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class Tree {
    int rootValue;
    std::vector<Tree> children;
public:
    void setRoot(int);
    void addChildren(Tree);
    void postOrderPrint();
};

void Tree::setRoot(int value){
   this->rootValue = value;
}

void Tree::addChildren(Tree t){
    this->children.push_back(t);
}

void Tree::postOrderPrint(){
    for (Tree child: this->children){
        child.postOrderPrint();
    }
    std::cout << this->rootValue << " " << this->children.size() << std::endl;
}

std::pair<Tree, int> treeCreator(std::vector<std::pair<int, int>> preOrderPrintedTree, int cursor){
    Tree answerTree;
    int answerCursor;
    answerTree.setRoot(preOrderPrintedTree[cursor].first);
    if (cursor == preOrderPrintedTree.size() - 1){
        answerCursor = cursor + 1;
    }
    else{
        int numberOfChildren = preOrderPrintedTree[cursor].second;
        int immediateCursor = cursor + 1;
        for (int child = 1; child <= numberOfChildren; child++){
            std::pair<Tree, int> newStuff = treeCreator(preOrderPrintedTree, immediateCursor);
            Tree newChildren = newStuff.first;
            immediateCursor = newStuff.second;
            answerTree.addChildren(newChildren);
        }
        answerCursor = immediateCursor;
    }
    std::pair<Tree, int> answer(answerTree, answerCursor);
    return answer;
}


int main(){
    std::vector<std::pair<int, int>> preOrderPrintedTree;
    std::string line;
    while (getline(std::cin, line)){
        std::stringstream ss(line);
        int rootValue;
        int numberOfChildren;
        ss >> rootValue;
        ss >> numberOfChildren;
        std::pair<int, int> p (rootValue, numberOfChildren);
        preOrderPrintedTree.push_back(p);
    }
    if (preOrderPrintedTree.empty()){
    }
    else{
        treeCreator(preOrderPrintedTree, 0).first.postOrderPrint();
    }
}
