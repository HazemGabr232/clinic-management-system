#ifndef PATIENT_H
#define PATIENT_H
#include "types.h"
#include <stdbool.h>
	
#define DATE1 "2:00"
#define DATE2 "2:30"
#define DATE3 "3:00"
#define DATE4 "3:30"
#define DATE5 "4:00"


typedef struct node_type patient ;

struct node_type {
	s16 id ;
	char name[40] ;
	s16 age ;
	char gender[20];
	char reservation[5];
	patient* next_patient ;

};

typedef struct{
        s16 id ;
        char name[40] ;
        s16 age ;
        char gender[20];
        char reservation[5];
}data;

void add_patient(data newdata);
void edit_patient(data newdata);
void reserve(s16 id , char reservation[5]);
void cancle_reservation(s16 id);
void view_reservations();         //user mode 
void view_patient_record(s16 id); //user mode

#endif
