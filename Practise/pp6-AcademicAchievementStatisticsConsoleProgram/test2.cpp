#include <iostream>
#include <fstream>
#include <string>

class Student {
protected:
    std::string name;
    int studentID;
    float* scores;
    int numCourses;

public:
    Student(const std::string& n, int id, int numCourses);
    virtual ~Student();

    virtual float getAverageScore() = 0;
    virtual void printInfo() = 0;
    virtual float getCommonCourseAverage() = 0;
};

Student::Student(const std::string& n, int id, int numCourses)
    : name(n), studentID(id), numCourses(numCourses) {
    scores = new float[numCourses];
}

Student::~Student() {
    delete[] scores;
}

class ArtsStudent : public Student {
public:
    ArtsStudent(const std::string& n, int id, int numCourses);
    float getAverageScore() override;
    void printInfo() override;
    float getCommonCourseAverage() override;
    float getArtsCourseAverage();
};

ArtsStudent::ArtsStudent(const std::string& n, int id, int numCourses)
    : Student(n, id, numCourses) {
}

float ArtsStudent::getAverageScore() {
    float totalScore = 0.0;
    for (int i = 0; i < numCourses; ++i) {
        totalScore += scores[i];
    }
    return totalScore / numCourses;
}

void ArtsStudent::printInfo() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Student ID: " << studentID << std::endl;
    std::cout << "Average Score: " << getAverageScore() << std::endl;
}

float ArtsStudent::getCommonCourseAverage() {
    float totalScore = 0.0;
    for (int i = 0; i < numCourses; ++i) {
        totalScore += scores[i];
    }
    return totalScore / numCourses;
}

float ArtsStudent::getArtsCourseAverage() {
    // Calculate average score for arts-specific courses
    // ...
}

class ScienceStudent : public Student {
public:
    ScienceStudent(const std::string& n, int id, int numCourses);
    float getAverageScore() override;
    void printInfo() override;
    float getCommonCourseAverage() override;
    float getScienceCourseAverage();
};

ScienceStudent::ScienceStudent(const std::string& n, int id, int numCourses)
    : Student(n, id, numCourses) {
}

float ScienceStudent::getAverageScore() {
    // Calculate average score for science student
    // ...
}

void ScienceStudent::printInfo() {
    // Print science student information
    // ...
}

float ScienceStudent::getCommonCourseAverage() {
    // Calculate average score for common courses
    // ...
}

float ScienceStudent::getScienceCourseAverage() {
    // Calculate average score for science-specific courses
    // ...
}

int main() {
    // Read student scores from CSV files
    // ...

    // Create and store ArtsStudent and ScienceStudent objects
    // ...

    // Process command line inputs and display statistics
    // ...

    return 0;
}
