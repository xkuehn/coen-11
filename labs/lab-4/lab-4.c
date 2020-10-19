#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define N_GENDERS 3
#define N_SYMPTOMS 10
#define N_INTS 2
#define MAX_ITS 10000

char * genders[N_GENDERS] = {"M", "F", "O"};
char * symptoms[N_SYMPTOMS] = {
   "Coughing", 
    "Sneezing", 
    "Headache", 
    "Fever", 
    "Soreness", 
    "Allergies", 
    "Light-Headed", 
    "Itchy", 
    "Shivers", 
    "Shortness of Breath"
};

// double gender_wait[N_GENDERS] = {0, 0, 0};
// // double * p_gender_wait = gender_wait;
// double symptom_wait[N_SYMPTOMS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
// // double * p_symptom_wait = symptom_wait;

// int gender_count[N_GENDERS] = {0, 0, 0};
// // int * p_gender_count = gender_count;
// int symptom_count[N_SYMPTOMS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
// // int * p_symptom_count = symptom_count;
int ** queue;

int turned_away = 0;
int cur_patient = 0;
int num_patients = 0;
int total_its = 0;
int times_full = 0;

// int * p_turned_away = &turned_away;
// int * p_cur_patient = &cur_patient;
// int * p_num_patients = &num_patients;
// int * p_total_its = &total_its;
// int * p_times_full = &times_full;

//function declarations
void add(int gender_code, int symptom_code, const int maxsize);
void experiment(int maxsize, double retest);
void next();
void print();

//main function checks for user input to begin experiment, prints out total number of iterations, number of patients turned away and number of times list was full
int main(const int argc, const char ** argv){

    srand((int)time(NULL));

    if (argc != 3){
        fprintf(stderr, "   Invalid program usage.\n");
        fprintf(stderr, "   Usage: lab4 <queue_maxsize> <retest_chance>\n");
        return 1;
    }

    if (atoi(argv[1]) <= 0 || atof(argv[2]) > 1.0 || atof(argv[2]) < 0.0) {
        fprintf(stderr, "   Invalid program usage.\n");
        fprintf(stderr, "   <queue_maxsize>: greater than 0, <retest_chance>: between 0 and 1\n");
        return 1;
    }

    //get queue size
    int maxsize = atoi(argv[1]);
    printf("    Requested queue size: %d\n", maxsize);

    //get retest chance
    double retest = atof(argv[2]);
    printf("    Requested retest chance: %.2lf\n", retest);

    //allocate memory for the queue
    //allocate outer pointer array
    queue = (int **)malloc(maxsize * sizeof(int *));

    //allocated inner pointer array
    for (int i = 0; i < maxsize; i++){
        queue[i] = (int *)malloc(N_INTS * sizeof(int));
    }

    //start experiment
    experiment(maxsize, retest);

    //print results
    print();

    //free dynamically allocated memory
    for (int i = 0; i < maxsize; i++){
        free(queue[i]);
    }

    free(queue);

    return 0;
}

//adds patient to queue with gender and symptom
void add(int gen_code, int symp_code, const int maxsize){
    
	if(cur_patient == maxsize){
	    turned_away++;
		times_full++;
        //printf("%s\n", "List is full!");
        return;
    }

    //printf("Adding someone to: %d\n", cur_patient);
        
    queue[cur_patient][0] = gen_code;
    queue[cur_patient][1] = symp_code;
    cur_patient += 1;
    num_patients += 1;

    return;
}

//removes first patient in queue and moves everyone after up the list by one spot
void next(){

    if(num_patients <= 0){
        //printf("%s\n", "List is empty!");
        return;
    }

    //printf("Removing someone from: %d\n", cur_patient);

    int att_index = 0;
    int pat_index = 0;
    for(int i = 1; i < cur_patient; i++){
        for(int j = 0; j < 2; j++){
            queue[pat_index][att_index] = queue[i][j];
            att_index += 1;
        }
        pat_index += 1;
        att_index = 0;
    }
    cur_patient -= 1;

    return;
}

void print(){

    // //wait time for male
    // double male_avg = gender_wait[0]/gender_count[0];
    // printf("Average wait time for %s: %.1lfs\n", genders[0], male_avg);
    // //wait time for female
    // double female_avg = gender_wait[1]/gender_count[1];
    // printf("Average wait time for %s: %.1lfs\n", genders[1], female_avg);
    // //wait time for other
    // double other_avg = gender_wait[2]/gender_count[2];
    // printf("Average wait time for %s: %.1lfs\n", genders[2], other_avg);
        
    // //wait time for symptoms
    // printf("\n<Symptom>, <Average wait time>\n");
    // for(int i = 0; i < N_SYMPTOMS; i++){
    //     double symptom_avg = symptom_wait[i]/symptom_count[i];
    //     printf("%s, %.1lfs\n", symptoms[i], symptom_avg);
    // }

    //print extra stats
    printf("%d\n", turned_away);
    return;
}

//loops the experiment N times checking conditions and then calling correct functions: add(), next()
void experiment(int maxsize, double retest){

    while(total_its < MAX_ITS){
        int gen_code = rand() % 3;
        // int * p_gen_code = &gen_code;
        int symp_code = rand() % 10;
        // int * p_symp_code = &symp_code;
        int add_chance = rand() % 100 + 1;
        // int * p_add_chance = &add_chance;

        //printf("%d", add_chance);

        if(add_chance > 50){
            add(gen_code, symp_code, maxsize);
            total_its += 1;
            continue;
        } else {
         //    double wait_time = (double)rand()/RAND_MAX*30.0;
         //    // *(p_gender_wait + gen_code) += wait_time;
         //    gender_wait[gen_code] += wait_time;
         //    // *(p_symptom_wait + symp_code) += wait_time;
         //    symptom_wait[symp_code] += wait_time;
         //    // *(p_gender_count + gen_code) += 1;
        	// gender_count[gen_code] += 1;
         //    // *(p_symptom_count + symp_code) += 1;
        	// symptom_count[symp_code] += 1;
                        
		    int back_chance = rand() % 100 + 1;
            if(back_chance > retest*100){
                //printf("Added patient back to: %d\n", cur_patient);
                next();
                add(gen_code, symp_code, maxsize);
                total_its += 1;
                continue;
            }
            next();
            total_its += 1;
            continue;
        }
    }
    return;
}

