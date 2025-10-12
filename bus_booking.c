#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// location
char ch[10][130] = {"KL     -> Penang", "KL     -> Johor", "Penang -> KL", "Penang -> Johor", "Johor  -> KL", "Johor  -> Penang"};
// ticket holder's name
char name[32][100] = {'\0'};
char number[32][2] = {'\0'};
int num1[32] = {0};
int trno;

// struct
typedef struct
{
    char username[21];
    char password[16];
} Account;

// Function:
int registerAccount(Account accounts[], int *accountCount);
int login(Account accounts[], int accountCount);
void loadAccounts(Account accounts[], int *accountCount);
void booking();
void status_1(int trno);
void name_number(int booking, char numstr[100]);
int read_number(int trno);
void read_name(int trno);
void status();
void cancle();
void exitProgram();
// 清除输入流直到遇到新行或文件结束

int main()
{
    Account accounts[100]; // 假设最多100个账户
    int accountCount = 0;
    loadAccounts(accounts, &accountCount);

    int login_choice, seat_choice;
    int login_key;
    while (1)
    {
        printf("\n=================== Login Page ====================\n");
        printf("1. Register\n2. Login\n0. Exit\n");
        printf(">>Please enter the number of your choice (1~2) or 0 to exit: ");
        scanf("%d", &login_choice);

        switch(login_choice){
            case 1:
                login_key=registerAccount(accounts, &accountCount);
                break;
            case 2:
                login_key=login(accounts, accountCount);;
                break;
            case 0:
                exitProgram();
            default:
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("Err selection!!\nPls input again...\n");
        }
        int num, i;
        while (login_key == 1)
        {
            printf("\n==================== Home Page ====================\n");
            printf("1. Book Seat\n2. View Seats\n3. Cancel Booking\n4. Change Booking\n0. Exit\n");
            printf(">>Please enter the number of your choice (1~4) or 0 to exit: ");
            scanf("%d", &seat_choice);

            switch (seat_choice)
            {
            case 1:
                booking();
                // processPayment(&buses[0], &ticket);  // 处理支付并传递bus的引用
                break;
            case 2:
                status();
                break;
            case 3:
                cancle();
                break;
            case 4:
                // changeBooking(&buses[0]);
                break;
            case 0:
                // printTicket(ticket);
                exitProgram();
                break;
            default:
                printf("Invalid option\n");
            }
        }
    }
}
int registerAccount(Account accounts[], int *accountCount)
{
    char username[21], password[16];
    printf("\n===================================================\n");
    printf("Enter a new username (or enter 0 to exit): ");
    scanf("%20s", username);

        if (strcmp(username, "0") == 0)
        {
            printf("Back to Login Page...\n");
            return 0; // 用户输入0，退出登录
        }
    // 检查用户名是否已存在
    for (int i = 0; i < *accountCount; i++)
    {
        if (strcmp(accounts[i].username, username) == 0)
        {
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Username already exists.\n");
            printf("Back to Login Page...\n");
            return 0;
        }
    }

    printf("Enter a password: ");
    scanf("%15s", password);

    strcpy(accounts[*accountCount].username, username);
    strcpy(accounts[*accountCount].password, password);
    (*accountCount)++;

    // 保存到文件
    FILE *file = fopen("Acc.txt", "a");
    if (file != NULL)
    {
        fprintf(file, "%s %s\n", username, password);
        fclose(file);
        printf("\n===================================================\n");
        printf("Account saved!\n");
    }
    else
    {
        printf("Error opening file.\n");
    }

    printf("Registration successful!\nAuto Login...\n");
    return 1;
}
int login(Account accounts[], int accountCount)
{
    char username[21], password[16];

    while (1)
    {
        printf("Enter your username (or enter 0 to exit): ");
        scanf("%20s", username);

        if (strcmp(username, "0") == 0)
        {
            printf("Back to Login Page...\n");
            return 0; // 用户输入0，退出登录
        }

        printf("Enter your password: ");
        scanf("%15s", password);

        for (int i = 0; i < accountCount; i++)
        {
            if (strcmp(accounts[i].username, username) == 0 &&
                strcmp(accounts[i].password, password) == 0)
            {
                printf("\n===================================================\n");
                printf("\nLogin successful!\n");
                return 1; // 登录成功
                break;
            }
        }
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Invalid username or password.\n");
        printf("Pls enter again!\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    }

    return 0; // 登录失败
}
void loadAccounts(Account accounts[], int *accountCount)
{
    FILE *file = fopen("Acc.txt", "r");
    if (file != NULL)
    {
        while (fscanf(file, "%20s %15s", accounts[*accountCount].username,
                      accounts[*accountCount].password) == 2)
        {
            (*accountCount)++;
        }
        fclose(file);
    }
    else
    {
        printf("Error opening file or file does not exist.\n");
    }
}
void bus()
{
    printf("[1]. %s\n", ch[0]);
    printf("[2]. %s\n", ch[1]);
    printf("[3]. %s\n", ch[2]);
    printf("[4]. %s\n", ch[3]);
    printf("[5]. %s\n", ch[4]);
    printf("[6]. %s\n", ch[5]);
}
void booking()
{
    int i = 0;
    char numstr[100];
    printf("\n================= Choose Location =================\n");
    bus(); // for seeing bus list
    printf(">>Please enter the Bus number (1~5) or 0 to exit: ");
    scanf("%d", &trno);
    printf("\n============= Bus Reservation System ==============\n");
    printf("Your Bus Number is %d\n%s\n", trno, ch[trno - 1]);
    status_1(trno);
    FILE *f1, *fopen(); // for reading the seats from the user.
    char str1[80] = "32", str2[4], str3[4];
    // seat1 is check left seat in bus
    int seat1, seat2, booking = 0;
    if (trno == 1)
    {
        f1 = fopen("tr1.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    else if (trno == 2)
    {
        f1 = fopen("tr2.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    else if (trno == 3)
    {
        f1 = fopen("tr3.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    else if (trno == 4)
    {
        f1 = fopen("tr4.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    else if (trno == 5)
    {
        f1 = fopen("tr5.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    else if (trno == 6)
    {
        f1 = fopen("tr6.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    seat1 = atoi(str1); // covert the string into number
    if (seat1 <= 0)
    {
        printf("There is no blank seat in this bus ");
    }
    else
    {
        while (1)
        {
            printf("\nAvailable Seats:------>%d\n", seat1);
            printf("Number of Tickets (0~32):----->");
            scanf("%d", &booking);
            printf("\n");
            if (booking >= 0 && booking <= 32)
            {
                seat1 = seat1 - booking;
                itoa(trno, numstr, 10);
                name_number(booking, numstr);
                printf("\nThe Total booking amount is %d\n", 200 * booking);
                itoa(seat1, str1, 10);
                // for reading the seats from the user.
                if (trno == 1)
                {
                    f1 = fopen("tr1.txt", "w");
                    fputs(str1, f1);
                    fclose(f1);
                }
                else if (trno == 2)
                {
                    f1 = fopen("tr2.txt", "w");
                    fputs(str1, f1);
                    fclose(f1);
                }
                else if (trno == 3)
                {
                    f1 = fopen("tr3.txt", "w");
                    fputs(str1, f1);
                    fclose(f1);
                }
                else if (trno == 4)
                {
                    f1 = fopen("tr4.txt", "w");
                    fputs(str1, f1);
                    fclose(f1);
                }
                else if (trno == 5)
                {
                    f1 = fopen("tr5.txt", "w");
                    fputs(str1, f1);
                    fclose(f1);
                }
                else if (trno == 6)
                {
                    f1 = fopen("tr6.txt", "w");
                    fputs(str1, f1);
                    fclose(f1);
                }
                break;
            }
            else
            {
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("Number is out of range! Pls input again.\n");
            }
        }
    }
}
// bus seat check
void status_1(int trno)
{
    int i, index = 0, j;
    j = read_number(trno);
    read_name(trno);
    char tempname[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
    for (i = 0; i < j; i++)
    {
        strcpy(tempname[num1[i]], name[i]);
    }
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("[%2d.%10s]\t", index + 1, tempname[index + 1]);
            index++;
        }
        printf("\n");
    }
}
// keyin SeatNo & Name on seat
void name_number(int booking, char numstr[100])
{
    char tempstr[100], tempstr1[12] = "status", tempstr2[12] = "number";
    int number;
    FILE *a, *b;
    int i = 0;
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);
    a = fopen(tempstr1, "a");     // for open the file to write the name in the file
    b = fopen(tempstr2, "a");     // for open the file for writing the number in the file
    for (i = 0; i < booking; i++) // for entering the person name and seat number in the file
    {
        while (1)
        {
            printf("\n======= Enter the details for ticket no %d ========\n", i + 1);
            printf("Enter the seat number (1~32):--->");
            scanf("%d", &number);
            if (number >= 1 && number <= 32)
            {
                printf("Enter the name of person:--->");
                scanf("%s", name[number - 1]);
                printf("\n================= Payment Details =================\n");
                printf("\n");
                itoa(number, tempstr, 10);
                fprintf(a, "%s ", name[number - 1]);
                fprintf(b, "%s ", tempstr);
                break;
            }
            else
            {
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("Number is out of range! Pls input again.\n");
            }
        }
    }
    fclose(a);
    fclose(b);
}
int read_number(int trno) // for putting the numeric value in the array
{
    char tempstr[100], tempstr2[12] = "number";
    FILE *a, *b;
    char numstr[100];
    int i = 0, j = 0, k;
    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr2, numstr);
    a = fopen(tempstr2, "a+"); // for open the file to write the name in the file
    while (!feof(a))
    {
        number[i][j] = fgetc(a);

        if (number[i][j] == ' ')
        {
            j = 0;
            i++;
        }
        else
        {
            j++;
        }
    }
    k = i;
    for (i = 0; i < k; i++)
    {
        num1[i] = atoi(number[i]);
    }
    fclose(a);
    return k;
}
void read_name(int trno) // for putting the numeric value in the array
{
    char tempstr1[12] = "status";
    FILE *b;
    char numstr[100];
    int i = 0, j = 0, k = 0;
    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    b = fopen(tempstr1, "a+"); // for open the file to write the name in the file
    while (!feof(b))
    {
        name[i][j] = fgetc(b);

        if (name[i][j] == ' ')
        {
            j = 0;
            i++;
        }
        else
        {
            j++;
        }
    }
    name[i][j] = '\0';
    k = i;
    fclose(b);
}
void status()
{
    printf("\n============== Check Bus Seat Status ==============\n");
    int i, trno, index = 0, j;
    printf(">>Please enter the Bus number (1~5) or 0 to exit: ");
    scanf("%d", &trno);
    j = read_number(trno);
    read_name(trno);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("This Bus Number is %d\n%s\n", trno, ch[trno - 1]);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    char tempname[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
    for (i = 0; i < j; i++)
    {
        strcpy(tempname[num1[i]], name[i]);
    }
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("[%2d.%10s]\t", index + 1, tempname[index + 1]);
            index++;
        }
        printf("\n");
    }
}
void cancle()
{
    int seat_no, i, j;
    char numstr[100], tempstr2[15] = "number", tempstr1[15] = "status";
    printf("Enter the bus number:---->");
    scanf("%d", &trno);
    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);
    read_number(trno);
    read_name(trno);
    status_1(trno);
    printf("Enter the seat number:--->");
    scanf("%d", &seat_no);
    FILE *a, *b;
    a = fopen(tempstr1, "w+");
    b = fopen(tempstr2, "w+");
    for (i = 0; i < 32; i++)
    {
        if (num1[i] == seat_no)
        {
            for (j = 0; j < 32; j++)
            {
                if (num1[j] != seat_no && num1[j] != 0)
                {
                    fprintf(b, "%d ", num1[j]);
                    fprintf(a, "%s", name[j]);
                }
                else if (num1[j] == seat_no && num1[j] != 0)
                {
                    strcpy(name[j], "Empty ");
                }
            }
        }
    }
    fclose(a);
    fclose(b);
    printf("\n\n");
    printf("\n================= Money Refunded ==================\n");
    printf("\nYour Rm 200 has been Returned\n");
    printf("\n===================================================\n");
}
void clearInputStream()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void exitProgram()
{
    char input[10];
    printf("\n================= Exiting System ==================\n");
    printf("Are you sure you want to exit? (Y/N): ");
    clearInputStream();      // 清除输入流中的任何之前的输入
    fgets(input, 10, stdin); // 读取输入

    // 检查输入是否为 Y 或 y
    if (strcmp(input, "Y\n") == 0 || strcmp(input, "y\n") == 0)
    {
        printf("Exiting in 5 seconds...\n");
        for (int i = 5; i > 0; i--)
        {
            printf("%d...\n", i);
            Sleep(1000); // Windows 下的休眠
        }
        exit(0); // 退出程序
    }
    else
    {
        printf("Exit canceled.\n\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Back to Login Page...\n");
    }
}