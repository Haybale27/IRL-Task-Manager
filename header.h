#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <thread>
#include <atomic>
#include <chrono>
#include <vector>
#include <windows.h>
#include <fstream>
#include <limits>
#include <sstream>

using namespace std;

struct Task{
    string name;
    string description;
    string type;
    time_t dueDate;
    int importance;
    int estTime;
    int priority;
};

const int CALENDAR_WIDTH = 238;
const int BLOCK_WIDTH = CALENDAR_WIDTH / 7;
const int BLOCK_HEIGHT = 12;

vector<string> testTasks = {"event 1", "event 2", "event 3", "event 4", "event 5", "event 6", "event 7", "event 8", "event 9", "event 10", "event 11", "event 12", "event 13", "event 14", "event 15", "event 16", "event 17", "event 18", "event 19"};
vector<Task> tasks;
int screenWidth = 120;
int screenHeight = 40;
atomic<bool> running(true);
string timeStr = "now";
int credits = 0;
string currentTask = "work on task manager";
string nextTask = "eat lunch";

void main_menu();
void display_todo_list();
void display_schedule();
void manage_tasks();
void manage_schedule();
void credits_shop();

void read_tasks_file();
void read_events_file();
void read_weekly_schedule_file();
void read_save_file();

void write_tasks_file();
void write_events_file();
void write_weekly_schedule_file();
void write_save_file();

void display_calendar();
void update_time();
void display_stats();
int input_check(int min, int max);
void get_console_size(int &width, int &height);
time_t string_to_time_t(const string datetime);

#endif