//
// Created by User on 10/20/2020.
//


#include <sstream>
#include <utility>
#include <set>
#include <vector>
#include <map>
#include <iostream>

void myerror(int k){
    std::cerr << "ERROR at " + std::to_string(k) << std::endl;
}

std:: string wlp4_lr1 = "35\n"
                        "AMP\n"
                        "BECOMES\n"
                        "BOF\n"
                        "COMMA\n"
                        "DELETE\n"
                        "ELSE\n"
                        "EOF\n"
                        "EQ\n"
                        "GE\n"
                        "GT\n"
                        "ID\n"
                        "IF\n"
                        "INT\n"
                        "LBRACE\n"
                        "LBRACK\n"
                        "LE\n"
                        "LPAREN\n"
                        "LT\n"
                        "MINUS\n"
                        "NE\n"
                        "NEW\n"
                        "NULL\n"
                        "NUM\n"
                        "PCT\n"
                        "PLUS\n"
                        "PRINTLN\n"
                        "RBRACE\n"
                        "RBRACK\n"
                        "RETURN\n"
                        "RPAREN\n"
                        "SEMI\n"
                        "SLASH\n"
                        "STAR\n"
                        "WAIN\n"
                        "WHILE\n"
                        "17\n"
                        "start\n"
                        "dcl\n"
                        "dcls\n"
                        "expr\n"
                        "factor\n"
                        "lvalue\n"
                        "procedure\n"
                        "procedures\n"
                        "main\n"
                        "params\n"
                        "paramlist\n"
                        "statement\n"
                        "statements\n"
                        "term\n"
                        "test\n"
                        "type\n"
                        "arglist\n"
                        "start\n"
                        "49\n"
                        "start BOF procedures EOF\n"
                        "procedures procedure procedures\n"
                        "procedures main\n"
                        "procedure INT ID LPAREN params RPAREN LBRACE dcls statements RETURN expr SEMI RBRACE\n"
                        "main INT WAIN LPAREN dcl COMMA dcl RPAREN LBRACE dcls statements RETURN expr SEMI RBRACE\n"
                        "params\n"
                        "params paramlist\n"
                        "paramlist dcl\n"
                        "paramlist dcl COMMA paramlist\n"
                        "type INT\n"
                        "type INT STAR\n"
                        "dcls\n"
                        "dcls dcls dcl BECOMES NUM SEMI\n"
                        "dcls dcls dcl BECOMES NULL SEMI\n"
                        "dcl type ID\n"
                        "statements\n"
                        "statements statements statement\n"
                        "statement lvalue BECOMES expr SEMI\n"
                        "statement IF LPAREN test RPAREN LBRACE statements RBRACE ELSE LBRACE statements RBRACE\n"
                        "statement WHILE LPAREN test RPAREN LBRACE statements RBRACE\n"
                        "statement PRINTLN LPAREN expr RPAREN SEMI\n"
                        "statement DELETE LBRACK RBRACK expr SEMI\n"
                        "test expr EQ expr\n"
                        "test expr NE expr\n"
                        "test expr LT expr\n"
                        "test expr LE expr\n"
                        "test expr GE expr\n"
                        "test expr GT expr\n"
                        "expr term\n"
                        "expr expr PLUS term\n"
                        "expr expr MINUS term\n"
                        "term factor\n"
                        "term term STAR factor\n"
                        "term term SLASH factor\n"
                        "term term PCT factor\n"
                        "factor ID\n"
                        "factor NUM\n"
                        "factor NULL\n"
                        "factor LPAREN expr RPAREN\n"
                        "factor AMP lvalue\n"
                        "factor STAR factor\n"
                        "factor NEW INT LBRACK expr RBRACK\n"
                        "factor ID LPAREN RPAREN\n"
                        "factor ID LPAREN arglist RPAREN\n"
                        "arglist expr\n"
                        "arglist expr COMMA arglist\n"
                        "lvalue ID\n"
                        "lvalue STAR factor\n"
                        "lvalue LPAREN lvalue RPAREN\n"
                        "132\n"
                        "863\n"
                        "72 RPAREN reduce 45\n"
                        "112 paramlist shift 1\n"
                        "85 LPAREN shift 2\n"
                        "40 factor shift 3\n"
                        "3 EQ reduce 47\n"
                        "74 EQ reduce 46\n"
                        "21 INT shift 4\n"
                        "100 EQ reduce 48\n"
                        "106 STAR shift 5\n"
                        "86 STAR shift 5\n"
                        "88 STAR shift 5\n"
                        "95 SEMI shift 6\n"
                        "51 SEMI shift 7\n"
                        "118 NULL shift 8\n"
                        "128 STAR reduce 11\n"
                        "2 NULL shift 8\n"
                        "108 GT shift 9\n"
                        "57 RETURN reduce 16\n"
                        "6 INT reduce 13\n"
                        "7 INT reduce 12\n"
                        "19 factor shift 10\n"
                        "71 factor shift 10\n"
                        "14 term shift 11\n"
                        "44 term shift 11\n"
                        "17 term shift 11\n"
                        "25 term shift 11\n"
                        "13 term shift 11\n"
                        "9 term shift 11\n"
                        "117 BECOMES reduce 14\n"
                        "94 LPAREN reduce 11\n"
                        "100 GT reduce 48\n"
                        "3 GT reduce 47\n"
                        "74 GT reduce 46\n"
                        "85 expr shift 12\n"
                        "108 GE shift 13\n"
                        "74 GE reduce 46\n"
                        "3 GE reduce 47\n"
                        "100 GE reduce 48\n"
                        "128 PRINTLN reduce 11\n"
                        "108 EQ shift 14\n"
                        "2 STAR shift 5\n"
                        "118 STAR shift 5\n"
                        "106 NEW shift 15\n"
                        "86 NEW shift 15\n"
                        "88 NEW shift 15\n"
                        "123 RPAREN shift 16\n"
                        "108 LT shift 17\n"
                        "23 procedure shift 18\n"
                        "70 term shift 11\n"
                        "31 PLUS shift 19\n"
                        "32 PLUS shift 19\n"
                        "33 PLUS shift 19\n"
                        "34 PLUS shift 19\n"
                        "35 PLUS shift 19\n"
                        "36 PLUS shift 19\n"
                        "94 WHILE reduce 11\n"
                        "29 COMMA shift 20\n"
                        "94 dcls shift 21\n"
                        "70 ID shift 22\n"
                        "0 BOF shift 23\n"
                        "5 NULL shift 8\n"
                        "56 LPAREN shift 24\n"
                        "108 LE shift 25\n"
                        "101 COMMA shift 26\n"
                        "121 SEMI shift 27\n"
                        "83 DELETE reduce 18\n"
                        "59 RETURN reduce 15\n"
                        "57 WHILE reduce 16\n"
                        "18 main shift 28\n"
                        "82 DELETE reduce 19\n"
                        "127 STAR reduce 39\n"
                        "102 STAR reduce 40\n"
                        "74 LE reduce 46\n"
                        "30 STAR reduce 36\n"
                        "8 STAR reduce 37\n"
                        "112 dcl shift 29\n"
                        "90 STAR reduce 43\n"
                        "93 STAR reduce 42\n"
                        "97 STAR reduce 38\n"
                        "116 STAR reduce 41\n"
                        "73 NUM shift 30\n"
                        "14 expr shift 31\n"
                        "44 expr shift 32\n"
                        "17 expr shift 33\n"
                        "25 expr shift 34\n"
                        "13 expr shift 35\n"
                        "9 expr shift 36\n"
                        "37 EOF reduce 4\n"
                        "87 RBRACE shift 37\n"
                        "26 INT shift 4\n"
                        "24 INT shift 4\n"
                        "5 STAR shift 5\n"
                        "59 STAR reduce 15\n"
                        "130 DELETE reduce 17\n"
                        "68 DELETE reduce 20\n"
                        "131 DELETE reduce 21\n"
                        "59 WHILE reduce 15\n"
                        "11 LT reduce 28\n"
                        "61 LT reduce 30\n"
                        "60 LT reduce 29\n"
                        "129 LPAREN shift 38\n"
                        "121 PLUS shift 19\n"
                        "46 NEW shift 15\n"
                        "52 NEW shift 15\n"
                        "66 NEW shift 15\n"
                        "4 ID reduce 9\n"
                        "38 LPAREN shift 38\n"
                        "85 STAR shift 5\n"
                        "18 procedures shift 39\n"
                        "85 NUM shift 30\n"
                        "40 NULL shift 8\n"
                        "61 RPAREN reduce 30\n"
                        "60 RPAREN reduce 29\n"
                        "11 RPAREN reduce 28\n"
                        "59 ID reduce 15\n"
                        "59 IF reduce 15\n"
                        "57 RBRACE reduce 16\n"
                        "61 NE reduce 30\n"
                        "60 NE reduce 29\n"
                        "11 NE reduce 28\n"
                        "77 IF reduce 15\n"
                        "76 IF reduce 15\n"
                        "115 STAR shift 40\n"
                        "78 ID reduce 15\n"
                        "78 IF reduce 15\n"
                        "74 RBRACK reduce 46\n"
                        "3 RBRACK reduce 47\n"
                        "100 RBRACK reduce 48\n"
                        "128 LPAREN reduce 11\n"
                        "77 ID reduce 15\n"
                        "76 ID reduce 15\n"
                        "15 INT shift 41\n"
                        "113 STAR shift 40\n"
                        "114 STAR shift 40\n"
                        "20 type shift 42\n"
                        "22 RPAREN reduce 35\n"
                        "24 type shift 42\n"
                        "26 type shift 42\n"
                        "129 WHILE shift 43\n"
                        "108 NE shift 44\n"
                        "11 LE reduce 28\n"
                        "70 factor shift 10\n"
                        "105 NEW shift 15\n"
                        "104 NEW shift 15\n"
                        "80 term shift 11\n"
                        "80 expr shift 12\n"
                        "113 LPAREN shift 38\n"
                        "114 LPAREN shift 38\n"
                        "117 RPAREN reduce 14\n"
                        "115 LPAREN shift 38\n"
                        "61 LE reduce 30\n"
                        "60 LE reduce 29\n"
                        "63 BECOMES shift 45\n"
                        "90 PCT reduce 43\n"
                        "116 PCT reduce 41\n"
                        "30 PCT reduce 36\n"
                        "8 PCT reduce 37\n"
                        "127 PCT reduce 39\n"
                        "102 PCT reduce 40\n"
                        "93 PCT reduce 42\n"
                        "97 PCT reduce 38\n"
                        "47 MINUS reduce 32\n"
                        "48 MINUS reduce 33\n"
                        "49 MINUS reduce 34\n"
                        "10 MINUS reduce 31\n"
                        "10 STAR reduce 31\n"
                        "11 STAR shift 46\n"
                        "61 STAR shift 46\n"
                        "60 STAR shift 46\n"
                        "70 LPAREN shift 2\n"
                        "46 factor shift 47\n"
                        "52 factor shift 48\n"
                        "66 factor shift 49\n"
                        "14 STAR shift 5\n"
                        "44 STAR shift 5\n"
                        "17 STAR shift 5\n"
                        "25 STAR shift 5\n"
                        "13 STAR shift 5\n"
                        "9 STAR shift 5\n"
                        "80 arglist shift 50\n"
                        "12 RPAREN reduce 44\n"
                        "19 NEW shift 15\n"
                        "71 NEW shift 15\n"
                        "45 NUM shift 51\n"
                        "61 GE reduce 30\n"
                        "60 GE reduce 29\n"
                        "11 GE reduce 28\n"
                        "10 RBRACK reduce 31\n"
                        "47 RBRACK reduce 32\n"
                        "48 RBRACK reduce 33\n"
                        "49 RBRACK reduce 34\n"
                        "90 COMMA reduce 43\n"
                        "116 COMMA reduce 41\n"
                        "61 GT reduce 30\n"
                        "60 GT reduce 29\n"
                        "11 SLASH shift 52\n"
                        "11 GT reduce 28\n"
                        "61 SLASH shift 52\n"
                        "60 SLASH shift 52\n"
                        "30 COMMA reduce 36\n"
                        "8 COMMA reduce 37\n"
                        "127 COMMA reduce 39\n"
                        "102 COMMA reduce 40\n"
                        "47 STAR reduce 32\n"
                        "48 STAR reduce 33\n"
                        "49 STAR reduce 34\n"
                        "80 ID shift 22\n"
                        "93 COMMA reduce 42\n"
                        "97 COMMA reduce 38\n"
                        "70 NULL shift 8\n"
                        "59 RBRACE reduce 15\n"
                        "46 AMP shift 53\n"
                        "52 AMP shift 53\n"
                        "66 AMP shift 53\n"
                        "23 main shift 28\n"
                        "94 ID reduce 11\n"
                        "78 RBRACE reduce 15\n"
                        "94 IF reduce 11\n"
                        "94 PRINTLN reduce 11\n"
                        "23 INT shift 54\n"
                        "5 ID shift 22\n"
                        "46 STAR shift 5\n"
                        "52 STAR shift 5\n"
                        "66 STAR shift 5\n"
                        "113 DELETE shift 55\n"
                        "114 DELETE shift 55\n"
                        "116 SLASH reduce 41\n"
                        "129 STAR shift 40\n"
                        "90 SLASH reduce 43\n"
                        "112 RPAREN reduce 5\n"
                        "54 WAIN shift 56\n"
                        "127 SLASH reduce 39\n"
                        "102 SLASH reduce 40\n"
                        "93 SLASH reduce 42\n"
                        "97 SLASH reduce 38\n"
                        "30 SLASH reduce 36\n"
                        "8 SLASH reduce 37\n"
                        "19 STAR shift 5\n"
                        "71 STAR shift 5\n"
                        "118 NUM shift 30\n"
                        "109 statement shift 57\n"
                        "2 NUM shift 30\n"
                        "73 LPAREN shift 2\n"
                        "53 LPAREN shift 38\n"
                        "47 COMMA reduce 32\n"
                        "48 COMMA reduce 33\n"
                        "49 COMMA reduce 34\n"
                        "14 factor shift 10\n"
                        "44 factor shift 10\n"
                        "17 factor shift 10\n"
                        "25 factor shift 10\n"
                        "13 factor shift 10\n"
                        "9 factor shift 10\n"
                        "10 COMMA reduce 31\n"
                        "100 STAR reduce 48\n"
                        "3 STAR reduce 47\n"
                        "74 STAR reduce 46\n"
                        "115 DELETE shift 55\n"
                        "109 PRINTLN shift 58\n"
                        "78 WHILE reduce 15\n"
                        "77 RBRACE reduce 15\n"
                        "76 RBRACE reduce 15\n"
                        "113 statement shift 57\n"
                        "114 statement shift 57\n"
                        "22 PLUS reduce 35\n"
                        "115 statement shift 57\n"
                        "105 AMP shift 53\n"
                        "104 AMP shift 53\n"
                        "77 WHILE reduce 15\n"
                        "76 WHILE reduce 15\n"
                        "128 dcls shift 59\n"
                        "118 term shift 11\n"
                        "2 term shift 11\n"
                        "19 term shift 60\n"
                        "71 term shift 61\n"
                        "128 WHILE reduce 11\n"
                        "19 LPAREN shift 2\n"
                        "71 LPAREN shift 2\n"
                        "128 RETURN reduce 11\n"
                        "57 ID reduce 16\n"
                        "57 IF reduce 16\n"
                        "23 procedures shift 62\n"
                        "2 LPAREN shift 2\n"
                        "118 LPAREN shift 2\n"
                        "21 dcl shift 63\n"
                        "19 NULL shift 8\n"
                        "71 NULL shift 8\n"
                        "78 PRINTLN reduce 15\n"
                        "77 PRINTLN reduce 15\n"
                        "76 PRINTLN reduce 15\n"
                        "2 expr shift 64\n"
                        "118 expr shift 65\n"
                        "11 PCT shift 66\n"
                        "21 ID reduce 15\n"
                        "21 IF reduce 15\n"
                        "6 LPAREN reduce 13\n"
                        "7 LPAREN reduce 12\n"
                        "113 lvalue shift 67\n"
                        "114 lvalue shift 67\n"
                        "14 NULL shift 8\n"
                        "44 NULL shift 8\n"
                        "17 NULL shift 8\n"
                        "25 NULL shift 8\n"
                        "13 NULL shift 8\n"
                        "9 NULL shift 8\n"
                        "118 AMP shift 53\n"
                        "115 lvalue shift 67\n"
                        "2 AMP shift 53\n"
                        "16 SEMI shift 68\n"
                        "80 factor shift 10\n"
                        "94 INT reduce 11\n"
                        "5 NEW shift 15\n"
                        "73 STAR shift 5\n"
                        "57 PRINTLN reduce 16\n"
                        "80 NEW shift 15\n"
                        "74 LT reduce 46\n"
                        "3 LT reduce 47\n"
                        "46 NUM shift 30\n"
                        "52 NUM shift 30\n"
                        "66 NUM shift 30\n"
                        "10 PCT reduce 31\n"
                        "3 LE reduce 47\n"
                        "100 LE reduce 48\n"
                        "85 NEW shift 15\n"
                        "21 WHILE reduce 15\n"
                        "47 PCT reduce 32\n"
                        "48 PCT reduce 33\n"
                        "49 PCT reduce 34\n"
                        "100 LT reduce 48\n"
                        "21 RBRACE reduce 15\n"
                        "22 COMMA reduce 35\n"
                        "129 PRINTLN shift 58\n"
                        "22 SEMI reduce 35\n"
                        "100 NE reduce 48\n"
                        "3 NE reduce 47\n"
                        "74 NE reduce 46\n"
                        "40 AMP shift 53\n"
                        "14 ID shift 22\n"
                        "44 ID shift 22\n"
                        "17 ID shift 22\n"
                        "25 ID shift 22\n"
                        "13 ID shift 22\n"
                        "9 ID shift 22\n"
                        "94 RETURN reduce 11\n"
                        "46 NULL shift 8\n"
                        "52 NULL shift 8\n"
                        "66 NULL shift 8\n"
                        "19 AMP shift 53\n"
                        "71 AMP shift 53\n"
                        "118 ID shift 22\n"
                        "2 ID shift 22\n"
                        "54 ID shift 69\n"
                        "80 NULL shift 8\n"
                        "129 RETURN shift 70\n"
                        "61 PLUS reduce 30\n"
                        "60 PLUS reduce 29\n"
                        "11 PLUS reduce 28\n"
                        "59 DELETE reduce 15\n"
                        "22 PCT reduce 35\n"
                        "31 MINUS shift 71\n"
                        "32 MINUS shift 71\n"
                        "33 MINUS shift 71\n"
                        "34 MINUS shift 71\n"
                        "35 MINUS shift 71\n"
                        "36 MINUS shift 71\n"
                        "105 NUM shift 30\n"
                        "104 NUM shift 30\n"
                        "85 arglist shift 72\n"
                        "22 RBRACK reduce 35\n"
                        "6 DELETE reduce 13\n"
                        "7 DELETE reduce 12\n"
                        "109 RETURN shift 73\n"
                        "88 LPAREN shift 2\n"
                        "12 PLUS shift 19\n"
                        "53 ID shift 74\n"
                        "105 LPAREN shift 2\n"
                        "104 LPAREN shift 2\n"
                        "106 LPAREN shift 2\n"
                        "86 LPAREN shift 2\n"
                        "22 MINUS reduce 35\n"
                        "90 BECOMES reduce 43\n"
                        "93 BECOMES reduce 42\n"
                        "97 BECOMES reduce 38\n"
                        "127 BECOMES reduce 39\n"
                        "102 BECOMES reduce 40\n"
                        "30 BECOMES reduce 36\n"
                        "8 BECOMES reduce 37\n"
                        "70 NUM shift 30\n"
                        "116 BECOMES reduce 41\n"
                        "19 NUM shift 30\n"
                        "71 NUM shift 30\n"
                        "73 expr shift 75\n"
                        "94 STAR reduce 11\n"
                        "126 LBRACE shift 76\n"
                        "125 LBRACE shift 77\n"
                        "100 SLASH reduce 48\n"
                        "3 SLASH reduce 47\n"
                        "96 LBRACE shift 78\n"
                        "74 SLASH reduce 46\n"
                        "55 LBRACK shift 79\n"
                        "40 STAR shift 5\n"
                        "128 INT reduce 11\n"
                        "2 NEW shift 15\n"
                        "22 LPAREN shift 80\n"
                        "127 NE reduce 39\n"
                        "102 NE reduce 40\n"
                        "93 NE reduce 42\n"
                        "97 NE reduce 38\n"
                        "90 NE reduce 43\n"
                        "116 NE reduce 41\n"
                        "116 MINUS reduce 41\n"
                        "38 STAR shift 40\n"
                        "78 RETURN reduce 15\n"
                        "112 INT shift 4\n"
                        "30 NE reduce 36\n"
                        "8 NE reduce 37\n"
                        "30 MINUS reduce 36\n"
                        "8 MINUS reduce 37\n"
                        "118 NEW shift 15\n"
                        "127 MINUS reduce 39\n"
                        "102 MINUS reduce 40\n"
                        "93 MINUS reduce 42\n"
                        "97 MINUS reduce 38\n"
                        "90 MINUS reduce 43\n"
                        "77 RETURN reduce 15\n"
                        "76 RETURN reduce 15\n"
                        "39 EOF reduce 1\n"
                        "6 WHILE reduce 13\n"
                        "7 WHILE reduce 12\n"
                        "28 EOF reduce 2\n"
                        "59 PRINTLN reduce 15\n"
                        "113 RBRACE shift 81\n"
                        "114 RBRACE shift 82\n"
                        "127 RBRACK reduce 39\n"
                        "102 RBRACK reduce 40\n"
                        "93 RBRACK reduce 42\n"
                        "97 RBRACK reduce 38\n"
                        "109 lvalue shift 67\n"
                        "90 RBRACK reduce 43\n"
                        "116 RBRACK reduce 41\n"
                        "115 RBRACE shift 83\n"
                        "30 RBRACK reduce 36\n"
                        "8 RBRACK reduce 37\n"
                        "21 PRINTLN reduce 15\n"
                        "14 LPAREN shift 2\n"
                        "44 LPAREN shift 2\n"
                        "17 LPAREN shift 2\n"
                        "25 LPAREN shift 2\n"
                        "13 LPAREN shift 2\n"
                        "9 LPAREN shift 2\n"
                        "112 params shift 84\n"
                        "12 COMMA shift 85\n"
                        "75 MINUS shift 71\n"
                        "22 SLASH reduce 35\n"
                        "103 RPAREN reduce 8\n"
                        "5 NUM shift 30\n"
                        "67 BECOMES shift 86\n"
                        "11 RBRACK reduce 28\n"
                        "61 COMMA reduce 30\n"
                        "60 COMMA reduce 29\n"
                        "61 RBRACK reduce 30\n"
                        "60 RBRACK reduce 29\n"
                        "11 COMMA reduce 28\n"
                        "74 PCT reduce 46\n"
                        "3 PCT reduce 47\n"
                        "100 PCT reduce 48\n"
                        "75 PLUS shift 19\n"
                        "5 LPAREN shift 2\n"
                        "112 type shift 42\n"
                        "85 ID shift 22\n"
                        "3 BECOMES reduce 47\n"
                        "74 BECOMES reduce 46\n"
                        "100 BECOMES reduce 48\n"
                        "85 term shift 11\n"
                        "116 SEMI reduce 41\n"
                        "64 MINUS shift 71\n"
                        "93 SEMI reduce 42\n"
                        "97 SEMI reduce 38\n"
                        "65 MINUS shift 71\n"
                        "90 SEMI reduce 43\n"
                        "80 LPAREN shift 2\n"
                        "75 SEMI shift 87\n"
                        "130 RBRACE reduce 17\n"
                        "68 RBRACE reduce 20\n"
                        "131 RBRACE reduce 21\n"
                        "14 AMP shift 53\n"
                        "44 AMP shift 53\n"
                        "17 AMP shift 53\n"
                        "25 AMP shift 53\n"
                        "13 AMP shift 53\n"
                        "9 AMP shift 53\n"
                        "82 RBRACE reduce 19\n"
                        "79 RBRACK shift 88\n"
                        "127 SEMI reduce 39\n"
                        "102 SEMI reduce 40\n"
                        "30 SEMI reduce 36\n"
                        "8 SEMI reduce 37\n"
                        "83 RBRACE reduce 18\n"
                        "68 PRINTLN reduce 20\n"
                        "131 PRINTLN reduce 21\n"
                        "130 PRINTLN reduce 17\n"
                        "47 PLUS reduce 32\n"
                        "48 PLUS reduce 33\n"
                        "49 PLUS reduce 34\n"
                        "82 PRINTLN reduce 19\n"
                        "10 PLUS reduce 31\n"
                        "109 WHILE shift 43\n"
                        "83 PRINTLN reduce 18\n"
                        "65 PLUS shift 19\n"
                        "64 PLUS shift 19\n"
                        "77 STAR reduce 15\n"
                        "76 STAR reduce 15\n"
                        "10 SEMI reduce 31\n"
                        "78 STAR reduce 15\n"
                        "73 NULL shift 8\n"
                        "46 LPAREN shift 2\n"
                        "52 LPAREN shift 2\n"
                        "66 LPAREN shift 2\n"
                        "4 STAR shift 89\n"
                        "47 SEMI reduce 32\n"
                        "48 SEMI reduce 33\n"
                        "49 SEMI reduce 34\n"
                        "116 RPAREN reduce 41\n"
                        "40 NUM shift 30\n"
                        "30 RPAREN reduce 36\n"
                        "8 RPAREN reduce 37\n"
                        "127 RPAREN reduce 39\n"
                        "102 RPAREN reduce 40\n"
                        "50 RPAREN shift 90\n"
                        "93 RPAREN reduce 42\n"
                        "97 RPAREN reduce 38\n"
                        "105 NULL shift 8\n"
                        "104 NULL shift 8\n"
                        "90 RPAREN reduce 43\n"
                        "109 DELETE shift 55\n"
                        "18 procedure shift 18\n"
                        "100 PLUS reduce 48\n"
                        "74 PLUS reduce 46\n"
                        "3 PLUS reduce 47\n"
                        "85 factor shift 10\n"
                        "10 NE reduce 31\n"
                        "47 NE reduce 32\n"
                        "48 NE reduce 33\n"
                        "49 NE reduce 34\n"
                        "94 DELETE reduce 11\n"
                        "116 EQ reduce 41\n"
                        "100 COMMA reduce 48\n"
                        "30 GT reduce 36\n"
                        "8 GT reduce 37\n"
                        "3 COMMA reduce 47\n"
                        "93 GT reduce 42\n"
                        "97 GT reduce 38\n"
                        "127 GT reduce 39\n"
                        "102 GT reduce 40\n"
                        "1 RPAREN reduce 6\n"
                        "74 COMMA reduce 46\n"
                        "27 RBRACE shift 91\n"
                        "90 GE reduce 43\n"
                        "93 GE reduce 42\n"
                        "97 GE reduce 38\n"
                        "116 GE reduce 41\n"
                        "83 WHILE reduce 18\n"
                        "30 GE reduce 36\n"
                        "8 GE reduce 37\n"
                        "127 GE reduce 39\n"
                        "102 GE reduce 40\n"
                        "21 LPAREN reduce 15\n"
                        "6 STAR reduce 13\n"
                        "7 STAR reduce 12\n"
                        "82 WHILE reduce 19\n"
                        "68 WHILE reduce 20\n"
                        "131 WHILE reduce 21\n"
                        "130 WHILE reduce 17\n"
                        "61 PCT shift 66\n"
                        "60 PCT shift 66\n"
                        "80 NUM shift 30\n"
                        "20 dcl shift 29\n"
                        "99 RPAREN shift 92\n"
                        "128 ID reduce 11\n"
                        "57 LPAREN reduce 16\n"
                        "80 RPAREN shift 93\n"
                        "92 LBRACE shift 94\n"
                        "14 NUM shift 30\n"
                        "44 NUM shift 30\n"
                        "17 NUM shift 30\n"
                        "25 NUM shift 30\n"
                        "13 NUM shift 30\n"
                        "9 NUM shift 30\n"
                        "90 GT reduce 43\n"
                        "116 GT reduce 41\n"
                        "45 NULL shift 95\n"
                        "128 IF reduce 11\n"
                        "81 ELSE shift 96\n"
                        "57 DELETE reduce 16\n"
                        "64 RPAREN shift 97\n"
                        "73 AMP shift 53\n"
                        "62 EOF shift 98\n"
                        "21 STAR reduce 15\n"
                        "118 factor shift 10\n"
                        "105 factor shift 10\n"
                        "104 factor shift 10\n"
                        "2 factor shift 10\n"
                        "29 RPAREN reduce 7\n"
                        "100 RPAREN reduce 48\n"
                        "105 ID shift 22\n"
                        "104 ID shift 22\n"
                        "82 LPAREN reduce 19\n"
                        "20 INT shift 4\n"
                        "88 factor shift 10\n"
                        "130 LPAREN reduce 17\n"
                        "106 factor shift 10\n"
                        "86 factor shift 10\n"
                        "68 LPAREN reduce 20\n"
                        "131 LPAREN reduce 21\n"
                        "26 dcl shift 99\n"
                        "19 ID shift 22\n"
                        "71 ID shift 22\n"
                        "74 RPAREN reduce 46\n"
                        "111 RPAREN shift 100\n"
                        "3 RPAREN reduce 47\n"
                        "83 LPAREN reduce 18\n"
                        "24 dcl shift 101\n"
                        "5 factor shift 102\n"
                        "20 paramlist shift 103\n"
                        "107 LPAREN shift 104\n"
                        "43 LPAREN shift 105\n"
                        "58 LPAREN shift 106\n"
                        "12 MINUS shift 71\n"
                        "11 MINUS reduce 28\n"
                        "61 MINUS reduce 30\n"
                        "60 MINUS reduce 29\n"
                        "59 INT shift 4\n"
                        "93 LT reduce 42\n"
                        "97 LT reduce 38\n"
                        "90 LT reduce 43\n"
                        "30 LT reduce 36\n"
                        "8 LT reduce 37\n"
                        "127 LT reduce 39\n"
                        "102 LT reduce 40\n"
                        "91 INT reduce 3\n"
                        "116 LT reduce 41\n"
                        "93 LE reduce 42\n"
                        "97 LE reduce 38\n"
                        "108 PLUS shift 19\n"
                        "127 LE reduce 39\n"
                        "102 LE reduce 40\n"
                        "30 LE reduce 36\n"
                        "8 LE reduce 37\n"
                        "129 ID shift 74\n"
                        "116 LE reduce 41\n"
                        "129 IF shift 107\n"
                        "90 LE reduce 43\n"
                        "46 ID shift 22\n"
                        "52 ID shift 22\n"
                        "66 ID shift 22\n"
                        "70 NEW shift 15\n"
                        "88 NULL shift 8\n"
                        "106 NULL shift 8\n"
                        "86 NULL shift 8\n"
                        "10 EQ reduce 31\n"
                        "47 EQ reduce 32\n"
                        "48 EQ reduce 33\n"
                        "49 EQ reduce 34\n"
                        "80 STAR shift 5\n"
                        "6 PRINTLN reduce 13\n"
                        "7 PRINTLN reduce 12\n"
                        "22 LT reduce 35\n"
                        "59 LPAREN reduce 15\n"
                        "59 type shift 42\n"
                        "73 NEW shift 15\n"
                        "22 LE reduce 35\n"
                        "109 STAR shift 40\n"
                        "105 expr shift 108\n"
                        "104 expr shift 108\n"
                        "93 PLUS reduce 42\n"
                        "97 PLUS reduce 38\n"
                        "90 PLUS reduce 43\n"
                        "116 PLUS reduce 41\n"
                        "30 PLUS reduce 36\n"
                        "8 PLUS reduce 37\n"
                        "127 PLUS reduce 39\n"
                        "102 PLUS reduce 40\n"
                        "10 GT reduce 31\n"
                        "47 GT reduce 32\n"
                        "48 GT reduce 33\n"
                        "49 GT reduce 34\n"
                        "109 IF shift 107\n"
                        "109 ID shift 74\n"
                        "80 AMP shift 53\n"
                        "108 MINUS shift 71\n"
                        "10 GE reduce 31\n"
                        "47 GE reduce 32\n"
                        "48 GE reduce 33\n"
                        "49 GE reduce 34\n"
                        "21 statements shift 109\n"
                        "109 LPAREN shift 38\n"
                        "59 dcl shift 63\n"
                        "128 DELETE reduce 11\n"
                        "40 ID shift 22\n"
                        "84 RPAREN shift 110\n"
                        "88 NUM shift 30\n"
                        "106 NUM shift 30\n"
                        "86 NUM shift 30\n"
                        "40 LPAREN shift 2\n"
                        "38 lvalue shift 111\n"
                        "22 BECOMES reduce 35\n"
                        "40 NEW shift 15\n"
                        "69 LPAREN shift 112\n"
                        "77 statements shift 113\n"
                        "76 statements shift 114\n"
                        "73 term shift 11\n"
                        "78 statements shift 115\n"
                        "53 STAR shift 40\n"
                        "57 STAR reduce 16\n"
                        "93 EQ reduce 42\n"
                        "97 EQ reduce 38\n"
                        "90 EQ reduce 43\n"
                        "30 EQ reduce 36\n"
                        "8 EQ reduce 37\n"
                        "127 EQ reduce 39\n"
                        "102 EQ reduce 40\n"
                        "85 AMP shift 53\n"
                        "47 LT reduce 32\n"
                        "48 LT reduce 33\n"
                        "49 LT reduce 34\n"
                        "10 LT reduce 31\n"
                        "117 COMMA reduce 14\n"
                        "18 INT shift 54\n"
                        "83 RETURN reduce 18\n"
                        "10 LE reduce 31\n"
                        "3 MINUS reduce 47\n"
                        "129 statement shift 57\n"
                        "74 MINUS reduce 46\n"
                        "22 NE reduce 35\n"
                        "10 RPAREN reduce 31\n"
                        "100 MINUS reduce 48\n"
                        "47 LE reduce 32\n"
                        "48 LE reduce 33\n"
                        "49 LE reduce 34\n"
                        "106 term shift 11\n"
                        "86 term shift 11\n"
                        "130 RETURN reduce 17\n"
                        "47 RPAREN reduce 32\n"
                        "48 RPAREN reduce 33\n"
                        "49 RPAREN reduce 34\n"
                        "70 AMP shift 53\n"
                        "88 term shift 11\n"
                        "68 RETURN reduce 20\n"
                        "131 RETURN reduce 21\n"
                        "82 RETURN reduce 19\n"
                        "105 term shift 11\n"
                        "104 term shift 11\n"
                        "82 STAR reduce 19\n"
                        "22 STAR reduce 35\n"
                        "83 STAR reduce 18\n"
                        "77 LPAREN reduce 15\n"
                        "76 LPAREN reduce 15\n"
                        "65 RBRACK shift 116\n"
                        "70 STAR shift 5\n"
                        "68 STAR reduce 20\n"
                        "131 STAR reduce 21\n"
                        "78 LPAREN reduce 15\n"
                        "130 STAR reduce 17\n"
                        "129 DELETE shift 55\n"
                        "121 MINUS shift 71\n"
                        "78 DELETE reduce 15\n"
                        "42 ID shift 117\n"
                        "77 DELETE reduce 15\n"
                        "76 DELETE reduce 15\n"
                        "113 ID shift 74\n"
                        "114 ID shift 74\n"
                        "113 IF shift 107\n"
                        "114 IF shift 107\n"
                        "115 ID shift 74\n"
                        "115 IF shift 107\n"
                        "38 ID shift 74\n"
                        "123 PLUS shift 19\n"
                        "124 PLUS shift 19\n"
                        "122 PLUS shift 19\n"
                        "47 SLASH reduce 32\n"
                        "48 SLASH reduce 33\n"
                        "49 SLASH reduce 34\n"
                        "10 SLASH reduce 31\n"
                        "41 LBRACK shift 118\n"
                        "14 NEW shift 15\n"
                        "44 NEW shift 15\n"
                        "17 NEW shift 15\n"
                        "25 NEW shift 15\n"
                        "13 NEW shift 15\n"
                        "9 NEW shift 15\n"
                        "105 STAR shift 5\n"
                        "104 STAR shift 5\n"
                        "105 test shift 119\n"
                        "104 test shift 120\n"
                        "5 AMP shift 53\n"
                        "122 MINUS shift 71\n"
                        "123 MINUS shift 71\n"
                        "124 MINUS shift 71\n"
                        "70 expr shift 121\n"
                        "100 SEMI reduce 48\n"
                        "73 ID shift 22\n"
                        "3 SEMI reduce 47\n"
                        "74 SEMI reduce 46\n"
                        "113 WHILE shift 43\n"
                        "114 WHILE shift 43\n"
                        "88 ID shift 22\n"
                        "106 ID shift 22\n"
                        "86 ID shift 22\n"
                        "22 GE reduce 35\n"
                        "115 WHILE shift 43\n"
                        "88 expr shift 122\n"
                        "106 expr shift 123\n"
                        "86 expr shift 124\n"
                        "120 RPAREN shift 125\n"
                        "119 RPAREN shift 126\n"
                        "22 GT reduce 35\n"
                        "129 lvalue shift 67\n"
                        "11 SEMI reduce 28\n"
                        "6 IF reduce 13\n"
                        "7 IF reduce 12\n"
                        "61 SEMI reduce 30\n"
                        "60 SEMI reduce 29\n"
                        "53 lvalue shift 127\n"
                        "6 ID reduce 13\n"
                        "7 ID reduce 12\n"
                        "88 AMP shift 53\n"
                        "89 ID reduce 10\n"
                        "110 LBRACE shift 128\n"
                        "106 AMP shift 53\n"
                        "86 AMP shift 53\n"
                        "83 IF reduce 18\n"
                        "83 ID reduce 18\n"
                        "82 IF reduce 19\n"
                        "130 IF reduce 17\n"
                        "82 ID reduce 19\n"
                        "68 IF reduce 20\n"
                        "131 IF reduce 21\n"
                        "31 RPAREN reduce 22\n"
                        "32 RPAREN reduce 23\n"
                        "33 RPAREN reduce 24\n"
                        "34 RPAREN reduce 25\n"
                        "35 RPAREN reduce 26\n"
                        "36 RPAREN reduce 27\n"
                        "21 type shift 42\n"
                        "6 RETURN reduce 13\n"
                        "7 RETURN reduce 12\n"
                        "59 statements shift 129\n"
                        "68 ID reduce 20\n"
                        "131 ID reduce 21\n"
                        "130 ID reduce 17\n"
                        "22 EQ reduce 35\n"
                        "11 EQ reduce 28\n"
                        "73 factor shift 10\n"
                        "61 EQ reduce 30\n"
                        "60 EQ reduce 29\n"
                        "85 NULL shift 8\n"
                        "115 PRINTLN shift 58\n"
                        "124 SEMI shift 130\n"
                        "122 SEMI shift 131\n"
                        "21 RETURN reduce 15\n"
                        "113 PRINTLN shift 58\n"
                        "114 PRINTLN shift 58\n"
                        "21 DELETE reduce 15";

