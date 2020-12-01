//
// Created by User on 10/9/2020.
//

#include <iostream>
#include "MIPS_assembly.h"


int Parser::getLineCode(std::vector<Token> tokenList, int lineNumber){
    if(tokenList.empty()){
        return - 1;
    }
    // pass through all Labels from the beginning
    int currentIndex = 0;
    while(true){
        if(currentIndex >= tokenList.size()){
            return -1;
        }
        if(tokenList[currentIndex].getKind() != Token::Kind::LABEL){
            break;
        }
        currentIndex++;
    }

    // checking bad beginnings (after all labels)
    Token firstToken = tokenList[currentIndex];
    std::string first_register_value;
    std::string second_register_value;
    std::string third_register_value;
    int i_value;
    std::string currentLexeme = tokenList[currentIndex].getLexeme();
    switch (firstToken.getKind()){
        case Token::Kind::ID:
            checkInvalidOpcode(firstToken);
            if (currentIndex + 1 >= tokenList.size()){throw ParserFailure("ERROR: opcode needs at least one register");}
            if (tokenList[currentIndex + 1].getKind() != Token::Kind::REG){throw ParserFailure("ERROR: after ID need register");}
            first_register_value = removeDollar(tokenList[currentIndex + 1].getLexeme());
            if (currentLexeme == "jalr" or currentLexeme == "jr" or
                    currentLexeme == "mfhi" or currentLexeme == "mflo" or currentLexeme == "lis"){

                if (currentIndex + 2 != tokenList.size()){
                    throw ParserFailure("ERROR: expected end of line");
                }
                if (currentLexeme == "jalr" or currentLexeme == "jr") {
                    type_d_s_t(currentLexeme, "", first_register_value, "");
                }
                if (currentLexeme == "mfhi" or currentLexeme == "mflo" or
                        currentLexeme == "lis") {
                    return type_d_s_t(currentLexeme, first_register_value, "", "");
                }
            }
            else{
                if (currentIndex + 3 >= tokenList.size()){throw ParserFailure("ERROR: wasn't expecting end of file");}
                if (tokenList[currentIndex + 2].getKind() != Token::Kind::COMMA){throw ParserFailure("ERROR: expecting comma");}
                if (tokenList[currentIndex].getLexeme() == "lw" or tokenList[currentIndex].getLexeme() == "sw"){
                    if (currentIndex + 7 != tokenList.size()){throw ParserFailure("ERROR: wrong size of tokens list");}
                    i_value = processInteger(tokenList[currentIndex + 3], true);
                    if (tokenList[currentIndex + 4].getKind() != Token::Kind::LPAREN){throw ParserFailure("ERROR: expecting LPAREN");}
                    if (tokenList[currentIndex + 5].getKind() != Token::Kind::REG){throw ParserFailure("ERROR: expecting REG");}
                    second_register_value = removeDollar(tokenList[currentIndex + 5].getLexeme());
                    if (tokenList[currentIndex + 6].getKind() != Token::Kind::RPAREN){throw ParserFailure("ERROR: expecting RPAREN");}
                    return type_s_t_i(tokenList[currentIndex].getLexeme(), second_register_value, first_register_value, i_value);
                }
                if (tokenList[currentIndex + 3].getKind() != Token::Kind::REG){throw ParserFailure("ERROR: expecting REG");}
                second_register_value = removeDollar(tokenList[currentIndex + 3].getLexeme());
                if (tokenList[currentIndex].getLexeme() == "mult" or tokenList[currentIndex].getLexeme() == "multu" or
                    tokenList[currentIndex].getLexeme() == "div" or tokenList[currentIndex].getLexeme() == "divu") {

                    if (currentIndex + 4 != tokenList.size()){throw ParserFailure("ERROR: end of the line at the wrong place");}
                    return type_d_s_t(tokenList[currentIndex].getLexeme(), "", first_register_value, second_register_value);
                }
                if (tokenList[currentIndex].getLexeme() == "bne" or tokenList[currentIndex].getLexeme() == "beq") {

                    if (currentIndex + 6 != tokenList.size()){throw ParserFailure("ERROR: end of line at the wrong place");}
                    if (tokenList[currentIndex + 4].getKind() != Token::Kind::COMMA){throw ParserFailure("ERROR: expecting COMMA");}
                    i_value = processImmediate(tokenList[currentIndex + 5], lineNumber, true, true);
                    return type_s_t_i(tokenList[currentIndex].getLexeme(), first_register_value, second_register_value, i_value);
                }
                if (tokenList[currentIndex].getLexeme() == "add" or tokenList[currentIndex].getLexeme() == "sub" or
                        tokenList[currentIndex].getLexeme() == "slt" or tokenList[currentIndex].getLexeme() == "sltu") {
                    if (currentIndex + 6 != tokenList.size()){throw ParserFailure("ERROR: end of the line at the wrong place");}
                    if (tokenList[currentIndex + 4].getKind() != Token::Kind::COMMA){throw ParserFailure("ERROR: expecting COMMA");}
                    if (tokenList[currentIndex + 5].getKind() != Token::Kind::REG){throw ParserFailure("ERROR: expecting REG");}
                    third_register_value = removeDollar(tokenList[currentIndex + 5].getLexeme());
                    return type_d_s_t(tokenList[currentIndex].getLexeme(), first_register_value, second_register_value, third_register_value);
                }
            }
            break;

        case Token::Kind::WORD:
            if (currentIndex + 1 >= tokenList.size()){
                throw ParserFailure("ERROR: .word needs complement");
            }
            else{
                if (currentIndex + 2 != tokenList.size()){
                    throw ParserFailure("ERROR: expected end of line");
                }
                else{
                    printUnsignedInstruction(processImmediate(tokenList[currentIndex + 1], lineNumber, false, false));
                }
            }
            break;
        default:
            throw ParserFailure("ERROR: begin of line is not ID or WORD");
    }
    return 0;
    // you can't put anything after this.
};

