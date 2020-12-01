//
// Created by User on 10/9/2020.
//

#ifndef CS241_SEMANTIC_ANALYSIS_H
#define CS241_SEMANTIC_ANALYSIS_H

#include "scanner.h"
#include <map>

class Semantic_Analysis {
std::map<std::string, int> LabelTable;
public:
    void doLabels(std::vector<std::vector<Token>>&);

};


#endif //CS241_SEMANTIC_ANALYSIS_H
