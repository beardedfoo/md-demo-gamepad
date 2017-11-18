#include <genesis.h> // gendev 0.3.0

// Show a different message for each button on the gamepad
char * msg = "?";

void joyHandler(u16 joy, u16 changed, u16 state) {
  // Ignore input from anything except player one
  if (joy != JOY_1) {
    return;
  }

  // Choose a string to display based on the current input
  if (state & BUTTON_MODE) {
    msg = "M";
  } else if (state & BUTTON_START) {
    msg = "S";
  } else if (state & BUTTON_A) {
    msg = "A";
  } else if (state & BUTTON_B) {
    msg = "B";
  } else if (state & BUTTON_C) {
    msg = "C";
  } else if (state & BUTTON_X) {
    msg = "X";
  } else if (state & BUTTON_Y) {
    msg = "Y";
  } else if (state & BUTTON_Z) {
    msg = "Z";
  } else if (state & BUTTON_UP) {
    msg = "^";
  } else if (state & BUTTON_DOWN) {
    msg = "v";
  } else if (state & BUTTON_LEFT) {
    msg = "<";
  } else if (state & BUTTON_RIGHT) {
    msg = ">";
  } else {
    msg = "?";
  }
}

int main() {
  JOY_init();
  JOY_setEventHandler(&joyHandler);

  while(1)
  {
    // During the v-blanking period update the VDP with msg
    VDP_waitVSync();
    VDP_drawText(msg, 10, 13);
  }
}