class Tree{
public:
    std::string root;
    std::vector<Tree*> subtrees;
    ~Tree(){
        for (Tree* pointer: subtrees){
            if (pointer != nullptr){
                delete pointer;
            }
        }
    }
    Tree(std::string name){
        root = name;
    }
};

void TreePrinter(Tree * t){
    if (t == nullptr){return;}
    else{
        std::cout << t->root << std::endl;
        for (int i =0; i < t->subtrees.size(); i++){
            TreePrinter(t->subtrees[t->subtrees.size() - 1 - i]);
        }
    }
}

void TreeStackDeleter(std::vector<Tree*> tree){
    for (Tree* subtree: tree){
        if(subtree != nullptr){
            delete subtree;
        }
    }
}

class LR1 {

public:
    void recognize(const std::string&);
    LR1(const std::vector<std::string>&, const std::vector<std::string>&, std::map<std::string, std::string> lexemeMap);

private:
    /* A set of all accepting states for the DFA.
     * Currently non-accepting states are not actually present anywhere
     * in memory, but a list can be found in the constructor.
     */
    std::map<std::string, std::string> lexemeMap;
    std::set<std::string> acceptingStates;
    std::map<std::pair<int, std::string>, std::pair<int, bool>> transitionMap;
    std::vector<int> sizeOfDerivations;
    std::vector<std::string> pureDerivations;
    std::vector<std::string> LHSDerivations;
    int startingState = 0;
};

