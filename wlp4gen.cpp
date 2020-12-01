//
// Created by User on 10/22/2020.
//
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>

// helper method to merge two maps
std::map<std::string, std::string> concatenate(const std::map<std::string, std::string>& m1, const std::map<std::string, std::string>& m2){
    std::map<std::string, std::string> m3;
    for (auto & it : m1){
        m3[it.first] = it.second;
    }

    for (auto & it : m2){
        if(m3.count(it.first) != 0){
            throw "ERROR: two things declared with the same name";
        }
        else{
            m3[it.first] = it.second;
        }
    }
    return m3;
}

// helper method to print a map
void print(const std::map<std::string, std::string>& map){
    for (auto & it: map){
        std::cerr << it.first << " " << it.second << std::endl;
    }
}

std::set <std::string>  tokenTerminals {"BOF", "BECOMES", "COMMA", "ELSE", "EOF", "EQ", "GE", "GT", "ID", "IF", "INT", "LBRACE", "LE", "LPAREN", "LT", "MINUS", "NE", "NUM", "PCT", "PLUS", "PRINTLN", "RBRACE", "RETURN", "RPAREN", "SEMI", "SLASH", "STAR", "WAIN", "WHILE", "AMP", "LBRACK", "RBRACK", "NEW", "DELETE", "NULL"};

class ParseTree {
public:
    // There are 2 options here, either a parse tree stores a derivation rule, like expr -> expr PLUS expr, in this case the LHS would be expr,
    // and the RHS would be expr PLUS expr the other option is to store a token terminal and its LEXEMME such as INT int, in this case INT
    // is the LHS, and int is the RHS.
    std::string LHS;
    std::string RHS;
    // if you take the string LHS + RHS, and divide into a vector this is what tokens are
    std::vector<std::string> tokens;
    // if the parse tree stores a derivation rule, there are children for each token of the RHS, in case the parse tree is a leaf,
    // that is a terminal token with its LEXEMME then there are no children
    std::vector<ParseTree*> children;
    // stores children.size()
    int numberOfExpectedChildren{};
    // stores the parent of the parse tree, in case there is no parent then it is a nullptr
    ParseTree* parent{};

    // tables
    // in case this parse tree is either a procedure or wain, then variableTable stores all the variables that are available in the procedure,
    // that includes the parameters and the declared variables, where the keys are the ids and values are their types. In case the parse tree
    // is not the root of a procedure or wain, it stores all variables that are declared inside of thie parse tree.
    std::map <std::string, std::string> variableTable;
    // in case this parse tree is either a procedure or wain, then declaredSignatures stores all the signatures that have been declared until
    // this point in the program, where the keys are the ids of the procedures and the values are their signatures. In case the parse tree
    // is not the root of a procedure or wain, this stores an empty map.
    std::map <std::string, std::vector<std::string>> declaredSignatures;
    // in case this parse tree is the root of a procedure or wain, procedureName stores the name of the procedure, otherwise it stores
    // an empty string
    std::string procedureName;

    // prints the parse tree in pre order format.
    void preOrderPrint();
    // this method should only be used when the parse tree is the root of a procedure or wain,
    // if that is the case then it returns the signature of the procedure.
    std::vector<std::string> signatureExtractor();
    // creates all variable tables
    void variableTablesCreator();
    // name is self explanatory
    void checkingVariablesAndProceduresWithoutDeclaration(const std::map<std::string, std::string>&, const  std::map <std::string, std::vector<std::string>>&);
    // creates all declaredSignatures
    void procedureTablesCreator(std::map <std::string, std::vector<std::string>>);
    // checks if the string is well typed, that is follow the semantic rules of WLP4
    // in case it do so, it returns a string without throwing an error, the string in
    // is empty if the parse tree has no "type", and if the parse tree is the root of
    // something like an expr, then it returns the type of the expr.
    std::string well_typed(std::map <std::string, std::string>&, std::map <std::string, std::vector<std::string>>&);
    // this will store the output of well_typed.
    std::string type;
    std::string programGenerator(std::map<std::string, std::pair<std::string, int>>&, int&);
    explicit ParseTree(const std::string& s);
    ~ParseTree();
};

ParseTree::~ParseTree(){
    for (auto & child: children){
        delete child;
    }
}

ParseTree::ParseTree(const std::string& s){
    std::stringstream ss(s);
    std::string a;
    while(ss >> a){
        tokens.push_back(a);
    }
    LHS = tokens[0];
    RHS = "";
    for (int i = 1; i < tokens.size(); i++){
        RHS += tokens[i];
        if (i != tokens.size() - 1){
            RHS += " ";
        }
    }
}

