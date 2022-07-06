#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wordsinsentence(char **x) {
    int w = 0;
    while (*x) {
        w += 1;
        x++;
    }
    return w;
}

int wordsinmono(char ***x) {
    int w = 0;
    while (*x) {
        w += wordsinsentence(*x);
        x++;
    }
    return w;
}

int wordsinbio(char ****x) {
    int w = 0;
    while (*x) {
        w += wordsinmono(*x);
        x++;
    }
    return w;
}

int wordsinlib(char *****x) {
    int w = 0;
    while (*x) {
        w += wordsinbio(*x);
        x++;
    }
    return w;
}

int wordsinlol(char ******x) {
    int w = 0;
    while (*x) {
        w += wordsinlib(*x);
        x++;
    }
    return w;
}

int main(void) {
    char *word;
    char **sentence;
    char ***monologue;
    char ****biography;
    char *****biolibrary;
    char ******lol;

    //fill data structure
    word = malloc(4 * sizeof *word); // assume it worked
    strcpy(word, "foo");

    sentence = malloc(4 * sizeof *sentence); // assume it worked
    sentence[0] = word;
    sentence[1] = word;
    sentence[2] = word;
    sentence[3] = NULL;

    monologue = malloc(4 * sizeof *monologue); // assume it worked
    monologue[0] = sentence;
    monologue[1] = sentence;
    monologue[2] = sentence;
    monologue[3] = NULL;

    biography = malloc(4 * sizeof *biography); // assume it worked
    biography[0] = monologue;
    biography[1] = monologue;
    biography[2] = monologue;
    biography[3] = NULL;

    biolibrary = malloc(4 * sizeof *biolibrary); // assume it worked
    biolibrary[0] = biography;
    biolibrary[1] = biography;
    biolibrary[2] = biography;
    biolibrary[3] = NULL;

    lol = malloc(4 * sizeof *lol); // assume it worked
    lol[0] = biolibrary;
    lol[1] = biolibrary;
    lol[2] = biolibrary;
    lol[3] = NULL;

    printf("total words in my lol: %d\n", wordsinlol(lol));

    free(lol);
    free(biolibrary);
    free(biography);
    free(monologue);
    free(sentence);
    free(word);
}
