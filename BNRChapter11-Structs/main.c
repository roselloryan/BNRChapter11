//
//  main.c
//  BNRChapter11-Structs

#include <stdio.h>
#include <time.h>

// Declare struct.
//struct Person {
//    float heightInMeters;
//    int weightInKilos;
//};

// Declare typedef struct.
typedef struct {
    float heightInMeters;
    int weightInKilos;
} Person;


float bodyMassIndex(Person p) {
    
    return p.weightInKilos / (p.heightInMeters * p.heightInMeters);
}

int main(int argc, const char * argv[]) {
 
    // non-typdef
//    struct Person mikey;
//    mikey.heightInMeters = 1.7;
//    mikey.weightInKilos = 96;
//    
//    struct Person aaron;
//    aaron.heightInMeters = 1.97;
//    aaron.weightInKilos = 84;
    
    // typedef
    Person mikey;
    mikey.heightInMeters = 1.7;
    mikey.weightInKilos = 96;
    
    Person aaron;
    aaron.heightInMeters = 1.97;
    aaron.weightInKilos = 84;
    
    printf("mikey is %.2f meters tall\n", mikey.heightInMeters);
    printf("mikey weighs %.2d kilograms\n", mikey.weightInKilos);
    printf("aaron is %.2f meters tall\n", aaron.heightInMeters);
    printf("aaron weighs %.2d kilograms\n\n\n", aaron.weightInKilos);
    
    float bmi;
    bmi = bodyMassIndex(mikey);
    printf("mikey has a bmi of %.2f\n", bmi);
    
    bmi = bodyMassIndex(aaron);
    printf("aaron has a bmi of %.2f\n\n", bmi);
    
    long secondsSince1970 = time(NULL);
    printf("It has been %ld seconds since 1970\n", secondsSince1970);
    
    struct tm now;
    localtime_r(&secondsSince1970, &now);
    printf("The time is %d:%d:%d\n", now.tm_hour, now.tm_min, now.tm_sec);
    
    
    // Add 4 million seconds to the time in seconds
    secondsSince1970 = secondsSince1970 + 4000000000;
    printf("It will have been %ld seconds since 1970 in 4,000,000,000 seconds.\n", secondsSince1970);
    
    struct tm nowPlusFourMillionSeconds;
    localtime_r(&secondsSince1970, &nowPlusFourMillionSeconds);
    printf("The date will be %d:%d:%d in 4 million seconds.\n", nowPlusFourMillionSeconds.tm_mon + 1, nowPlusFourMillionSeconds.tm_mday, nowPlusFourMillionSeconds.tm_year + 1900);
    
    
    
    
    return 0;
}
