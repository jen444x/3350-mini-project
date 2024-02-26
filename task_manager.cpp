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
            string task_name, task_date;
            Task_attributes data;

            while (my_file >> task_name >> task_date) {
                data.name = task_name;
                data.due_date = task_date;
                vec.push_back(data);
                //cout << vec.back().name << " " << vec.back().due_date << endl;
            }
        }     
        my_file.close();
    }
    ~TaskManager() {
        // Save tasks from vector to file 
        my_file.open("file.txt", ios::out);
        if (my_file.is_open()) {
            for (auto& a : vec) {
                my_file << a.name << " " << a.due_date << "\n";
            }
            cout << "Data saved succesfully.\n\n";

            my_file.close(); 
        }
        else {
            cout << "File is not open. Task not added.\n\n";
        }
    }
    void add_task(string name, string due_date)
    {
        Task_attributes data;
        data.name = name;
        data.due_date = due_date;
        // add task to vector
        vec.push_back(data);
        
        for (auto& a : vec) {
            cout << a.name << " " << a.due_date << endl;
        }
    }
    void edit_task()
    {
        char input;
        // find task
        int size = vec.size();
        for (int i = 0; i < size; i++) {
            if (vec[i].name == n) {
                do {
                    cout << "Task found: " << vec[i].name << " due on " << vec[i].due_date << "\n\n"
                            "Press 'n' to edit the name of the task.\n"
                            "Press 'd' to edit the due date of the task.\n";
                    cin >> input;
                    cin.ignore();

                    if (input == 'n') {
                    
                    }
                    else if (input == 'd') {
                    }
                    else {
                        cout << "Input not recognised.\n";
                    } while (input != 'n' || input != 'd');
            }
        }
    }
    bool delete_task(string n)
    {   
        char input;
        // find task
        int size = vec.size();
        for (int i = 0; i < size; i++) {
            if (vec[i].name == n) {
                // confirm its the correct task
                do {
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
        return false;
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
        cout << "q: quit" << endl << endl;
        cin >> input;
        cin.ignore();
        
        if (input == 'a')
        {
            cout << "Name of task: ";
            getline(cin, name);

            cout << "Due date of task: ";
            getline(cin, due_date);

            manager.add_task(name, due_date);
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
            // show_tasks()
        }   
} while (input != 'q');

    return 0;
}
