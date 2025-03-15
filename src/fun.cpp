// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include "cmath"
#include <cctype>

unsigned int faStr1(const char *str) {
    if (str == nullptr) {
        return 0;
    }
    bool in_word = false;
    bool without_numbers = true;
    int words_without_numbers = 0;
    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            in_word = false;
            without_numbers = true;
        } else {
            if (!in_word) {
                in_word = true;
            }
            if (str[i] >= '0' && str[i] <= '9' && without_numbers) {
                without_numbers = false;
            }
            if ((str[i + 1] == ' ' || str[i + 1] == '\0') && in_word && without_numbers) {
                words_without_numbers++;
            }
        }
    }
    return words_without_numbers;
}

unsigned int faStr2(const char *str) {
    if (str == nullptr) {
        return 0;
    }
    bool in_word = false;
    bool small_letters_only = true;
    int normal_words = 0;
    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            in_word = false;
            small_letters_only = true;
        } else {
            if (!in_word) {
                in_word = true;
                if (str[i] < 'A' || str[i] > 'Z') {
                    small_letters_only = false;
                }
            } else {
                if (str[i] < 'a' || str[i] > 'z') {
                    small_letters_only = false;
                }
            }
            if ((str[i + 1] == ' ' || str[i + 1] == '\0') && in_word && small_letters_only) {
                normal_words++;
            }
        }
    }
    return normal_words;
}

unsigned int faStr3(const char *str)
{
    if (str == nullptr) {
        return 0;
    }
    bool in_word = false;
    int number_of_letters = 0;
    int number_of_words = 0;
    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            in_word = false;
        } else {
            if (!in_word) {
                in_word = true;
            }
            number_of_letters++;
            if ((str[i + 1] == ' ' || str[i + 1] == '\0') && in_word) {
                number_of_words++;
            }
        }
    }
    return std::round(static_cast<double>(number_of_letters) / number_of_words);
}
