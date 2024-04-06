// Copyright 2022 UNN-IASR
#include <cctype>
#include <cstring>
#include <cmath>
#include "fun.h"

// Функция для подсчета слов без цифр в строке
unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool isWord = false;

    while (*str) {
        if (!std::isdigit(*str) && !std::isspace(*str)) {
            if (!isWord) {
                isWord = true;
            }
        } else if (std::isspace(*str)) {
            if (isWord) {
                count++;
                isWord = false;
            }
        } else if (std::isdigit(*str)) {
            isWord = false;
            while (*str && !std::isspace(*str)) {
                str++;
            }
        }

        str++;
    }

    if (isWord) {
        count++;
    }

    return count;
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