void Parser::printUnsignedInstruction(int instr) {
    char unsigned c = instr >> 24;
    std::cout << c;
    c = instr >> 16;
    std::cout << c;
    c = instr >> 8;
    std::cout << c;
    c = instr;
    std::cout << c;
}

void Parser::doLabels(std::vector<std::vector<Token> > &tokenLines) {
    long label_position = 0;
    for (std::vector<Token> tokenLine: tokenLines){
        // pass through all Labels from the beginning
        int currentIndex = 0;
        while(true){
            if (currentIndex >= tokenLine.size()){break;}
            if(tokenLine[currentIndex].getKind() != Token::Kind::LABEL){break;}
            std::string currentLexemme = tokenLine[currentIndex].getLexeme();
            if (this->LabelTable.count(currentLexemme.substr(0, currentLexemme.size() - 1)) == 1){
                throw ParserFailure("ERROR: Duplicate LABELS");
            }
            this->LabelTable[currentLexemme.substr(0, currentLexemme.size() - 1)] = label_position;
            currentIndex++;
        }
        if (currentIndex == tokenLine.size()){
            continue;
        }
        else{
            label_position = label_position + 4;
            // checking whether there are LABELS after the first non label.
            for (int afterLabels = currentIndex; afterLabels < tokenLine.size(); afterLabels++){
                Token::Kind currentKind = tokenLine[currentIndex].getKind();
                std::string currentLexemme = tokenLine[currentIndex].getLexeme();
                if(currentKind == Token::Kind::REG){
                    int integer = std::stol(removeDollar(currentLexemme));
                    if (integer < 0 or integer > 31){
                        throw ParserFailure("ERROR: integer from register is out of bounds");
                    }
                }
                if(tokenLine[currentIndex].getKind() == Token::Kind::LABEL){
                    throw ParserFailure("ERROR: LABEL after non LABEL Token");
                }
            }
        }
    }
}

int Parser::type_d_s_t(std::string name, std::string d, std::string s, std::string t){
    int instr = 0;
    if (!d.empty()){
        instr = instr | (std::stoi(d) << 11);
    }
    if (!s.empty()){
        instr = instr | (std::stoi(s) << 21);
    }
    if (!t.empty()){
        instr = instr | (std::stoi(t) << 16);
    }
    instr = instr | (this->IDValue[name] << (this->IDPlacement[name]));
     printUnsignedInstruction(instr);
     return 0;
}

