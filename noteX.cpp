#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class task {
    public:
    string name;
};
void nop(string& a){
    while(a[0]==' '){
        a.erase(a.begin());
    }
}
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
    cout << "Welcome to noteX v1.1\nIf you need help write --help\n";
    
    while(true){
        if(!a.empty())printtask(a);
        else cout << "No current tasks!" << endl;
        string wtd;
        cin >> wtd;
        if(wtd == "add"){
            task temp;
            string name;
            while(name.empty()){getline(cin, name);nop(name);}
            temp.name = name;
            a.push_back(temp);
            tofile(a);
        }
        if(wtd == "del"){
            int del;
            cin >> del;
            if(del < 1 || del > a.size()){cout << "No such task\n";continue;}
            a.erase(a.begin()+del-1);
            tofile(a);
        }
        if(wtd == "--help"){
            cout << "add <name> - new task\ndel <number> - delete task\n";
        }
}
return 0;
}