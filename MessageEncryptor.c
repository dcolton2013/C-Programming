/***************************************
 * File:   MessageEncryptor.c
 * Author: Donovan Colton
 *
 * Created on October 4, 2016, 3:39 PM
 ***************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    //array letrers hold original string
    //encrypted hold strirng after shift
    char letters[80];
    char encrypted[80];

    //
    char c = '?';
    int index = 0;
    int shift = 0;

    //take in value to be encrypted
    printf("Enter message to be encrypted: ");
    while ((c = getchar()) != '\n'){
        if ('A'<=c || c <= 'z'){
            letters[index++] = c;
        }
    }

    //take in shift
    printf("Enter shift amount: ");
    scanf("%d", &shift);

    //make shift
    //only encrypt letters, digits remain the same
    for (int i = 0; i < index ; i++){
        int letter = letters[i];
        //only encrpyte alphabetic chars
        if (letter < 'z' && letter > 'A'){
            //encrypt uppercase char
            if (letter <= 'Z'){
                encrypted[i] = ((letter - 'A')+shift)%26 +'A';
            }
            //encrpyt lowercase char
            else
                encrypted[i] = ((letter - 'a')+shift)%26 +'a';
            //add nonalphabetic char to array
        }else{
            encrypted[i] = letters[i];
        }
    }

    for (int i = 0; i < index; i++){
        printf("%c",encrypted[i]);
    }
	printf("\n");
    return (EXIT_SUCCESS);
}
