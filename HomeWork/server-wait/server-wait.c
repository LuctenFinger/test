#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct student student;

struct student
{
    char StudentNum[11];//ip
    int lesson;
    int GPA;
    student* right;
    student* left;
    student* up;
    student* down;
}*head, *tail;



int init(student* p)
{
    strcpy(p->StudentNum, "0000000000");
    p->lesson = -1;
    p->GPA = -1;
    p->left = NULL;
    p->right = NULL;
    p->up = NULL;
    p->down = NULL;
    return 0;
}

//INSERT modules************************************
student *p0[3];



int FindInsert(student *p, student *x, int m)
{
    if (m==0)
    {
         if(p->lesson < x->lesson ||
            (p->lesson == x->lesson && p->GPA < x->GPA))
         {
             if (p->right == NULL || p->right->lesson > x->lesson ||
                 (p->right->lesson == x->lesson && p->right->GPA >= x->GPA))
             {
                 p0[0] = p;
                 return 0;
             }
         }
    }


    if (p->right == NULL || p->right->lesson > x->lesson)
    {
        p0[m] = p;
        FindInsert(p->down, x, m-1);
    }

    else if (p->lesson == x->lesson && p->right->GPA > x->GPA)
    {
        p0[m] = p;
        FindInsert(p->down, x, m-1);
    }

    else FindInsert(p->right, x, m);

}





int inserted(student* p)
{

    student *q, *tmp = NULL;


    int i;
    for (i=0; i<3; i++)
        if(i==0 || rand()%2==1)
        {

            q = (student *)malloc(sizeof(student));
            q->up = NULL;
            q->left = p0[i];
            q->right = p0[i]->right;
            p0[i]->right = q;


            q->down = tmp;
            q->GPA = p->GPA;
            q->lesson = p->lesson;
            strcpy(q->StudentNum, p->StudentNum);

            if (tmp != NULL)
                tmp->up = q;

            tmp = q;
        }

    free(p);

    if (p0[0] == tail)
        tail = q;

    return 0;
}


//DEL MODULES*********************************************
char DelStuNum[11];
int DelLesson, DelGPA;
student *DelP;


int FindDel(student *p)
{
    if (strcmp(p->StudentNum, DelStuNum) == 0)
        {
            DelP = p;
            return 0;
        }


    if (p->right == NULL || p->right->lesson > DelLesson)
        return FindDel(p->down);
    else if (p->lesson == DelLesson && p->right->GPA > DelGPA)
        return FindDel(p->down);

    else return FindDel(p->right);

}

int del(student* p)
{
    if (p == tail)
        tail = p->left;


    if(p->up != NULL)
        del(p->up);
    if (p->right != NULL)
    {
        p->left->right = p->right;
        p->right->left = p->left;
    }

    else p->left->right = NULL;





    free(p);
    return 0;
}

//OUTPUT MODULES************************************

int output()
{
    FILE *fp = fopen("output.txt", "w");
    fprintf(fp, "%s\n", tail->StudentNum);
    fclose(fp);
    return 0;
}


//************************************
int main()
{
    char ch[2];
    int i;

    student *tmp, *p;

    FILE *fp = fopen("list.txt", "r");

    srand(time(NULL));

    head = (student *)malloc(sizeof(student));
    init(head);
    tmp = head;


    for (i=0; i<2; i++)
    {
        p = (student *)malloc(sizeof(student));
        init(p);
        p->up = tmp;
        tmp->down = p;
        tmp = p;
        tail = p;
    }



    for (i=0; fscanf(fp, "%s", ch)!=EOF; i++)
    {
        if (ch[0] == '+')//user plus
        {
            p = (student *)malloc(sizeof(student));
            fscanf(fp, "%s", p->StudentNum);
            fscanf(fp, "%d", &(p->lesson));
            fscanf(fp, "%d", &(p->GPA));
            FindInsert(head, p, 2);
            inserted(p);
        }

        if (ch[0] == '-')//user offline
        {
            fscanf(fp, "%s", DelStuNum);
            fscanf(fp, "%d", &DelLesson);
            fscanf(fp, "%d", &DelGPA);
            FindDel(head);
            del(DelP);
        }

        if (ch[0] == '=')//user login
        {
            output();
            del(tail);
        }

    }
    fclose(fp);

    return 0;

}
