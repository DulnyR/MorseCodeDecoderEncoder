#include "morse_data_and_functions.h"
#include <iostream>
#include <stdlib.h>


using namespace std;

int main() {
    bool table_ok;
    Morse_Code myMorse("morse_code_table");

    myMorse.encode_a_file("test_to_encode");
    myMorse.decode_a_file("test_to_decode");
}