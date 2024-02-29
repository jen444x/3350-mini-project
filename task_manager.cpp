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
            int priority;  // 1 - high priority, 2 - med priority, 3 - low priority
            // string description
        };
        vector<Task_attributes> vec;
        fstream my_file;
    public:
    TaskManager() {   
        // Opening the file for reading & writing.
        my_file.open("file.txt", ios::in );
        if (!my_file) {
            // Create file
            my_file.open("file.txt", ios::out);
            if (!my_file) {
                cout << "Error creating file!\n\n";
                return;
            }
        }
        else {
            // Load tasks from file into vector
            string task_name, task_date, priority_str;
            int priority;
            Task_attributes data;

            while (getline(my_file, task_name) && getline(my_file, task_date) && getline(my_file, priority_str)) {
                data.name = task_name;
                data.due_date = task_date;
                priority = stoi(priority_str);
                data.priority = priority;
                vec.push_back(data);
            }
        }     
        my_file.close();
    }
    ~TaskManager() {
        // Save tasks from vector to file 
        my_file.open("file.txt", ios::out);
        if (my_file.is_open()) {
            for (auto& a : vec) {
                my_file << a.name << "\n" << a.due_date << "\n" << a.priority << "\n";
            }
            cout << "Data saved succesfully.\n\n";

            my_file.close(); 
        }
        else {
            cout << "File is not open. Task not added.\n\n";
        }
    }

    static bool compare_dates (Task_attributes& task1, Task_attributes& task2) {
        bool less_than = false;
        if (task1.due_date <= task2.due_date) {
            if (task1.priority < task2.priority) {
                less_than = true;
            }
            else {
                less_than = false;
            }
        }
        return less_than;  // soonest dates go first
    }

    void add_task(string name, string due_date, int priority)
    {
        Task_attributes data;
        data.name = name;
        data.due_date = due_date;
        data.priority = priority;
        // add task to vector
        vec.push_back(data);
        
        cout << "\nTask has been added.\n\n";

        // sort data
        sort(vec.begin(), vec.end(), compare_dates);
    }
   bool edit_task(string n)
    {
        char input;
        string new_name, new_ddate;
        bool found;

        // find task
        int size = vec.size();
        for (int i = 0; i < size; i++) {
            if (vec[i].name == n) {
                do {
                    found = true;
                    cout << "Task found: " << vec[i].name << " due on " << vec[i].due_date << "\n\n"
                            "Press 'n' to edit the name of the task.\n"
                            "Press 'd' to edit the due date of the task.\n"
                            "Press 'x' to continue looking without deleting.\n";;
                    cin >> input;
                    cin.ignore();

                    if (input == 'n') {
                        cout << "New name: ";
                        cin >> new_name;

                        vec[i].name = new_name;
                        return true;
                    }
                    else if (input == 'd') {
                        cout << "New due date: ";
                        cin >> new_ddate;

                        vec[i].due_date = new_ddate;

                        // sort data
                        sort(vec.begin(), vec.end(), compare_dates);
                        return true;
                    }
                    else if (input == 'x') {
                        found == true;
                    }
                    else {
                        cout << "Input not recognised.\n";
                    }
                 } while (input != 'x');
            }
        }
        if (found == false) {
            cout << n << " was not found.\n\n";
        }
        return false;
    } 
    bool delete_task(string n)
    {   
        char input;
        bool found = false;

        // find task
        int size = vec.size();
        for (int i = 0; i < size; i++) {
            if (vec[i].name == n) {
                // confirm its the correct task
                do {
                    found = true;
                    cout << "Task found: " << vec[i].name << " due on " << vec[i].due_date << "\n\n"
                            "Press 'c' to confirm deletion of this task.\n"
                            "Press 'x' to continue looking without deleting.\n";
                    cin >> input;
                    cin.ignore();

                    // if it's not, continue to look for it
                    if (input == 'c') {
                        // delete task
                        vec.erase(vec.begin()+i);
                        return true;
                    }
                } while (input != 'x');
            }
        }
        if (found == false) {
            cout << n << " was not found.\n\n";
        }
        return false;
    }
    void show_tasks()
    {
        int size = vec.size();
        for (int i = 0; i < size; i++) {
            cout << vec[i].name << " - Due on " << vec[i].due_date << endl;
        }
        cout << endl;
    }
};

int main() {
    TaskManager manager;

    char input;
    string name, date;
    int priority, num;
    string due_date;
    char buf[BUFSIZ];

    time_t timer;
    struct tm *tm_info;
    time(&timer);
    tm_info = localtime(&timer);
    strftime(buf, 26, "%Y:%m:%d\n", tm_info);
    cout << buf << endl;
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
        cout << "q: quit" << endl << endl;
        cin >> input;
        cin.ignore();
        
        if (input == 'a')
        {
            cout << "Name of task: ";
            getline(cin, name);

            cout << "Due date of task: ";
            getline(cin, due_date);

            cout << "Priority level (Choose 1, 2, or 3): ";
            cin >> priority;
            cin.ignore();

            manager.add_task(name, due_date, priority);
        }
        else if (input == 'e')
        {
            cout << "Name of task that needs editing: ";
            getline(cin, name);


            if(manager.edit_task(name)) {
                cout << "Succesfully edited.\n\n";
            }
            else {
                cout << "No task was edited.\n\n";
            }
        }
        else if (input == 'd')
        {
            cout << "Name of task to delete: ";
            getline(cin, name);
            if (manager.delete_task(name)) {
                cout << "Succesfuly deleted.\n\n";
            }
            else {
                cout << "No task was deleted.\n\n";
            }
        }
        else if (input == 's')
        {
            cout << "Here are all your current tasks: " << endl << endl;
            manager.show_tasks();
        }   
} while (input != 'q');

    return 0;
}
