//
// Created by User on 10/9/2020.
//

#ifndef CS241_ASM_H
#define CS241_ASM_H


#include <vector>
#include <string>
#include "scanner.h"
#include <map>

class Parser {
std::vector<std::string> validIDs = {"add", "sub", "mult",
                                     "multu", "div", "divu",
                                     "mfhi", "mflo", "lis",
                                     "lw", "sw", "slt",
                                     "sltu", "beq", "bne",
                                     "jr", "jalr"};
std::map<std::string, int> IDPlacement = {
        {"add", 0},
        {"sub", 0},
        {"mult", 0},
        {"multu", 0},
        {"div", 0},
        {"divu", 0},
        {"mfhi", 0},
        {"mfhlo", 0},
        {"lis", 0},
        {"lw",26},
        {"sw", 26},
        {"slt", 0},
        {"sltu", 0},
        {"beq", 26},
        {"bne",  26},
        {"jr", 0},
        {"jalr", 0}
};

std::map<std::string, int> IDValue = {
        {"add", 32},
        {"sub", 34},
        {"mult", 24},
        {"multu", 25},
        {"div", 26},
        {"divu", 27},
        {"mfhi", 16},
        {"mflo", 18},
        {"lis", 20},
        {"lw", 35},
        {"sw", 43},
        {"slt", std::stoi("101010", 0, 2)},
        {"sltu", std::stoi("101011", 0, 2)},
        {"beq", std::stoi("100", 0, 2)},
        {"bne", std::stoi("101", 0, 2)},
        {"jr", 8},
        {"jalr", 9}
};

std::map<std::string, int> LabelTable;

int type_d_s_t(std::string, std::string, std::string, std::string);
int type_s_t_i(std::string, std::string, std::string, int);
void printUnsignedInstruction(int);

    void checkInvalidOpcode(Token);
static int processInteger(Token, bool);
int processImmediate(Token, int, bool, bool);
public:
    void doLabels(std::vector<std::vector<Token>>&);
    int getLineCode(std::vector<Token>, int);

    std::string removeDollar(const std::string &basicString);

    void showTable();
};

class ParserFailure {
    std::string message;

public:
    ParserFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

void parsing_semantic_analysis_synthesis(std::vector<std::vector<Token>>&);

#endif //CS241_SCANNER_H
