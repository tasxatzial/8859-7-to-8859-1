/* Convert iso8859-7 text to iso8859-1 */

#include <stdio.h>

/* Number of characters in each ISO standard */
#define NUM_CHARS 256

/* Each character in ISO8859-7 corresponds to 3 characters in ISO 8859-1 */
#define CHAR_SIZE 3

/* -------------------------- ASCII Codes --------------------------*/

/* quote and double quote */
#define QUOTE 39
#define DOUBLE_QUOTE 34

/* greek capital non-accented letters */
#define ALPHA 193
#define BETA 194
#define GAMMA 195
#define DELTA 196
#define EPSILON 197
#define ZETA 198
#define ETA 199
#define THETA 200
#define IOTA 201
#define KAPPA 202
#define LAMBDA 203
#define MU 204
#define NU 205
#define XI 206
#define OMICRON 207
#define PI 208
#define RHO 209
#define SIGMA 211
#define TAU 212
#define UPSILON 213
#define PHI 214
#define CHI 215
#define PSI 216
#define OMEGA 217

/* greek small non-accented letters */
#define LOW_ALPHA 225
#define LOW_BETA 226
#define LOW_GAMMA 227
#define LOW_DELTA 228
#define LOW_EPSILON 229
#define LOW_ZETA 230
#define LOW_ETA 231
#define LOW_THETA 232
#define LOW_IOTA 233
#define LOW_KAPPA 234
#define LOW_LAMBDA 235
#define LOW_MU 236
#define LOW_NU 237
#define LOW_XI 238
#define LOW_OMICRON 239
#define LOW_PI 240
#define LOW_RHO 241
#define LOW_FINAL_SIGMA 242
#define LOW_SIGMA 243
#define LOW_TAU 244
#define LOW_UPSILON 245
#define LOW_PHI 246
#define LOW_CHI 247
#define LOW_PSI 248
#define LOW_OMEGA 249

/* greek accented letters */
#define ALPHA_ACC 182
#define LOW_ALPHA_ACC 220
#define EPSILON_ACC 184
#define LOW_EPSILON_ACC 221
#define ETA_ACC 185
#define LOW_ETA_ACC 222
#define IOTA_ACC 186
#define LOW_IOTA_ACC 223
#define OMICRON_ACC 188
#define LOW_OMICRON_ACC 252
#define UPSILON_ACC 190
#define LOW_UPSILON_ACC 253
#define OMEGA_ACC 191
#define LOW_OMEGA_ACC 254

/* greek characters with dlalytika */
#define IOTA_DIA 218
#define LOW_IOTA_DIA 250
#define UPSILON_DIA 219
#define LOW_UPSILON_DIA 251
#define LOW_IOTA_ACC_DIA 192
#define LOW_UPSILON_ACC_DIA 224


