#include <stdlib.h>

int get_word_count(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);

char **strtow(char *str, char *delims) {
    int wc, i = 0, n = 0, wordLen;
    char **words;

    if (str == NULL || delims == NULL)
        return NULL;

    wc = get_word_count(str, delims);
    if (wc == 0)
        return NULL;

    words = malloc((wc + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;

    while (i < wc) {
        while (is_delim(*str, delims))
            str++;

        wordLen = get_word_length(str, delims);

        words[i] = malloc((wordLen + 1) * sizeof(char));
        if (words[i] == NULL) {
            while (i >= 0)
                free(words[i--]);
            free(words);
            return NULL;
        }

        n = 0;
        while (n < wordLen)
            words[i][n++] = *(str++);
        words[i][n] = '\0'; /* Null-terminate the word */
        i++;
    }
    words[i] = NULL; /* Null-terminate the array */
    return words;
}

int get_word_count(char *str, char *delims) {
    int wc = 0, pending = 1;

    while (*str) {
        if (is_delim(*str, delims))
            pending = 1;
        else if (pending) {
            pending = 0;
            wc++;
        }
        str++;
    }
    return wc;
}

int get_word_length(char *str, char *delims) {
    int wLen = 0;

    while (*str && !is_delim(*str, delims)) {
        wLen++;
        str++;
    }
    return wLen;
}

int is_delim(char ch, char *delims) {
    while (*delims) {
        if (*delims++ == ch)
            return 1;
    }
    return 0;
}

