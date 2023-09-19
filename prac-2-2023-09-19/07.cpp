#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

struct Course {
    std::string name;
    int semester;
    bool finished;
};

struct Student {
    std::string name;
    std::string group;
    std::vector<Course> courses;
};

//--- cut here

#include <sstream>

Student make_student(std::string d) {
    Student result;

    std::string tmps;
    std::stringstream s(d);
    std::vector<std::string> words;

    while (getline(s, tmps, ';')) {
        words.push_back(tmps);
    }

    result.name = words[0]; words.erase(words.begin());
    result.group = words[0]; words.erase(words.begin());

    Course empty;
    std::fill_n(std::back_inserter(result.courses), words.size()/3, empty);
    for (int i = 0; i < words.size(); i++) {
        switch (i%3) {
            case 0:
                result.courses[(int)(i/3)].name = words[i];
                break;
            case 1:
                result.courses[(int)(i/3)].semester = std::stoi(words[i]);
                break;
            case 2:
                result.courses[(int)(i/3)].finished = words[i] == "1" ? true : false;
                break;
        }
    }

    return result;
}

bool is_upper(Student x, Student y) {
    if (x.group < y.group) {
        return true;
    } else if (x.group == y.group) {
        return x.name < y.name;
    }
    return false;
}

bool is_debtor(Student x, int cur_semester, int max_debt) {
    int debt = 0;
    for (auto& c : x.courses) {
        // Wow, actually good test cases this time allowed me to understand
        // that this is supposed to be a < and not <=. How generous.
        if ((c.semester < cur_semester) && !c.finished) {
            debt += 1;
        }
    }
    return debt > max_debt;
}

void print(std::vector<Student> students) {
    if (students.size() == 0) {
        std::cout << "Empty list!" << std::endl;
        return;
    }

    std::string prev = "";
    for (auto& s : students) {
        if (s.group != prev) {
            prev = s.group;
            std::cout << s.group << std::endl;
        }
        std::cout << "- " << s.name << std::endl;
    }
}

//---

int main()
{
    int cur_semester, max_debt, stud_count;
    std::cin >> stud_count >> cur_semester >> max_debt;
    std::cin.ignore(1);  // Убираем из потока символ \n для корректной работы getline

    std::vector<Student> students(stud_count);
    for(auto& student: students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }
    
    std::vector<Student> expulsion_candidates;
    std::copy_if(students.begin(),
                 students.end(),
                 std::back_inserter(expulsion_candidates),
                 [cur_semester, max_debt](const Student& student){
                     return is_debtor(student, cur_semester, max_debt);
                 });

    std::sort(expulsion_candidates.begin(), expulsion_candidates.end(), is_upper);
    print(expulsion_candidates);
}
