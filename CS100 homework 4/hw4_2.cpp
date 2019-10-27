 #include <iostream>
#include <string>
#include <random>
#include <utility>
#include <time.h>
#include <functional>
#include "stdio.h"

using namespace std;

#define MAX_ROWS 3
#define MAX_COLS 10
#define MAX_STUDENTS 30

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define NOTHING 0
#define APPLEPIE 1
#define BEEF 2
#define CURRY 3

typedef int MEALTYPE;

class Fmart;

int randInt(int min, int max)
{
    if (max < min)
        swap(max, min);
    return rand() % (max - min + 1) + min;
}

class Player
{
public:
    //constructor
    Player(Fmart *fp);

    //destructor
    ~Player();

    //accessors
    int row() const;
    int col() const;
    int lives() const;
    int score() const;
    MEALTYPE mealInHand() const;

    //mutators
    void pickup(MEALTYPE meal);
    void move(int dir);

    void deliver();
    void decLife();
    void judge();

private:
    int m_row;
    int m_col;
    int m_lives;
    int m_score;
    MEALTYPE m_mealInHand;
    Fmart *m_fp;
};

class Student
{
public:
    //constructor
    Student(Fmart *fp, int row, int col);

    //destructor
    ~Student();

    //accessors
    int row() const;
    int col() const;
    MEALTYPE typeWanted() const;

    //mutators
    void moveForward();

private:
    // TODO: add private members for Student class.
    int m_row;
    int m_col;
    MEALTYPE m_typeWanted;
    Fmart *m_fp;
};

class Fmart
{
public:
    //constructor
    Fmart();
    //destructor
    ~Fmart();

    //accessors
    Player *getPlayer() const;
    Student *getStudent(int row, int col) const; //��Ҫѧ��������ŵķ�ʽ�Ƿ���Mealtyoe
    int numberOfStudents() const;
    bool studentAt(int row, int col) const;

    //mutators
    bool addStudent();
    bool deleteStudent(int row, int col);
    void display();
    void play();
    void print();

private:
    Player *m_player;
    Student *m_students[MAX_STUDENTS];
    int m_numStudents;
};

//---------------------------Implementions of Fmart-------------------------------------//

void Fmart::print()  //�����Ҫѧ
{
    for (int i = 0; i < m_numStudents; i++)
    {
        printf("c:%d r:%d\n", m_students[i]->col(), m_students[i]->row());
    }
}

Fmart::Fmart()
{
    // This constructor:
    // (1) adds a new player
    // (2) initializes m_students to be NULL (or nullptr)
    // (3) initializes the number of students to be 0.
    // TODO: finish the implementation.

    m_player = new Player(this);
    for(int i=0;i<MAX_STUDENTS;i++){
        m_students[i] = NULL;
    }
    m_numStudents = 0;
}

Fmart::~Fmart()
{
    // TODO: delete everything you dynamically created.
    delete m_player;
}

Student *Fmart::getStudent(int row, int col) const
{
    for (int i = 0; i < m_numStudents; i++)
    {
        if (m_students[i]->col() == col && m_students[i]->row() == row)
            return m_students[i];
    }
}

Player *Fmart::getPlayer() const
{
    // This function returns a pointer to the player.
    // TODO: finish the implementation.
    return m_player; 
}

int Fmart::numberOfStudents() const
{
    // This function returns the number of students.
    // TODO: finish the implementation.
    return m_numStudents; 
}

bool Fmart::studentAt(int row, int col) const
{
    // TODO: check if there is a student at (row, col), if so, return true, else return false.


    for (int i = 0; i < m_numStudents; i++)
    {
        if ((m_students[i]->col() == col) && (m_students[i]->row() == row))
            return true;
    }
    return false;
}

bool Fmart::addStudent()
{
    // TODO: add a new student at the rightmost column.
    // If Student number is greater than MAX_STUDENTS, just do nothing and return false.
    // If you added a student successfully, return true.
    // You will need randInt() to get a random number.
    //return false; // This line is only for the program to compile.
    if (m_numStudents >= MAX_STUDENTS)
        return false;

    int row_ = randInt(1, 3);

    while (studentAt(row_, 10) == 1)
    {
        row_ = randInt(1, 3);
    }

    m_students[m_numStudents] = new Student(this, row_, 10);

    m_numStudents++;

    return true;
}

