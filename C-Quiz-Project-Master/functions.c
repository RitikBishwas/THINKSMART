#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "Headers/global.h"
#include "Headers/functions.h"

C_Programming p1;
Engineering_Visualisation e1;
Data_Structure d1;
Computer_Systems c1;
System_Programming s1;
General g1;
Question q;
Student currStudent;

int Answer;
int Total_Score;
int Life1;
int Life2;
double elapsed;
double time_taken;

time_t start_time, end_time;

int questions[10];
Student students[100]; // Adjust the array size as per your needs
int numPlayers = 0;

void setValues(Question *q, char qt[], char a1[], char a2[], char a3[], char a4[], int ca, int pa, int s1, int s2, char h[])
{
    strcpy(q->Question_Text, qt);
    strcpy(q->Option_1, a1);
    strcpy(q->Option_2, a2);
    strcpy(q->Option_3, a3);
    strcpy(q->Option_4, a4);
    q->Correct_Answer = ca;
    q->Question_Score = pa;
    q->show1 = s1;
    q->show2 = s2;
    strcpy(q->Hint, h);
}

void setQuestions(int n, int diff)
{
    if (diff == 1)
    {
        switch (n)
        {
        case 1:
            setValues(&p1.p_q[0], "Which of the following is the correct syntax to declare a variable in C?", "1) int variableName;", "2) variableName int;", "3) var variableName;", "4) variableName = int;", 1, 10, 1, 3, "The data type is usually mentioned before the variable name in C.");
            setValues(&p1.p_q[1], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nprintf(\"%d\", sizeof(float));\nreturn 0;\n}", "1) 4", "2) 8", "3) 2", "4) Compiler Error", 1, 10, 1, 4, "The sizeof operator returns the size in bytes of a data type.");
            setValues(&p1.p_q[2], "Which of the following is NOT a valid identifier in C?", "1) myVariable", "2) _variable", "3) 123variable", "4) variable123", 3, 10, 2, 3, "An identifier cannot start with a digit.");
            setValues(&p1.p_q[3], "What is the purpose of the \"break\" statement in C?", "1) To exit the current loop or switch statement", "2) To skip the current iteration of a loop", "3) To continue to the next iteration of a loop", "4) To print a line break in the output", 1, 10, 1, 3, "The \"break\" statement is used to terminate the execution of a loop or switch statement.");
            setValues(&p1.p_q[4], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint x = 5;\nprintf(\"%d\", ++x);\nreturn 0;\n}", "1) 4", "2) 5", "3) 6", "4) Compiler Error", 3, 10, 2, 3, "The prefix increment operator (++x) increments the value of x before it is used in the printf statement.");
            setValues(&p1.p_q[5], "Which of the following is the correct way to define a constant in C?", "1) constant int PI = 3.14;", "2) const int PI = 3.14;", "3) #define PI 3.14", "4) Both 2) and 3)", 4, 10, 2, 4, "Constants can be defined using either the \"const\" keyword or the preprocessor directive \"#define\".");
            setValues(&p1.p_q[6], "What is the purpose of the \"sizeof\" operator in C?", "1) To calculate the size of a data type", "2) To calculate the sum of two numbers", "3) To determine if a variable is initialized", "4) To convert one data type to another", 1, 10, 1, 4, "The \"sizeof\" operator returns the size in bytes of a data type or variable.");
            setValues(&p1.p_q[7], "Which of the following is the correct way to read a character from the user in C?", "1) scanf(\"%c\", &ch);", "2) scanf(\"%s\", &ch);", "3) scanf(\"%d\", &ch);", "4) getchar(ch);", 1, 10, 1, 2, "The \"%c\" format specifier is used to read a character, and the \"&\" operator is used to get the address of the variable.");
            setValues(&p1.p_q[8], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint x = 10;\nint y = 5;\nprintf(\"%d\", x > y ? x : y);\nreturn 0;\n}", "1) 10", "2) 5", "3) 15", "4) Compiler Error", 1, 10, 1, 3, "The ternary operator (?:) returns the value of x if x > y, otherwise it returns the value of y.");
            setValues(&p1.p_q[9], "What is the purpose of the \"continue\" statement in C?", "1) To exit the current loop", "2) To skip the remaining code in the current iteration ", "3) To return a value from a function", "4) To transfer control to another part of the program", 2, 10, 2, 4, "The \"continue\" statement is used to skip the remaining code in a loop and move to the next iteration.");
            setValues(&p1.p_q[10], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint x = 10;\nint y = 5;\nprintf(\"%d\", x & y);\nreturn 0;\n}", "1) 10", "2) 5", "3) 15", "4) 0", 4, 10, 2, 4, "The bitwise AND operator (&) performs a bitwise AND operation on the binary representations of x and y.");
            setValues(&p1.p_q[11], "Which of the following is the correct way to define a function in C?", "1) functionName;", "2) functionName();", "3) functionName() {}", "4) function functionName() {}", 3, 10, 2, 3, "A function definition consists of the return type, function name, parentheses, and function body enclosed in curly braces.");
            setValues(&p1.p_q[12], "What is the purpose of the \"strcpy\" function in C?", "1) To concatenate two strings", "2) To compare two strings", "3) To copy one string to another", "4) To convert a string to uppercase", 3, 10, 3, 1, "The \"strcpy\" function is used to copy the contents of one string to another.");
            setValues(&p1.p_q[13], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nchar str[] = \"Hello\";\nprintf(\"%c\", str[3]);\nreturn 0;\n}", "1) H", "2) e", "3) l", "4) l", 4, 10, 1, 4, "Arrays in C are zero-indexed, so str[3] represents the fourth character in the array.");
            setValues(&p1.p_q[14], "What is the purpose of the \"scanf\" function in C?", "1) To print output to the console", "2) To read input from the user", "3) To format strings", "4) To perform mathematical calculations", 2, 10, 2, 3, "The \"scanf\" function is used to read input from the user based on the specified format.");
            setValues(&p1.p_q[15], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint x = 5;\nint y = 2;\nprintf(\"%d\", x / y);\nreturn 0;\n}", "1) 2.5", "2) 2", "3) 2.0", "4) Compiler Error", 2, 10, 2, 3, "The division operator (/) performs integer division, which truncates the decimal part of the result.");
            setValues(&p1.p_q[16], "Which of the following is the correct syntax to define a structure in C?", "1) struct MyStruct { int x; };", "2) MyStruct { int x; };", "3) structure MyStruct { int x; };", "4) MyStruct = structure { int x; }", 1, 10, 1, 4, "The keyword \"struct\" is used to define a structure, followed by the structure name and the definition inside curly braces.");
            setValues(&p1.p_q[17], "What is the purpose of the \"fwrite\" function in C?", "1) To write data to a file", "2) To read data from a file", "3) To copy a file", "4) To delete a file", 1, 10, 1, 2, "The \"fwrite\" function is used to write data from memory to a file.");
            setValues(&p1.p_q[18], " What is the purpose of the \"malloc\" function in C?", "1) To allocate memory for an array", "2) To deallocate memory", "3) To compare two strings", "4) To copy one string to another", 1, 10, 1, 3, "The \"malloc\" function is used to dynamically allocate memory during runtime.");
            setValues(&p1.p_q[19], "Which of the following is the correct way to access the value of a structure member in C?", "1) structureName.memberName", "2) structureName->memberName", "3) structureName[memberName]", "4) structureName.memberName()", 2, 10, 2, 4, "The arrow operator (->) is used to access structure members when using a pointer to the structure.");
            setValues(&p1.p_q[20], "What is the purpose of the \"fclose\" function in C?", "1) To open a file", "2) To write data to a file", "3) To close a file", "4) To delete a file", 3, 10, 1, 3, "The \"fclose\" function is used to close an open file.");
            setValues(&p1.p_q[21], "Which of the following is the correct way to define a constant pointer in C?", "1) const int *ptr;", "2) int *const ptr;", "3) const int *const ptr;", "4) All of the above", 4, 10, 2, 4, "Constants can be applied to the pointer, the pointed-to value, or both.");
            setValues(&p1.p_q[22], "What is the purpose of the \"strcmp\" function in C?", "1) To concatenate two strings", "2) To compare two strings", "3) To copy one string to another", "4) To convert a string to uppercase", 2, 10, 1, 2, "The \"strcmp\" function is used to compare two strings lexicographically.");
            setValues(&p1.p_q[23], "Which of the following is the correct syntax to define a two-dimensional array in C?", "1) int array[rows][columns];", "2) int array[columns][rows];", "3) int array[rows, columns];", "4) int array[columns, rows];", 1, 10, 1, 3, "The number of rows is mentioned first, followed by the number of columns.");
            setValues(&p1.p_q[24], "What is the purpose of the \"fprintf\" function in C?", "1) To read input from a file", "2) To write formatted output to a file", "3) To copy a file", "4) To delete a file", 2, 10, 2, 3, "The \"fprintf\" function is used to write formatted data to a file.");

            random_Qnumber();

            for (int i = 0; i < 10; i++)
            {
                start_time = time(NULL);
                printf("\033[35m");
                printf("%d. ", i + 1);
                printf("\033[0m");
                askQuestion(&p1.p_q[questions[i]]);
                end_time = time(NULL);
                elapsed = difftime(end_time, start_time);
                printf("\033[0;31m"); // ANSI escape code for red color
                printf("Time taken: %.2f seconds\n", elapsed);
                printf("\033[0m"); // ANSI escape code to reset color

                printf("\033[0;32m"); // ANSI escape code for green color
                printf("Press Enter to Continue.");
                printf("\033[0m"); // ANSI escape code to reset color
                getchar();
                getchar();
                time_taken += elapsed;
                system("cls");
            }

            printf("\033[1;33mThe Total Score is %d out of 100.\033[0m\n", Total_Score); // Yellow color for celebrating

            FILE *file_1 = fopen("ScoresEasy\\1_scores_CP.txt", "a");
            FILE *file_1_b = fopen("ScoresEasy\\1_scores_CP.dat", "rb");
            setScore(file_1, Total_Score, Name, time_taken);
            fclose(file_1);

            if (file_1_b == NULL)
            {
                printf("File not available !!");
                return;
            }

            while (fread(&currStudent, sizeof(Student), 1, file_1_b) == 1)
                students[numPlayers++] = currStudent;

            fclose(file_1_b);

            qsort(students, numPlayers, sizeof(Student), compareStudents);

            FILE *file_1_w = fopen("ScoresEasy\\1_scores_CP.dat", "wb");
            leaderboard(file_1_w, students, &numPlayers, Total_Score, Name, time_taken);
            break;
        case 2:
            setValues(&e1.e_q[0], "Which type of line is used to represent hidden or invisible edges in an orthographic projection?", "1) Dashed line", "2) Solid line", "3) Dot-dashed line", "4) Dotted line", 1, 10, 1, 3, "Hidden lines are typically represented by dashed lines to differentiate them from visible lines.");
            setValues(&e1.e_q[1], "In an isometric projection, angles between axes are:", "1) 90 degrees", "2) 120 degrees", "3) 30 degrees", "4) 45 degrees", 3, 10, 2, 3, "In an isometric projection, the angles between each pair of axes are 120 degrees.");
            setValues(&e1.e_q[2], "What is the purpose of a centerline in an engineering drawing?", "1) To indicate symmetry", "2) To indicate dimensions", "3) To indicate hidden lines", "4) To indicate material specifications", 1, 10, 1, 3, "Centerlines are used to indicate the symmetry of an object or feature.");
            setValues(&e1.e_q[3], "Which type of projection is commonly used in engineering drawings?", "1) Perspective projection", "2) Isometric projection", "3) Oblique projection", "3) Oblique projection", 4, 10, 1, 4, "Orthographic projection is the standard method used to represent objects in engineering drawings.");
            setValues(&e1.e_q[4], "Which of the following is NOT a basic dimensioning element in engineering drawings?", "1) Diameter", "2) Radius", "3) Thickness", "4) Volume", 4, 10, 2, 4, "Basic dimensioning elements include diameter, radius, and thickness, which define the size and shape of objects.");
            setValues(&e1.e_q[5], "What does the term \"tolerance\" refer to in engineering drawings?", "1) The level of accuracy required for a dimension", "2) The distance between two parallel lines", "3) The thickness of a line", "4) The size of a drawing sheet", 1, 10, 1, 3, "Tolerance defines the allowable variation from a specified dimension.");
            setValues(&e1.e_q[6], "Which type of line is used to represent the outline of an object in an orthographic projection?", "1) Phantom line", "2) Hidden line", "3) Object line", "4) Centerline", 3, 10, 3, 4, "Object lines are solid lines used to represent the visible edges of an object in an orthographic projection.");
            setValues(&e1.e_q[7], "What is the purpose of section views in engineering drawings?", "1) To show the interior details of an object", "2) To indicate symmetry", "3) To show the isometric view of an object", "4) To indicate surface finishes", 1, 10, 1, 3, "Section views are used to reveal the internal features of an object that are not visible in the standard views.");
            setValues(&e1.e_q[8], "Which type of projection is commonly used to represent curved surfaces in engineering drawings?", "1) Isometric projection", "2) Oblique projection", "3) Orthographic projection", "4) Perspective projection", 2, 10, 2, 4, "Oblique projection is often used to represent curved surfaces by showing them at an angle.");
            setValues(&e1.e_q[9], "What does the abbreviation \"R\" typically represent in engineering drawings?", "1) Radius", "2) Right angle", "3) Rectangular dimension", "4) Roughness", 1, 10, 1, 2, "The abbreviation \"R\" is commonly used to represent the radius of a curved feature in engineering drawings.");
            setValues(&e1.e_q[10], "Which type of line is used to represent alternate positions or movement in engineering drawings?", "1) Hidden line", "2) Phantom line", "3) Construction line", "4) Centerline", 2, 10, 2, 4, "Phantom lines are used to represent alternate positions or movement of an object.");
            setValues(&e1.e_q[11], "What does the abbreviation \"C\" typically represent in engineering drawings?", "1) Centerline", "2) Circumference", "3) Chord", "4) Counterbore", 1, 10, 1, 4, "The abbreviation \" C \" is commonly used to represent a centerline in engineering drawings.");
            setValues(&e1.e_q[12], "Which type of line is used to indicate a cutting plane in a section view?", "1) Phantom line", "2) Hidden line", "3) Cutting plane line", "4) Break line", 3, 10, 2, 3, "Cutting plane lines are used to indicate the plane along which a section view is taken.");
            setValues(&e1.e_q[13], "Which type of line is used to represent an alternate position or a repeated detail in a drawing?", "1) Hidden line", "2) Phantom line", "3) Construction line", "4) Break line", 4, 10, 2, 4, "Break lines are used to show an alternate position or a repeated detail in a drawing.");
            setValues(&e1.e_q[14], "Which type of line is used to represent a cylindrical surface in a sectional view?", "1) Hidden line", "2) Phantom line", "3) Section line", "4) Cutting plane line", 3, 10, 1, 3, "Section lines are used to represent the cut surface of a material in a sectional view.");
            setValues(&e1.e_q[15], "Which type of line is used to represent the edge of a surface or an outline of a part in an engineering drawing?", "1) Phantom line", "2) Centerline", "3) Object line", "4) Construction line", 3, 10, 3, 4, "Object lines are solid lines used to represent the visible edges or outline of a part.");
            setValues(&e1.e_q[16], "What does the abbreviation \"DIA\" typically represent in engineering drawings?", "1) Dimension", "2) Diameter", "3) Drawing", "4) Distance", 2, 10, 2, 3, "The abbreviation \" DIA \" is commonly used to represent the diameter of a circular feature in engineering drawings.");
            setValues(&e1.e_q[17], "Which type of line is used to represent the outline of an object that extends beyond the boundaries of the drawing sheet?", "1) Extension line", "2) Hidden line", "3) Phantom line", "4) Break line", 3, 10, 1, 3, "Phantom lines are used to represent the outline of an object that extends beyond the boundaries of the drawing sheet.");
            setValues(&e1.e_q[18], "What does the abbreviation \"H\" typically represent in engineering drawings?", "1) Height", "2) Hypotenuse", "3) Horizontal", "4) Hole", 1, 10, 1, 3, "The abbreviation \" H \" is commonly used to represent the height of a feature or an object in engineering drawings.");
            setValues(&e1.e_q[19], "Which type of line is used to represent the outline of an object when it is partially obscured by another object?", "1) Hidden line", "2) Phantom line", "3) Extension line", "4) Section line", 1, 10, 1, 2, "Hidden lines are used to represent the outline of an object when it is obscured by another object in an orthographic projection.");
            setValues(&e1.e_q[20], "Which type of line is used to indicate the cutting plane in a sectional view?", "1) Break line", "2) Hidden line", "3) Phantom line", "4) Section line", 4, 10, 2, 4, "Section lines are used to indicate the cutting plane in a sectional view.");
            setValues(&e1.e_q[21], "What does the abbreviation \"THK\" typically represent in engineering drawings?", "1) Thickness", "2) Think", "3) Throttle", "4) Thread", 1, 10, 1, 3, "The abbreviation \"THK\" is commonly used to represent the thickness of a material or a feature in engineering drawings.");
            setValues(&e1.e_q[22], "Which type of line is used to represent the edges of a hole or a cylindrical feature in a sectional view?", "1) Hidden line", "2) Phantom line", "3) Section line", "4) Cutting plane line", 3, 10, 3, 4, "Section lines are used to represent the edges of a hole or a cylindrical feature in a sectional view.");
            setValues(&e1.e_q[23], "What does the abbreviation \"TYP\" typically represent in engineering drawings?", "1) Typical", "2) Thickness", "3) Taper", "4) Tolerance", 1, 10, 1, 2, "The abbreviation \"TYP\" is commonly used to represent a typical dimension or feature in engineering drawings.");
            setValues(&e1.e_q[24], "Which type of line is used to represent a long, narrow slot in an engineering drawing?", "1) Hidden line", "2) Phantom line", "3) Break line", "4) Centerline", 1, 10, 1, 4, "Hidden lines are used to represent the edges of a long, narrow slot in an engineering drawing.");
            setValues(&e1.e_q[25], "What does the abbreviation \"CONC\" typically represent in engineering drawings?", "1) Concentric", "2) Concrete", "3) Concentration", "3) Concentration", 2, 10, 1, 2, "The abbreviation \"CONC\" is commonly used to represent a concrete material or construction in engineering drawings.");

            random_Qnumber();

            for (int i = 0; i < 10; i++)
            {
                start_time = time(NULL);
                printf("\033[35m");
                printf("%d. ", i + 1);
                printf("\033[0m");
                askQuestion(&e1.e_q[questions[i]]);
                end_time = time(NULL);
                elapsed = difftime(end_time, start_time);
                printf("\033[0;31m"); // ANSI escape code for red color
                printf("Time taken: %.2f seconds\n", elapsed);
                printf("\033[0m"); // ANSI escape code to reset color

                printf("\033[0;32m"); // ANSI escape code for green color
                printf("Press Enter to Continue.");
                printf("\033[0m"); // ANSI escape code to reset color
                getchar();
                getchar();
                time_taken += elapsed;
                system("cls");
            }

            printf("\033[1;33mThe Total Score is %d out of 100.\033[0m\n", Total_Score); // Yellow color for celebrating

            FILE *file_2 = fopen("ScoresEasy\\2_scores_EV.txt", "a");
            FILE *file_2_b = fopen("ScoresEasy\\2_scores_EV.dat", "rb");
            setScore(file_2, Total_Score, Name, time_taken);
            fclose(file_2);

            if (file_2_b == NULL)
            {
                printf("File not available !!");
                return;
            }

            while (fread(&currStudent, sizeof(Student), 1, file_2_b) == 1)
                students[numPlayers++] = currStudent;
            fclose(file_2_b);

            qsort(students, numPlayers, sizeof(Student), compareStudents);

            FILE *file_2_w = fopen("ScoresEasy\\2_scores_EV.dat", "wb");
            leaderboard(file_2_w, students, &numPlayers, Total_Score, Name, time_taken);
            break;
        case 3:
            setValues(&c1.c_q[0], "Which component of a computer is responsible for executing instructions?", "1) Central Processing Unit (CPU)", "2) Random Access Memory (RAM)", "3) Hard Disk Drive (HD4)", "4) Graphics Processing Unit (GPU)", 1, 10, 1, 3, "It is often referred to as the \"brain\" of the computer.");
            setValues(&c1.c_q[1], "Which type of memory is volatile and loses its data when the power is turned off?", "1) Read-Only Memory (ROM)", "2) Cache Memory", "3) Secondary Memory", "4) Random Access Memory (RAM)", 4, 10, 4, 2, "It provides temporary storage for data and instructions that are actively being used by the CPU.");
            setValues(&c1.c_q[2], "What is the purpose of an operating system?", "1)manage hardware resources", "2) Store data permanently", "3) Run application software", "4) All of the above", 4, 10, 4, 3, "An operating system is responsible for managing various aspects of computer hardware, providing an interface for user interaction, and enabling software execution.");
            setValues(&c1.c_q[3], "Which of the following is an example of an input device?", "1) Monitor", "2) Printer", "3) Keyboard", "4) Speakers", 3, 10, 3, 1, "Input devices are used to enter data or commands into the computer system.");
            setValues(&c1.c_q[4], "What is the function of a motherboard in a computer system?", "1) Store data permanently", "2) Provide power to the system", "3) Connect all the hardware components", "4) Execute program instructions", 3, 10, 3, 2, "The motherboard is the main circuit board that connects the CPU, RAM, storage devices, and other peripherals.");
            setValues(&c1.c_q[5], "Which programming language is often used for web development?", "1) Java", "2) C++", "3) Python", "4) HTML", 4, 10, 4, 2, "HTML (Hypertext Markup Language) is the standard language for creating web pages.");
            setValues(&c1.c_q[6], "What is the primary function of a compiler?", "1) Execute program instructions", "2) Convert source code into machine code", "3) Provide an interface for user interaction", "4) Manage computer hardware resources", 2, 10, 2, 3, "A compiler translates high-level programming languages into low-level machine code that can be executed by the computer.");
            setValues(&c1.c_q[7], "Which of the following is a secondary storage device?", "1) USB flash drive", "2) CPU cache", "3) RAM", "4) Optical disc drive", 1, 10, 1, 4, "Secondary storage devices are used for long-term storage of data and programs.");
            setValues(&c1.c_q[8], "What is the purpose of an IP address?", "1) Identify a specific website", "2) Store files and folders", "3) Identify a device on a network", "4) Execute program instructions", 3, 10, 2, 3, "An IP address is a unique numerical identifier assigned to each device connected to a network.");
            setValues(&c1.c_q[9], "Which of the following is an example of an output device?", "1) Mouse", "2) Hard disk drive", "3) Printer", "4) Network interface card (NI3)", 3, 10, 3, 4, "Output devices are used to display or produce information from the computer system.");
            setValues(&c1.c_q[10], "What does the acronym \"URL\" stand for?", "1) Uniform Resource Locator", "2) Unified Resource Locator", "3) Uniform Resource Language", "4) Universal Routing Language", 1, 10, 1, 3, "A URL is the address used to locate a resource on the internet.");
            setValues(&c1.c_q[11], "Which of the following is an example of a high-level programming language?", "1) Assembly language", "2) Machine language", "3) C++", "4) Binary code", 3, 10, 3, 2, "High-level programming languages are easier for humans to read and write compared to low-level languages like assembly or machine language.");
            setValues(&c1.c_q[12], "What is the purpose of a firewall in a computer system?", "1) Protect against unauthorized access", "2) Store data permanently", "3) Execute program instructions", "4) Provide power to the system", 1, 10, 1, 4, "A firewall is a security measure that monitors and filters incoming and outgoing network traffic to protect against unauthorized access or malicious activities.");
            setValues(&c1.c_q[13], "What is the function of an input/output (I/O) device?", "1) Execute program instructions", "2) Connect all the hardware components", "3) Store data permanently", "4) Enable communication between the computer and the user or other devices", 4, 10, 2, 4, "I/O devices facilitate the exchange of data between the computer and external devices, such as keyboards, mice, monitors, and printers.");
            setValues(&c1.c_q[14], "Which of the following is an example of system software?", "1) Web browser", "2) Word processor", "3) Operating system", "4) Spreadsheet program", 3, 10, 3, 1, "System software provides the fundamental functions and services required to operate and manage a computer system.");
            setValues(&c1.c_q[15], "What is the purpose of a cache memory in a computer system?", "1) Store frequently used data and instructions for quick access", "2) Execute program instructions", "3) Connect all the hardware components", "4) Store data permanently", 1, 10, 1, 2, "Cache memory is a high-speed storage unit that holds frequently accessed data and instructions to reduce the time it takes for the CPU to access them.");
            setValues(&c1.c_q[16], "Which of the following is an example of a network topology?", "1) HTML", "2) Ethernet", "3) Ring", "4) Java", 3, 10, 2, 3, "Network topology refers to the physical or logical layout of devices and connections in a network, such as bus, star, ring, or mesh.");
            setValues(&c1.c_q[17], "What is the purpose of a compiler in the software development process?", "1) Detect and fix software bugs", "2) Convert source code into machine code", "3) Provide an interface for user interaction", "4) Manage computer hardware resources", 2, 10, 2, 4, "A compiler is used to translate human-readable source code into machine code that can be executed by the computer.");
            setValues(&c1.c_q[19], "Which of the following is an example of an application software?", "1) Operating system", "2) Compiler", "3) Spreadsheet program", "4) BIOS", 3, 10, 4, 3, "Application software is designed to perform specific tasks or applications, such as word processing, spreadsheet calculations, or graphic design.");
            setValues(&c1.c_q[20], "What is the purpose of a graphical user interface (GUI)?", "1) Manage computer hardware resources", "2) Provide an interface for user interaction", "3) Convert source code into machine code", "4) Store data permanently", 2, 10, 2, 1, "A GUI allows users to interact with the computer system using graphical elements, such as windows, icons, and menus.");
            setValues(&c1.c_q[21], "Which type of computer memory is non-volatile and retains its data even when the power is turned off?", "1) Cache memory", "2) Random Access Memory (RAM)", "3) Read-Only Memory (ROM)", "4) Hard Disk Drive (HDD)", 3, 10, 3, 4, "ROM is a type of memory that stores permanent instructions or data that are not intended to be modified.");
            setValues(&c1.c_q[22], "What is the purpose of an antivirus software?", "1) Convert source code into machine code", "2) Provide an interface for user interaction", "3) Detect and remove computer viruses", "4) Store data permanently", 3, 10, 1, 3, "Antivirus software is designed to identify, prevent, and remove malicious software, including computer viruses, from a computer system.");
            setValues(&c1.c_q[23], "Which of the following is an example of a cloud storage service?", "1) USB flash drive", "2) DVD-ROM", "3) Google Drive", "4) Solid State Drive (SSD)", 3, 10, 3, 2, "Cloud storage services allow users to store and access their files and data remotely over the internet.");
            setValues(&c1.c_q[24], "What is the purpose of an interrupt in a computer system?", "1) Execute program instructions", "2) Connect all the hardware components", "3) Provide power to the system", "4) Signal the CPU to pause its current activities and handle a specific event or condition", 4, 10, 4, 1, "Interrupts are used to handle time-critical events or tasks that require immediate attention from the CPU.");
            setValues(&c1.c_q[25], "Which of the following is an example of a firmware?", "1) Web browser", "2) Operating system", "3) Printer driver", "4) BIOS", 4, 10, 4, 3, "Firmware is a type of software that is permanently stored in hardware devices, such as the Basic Input/Output System (BIOS) of a computer.");

            random_Qnumber();

            for (int i = 0; i < 10; i++)
            {
                start_time = time(NULL);
                printf("\033[35m");
                printf("%d. ", i + 1);
                printf("\033[0m");
                askQuestion(&c1.c_q[questions[i]]);
                end_time = time(NULL);
                printf("\033[0;31m"); // ANSI escape code for red color
                printf("Time taken: %.2f seconds\n", elapsed);
                printf("\033[0m"); // ANSI escape code to reset color

                printf("\033[0;32m"); // ANSI escape code for green color
                printf("Press Enter to Continue.");
                printf("\033[0m"); // ANSI escape code to reset color
                getchar();
                getchar();
                time_taken += elapsed;
                system("cls");
            }

            printf("\033[1;33mThe Total Score is %d out of 100.\033[0m\n", Total_Score); // Yellow color for celebrating

            FILE *file_3 = fopen("ScoresEasy\\3_scores_CS.txt", "a");
            FILE *file_3_b = fopen("ScoresEasy\\3_scores_CS.dat", "rb");
            setScore(file_3, Total_Score, Name, time_taken);
            fclose(file_3);

            if (file_3_b == NULL)
            {
                printf("File not available !!");
                return;
            }

            while (fread(&currStudent, sizeof(Student), 1, file_3_b) == 1)
                students[numPlayers++] = currStudent;

            fclose(file_3_b);

            qsort(students, numPlayers, sizeof(Student), compareStudents);

            FILE *file_3_w = fopen("ScoresEasy\\3_scores_CS.dat", "wb");
            leaderboard(file_3_w, students, &numPlayers, Total_Score, Name, time_taken);
            break;
        case 4:
            setValues(&d1.d_q[0], "Which data structure is based on the \"First-In-First-Out\" (FIFO) principle?", "1) Stack", "2) Queue", "3) Heap", "4) Linked List", 2, 10, 2, 4, "Think about the order in which elements are accessed or removed from the structure.");
            setValues(&d1.d_q[1], "Which sorting algorithm has a worst-case time complexity of O(n^2)?", "1) Merge Sort", "2) Quick Sort", "3) Insertion Sort", "4) Heap Sort", 3, 10, 3, 1, "Consider the sorting algorithms that involve comparing and swapping elements.");
            setValues(&d1.d_q[2], "What is the time complexity of searching for an element in a balanced binary search tree?", "1) O(n)", "2) O(log n)", "3) O(n log n)", "4) O(1)", 2, 10, 2, 3, "Think about the property that makes a binary search tree balanced.");
            setValues(&d1.d_q[3], "Which data structure is efficient for implementing a LIFO (Last-In-First-Out) order of elements?", "1) Queue", "2) Array", "3) Linked List", "4) Stack", 4, 10, 4, 1, "Consider the order in which elements are accessed or removed from the structure.");
            setValues(&d1.d_q[4], "What is the worst-case time complexity of the quicksort algorithm?", "1) O(n)", "2) O(log n)", "3) O(n^2)", "4) O(n log n)", 3, 10, 3, 2, "Consider the best and worst-case scenarios for quicksort.");
            setValues(&d1.d_q[5], "Which data structure uses a \"hash function\" for efficient insertion and retrieval of elements?", "1) Queue", "2) Heap", "3) Hash Table", "4) Binary Search Tree", 3, 10, 3, 1, "Think about the mechanism that allows constant-time access to elements.");
            setValues(&d1.d_q[6], "Which searching algorithm requires a sorted array as input?", "1) Linear Search", "2) Binary Search", "3) Depth-First Search", "4) Breadth-First Search", 2, 10, 2, 4, "Consider the algorithm that divides the search space in half at each step.");
            setValues(&d1.d_q[7], "Which data structure represents a hierarchical relationship between elements?", "1) Graph", "2) Linked List", "3) Tree", "4) Stack)", 3, 10, 3, 1, "Think about the structure that consists of nodes with parent-child relationships.");
            setValues(&d1.d_q[8], "Which algorithm is used to find the shortest path between two vertices in a weighted graph?", "1) Depth-First Search", "2) Breadth-First Search", "3) Dijkstra's Algorithm", "4) Bellman-Ford Algorithm", 3, 10, 3, 2, "Consider the algorithm that takes edge weights into account.");
            setValues(&d1.d_q[9], "Which data structure provides constant-time insertion, deletion, and retrieval of the minimum and maximum elements?", "1) Heap", "2) Queue", "3) Stack", "4) Linked List", 1, 10, 1, 3, "Think about the structure that maintains the order of elements based on their priority.");
            setValues(&d1.d_q[10], "Which data structure is used to implement a breadth-first search (BFS) traversal of a graph?", "1) Queue", "2) Stack", "3) Heap", "4) Linked List", 1, 10, 1, 4, "Think about the order in which vertices are processed in BFS.");
            setValues(&d1.d_q[11], "Which algorithm is used to find the minimum spanning tree in a connected, weighted graph?", "1) Depth-First Search", "2) Breadth-First Search", "3) Prim's Algorithm", "4) Kruskl's Algorithm)", 3, 10, 3, 1, "Consider the algorithm that greedily selects the minimum weight edges.");
            setValues(&d1.d_q[12], "What is the time complexity of searching for an element in a hash table in the average case?", "1) O(1)", "2) O(n)", "3) O(log n)", "4) O(n log n))", 1, 10, 1, 3, "Think about the efficiency of the hash function and collision resolution technique.");
            setValues(&d1.d_q[13], "Which data structure is best suited for implementing a priority queue?", "1) Stack", "2) Linked List", "3) Heap", "4) Queue", 3, 10, 3, 4, "Consider the data structure that efficiently supports extracting the highest priority element.");
            setValues(&d1.d_q[14], ".What is the time complexity of merging two sorted arrays of sizes n and m, respectively?", "1) O(n)", "2) O(m)", "3) O(n + m)", "4) O(n * m)", 3, 10, 3, 1, "Think about the number of comparisons required to merge the arrays.");
            setValues(&d1.d_q[15], "Which algorithm is used to find the longest increasing subsequence in an array?", "1) Dijkstra's Algorithm", "2) Bellman-Ford Algorithm", "3) Prim's Algorithm", "4) Dynamic Programming", 4, 10, 4, 1, "Consider the approach that breaks down the problem into smaller subproblems.");
            setValues(&d1.d_q[16], "Which data structure is used to implement undo-redo functionality in a text editor?", "1) Queue", "2) Stack", "3) Heap", "4) Linked List", 2, 10, 2, 3, "Think about the order in which operations need to be performed for undo-redo.");
            setValues(&d1.d_q[17], "What is the time complexity of performing a matrix multiplication of two n x n matrices using the standard algorithm?", "1) O(1)", "2) O(n)", "3) O(n^2)", "4) O(n^3)", 4, 10, 4, 3, "Think about the number of multiplications required for each entry in the resulting matrix.");
            setValues(&d1.d_q[18], "Which algorithm is used to find the maximum flow in a network?", "1) Depth-First Search", "2) Breadth-First Search", "3) Dijkstra's Algorithm", "4) Ford-Fulkerson Algorithm", 4, 10, 4, 1, "Consider the algorithm that repeatedly augments the flow along the path.");
            setValues(&d1.d_q[19], "Which data structure is used to implement the undo operation in a text editor?", "1) Stack", "2) Queue", "3) Linked List", "4) Heap", 1, 10, 1, 3, "Think about the data structure that stores unique elements and supports efficient membership checking.");
            setValues(&d1.d_q[20], "Which algorithm is used to find the strongly connected components in a directed graph?", "1) Breadth-First Search", "2) Depth-First Search", "3) Dijkstra's Algorithm", "4) Kruskal's Algorithm", 2, 10, 2, 4, "Consider the algorithm that explores the graph by traversing through its vertices.");
            setValues(&d1.d_q[21], "Which data structure is used to efficiently check if an element is present or not?", "1) Queue", "2) Stack", "3) Set", "4) Linked List", 3, 10, 3, 4, "Think about the data structure that stores unique elements and supports efficient membership checking.");
            setValues(&d1.d_q[22], "What is the time complexity of a balanced binary search tree's operations in the worst case?", "1) O(n)", "2) O(log n)", "3) O(n log n)", "4) O(1)", 2, 10, 2, 4, "Think about the height of a balanced binary search tree.");
            setValues(&d1.d_q[23], "Which data structure is used to implement the call stack in most programming languages?", "1) Queue", "2) Stack", "3) Heap", "4) Linked List", 2, 10, 2, 1, "Think about the Last-In-First-Out (LIFO) property required for function calls.");
            setValues(&d1.d_q[24], "What is the time complexity of the radix sort algorithm?", "1) O(n)", "2) O(n^2)", "3) O(kn)", "4) O(n log n)", 3, 10, 3, 4, "Think about the number of passes required for sorting the digits.");
            setValues(&d1.d_q[25], "Which data structure is used to implement the backtracking algorithm?", "1) Queue", "2) Stack", "3) Heap", "4) Linked List", 2, 10, 2, 4, "Think about the Last-In-First-Out (LIFO) property required for backtracking.");

            random_Qnumber();

            for (int i = 0; i < 10; i++)
            {
                start_time = time(NULL);
                printf("\033[35m");
                printf("%d. ", i + 1);
                printf("\033[0m");
                askQuestion(&d1.d_q[questions[i]]);
                end_time = time(NULL);
                elapsed = difftime(end_time, start_time);
                printf("\033[0;31m"); // ANSI escape code for red color
                printf("Time taken: %.2f seconds\n", elapsed);
                printf("\033[0m"); // ANSI escape code to reset color

                printf("\033[0;32m"); // ANSI escape code for green color
                printf("Press Enter to Continue.");
                printf("\033[0m"); // ANSI escape code to reset color
                time_taken += elapsed;
                getchar();
                getchar();

                system("cls");
            }

            printf("\033[1;33mThe Total Score is %d out of 100.\033[0m\n", Total_Score); // Yellow color

            FILE *file_4 = fopen("ScoresEasy\\4_scores_DS.txt", "a");
            FILE *file_4_b = fopen("ScoresEasy\\4_scores_DS.dat", "rb");
            setScore(file_4, Total_Score, Name, time_taken);
            fclose(file_4);

            if (file_4_b == NULL)
            {
                printf("File not available !!");
                return;
            }

            while (fread(&currStudent, sizeof(Student), 1, file_4_b) == 1)
                students[numPlayers++] = currStudent;

            fclose(file_4_b);

            qsort(students, numPlayers, sizeof(Student), compareStudents);

            FILE *file_4_w = fopen("ScoresEasy\\4_scores_DS.dat", "wb");
            leaderboard(file_4_w, students, &numPlayers, Total_Score, Name, time_taken);
            break;
        case 5:
            setValues(&s1.s_q[0], "What is the primary purpose of a compiler?", "1) Execute programs", "2) Interpret source code", "3) Translate source code to machine code", "4) Debug programs", 3, 10, 3, 4, "A compiler converts high-level programming languages into low-level machine code.");
            setValues(&s1.s_q[1], "What is the purpose of the lexical analysis phase in a compiler?", "1) Performs syntax checking", "2) Builds the symbol table", "3) Breaks the source code into tokens", "4) Generates optimized code", 3, 10, 3, 1, "Lexical analysis scans the source code and breaks it into meaningful units called tokens.");
            setValues(&s1.s_q[2], "What is the purpose of the semantic analysis phase in a compiler?", "1) Checks for syntax errors", "2) Generates intermediate code", "3) Resolves variable references and enforces language semantics", "4) Performs optimization", 3, 10, 3, 1, "Semantic analysis ensures that the program adheres to the rules and constraints of the programming language.");
            setValues(&s1.s_q[3], "Which optimization technique reduces the number of memory accesses in a program?", "1) Loop unrolling", "2) Common subexpression elimination", "3) Dead code elimination", "4) Register allocation", 1, 10, 1, 2, "Loop unrolling reduces the overhead of loop control and memory accesses by duplicating loop iterations.");
            setValues(&s1.s_q[4], "What is the purpose of the semantic analysis phase in a compiler?", "1) Checks for syntax errors", "2) Generates intermediate code", "3) Resolves variable references and enforces language semantics", "4) Performs optimization", 3, 10, 3, 4, "Semantic analysis ensures that the program adheres to the rules and constraints of the programming language.");
            setValues(&s1.s_q[5], "which of the following is an example of a top-down parsing technique?", "1) Recursive Descent", "2) LR Parsing", "3) LALR Parsing", "4) Shift-Reduce Parsing", 1, 10, 1, 2, "Recursive Descent is a top-down parsing technique where each non-terminal in the grammar has a corresponding parsing function.");
            setValues(&s1.s_q[6], "What does the acronym \"LLVM\" stand for in the context of compilers?", "1) Low-Level Virtual Machine", "2) Language-Level Verification Model", "3) Linker and Loader for Virtual Machines", "4) Lightweight Language Validation Mechanism", 1, 10, 1, 3, "LLVM is a compiler infrastructure project that provides a collection of modular and reusable compiler and toolchain technologies.");
            setValues(&s1.s_q[7], "Which phase of the compiler performs type checking?", "1) Lexical Analysis", "2) Syntax Analysis", "3) Semantic Analysis", "4) Code Generation", 3, 10, 3, 1, "Semantic analysis verifies the compatibility and correctness of types used in the program.");
            setValues(&s1.s_q[8], "Which technique is used to convert an infix expression to postfix in a compiler?", "1) Abstract Syntax Tree (AST)", "2) Operator Precedence Parsing", "3) Recursive Descent Parsing", "4) Dangling Else Problem", 2, 10, 2, 3, "Operator precedence parsing converts infix expressions to postfix using operator precedence and associativity rules.");
            setValues(&s1.s_q[9], "Which of the following is an example of a code optimization technique?", "1) Lexical Analysis", "2) Syntax Analysis", "3) Dead Code Elimination", "4) Tokenization", 3, 10, 3, 1, "Dead code elimination removes code that does not affect the program's output.");
            setValues(&s1.s_q[10], "Which phase of the compiler performs constant folding and propagation?", "1) Lexical Analysis", "2) Syntax Analysis", "3) Semantic Analysis", "4) Code Optimization", 4, 10, 4, 3, "Constant folding and propagation simplify expressions by evaluating constant expressions at compile-time.");
            setValues(&s1.s_q[11], "What is the primary purpose of an operating system?", "1) Manage hardware components", "2) Run application software", "3) Provide user interfaces", "4) Control and coordinate computer resources", 4, 10, 4, 2, "The operating system manages and allocates computer resources such as CPU, memory, and devices.");
            setValues(&s1.s_q[12], "What is the role of the kernel in an operating system?", "1) Provides user interfaces", "2) Executes application software", "3) Manages system resources", "4) Controls input/output operations", 3, 10, 3, 1, "The kernel is the core component of an operating system that manages system resources and provides essential services.");
            setValues(&s1.s_q[13], "Which scheduling algorithm is based on priority assigned to each process?", "1) Round Robin", "2) First-Come, First-Served (FCFS)", "3) Shortest Job Next (SJN)", "4) Priority Scheduling", 4, 10, 4, 2, "Priority Scheduling assigns priority values to each process and schedules them based on their priority.");
            setValues(&s1.s_q[14], "Which memory management technique allows processes to be allocated memory in non-contiguous blocks?", "1) Paging", "2) Segmentation", "3) Swapping", "4) Fragmentation", 2, 10, 2, 4, "Segmentation divides the main memory into variable-sized segments to accommodate processes.");
            setValues(&s1.s_q[15], "What is assembly language?", "1) A high-level programming language", "2) A low-level programming language", "3) A scripting language", "4) A markup language", 2, 10, 2, 4, "Assembly language is a low-level programming language that is closely related to machine code and specific to a particular processor architecture.");
            setValues(&s1.s_q[16], "Which of the following is NOT true about assembly language?", "1) It is easier to understand than machine code", "2) It is directly executed by the processor", "3) It uses mnemonic instructions and symbolic labels", "4) It is portable across different processor architectures", 4, 10, 4, 3, "Assembly language is specific to a particular processor architecture and is not portable across different architectures.");
            setValues(&s1.s_q[17], "What is the purpose of an assembler?", "1) To execute assembly language programs", "2) To translate assembly language to machine code", "3) To provide an interactive programming environment", "4) To debug assembly language programs", 2, 10, 2, 1, "An assembler converts assembly language instructions into machine code that can be directly executed by the processor.");
            setValues(&s1.s_q[18], "Which of the following is a valid assembly language instruction?", "1) ADD R1, R2", "2) PRINT \"Hello, World!\"", "3) IF-ELSE", "4) FOR Loop", 1, 10, 1, 4, "Assembly language instructions typically consist of an operation mnemonic followed by operands, such as registers or memory addresses.");
            setValues(&s1.s_q[19], "Which component of the computer is responsible for executing assembly language instructions?", "1) Central Processing Unit (CPU)", "2) Random Access Memory (RAM)", "3) Hard Disk Drive (HD4)", "4) Graphics Processing Unit (GPU)", 1, 10, 1, 3, "The CPU is the component of the computer that executes instructions, including assembly language instructions.");
            setValues(&s1.s_q[20], "Which of the following is NOT a typical register found in a processor?", "1) Accumulator", "2) Instruction Register", "3) Memory Address Register", "4) Control Register", 2, 10, 2, 4, "The instruction register holds the current instruction being executed, but it is not a general-purpose register.");
            setValues(&s1.s_q[21], "What is the purpose of the MOV instruction in assembly language?", "1) Move data between registers or memory locations", "2) Add two values", "3) Compare two values", "4) Jump to a different instruction", 1, 10, 1, 4, "The MOV instruction is used to transfer (move) data between registers or memory locations.");
            setValues(&s1.s_q[22], "Which of the following is a conditional jump instruction in assembly language?", "1) MOV", "2) ADD", "3) JMP", "4) CALL", 3, 10, 3, 4, "The JMP instruction is used for an unconditional jump, while conditional jumps depend on certain conditions.");
            setValues(&s1.s_q[23], "What is a macro in programming?", "1) A type of data structure", "2) A high-level programming language", "3) A reusable piece of code", "4) A database management system", 3, 10, 3, 2, "Macros are reusable code snippets that can be expanded inline in a program.");
            setValues(&s1.s_q[24], "What is the primary purpose of using macros?", "1) To improve code readability", "2) To reduce code duplication", "3) To increase code portability", "4) To optimize program execution", 2, 10, 2, 3, "Macros help in reducing code duplication by allowing you to define reusable code segments.");
            setValues(&s1.s_q[25], "Which programming languages support macros?", "1) Only high-level languages like Python and Java", "2) Only low-level languages like Assembly", "3) Both high-level and low-level languages", "4) None of the above", 3, 10, 3, 1, "Macros are supported in both high-level and low-level languages, although the syntax and usage may vary.");

            random_Qnumber();

            for (int i = 0; i < 10; i++)
            {
                start_time = time(NULL);
                printf("\033[35m");
                printf("%d. ", i + 1);
                printf("\033[0m");
                askQuestion(&s1.s_q[questions[i]]);
                end_time = time(NULL);
                elapsed = difftime(end_time, start_time);
                printf("\033[0;31m"); // ANSI escape code for red color
                printf("Time taken: %.2f seconds\n", elapsed);
                printf("\033[0m"); // ANSI escape code to reset color

                printf("\033[0;32m"); // ANSI escape code for green color
                printf("Press Enter to Continue.");
                printf("\033[0m"); // ANSI escape code to reset color
                time_taken += elapsed;
                getchar();
                getchar();

                system("cls");
            }

            printf("\033[1;33mThe Total Score is %d out of 100.\033[0m\n", Total_Score); // Yellow color for celebrating

            FILE *file_5 = fopen("ScoresEasy\\5_scores_SP.txt", "a");
            FILE *file_5_b = fopen("ScoresEasy\\5_scores_SP.dat", "rb");
            setScore(file_5, Total_Score, Name, time_taken);
            fclose(file_5);

            if (file_5_b == NULL)
            {
                printf("File not available !!");
                return;
            }

            while (fread(&currStudent, sizeof(Student), 1, file_5_b) == 1)
                students[numPlayers++] = currStudent;

            fclose(file_5_b);

            qsort(students, numPlayers, sizeof(Student), compareStudents);

            FILE *file_5_w = fopen("ScoresEasy\\5_scores_SP.dat", "wb");
            leaderboard(file_5_w, students, &numPlayers, Total_Score, Name, time_taken);
            break;
        case 6:
            setValues(&g1.g_q[0], " What is always in front of you but can't be seen?", "1) Future", "2) Mirror", "3) Air", "4) Memory", 1, 10, 1, 3, "It refers to the concept of time.");
            setValues(&g1.g_q[1], " What has keys but can't open locks?", "1) Piano", "2) Keyboard", "3) Map", "4) Tree", 1, 10, 1, 4, "It produces sounds when you press its keys.");
            setValues(&g1.g_q[2], "The more you take, the more you leave behind. What am I?", "1) Footsteps", "2) Breath", "3) Time", "4) Knowledge", 3, 10, 3, 1, " It refers to a non-physical concept.");
            setValues(&g1.g_q[3], "I speak without a mouth and hear without ears. I have no body, but I come alive with wind. What am I?", "1) Whisper", "2) Echo", "3) Dream", "4) Thought", 2, 10, 2, 1, "You often hear it in nature.");
            setValues(&g1.g_q[4], "What has a heart that doesn't beat?", "1) Clock", "2) Human", "3) Computer", "4) Tomato", 1, 10, 1, 2, "It is a common household item.");
            setValues(&g1.g_q[5], "I can be cracked, made, told, and played. What am I?", "1) Joke", "2) Egg", "3) Music", "4) Riddle", 1, 10, 1, 3, " It involves creativity.");
            setValues(&g1.g_q[6], "What gets wetter the more it dries?", "1) Towel", "2) Soap", "3) Hair", "4) Table", 1, 10, 1, 3, "It is used for drying.");
            setValues(&g1.g_q[7], "I am always hungry, I must always be fed. The finger I touch will soon turn red. What am I?", "1) Fire", "2) Baby", "3) Shark", "4) Spider", 1, 10, 1, 3, "It requires fuel to continue.");
            setValues(&g1.g_q[8], "The more you have of it, the less you see. What is it?", "1) Darkness", "2) Wisdom", "3) Sleep", "4) Mist", 1, 10, 1, 4, "It refers to a lack of something.");
            setValues(&g1.g_q[9], "I can fly without wings. I can cry without eyes. Wherever I go, darkness follows me. What am I?", "1) Wind", "2) Ghost", "3) Cloud", "4) Moon", 3, 10, 3, 4, " It is related to weather.");
            setValues(&g1.g_q[10], "I have cities but no houses, forests but no trees, and rivers but no water. What am I?", "1) Map", "2) Globe", "3) Book", "4) Dream", 1, 10, 1, 2, "It provides information.");
            setValues(&g1.g_q[11], " What goes up but never comes down?", "1) Age", "2) Happiness", "3) Energy", "4) Balloon", 1, 10, 1, 3, "It refers to a natural process.");
            setValues(&g1.g_q[12], " I am an odd number. Take away one letter and I become even. What number am I?", "1) One", "2) Three", "3) Five", "4) Seven", 4, 10, 4, 3, "Pay attention to the wording.");
            setValues(&g1.g_q[13], "The more you take, the more you leave behind. What am I", "1) Steps", "2) Footprints", "3) Time", "4) Money", 3, 10, 3, 2, "It refers to a non-physical concept.");
            setValues(&g1.g_q[14], "What can you catch but not throw?", "1) Cold", "2) Ball", "3) Fish", "4) Air", 1, 10, 1, 4, "It is an illness.");
            setValues(&g1.g_q[15], "The person who makes it, sells it. The person who buys it, never uses it. The person who uses it, never knows they're using it. What is it?", "1) Coffin", "2) Pen", "3) Bed", "4) Car", 1, 10, 1, 3, "It is related to a somber event.");
            setValues(&g1.g_q[16], "I am not alive, but I can grow; I don't have lungs, but I need air; I don't have a mouth, but water kills me. What am I?", "1) Fire", "2) Tree", "3) Cloud", "4) Candle", 1, 10, 1, 4, "It is a common household item.");
            setValues(&g1.g_q[17], "What has keys that open no locks, space but no room, and you can enter but not go in?", "1) Keyboard", "2) Piano", "3) Map", "4) Website", 4, 10, 4, 3, "It is a virtual space.");
            setValues(&g1.g_q[18], " What has a neck but no head?", "1) Bottle", "2) Giraffe", "3) Shirt", "4) Pen", 1, 10, 1, 2, "It is a common object.");
            setValues(&g1.g_q[19], " What can be seen once in a minute, twice in a moment, and never in a thousand years?", "1) Opportunity", "2) Reflection", "3) Lightning", "4) Star", 3, 10, 3, 2, "It is a natural phenomenon.");
            setValues(&g1.g_q[20], " I am taken from a mine and shut in a wooden case, from which I am never released, and yet I am used by almost every person. What am I?", "1) Coal", "2) Oxygen", "3) Gold", "4) Pencil Lead", 4, 10, 4, 1, "You use it to write or draw.");
            setValues(&g1.g_q[21], "What has a thumb and four fingers, but is not alive?", "1) Glove", "2) Statue", "3) Handprint", "4) Puppet", 1, 10, 1, 3, "It is often worn.");
            setValues(&g1.g_q[22], "The more you work, the more I'll eat. You keep me full, I'll keep you neat. What am I?", "1) Time", "2) Money", "3) Vacuum cleaner", "4) Hunger", 3, 10, 3, 4, "It involves cleanliness");
            setValues(&g1.g_q[23], " What has a face and two hands but no arms or legs?", "1) Clock", "2) Mirror", "3) Sun", "4) Ball", 1, 10, 1, 3, "It helps you keep track of time.");
            setValues(&g1.g_q[24], " What has keys but can't open locks?", "1) Piano", "2) Keyboard", "3) Map", "4) Tree", 1, 10, 1, 2, "It produces sounds when you press its keys.");
            setValues(&g1.g_q[25], "I can be cracked, made, told, and played. What am I?", "1) Joke", "2) Egg", "3) Music", "4) Riddle", 4, 10, 4, 3, "It involves creativity.");
            random_Qnumber();

            for (int i = 0; i < 10; i++)
            {
                start_time = time(NULL);
                printf("\033[35m");
                printf("%d. ", i + 1);
                printf("\033[0m");
                askQuestion(&g1.g_q[questions[i]]);
                end_time = time(NULL);
                elapsed = difftime(end_time, start_time);
                printf("\033[0;31m"); // ANSI escape code for red color
                printf("Time taken: %.2f seconds\n", elapsed);
                printf("\033[0m"); // ANSI escape code to reset color

                printf("\033[0;32m"); // ANSI escape code for green color
                printf("Press Enter to Continue.");
                printf("\033[0m"); // ANSI escape code to reset color
                time_taken += elapsed;
                getchar();
                getchar();

                system("cls");
            }

            printf("\033[1;33mThe Total Score is %d out of 100.\033[0m\n", Total_Score); // Yellow color for celebrating

            FILE *file_6 = fopen("ScoresEasy\\6_scores_R.txt", "a");
            FILE *file_6_b = fopen("ScoresEasy\\6_scores_R.dat", "rb");
            setScore(file_6, Total_Score, Name, time_taken);
            fclose(file_6);

            if (file_6_b == NULL)
            {
                printf("File not available !!");
                return;
            }

            while (fread(&currStudent, sizeof(Student), 1, file_6_b) == 1)
                students[numPlayers++] = currStudent;

            fclose(file_6_b);

            qsort(students, numPlayers, sizeof(Student), compareStudents);

            FILE *file_6_w = fopen("ScoresEasy\\6_scores_R.dat", "wb");
            leaderboard(file_6_w, students, &numPlayers, Total_Score, Name, time_taken);
            break;

        default:
            break;
        }
    }

    else if (diff == 2)
    {
        switch (n)
        {
        case 1:
            setValues(&p1.p_q[0], "What is the output of the following code snippet?\n#include <stdio.h>\nint main(){\nint x = 3;\nprintf(\"%d\", ++x * x++);\nreturn 0;\n}", "1) 12", "2) 15", "3) 16", "4) Undefined", 3, 10, 1, 3, "Understand the order of evaluation and side effects in expressions.");
            setValues(&p1.p_q[1], "What is the output of the code snippet below?#include <stdio.h>\nint main() {\nint arr[5] = {1, 2, 3, 4, 5};\nint *ptr = arr;\nprintf(\"%d\", *(ptr++));\nreturn 0;\n}", "1) 1", "2) 2", "2) 3", "4) Compiler error", 1, 10, 1, 3, "The increment operator has higher precedence than the dereference operator.");
            setValues(&p1.p_q[2], "What will be the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint x = 5;\nint y = 3;\nprintf(\"%d\", x%-y);\nreturn 0;\n}", "1) 2", "2) -2", "3) Compiler error", "4) Undefined", 2, 10, 1, 2, "Understand the behavior of the modulus operator with negative operands.");
            setValues(&p1.p_q[3], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint a = 7;\nint b = 4;\nprintf(\"%f\", (float)a / 2);\nreturn 0;\n}", "1) 1.75", "2) 1", "3) 1.0", "4) Compiler error", 1, 10, 1, 3, "The expression (float)a / b performs a floating-point division.");
            setValues(&p1.p_q[4], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint x = 0;\nprintf(\"%d\", x++);\nprintf(\"%d\", x);\nreturn 0;\n}", "1) 0 0", "2) 0 1", "3) 1 1", "4) Undefined", 2, 10, 2, 3, "Understand the postfix increment operator's behavior.");
            setValues(&p1.p_q[5], "What will be the value of x after the execution of the following code?\n#include <stdio.h>\nint main() {\nint x = 5;\nx *= x + 2;\nprintf(\"%d\", x);\nreturn 0;\n}", "1) 21", "2) 35", "3) 49", "4) 54", 3, 10, 1, 3, "The compound assignment operator *= performs multiplication and assignment.");
            setValues(&p1.p_q[6], "What will be the output of the code snippet below?\n#include <stdio.h>\nint main() {\nint a = 5;\nint b = 2;\nprintf(\"%d\", a+++2);\nreturn 0;\n}", "1) 7", "2) 8", "3) 9", "4) Compiler error", 2, 10, 2, 4, "Pay attention to the order of operations and the postfix increment operator.");
            setValues(&p1.p_q[7], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nchar str[] = \"Hello\";\nprintf(\"%c\", str[5]);\nreturn 0;\n}", "1) H", "2) e", "3) o", "4) Compiler error", 3, 10, 1, 3, "Array indices start from 0.");
            setValues(&p1.p_q[8], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint a = 5;\nint b = 7;\nprintf(\"%d\", a > b ? a : 2);\nreturn 0;\n}", "1) 5", "2) 7", "3) Compiler error", "4) Undefined", 2, 10, 2, 3, "Understand the ternary conditional operator.");
            setValues(&p1.p_q[9], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint x = 10;\nif (x > 5)\nprintf(\"Hello\");\nelse if (x > 7)\nprintf(\"World\");\nelse\nprintf(\"Hi\");\nreturn 0;\n}", "1) Hello", "2) World", "3) Hi", "4) Compiler error", 1, 10, 1, 3, "The condition in the first if statement is satisfied.");
            setValues(&p1.p_q[10], "What will be the value of x after the execution of the following code?\n#include <stdio.h>\nint main() {\nint x = 10;\nif (x > 5) {\nx = 5;\n} else if (x > 7) {\nx = 7;\n}\nprintf(\"%d\", x);\nreturn 0;\n}", "1) 5", "2) 7", "3) 10", "4) Undefined", 1, 10, 1, 3, "Understand the flow of control in an if-else ladder.");
            setValues(&p1.p_q[11], "What will be the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint x = 5;\nint y = 3;\nprintf(\"%d\", x & y);\nreturn 0;\n}", "1) 1", "2) 3", "3) 5", "4) Compiler error", 1, 10, 1, 3, "Understand the bitwise AND operator.");
            setValues(&p1.p_q[12], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint arr[] = {1, 2, 3};\nprintf(\"%d\", arr[3]);\nreturn 0;\n}", "1) 1", "2) 2", "3) 3", "4) Compiler error", 4, 10, 2, 4, "The array arr has only three elements.");
            setValues(&p1.p_q[13], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint x = 3;\nprintf(\"%d\", x++);\nprintf(\"%d\", ++x);\nreturn 0;\n}", "1) 34", "2) 43", "3) 44", "4) Undefined", 2, 10, 2, 4, "Understand the behavior of the increment operator.");
            setValues(&p1.p_q[14], "What will be the value of x after the execution of the following code?\n#include <stdio.h>\nint main() {\nint x = 5;\nx = x++ + ++x;\nprintf(\"%d\", x);\nreturn 0;\n}", "1) 11", "2) 12", "3) 13", "4) Undefined", 3, 10, 1, 3, "Understand the order of evaluation and side effects in expressions.");
            setValues(&p1.p_q[15], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nchar str[] = \"Hello\";\nprintf(\"%c\", *(str + 1));\nreturn 0;\n}", "1) H", "2) e", "3) o", "4) Compiler error", 2, 10, 1, 2, "Understand how pointer arithmetic works with arrays.");
            setValues(&p1.p_q[16], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint a = 5;\nint b = 7;\nprintf(\"%d\", a & 2);\nreturn 0;\n}", "1) 1", "2) 4", "3) 5", "4) Compiler error", 1, 10, 1, 3, "Understand the bitwise AND operator.");
            setValues(&p1.p_q[17], "What will be the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint x = 5;\nint y = 3;\nprintf(\"%d\", x | y);\nreturn 0;\n}", "1) 1", "2) 3", "3) 5", "4) Compiler error", 3, 10, 1, 3, "Understand the bitwise OR operator.");
            setValues(&p1.p_q[18], "What will be the value of x after the execution of the following code?\n#include <stdio.h>\nint main() {\nint x = 5;\nif (x > 5) {\nx = 10;\n} else if (x < 5) {\nx = 15;\n}\nprintf(\"%d\", x);\nreturn 0;\n}", "1) 5", "2) 10", "3) 15", "4) Undefined", 1, 10, 1, 4, "Understand the flow of control in an if-else ladder.");
            setValues(&p1.p_q[19], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint arr[] = {1, 2, 3};\nprintf(\"%d\", *arr);\nreturn 0;\n}", "1) 1", "2) 2", "3) 3", "4) Compiler error", 1, 10, 1, 4, "The array name can be treated as a pointer to the first element.");
            setValues(&p1.p_q[20], "What will be the value of x after the execution of the following code?\n#include <stdio.h>\nint main() {\nint x = 5;\nx = x - - - x;\nprintf(\"%d\", x);\nreturn 0;\n}", "1) 2", "2) 5", "3) 6", "4) Undefined", 3, 10, 1, 3, "Pay attention to the unary minus operator.");
            setValues(&p1.p_q[21], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint x = 10;\nprintf(\"%d\", x << 1);\nreturn 0;\n}", "1) 5", "2) 10", "3) 20", "4) Compiler error", 3, 10, 3, 4, "Understand the left shift operator.");
            setValues(&p1.p_q[22], "What will be the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint x = 5;\nprintf(\"%d\", ~x);\nreturn 0;\n}", "1) -5", "2) -6", "3) 4", "4) 5", 1, 10, 1, 2, "Understand the bitwise complement operator.");
            setValues(&p1.p_q[23], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint x = 5;\nint y = x > 3 && x < 10;\nprintf(\"%d\", y);\nreturn 0;\n}", "1) 0", "2) 1", "3) 3", "4) Compiler error", 2, 10, 2, 3, "Understand the logical AND operator.");
            setValues(&p1.p_q[24], "What is the output of the following code snippet?\n#include <stdio.h>\nint main() {\nint x = 5;\nint y = 3;\nprintf(\"%d\", x ^ y);\nreturn 0;\n}", "1) 2", "2) 3", "3) 5", "4) Compiler error", 1, 10, 1, 4, "Understand the bitwise XOR operator.");
            setValues(&p1.p_q[25], "What is the purpose of the \"fwrite\" function in C?", "1) To write data to a file", "2) To read data from a file", "3) To copy a file", "4) To delete a file", 1, 10, 1, 2, "The \"fwrite\" function is used to write data from memory to a file.");

            random_Qnumber();

            for (int i = 0; i < 10; i++)
            {
                start_time = time(NULL);
                printf("\033[35m");
                printf("%d. ", i + 1);
                printf("\033[0m");
                askQuestion(&p1.p_q[questions[i]]);
                end_time = time(NULL);
                elapsed = difftime(end_time, start_time);
                printf("\033[0;31m"); // ANSI escape code for red color
                printf("Time taken: %.2f seconds\n", elapsed);
                printf("\033[0m"); // ANSI escape code to reset color

                printf("\033[0;32m"); // ANSI escape code for green color
                printf("Press Enter to Continue.");
                printf("\033[0m"); // ANSI escape code to reset color
                getchar();
                getchar();
                time_taken += elapsed;
                system("cls");
            }

            printf("\033[1;33mThe Total Score is %d out of 100.\033[0m\n", Total_Score); // Yellow color for celebrating

            FILE *file_1 = fopen("ScoresHard\\1_scores_CP.txt", "a");
            FILE *file_1_b = fopen("ScoresHard\\1_scores_CP.dat", "rb");
            setScore(file_1, Total_Score, Name, time_taken);
            fclose(file_1);

            if (file_1_b == NULL)
            {
                printf("File not available !!");
                return;
            }

            while (fread(&currStudent, sizeof(Student), 1, file_1_b) == 1)
                students[numPlayers++] = currStudent;

            fclose(file_1_b);

            qsort(students, numPlayers, sizeof(Student), compareStudents);

            FILE *file_1_w = fopen("ScoresHard\\1_scores_CP.dat", "wb");
            leaderboard(file_1_w, students, &numPlayers, Total_Score, Name, time_taken);
            break;
        case 2:
            setValues(&e1.e_q[0], "What is the purpose of an orthographic projection in engineering drawing?", "1) To represent a 3D object in a 2D format", "2) To create an isometric view of an object", "3) To show different views of an object simultaneously", "4) To add dimensions to an objct ", 1, 10, 1, 4, "Orthographic projection is a technique used to represent objects in a series of two-dimensional views.");
            setValues(&e1.e_q[1], "Which of the following geometric constructions is used to divide a line segment into equal parts?", "1) Compass and straightedge construction", "2) Isometric projection", "3) Sectional views", "4) Pictorial projections", 1, 10, 1, 2, "This construction technique involves drawing arcs of equal radii.");
            setValues(&e1.e_q[2], "What is the purpose of sectioning in engineering drawing?", "1) To show hidden features of an object", "2) To provide a detailed view of an object", "3) To represent the object's internal structure", "4) To define the object's material properties", 3, 10, 3, 2, "Sectioning involves cutting a solid object to reveal its interior details.");
            setValues(&e1.e_q[3], "Which type of line is used to represent the intersection of two surfaces in engineering drawing?", "1) Hidden line", "2) Centerline", "3) Construction line", "4) Section line", 1, 10, 1, 2, " This type of line is used to show the limit of intersection between two surfaces.");
            setValues(&e1.e_q[4], "What is the purpose of dimensioning in engineering drawing?", "1) To create accurate scale models", "2) To indicate the scale of the drawing", "3) To specify the size and location of features", "4) To represent the object in three dimension", 3, 10, 3, 1, "Dimensioning provides crucial information about the size and position of features in a drawing.");
            setValues(&e1.e_q[5], "Which type of projection shows the true shape and size of inclined surfaces in a drawing?", "1) Isometric projection", "2) Perspective projection", "3) Auxiliary projection", "4) Oblique projection", 4, 10, 4, 3, "This type of projection is used to represent inclined surfaces without distortion.");
            setValues(&e1.e_q[6], "Which type of line is used to represent the centerline of a cylindrical feature in engineering drawing?", "1) Hidden line", "2) Dimension line", "3) Extension line", "4)Centerline", 4, 10, 4, 2, "The centerline represents the axis of symmetry for cylindrical features.");
            setValues(&e1.e_q[7], "What does the abbreviation R.A. stand for in engineering drawing?", "1) Right Angle", "2) Radius of Arc", "3) Rectangular Area", "4) Roughness Average", 2, 10, 2, 4, "R.A. is commonly used to indicate the radius of an arc.");
            setValues(&e1.e_q[8], "Which type of projection is commonly used in architectural and furniture design to provide a realistic representation of the object?", "1) Isometric projection", "2) Oblique projection", "3) Orthographic projection", "4) Perspective projection", 4, 10, 4, 1, "This type of projection creates a sense of depth and realism in the drawing.");
            setValues(&e1.e_q[9], "Which of the following is used to indicate that a particular feature of an object is symmetrical?", "1) Centerline", "2) Hidden line", "3) Extension line", "4) Dimension line", 1, 10, 2, 1, "Symmetrical features are represented using a specific type of line.");
            setValues(&e1.e_q[10], "Which type of line is used to indicate the cutting plane in a sectional view?", "1) Hidden line", "2) Section line", "3) Centerline", "4) Dimension line", 2, 10, 2, 4, "This line type is used to show where the object has been cut to create the sectional view.");
            setValues(&e1.e_q[11], "Which type of projection is commonly used to represent the true shape and size of the features on an object's principal faces?", "1) Auxiliary projection", "2) Perspective projection", "3) Isometric projection", "4) Orthographic projection", 4, 10, 4, 2, "This type of projection shows multiple views of an object from different directions.");
            setValues(&e1.e_q[12], "What does the abbreviation C.L. stand for in engineering drawing?", "1) Centerline", "2) Clearance Level", "3) Cut Length", "4) Circumference Limit", 1, 10, 1, 2, "C.L. is commonly used to indicate the centerline of a feature.");
            setValues(&e1.e_q[13], "Which of the following is used to indicate the surface finish or texture of an object in engineering drawing?", "1) Centerline", "2) Hidden line", "3) Leader line", "4) Surface symbol", 4, 10, 4, 2, "This graphical symbol provides information about the surface quality of an object.");
            setValues(&e1.e_q[14], "Which type of line is used to connect a dimension line to the feature being dimensioned?", "1) Leader line", "2) Hidden line", "3) Extension line", "4) Centerline", 1, 10, 1, 3, "This line type is used to associate a dimension with the feature it is measuring.");
            setValues(&e1.e_q[15], "Which of the following is used to indicate the location of holes or other features relative to a reference point?", "1) Hidden line", "2) Centerline", "3) Extension line", "4) Leader line", 4, 10, 4, 2, "This line type is used to provide information about the location of features.");
            setValues(&e1.e_q[16], "What does the abbreviation C/S stand for in engineering drawing?", "1) Cross Section", "2) Center of Symmetry", "3) Clearance Space", "4) Cut Surface", 1, 10, 1, 3, "C/S is commonly used to indicate a cross-sectional view of an object.");
            setValues(&e1.e_q[17], "Which of the following is used to indicate that a feature extends beyond the limits of the drawing?", "1) Break line", "2) Hidden line", "3) Extension line", "4) Dimension line", 1, 10, 1, 4, "This line type is used to shorten long features for ease of drawing.");
            setValues(&e1.e_q[18], "What is the purpose of a revision triangle in engineering drawing?", "1) To indicate the scale of the drawing", "2) To show the direction of projection", "3) To mark changes or revisions made to the drawing", "4) To highlight critical dimensions", 3, 10, 3, 4, "A revision triangle is typically placed near areas of the drawing where changes have been made.");
            setValues(&e1.e_q[19], "Which of the following is used to represent a rounded or curved feature in engineering drawing?", "1) Hidden line", "2) Break line", "3) Section line", "4) Centerline", 1, 10, 2, 1, "This line type is used to represent the outline of curved surfaces.");
            setValues(&e1.e_q[20], "What is the purpose of an exploded view in engineering drawing?", "1) To show the internal structure of an object", "2) To indicate the scale of the drawing", "3) To provide a realistic representation of an object", "4) To illustrate the assembly sequence of an object", 4, 10, 4, 2, " An exploded view is commonly used in assembly drawings to show how components fit together.");
            setValues(&e1.e_q[21], "Which type of projection is commonly used to represent objects with inclined surfaces in a single view?", "1) Isometric projection", "2) Auxiliary projection", "3) Orthographic projection", "4) Oblique projection", 2, 10, 2, 4, "This type of projection is useful for representing objects with inclined surfaces at their true shape and size.");
            setValues(&e1.e_q[22], "Which type of line is used to represent the edge of a surface that is not visible in a particular view?", "1) Hidden line", "2) Dimension line", "3) Centerline", "4) Break line", 1, 10, 1, 4, "This type of line is used to indicate features that are obstructed or hidden from view.");
            setValues(&e1.e_q[23], "What is the purpose of an isometric scale in engineering drawing?", "1) To measure angles in isometric projection", "2) To measure the length and width of an isometric drawing", "3) To convert measurements from orthographic projection to isometric projection", "4) To create accurate isometric drawings with correct proportions", 4, 10, 4, 3, "An isometric scale is a specialized measuring tool used for isometric drawings.");
            setValues(&e1.e_q[24], "Which type of line is used to represent a long, narrow slot in an engineering drawing?", "1) Hidden line", "2) Phantom line", "3) Break line", "4) Centerline", 1, 10, 1, 4, "Hidden lines are used to represent the edges of a long, narrow slot in an engineering drawing.");
            setValues(&e1.e_q[25], "What does the abbreviation \"CONC\" typically represent in engineering drawings?", "1) Concentric", "2) Concrete", "3) Concentration", "3) Concentration", 2, 10, 1, 2, "The abbreviation \"CONC\" is commonly used to represent a concrete material or construction in engineering drawings.");

            random_Qnumber();

            for (int i = 0; i < 10; i++)
            {
                start_time = time(NULL);
                printf("\033[35m");
                printf("%d. ", i + 1);
                printf("\033[0m");
                askQuestion(&e1.e_q[questions[i]]);
                end_time = time(NULL);
                elapsed = difftime(end_time, start_time);
                printf("\033[0;31m"); // ANSI escape code for red color
                printf("Time taken: %.2f seconds\n", elapsed);
                printf("\033[0m"); // ANSI escape code to reset color

                printf("\033[0;32m"); // ANSI escape code for green color
                printf("Press Enter to Continue.");
                printf("\033[0m"); // ANSI escape code to reset color
                getchar();
                getchar();
                time_taken += elapsed;
                system("cls");
            }

            printf("\033[1;33mThe Total Score is %d out of 100.\033[0m\n", Total_Score); // Yellow color for celebrating

            FILE *file_2 = fopen("ScoresHard\\2_scores_EV.txt", "a");
            FILE *file_2_b = fopen("ScoresHard\\2_scores_EV.dat", "rb");
            setScore(file_2, Total_Score, Name, time_taken);
            fclose(file_2);

            if (file_2_b == NULL)
            {
                printf("File not available !!");
                return;
            }

            while (fread(&currStudent, sizeof(Student), 1, file_2_b) == 1)
                students[numPlayers++] = currStudent;
            fclose(file_2_b);

            qsort(students, numPlayers, sizeof(Student), compareStudents);

            FILE *file_2_w = fopen("ScoresHard\\2_scores_EV.dat", "wb");
            leaderboard(file_2_w, students, &numPlayers, Total_Score, Name, time_taken);
            break;
        case 3:
            setValues(&c1.c_q[0], "Which of the following RAID levels provides the highest level of fault tolerance?", "1) RAID 0", "2) RAID 1", "3) RAID 5", "4) RAID 10", 4, 10, 1, 4, "This RAID level combines striping and mirroring techniques.");
            setValues(&c1.c_q[1], "What is the purpose of a subnet mask in computer networking?", "1) To determine the default gateway", "2) To identify the network address", "3) To encrypt data transmission", "4) To assign IP addresses dynamically", 2, 10, 2, 3, "It is used to divide an IP address into network and host portions.");
            setValues(&c1.c_q[2], "What is the purpose of an interrupt in a computer system?", "1) To stop the execution of a program", "2) To synchronize the activities of multiple processes", "3) To request a service from the operating system", "4) To allocate memory for a new process", 3, 10, 1, 3, "It allows the CPU to temporarily suspend its current activities.");
            setValues(&c1.c_q[3], "In computer graphics, what does the acronym \"GPU\" stand for?", "1) General Processing Unit", "2) Graphical Performance Unit", "3) Graphics Processing Unit", "4) Geometric Processing Unit", 3, 10, 3, 4, "It is a specialized electronic circuit designed to handle complex calculations related to graphics rendering.");
            setValues(&c1.c_q[4], "Which of the following network topologies provides the highest level of fault tolerance and redundancy?", "1) Star topology", "2) Bus topology", "3) Ring topology", "4) Mesh topology", 4, 10, 2, 4, "In this topology, each node is connected to every other node.");
            setValues(&c1.c_q[5], "Which of the following encryption algorithms is considered the most secure for transmitting sensitive information over the internet?", "1) AES (Advanced Encryption Standar4)", "2) DES (Data Encryption Standar4)", "3) RSA (Rivest-Shamir-Adleman)", "4) MD5 (Message Digest Algorithm 5)", 1, 10, 1, 2, "It is widely used for secure communication and data encryption.");
            setValues(&c1.c_q[6], "What is the purpose of a firewall in computer networking?", "1) To encrypt data transmission", "2) To prevent unauthorized access to a network", "3) To allocate IP addresses dynamically", "4) To route data packets between networks", 2, 10, 1, 2, "It acts as a barrier between a trusted internal network and an untrusted external network.");
            setValues(&c1.c_q[7], "Which of the following is an example of a volatile storage medium?", "1) Hard disk drive (HD4)", "2) Solid-state drive (SS4)", "3) USB flash drive", "4) Random Access Memory (RAM)", 4, 10, 2, 4, "This type of storage loses its data when power is removed.");
            setValues(&c1.c_q[8], "Which of the following is not a commonly used programming language for web development?", "1) Java", "2) Python", "3) HTML", "4) C#", 2, 10, 2, 3, "This language is primarily used for desktop application development.");
            setValues(&c1.c_q[9], "What does the acronym SQL stand for in the context of databases?", "1) Structured Query Language", "2) Sequential Query Language", "3) Single Query Language", "4) System Query Language", 1, 10, 1, 4, "It is a standard language for managing relational databases.");
            setValues(&c1.c_q[10], "Which of the following is an example of a compiler?", "1) Java Virtual Machine (JVM)", "2) Python Interpreter", "3) GCC (GNU Compiler Collection)", "4) Node.js", 3, 10, 1, 3, "It translates source code into machine code before execution.");
            setValues(&c1.c_q[11], "Which of the following is not a primary function of an operating system?", "1) Memory management", "2) Device driver management", "3) File system management", "4) User interface management", 2, 10, 2, 3, "This function deals with the interaction between the operating system and the hardware.");
            setValues(&c1.c_q[12], "What is the purpose of a cache memory in a computer system?", "1) To store frequently accessed data for faster retrieval", "2) To execute arithmetic and logical operations", "3) To allocate memory dynamically", "4) To manage input and output devices", 1, 10, 1, 3, "It serves as a temporary storage for frequently used data.");
            setValues(&c1.c_q[13], "Which of the following is not a common network topology?", "1) Tree topology", "2) Mesh topology", "3) Star topology", "4) Linear topology", 4, 10, 3, 4, "This topology is not commonly used in network configurations.");
            setValues(&c1.c_q[14], "Which of the following is an example of an object-oriented programming language?", "1) C", "2) Assembly", "3) Pascal", "4) C++", 4, 10, 2, 4, "This language supports the concepts of classes and objects.");
            setValues(&c1.c_q[15], "Which of the following is a binary representation of the decimal number 25?", "1) 00011001", "2) 00010101", "3) 00011110", "4) 00011010", 1, 10, 1, 3, "Convert the decimal number into binary using the place-value method.");
            setValues(&c1.c_q[16], "Which of the following is an example of a high-level programming language?", "1) Assembly language", "2) Machine language", "3) C++", "4) Binary code", 3, 10, 1, 3, "This language is designed to be easily understood by humans.");
            setValues(&c1.c_q[17], " Which of the following is not a type of computer memory?", "1) Cache memory", "2) Secondary memory", "3) Virtual memory", "4) Auxiliary memory", 4, 10, 3, 4, "This type of memory is not directly accessible by the CPU.");
            setValues(&c1.c_q[18], "Which of the following is not a benefit of virtualization in computer systems?", "1) Improved hardware utilization", "2) Enhanced security and isolation", "3) Reduced power consumption", "4) Increased network bandwidth", 4, 10, 2, 4, "This benefit is not directly associated with virtualization.");
            setValues(&c1.c_q[19], "What does the acronym ASCII stand for in computer systems?", "1) American Standard Code for Information Interchange", "2) Advanced System Configuration and Information", "3) Automated System Control and Information Interface", "4) Association for Standardization and Control of Information", 1, 10, 1, 3, "It is a character encoding standard used for representing text in computers.");
            setValues(&c1.c_q[20], "Which of the following is an example of a command-line interface (CLI) operating system?", "1) Windows", "2) macOS", "3) Linux", "4) Android", 3, 10, 2, 3, "This type of operating system relies on text-based commands for interaction.");
            setValues(&c1.c_q[21], "Which of the following is a fundamental component of a CPU?", "1) Motherboard", "2) Hard disk drive (HDD)", "3) Control Unit (CU)", "4) Power Supply Unit (PSU)", 3, 10, 1, 3, "It is responsible for executing instructions and managing the flow of data.");
            setValues(&c1.c_q[22], "Which of the following is not an example of a cloud computing service model?", "1) Infrastructure as a Service (IaaS)", "2) Platform as a Service (PaaS)", "3) Software as a Service (SaaS)", "4) Database as a Service (DBaaS)", 4, 10, 1, 4, "This service model is not commonly associated with cloud computing.");
            setValues(&c1.c_q[23], "What is the purpose of an API (Application Programming Interface)?", "1) To provide an interface for user interaction", "2) To execute instructions of a program", "3) To enable communication between software applications", "4) To manage memory allocation", 3, 10, 1, 3, "It defines a set of rules and protocols for software interaction.");
            setValues(&c1.c_q[24], "Which of the following is not a type of computer network?", "1) Local Area Network (LAN)", "2) Wide Area Network (WAN)", "3) Metropolitan Area Network (MAN)", "4) Personal Area Network (PAN)", 4, 10, 2, 4, "This type of network is not commonly used in general network infrastructure.");
            setValues(&c1.c_q[25], "Which of the following is an example of a firmware?", "1) Web browser", "2) Operating system", "3) Printer driver", "4) BIOS", 4, 10, 4, 3, "Firmware is a type of software that is permanently stored in hardware devices, such as the Basic Input/Output System (BIOS) of a computer.");

            random_Qnumber();

            for (int i = 0; i < 10; i++)
            {
                start_time = time(NULL);
                printf("\033[35m");
                printf("%d. ", i + 1);
                printf("\033[0m");
                askQuestion(&c1.c_q[questions[i]]);
                end_time = time(NULL);
                printf("\033[0;31m"); // ANSI escape code for red color
                printf("Time taken: %.2f seconds\n", elapsed);
                printf("\033[0m"); // ANSI escape code to reset color

                printf("\033[0;32m"); // ANSI escape code for green color
                printf("Press Enter to Continue.");
                printf("\033[0m"); // ANSI escape code to reset color
                getchar();
                getchar();
                time_taken += elapsed;
                system("cls");
            }

            printf("\033[1;33mThe Total Score is %d out of 100.\033[0m\n", Total_Score); // Yellow color for celebrating

            FILE *file_3 = fopen("ScoresHard\\3_scores_CS.txt", "a");
            FILE *file_3_b = fopen("ScoresHard\\3_scores_CS.dat", "rb");
            setScore(file_3, Total_Score, Name, time_taken);
            fclose(file_3);

            if (file_3_b == NULL)
            {
                printf("File not available !!");
                return;
            }

            while (fread(&currStudent, sizeof(Student), 1, file_3_b) == 1)
                students[numPlayers++] = currStudent;

            fclose(file_3_b);

            qsort(students, numPlayers, sizeof(Student), compareStudents);

            FILE *file_3_w = fopen("ScoresHard\\3_scores_CS.dat", "wb");
            leaderboard(file_3_w, students, &numPlayers, Total_Score, Name, time_taken);
            break;
        case 4:
            setValues(&d1.d_q[0], "Which sorting algorithm has the worst-case time complexity of O(n^2)?", "1) Merge sort", "2) Quick sort", "3) Insertion sort", "4) Heap sort", 3, 10, 3, 1, "This sorting algorithm works by repeatedly inserting an element into its sorted position within a larger list.");
            setValues(&d1.d_q[1], "In a binary search tree, which traversal method would yield a sorted sequence of values?", "1) Preorder traversal", "2) Inorder traversal", "3) Postorder traversal", "4) Level order traversal", 2, 10, 2, 1, "This traversal method visits the left subtree, then the current node, and finally the right subtree.");
            setValues(&d1.d_q[2], "Which data structure is NOT suitable for implementing a priority queue?", "1) Array", "2) Linked list", "3) Heap", "4) Stack", 4, 10, 4, 3, "This data structure follows the LIFO (Last In, First Out) principle.");
            setValues(&d1.d_q[3], "The time complexity of the Bellman-Ford algorithm for finding the shortest path in a weighted graph is:", "1) O(V^2)", "2) O(E^2)", "3) O(VE)", "4) O(Elog(V))", 3, 10, 3, 2, "This algorithm handles both positive and negative edge weights.");
            setValues(&d1.d_q[4], "Which of the following is NOT a Greedy algorithm?", "1) Dijkstra's algorithm", "2) Kruskal's algorithm", "3) Prim's algorithm", "4) Bellman-Ford algorithm", 4, 10, 4, 1, "This algorithm selects the locally optimal choice at each step.");
            setValues(&d1.d_q[5], "Which data structure is used to implement depth-first search (DFS) in a graph?", "1) Queue", "2) Stack", "3) Heap", "4) Hash table", 2, 10, 2, 1, "This data structure follows the LIFO (Last In, First Out) principle.");
            setValues(&d1.d_q[6], "In the worst-case scenario, which sorting algorithm requires the minimum number of swaps?", "1) Bubble sort", "2) Insertion sort", "3) Quick sort", "4) Selection sort", 4, 10, 4, 2, "This sorting algorithm selects the smallest (or largest) element and places it in its correct position.");
            setValues(&d1.d_q[7], "Which of the following is an example of an NP-complete problem?", "1) Primality testing", "2) Dijkstra's algorithm", "3) Traveling Salesman Problem (TSP)", "4) Binary search", 3, 10, 3, 4, "This problem involves finding the shortest possible route that visits every city and returns to the starting point.");
            setValues(&d1.d_q[8], "Which of the following data structures uses the First In, First Out (FIFO) principle?", "1) Stack", "2) Queue", "3) Hash table", "4) Binary tree", 2, 10, 2, 1, "This data structure works like a line of people waiting for a bus.");
            setValues(&d1.d_q[9], "Which of the following is NOT a method for resolving collisions in hash tables?", "1) Separate chaining", "2) Linear probing", "3) Quadratic probing", "4) Breadth-first search", 4, 10, 4, 2, "This method involves storing multiple elements with the same hash key in a linked list.");
            setValues(&d1.d_q[10], ".In the context of Big O notation, if a function has a time complexity of O(n^2), it means that:", "1) The function executes in constant time.", "2) The function executes in logarithmic time.", "3) The function executes in linear time.", "4) The function executes in quadratic time.", 4, 10, 4, 1, "This time complexity denotes a nested loop structure where the number of iterations is proportional to the square of the input size.");
            setValues(&d1.d_q[11], "Which of the following is an advantage of using a linked list over an array?", "1) Constant-time access to elements", "2) Efficient memory utilization", "3) Random access to elements", "4) Compact storage of elements", 2, 10, 2, 4, "This data structure allows dynamic memory allocation and insertion/removal of elements without shifting the entire list.");
            setValues(&d1.d_q[12], "Which of the following sorting algorithms has a time complexity of O(n*log(n)) in the worst case?", "1) Bubble sort", "2) Quick sort", "3) Radix sort", "4) Bucket sort", 2, 10, 2, 4, "This algorithm divides the input into smaller partitions and recursively sorts them.");
            setValues(&d1.d_q[13], "Which of the following is NOT a valid approach to traverse a graph?", "1) Breadth-first search", "2) Depth-first search", "3) Dijkstra's algorithm", "4) Binary search", 4, 10, 4, 2, "This approach involves searching for a specific value in a sorted array by repeatedly dividing it into two halves.");
            setValues(&d1.d_q[14], "Which data structure is typically used to implement a Least Recently Used (LRU) cache?", "1) Queue", "2) Stack", "3) Heap", "4) Hash table", 1, 10, 1, 3, "This data structure keeps track of the order in which elements were accessed or modified.");
            setValues(&d1.d_q[15], "Which of the following data structures is used to implement a breadth-first search (BFS) in a graph?", "1) Queue", "2) Stack", "3) Heap", "4) Hash table", 1, 10, 1, 2, "This data structure follows the First In, First Out (FIFO) principle.");
            setValues(&d1.d_q[16], "In a balanced binary search tree, what is the maximum height in terms of the number of nodes?", "1) log(n)", "2) n", "3) n/2", "4) √n", 1, 10, 1, 2, "This property ensures efficient search, insertion, and deletion operations.");
            setValues(&d1.d_q[17], "Which algorithm is used to find the strongly connected components in a directed graph?", "1) Dijkstra's algorithm", "2) Bellman-Ford algorithm", "3) Kosaraju's algorithm", "4) Kruskal's algorithm", 3, 10, 3, 4, "This algorithm involves two passes of depth-first search (DFS).");
            setValues(&d1.d_q[18], "The time complexity of the breadth-first search (BFS) algorithm is:", "1) O(V)", "2) O(E)", "3) O(V+E)", "4) O(V^2)", 3, 10, 3, 4, "This algorithm explores all vertices reachable from the starting vertex in breadth-first order.");
            setValues(&d1.d_q[19], "Which of the following data structures uses the Last In, First Out (LIFO) principle?", "1) Stack", "2) Queue", "3) Heap", "4) Binary tree", 1, 10, 1, 4, "This data structure works like a stack of plates.");
            setValues(&d1.d_q[20], "The time complexity of the best-case scenario for the merge sort algorithm is:", "1) O(n)", "2) O(nlog(n))", "3) O(n^2)", "4) O(log(n))", 2, 10, 2, 4, "This best-case scenario occurs when the input is already sorted.");
            setValues(&d1.d_q[21], "Which algorithm is used to find the maximum flow in a network?", "1) Bellman-Ford algorithm", "2) Kruskal's algorithm", "3) Dijkstra's algorithm", "4) Ford-Fulkerson algorithm", 4, 10, 4, 3, "This algorithm involves finding an augmenting path and adjusting the flow along it.");
            setValues(&d1.d_q[22], "In a hash table with separate chaining, the worst-case time complexity for search, insert, and delete operations is:", "1) O(1)", "2) O(log(n))", "3) O(n)", "4) O(n*log(n))", 3, 10, 3, 1, "This time complexity arises when many elements hash to the same index and form long chains.");
            setValues(&d1.d_q[23], "Which of the following is NOT an example of a divide-and-conquer algorithm?", "1) Merge sort", "2) Quick sort", "3) Depth-first search", "4) Binary search", 3, 10, 3, 1, "This algorithm repeatedly divides the input into smaller halves until a base case is reached.");
            setValues(&d1.d_q[24], "Which algorithm is used to find the shortest path in a weighted graph with non-negative edge weights?", "1) Dijkstra's algorithm", "2) Bellman-Ford algorithm", "3) Prim's algorithm", "4) Kruskal's algorithm", 1, 10, 1, 2, "This algorithm maintains a priority queue of vertices and their tentative distances from the source.");
            setValues(&d1.d_q[25], "Which data structure is used to implement the backtracking algorithm?", "1) Queue", "2) Stack", "3) Heap", "4) Linked List", 2, 10, 2, 4, "Think about the Last-In-First-Out (LIFO) property required for backtracking.");
            random_Qnumber();

            for (int i = 0; i < 10; i++)
            {
                start_time = time(NULL);
                printf("\033[35m");
                printf("%d. ", i + 1);
                printf("\033[0m");
                askQuestion(&d1.d_q[questions[i]]);
                end_time = time(NULL);
                elapsed = difftime(end_time, start_time);
                printf("\033[0;31m"); // ANSI escape code for red color
                printf("Time taken: %.2f seconds\n", elapsed);
                printf("\033[0m"); // ANSI escape code to reset color

                printf("\033[0;32m"); // ANSI escape code for green color
                printf("Press Enter to Continue.");
                printf("\033[0m"); // ANSI escape code to reset color
                time_taken += elapsed;
                getchar();
                getchar();

                system("cls");
            }

            printf("\033[1;33mThe Total Score is %d out of 100.\033[0m\n", Total_Score); // Yellow color

            FILE *file_4 = fopen("ScoresHard\\4_scores_DS.txt", "a");
            FILE *file_4_b = fopen("ScoresHard\\4_scores_DS.dat", "rb");
            setScore(file_4, Total_Score, Name, time_taken);
            fclose(file_4);

            if (file_4_b == NULL)
            {
                printf("File not available !!");
                return;
            }

            while (fread(&currStudent, sizeof(Student), 1, file_4_b) == 1)
                students[numPlayers++] = currStudent;

            fclose(file_4_b);

            qsort(students, numPlayers, sizeof(Student), compareStudents);

            FILE *file_4_w = fopen("ScoresHard\\4_scores_DS.dat", "wb");
            leaderboard(file_4_w, students, &numPlayers, Total_Score, Name, time_taken);
            break;
        case 5:
            setValues(&s1.s_q[0], "Which of the following is NOT a system call?", "1) fork()", "2) exec()", "3) printf()", "4) open()", 3, 10, 1, 3, "System calls are used to interact with the operating system kernel.");
            setValues(&s1.s_q[1], "In a Unix-like operating system, which system call is used to create a new process?", "1) fork()", "2) exec()", "3) wait()", "4) exit()", 1, 10, 1, 3, "This system call creates a child process that is an exact copy of the parent process.");
            setValues(&s1.s_q[2], "Which of the following is NOT a commonly used file descriptor in Unix-like systems?", "1) STDIN_FILENO", "2) STDOUT_FILENO", "3) STDERR_FILENO", "4) FILE_FILENO", 4, 10, 3, 4, "File descriptors represent opened files or I/O streams.");
            setValues(&s1.s_q[3], "Which system call is used to allocate memory dynamically in C/C++?", "1) malloc()", "2) calloc()", "3) free()", "4) realloc()", 1, 10, 1, 2, "This system call is used to allocate a block of memory of a specified size.");
            setValues(&s1.s_q[4], "In Linux, what is the command to display the current process ID (PI4)?", "1) ps", "2) pidof", "3) top", "4) getpid", 4, 10, 1, 4, "This command displays information about running processes.");
            setValues(&s1.s_q[5], "What is the purpose of an assembler in system programming?", "1) To convert high-level programming languages to machine code", "2) To convert assembly language to machine code", "3) To convert machine code to assembly language", "4) To optimize compiled code", 2, 10, 1, 2, "An assembler translates assembly language instructions into machine code.");
            setValues(&s1.s_q[6], "Which of the following is NOT a typical step in the compilation process?", "1) Preprocessing", "2) Linking", "3) Assembling", "4) Interpreting", 4, 10, 1, 4, "This step combines object files into an executable or shared library.");
            setValues(&s1.s_q[7], "Which type of memory is used to store temporary variables and function call stack in a program?", "1) Heap memory", "2) Stack memory", "3) Static memory", "4) Global memory", 2, 10, 1, 2, "This type of memory has a last-in-first-out (LIFO) structure");
            setValues(&s1.s_q[8], "In the context of operating systems, what is a context switch?", "1) The process of switching between different user accounts", "2) The process of switching between different CPUs in a multiprocessor system", "3) The process of switching between different threads in a process", "4) The process of saving and restoring the state of a process or thread", 4, 10, 2, 4, "This operation involves saving the current execution context and restoring the previously saved context.");
            setValues(&s1.s_q[9], "Which of the following statements is true about system libraries?", "1) They are part of the operating system kernel.", "2) They are written in high-level languages like C/C++.", "3) They are not accessible to user programs.", "4) They contain functions that provide higher-level abstractions for system programming.", 4, 10, 3, 4, "System libraries provide an interface for interacting with the operating system.");
            setValues(&s1.s_q[10], "In Unix-like systems, what is the purpose of the \"chmod\" command?", "1) To change the ownership of a file", "2) To change the file's permissions", "3) To change the file's size", "4) To change the file's timestamp", 2, 10, 2, 3, "This command allows the modification of file permissions.");
            setValues(&s1.s_q[11], "Which of the following is NOT a file permission in Unix-like systems?", "1) Read (r)", "2) Write (w)", "3) Execute (x)", "4) Delete (4)", 4, 10, 2, 4, "File permissions control read, write, and execute rights for users, groups, and others.");
            setValues(&s1.s_q[12], "In Unix-like systems, what is the purpose of the \"make\" utility?", "1) To compile C/C++ programs", "2) To create compressed archives", "3) To manage shared libraries", "4) To automate the build process of software projects", 4, 10, 1, 4, "This utility reads a file called \"Makefile\" to determine how to build a program.");
            setValues(&s1.s_q[13], "Which of the following is an example of a device file in Unix-like systems?", "1) /etc/passwd", "2) /usr/bin/gcc", "3) /dev/null", "4) /var/log/messages", 3, 10, 1, 3, "Device files represent physical or virtual devices on the system.");
            setValues(&s1.s_q[14], "In C programming, what is the purpose of the \"volatile\" keyword?", "1) To declare a constant variable", "2) To specify the storage class of a variable", "3) To indicate that a variable's value can change unexpectedly", "4) To define a function that takes a variable number of arguments", 3, 10, 2, 3, "This keyword tells the compiler not to optimize accesses to the variable.");
            setValues(&s1.s_q[15], "What is the role of a linker in the compilation process?", "1) To convert high-level programming languages to machine code", "2) To convert assembly language to machine code", "3) To combine object files into an executable program", "4) To optimize compiled code", 3, 10, 1, 3, "A linker resolves external references and creates an executable file.");
            setValues(&s1.s_q[16], "Which of the following is NOT a commonly used system programming language?", "1) C", "2) C++", "3) Java", "4) Assembly language", 3, 10, 2, 3, "System programming languages provide low-level access to system resources.");
            setValues(&s1.s_q[17], "In Unix-like systems, what is the purpose of the \"ld\" command?", "1) To compile C/C++ programs", "2) To assemble assembly language programs", "3) To link object files into an executable or shared library", "4) To display the contents of object files", 3, 10, 1, 3, "This command is commonly used as a linker.");
            setValues(&s1.s_q[18], "Which of the following is NOT a common use case for system programming?", "1) Developing device drivers", "2) Writing operating systems", "3) Creating web applications", "4) Implementing network protocols", 3, 10, 2, 3, "System programming focuses on low-level software development.");
            setValues(&s1.s_q[19], "In Unix-like systems, what is the purpose of the \"fork\" system call?", "1) To create a child process", "2) To execute a new program", "3) To wait for a child process to terminate", "4) To exit the current process", 1, 10, 1, 3, "This system call creates a new process that is a copy of the calling process.");
            setValues(&s1.s_q[20], "Which of the following is an example of an interrupt-driven I/O mechanism?", "1) Polling", "2) Busy waiting", "3) DMA (Direct Memory Access)", "4) ISR (Interrupt Service Routine)", 4, 10, 2, 4, "This mechanism allows the processor to handle I/O requests asynchronously.");
            setValues(&s1.s_q[21], "In Unix-like systems, what is the purpose of the \"signal\" system call?", "1) To handle exceptions and errors", "2) To send messages between processes", "3) To synchronize concurrent processes", "4) To handle asynchronous events, such as interrupts or signals", 4, 10, 1, 4, "This system call allows processes to handle asynchronous events from the operating system.");
            setValues(&s1.s_q[22], "Which of the following is NOT an example of a system programming interface?", "1) POSIX", "2) Win32 API", "3) DirectX", "4) Java Native Interface (JNI)", 3, 10, 1, 3, "System programming interfaces provide a set of functions and services for interacting with the operating system.");
            setValues(&s1.s_q[23], "In C programming, what is the purpose of the \"restrict\" keyword?", "1) To declare a pointer that can be modified", "2) To specify the alignment of a variable", "3) To indicate that a pointer is not aliased", "4) To define a macro with restricted scope", 3, 10, 2, 3, "This keyword allows optimizations based on the assumption that the pointer is not aliased.");
            setValues(&s1.s_q[24], "What is the role of an assembler in the compilation process?", "1) To convert high-level programming languages to machine code", "2) To convert assembly language to machine code", "3) To combine object files into an executable program", "4) To optimize compiled code", 2, 10, 2, 4, "An assembler translates assembly language instructions into machine code.");
            setValues(&s1.s_q[25], "Which component of the computer is responsible for executing assembly language instructions?", "1) Central Processing Unit (CPU)", "2) Random Access Memory (RAM)", "3) Hard Disk Drive (HD4)", "4) Graphics Processing Unit (GPU)", 1, 10, 1, 3, "The CPU is the component of the computer that executes instructions, including assembly language instructions.");
            random_Qnumber();

            for (int i = 0; i < 10; i++)
            {
                start_time = time(NULL);
                printf("\033[35m");
                printf("%d. ", i + 1);
                printf("\033[0m");
                askQuestion(&s1.s_q[questions[i]]);
                end_time = time(NULL);
                elapsed = difftime(end_time, start_time);
                printf("\033[0;31m"); // ANSI escape code for red color
                printf("Time taken: %.2f seconds\n", elapsed);
                printf("\033[0m"); // ANSI escape code to reset color

                printf("\033[0;32m"); // ANSI escape code for green color
                printf("Press Enter to Continue.");
                printf("\033[0m"); // ANSI escape code to reset color
                time_taken += elapsed;
                getchar();
                getchar();

                system("cls");
            }

            printf("\033[1;33mThe Total Score is %d out of 100.\033[0m\n", Total_Score); // Yellow color for celebrating

            FILE *file_5 = fopen("ScoresHard\\5_scores_SP.txt", "a");
            FILE *file_5_b = fopen("ScoresHard\\5_scores_SP.dat", "rb");
            setScore(file_5, Total_Score, Name, time_taken);
            fclose(file_5);

            if (file_5_b == NULL)
            {
                printf("File not available !!");
                return;
            }

            while (fread(&currStudent, sizeof(Student), 1, file_5_b) == 1)
                students[numPlayers++] = currStudent;

            fclose(file_5_b);

            qsort(students, numPlayers, sizeof(Student), compareStudents);

            FILE *file_5_w = fopen("ScoresHard\\5_scores_SP.dat", "wb");
            leaderboard(file_5_w, students, &numPlayers, Total_Score, Name, time_taken);
            break;
        case 6:
            setValues(&g1.g_q[0], "The day before yesterday, I was 25 years old. Next year, I will turn 28. What is my birthday and today's date?", "1) January 1st", "2) February 28th", "3) November 30th", "4) December 31st", 4, 10, 4, 2, "Consider the time frame and ages carefully.");
            setValues(&g1.g_q[1], "I am an odd number. Take away one letter, and I become even. What number am I?", "1) Five", "2) Seven", "3) Three", "4) Nine", 3, 10, 3, 2, "Focus on the spelling of the words.");
            setValues(&g1.g_q[2], "I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?", "1) Echo", "2) Windmill", "3) Whistle", "4) Radio", 1, 10, 1, 3, "Think about things that can produce sound.");
            setValues(&g1.g_q[3], "What comes once in a minute, twice in a moment, but never in a thousand years?", "1) The letter \"M\"", "2) The letter \"A\"", "3) The number \"2\"", "4) The number \"0\"", 1, 10, 1, 2, "Focus on the occurrence of letters or numbers.");
            setValues(&g1.g_q[4], "I have keys but no locks. I have space but no room. You can enter but can't go outside. What am I?", "1) Keyboard", "2) Calculator", "3) Website", "4) Email", 3, 10, 3, 4, "Think about things related to technology and access.");
            setValues(&g1.g_q[5], "I have cities but no houses, forests but no trees, and rivers but no water. What am I?", "1) Map", "2) Globe", "3) Painting", "4) Dream", 1, 10, 1, 4, "Consider things that represent or depict locations.");
            setValues(&g1.g_q[6], "The more you take, the more you leave behind. What am I?", "1) Footsteps", "2) Time", "3) Memories", "4) Darkness", 1, 10, 1, 2, "Think about actions and their consequences.");
            setValues(&g1.g_q[7], "I am taken from a mine and shut in a wooden case from which I am never released. I am used by almost every person. What am I?", "1) Pencil", "2) Diamond", "3) Coal", "4) Breath", 1, 10, 3, 1, "Focus on widely used objects.");
            setValues(&g1.g_q[8], "I have keys but can't open locks. I have a space but no room. You can enter, but you can't go outside. What am I?", "1) Keyboard", "2) Calculator", "3) Website", "4) Email", 1, 10, 1, 4, "This is similar to  word typing.");
            setValues(&g1.g_q[9], "What has a heart that doesn't beat?", "1) Clock", "2) Book", "3) Deck of cards", "4) Music player", 3, 10, 3, 2, "Think about objects with symbolic representations.");
            setValues(&g1.g_q[10], "I am always hungry, I must always be fed. The finger I touch will soon turn red. What am I?", "1) Fire", "2) Knife", "3) Fork", "4) Time", 1, 10, 1, 3, "Think about objects associated with danger.");
            setValues(&g1.g_q[11], "I am a three-letter word. I become longer when you add two letters to me. What word am I?", "1) Now", "2) Ago", "3) Old", "4) New", 1, 10, 1, 3, "Think about words that can become different words by adding letters.");
            setValues(&g1.g_q[12], "I am an insect. The first part of my name is the name of another insect. What am I?", "1) Butterfly", "2) Beetle", "3) Dragonfly", "4) Mosquito", 2, 10, 2, 4, "Look for clues in the question itself.");
            setValues(&g1.g_q[13], "You see me once in June, twice in November, and not at all in May. What am I?", "1) The letter \"E\"", "2) The letter \"O\"", "3) The letter \"A\"", "4) The letter \"U\"", 1, 10, 1, 4, "Focus on the occurrences of letters in the given months.");
            setValues(&g1.g_q[14], "I am taken from a mine and shut in a wooden case. When you need me, you throw me away. What am I?", "1) Matchstick", "2) Key", "3) Pencil", "4) Rubber eraser", 1, 10, 1, 3, "Think about objects that are used and discarded.");
            setValues(&g1.g_q[15], "What has keys but can't open locks? What has space but has no room? What can you enter but can't go outside?", "1) Keyboard", "2) Calculator", "3) Computer", "4)Typewriter", 2, 10, 2, 4, "This is similar to Questions 5 and 9, but with a different answer.");
            setValues(&g1.g_q[16], "I am a word of letters three. Add two, and fewer there will be. What word am I?", "1) Few", "2) Less", "3) Lot", "4) Many", 3, 10, 3, 4, "Think about words that become shorter when you add letters.");
            setValues(&g1.g_q[17], "I am tall when I am young, and short when I am old. What am I?", "1) Pencil", "2) Candle", "3) Tree", "4) Bottle", 2, 10, 2, 4, "Focus on objects that change their physical characteristics over time.");
            setValues(&g1.g_q[18], "What gets wet while drying?", "1) Towel", "2) Watermelon", "3) Cloth", "4) Umbrella", 1, 10, 1, 4, "Think about objects that have a drying process associated with them.");
            setValues(&g1.g_q[19], "The more you take, the more you leave behind. What am I?", "1) Footsteps", "2) Time", "3) Memories", "4) Darkness", 1, 10, 1, 3, "This is similar to Question 7, but with the same answer.");
            setValues(&g1.g_q[20], "I am an odd number. Take away one letter, and I become even. What number am I?", "1) Five", "2) Seven", "3) Three", "4) Nine", 3, 10, 3, 4, "This is similar to Question 2, but with the same answer.");
            setValues(&g1.g_q[21], "I am a word that is spelled the same backward and forward. What am I?", "1) Racecar", "2) Level", "3) Radar", "4) Mom", 1, 10, 1, 2, "Think about words that are palindromes.");
            setValues(&g1.g_q[22], "I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?", "1) Echo", "2) Windmill", "3) Whistle", "4) Radio", 1, 10, 1, 2, "This is similar to Question 3, but with the same answer.");
            setValues(&g1.g_q[23], "What has a heart that doesn't beat?", "1) Clock", "2) Book", "3) Deck of cards", "4) Music player", 3, 10, 3, 4, "This is similar to Question 10, but with the same answer.");
            setValues(&g1.g_q[24], "I have a neck, but no head. I wear a cap, but no hat. What am I?", "1) Bottle", "2) Pen", "3) Key", "4) Guitar", 1, 10, 1, 4, "Think about objects that have specific parts.");
            setValues(&g1.g_q[25], "I can be cracked, made, told, and played. What am I?", "1) Joke", "2) Egg", "3) Music", "4) Riddle", 1, 10, 1, 3, "It involves creativity.");

            random_Qnumber();

            for (int i = 0; i < 10; i++)
            {
                start_time = time(NULL);
                printf("\033[35m");
                printf("%d. ", i + 1);
                printf("\033[0m");
                askQuestion(&g1.g_q[questions[i]]);
                end_time = time(NULL);
                elapsed = difftime(end_time, start_time);
                printf("\033[0;31m"); // ANSI escape code for red color
                printf("Time taken: %.2f seconds\n", elapsed);
                printf("\033[0m"); // ANSI escape code to reset color

                printf("\033[0;32m"); // ANSI escape code for green color
                printf("Press Enter to Continue.");
                printf("\033[0m"); // ANSI escape code to reset color
                time_taken += elapsed;
                getchar();
                getchar();

                system("cls");
            }

            printf("\033[1;33mThe Total Score is %d out of 100.\033[0m\n", Total_Score); // Yellow color for celebrating

            FILE *file_6 = fopen("ScoresHard\\6_scores_R.txt", "a");
            FILE *file_6_b = fopen("ScoresHard\\6_scores_R.dat", "rb");
            setScore(file_6, Total_Score, Name, time_taken);
            fclose(file_6);

            if (file_6_b == NULL)
            {
                printf("File not available !!");
                return;
            }

            while (fread(&currStudent, sizeof(Student), 1, file_6_b) == 1)
                students[numPlayers++] = currStudent;

            fclose(file_6_b);

            qsort(students, numPlayers, sizeof(Student), compareStudents);

            FILE *file_6_w = fopen("ScoresHard\\6_scores_R.dat", "wb");
            leaderboard(file_6_w, students, &numPlayers, Total_Score, Name, time_taken);
            break;

        default:
            break;
        }
    }
}

void askQuestion(Question *q)
{
    printf("\033[35m");
    printf("%s\n", q->Question_Text);
    printf("\033[0m");
    printf("\033[1;36m%s\033[0m\n", q->Option_1); // Sky blue color for Option 1
    printf("\033[1;36m%s\033[0m\n", q->Option_2); // Sky blue color for Option 2
    printf("\033[1;36m%s\033[0m\n", q->Option_3); // Sky blue color for Option 3
    printf("\033[1;36m%s\033[0m\n", q->Option_4); // Sky blue color for Option 4

    printf("\x1b[32mEnter 5 for Lifeline.\n\n\x1b[0m");
    // Storing User's Answer
    printf("\033[34mEnter the answer (in number): \033[0m\n");
    while (1)
    {
        scanf("%d", &Answer);
        if (Answer > 5 || Answer < 1)
        {
            printf("\x1b[31mError: Invalid input.\n\x1b[0m");
            printf("\x1b[31mEnter the answer (in number): \n\x1b[0m");
            continue;
        }
        break;
    }

    int choice;
    while (Answer == 5)
    {
        if (Life1 == 1 && Life2 == 1)
        {
            printf("\x1b[31mNO MORE LIFELINES REMAINING!\n\x1b[0m");
            printf("\033[34mEnter the answer (in number): \n\033[0m");
            while (1)
            {
                scanf("%d", &Answer);
                if (Answer > 5 || Answer < 1)
                {
                    printf("Error: Invalid input.\nEnter the answer (in number): \n");
                    continue;
                }
                break;
            }
            break;
        }
        q->Question_Score /= 2;
        printf("\x1b[34mWhich LIFELINE do you want to use?\n\x1b[0m");
        printf("\x1b[33m1. Expert Advice\n");
        printf("2. 50-50\n\x1b[0m");
        printf("\x1b[36mEnter your choice (in number): \x1b[0m");
        scanf("%d", &choice);

        if (choice == 1 && Life1 == 0)
        {
            printf("\033[31mYOU HAVE CHOSEN EXPERT ADVICE.\n\033[0m");
            printf("\033[31mHINT:\033[0m");
            printf("\033[1;36m"); // ANSI escape code for cyan color
            printf("%s", q->Hint);
            printf("\033[0m"); // ANSI escape code to reset color

            printf("\n");
            Life1++;
        }
        else if (choice == 1)
        {
            printf("\033[0;31m"); // ANSI escape code for red color
            printf("EXPERT ADVICE IS EXHAUSTED! ");
            printf("\033[0m");
        } // ANSI escape code to reset color

        else if (choice == 2 && Life2 == 0)
        {
            printf("\033[0;31m"); // ANSI escape code for red color
            printf("\nYOU HAVE CHOSEN 50-50...\nTHE TWO OPTIONS REMAINING ARE-\n");
            printf("\033[0m"); // ANSI escape code to reset color

            if (q->show1 == 1 || q->show2 == 1)
                printf("\033[31m%s\033[0m\n", q->Option_1);
            if (q->show1 == 2 || q->show2 == 2)
                printf("\033[31m%s\033[0m\n", q->Option_2);
            if (q->show1 == 3 || q->show2 == 3)
                printf("\033[31m%s\033[0m\n", q->Option_3);
            if (q->show1 == 4 || q->show2 == 4)
                printf("\033[31m%s\033[0m\n", q->Option_4);
            Life2++;
        }
        else if (choice == 2)
            printf("\033[31m50-50 IS EXHAUSTED!\n\033[0m");
        printf("\033[34mWhat is your answer?(in number)\n\033[0m");
        while (1)
        {
            scanf("%d", &Answer);
            if (Answer > 5 || Answer < 1)
            {
                printf("Error: Invalid input.\nEnter the answer (in number): \n");
                continue;
            }
            break;
        }
    }

    if (Answer == q->Correct_Answer)
    {
        printf("\033[0;32m");
        printf("\nCorrect Answer!!\n");
        printf("\033[0m");
        Total_Score = Total_Score + q->Question_Score;
        printf("\033[1;36mScore = %d out of %d\033[0m\n", q->Question_Score, q->Question_Score); // Cyan color for score
    }
    else
    {
        printf("\033[0;31m");
        printf("\nWrong Answer !\n");
        printf("The Correct Answer was:%d\n", q->Correct_Answer);
        printf("Score = 0 out of %d\n", q->Question_Score);
        printf("\033[0m");
    }
}

void random_Qnumber()
{
    srand(time(NULL));
    questions[0] = rand() % 26;
    int i = 1, flag = 1;
    while (i < 10)
    {
        flag = 1;
        questions[i] = rand() % 26;
        for (int j = 0; j < i; j++)
        {
            if (questions[j] == questions[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            i++;
        else
            continue;
    }
}

void setScore(FILE *file, int score, char *name, float time)
{
    if (file == NULL)
        printf("Error opening the file.");
    else
    {
        fprintf(file, "%s\t%d\t%f\n", name, score, time);
        printf("Score saved successfully!\n");
    }
}

int compareStudents(const void *a, const void *b)
{
    const Student *s1 = (const Student *)a;
    const Student *s2 = (const Student *)b;
    if (s1->score < s2->score)
        return 1;
    else if (s1->score > s2->score)
        return -1;
    else if (s1->time < s2->time)
        return 1;
    else if (s1->time > s2->time)
        return -1;
    else
        return strcmp(s1->name, s2->name);
}

void leaderboard(FILE *file, Student students[], int *numOfPlayers, int score, char *name, float time)
{
    Student new;
    strcpy(new.name, name);
    new.score = score;
    new.time = time;

    int index = *numOfPlayers;
    for (int i = 0; i < *numOfPlayers; i++)
    {
        if (compareStudents(&new, &students[i]) < 0)
        {
            index = i;
            break;
        }
    }

    for (int i = *numOfPlayers; i > index; i--)
        students[i] = students[i - 1];

    students[index] = new;
    (*numOfPlayers)++;

    fwrite(students, sizeof(Student), *numOfPlayers, file);
    fclose(file);

    printf("\n\n\t\t\t     \x1b[31m\033[4mLeaderboard\x1b[0m\n\n");
    printf("\t\t\x1b[32mName\t\tScore\t\tTime\n\x1b[0m");
    for (int i = 0; i < *numOfPlayers; i++)
    {
        printf("\t\t\x1b[33m%s\x1b[0m\t\t", students[i].name); // Yellow color for name
        printf("\x1b[35m%d\x1b[0m\t\t", students[i].score);    // Magenta color for score
        printf("\x1b[36m%.3f\x1b[0m", students[i].time);       // Cyan color for time
        printf("\n");
    }

    printf("\n\n\x1b[34mPress Enter to continue: \x1b[0m");

    getchar();
}
