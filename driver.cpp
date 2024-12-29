/******************************
This is a project and stuff
Yeah
******************************/

#include "header.h"


int main() {
    // Clear the screen
    system("cls");
    get_console_size(screenWidth, screenHeight);

    main_menu();
    
    return 0;
}





void main_menu() {
    do {
        system("cls");
        display_stats();
        cout << "\nMain Menu\n";
        cout << "1. View Todo List\n2. View Schedule\n3. Manage Tasks\n4. Manage Schedule\n5. Credits Shop\n6. Quit\n";
        cout << "Enter Choice: ";
        int userInput = input_check(1, 6);
        switch (userInput){
            case 1:
                display_todo_list();
                break;
            case 2:
                display_schedule();
                break;
            case 3:
                manage_tasks();
                break;
            case 4:
                manage_schedule();
                break;
            case 5:
                credits_shop();
                break;
            case 6:
                running = false;
                break;
        }
    } while (running);
}



void display_todo_list(){
    bool inMenu = true;
    do {
        system("cls");
        display_stats();
        cout << "\nTodo List\n";
        read_tasks_file();
        cout << "1. \n2. \n3. \n";
        cout << "Enter Choice: ";
        int userInput = input_check(1, 3);
        switch(userInput){
            case 1:
                for (int i = 0; i < tasks.size(); i++){
                    cout << "Name: " << tasks[i].name << "\nDescription: " << tasks[i].description << "\nType: " << tasks[i].type << "\nDue Date: " << tasks[i].dueDate << "\nImportance: " << tasks[i].importance << "\nEstimated Time: " << tasks[i].estTime << endl;
                }
                Sleep(3000);
                break;
            case 2:
                break;
            case 3:
                inMenu = false;
                break;
        }
    } while(inMenu);
}

void display_schedule(){
    bool inMenu = true;
    do {
        system("cls");
        display_stats();
        cout << "\nSchedule\n";
        cout << "1. View Month\n2. \n3. \n";
        cout << "Enter Choice: ";
        int userInput = input_check(1, 3);
        switch(userInput){
            case 1:
                display_calendar();
                break;
            case 2:
                break;
            case 3:
                inMenu = false;
                break;
        }
    } while(inMenu);
}

void manage_tasks(){
    bool inMenu = true;
    do {
        system("cls");
        display_stats();
        cout << "\nTask Manager\n";
        cout << "1. \n2. \n3. \n";
        cout << "Enter Choice: ";
        int userInput = input_check(1, 3);
        switch(userInput){
            case 1:
                break;
            case 2:
                break;
            case 3:
                inMenu = false;
                break;
        }
    } while(inMenu);
}

void manage_schedule(){
    bool inMenu = true;
    do {
        system("cls");
        display_stats();
        cout << "\nSchedule Planner\n";
        cout << "1. \n2. \n3. \n";
        cout << "Enter Choice: ";
        int userInput = input_check(1, 3);
        switch(userInput){
            case 1:
                break;
            case 2:
                break;
            case 3:
                inMenu = false;
                break;
        }
    } while(inMenu);
}

void credits_shop(){
    bool inMenu = true;
    do {
        system("cls");
        display_stats();
        cout << "\nCredits Shop\n";
        cout << "1. \n2. \n3. \n";
        cout << "Enter Choice: ";
        int userInput = input_check(1, 3);
        switch(userInput){
            case 1:
                break;
            case 2:
                break;
            case 3:
                inMenu = false;
                break;
        }
    } while(inMenu);
}







void read_tasks_file(){
    ifstream file("tasks.txt");

    if (!file.is_open()) {
        cerr << "Error opening the file!";
    }

    string line;
    Task task;
    int count = 0;
    while (getline(file, line)){
        
        switch(count){
            case 0: //name
                task.name = line;
                break;
            case 1: //desc
                task.description = line;
                break;
            case 2: //type
                task.type = line;
                break;
            case 3: //date
                task.dueDate = string_to_time_t(line);
                break;
            case 4: //impt
                task.importance = stoi(line);
                break;
            case 5: //time
                task.estTime = stoi(line);
                break;
            case 6: //empt
                tasks.push_back(task);
                count = -1;
                break;
        }
        count++;
    }

    file.close();
}

void read_events_file(){

}

void read_weekly_schedule_file(){

}

void read_save_file(){

}



void write_tasks_file(){

}

void write_events_file(){

}

void write_weekly_schedule_file(){

}

void write_save_file(){

}


void printSeparatorLine() {
    for (int i = 0; i < CALENDAR_WIDTH; ++i) {
        cout << "#";
    }
    cout << "\n";
}

void printBlock(const string& content) {
    cout << "# " << setw(BLOCK_WIDTH - 3) << left << content << "#";
}

void printCalendarBlockRow(const vector<string>& contents) {
    for (int row = 0; row < BLOCK_HEIGHT; ++row) {
        for (size_t i = 0; i < contents.size(); ++i) {
            if (row == 0) {
                // Print day number in the first row
                printBlock(contents[i]);
            } else {
                // Leave the rest of the rows blank or add placeholders
               printBlock("");
            }
        }
        cout << "\n";
    }
}

