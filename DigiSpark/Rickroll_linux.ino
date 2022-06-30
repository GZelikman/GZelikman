//Rickroll your friends, if they have linux! 

#include "./GermanKeyboard.h"
void setup() {
}

void loop() {
 DigiKeyboard.sendKeyStroke(0);
 DigiKeyboard.delay(500);
 DigiKeyboard.sendKeyStroke(KEY_T, MOD_ALT_LEFT | MOD_CONTROL_LEFT);
 DigiKeyboard.delay(4000);
 pn("xdg-open https://www.youtube.com/watch?v=dQw4w9WgXcQ&ab_channel=RickAstley");
 DigiKeyboard.sendKeyStroke(KEY_ENTER);
 DigiKeyboard.delay(8000);
 DigiKeyboard.sendKeyStroke(KEY_SPACE);
 for (;;) {}
}