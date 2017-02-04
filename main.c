/*
 partial

 Author:
      Jhon Valencia jhonvalencia314@gmail.com



 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <string.h>
#include "utils.h"

int main (int argc, char *argv[])
{
	if ((argc > 4) || (argc == 1)){
		printf("Wrong usage, check partial -h or partial --help\n");
		return 1;
	}
	char* hel = "-h";
	char* hel2 = "--help";
	char* second = argv[1];
    if ((strcmp(second, hel) == 0) || (strcmp(second, hel2) == 0)){
        print_usage();
        return 0;
    }
    long counter = 0;
    long initialByte = 1;
    long lastByte = 0;
    char* FILENAME;
    if (argc == 2){
        FILENAME = argv[1];
    }
    if (argc == 3){
        initialByte = str2long(argv[1]);
        FILENAME = argv[2];
    }
    if (argc == 4){
        initialByte = str2long(argv[1]);
        lastByte = str2long(argv[2]);
        FILENAME = argv[3];
    }

    FILE *file = fopen(FILENAME, "rt");
    if (file == NULL){
        printf("ERROR: Unable to read file.\n");
        return 1;
    }
    fseek(file, 0, SEEK_END);
    long fileLen=ftell(file);
    fseek(file, 0, SEEK_SET);
    if (argc != 4){
        lastByte = fileLen;
    }

    // Check sanity
    if (initialByte <= 0){
        printf("ERROR: First byte must be greater than 1\n");
        return 1;
    }

    if (lastByte < initialByte){
        printf("ERROR, initial byte must be lower than final byte.\n");
        return 1;
    }

        // Check file not greater than lastByte
    if (lastByte > fileLen){
        printf("ERROR: %li greater than file size=%li\n", lastByte, fileLen);
        return 1;
    }


    int c;
    //Read and printing file:
    initialByte = initialByte - 1;
    while (counter < lastByte){
        c = getc(file);
        if ((counter >= initialByte) && (counter <= lastByte)){
            printf("%c", c);
        }
        counter++;
    }
    fclose(file);
	return 0;
}

