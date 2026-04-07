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
void permutations(int cnt) {
    cout << "d permuttt, nilai cnt: " << cnt << endl;
    int i;
    if (running_count == characters_count) {
        cout << "masuk running_count = characters_count, nilai running count: " << running_count << ", permutasi: " << running << endl;
        printf("%s\n", running);
    } else {
        for (i=0; i<characters_count; i++) {
            cout << "di dalam for, nilai cnt: " << cnt << ", nilai i: " << i << ", nilai bitmask: " << bitmask << ", nilai bitmask >> i: " << (bitmask >> i) << endl;
            if ( ((bitmask>>i)&1) == 0 ) {
                cout << "masuk, ketika nilai i: " << i << ", nilai characters[i]: " << characters[i] << ", nilai running_count: " << running_count << endl;
                running[running_count] = characters[i];
                bitmask |= (1<<i);
                running_count = running_count + 1;
                cout << "sebelum dijalankann permutations, nilai i: " << i << ", nilai bitmask: " << bitmask << ", nilai running_count: " << running_count << endl;
                permutations(cnt + 1);
                running_count = running_count - 1;
                bitmask &= ~(1<<i);
                cout << "setelah dijalankan permutations, nilai i: " << i << ", nilai bitmask: " << bitmask << ", nilai running_count: " << running_count << endl;
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

    permutations(0);

    free(characters);
    free(running);
}