void ParseTree::preOrderPrint(){
    std::cout << this->LHS << " " << this->RHS << " " << this->children.size() << std::endl;
    for (auto & child: this->children){
        child->preOrderPrint();
    }
}

void ParseTree::variableTablesCreator(){
    std::map<std::string, std::string> map;
    if (this->LHS == "main") {
        (this->children[3])->variableTablesCreator();
        (this->children[5])->variableTablesCreator();
        (this->children[8])->variableTablesCreator();
        map = concatenate(this->children[3]->variableTable, this->children[5]->variableTable);
        map = concatenate(map, this->children[8]->variableTable);
    }
    else if (this->LHS == "procedures"){
        (this->children[0])->variableTablesCreator();
        if (this->RHS != "main") {
            (this->children[1])->variableTablesCreator();
        }
    }
    else if (this->LHS == "procedure"){
        (this->children[3])->variableTablesCreator();
        (this->children[6])->variableTablesCreator();
        map = concatenate(this->children[3]->variableTable, this->children[6]->variableTable);
    }
    else if (this->LHS == "dcls"){
        if (this->RHS.empty()){
            return;
        }
        else{
            (this->children[0])->variableTablesCreator();
            (this->children[1])->variableTablesCreator();
            map = concatenate(this->children[0]->variableTable, this->children[1]->variableTable);
            int helper = this->children[1]->children[0]->tokens.size();
            bool isInt = true;
            if (helper == 3){isInt = false;}
            // this to check an error such as int x = NULL or int* x = 2;
            if (isInt and this->tokens[4] == "NULL"){
                throw "ERROR: variable assigned to have value different than its";
            }
            if (!isInt and this->tokens[4] == "NUM"){
                throw "ERROR: variable assigned to have value different than its";
            }
        }
    }
    else if (this->LHS == "dcl"){
        std::string ID = this->children[1]->RHS;
        std::string type = this->children[0]->RHS;
        if (type == "INT STAR"){
            type = "int*";
        }
        else{
            type = "int";
        }
        map[ID] = type;
    }
    else if (this->LHS == "params"){
        if (this->RHS.empty()){
            return;
        }
        else{
            this->children[0]->variableTablesCreator();
            map = this->children[0]->variableTable;
        }
    }
    else if (this->LHS == "paramlist"){
        this->children[0]->variableTablesCreator();
        map = this->children[0]->variableTable;
        if (this->tokens.size() == 2){
        }
        else{
            (this->children[2])->variableTablesCreator();
            map = concatenate(map, this->children[2]->variableTable);
        }
    }
    this->variableTable = map;
}

// this method should be used if the p is a pointer to a parse tree that
// has as its root a dcl, in this case it returns the type of the dcl.
std::string typeGetterFromdcl(const ParseTree *p){
    if (p->children[0]->RHS == "INT STAR"){
        return "int*";
    }
    else{
        return "int";
    }
}

std::vector<std::string> ParseTree::signatureExtractor() {
    std::vector<std::string> v;
    if (this->LHS == "main") {
        v.push_back(typeGetterFromdcl(this->children[3]));
        v.push_back(typeGetterFromdcl(this->children[5]));
        return v;
    }
    else{
        // we are now in a tree with the root as procedure
        ParseTree* currentParseTree = this->children[3];
        // we are not in a the tree with param root
        if (currentParseTree->RHS.empty()){
            return v;
        }
        else{
            currentParseTree = currentParseTree->children[0];
            // now we are in a tree with paramlist as the root
            while(true){
                // keep traversing through the the parameters and keep adding their types
                // to the vector v
                v.push_back(typeGetterFromdcl(currentParseTree->children[0]));
                if (currentParseTree->children.size() == 1){
                    break;
                }
                else{
                    currentParseTree = currentParseTree->children[2];
                }
            }
            return v;
        }
    }
}

void ParseTree::procedureTablesCreator( std::map <std::string, std::vector<std::string>> seenSignatures){
    if (this->RHS == "main"){
        this->children[0]->procedureName = "wain";
        this->children[0]->declaredSignatures = seenSignatures;
    }
    else{
        std::string procedureName2 = this->children[0]->children[1]->RHS;
        if (seenSignatures.count(procedureName2) != 0 or procedureName2 == "wain"){
            throw "ERROR: Procedure Declared Twice";
        }
        this->children[0]->procedureName = procedureName2;
        seenSignatures[procedureName2] = this->children[0]->signatureExtractor();
        this->children[0]->declaredSignatures = seenSignatures;
        this->children[1]->procedureTablesCreator(seenSignatures);
    }
}

