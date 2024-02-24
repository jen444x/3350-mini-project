#include <iostream> 
#include <fstream>
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

};

int main(int argc, char* argv[]) {
    char input;

    // Create file
    fstream my_file;
    // Opening the file for reading & writing.
    // ate - sets initial position of the file ptr to the EOF
	my_file.open("file.txt", ios::out | ios::in | ios::ate);

	if (!my_file) {
		cout << "File not created!\n";
	}
	else {
		cout << "File created successfully!\n";
		my_file.close(); 
	}


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
        add_task();
    }
    else if (input == 'e')
    {
        edit_task()
    }
    else if (input == 'd')
    {
        delete_task()
    }
    else if (input == 's')
    {
        show_tasks()
    }   

    return 0;
}