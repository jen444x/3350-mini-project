#include <iostream> 
#include <fstream>

using namespace std;

class TaskManager
{
    private:
        string name;
        int priority;
        string due_date;
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
    }
    ~TaskManager() {
        my_file.close(); // close file
    }
    string get_name()
    {
        return name;
    }
    void set_name(string n)
    {
        name = n;
    }
    string get_due_date()
    {
        return due_date;
    }
    void set_due_date(string dd)
    {
        due_date = dd;
    }
    void add_task()
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

        manager.set_name(name);
        manager.set_due_date(due_date);
        manager.add_task();

        // add_task();
    }
    else if (input == 'e')
    {
        cout << "Name of task that needs editing: ";
        getline(cin, name);

        manager.set_name(name);

        // edit_task();
    }
    else if (input == 'd')
    {
        cout << "Name of task to delete: ";
        getline(cin, name);

        manager.set_name(name);

        // delete_task();
    }
    else if (input == 's')
    {
        // show_tasks()
    }   

} while (input != 'q');

    return 0;
}