void display_calendar() {
    time_t t = time(nullptr);
    tm* currentTime = localtime(&t);

    int year = currentTime->tm_year + 1900;
    int month = currentTime->tm_mon + 1;

    while (true) {
        system("cls");
        // Array of month names and number of days
        const char* monthNames[] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Leap year adjustment
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth[1] = 29;
        }

        // Get the starting day of the week for the month
        tm timeIn = {};
        timeIn.tm_year = year - 1900;
        timeIn.tm_mon = month - 1;
        timeIn.tm_mday = 1;
        mktime(&timeIn);
        int startDay = timeIn.tm_wday; // 0 = Sunday, 1 = Monday, ...

        // Print the header
        printSeparatorLine();
        cout << "# " << setw(CALENDAR_WIDTH - 3) << left
                  << (string(monthNames[month - 1]) + " " + to_string(year)) << "#\n";
        printSeparatorLine();

        // Print day names
        const char* dayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        for (const char* dayName : dayNames) {
            printBlock(dayName);
        }
        cout << "\n";
        printSeparatorLine();

        // Fill blocks with day numbers
        vector<string> blocks(7, ""); // Create 7 blocks for each week
        int day = 1;

        // Fill in leading empty blocks for days before the start
        for (int i = 0; i < startDay; ++i) {
            blocks[i] = "";
        }

        // Fill in the days of the month
        for (int i = startDay; i < 7 && day <= daysInMonth[month - 1]; ++i) {
            blocks[i] = to_string(day++);
        }

        // Print the first row
        printCalendarBlockRow(blocks);
        printSeparatorLine();

        // Print the remaining weeks
        while (day <= daysInMonth[month - 1]) {
            blocks = vector<string>(7, ""); // Reset the blocks
            for (int i = 0; i < 7 && day <= daysInMonth[month - 1]; ++i) {
                blocks[i] = to_string(day++);
            }
            printCalendarBlockRow(blocks);
            printSeparatorLine();
        }

        // Prompt for user input
        cout << "\nEnter -1 to go back, -2 to look at previous month, -3 to look at next month, or a day number to look at that day: ";
        int userInput = input_check(-3, 31);
        switch (userInput) {
            case -1:
                return; // Exit the function
            case -2:
                // Go to the previous month
                if (--month < 1) {
                    month = 12; // Wrap to December
                    --year;
                }
                break;
            case -3:
                // Go to the next month
                if (++month > 12) {
                    month = 1; // Wrap to January
                    ++year;
                }
                break;
            default:
                // Display selected day
                cout << "Day " << userInput << " selected.\n";
                Sleep(1000);
                break;
        }
    }
}

/*void display_calendar() {
    time_t t = time(nullptr);
    tm* currentTime = localtime(&t);

    int year = currentTime->tm_year + 1900;
    int month = currentTime->tm_mon + 1;
    // Array of month names and number of days
    const char* monthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Leap year adjustment
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    // Get the starting day of the week for the month
    tm timeIn = {};
    timeIn.tm_year = year - 1900;
    timeIn.tm_mon = month - 1;
    timeIn.tm_mday = 1;
    mktime(&timeIn);
    int startDay = timeIn.tm_wday; // 0 = Sunday, 1 = Monday, ...

    // Print the header
    printSeparatorLine();
    cout << "# " << setw(CALENDAR_WIDTH - 3) << left
              << (string(monthNames[month - 1]) + " " + to_string(year)) << "#\n";
    printSeparatorLine();

    // Print day names
    const char* dayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    for (const char* dayName : dayNames) {
        printBlock(dayName);
    }
    cout << "\n";
    printSeparatorLine();

    // Fill blocks with day numbers
    vector<string> blocks(7, ""); // Create 7 blocks for each week
    int day = 1;

    // Fill in leading empty blocks for days before the start
    for (int i = 0; i < startDay; ++i) {
        blocks[i] = "";
    }

    // Fill in the days of the month
    for (int i = startDay; i < 7 && day <= daysInMonth[month - 1]; ++i) {
        blocks[i] = to_string(day++);
    }

    // Print the first row
    printCalendarBlockRow(blocks);
    printSeparatorLine();

    // Print the remaining weeks
    while (day <= daysInMonth[month - 1]) {
        blocks = vector<string>(7, ""); // Reset the blocks
        for (int i = 0; i < 7 && day <= daysInMonth[month - 1]; ++i) {
            blocks[i] = to_string(day++);
        }
        printCalendarBlockRow(blocks);
        printSeparatorLine();
    }
        cout << "\nEnter -1 to go back, -2 to look at previous month, -3 to look at next month, or a day number to look at that day: ";
    int userInput = input_check(-1, 31);
    switch(userInput){
        case -1:
            break;
        default:
            cout << "day " << userInput;
            Sleep(1000);
            break;
    }
}*/

void update_time() {
    // Get the current time
    time_t now = time(nullptr);
    timeStr = ctime(&now);
}

void display_stats(){
    update_time();
    cout << "Credits: " << credits << ".    Current Task: " << currentTask << ". Next Task: " << nextTask << ".     Time: " << timeStr << endl;
}

int input_check(int min, int max)
{
    int userInput;
    while (!(cin >> userInput) || userInput < min || userInput > max) {
        cout << "Invalid input. Enter number between " << min << " and " << max << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return userInput;
}

// Function to get the console's current width and height
void get_console_size(int &width, int &height) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    } else {
        // Fallback values in case of failure
        width = 120;  // Default console width
        height = 30; // Default console height
    }
}

time_t string_to_time_t(const string datetime) {
    tm tm = {}; // Initialize tm structure to zero
    istringstream ss(datetime);

    // Parse the input string
    char delimiter;
    ss >> tm.tm_mon >> delimiter >> tm.tm_mday >> delimiter >> tm.tm_year;
    ss >> tm.tm_hour >> delimiter >> tm.tm_min >> delimiter >> tm.tm_sec;

    // Adjust the fields to match the tm structure requirements
    tm.tm_mon -= 1;    // Months since January (0-11)
    tm.tm_year += 100; // Years since 1900

    // Convert to time_t
    return std::mktime(&tm);
}