void ParseTree::checkingVariablesAndProceduresWithoutDeclaration(const std::map<std::string, std::string>& tableVariable, const std::map <std::string, std::vector<std::string>>& tableProcedure){
    if (this->LHS == "procedures"){
        this->children[0]->checkingVariablesAndProceduresWithoutDeclaration(this->children[0]->variableTable, this->children[0]->declaredSignatures);
        if (!(this->RHS == "main")){
            this->children[1]->checkingVariablesAndProceduresWithoutDeclaration(tableVariable, tableProcedure);
        }
    }
    else if (this->LHS == "factor" and this->RHS == "ID") {
        if (tableVariable.count(this->children[0]->RHS) == 0) {
            throw "ERROR: variable not declared";
        }
    }
    else if (this->LHS == "factor" and (this->RHS == "ID LPAREN RPAREN" or this->RHS == "ID LPAREN arglist RPAREN")){
        if (tableVariable.count(this->children[0]->RHS) != 0 or  tableProcedure.count(this->children[0]->RHS) == 0){
            throw "ERROR: procedure not declared or has been replace by a variable";
        }
    }
    else if (this->LHS == "lvalue" and this->RHS == "ID"){
        if (tableVariable.count(this->children[0]->RHS) == 0){
            throw "ERROR: variable not declared";
        }
    }
    else{
        for (auto & child: this->children){
            child->checkingVariablesAndProceduresWithoutDeclaration(tableVariable, tableProcedure);
        }
    }
}

// helper method to check if the signature of a method is indeed correct
// this should be used with the following arguments, p is a pointer that
// points to a parse tree that has as its root the derivation rule of an
// arglist, the tableVariable stores all variables that are defined in this
// scope, and tableSignatures are all signatures that are available in this
// scope, and procedureName is the name of the procedure that called this
// arguments
void signatureCheck(ParseTree* p, std::map <std::string, std::string>& tableVariable, std::map <std::string, std::vector<std::string>>& tableSignatures, std::string procedureName){
    ParseTree * currentParseTree = p;
    std::vector<std::string> thisProcedureSignature = tableSignatures[procedureName];
    std::string type;
    for (int parameterCursor= 0; parameterCursor < thisProcedureSignature.size(); parameterCursor++){
        std::string expectedType = thisProcedureSignature[parameterCursor];
        std::string givenType = (currentParseTree->children[0])->well_typed(tableVariable, tableSignatures);
        if (expectedType != givenType){
            throw "ERROR: mismatch between type of expected argument and given argument";
        }
        if (currentParseTree->children.size() == 1){
            if (parameterCursor == thisProcedureSignature.size() - 1){
                return;
            }
            else{
                throw "ERROR: two few arguments were given";
            }
        }
        else{
            currentParseTree = currentParseTree->children[2];
        }
    }
    throw "ERROR: too many arguments were given";
}

