#include "patient.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static patient* head =NULL;
static s16 node_count=0;
bool date1f=0, date2f=0, date3f=0, date4f=0, date5f=0 ;

/* private functions*/
patient * get_patient(s16 id);
bool is_id_existed(s16 id);

void add_patient(data newdata){
	if (is_id_existed(newdata.id)){
		printf("id is already existed, try to edit\n");
		return;
	}
	patient* last;
	if(node_count == 0){
		head = (patient*)malloc(sizeof(patient));
		head->id = newdata.id;
		strcpy(head->name, newdata.name);
		head->age = newdata.age;
		strcpy(head->gender, newdata.gender);
		strcpy(head->reservation, newdata.reservation);
		head->next_patient= NULL;
		node_count++;
	}
	else{
		last=head;
		while(last->next_patient != NULL)
			last=last->next_patient;

		last->next_patient = (patient*)malloc(sizeof(patient));
                (last->next_patient)->id = newdata.id;
                strcpy((last->next_patient)->name, newdata.name);
                (last->next_patient)->age = newdata.age;
                strcpy((last->next_patient)->gender, newdata.gender);
                strcpy((last->next_patient)->reservation, newdata.reservation);
                (last->next_patient)->next_patient= NULL;
                node_count++;
	}
}

void edit_patient(data newdata){
	if(is_id_existed(newdata.id)==0){
		printf("id doesn't existed\n");
		return;
	}
	patient * some_patient =get_patient(newdata.id);
	strcpy(some_patient->name, newdata.name);
        some_patient->age = newdata.age;
        strcpy(some_patient->gender, newdata.gender);
        strcpy(some_patient->reservation, newdata.reservation);


}

void reserve(s16 id, char reservation[5]){
        if(is_id_existed(id)==0){
                printf("id doesn't existed\n");
                return;
        }
        patient* some_patient =get_patient(id);
	if (strcmp(reservation,DATE1) == 0 && date1f == 0){
		strcpy(some_patient->reservation, reservation);
		date1f=1;
		printf("reserved\n");
		return;
	}
        if (strcmp(reservation,DATE2) == 0 && date2f == 0){
                strcpy(some_patient->reservation, reservation);
                date2f=1;
                printf("reserved\n");
                return;
        }
        if (strcmp(reservation,DATE3) == 0 && date3f == 0){
                strcpy(some_patient->reservation, reservation);
                date3f=1;
                printf("reserved\n");
                return;
        }
        if (strcmp(reservation,DATE4) == 0 && date4f == 0){
                strcpy(some_patient->reservation, reservation);
                date4f=1;
                printf("reserved\n");
                return;
        }
        if (strcmp(reservation,DATE5) == 0 && date5f == 0){
                strcpy(some_patient->reservation, reservation);
                date5f=1;
                printf("reserved\n");
                return;
        }
	printf("that date is not available\n");
	return;
}

void cancle_reservation(s16 id){
	patient * some_patient = get_patient(id);
        if (strcmp(some_patient->reservation,DATE1) == 0){
        	date1f=0;
        }
        if (strcmp(some_patient->reservation,DATE2) == 0){
                date2f=0;
        }
        if (strcmp(some_patient->reservation,DATE3) == 0){
                date3f=0;
        }
        if (strcmp(some_patient->reservation,DATE4) == 0){
                date4f=0;
        }
        if (strcmp(some_patient->reservation,DATE5) == 0){
                date5f=0;
        }


	strcpy(some_patient->reservation, "none");
	
}

void view_reservations(){
        patient* last = head;
        while(last != NULL){
	        if (strcmp(last->reservation,DATE1) == 0){
        	        printf("date1: %d\n",last->id);
       		}
        	if (strcmp(last->reservation,DATE2) == 0){
                        printf("date2: %d\n",last->id);
        	}
        	if (strcmp(last->reservation,DATE3) == 0){
                	printf("date3: %d\n",last->id);
        	}
        	if (strcmp(last->reservation,DATE4) == 0){
                	printf("date4: %d\n",last->id);
        	}
        	if (strcmp(last->reservation,DATE5) == 0){
                	printf("date5: %d\n",last->id);
        	}
		last=last->next_patient;
	}

}

void view_patient_record(s16 id){
        patient * some_patient;
	some_patient = get_patient(id);
	printf("patient name: %s\n" ,some_patient->name);
        printf("patient age: %d\n" ,some_patient->age);
        printf("patient gender: %s\n" ,some_patient->gender);
        printf("patient reservation: %s\n" ,some_patient->reservation);
}

/*private functions definition*/
bool is_id_existed(s16 id){
	patient* last = head;
	while(last != NULL){
		if (last->id == id)
			return 1;   //true if id already existed
		else
			last = last->next_patient;
	}
	return 0; //if doesn't existed
}

patient * get_patient(s16 id){
       patient * last = head;
        while(last != NULL){
                if (last->id == id)
                        return last;   //true if id already existed
                else
                        last = last->next_patient;
        }
        return 0; //if doesn't existed
}

