//
// Created by 44811 on 2019/5/22.
//

#include <stdio.h>
#include <stdlib.h>


struct Student {
    int num;
    int virtue;
    int talent;
};

int compare(const void *elem1, const void *elem2) {
    struct Student *a, *b;
    a = (struct Student *) elem1;
    b = (struct Student *) elem2;
    if (a->virtue + a->talent < b->virtue + b->talent)
        return 1;
    else if (a->virtue + a->talent == b->virtue + b->talent && a->virtue < b->virtue)
        return 1;
    else if (a->virtue + a->talent == b->virtue + b->talent && a->virtue == b->virtue && a->num > b->num)
        return 1;
    else
        return -1;
}

//void sort(struct Student *students, int num) {
//    struct Student temp;
//    for (int i = 0; i < num; i++) {
//        int flag = 0;
//        for (int j = 0; j < num - i - 1; ++j) {
//            if (students[j].talent + students[j].virtue < students[j + 1].talent + students[j + 1].virtue) {
//                temp = students[j];
//                students[j] = students[j + 1];
//                students[j + 1] = temp;
//                flag = 1;
//            }
//            if (students[j].talent + students[j].virtue == students[j + 1].talent + students[j + 1].virtue &&
//                students[j].virtue < students[j + 1].virtue) {
//                temp = students[j];
//                students[j] = students[j + 1];
//                students[j + 1] = temp;
//                flag = 1;
//            }
//            if (students[j].talent + students[j].virtue == students[j + 1].talent + students[j + 1].virtue &&
//                students[j].virtue == students[j + 1].virtue && students[j].num > students[j + 1].num) {
//                temp = students[j];
//                students[j] = students[j + 1];
//                students[j + 1] = temp;
//                flag = 1;
//            }
//        }
//        if (flag == 0)
//            return;
//    }
//}


int main() {
    int N, L, H;
    scanf("%d %d %d", &N, &L, &H);
    struct Student *students = malloc(sizeof(struct Student) * N);
    struct Student *firstStudents = malloc(sizeof(struct Student) * N);
    struct Student *secondStudents = malloc(sizeof(struct Student) * N);
    struct Student *thirdStudents = malloc(sizeof(struct Student) * N);
    struct Student *fourthStudents = malloc(sizeof(struct Student) * N);
    for (int i = 0; i < N; ++i)
        scanf("%d %d %d", &students[i].num, &students[i].virtue, &students[i].talent);
    int firstCount = 0, secondCount = 0, thirdCount = 0, fourthCount = 0;
    for (int j = 0; j < N; ++j) {
        if (students[j].talent >= H && students[j].virtue >= H) {
            firstStudents[firstCount] = students[j];
            firstCount++;
        } else if (students[j].talent >= L && students[j].talent < H && students[j].virtue >= H) {
            secondStudents[secondCount] = students[j];
            secondCount++;
        } else if (students[j].talent >= L && students[j].virtue < H && students[j].virtue >= students[j].talent) {
            thirdStudents[thirdCount] = students[j];
            thirdCount++;
        } else if (students[j].virtue >= L && students[j].talent > students[j].virtue) {
            fourthStudents[fourthCount] = students[j];
            fourthCount++;
        }
    }
    qsort(firstStudents, firstCount, sizeof(firstStudents[0]), compare);
    qsort(secondStudents, secondCount, sizeof(secondStudents[0]), compare);
    qsort(thirdStudents, thirdCount, sizeof(thirdStudents[0]), compare);
    qsort(fourthStudents, fourthCount, sizeof(fourthStudents[0]), compare);
//    sort(firstStudents, firstCount);
//    sort(secondStudents, secondCount);
//    sort(thirdStudents, thirdCount);
//    sort(fourthStudents, fourthCount);
    printf("%d\n", firstCount + secondCount + thirdCount + fourthCount);
    for (int i = 0; i < firstCount; ++i)
        printf("%d %d %d\n", firstStudents[i].num, firstStudents[i].virtue, firstStudents[i].talent);
    for (int i = 0; i < secondCount; ++i)
        printf("%d %d %d\n", secondStudents[i].num, secondStudents[i].virtue, secondStudents[i].talent);
    for (int i = 0; i < thirdCount; ++i)
        printf("%d %d %d\n", thirdStudents[i].num, thirdStudents[i].virtue, thirdStudents[i].talent);
    for (int i = 0; i < fourthCount; ++i)
        printf("%d %d %d\n", fourthStudents[i].num, fourthStudents[i].virtue, fourthStudents[i].talent);
    return 0;
}