std::string ParseTree::well_typed(std::map <std::string, std::string>& tableVariable, std::map <std::string, std::vector<std::string>>& tableSignatures) {
    if (this->LHS == "main"){
        if (typeGetterFromdcl(this->children[5]) != "int"){
            throw "ERROR: wain needs to have this int as the second argument";
        }
        std::map <std::string, std::string> newTableVariable = this->variableTable;
        std::map <std::string, std::vector<std::string>> newTableSignatures = this->declaredSignatures;
        (this->children[9])->well_typed(newTableVariable, newTableSignatures);
        std::string returnedValue = (this->children[11])->well_typed(newTableVariable, newTableSignatures);
        if (returnedValue != "int"){
            throw "ERROR: wain returns expr that does not have type int";
        }
    }
    else if (this->LHS == "procedure"){
        std::map <std::string, std::string> newTableVariable = this->variableTable;
        std::map <std::string, std::vector<std::string>> newTableSignatures = this->declaredSignatures;
        (this->children[7])->well_typed(newTableVariable, newTableSignatures);
        std::string returnedValue = (this->children[9])->well_typed(newTableVariable, newTableSignatures);
        if (returnedValue != "int"){
            throw "ERROR: procedure has to return int";
        }
    }
    else if(this->LHS == "statement" and this->tokens[1] == "lvalue"){
        if ((this->children[0])->well_typed(tableVariable, tableSignatures) != (this->children[2])->well_typed(tableVariable, tableSignatures)){
            throw "ERROR: lvalue has different type than its assigned value";
        }
    }
    else if(this->LHS == "statement" and this->tokens[1] == "PRINTLN"){
        if ((this->children[2])->well_typed(tableVariable, tableSignatures) != "int"){
            throw "ERROR: PRINTLN does not receive integer";
        }
    }
    else if(this->LHS == "statement" and this->tokens[1] == "DELETE"){
        if ((this->children[3])->well_typed(tableVariable, tableSignatures) != "int*"){
            throw "ERROR: DELETE does not receive pointer";
        }
    }
    else if (this->LHS == "test"){
        if ((this->children[0])->well_typed(tableVariable, tableSignatures) != (this->children[2]->well_typed(tableVariable, tableSignatures))){
            throw "ERROR: comparison of elements of different types";
        }
    }
    else if (this->LHS == "expr"){
        if (this->children.size() == 1){
            type = (this->children[0])->well_typed(tableVariable, tableSignatures);
            return type;
        }
        else{
            std::string firstExpressionType = (this->children[0])->well_typed(tableVariable, tableSignatures);
            std::string secondExpressionType = (this->children[2])->well_typed(tableVariable, tableSignatures);
            if (firstExpressionType == "int" and secondExpressionType == "int"){
                type = "int";
                return type;
            }
            else if(firstExpressionType == "int*" and secondExpressionType == "int"){
                type = "int*";
                return type;
            }
            else{
                if (this->tokens[2] == "PLUS"){
                    if (firstExpressionType == "int" and secondExpressionType == "int*"){
                        type = "int*";
                        return type;
                    }
                    else{
                        throw "ERROR: +,- expression with wrong types";
                    }
                }
                else{
                    if (firstExpressionType == "int*" and secondExpressionType == "int*"){
                        type = "int";
                        return type;
                    }
                    else{
                        throw "ERROR: +,- expression with wrong types";
                    }
                }
            }
        }
    }
    else if (this->LHS == "term"){
        if (this->tokens[1] == "factor"){
            type = (this->children[0])->well_typed(tableVariable, tableSignatures);
            return type;
        }
        else{
            if ((this->children[0])->well_typed(tableVariable, tableSignatures) == "int" and  (this->children[2])->well_typed(tableVariable, tableSignatures) == "int"){
                type = "int";
                return type;
            }
            else{
                throw "ERROR: *,/,% expression with wrong types";
            }
        }
    }
    else if (this->LHS == "factor"){
        if (this->RHS == "ID"){
            type = (this->children[0])->well_typed(tableVariable, tableSignatures);
            return type;
        }
        if (this->RHS == "NUM"){
            type = "int";
            return type;
        }
        if (this->RHS == "NULL"){
            type = "int*";
            return type;
        }
        if (this->RHS == "LPAREN expr RPAREN"){
            type = (this->children[1])->well_typed(tableVariable, tableSignatures);
            return type;
        }
        if (this->RHS == "AMP lvalue"){
            std::string ans = (this->children[1])->well_typed(tableVariable, tableSignatures);
            if (ans == "int"){
                type = "int*";
                return type;
            }
            else{
                throw "ERROR: wrong type in ampersand";
            }
        }
        if (this->RHS == "STAR factor"){
            std::string ans = (this->children[1])->well_typed(tableVariable, tableSignatures);
            if (ans == "int*"){
                type = "int";
                return type;
            }
            else{
                throw "ERROR: wrong type in dereferecing";
            }
        }
        if (this->RHS == "NEW INT LBRACK expr RBRACK"){
            std::string ans = (this->children[3])->well_typed(tableVariable, tableSignatures);
            if (ans == "int"){
                type = "int*";
                return type;
            }
            else{
                throw "ERROR: wrong type in new";
            }
        }
        if (this->RHS == "ID LPAREN RPAREN"){
            std::string id = this->children[0]->RHS;
            if ((tableSignatures[id]).empty()){
                type = "int";
                return type;
            }
            else{
                throw "ERROR: function call should have at least one parameter";
            }
        }
        if (this->RHS == "ID LPAREN arglist RPAREN"){
            signatureCheck(this->children[2], tableVariable, tableSignatures, this->children[0]->RHS);
            type = "int";
            return type;
        }
    }
    else if (this->LHS == "lvalue"){
        if (this->RHS == "ID"){
            type = (this->children[0])->well_typed(tableVariable, tableSignatures);
            return type;
        }
        else if (this->RHS == "STAR factor"){
            std::string ans = (this->children[1])->well_typed(tableVariable, tableSignatures);
            if (ans == "int*"){
                type = "int";
                return type;
            }
            else{
                throw "ERROR: wrong type in dereferecing";
            }
        }
        else{
            type = (this->children[1])->well_typed(tableVariable, tableSignatures);
            return type;
        }
    }
    else if (this->LHS == "ID"){
        type = tableVariable[this->RHS];
        return type;
    }
    else{
        for(auto &child: this->children){
            child->well_typed(tableVariable, tableSignatures);
        }
    }
    return "";
}