void printer(std::vector<std::string> s) {
    for (std::string t: s){
        std::cout << t << std::endl;
    }
}


LR1::LR1(const std::vector<std::string>& rawDerivationRules , const std::vector<std::string>& rawTransitions, std::map<std::string, std::string> lexemeMap) {
    this->startingState = 0;
    this->lexemeMap = lexemeMap;
    for (const std::string& acceptingState: acceptingStates){
        this->acceptingStates.insert(acceptingState);
    }
    for (const std::string& rawTransition: rawTransitions){
        std::stringstream ss(rawTransition);
        int inputState;
        int outputState;
        std::string transitionSymbol;
        std::string reduce_shift;
        bool reduceShift;
        ss >> inputState;
        ss >> transitionSymbol;
        ss >> reduce_shift;
        ss >> outputState;
        reduceShift = reduce_shift == "reduce";
        std::pair<int, std::string> p {inputState, transitionSymbol};
        std::pair<int, bool> q {outputState, reduceShift};
        this->transitionMap[p] = q;
    }
    this->pureDerivations = rawDerivationRules;
    for (const std::string& rawDerivationRule: rawDerivationRules){
        std::stringstream ss(rawDerivationRule);
        std::string placeHolder;
        ss >> placeHolder;
        this->LHSDerivations.push_back(placeHolder);
        int count = 0;
        while(ss >> placeHolder){
            count ++;
        }
        this->sizeOfDerivations.push_back(count);
    }
}

