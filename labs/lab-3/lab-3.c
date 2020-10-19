#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define Q_MAX 50
#define N_GENDERS 3
#define N_SYMPTOMS 10
#define SYMPTOM_LENGTH 20
#define MAX_ITS 10000

char genders[N_GENDERS] = {'M', 'F', 'O'};
char symptoms[N_SYMPTOMS][20] = {"Coughing", "Sneezing", "Headache", "Fever", "Soreness", "Allergies", "Light-Headed", "Itchy", "Shivers", "Shortness of Breath"};

double gender_wait[N_GENDERS] = {0, 0, 0};
double symptom_wait[N_SYMPTOMS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int gender_count[N_GENDERS] = {0, 0, 0};
int symptom_count[N_SYMPTOMS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int queue[Q_MAX][2];

int turned_away = 0;
int cur_patient = 0;
int num_patients = 0;
int total_its = 0;
int times_full = 0;

//adds patient to queue with gender and symptom
void add(int gen_code, int symp_code){
	if(cur_patient > Q_MAX){
	    turned_away++;
		times_full++;
        printf("%s\n", "List is full!");
        return;
    }
        
    queue[cur_patient][0] = gen_code;
    queue[cur_patient][1] = symp_code;
    cur_patient += 1;
    num_patients += 1;

    return;
}

//removes first patient in queue and moves everyone after up the list by one spot
void next(){
    
    if(num_patients <= 0){
        printf("%s\n", "List is empty!");
    }

    int att_index = 0;
    int pat_index = 0;
    for(int i = 1; i < cur_patient; i++){
        for(int j = 0; j < 2; j++){
            queue[pat_index][att_index] = queue[i][j];
            att_index += 1;
        }
        cur_patient -= 1;
        pat_index += 1;
        att_index = 0;
    }
    return;
}

void print(){

    //wait time for male
    double male_avg = gender_wait[0]/gender_count[0];
    printf("Average wait time for Males: %.1lfs\n", male_avg);
    //wait time for female
    double female_avg = gender_wait[1]/gender_count[1];
    printf("Average wait time for Females: %.1lfs\n", female_avg);
    //wait time for other
    double other_avg = gender_wait[2]/gender_count[2];
    printf("Average wait time for Others: %.1lfs\n", other_avg);
        
    //wait time for symptoms
    printf("\n<Symptom>, <Average wait time>\n");
    for(int i = 0; i < N_SYMPTOMS; i++){
        double symptom_avg = symptom_wait[i]/symptom_count[i];
        printf("%s, %.1lfs\n", symptoms[i], symptom_avg);
    }
    return;
}

//loops the experiment 10,000 times checking conditions and then calling correct functions: add(), next()
void experiment(){

    while(total_its < MAX_ITS){
        int gen_code = rand() % 3;
        int symp_code = rand() % 10;
        int add_chance = rand() % 100 + 1;

        if(add_chance > 50){
            add(gen_code, symp_code);
            total_its += 1;
            continue;
        } else {
            double wait_time = (double)rand()/RAND_MAX*30.0;
            gender_wait[gen_code] += wait_time;
            symptom_wait[symp_code] += wait_time;
        	gender_count[gen_code] += 1;
        	symptom_count[symp_code] += 1;
                        
		    int back_chance = rand() % 100 + 1;
            if(back_chance > 85){
                next();
                add(gen_code, symp_code);
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

//main function checks for user input to begin experiment, prints out total number of iterations, number of patients turned away and number of times list was full
int main(void){

    srand((int)time(NULL));

    printf("Press 's' to begin experiment.\n");
    char command;
    scanf("%c", &command);

    if(command == 's'){
            experiment();
    } else {
        printf("Command not excepted. Press 's' to begin experiment.\n");
    }

    print();

	return 0;
}