std::string push(int i){
    return ("sw $" + std::to_string(i) + ", 0($30)\nsub $30, $30, $4\n");
}
std::string pop(int i){
    return ("add $30, $30, $4\nlw $" + std::to_string(i) + ", 0($30)\n");
}

std::string ParseTree::programGenerator(std::map<std::string, std::pair<std::string, int>> & offsetTable,  int & usedLabels){
    std::string code1;
    std::string code2;
    std::string code3;
    std::string code4;
    std::string code5;
    if (LHS == "start"){
        code1 += ".import print\n";
        code1 += "lis $4\n";
        code1 += ".word  4\n";
        code1 += "lis $10\n";
        code1 += ".word print\n";
        code1 += "lis $11\n";
        code1 += ".word 1\n";
        code1 += "sub $30, $30, $4\n";
        code1 += "add $29, $30, $0\n";
        code1 += push(1);
        code1 += push(2);
        code1 += (children[1])->programGenerator(offsetTable, usedLabels);
        code1 += "jr $31\n";
        return  code1;
    }
    else if (LHS == "procedures"){
        if (RHS == "main"){
            return (children[0])->programGenerator(offsetTable, usedLabels);
        }
        else{
            // TODO: finish this
        }
    }
    else if (LHS == "main"){
        std::pair<std::string, int> p  ("", 2);
        offsetTable["numberOfSavedOffsets"] = p;
        std::pair<std::string, int> q (children[3]->children[0]->RHS, 0);
        offsetTable[children[3]->children[1]->RHS] = q;
        std::pair<std::string, int> r (children[5]->children[1]->RHS, 4);
        offsetTable[children[5]->children[1]->RHS] = r;
        code1 += (children[8])->programGenerator(offsetTable, usedLabels);
        code1 += (children[9])->programGenerator(offsetTable, usedLabels);
        code1 += (children[11])->programGenerator(offsetTable, usedLabels);
        return code1;
    }
    else if (LHS == "dcls"){
        std::string type1;
        if (RHS == ""){
            return "";
        }
        else {
            code1 += (this->children[0])->programGenerator(offsetTable, usedLabels);
            if (this->tokens[4] == "NULL"){
                type1= "int*";
                code1 += "add $3, $0, $11\n";
            }
            else{
                type1 = "int";
                std::string num = this->children[3]->RHS;
                code1 += "lis $3\n.word " + num +"\n";
            }
            code1 += push(3);

            int inserted = offsetTable["numberOfSavedOffsets"].second;
            std::pair<std::string, int> p  ("", inserted+1);
            offsetTable["numberOfSavedOffsets"] = p;
            std::pair<std::string, int> q (type1, 4*inserted);
            offsetTable[this->children[1]->children[1]->RHS] = q;
            return code1;
        }
    }
    else if (LHS == "dcl"){
        code1 = (this->children[0])->programGenerator(offsetTable, usedLabels);
        return code1;
    }
    else if (LHS == "type"){
        if (RHS == "int"){
        }
        else {
        }
    }
    else if (LHS == "statements"){
        if (RHS == ""){
            return "";
        }
        else {
            code1 += (this->children[0])->programGenerator(offsetTable, usedLabels);
            code1 += (this->children[1])->programGenerator(offsetTable, usedLabels);
            return code1;
        }
    }
    else if (LHS == "statement"){
        if (RHS == "PRINTLN LPAREN expr RPAREN SEMI") {
            code1 += push(1);
            code1 += (this->children[2])->programGenerator(offsetTable, usedLabels);
            code1 += "add $1, $3, $0\n";
            code1 += push(31);
            code1 += "lis $5\n";
            code1 += ".word print\n";
            code1 += "jalr $5\n";
            code1 += pop(31);
            code1 += pop(1);
            return code1;
        }
        if (RHS == "lvalue BECOMES expr SEMI"){
            code1 += (this->children[0])->programGenerator(offsetTable, usedLabels);
            code1 += push(3);
            code1 += (this->children[2])->programGenerator(offsetTable, usedLabels);
            code1 += pop(5);
            code1 += "sw $3, 0($5)\n";
            return code1;
        }
        else if (RHS == "IF LPAREN test RPAREN LBRACE statements RBRACE ELSE LBRACE statements RBRACE"){
            code1 += (this->children[2])->programGenerator(offsetTable, usedLabels);
            int temp = usedLabels;
            usedLabels++;
            code1 += "beq $3, $0, else" + std::to_string(temp) + "\n";
            code1 += (this->children[5])->programGenerator(offsetTable, usedLabels);
            code1 += "beq $0, $0, endif" + std::to_string(temp) + "\n";
            code1 += "else" + std::to_string(temp) + ":\n";
            code1 += (this->children[9])->programGenerator(offsetTable, usedLabels);
            code1 += "endif" + std::to_string(temp) + ":\n";
            return code1;
        }
        else if (RHS == "WHILE LPAREN test RPAREN LBRACE statements RBRACE"){
            code1 += "loop" + std::to_string(usedLabels) + ":\n";
            int temp = usedLabels;
            usedLabels ++;
            code1 += (this->children[2])->programGenerator(offsetTable, usedLabels);
            code1 += "beq $3, $0 , endWhileLoop" + std::to_string(temp) + "\n";
            code1 += (this->children[5])->programGenerator(offsetTable, usedLabels);
            code1 += "beq $0, $0, loop"+ std::to_string(temp) +"\n";
            code1 += "endWhileLoop" + std::to_string(temp) + ":\n";
            return code1;
        }
        else {
            //TODO: finish this
        }
    }
    if (LHS == "test"){
        std::string type1 = (this->children[0])->type;
        code1 += (this->children[0])->programGenerator(offsetTable, usedLabels);
        code1 += push(3);
        code1 += (this->children[2])->programGenerator(offsetTable, usedLabels);
        code1+= pop(5);
        if (type1 == "int"){
            code1 += "slt $6, $3, $5\n";
            code1 += "slt $7, $5, $3\n";
        }
        else{
            code1 += "sltu $6, $3, $5\n";
            code1 += "sltu $7, $5, $3\n";
        }
        if (this->tokens[2] == "EQ"){
            code1 += "add $3, $6, $7\n";
            code1 += "sub $3, $11, $3\n";
        }
        else if (this->tokens[2] == "NE"){
            code1 += "add $3, $6, $7\n";
        }
        else if (this->tokens[2] == "LT"){
            code1 += "add $3, $0, $7\n";
        }
        else if (this->tokens[2] == "LE"){
            code1 += "sub $3, $11, $6\n";
        }
        else if (this->tokens[2] == "GT"){
            code1 += "add $3, $0, $6\n";
        }
        else if (this->tokens[2] == "GE"){
            code1 += "sub $3, $11, $7\n";
        }
        return code1;
    }
    else if (LHS == "lvalue"){
        if (RHS == "ID"){
            std::string id = (this->children[0]->RHS);
            int offset = offsetTable[id].second;
            code1 += "lis $3\n";
            code1 += ".word " + std::to_string(offset) + "\n";
            code1 += "sub $3, $29, $3\n";
            return code1;
        }
        else if (RHS == "LPAREN lvalue RPAREN "){
            return (this->children[1])->programGenerator(offsetTable, usedLabels);
        }
        else{
            code1 += (this->children[1])->programGenerator(offsetTable, usedLabels);
            return code1;
        }
    }
    else if (LHS == "expr"){
        if (RHS == "term"){
            return (children[0])->programGenerator(offsetTable, usedLabels);
        }
        else{
            if (this->children[0]->type == "int" and this->children[2]->type == "int"){
                code1 += (this->children[0])->programGenerator(offsetTable, usedLabels);
                code1 += push(3);
                code1 += (this->children[2])->programGenerator(offsetTable, usedLabels);
                code1 += pop(5);
                if (this->tokens[2] == "PLUS"){
                    code1+= "add $3, $5, $3\n";
                }
                else{
                    code1+= "sub $3, $5, $3\n";
                }
                return code1;
            }
            //TODO: finish this
        }
    }
    else if (LHS == "term"){
        if (RHS == "factor"){
            return (children[0])->programGenerator(offsetTable, usedLabels);
        }
        else{
            code1 += (this->children[0])->programGenerator(offsetTable, usedLabels);
            code1 += push(3);
            code1 += (this->children[2])->programGenerator(offsetTable, usedLabels);
            code1 += pop(5);
            if (this->tokens[2] == "STAR"){
                code1+= "mult $5, $3\n";
                code1+= "mflo $3\n";
            }
            else if (this->tokens[2] == "SLASH"){
                code1+= "div $5, $3\n";
                code1+= "mflo $3\n";
            }
            else{
                code1+= "div $5, $3\n";
                code1+= "mfhi $3\n";
            }
            return code1;
        }
    }
    else if (LHS == "factor"){
        if (RHS == "ID"){
            return (children[0])->programGenerator(offsetTable, usedLabels);
        }
        else if (RHS == "LPAREN expr RPAREN"){
            return (children[1])->programGenerator(offsetTable, usedLabels);
        }
        else if (RHS == "NUM"){
            std::string integer = this->children[0]->RHS;
            code1 += "lis $3\n";
            code1 += (".word " + integer + "\n");
            return code1;
        }
        else if (RHS == "NULL"){
            code1 += "lis $3\n";
            code1 += ".word 1\n";
            return code1;
        }
        else{
            //TODO: finish this
        }
    }
    else if (LHS == "ID"){
        std::string id = this->RHS;
        std::string idOffset = std::to_string(- offsetTable[id].second);
        code1 += ("lw  $3, " + idOffset + "($29)\n");
        return code1;
    }
    else {
        return "";
    }
}