/* map_init

Initializes a 2-dimensional array of chars that maps ISO8859-7 characters
to ISO8859-1 characters.

Parameters:
map: a 2-dimensional array

Returns: void */
void map_init(char map[NUM_CHARS][CHAR_SIZE]) {
    int i;

    /* if i is the ASCII code of an ISO8859-7 char, then map[i][0], map[i][1],
     * map[i][2] in that order form the corresponding character in
     * ISO8859-1. Create an initial mapping as shown below. */
    for (i = 0; i < NUM_CHARS; i++) {
        map[i][0] = i;
        map[i][1] = '\0';
        map[i][2] = '\0';
    }

    /* Next, map specific characters: If a character in ISO8859-7 needs to be
     * converted to >1 characters in ISO8859-1 then use map[][1] and map[][2]
     * to specify the extra characters. */

    /* map capital non-accented letters */
    map[ALPHA][0] = 'A';
    map[BETA][0] = 'V';
    map[GAMMA][0] = 'G';
    map[DELTA][0] = 'D';
    map[EPSILON][0] = 'E';
    map[ZETA][0] = 'Z';
    map[ETA][0] = 'H';
    map[THETA][0] = '8';
    map[IOTA][0] = 'I';
    map[KAPPA][0] = 'K';
    map[LAMBDA][0] = 'L';
    map[MU][0] = 'M';
    map[NU][0] = 'N';
    map[OMICRON][0] = 'O';
    map[PI][0] = 'P';
    map[RHO][0] = 'R';
    map[SIGMA][0] = 'S';
    map[TAU][0] = 'T';
    map[UPSILON][0] = 'Y';
    map[PHI][0] = 'F';
    map[CHI][0] = 'X';
    map[OMEGA][0] = 'W';

    /* map small non-accented letters */
    map[LOW_ALPHA][0] = 'a';
    map[LOW_BETA][0] = 'v';
    map[LOW_GAMMA][0] = 'g';
    map[LOW_DELTA][0] = 'd';
    map[LOW_EPSILON][0] = 'e';
    map[LOW_ZETA][0] = 'z';
    map[LOW_ETA][0] = 'h';
    map[LOW_THETA][0] = '8';
    map[LOW_IOTA][0] = 'i';
    map[LOW_KAPPA][0] = 'k';
    map[LOW_LAMBDA][0] = 'l';
    map[LOW_MU][0] = 'm';
    map[LOW_NU][0] = 'n';
    map[LOW_OMICRON][0] = 'o';
    map[LOW_PI][0] = 'p';
    map[LOW_RHO][0] = 'r';
    map[LOW_FINAL_SIGMA][0] = 's';
    map[LOW_SIGMA][0] = 's';
    map[LOW_TAU][0] = 't';
    map[LOW_UPSILON][0] = 'y';
    map[LOW_PHI][0] = 'f';
    map[LOW_CHI][0] = 'x';
    map[LOW_OMEGA][0] = 'w';		

    /* map double letters */
    map[XI][0] = 'K';
    map[XI][1] = 'S';
    map[PSI][0] = 'P';
    map[PSI][1] = 'S';
    map[LOW_XI][0] = 'k';
    map[LOW_XI][1] = 's';
    map[LOW_PSI][0] = 'p';
    map[LOW_PSI][1] = 's';

    /* map accented letters*/
    map[ALPHA_ACC][0] = QUOTE;
    map[ALPHA_ACC][1] = 'A';
    map[LOW_ALPHA_ACC][0] = 'a';
    map[LOW_ALPHA_ACC][1] = QUOTE;
    map[EPSILON_ACC][0] = QUOTE;
    map[EPSILON_ACC][1] = 'E';
    map[LOW_EPSILON_ACC][0] = 'e';
    map[LOW_EPSILON_ACC][1] = QUOTE;
    map[ETA_ACC][0] = QUOTE;
    map[ETA_ACC][1] = 'H';
    map[LOW_ETA_ACC][0] = 'h';
    map[LOW_ETA_ACC][1] = QUOTE;
    map[IOTA_ACC][0] = QUOTE;
    map[IOTA_ACC][1] = 'I';
    map[LOW_IOTA_ACC][0] = 'i';
    map[LOW_IOTA_ACC][1] = QUOTE;
    map[OMICRON_ACC][0] = QUOTE;
    map[OMICRON_ACC][1] = 'O';
    map[LOW_OMICRON_ACC][0] = 'o';
    map[LOW_OMICRON_ACC][1] = QUOTE;
    map[OMEGA_ACC][0] = QUOTE;
    map[OMEGA_ACC][1] = 'W';
    map[LOW_OMEGA_ACC][0] = 'w';
    map[LOW_OMEGA_ACC][1] = QUOTE;
    map[UPSILON_ACC][0] = QUOTE;
    map[UPSILON_ACC][1] = 'Y';
    map[LOW_UPSILON_ACC][0] = 'y';
    map[LOW_UPSILON_ACC][1] = QUOTE;

    /* map dlalytika letters */
    map[LOW_IOTA_DIA][0] = 'i';
    map[LOW_IOTA_DIA][1] = DOUBLE_QUOTE;
    map[LOW_IOTA_ACC_DIA][0] = 'i';
    map[LOW_IOTA_ACC_DIA][1] = QUOTE;
    map[LOW_IOTA_ACC_DIA][2] = DOUBLE_QUOTE;
    map[LOW_UPSILON_DIA][0] = 'y';
    map[LOW_UPSILON_DIA][1] = DOUBLE_QUOTE;
    map[LOW_UPSILON_ACC_DIA][0] = 'y';
    map[LOW_UPSILON_ACC_DIA][1] = QUOTE;
    map[LOW_UPSILON_ACC_DIA][2] = DOUBLE_QUOTE;
}


/* print_char

Prints 1 or 2 or 3 ISO8859-1 characters based on
the conversion rules from ISO8859-7 to ISO8859-1.

Parameters:
ch: ASCII code of an ISO8859-7 char
map: 256x3 char array that has the conversion rules to ISO8859-1

Returns: void */
void print_char(int ch, char map[NUM_CHARS][CHAR_SIZE]) {
    putchar(map[ch][0]);
    if (map[ch][1] != '\0') { 
        putchar(map[ch][1]);
        if (map[ch][2] != '\0') 
            putchar(map[ch][2]);
    }
}

/* FSM

Has 5 states and detects whether a character is the first or second
character of any of the greek double letters:
MU-PI, MU-LOW_PI
NU-TAU, NU-LOW_TAU
LOW_MU-PI, LOW_MU-LOW_PI
LOW_NU-TAU, LOW_NU-LOW_TAU

States;
FSM_MU: FSM read a MU.
FSM_NU: FSM read a NU.
FSM_LOW_MU: FSM read a LOW_MU.
FSM_LOW_NU: FSM read LOW_NU.
FSM_DEFAULT: FSM read none of the above characters */
enum FSM {FSM_MU, FSM_NU, FSM_LOW_MU, FSM_LOW_NU, FSM_DEFAULT};


