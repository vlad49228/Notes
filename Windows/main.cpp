#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
using namespace std;
class task {
    public:
    string name;
};
void tofile(vector<task>& a){
     ofstream fout("tasks.txt");
     for(int i = 0; i < a.size(); i++){
        string s = a[i].name;
        fout << s << "\n";
    }
}
void Gettasks(vector<task>& a){
    ifstream fin("tasks.txt");
    a.erase(a.begin(), a.end());
    string t;
    while(getline(fin,t)){
            task temp;
            temp.name = t;
            a.push_back(temp);
    }
}
void printtask(vector<task>& a){
    int temp = 1;
    for(task t : a){
        cout << temp << ". " << t.name << "\n";
        temp++;
    }
}
int main(){
    vector<task> a;
    Gettasks(a);
    while(true){
        system("cls");
        if(!a.empty())printtask(a);
        else cout << "No current tasks!" << endl;
        cout << "What do you want to do?\n1. Add task, 2. Delete task, 3. Edit task\n(write number of what you want to do)\n";
        int wtd;
        while(!(cin>>wtd)){
            cout << "Not number\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(wtd == 1){
            string write;
            cout << "Write task: \n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, write);
            task t;
            t.name = write;
            a.push_back(t);
            tofile(a);
            continue;
        }
        if(wtd == 2){
            cout << "Write number of task that you want to delete:\n";
            int del;
            while(!(cin>>del)){
            cout << "Not number\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
            if(del-1<a.size()&&del-1>=0){
                a.erase(a.begin()+del-1);
                tofile(a);
                cout << "Succesfully delited\n";
                continue;
            }
            else {cout << "No such task\n"; continue;}
        }
    if(wtd == 3){
        cout << "Write number of task that you want to edit:\n";
        int edit;
        while(!(cin>>edit)){
            cout << "Not number\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(edit-1<a.size()&&edit-1>=0){
            cout << "Write new task:\n";
            string another;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, another);
            task t;
            t.name = another;
            a[edit-1] = t;
            tofile(a);
            continue;
        }
        else {cout << "No such task\n"; continue;}
    }
}
return 0;
}
