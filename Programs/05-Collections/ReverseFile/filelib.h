/*
 * File: filelib.h
 * ---------------
 * This patched version of filelib.h makes it possible to include the
 * code for readEntireFile even though it is defined in the system
 * version of filelib.h.
 */

#include "private/../filelib.h"
#define readEntireFile readEntireFileX
