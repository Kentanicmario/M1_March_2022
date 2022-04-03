#include "header.h"
#include "func_decl.h"

extern struct vehicle *parkinfo[10][10];
extern int vehicle_count;
extern int fourwheeler_count;
extern int twowheeler_count;

int main()
{
    int choice, type, number, row = 0, col = 0;
    int i, tarr[2];
    int finish = 1;
    int tries = 0;
    char uname[10], pword[10];

    system("cls||clear") ;

    do {
        printf("LOGIN TO PORTAL");
        printf("\n\n\tUSERNAME:- ");
        scanf("%s", uname);
        printf("\tPASSWORD:- ");
        scanf("%s", pword);
        if (login(uname, pword))
        {
            printf("\n\tLOGIN SUCCESSFUL!!!");
            printf("\n\tPress 'Enter' to main menu");
            flushinp();
            getchar();
            break;
        }
        else
        {
            printf("\n\tLOGIN UNSUCESSFUL!!!");
            tries++;
            flushinp();
            getchar();
        }
    } while (tries <= 2);

    if (tries > 2)
    {
        printf("\nWrong username and password for 2 times!!!.\n");
        printf("Press 'Enter' to exit program.");
        flushinp();
        getchar();
        return 0;
    }
    system("cls||clear");

    while (finish)
    {
        system("cls||clear") ;
        printf(" VEHICLE PARKING MANAGEMENT \n");
        printf("\n\t1>> Arrival Vehicle\n");
        printf("\n\t2>> Total No. Of Vehicles,4-wheelers,2-wheelers Parked\n");
        printf("\n\t3>> Display of parked Vehicle\n");
        printf("\n\t4>> Departure Vehicle\n");
        printf("\n\t5>> Exit\n");
        printf("\n\n Enter Your Choice: ");

        scanf("%d", &choice);
        system("cls||clear") ;

        switch (choice)
        {
            case 1:
                printf("ADD VEHICLE:\n");

                do {
                    printf("\tEnter vehicle type (1 for 4-Wheeler / 2 for 2-Wheeler): ");
                    scanf("%d", &type);
                    if (!valid_vehicle_type(type))
                        printf("\nInvalid vehicle type.\n");
                } while (!valid_vehicle_type(type));

                printf("\tEnter your vehicle number: ");
                scanf("%d", &number);

                if (valid_vehicle_type(type))
                {
                    get_free_rowcol(type, tarr);
                    if (tarr[0] != -1 && tarr[1] != -1)
                    {
                        row = tarr[0];
                        col = tarr[1];
                        parkinfo[row][col] = add(type, number, row, col);
                    }
                    else
                    {
                        printf("\nNo parking slot available for %s\n", TYPE[type]);
                    }
                }
                else
                {
                    printf("Invalid type\n");
                    break;
                }
                printf("\nPress any key to next step");
                flushinp();
                getchar();
                break;
            case 2:
                system("cls||clear") ;
                printf("Total Vehicles Parked: %d\nTotal 4-wheelers Parked: %d\n"
                       "Total 2-wheelers parked: %d\n", vehicle_count, fourwheeler_count, twowheeler_count);
                printf("\nPress any key to next step");
                flushinp();
                getchar();
                break;
            case 3:
                system("cls||clear") ;
                printf("Display\n");
                display();
                printf("\nPress any key to next step");
                flushinp();
                getchar();
                break;
            case 4:
                system("cls||clear") ;
                printf("Departure\n");
                type = 0;

                flushinp();

                do {
                    printf("\tEnter vehicle type (1 for 4-Wheeler / 2 for 2-Wheeler): ");
                    scanf("%d", &type);
                    if (!valid_vehicle_type(type))
                        printf("\nInvalid vehicle type.\n");
                } while (!valid_vehicle_type(type));

                printf("\tEnter your vehicle number: ");
                scanf("%d", &number);

                if (valid_vehicle_type(type))
                {
                    get_rowcol_by_number(type, number, tarr);
                    if (tarr[0] != -1 && tarr[1] != -1)
                    {
                        col = tarr[1];
                        if (type == FOUR_WHEELER) {
                            row = tarr[0];
                            fourwheeler_count --;
                        } else {
                            row = tarr[0] - 5;
                            twowheeler_count --;
                        }
                        vehicle_count --;

                        parkinfo[row][col] = 0;
                        for (i = col; i < 9; i++)
                        {
                            parkinfo[row][i] = parkinfo[row][i + 1];
                        }
                        parkinfo[row][i] = 0;
                    }
                    else
                    {
                        printf("\nInvalid %s number, or no %s with number %d parked.\n", TYPE[type], TYPE[type], number);
                    }
                }
                printf("\nPress 'Enter' to main menu\n");
                flushinp();
                getchar();
                break;
            case 5:
                system("cls||clear") ;
                finish = 0;
                break;
            default:
                printf("Invalid Choice");
        }
    }
    return 0;
}
