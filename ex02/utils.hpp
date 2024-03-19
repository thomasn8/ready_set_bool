#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>

void printBlockMirror(size_t *block, size_t blockLength);
void printBlockValues(size_t *block, size_t blockLength);
void printSymmetricalAdditionDetails(size_t e, size_t n, size_t indexMirroredNumber, size_t * block);
size_t myPow(size_t base, size_t exponent);
size_t decimalToBinary(size_t n);