int Parser::type_s_t_i(std::string name, std::string s, std::string t, int i){
    int instr = 0;
    if (!s.empty()){
        instr = instr | (std::stoi(s) << 21);
    }
    if (!t.empty()){
        instr = instr | (std::stoi(t) << 16);
    }
    instr = instr | (i & ((1 << 16) -1));
    instr = instr | (this->IDValue[name] << (this->IDPlacement[name]));
    printUnsignedInstruction(instr);
    return 0;
}

std::string Parser::removeDollar(const std::string &s) {
    return s.substr(1, s.size() -1);
}

ParserFailure::ParserFailure(std::string message):
        message(std::move(message)) {}

const std::string &ParserFailure::what() const { return message; }

void parsing_semantic_analysis_synthesis(std::vector<std::vector<Token>>& t){
    Parser p;
    p.doLabels(t);
    int currentLine = 0;
    int isThereAnything;
    for (std::vector<Token> tokenLine: t){
        isThereAnything = p.getLineCode(tokenLine, currentLine);
        if (isThereAnything == 0) {
            currentLine = currentLine + 1;
        }
    }
    bool testingTable = false;
    if(testingTable){
        p.showTable();
    }
}

void Parser::showTable() {
    for (std::map<std::string,int>::iterator it = LabelTable.begin(); it != LabelTable.end(); ++it) {
        std::cerr << it->first << " " << it->second << std::endl;
    }
}

void Parser::checkInvalidOpcode(Token t){
    bool isIt = false;
    for (std::string goodOpcode: this->validIDs){
        if (t.getLexeme() == goodOpcode){
            isIt = true;
            break;
        }
    }
    if (!isIt){
        throw ParserFailure("ERROR: opcode does not exist");
    }
}

void linePrinter(std::vector<Token> tokenLine){
    for (auto &token : tokenLine) {
        std::cout << token << ' ';
    }
    std::cout << std::endl;
}

int Parser::processInteger(Token token, bool tight){
    int instr;
    long linger;
    bool didItComeFromINT;
    switch (token.getKind()){
        case Token::Kind::INT:
            didItComeFromINT = true;
            linger = std::stol(token.getLexeme());
            break;
        case Token::Kind::HEXINT:
            didItComeFromINT = false;
            linger = std::stol(token.getLexeme(), 0, 16);
            break;
        default:
            throw ParserFailure("ERROR: processed Integer and didn't receive INT or HEXINT");
    }
    if (tight){
        if (didItComeFromINT) {
            if (linger > 32767 or linger < -32768) {
                throw ParserFailure("ERROR: processed Integer is out of tight bound");
            } else {
                instr = linger;
                return instr;
            }
        } else{
            if (linger > 65535){
                throw ParserFailure("ERROR: processed Integer is out of tight bound");
            } else {
                instr = linger;
                return instr;
            }
        }
    }
    else{
        if (linger > 4294967295 or linger < -(1 << 31)){
            throw ParserFailure("ERROR: processed Integer is out of loose bound");
        }
        instr = linger;
        return instr;
    }
}


int Parser::processImmediate(Token token, int pos, bool offset, bool tight){
// the boolean is true when you are doing offsets, and it is false when you are simply replacing the value.
    int instr;
    int labelAddress;
    if(token.getKind() == Token::Kind::ID) {
        std::string lookup = token.getLexeme();
        if (LabelTable.count(lookup) == 0) {
            throw ParserFailure("ERROR: ID undefined");
        }
        labelAddress = LabelTable[lookup];
        if (offset){
            instr = labelAddress/4 - pos - 1;
        }
        else{
            instr = labelAddress;
        }
        return instr;
    }
    else{
        return processInteger(token, tight);
    }
}

int main() {
    std::string line;
    std::vector<std::vector<Token> > tokenLines;

    try {
        while (getline(std::cin, line)) {
            tokenLines.push_back(scan(line));
        }
    } catch (ScanningFailure &f) {
        std::cerr << f.what() << std::endl;

        return 1;
    }
    try {
        parsing_semantic_analysis_synthesis(tokenLines);
    } catch (ParserFailure &f){
        std::cerr << f.what() << std::endl;
        return 1;
    }

}