// it receives a preOrderPrintedTree where the strings are the lines in preorder,
// and the int is the amount of children each node will have.
ParseTree* treeCreator2(std::vector<std::pair<std::string, int>> preOrderPrintedTree){
    int cursor = 0;
    ParseTree* parentTree = nullptr;
    ParseTree* currentTree = nullptr;
    while(cursor != preOrderPrintedTree.size()) {
        if (parentTree and parentTree->children.size() == parentTree->numberOfExpectedChildren){
            parentTree = parentTree->parent;
            continue;
        }
        currentTree = new ParseTree(preOrderPrintedTree[cursor].first);
        currentTree->numberOfExpectedChildren = preOrderPrintedTree[cursor].second;
        currentTree->parent = parentTree;
        if (parentTree) {
            parentTree->children.push_back(currentTree);
        }
        parentTree = currentTree;
        cursor++;
    }
    while(parentTree->parent){
        parentTree = parentTree->parent;
    }
    return parentTree;
}

// helper function
std::vector<std::pair<std::string, int>> childrenSizeAdder(const std::vector<std::string>& preOrderPrintedTree){
    std::vector<std::pair<std::string, int>> preOrderPrintedTreeWithChildrenSize;
    for(auto & cursor : preOrderPrintedTree){
        std::stringstream ss(cursor);
        std::string non_terminals;
        ss >> non_terminals;
        if (tokenTerminals.count(non_terminals) != 0){
            std::pair<std::string, int> p(cursor, 0);
            preOrderPrintedTreeWithChildrenSize.push_back(p);
            continue;
        }
        int childrenSize = 0;
        while(ss >> non_terminals){
            childrenSize++;
        }
        std::pair<std::string, int> p(cursor, childrenSize);
        preOrderPrintedTreeWithChildrenSize.push_back(p);
    }
    return preOrderPrintedTreeWithChildrenSize;
}

