//
// Created by User on 10/9/2020.
//

#include "MIPS_semantic_analysis.h"
#include "MIPS_assembly.h"


void Semantic_Analysis::doLabels(std::vector<std::vector<Token> > &lines) {
    int label_position = 0;
    for (int lineIndex = 0; lineIndex < lines.size(); lineIndex++){
        if(lines[lineIndex].empty()){
            return;
        }
        // pass through all Labels from the begining
        int currentIndex = 0;
        while(lines[lineIndex][currentIndex].getKind() == Token::Kind::LABEL){
            std::string value = lines[lineIndex][currentIndex].getLexeme();
            if (this->LabelTable.count(value.substr(0, value.size()-1)) == 1){
                throw ParserFailure("ERROR: Duplicate LABELS");
            }
            this->LabelTable[value.substr(0, value.size()-1)] = label_position;
            currentIndex++;
        }
        if (currentIndex == lines[lineIndex].size()){
            continue;
        }
        else{
            label_position = label_position + 4;
            // checking whether there are LABELS after the first non label.
            for (int afterLabels = currentIndex; afterLabels < lines[lineIndex].size(); afterLabels++){
                if(lines[lineIndex][currentIndex].getKind() == Token::Kind::LABEL){
                    throw ParserFailure("ERROR: LABEL after non LABEL Token");
                }
            }
        }

    }
}
