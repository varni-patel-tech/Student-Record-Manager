
#include <stdio.h>

struct student
{
    char name[50];
    int roll, marks;
};

int roll_exists(int roll)
{
    FILE *fp = fopen("records.txt", "r");

    if (fp == NULL)
        return 0;

    struct student temp;

    while (fscanf(fp, "%49s %d %d", temp.name, &temp.roll, &temp.marks) == 3)
    {
        if (temp.roll == roll)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void add()
{
    struct student s;

    printf("Enter name, roll number and marks: ");

    if (scanf("%49s %d %d", s.name, &s.roll, &s.marks) != 3)
    {
        printf("Invalid input!\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
        return;
    }

    if (roll_exists(s.roll))
    {
        printf("A student with this roll number already exists!\n");
        return;
    }

    FILE *fp = fopen("records.txt", "a");

    if (fp == NULL)
    {
        printf("Could not open the file!\n");
        return;
    }

    fprintf(fp, "%s %d %d\n", s.name, s.roll, s.marks);
    fclose(fp);

    printf("Student record added successfully!\n");
}

void display()
{
    FILE *fp = fopen("records.txt", "r");

    if (fp == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    struct student temp;
    int found = 0;

    printf("\n--- Student Records ---\n");

    while (fscanf(fp, "%49s %d %d", temp.name, &temp.roll, &temp.marks) == 3)
    {
        printf("Name: %s | Roll: %d | Marks: %d\n", temp.name, temp.roll, temp.marks);
        found = 1;
    }

    if (!found)
        printf("No student records available.\n");

    fclose(fp);
}

void sroll()
{
    int r, found = 0;

    printf("Enter roll number: ");

    if (scanf("%d", &r) != 1)
    {
        printf("Invalid roll number!\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
        return;
    }

    FILE *fp = fopen("records.txt", "r");

    if (fp == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    struct student temp;

    while (fscanf(fp, "%49s %d %d", temp.name, &temp.roll, &temp.marks) == 3)
    {
        if (r == temp.roll)
        {
            printf("Name: %s | Roll: %d | Marks: %d\n",
                   temp.name, temp.roll, temp.marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No student found.\n");

    fclose(fp);
}

void topper()
{
    struct student temp, best;
    int found = 0;

    FILE *fp = fopen("records.txt", "r");

    if (fp == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    while (fscanf(fp, "%49s %d %d", temp.name, &temp.roll, &temp.marks) == 3)
    {
        if (!found || temp.marks > best.marks)
        {
            best = temp;
            found = 1;
        }
    }

    if (found)
    {
        printf("\n--- Topper Details ---\n");
        printf("Name: %s | Roll: %d | Marks: %d\n",
               best.name, best.roll, best.marks);
    }
    else
    {
        printf("No student records available.\n");
    }

    fclose(fp);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== STUDENT RECORD MANAGER =====\n");
        printf("1. Add a student\n");
        printf("2. Display all students\n");
        printf("3. Search by roll number\n");
        printf("4. Find the topper\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid choice!\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            continue;
        }

        switch (choice)
        {
        case 1:
            add();
            break;

        case 2:
            display();
            break;

        case 3:
            sroll();
            break;

        case 4:
            topper();
            break;

        case 5:
            printf("Have a nice day!\n");
            return 0;

        default:
            printf("Invalid choice! Please select 1 to 5.\n");
        }
    }
    return 0;
}
