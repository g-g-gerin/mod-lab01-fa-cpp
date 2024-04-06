// Copyright 2022 UNN-IASR
#include <cctype>
#include <cstring>
#include <cmath>
#include "fun.h"

unsigned int faStr1(const char *inputString) {
    unsigned int countValidWords = 0;
    bool isWord = false;
    bool hasDigit = false;

    while (*inputString) {
        if (std::isalpha(*inputString)) {
            if (!isWord) {
                isWord = true;
                hasDigit = false;
            }
        } else if (std::isdigit(*inputString)) {
            if (isWord) {
                hasDigit = true;
            }
        } else {
            if (isWord && !hasDigit) {
                ++countValidWords;
            }
            isWord = false;
        }
        ++inputString;
    }

    if (isWord && !hasDigit) {
        ++countValidWords;
    }

    return countValidWords;
}

unsigned int faStr2(const char *inputString) {
    unsigned int countCapitalizedWords = 0;
    bool isCapitalizedWord = false;

    while (*inputString) {
        if (std::isupper(*inputString) && !isCapitalizedWord) {
            isCapitalizedWord = true;
            ++inputString;
            while (std::islower(*inputString)) {
                ++inputString;
            }
            if (*inputString == '\0' || *inputString == ' ') {
                countCapitalizedWords++;
            }
            isCapitalizedWord = false;
        } else if (!std::isalpha(*inputString)) {
            isCapitalizedWord = false;
        }
        if (*inputString) ++inputString;
    }
    return countCapitalizedWords;
}

unsigned int faStr3(const char *inputString) {
    unsigned int totalWords = 0, totalChars = 0, wordLength = 0;

    while (*inputString) {
        if (isalpha(*inputString)) {
            ++wordLength;
        } else if (wordLength > 0) {
            ++totalWords;
            totalChars += wordLength;
            wordLength = 0;
        }
        ++inputString;
    }

    if (wordLength > 0) {
        ++totalWords;
        totalChars += wordLength;
    }

    if (totalWords == 0) return 0;

    double avgLength = static_cast<double>(totalChars) / totalWords;
    return static_cast<unsigned int>(avgLength + 0.5);
}
