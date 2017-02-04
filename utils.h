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

#include <string.h>
#include <math.h>

long str2long(char *s){
    // Idea: Return numerical value like str2int()
    long i,n,temp,output = 0;
    n = strlen(s);
    for (i = 0; i < n; i++){
        temp = s[i] - 48;
        if (temp < 0 || temp > 9){
            return 0;
        }
        output = output + temp*pow(10, (n-1-i));
    }
    return output;
}

void print_usage(){
	printf("Show content from iByte to fByte of a file\n");
	printf("\tUsage: ");
	printf("partial iByte fByte FILENAME\n");
	printf("iByte = Initial byte (default 0), fByte =  Final byte (default last)\n");
}
