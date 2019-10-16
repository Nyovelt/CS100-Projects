#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define RES_SIZE 128
#define NAME_SIZE 64

/*******************************Struct declarations****************************************/
//It's generally good to put all your structures at the beginning of a single file.
typedef struct a
{
    char name[NAME_SIZE];
    float score;
} Student;

typedef struct b
{
    /* data */
    Student *data;
    struct b *next;
} Node;

typedef struct c
{
    /* data */
    Node *head;
    Node *tail;
    int size;
} LinkedList;

/*******************************Part0: common functions******************************/

int min(int a, int b)
{
    return (a > b) ? a : b;
}

/*******************************Part1: comparison and sorting******************************/
int compare(const char *str1, const char *str2)
{
    //YOUR CODE HERE
    for (int i = 0; i < min(strlen(str1), strlen(str2)); i++)
    {
        if ((*(str1 + i)) > *(str2 + i))
        {
            return 1;
        }
        else if ((*(str1 + i)) < *(str2 + i))
        {
            return -1;
        }
        else
        {
            if (i == (min(strlen(str1), strlen(str2)) - 1))
                return 0;
        }
    }
}

void string_sort(char *strings[], int size)
{
    //YOUR CODE HERE
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (compare(strings[j - 1], strings[j]) == 1)
            {
                char *p;
                p = strings[j];
                strings[j] = strings[j - 1];
                strings[j - 1] = p;
            }
        }
    }
    //return *strings;
}

/*********************************New student function*************************************/
Student *new_student(const char *_name, float _score)
{
    //YOUR CODE HERE
    Student *r = (struct Student *)malloc(sizeof(Student));
    strcpy(r->name, _name);
    r->score = _score;
    return r;
}

/*******************************Part2: LinkedList & functions******************************/
void list_init(LinkedList *l)
{
    //YOUR CODE

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

void list_insert(LinkedList *l, Student *stu_ptr)
{
    //YOUR CODE HERE
    Node *newStudent = malloc(sizeof(Node));

    if (l->head == NULL)
    {
        l->head = newStudent;
        l->tail = newStudent;
    }
    else
    {
        l->tail->next = newStudent;
        l->tail = newStudent;
    }
    l->size++;
    newStudent->data = stu_ptr;
    newStudent->next = NULL;
}

void list_erase(LinkedList *l)
{
    //YOUR CODE HERE
    Node *a = NULL;
    Node *b = NULL;
    a = l->head;
    while (a != NULL)
    {
        b = a->next;
        free(a);
        a = b;
    }
    list_init(l);
}

Node *list_remove(LinkedList *l, Node *target)
{
    //YOUR CODE HERE
    Node *a = NULL;
    Node *b = NULL;
    a = l->head;
    int i = 0;
    if (!l->size)
    {
        return NULL;
    }
    if (l->size == 1)
    {
        free(l->head);
        list_init(l);
        return NULL;
    }
    while (1)
    {
        i++;

        if (a != target)
        {
            b = a;
            a = a->next;
        }
        else if (a == target)
        {
            if (i > 1 && i < l->size)
            {
                b->next = a->next;
                free(a);
                l->size--;
                return b->next;
            }
            else if (i == 1)
            {
                l->head = a->next;
                l->size--;
                free(a);
                return l->head;
            }
            else if (i == l->size)
            {
                l->tail = b;
                b->next = NULL;
                free(a);
                l->size--;
                return NULL;
            }
        }
        if (i == l->size)
        {
            return NULL;
        }
    }
    return NULL;
}
/*******************************Part3: Searching*******************************************/
Node *list_search_by_name(LinkedList *l, char *search_name)
{
    if (search_name == NULL)
    {
        return NULL;
    }
    else if (l->size == 0)
    {
        return NULL;
    }
    else if (l->size == 1)
    {
        if (compare(l->head->data->name, search_name) == 0)
        {
            return l->head;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        Node *temp = NULL;
        temp = l->head;
        int i = 0;

        while (i < l->size)
        {
            i++;
            if (compare(temp->data->name, search_name) == 0)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
}

int list_search_by_score(LinkedList *l,
                         float lower_bound,
                         float upper_bound,
                         char *result[RES_SIZE])
{

    Node *temp;
    temp = l->head;
    int i, j;
    i = 0;
    j = 0;
    while (i < l->size)
    {
        i++;
        if (temp->data->score >= lower_bound && temp->data->score <= upper_bound)
        {
            result[j] = temp->data->name;
            j++;
        }
        temp = temp->next;
        string_sort(result, j);
    }
    return j;
}

/*******************************Your Main Function*****************************************/
//DO NOT submit main function to OJ, or compile error may happen!

int main()
{
    Student *stu1 = new_student("AA", 12);
    Student *stu2 = new_student("BC", 13);
    Student *stu3 = new_student("EC", 14);
    Student *stu4 = new_student("DD", 15);
    //printf("%s %f\n",stu1->name,stu1->score);
    LinkedList *list;
    LinkedList l;
    list = &l;
    Node *p;
    list_init(list);
    //printf("size = %d\n", list->size);
    list_insert(list, stu1);
    //printf("size = %d\n", list->size);
    //list_insert(list, stu2);
    //list_insert(list, stu3);
    //list_insert(list, stu4);
    //printf("size = %d\n", list->size);
    //printf("%s %f\n", list->head->data->name, list->head->data->score);
    //printf("%s %f\n", list->tail->data->name, list->tail->data->score);
    //printf("%f", list_search_by_name(list, stu1->name)->data->score);
    //printf("%s",list_search_by_name(list,stu2->name)->data->name);
    //char *a=NULL;
    //printf("%s",list_search_by_name(a)->data->name);
    char *result[RES_SIZE];
    printf("%d", list_search_by_score(list, 12, 12, result));
}