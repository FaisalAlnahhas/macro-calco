//
//  macrosCalculator.c
//  
//
//  Created by Faisal Alnahhas on 10/17/17.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int activity_level = 0;
int weight = 0;
int p, c, choice, write_file, modified_calories;
long f;

//char name[80];

/*void write_to_file(char *fp)
{
    time_t rawtime;
    char buffer [255];
    
    time (&rawtime);
    sprintf(buffer,"time: %s",ctime(&rawtime) );
    // Lets convert space to _ in
    char *pt = buffer;
    for (; *pt; ++pt)
    {
        if (*pt  == ' ')
            *pt  = '_';
    }

    char str[80];
    strcpy(str, name);
    strcat(str, " 's macros_");
    strcat(str, buffer);
    strcat(str, ".txt");
    //strcat(str, "concatenated.");
    
    FILE *fw = fopen(str, "ab");
    if (fw != NULL)
    {
        fputs("Thank you for choosing MacroCalco.\n", fw);
        fprintf(fw, "Protein: %d grams\n", p);
        fprintf(fw, "Carbs: %d grams\n", c);
        fprintf(fw, "Fats: %ld grams\n", f);
        fputs("\n", fw);
        fputs("Happy Gains\n", fw);
    }

    fclose(fw);
    
    free(str);
    
    FILE *fp = fopen(filepath, "ab");
    if (fp != NULL)
    {
        fputs(data, fp);
        fclose(fp);
    }
} */


void bulk(int al)
{
    int calories;
    if (al == 1)
    {
        calories = weight * 12;
    }
    else if(al == 2)
    {
        calories = weight * 13;
    }
    else if(al == 3)
    {
        calories = weight * 14;
    }
    
    else
    {
        printf("You're too strong for MacroCalco\n");
        printf("Good bye! ");
        exit(0);
    }
    modified_calories = calories + 300;
    p = weight;
    int p_cals = 4 * p;
    f = 0.6 * weight;
    int f_cals = f * 9;
    int c_cals = modified_calories - (f_cals + p_cals);
    c = c_cals / 4;
    printf("based on your input to bulk you need to increase your maintaince caloric intake to: %d and the breakdown of your macros is as follows:\n", modified_calories);
    printf("\n");
    printf("Protein calories: %d, which is about %d grams\n", p_cals, p);
    printf("\n");
    printf("Carbohydrates calories: %d, which is about %d grams\n", c_cals, c);
    printf("\n");
    printf("fat calories: %d, which is about %ld grams\n", f_cals, f);
    printf("\n");
}

void maintain(int al)
{
    int calories;
    if (al == 1)
    {
        calories = weight * 12;
    }
    else if(al == 2)
    {
        calories = weight * 13;
    }
    else if(al == 3)
    {
        calories = weight * 14;
    }
    
    else
    {
        printf("You're too strong for MacroCalco\n");
        printf("Good bye!");
        exit(0);
    }
    modified_calories = calories;
    p = weight;
    int p_cals = 4 * p;
    f = 0.5 * weight;
    int f_cals = f * 9;
    int c_cals = modified_calories - (f_cals + p_cals);
    c = c_cals / 4;
    printf("based on your input to maintain you need to increase your maintaince caloric intake to: %d and the breakdown of your macros is as follows:\n", modified_calories);
    printf("\n");
    printf("Protein calories: %d, which is about %d grams\n", p_cals, p);
    printf("\n");
    printf("Carbohydrates calories: %d, which is about %d grams\n", c_cals, c);
    printf("\n");
    printf("fat calories: %d, which is about %ld grams\n", f_cals, f);
    printf("\n");
}

void slim(int al)
{
    int calories;
    if (al == 1)
    {
        calories = weight * 12;
    }
    else if(al == 2)
    {
        calories = weight * 13;
    }
    else if(al == 3)
    {
        calories = weight * 14;
    }
    
    else
    {
        printf("You're too strong for MacroCalco\n");
        printf("Good bye!");
        exit(0);
    }
    modified_calories = calories - 300;
    p = weight;
    int p_cals = 4 * p;
    f = 0.5 * weight;
    int f_cals = f * 9;
    int c_cals = modified_calories - (f_cals + p_cals);
    c = c_cals / 4;
    printf("based on your input to slim you need to increase your maintaince caloric intake to: %d and the breakdown of your macros is as follows:\n", modified_calories);
    printf("\n");
    printf("Protein calories: %d, which is about %d grams\n", p_cals, p);
    printf("\n");
    printf("Carbohydrates calories: %d, which is about %d grams\n", c_cals, c);
    printf("\n");
    printf("fat calories: %d, which is about %ld grams\n", f_cals, f);
    printf("\n");
}

