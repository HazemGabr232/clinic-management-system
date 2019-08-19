#include <stdio.h>
#include "patient.h"
#include "types.h"

#define PASS 1234

void user_mode();
void admin_mode();

void main(void){
	s16 mode=0;
	begining:
        printf("0: to halt\n");
	printf("1: user mode\n");
        printf("2: admin mode\n>>");
	fflush(stdin);
	scanf("%hi", &mode);
	switch(mode){
		case 0: 
			return;
		case 1:
			user_mode();
			mode = 0;
			goto begining;
			break;
		case 2:
			admin_mode();
			mode = 0;
			goto begining;
			break;
	}
}

void user_mode(){
	s16 command = 0;
	s16 id;
	printf("0: go back\n");
	printf("1: view reservations\n");
        printf("2: view patient record\n>>");
	fflush(stdin);
	scanf("%hi", &command);
        switch(command){
                case 0:
                        return;
                case 1:
                        view_reservations();
                        break;
                case 2:
			printf("enter id:\n>>");
                        fflush(stdin);
			scanf("%hi", &id);
			view_patient_record(id);
                        break;
        }
}

void admin_mode(){
	char reservation[5];
	s16 id;
	s16 pass;
	s16 count = 0;
	data new_data;
	s16 command;
        printf("enter password:\n>>");
	try_again:
        if (count == 3){
                printf("no more tries\n");
                return;
        }
	fflush(stdin);
	scanf("%hi", &pass);	
	if (pass!=PASS){
		printf("try again\n>>");
		count++;
		goto try_again;

	}
	else{
	        printf("0: go back\n");
        	printf("1: add patient\n");
        	printf("2: edit patient\n");
                printf("3: reserve\n");
                printf("4: cancle reservation\n>>");
        	fflush(stdin);
        	scanf("%hi", &command);
        	switch(command){
                	case 0:
                        	return;
                        case 1:
                                printf("enter id:\n>>");
                                fflush(stdin);
                                scanf("%hi", &(new_data.id));
                                printf("enter name:\n>>");
                                fflush(stdin);
                                scanf("%s", new_data.name);
                                printf("enter age:\n>>");
                                fflush(stdin);
                                scanf("%hi", &(new_data.age));
                                printf("enter gender:\n>>");
                                fflush(stdin);
                                scanf("%s", new_data.gender);
                                add_patient(new_data);
                                break;

			case 2:
                                printf("enter id:\n>>");
                                fflush(stdin);
                                scanf("%hi", &(new_data.id));
                                printf("enter name:\n>>");
                                fflush(stdin);
                                scanf("%s", new_data.name);
                                printf("enter age:\n>>");
                                fflush(stdin);
                                scanf("%hi", &(new_data.age));
                                printf("enter gender:\n>>");
                                fflush(stdin);
                                scanf("%s", new_data.gender);
				edit_patient(new_data);
				break;
	
                	case 3:
                                printf("enter id:\n>>");
                                fflush(stdin);
                                scanf("%hi", &id);
                                printf("enter requiered time:\n>>");
                                fflush(stdin);
                                scanf("%s", reservation);
				reserve(id, reservation);
                        	break;
                	case 4:
                        	printf("enter id:\n>>");
                        	fflush(stdin);
                        	scanf("%hi", &id);
                        	cancle_reservation(id);
                        	break;
	        }


	}
}
