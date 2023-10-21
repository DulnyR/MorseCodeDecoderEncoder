#include "morse_data_and_functions.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

vector<CodePair> code_table;

Morse_Code::Morse_Code() {}

Morse_Code::Morse_Code(string key_file){
    ifstream table_stream;
    table_stream.open(key_file);
    if(!table_stream) {
        cout << "prob opening " << key_file << endl;
    }

    string line;
    while(getline(table_stream,line)) {
        CodePair p;
        p.plain = line[0];
        p.code = line.substr(2);
        code_table.push_back(p);
    }

    // check;
    cout << "size of code table " << code_table.size() << endl;
    for(int i=0; i < code_table.size(); i++) {
        cout << code_table[i].plain << " " << code_table[i].code << endl;
    }
}

string Morse_Code::encode_a_char(char c) {

    for(int i = 0; i < code_table.size(); i++) {
        if(code_table[i].plain == c) {
            return code_table[i].code;
        }
    }
    // reach here only if not found
    return "*****";
}

char Morse_Code::decode_a_morse_code(string s) {
    for(CodePair pair : code_table) {
        if(pair.code == s) {
            return pair.plain;
        }
    }
    return '*';
}

vector<string> Morse_Code::encode_a_word(string word) {
    vector<string> encoded;
    for(int i = 0; i < word.size(); i++) {
        encoded.push_back(encode_a_char(word[i]));
    }
    return encoded;
}

// get each 'word' via <<, an split this into chars, then encode
// print codes separated by 3 spaces
// print 7 spaces for word separation
void Morse_Code::encode_a_file(string filename) {

    ifstream file;
    file.open(filename.c_str());
    if (!file) {
        cout << "prob opening" << filename << endl;
        exit(1);
    }

    string word;
    vector<string> coded_word;
    while (file >> word) {
        coded_word = encode_a_word(word);
        for (int i = 0; i < coded_word.size(); i++) {
            cout << coded_word[i];
            if (i != coded_word.size() - 1) {
                cout << "   ";
            }
        }
        cout << "       ";
    }

    cout << endl;
}

void Morse_Code::decode_a_file(string filename)
{
    ifstream file;
    file >> noskipws;
    file.open(filename.c_str());
    if (!file) {
        cout << "prob opening" << filename << endl;
        exit(1);
    }

    char character;
    string word;
    char decoded_letter;
    int space_count = 0;
    while (file >> character) {
        if(character != ' ') {
            if(space_count > 3) cout << ' ';
            space_count = 0;
            word.push_back(character);
        }
        else if(character == ' ') {
            if(space_count == 0) {
                decoded_letter = decode_a_morse_code(word);
                cout << decoded_letter;
                word.clear();
            }
            space_count++;
        }
    }
}
