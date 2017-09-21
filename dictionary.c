/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// typedef struct node{
//     bool islast;
//     struct node *children[27];
// }node;

node *root = NULL;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    //printf("%s \n", word);
    //printf("Check %d", root->islast);
    //printf("Okay...");
    //printf("Test");
    node *current;
        //printf("Test");
    if(root != NULL){
        current = root;
    }else{
        return false;
    }
    for(int i = 0; word[i] != '\0'; i++){
        int index = 0;
        char c = word[i];
        if(c >= 65 && c <= 90){
            index = c - 65;
        }else if(word[i] >= 97 && word[i] <= 122){
            index = c - 97;
        }else{
            return false;
        }
        //printf("%c %i ", word[i], index);
        if(current->children[index] != NULL){
            //printf("%d", current->islast);
            current = current->children[index];
        }else{
            return false;
        }
    }
    if(current->islast == true){
        //printf("\n%s Exists\n", word);
        return true;
    }else{
        return false;

    }
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    root = malloc(sizeof(node));
    root->islast = true;
    
    FILE* dfile = fopen("dictionaries/large", "r");
    //printf("File Loading");
    if(dfile == NULL){
        return false;
    }
    
    node *current = root;
    //node *prev = root;
    
    char c = fgetc(dfile);
    int index = 0;
    for(int i = 0; c != EOF; i++){
        if(c == '\n'){
            current->islast = true;
            current = root;
            i = 0;
        }else{
            index = c - 97;
            //printf("%i , %i, %c\n",i , index, c);
            if(current->children[index] == NULL){
                current->children[index] = malloc(sizeof(node));
            }
            //prev = current;
            current = current->children[index];
        }
        c = fgetc(dfile);
    }
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
