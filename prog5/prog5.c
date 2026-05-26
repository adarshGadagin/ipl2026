#include <stdio.h>

union decision {
    unsigned char flags;
    struct field {
    unsigned int your_choice:1; /* tobe computed */
    int your_mothers_choice:1;
    int your_fathers_choice:1;
    int socially_acceptable:1;
    unsigned int financially_viable:1;
    int do_you_aptitude:1;
    int do_you_likeit:1;
    unsigned int decision:1; /* to be computed */
    }bits;
};

union decision input();
/* Write an expression that closely matches how you make decision */
void make_decision(union decision *d);
/* Print a nice narrative*/
void print_decsion(union decision d);
/* think of an interesting use for flags and printt an interpretaion based on the number stored in flags */
void print_conclusion_based_on_flags( union decision d);

int main(){
    union decision d;

    d.bits.your_mothers_choice = 1;
    d.bits.your_fathers_choice = 0;
    d.bits.socially_acceptable = 1;
    d.bits.financially_viable = 1;
    d.bits.do_you_aptitude = 1;
    d.bits.do_you_likeit = 1;

    d.bits.your_choice=
        d.bits.do_you_likeit && 
        (d.bits.your_fathers_choice || 
        d.bits.your_mothers_choice);

    d.bits.decision=
        d.bits.your_choice &&
        d.bits.financially_viable &&
        d.bits.do_you_aptitude;

    printf("Your choice: %u\n",d.bits.your_choice);
    printf("Financial viable: %u\n",d.bits.financially_viable);
    printf("Final decision: %u\n",d.bits.decision);

    printf("Flag = %u\n",d.flags);

    return 0;
}