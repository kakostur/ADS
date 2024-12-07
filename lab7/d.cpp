#include <bits/stdc++.h>

using namespace std;

struct Student{
    string last_name, first_name;
    double gpa;
};

bool comp(Student &a, Student &b) {
    if(a.gpa < b.gpa) 
        return true;
    if(a.gpa == b.gpa && a.last_name < b.last_name)
        return true;
    if(a.gpa == b.gpa && a.last_name == b.last_name && a.first_name < b.first_name)
        return true;
    return false;
}

int main() {
    int n; cin >> n;
    vector<Student> v;
    map<string,double> mp = {{"A+", 4.0}, {"A", 3.75}, {"B+", 3.5}, {"B",3}, {"C+", 2.5}, {"C", 2}, {"D+", 1.5}, {"D", 1.0}, {"F", 0}};

    for(int i = 0; i < n; i++) {
        string lastName, firstName; cin >> lastName >> firstName;
        int m; cin >> m;
        double sumGPA = 0;
        double gg = 0;
        double ff = 0; 
        for(int j = 0; j < m; j++) {
            string arip; cin >> arip;
            double san; cin >> san;
            gg += (san * mp[arip]);
            ff += san;
        }
        sumGPA = gg / ff;
        v.push_back({lastName, firstName, sumGPA});
    }

    sort(v.begin(), v.end(), comp);

    for(auto i : v) cout << i.last_name << " " << i.first_name <<" " << setprecision(3) << fixed << i.gpa <<endl;
}