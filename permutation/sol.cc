#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int bitmask;
char* characters;
int characters_count;
char* running;
int running_count;
void permutations() {
    cout << "masuk permut, nilai bitmask: " << bitmask << ", nilai running_count: " << running_count << ", dan nilai characters_count: " << characters_count << endl;
    int i;
    if (running_count == characters_count) {
        printf("%s\n", running);
    } else {
        for (i=0; i<characters_count; i++) {
            cout << "nilai i: " << i << ", nilai bitmask: " << bitmask << ", nilai bitmask >> i: " << (bitmask >> i) << endl;
            if ( ((bitmask>>i)&1) == 0 ) {
                cout << "masuk, ketika nilai i: " << i << ", nilai 1 << i: " << (1<<i) << ", nilai characters[i]: " << characters[i] << ", nilai running_count: " << running_count << endl;
                running[running_count] = characters[i];
                bitmask |= (1<<i);
                running_count = running_count + 1;
                permutations();
                running_count = running_count - 1;
            }
            cout << "akhir untuk nilai i: " << i << ", nilai bitmask: " << bitmask << ", nilai running_count: " << running_count << endl << endl;
        }
    }
}

main() {
    int i;
    int cases;

    characters = (char*)malloc(sizeof(char)*30);
    scanf("%s", characters);
    characters_count = strlen(characters);

    running = (char*)malloc(sizeof(char)*30);
    memset(running, 0, 30);
    running_count = 0;

    permutations();

    free(characters);
    free(running);
}
