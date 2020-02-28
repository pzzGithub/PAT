//
// Created by 44811 on 2020/1/13.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct time {
    int hour;
    int minute;
    int second;
} time;

typedef struct record {
    char ID[16];
    time inTime;
    time outTime;
} record;

int time2second(time t) {
    return (t.hour * 60 + t.minute) * 60 + t.second;
}

int main() {
    int N;
    int unlockedIndex = 0, lockedIndex = 0;
    scanf("%d", &N);
    record *records = (record *) malloc(sizeof(record) * N);
    for (int i = 0; i < N; i++) {
        scanf("%s", records[i].ID);
        scanf("%d:%d:%d %d:%d:%d", &records[i].inTime.hour, &records[i].inTime.minute, &records[i].inTime.second,
              &records[i].outTime.hour, &records[i].outTime.minute, &records[i].outTime.second);
    }

    for (int i = 0; i < N; i++) {
        if (time2second(records[i].inTime) < time2second(records[unlockedIndex].inTime))
            unlockedIndex = i;
        if (time2second(records[i].outTime) > time2second(records[lockedIndex].outTime))
            lockedIndex = i;
    }

    printf("%s %s", records[unlockedIndex].ID, records[lockedIndex].ID);
    return 0;
}