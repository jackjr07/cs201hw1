/*Jack Wanitkun CS201
 * HW 1
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

/*array of strings constaining: "The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"
 *Totally is 9 words
 * */

//Constants
const int MAX = 9;

//Create the random index for char
int createRandom(int i,int nums[MAX-1]){
    if(i == MAX) return nums;
    //srand(time(NULL));
    int random = (rand() % 10);
    if(i == 0){
        //printf("Passed i = 0");
        nums[i] = random;
        ++i;
        return createRandom(i, nums);
    };
    int check = checkNum(nums, random);
    //printf("Check: %d\n", check);
    if(check == 0){
        //srand(time(NULL));
        random = (rand() % 10);
        //printf("Re: %d\n", random);
        return createRandom(i, nums);
    }else{
        //printf("Hit: %d\n", random);
        nums[i] = random;
        ++i;
        return createRandom(i, nums);
    }
};

//Check does the random number is duplicated
int checkNum(int nums[MAX], int curr){
    for(int i = 0; i<MAX; ++i){
        if(nums[i] == curr){
            return 0;
        }
    }
    return 1;
}

//Start the game. Print out the text from random index. Then Scan the input and compare to the task
int startGame(char ** words, int nums[MAX-1], int i, int scores){
    //Base cases
    if(i > MAX) return 0;
    if(nums[i] == 9) return startGame(words, nums, ++i, scores);
    //Print out the task word
    printf("Type: %s >> \n", words[nums[i]]);

    char * hold = NULL;
    int inputSize;
    getline(&hold, &inputSize, stdin);
    printf("Test: %s", hold);
    
    scores =  scoreGame(words[nums[i]], hold);
    if(scores) ++scores;
    printf("Score: %d", scores);

    return startGame(words, nums, ++i, scores);
}

int scoreGame(char * words, char * hold){
    if(words == NULL || hold == NULL) return 0;
    if(strcmp(words, hold) == 0) return 1; 
    else return 0;
}


int main(){
    //Initialized values
    char * words[] = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    int i = 0;
    int nums[MAX-1];
    srand(time(NULL));

    printf("Jack Wanitkun CS201 HW1\n");

    createRandom(0, nums);
    for(int j = 0; j< MAX; ++j){
        printf("Test: %d\n", nums[j]);
    }
    startGame(words, nums, 0, 0);



    return 0;
}
