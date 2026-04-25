#pragma once 
#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
constexpr int subnum=5;
constexpr int maxdegree=100;
const string subnames[subnum]={"Logic","Statistics","Numerical analysis","Machine","Control"};

struct student {
string id;
string name;
double grades[subnum];
double total_rate(){
    return((grades[0]+grades[1]+grades[2]+grades[3]+grades[4])/subnum);};
};
void add_student(vector<student>& students);
void display(vector<student>& students);
void Search(vector<student>& students);
void update (vector<student>& students);
void delete_student(vector<student>& students);
void show_top_performing_students (vector<student>& students);
void save_to_file(vector<student>& students);
void load_from_file(vector<student>& students);