/* actions_default

Called when FSM is in state FSM_DEFAULT and a character is read.
Prints the converted character only when the character
is not the first letter of any of the greek double letters (see code)

Parameters:
ch: ASCII code of an ISO8859-7 char
map: 256x3 char array that has the conversion rules to ISO8859-1 */
enum FSM actions_default(int ch, char map[NUM_CHARS][CHAR_SIZE]) {
    enum FSM state = FSM_DEFAULT;
    switch(ch) {
        case MU:
            state = FSM_MU;
            break;
        case NU:
            state = FSM_NU;
            break;
        case LOW_MU:
            state = FSM_LOW_MU;
            break;
        case LOW_NU:
            state = FSM_LOW_NU;
            break;
        default:
            state = FSM_DEFAULT;
            print_char(ch, map);
    }
    return state;
}

/* actions_MU

Called when FSM is in state FSM_MU and a character is read.
One or two converted characters are printed (see code)

Parameters:
ch: ASCII code of an ISO8859-7 char
map: 256x3 char array that has the conversion rules to ISO8859-1 */
enum FSM actions_MU(int ch, char map[NUM_CHARS][CHAR_SIZE]) {
    enum FSM state = FSM_MU;
    switch(ch) {
        case PI: case LOW_PI:
            putchar('B');
            state = FSM_DEFAULT;
            break;
        case MU:
            putchar('M');
            state = FSM_MU;
            break;
        case LOW_MU:
            putchar('M');
            state = FSM_LOW_MU;
            break;
        default:
            putchar('M');
            print_char(ch, map);
            state = FSM_DEFAULT;
    }
    return state;
}

/* actions_NU

Called when FSM is in state FSM_NU and a character is read.
One or two converted characters are printed (see code)

Parameters:
ch: ASCII code of an ISO8859-7 char
map: 256x3 char array that has the conversion rules to ISO8859-1 */
enum FSM actions_NU(int ch, char map[NUM_CHARS][CHAR_SIZE]) {
    enum FSM state = FSM_NU;
    switch (ch) {
        case TAU: case LOW_TAU:
            putchar('D');
            state = FSM_DEFAULT;
            break;
        case NU:
            putchar('N');
            state = FSM_NU;
            break;
        case LOW_NU:
            putchar('N');
            state = FSM_LOW_NU;
            break;
        default:
            putchar('N');
            print_char(ch, map);
            state = FSM_DEFAULT;
    }
    return state;
}

/* actions_LOW_MU

Called when FSM is in state FSM_LOW_MU and a character is read.
One or two converted characters are printed (see code)

Parameters:
ch: ASCII code of an ISO8859-7 char
map: 256x3 char array that has the conversion rules to ISO8859-1 */
enum FSM actions_LOW_MU(int ch, char map[NUM_CHARS][CHAR_SIZE]) {
    enum FSM state = FSM_LOW_MU;
    switch (ch) {
        case PI: case LOW_PI:
            putchar('b');
            state = FSM_DEFAULT;
            break;
        case MU:
            putchar('m');
            state = FSM_MU;
            break;
        case LOW_MU:
            putchar('m');
            state = FSM_LOW_MU;
            break;
        default:
            putchar('m');
            print_char(ch, map);
            state = FSM_DEFAULT;
    }
    return state;
}

/* actions_LOW_NU

Called when FSM is in state FSM_LOW_NU and a character is read.
One or two converted characters are printed (see code)

Parameters:
ch: ASCII code of an ISO8859-7 char
map: 256x3 char array that has the conversion rules to ISO8859-1 */
enum FSM actions_LOW_NU(int ch, char map[NUM_CHARS][CHAR_SIZE]) {
    enum FSM state = FSM_LOW_NU;
    switch (ch) {
        case TAU: case LOW_TAU:
            putchar('d');
            state = FSM_DEFAULT;
            break;
        case NU:
            putchar('n');
            state = FSM_NU;
            break;
        case LOW_NU:
            putchar('n');
            state = FSM_LOW_NU;
            break;
        default:
            putchar('n');
            print_char(ch, map);
            state = FSM_DEFAULT;
    }
    return state;
}

/* main

Reads ISO8859-7 characters characters from standard input, converts
them to ISO8859-1, and writes the result to standard output */
int main() {
    /* ASCII code for the ISO8859-7 characters */
    int ch;

    /* The conversion rules from ISO8859-7 to ISO8859-1 */
    char map_array[NUM_CHARS][CHAR_SIZE];

    /* Initialize the FSM */
    enum FSM state = FSM_DEFAULT;

    /* All the FSM functions control the FSM state */
    enum FSM (*actions[])(int, char [NUM_CHARS][CHAR_SIZE]) =
    {
        actions_MU, actions_NU, actions_LOW_MU, actions_LOW_NU, actions_default
    };

    /* Initialize the conversion rules */
    map_init(map_array);

    /* Read input and print the converted characters */
    while ((ch = getchar()) != EOF) {
        state = actions[state](ch, map_array);
    }

    return 0;
}