void LR1::recognize(const std::string& rawWord) {
    std::vector<int> stateStack;
    std::vector<Tree*> treeStack;
    std::vector<std::string> symbolStack;
    std::vector<std::string> plainParseTree;
    stateStack.push_back(0);
    std::stringstream ss(rawWord);
    std::string newSymbol;
    std::string newToken;
    std::vector<std::string> unread;
    Tree *bigTree = nullptr;
    int unreadCounter = -1;

    while (ss >> newSymbol){
        unread.push_back(newSymbol);
    }

    int currentState = this->startingState;
    bool stillthesame = false;
    while(true){
        if (!stillthesame){
            unreadCounter ++;
            if (unreadCounter == unread.size()){
                bigTree = new Tree(pureDerivations[0]);
                int treeSize = treeStack.size() - 1;
                for (int counter = 0; counter <= treeSize; counter ++){
                    bigTree->subtrees.push_back(treeStack[treeSize - counter]);
                    treeStack.pop_back();
                }
                plainParseTree.push_back(this->pureDerivations[0]);

                break;
            }
        }
        else{
            stillthesame = false;
        }
        newSymbol = unread[unreadCounter];
        newToken = this->lexemeMap[newSymbol];
        std::pair<int, std::string> p(currentState, newToken);
        if (transitionMap.count(p) == 0) {
            TreeStackDeleter(treeStack);
            myerror(unreadCounter);
            return;
        } else {
            std::pair<int, bool> q = transitionMap[p];
            if (q.second){
                int rule = q.first;
                int size = this->sizeOfDerivations[rule];
                Tree * newSubTree = new Tree(pureDerivations[rule]);
                plainParseTree.push_back(this->pureDerivations[rule]);
                for (int counter = 0; counter < size; counter++){
                    stateStack.pop_back();
                    symbolStack.pop_back();
                }
                int treeSize = treeStack.size() - 1;
                for (int counter = 0; counter < size; counter ++){
                    newSubTree->subtrees.push_back(treeStack[treeSize - counter]);
                    treeStack.pop_back();
                }
                treeStack.push_back(newSubTree);
                std::string newNonTerminal = this->LHSDerivations[rule];
                symbolStack.push_back(newNonTerminal);
                currentState = stateStack[stateStack.size() - 1];
                std::pair<int, std::string> p2(currentState, newNonTerminal);
                if (transitionMap.count(p2) == 0) {
                    TreeStackDeleter(treeStack);
                    myerror(unreadCounter);
                    return;
                }
                else{
                    q = transitionMap[p2];
                    stateStack.push_back(q.first);
                    currentState = q.first;
                    stillthesame = true;
                    continue;
                }
            }
            else{
                symbolStack.push_back(newToken);
                plainParseTree.push_back(newToken + " " + newSymbol);
                treeStack.push_back(new Tree(newToken + " " + newSymbol));
                stateStack.push_back(q.first);
                currentState = q.first;
            }
        }
    }
    TreePrinter(bigTree);
    delete bigTree;
}

