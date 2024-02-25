#include <iostream> 
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class TaskManager
{
    private:
        struct Task_attributes {
            string name;
            string due_date;
            // int priority;  
        };
        vector<Task_attributes> vec;
        fstream my_file;
    public:
    TaskManager() {   
        // Opening the file for reading & writing.
        my_file.open("tasks.txt", ios::out | ios::in | ios::app);
        if (!my_file) {
            cout << "File not created!\n\n";
        }
        else {
            cout << "File created successfully!\n\n";
        }     

        // Load tasks from file into vector
        string task_name, task_date;
        Task_attributes data;

        while (my_file >> task_name >> task_date) {
            data.name = task_name;
            data.due_date = task_date;
            vec.push_back(data);
            cout << vec.back().name << " " << vec.back().due_date << endl;
        }
    }
    ~TaskManager() {
        // Save tasks to file 
        my_file.close(); // close file
    }
    void add_task(string name, string due_date)
    {
        // add task to file
        if (my_file.is_open()) {
            my_file << name << " " << due_date << "\n";
            my_file.flush(); // Flush the output stream
            cout << "Task added successfully!\n\n";
        } else {
            cout << "File is not open. Task not added.\n\n";
        }
    }
    void edit_task()
    {
    }
    void delete_task()
    {
    }
    void show_tasks()
    {
    }
    
};

int main() {
    TaskManager manager;

    char input;
    string name, date;
    int priority, num;
    string due_date;
/*
    cout << "------- WELCOME TO TASK MANAGER -------" << endl << endl;
    cout << date << " - You have" << num << "tasks due today" << endl;
    if (num == 0) 
        cout << "YAY do something other than homework today ;D" << endl;
    else
        cout << "Get to work, you got this!!" << endl;
*/
    do {    
    cout << "Choose an option:" << endl;
    cout << "a: add task" << endl;
    cout << "e: edit task" << endl;
    cout << "d: delete task" << endl;
    cout << "s: show current tasks" << endl;
    cout << "q: quit" << endl;
    cin >> input;
    cin.ignore();
    
    if (input == 'a')
    {
        cout << "Name of task: ";
        getline(cin, name);

        cout << "Due date of task: ";
        getline(cin, due_date);

        manager.add_task(name, due_date);

        // add_task();
    }
    else if (input == 'e')
    {
        cout << "Name of task that needs editing: ";
        getline(cin, name);


        // edit_task();
    }
    else if (input == 'd')
    {
        cout << "Name of task to delete: ";
        getline(cin, name);


        // delete_task();
    }
    else if (input == 's')
    {
        // show_tasks()
    }   

} while (input != 'q');

    return 0;
}
