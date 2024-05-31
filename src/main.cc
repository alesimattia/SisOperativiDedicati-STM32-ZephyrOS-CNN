/**
----------------------------------------------------------------------
@author: Alesi Mattia s1114418
@project: CNN Person Detector su ZephyrOS
@cite: TensorFlow Lite for Microcontroller
----------------------------------------------------------------------
**/

#include "tensorflow/lite/micro/examples/person_detection/main_functions.h"

// This is the default main used on systems that have the standard C entry
// point. Other devices (for example FreeRTOS or ESP32) that have different
// requirements for entry code (like an app_main function) should specialize
// this main.cc file in a target-specific subfolder.
int main(int argc, char* argv[]) {
  setup();
  while (true) {
    loop();
  }
  return 0; //richiesto da specifiche C++ ZephyrOS
}
