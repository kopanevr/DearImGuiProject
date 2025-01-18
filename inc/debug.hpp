#pragma once

#ifndef NDEBUG
#define DEBUG_PRINT(msg, ...)       std::cout << msg << ": " __VA_ARGS__ << "\n"
#else
#define DEBUG_PRINT(msg, ...)
#endif