int main() {
    std::stringstream ss(wlp4_lr1);
    std::string line;
    std::string startingState;
    std::vector<std::string> rawDerivationRules;
    std::vector<std::string> rawTransitions;
    // terminals
    getline(ss, line);
    int numberOfSymbols = std::stoi(line);
    for (int i = 0; i < numberOfSymbols; i ++){
        getline(ss, line);
    }
    // non terminals
    getline(ss, line);
    int numberOfNonTerminals = std::stoi(line);
    for (int i = 0; i < numberOfNonTerminals; i ++){
        getline(ss, line);
    }
    // initial state
    getline(ss, line);
    startingState = line;

    // raw derivations
    getline(ss, line);
    int numberOfDerivations = std::stoi(line);
    for (int i = 0; i < numberOfDerivations; i ++){
        getline(ss, line);
        rawDerivationRules.push_back(line);
    }

    // number of States
    getline(ss, line);
    int numberOfStates = std::stoi(line);

    // raw transitions
    getline(ss, line);
    int numberOfTransitions = std::stoi(line);
    for (int i = 0; i < numberOfTransitions; i ++){
        getline(ss, line);
        rawTransitions.push_back(line);
    }
    // actual string to be translated
    std::string rawWord = "BOF ";
    std::map<std::string, std::string> lexemeMap;
    while(getline(std::cin, line)){
        std::string placeHolder;
        std::string placeHolder2;
        std::stringstream s(line);
        s >> placeHolder;
        s >> placeHolder2;
        rawWord += " " + placeHolder2;
        lexemeMap[placeHolder2] = placeHolder;
    }
    lexemeMap["BOF"] = "BOF";
    lexemeMap["EOF"] = "EOF";
    rawWord = rawWord + " EOF";

    LR1 lr1(rawDerivationRules, rawTransitions, lexemeMap);

    lr1.recognize(rawWord);

}