int main() {
    bool debug = false;
    std::ifstream file;
    if (debug){
        file.open("");
    }
    std::vector<std::string> preOrderPrintedTree;
    std::vector<std::pair<std::string, int>> preOrderPrintedTreeWithChildrenSize;
    std::string line;
    if (!debug) {
        while (getline(std::cin, line)) {
            preOrderPrintedTree.push_back(line);
        }
    }
    if (debug){
        while (getline(file, line)) {
            preOrderPrintedTree.push_back(line);
        }
        file.close();
    }
    if (preOrderPrintedTree.empty()) {
        return 0;
    }
    ParseTree* parseTree = treeCreator2(childrenSizeAdder(preOrderPrintedTree));
    try{
    int question = 5;
    if (question == 1) {
        /*
        (parseTree->children[1]->children[0])->variableTablesCreator();
        (parseTree->children[1]->children[0])->checkingVariablesWithoutDeclaration((parseTree->children[1]->children[0])->variableTable);
        std::map<std::string, std::string> map1 = parseTree->children[1]->children[0]->children[3]->variableTable;
        std::map<std::string, std::string> map2 = parseTree->children[1]->children[0]->children[5]->variableTable;
        std::map<std::string, std::string> map3 = parseTree->children[1]->children[0]->variableTable;
        std::cerr << "wain:";
        for (auto &it: map1) {
            std::cerr << " " << it.second;
        }
        for (auto &it: map2) {
            std::cerr << " " << it.second;
        }
        std::cerr << std::endl;
        print(map3);
         */
    }
    if (question == 2) {
        //creating the variable table for each procedure
        ParseTree* currentParseTree = parseTree->children[1];
        currentParseTree->variableTablesCreator();
        std::map <std::string, std::vector<std::string>> emptyMap;
        currentParseTree->procedureTablesCreator(emptyMap);
        std::map<std::string, std::string> emptyMap1;
        std::map <std::string, std::vector<std::string>> emptyMap2;
        currentParseTree->checkingVariablesAndProceduresWithoutDeclaration(emptyMap1, emptyMap2);
        while (true){
            std::cerr << currentParseTree->children[0]->procedureName << ":";
            std::vector<std::string> v = currentParseTree->children[0]->signatureExtractor();
            for (const std::string& it : v){
                std::cerr << " " << it;
            }
            std::cerr << std::endl;
            if (currentParseTree->RHS == "main"){
                print(currentParseTree->children[0]->variableTable);
                break;
            }
            else{
                currentParseTree = currentParseTree->children[1];
            }
        }
    }
    if (question == 3) {
        //creating the variable table for each procedure
        ParseTree* currentParseTree = parseTree->children[1];
        currentParseTree->variableTablesCreator();
        std::map <std::string, std::vector<std::string>> emptyMap;
        currentParseTree->procedureTablesCreator(emptyMap);
        std::map<std::string, std::string> emptyMap1;
        std::map <std::string, std::vector<std::string>> emptyMap2;
        currentParseTree->checkingVariablesAndProceduresWithoutDeclaration(emptyMap1, emptyMap2);
        while (true){
            std::cerr << currentParseTree->children[0]->procedureName << ":";
            std::vector<std::string> v = currentParseTree->children[0]->signatureExtractor();
            for (const std::string& it : v){
                std::cerr << " " << it;
            }
            std::cerr << std::endl;
            print(currentParseTree->children[0]->variableTable);
            if (currentParseTree->RHS == "main"){
                break;
            }
            else{
                currentParseTree = currentParseTree->children[1];
            }
        }
    }
        if (question == 4) {
            /*
            //creating the variable table for each procedure
            ParseTree *currentParseTree = parseTree->children[1];
            currentParseTree->variableTablesCreator();
            std::map<std::string, std::vector<std::string>> emptyMap;
            currentParseTree->procedureTablesCreator(emptyMap);
            std::map<std::string, std::string> emptyMap1;
            std::map<std::string, std::vector<std::string>> emptyMap2;
            currentParseTree->checkingVariablesAndProceduresWithoutDeclaration(emptyMap1, emptyMap2);
            std::map<std::string, std::string> emptyMap3;
            std::map<std::string, std::vector<std::string>> emptyMap4;
            currentParseTree->well_typed(emptyMap3, emptyMap4);
             */
        }
        if (question == 5){
            //creating the variable table for each procedure
            ParseTree *currentParseTree = parseTree->children[1];
            currentParseTree->variableTablesCreator();
            std::map<std::string, std::vector<std::string>> emptyMap;
            currentParseTree->procedureTablesCreator(emptyMap);
            std::map<std::string, std::string> emptyMap1;
            std::map<std::string, std::vector<std::string>> emptyMap2;
            currentParseTree->checkingVariablesAndProceduresWithoutDeclaration(emptyMap1, emptyMap2);
            std::map<std::string, std::string> emptyMap3;
            std::map<std::string, std::vector<std::string>> emptyMap4;
            currentParseTree->well_typed(emptyMap3, emptyMap4);
            std::map <std::string, std::pair<std::string, int>> newEmptyMap;
            int value = 0;
            std::cout << parseTree->programGenerator(newEmptyMap, value);
        }
        // avoiding memory leaks
    delete  parseTree;
    }
    catch (const char* msg){
        // avoiding memory leaks
        delete parseTree;
        std::cerr << msg << std::endl;
    }
}
