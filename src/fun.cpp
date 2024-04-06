// Copyright 2022 UNN-IASR
#include <cctype>
#include <cstring>
#include <cmath>
#include "fun.h"

unsigned int faStr1(const char *inputString) {
    unsigned int countValidWords = 0;
    bool isInWord = false;

    while (*inputString) {
        if (std::isalpha(*inputString) && !isInWord) {
            isInWord = true;
            while (std::isalpha(*inputString)) ++inputString;
            countValidWords += 1;
            isInWord = false;
        } else {
            if (!std::isalnum(*inputString)) {
                isInWord = false;
            }
            ++inputString;
        }
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
    unsigned int totalWordCount = 0;
    unsigned int totalCharacters = 0;
    unsigned int currentWordLength = 0;

    while (*inputString) {
        if (std::isalpha(*inputString)) {
            currentWordLength++;
        } else if (currentWordLength > 0) {
            totalWordCount++;
            totalCharacters += currentWordLength;
            currentWordLength = 0;
        }
        ++inputString;
    }

    if (currentWordLength > 0) {
        totalWordCount++;
        totalCharacters += currentWordLength;
    }

    double averageLength = static_cast<double>(totalCharacters) / totalWordCount;
    unsigned int roundedAverage = static_cast<unsigned int>(round(averageLength));

    return roundedAverage;
}
}
