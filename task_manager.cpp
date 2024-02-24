#include <iostream> 

using namespace std;

class Task
{
    private:
        string name;
        int priority;
        string due_date;
    public:
    Task() {

    }
    ~Task() {

    }
    sring get_name()
    {
        return name;
    }
    void set_name(string n)
    {
        name = n;
    }
    sring get_due_date()
    {
        return due_date;
    }
    void set_due_date(string dd)
    {
        due_date = dd;
    }
    void add_task()
    {
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
    Task task1;
    char input;
    string name;
    int priority;
    string due_date;

    cout << "------- WELCOME TO TASK MANAGER -------" << endl << endl;
    cout << date << " - You have" << num << "tasks due today" << endl;
    if (num == 0) 
        cout << "YAY do something other than homework today ;D" << endl;
    else
        cout << "Get to work, you got this!!" << endl;

    do{    
    cout << "Choose an option:" << endl;
    cout << "a: add task" << endl;
    cout << "e: edit task" << endl;
    cout << "d: delete task" << endl;
    cout << "s: show current tasks" << endl;
    cout << "q: quit" << endl;
    cin >> input;
    } while (input != 'q');

    if (input == 'a')
    {
        cout << "Name of task: ";
        getline(cin, name);
        cout << "Due date of task: ";
        getline(cin, due_date);

        task1.set_name(name);
        task1.set_due_date(due_date);

        add_task();
    }
    else if (input == 'e')
    {
        cout << "Name of task that needs editing: ";
        getline(cin, name);

        task1.set_name(name);

        edit_task();
    }
    else if (input == 'd')
    {
        cout << "Name of task to delete: ";
        getline(cin, name);

        task1.set_name(name);

        delete_task();
    }
    else if (input == 's')
    {
        show_tasks()
    }   

    return 0;
}
