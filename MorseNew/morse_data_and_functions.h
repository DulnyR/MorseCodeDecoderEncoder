#include <string>
#include <vector>
using namespace std;

struct CodePair {
    char plain;
    string code;
};

class Morse_Code {

private:
    vector<CodePair> code_table;
    vector<string> encode_a_word(string word);
    string encode_a_char(char c);
    char decode_a_morse_code(string morse_code);

public:
    Morse_Code();
    Morse_Code(string key_file);
    void encode_a_file(string filename);
    void decode_a_file(string filename);

};

#ifndef MORSENEW_MORSE_DATA_AND_FUNCTIONS_H
#define MORSENEW_MORSE_DATA_AND_FUNCTIONS_H

#endif //MORSENEW_MORSE_DATA_AND_FUNCTIONS_H
