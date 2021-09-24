#include "ncurses_display.h"
#include "system.h"
#include <string>
#include <iostream>

int main() {
  System system;
  NCursesDisplay::Display(system);
}