void helper()
{
    printf("AWESOME, let's carry on..\n");
    sleep(1);
    printf("What is your weight in lbs: ");
    scanf("%d", &weight);
    printf("Noted.\n");
    sleep(1);
    printf("Now tell me what is your activity level? Enter 1, 2, or 3 (3 being a very active lifestyle): ");
    scanf("%d", &activity_level);
}

int main()
{
   /* time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    strftime(s, sizeof(s), "%c", tm);
    printf("%s\n", s); */
    
    char *file;
    time_t rawtime;
    char buffer2 [255];
    
    time (&rawtime);
    sprintf(buffer2,"time: %s",ctime(&rawtime) );
    strcpy(buffer2, ctime(&rawtime));
    printf("%s", buffer2);
    
    char * name = (char*) malloc( sizeof(name) );
    printf("Hello I am your friend MacroCalco!\n");
    printf("I am a tool you can use to learn how much protein, fat, and carbohydrates you should eat a day to achieve your fitness goals.\n");
    printf("When prompted to type in your name be sure to type the same name every time you run the executable file.\n");
top:
    printf("\n");
//TODO: change 0 to q
    printf("Before we begin, you can hit 0 to exit this program at anytime.\n");
    printf("\n");
    printf("What would you like to accomplish: bulk(1), maintain(2), or slim(3)?\n");
    printf("Enter 1, 2, or 3 to choose a plan: ");
    scanf("%d", &choice);
    if(choice == 0)
    {
        printf("\n");
        printf("Thank you for using MacroCalco, and happy gains :)\n");
        exit(0);

    }

    else if(choice == 1)
    {
        helper();
        bulk(activity_level);
        
    }
    else if(choice == 2)
    {
        helper();
        maintain(activity_level);
    }
    else if(choice == 3)
    {
        helper();
        slim(activity_level);
    }
    else
    {
        printf("\n");
        printf("The program is still developing once when we have more options we'll let you choose one, in the meantime please enter a valid option.\n");
        goto top;
    }
    
    printf("Would you like to record this information in a text file: Yes(1), No(2): ");
    scanf("%d", &write_file);
    if(write_file == 1)
    {
        printf("Please type in your name: ");
        scanf ("%s", name);
        printf("\n");
        printf("\n");
        printf("Producing file.. \n");
        
        time_t rawtime;
        char buffer [255];
        
        time (&rawtime);
        //sprintf(buffer,"time: %s",ctime(&rawtime) );
        // Lets convert space to _ in
        char *pt = buffer;
        for (; *pt; ++pt)
        {
            if (*pt  == ' ')
                *pt  = '_';
        }
        
        char str[80];
        strcpy(str, name);
        strcat(str, " 's macros");
        strcat(str, buffer);
        strcat(str, ".txt");
        //strcat(str, "concatenated.");
        
        FILE *fw = fopen(str, "ab");
        if (fw != NULL)
        {
            fputs("Thank you for choosing MacroCalco.\n", fw);
            fprintf(fw, "Your macros for: %s", ctime(&rawtime));
            fputs("\n", fw);
            fprintf(fw, "Caloric intake: %d, which is broken into: \n", modified_calories);
            fprintf(fw, "Protein: %d grams\n", p);
            fprintf(fw, "Carbs: %d grams\n", c);
            fprintf(fw, "Fats: %ld grams\n", f);
            fputs("\n", fw);
            fputs("Happy Gains\n", fw);
            fputs("\n", fw);
        }
        
        fclose(fw);
        
        
        sleep(1);
        printf("Done!\n");
        //sleep(1);
        printf("\n");
        printf("Thank you for using MacroCalco, and happy gains :)\n");
    }
    else
    {
        printf("Maybe next time.\n");
    }
    free(name);
    return 0;
}