bool Fmart::deleteStudent(int row, int col)
{
    // TODO: delete a student at position (row, col) from m_students.
    // If no student is at this position, return false.
    // If there is a student, delete the student, and shift all students after it to the left.
    // Maybe there are extra things to deal with?
    // YOUR CODE HERE
    for (int i = 0; i < m_numStudents; i++)
    {
        if ((m_students[i]->row() == row) && (m_students[i]->col() == col))
        {

            for (int j = i; j < m_numStudents - 1; j++)
            {
                m_students[j] = m_students[j + 1];
            }
            m_students[m_numStudents - 1] = NULL;

            break;
        }
    }
    m_numStudents--;

    return true;
}

/** Display the game grid
 * It will display grids, players and students.
 * There are a few blanks for you to fill in.
 */
void Fmart::display()
{
    char **disp = new char *[3];
    for (int i = 0; i < 3; i++)
    {
        disp[i] = new char[10];
        for (int j = 0; j < 10; j++)
            disp[i][j] = '.';
    }

    // TODO: Visit each student and:
    // (Assume this student is at (r, c))
    // If this student wants the meal the player is atholding, change disp[r-1][c-1] to '@'.
    // If this student doesn't want the meal, change disp[r-1][c-1] to 'S'.

    for (int i = 0; i < m_numStudents; i++)
    {
        int r = m_students[i]->row();
        int c = m_students[i]->col();

        if (m_students[i]->typeWanted() == m_player->mealInHand())
        {
            disp[r - 1][c - 1] = '@';
        }
        else
        {
            disp[r - 1][c - 1] = 'S';
        }
    }

    //disp[1][9] = 'T';

    int r = m_player->row();
    int c = m_player->col();

    switch ((m_player->mealInHand()))
    {
    case 0:
        disp[r - 1][c - 1] = 'P';
        break;
    case 1:
        disp[r - 1][c - 1] = 'A';
        break;
    case 2:
        disp[r - 1][c - 1] = 'B';
        break;
    case 3:
        disp[r - 1][c - 1] = 'C';
        break;
    default:
        break;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << disp[i][j];
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
        delete[] disp[i];
    delete[] disp;
}

void Fmart::play()
{
    addStudent(); //Adds the first student.
    while (m_player->lives() > 0)
    {
    INPUT:
        display();
        cout << "You have " << m_player->lives() << " lives, and your score is " << m_player->score() << "." << endl;
        cout << "make a move (a, b, c, u, d, g): " << endl;

        string input;
        getline(cin, input);
        cout << endl
             << endl
             << endl;

        char option = input[0]; //Here, option is 'a', 'b', 'c', 'u', 'd', or 'g'.

        // TODO: Let your player behave according to 'option'.
        // You should call member functions of class Player.
        switch (option)
        {
        case 'a':
            m_player->pickup(UP); //�����ֻ���define�Ķ��壨������Щ���ʣ�
            break;
        case 'b':
            m_player->pickup(2);
            break;
        case 'c':
            m_player->pickup(3);
            break;
        case 'u':
            m_player->move(1);
            break;
        case 'd':
            m_player->move(2);
            break;
        case 'g':
            m_player->deliver();
            break;
        default:
            goto INPUT; //�����򲻵��Ѳ�Ҫдgoto
            break;
        }


        // Moves all students forward
        for (int i = 0; i < m_numStudents; i++)
        {
            int detector = m_numStudents; // Detect whether a student has reached col 1 and is deleted.
            m_students[i]->moveForward();
            if (m_numStudents != detector)
                i--; // If so, move back 1 iteration.
        }

        // A 30% chance for adding a new student
        if (randInt(1, 10) <= 3)
            addStudent();

    }
    cout << "You lose. Your score is " << m_player->score() << ". Press any key to quit." << endl;
    getchar();
}

//---------------------------Implementions of Student -------------------------------------//
Student::Student(Fmart *fp, int row, int col)
{
    // TODO: this constructor initializes a student, at (row, col).
    // You should randomly choose 1 meal type, and store it in the student object.
    // fp is a pointer to the Fmart this student is in.
    m_fp = fp;
    m_row = row;
    m_col = col;
    m_typeWanted = randInt(1, 3);
}

Student::~Student()
{
    //delete m_fp;
    // TODO: delete everything you dynamically created.
}

int Student::row() const
{
    // TODO: return the row number.
    return m_row; // This line is only for the program to compile.
}

int Student::col() const
{
    // TODO: return the column number.
    return m_col; // This line is only for the program to compile.
}

MEALTYPE Student::typeWanted() const
{
    // TODO: return the type of meal this student wants.
    return m_typeWanted; // This line is only for the program to compile.
}

void Student::moveForward()
{
    // TODO:
    // Move the student forward for one step.
    // If this student reaches the first column, player's lives will be decreased by 1, and this student will be deleted.
    // YOUR CODE HERE
    //return; // This line is only for the program to compile.
    m_col--;
    if (m_col == 1)
    {
        m_fp->deleteStudent(m_row, m_col);
        m_fp->getPlayer()->decLife();
    }
}

//---------------------------Implementions of Player -------------------------------------//

Player::Player(Fmart *fp)
{
    // TODO: this constructor initializes the player.
    // For example, the player should be at (2, 1), have 3 lives, and have 0 score.
    // Please consider other parameters to initialize.
    m_fp = fp;
    m_row = 2;
    m_col = 1;
    m_lives = 3;
    m_score = 0;
    m_mealInHand = 0;
}

Player::~Player()
{

    // TODO: delete everything you dynamically created.
}

int Player::row() const
{
    // TODO: return the row number.
    return m_row; // This line is only for the program to compile.
}
int Player::col() const
{
    // TODO: return the column number.
    return m_col; // This line is only for the program to compile.
}

int Player::lives() const
{
    // TODO: return the number of lives.
    return m_lives; // This line is only for the program to compile.
}

int Player::score() const
{
    // TODO: return the score.
    return m_score; // This line is only for the program to compile.
}

MEALTYPE Player::mealInHand() const
{
    // TODO: return the type of meal in player's hand.
    return m_mealInHand; // This line is only for the program to compile.
}

void Player::pickup(MEALTYPE meal)
{
    // TODO: pick up a box meal of type 'meal'.
    //return; // This line is only for the program to compile.
    m_mealInHand = meal;
}

void Player::move(int dir)
{
    // TODO: Move the player upwards of downwards.
    // dir will be either UP or DOWN.
    //return; // This line is only for the program to compile.
    if (dir == 1)
    {
        m_row--;
    }
    else if (dir == 2)
    {
        m_row++;
    }
    judge();
}

void Player::judge() //��Judge�Ķ����Ž�ȥ����Ҫ�������������һЩ
{
    if (m_row < 1)
    {
        m_row = 1;
    }
    else if (m_row > MAX_ROWS)
    {
        m_row = MAX_ROWS;
    }
}

void Player::deliver()
{
    // TODO:
    // Send the meal to left-most student in that row.
    // If (1) He/She doesn't want this meal
    //    (2) No student at this row
    //    (3) Player has no meal in hand
    // just do nothing and returns.
    // If success, delete the student, increment m_score by 10, and set player's hand to NOTHING
    //return; // This line is only for the program to compile.
    //printf("deliver\n");
    for (int i = 2; i <= MAX_COLS; i++)
    {
        if (m_fp->studentAt(m_row, i))
        {
            if (m_fp->getStudent(m_row, i)->typeWanted() == m_mealInHand)
            {
                
                //  printf("%d %d\n",m_row,i);
                m_fp->deleteStudent(m_row, i);
                //printf("+10s\n");
                m_score += 10;
                m_mealInHand = 0;
            }
            break;
        }
    }
    //printf("not found\n");
}

void Player::decLife()
{
    m_lives--;
    // TODO: decrease player's life by 1.
    return; // This line is only for the program to compile.
}

// ------------------------------Main function--------------------------------------//
int main()
{
    srand(time(NULL));
    Fmart f;
    f.play();
}