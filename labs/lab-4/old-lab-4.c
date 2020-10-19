#include <stdio.h>    /** defines the printf function */
#include <stdlib.h>   /** defines the rand function */
#include <time.h>     /** defines the time function */

/* function prototypes */
int add(short gender, short symptom);
int next(short *gender, short *symptom);
void experiment();

/* global variables */
char * genders[6] = {
    "Male",
    "Female",
    "Trans",
    "Bigender",
    "Non-binary",
    "Rather not say"
};
#define NGENDERS 6

char * symptoms[12] = {
    "Headache",
    "High fever",
    "Unusual cold hands and feet",
    "Severe muscle pain",
    "Severe joint pain",
    "Seizures",
    "Stiff neck",
    "Vomiting",
    "Broken bone",
    "Bleeding",
    "Unresponsive",
    "Chest pain"
};
#define NSYMPTOMS 12
#define NREPEAT 10000

#define MAXSIZE 50
short gender_queue[MAXSIZE];
short symptom_queue[MAXSIZE];
int start = 0;
int size = 0;

double gender_times[NGENDERS];
double symptom_times[NSYMPTOMS];

int gender_counts[NGENDERS];
int symptom_counts[NSYMPTOMS];
int turned_away = 0;

/**
 * Lab 03: Wait queue simulation
 * @return int Zero for success
 */
int main()
{
    // Initialize the pseudo-random generator
    srand((int) time(NULL));

    // Initialize the global variables
    for(int i=0; i < MAXSIZE; ++i){
        gender_queue[i] = 0;
        symptom_queue[i] = 0;
    }
    for(int i=0; i < NGENDERS; ++i){
        gender_times[i] = 0.0;
        gender_counts[i] = 0;
    }
    for(int i=0; i < NSYMPTOMS; ++i){
        symptom_times[i] = 0.0;
        symptom_counts[i] = 0;
    }

    // Execute the experiment
    for(int i=0; i < NREPEAT; ++i){
        experiment();
    }

    // Output the results table
    printf("Gender/Symptom, Mean Wait\n");
    for(int i=0; i < NGENDERS; ++i){
        printf("%s, %.4f\n", genders[i], gender_times[i] / gender_counts[i]);
    }
    for(int i=0; i < NSYMPTOMS; ++i){
        printf("%s, %.4f\n", symptoms[i], symptom_times[i] / symptom_counts[i]);
    }
    printf("Number turned away, %d\n", turned_away);

    return EXIT_SUCCESS;
}

/**
 * Add a patient described by a given gender code and symptom code to the queue
 * @param  gender  Gender code for the patient
 * @param  symptom Symptom code for the patient
 * @return         0 if success, 1 if queue is full.
 */
int add(short gender, short symptom){
    int end = (start + size) % MAXSIZE;
    if (size == MAXSIZE){
        return 1;
    }
    gender_queue[end] = gender;
    symptom_queue[end] = symptom;
    size++;
    return 0;
}

/**
 * Return the next patient and remove them from the queue.
 * @param  gender  Pointer for place to store next patient gender code
 * @param  symptom Pointer for place to store next patient symptom code
 * @return         0 if success, 1 if queue was empty.
 */
int next(short *gender, short *symptom){
    if (size == 0){
        return 1;
    }
    *gender = gender_queue[start];
    *symptom = symptom_queue[start];
    start = (start + 1) % MAXSIZE;
    size--;
    return 0;
}

/**
 * Execute one round of the experiment
 */
void experiment(){
    short gender, symptom;
    /* choose random number between 1 and 100 */
    int ichoice = (int) (rand() % 100 + 1);
    /* add or remove patient */
    if(ichoice > 50){
        gender = (short) (rand() % NGENDERS);
        symptom = (short) (rand() % NSYMPTOMS);
        turned_away += add(gender, symptom);
    } else {
        int no_next = next(&gender, &symptom);
        if(!no_next){
            double wait_time = rand() % 30 + 1.0;
            gender_times[gender] += wait_time;
            gender_counts[gender]++;
            symptom_times[symptom] += wait_time;
            symptom_counts[symptom]++;
            ichoice = (int) (rand() % 100 + 1);
            if(ichoice > 85){
                add(gender, symptom);
            }
        }
    }
}