#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

// 学生基类
class Student {
public:
	Student(const std::string &name, const std::string &id)
		: name_(name), id_(id) {}

	virtual ~Student() {}

	virtual void CalculateAverageScore() = 0;

	virtual void PrintAverageScore() const = 0;

protected:
	std::string name_;
	std::string id_;
	double average_score_;
};

// 文科学生类
class LiberalArtsStudent : public Student {
public:
	LiberalArtsStudent(const std::string &name, const std::string &id, const std::vector<double> &common_scores, const std::vector<double> &liberal_arts_scores)
		: Student(name, id), common_scores_(common_scores), liberal_arts_scores_(liberal_arts_scores) {
		CalculateAverageScore();
	}

	void CalculateAverageScore() override {
		double total_score = 0;
		for (const double score : common_scores_) {
			total_score += score;
		}
		for (const double score : liberal_arts_scores_) {
			total_score += score;
		}
		average_score_ = total_score / (common_scores_.size() + liberal_arts_scores_.size());
	}

	void PrintAverageScore() const override {
		std::cout << "文科学生 " << name_ << " 的平均成绩: " << average_score_ << std::endl;
	}

private:
	std::vector<double> common_scores_;
	std::vector<double> liberal_arts_scores_;
};

// 理科学生类
class ScienceStudent : public Student {
public:
	ScienceStudent(const std::string &name, const std::string &id, const std::vector<double> &common_scores, const std::vector<double> &science_scores)
		: Student(name, id), common_scores_(common_scores), science_scores_(science_scores) {
		CalculateAverageScore();
	}

	void CalculateAverageScore() override {
		double total_score = 0;
		for (const double score : common_scores_) {
			total_score += score;
		}
		for (const double score : science_scores_) {
			total_score += score;
		}
		average_score_ = total_score / (common_scores_.size() + science_scores_.size());
	}

	void PrintAverageScore() const override {
		std::cout << "理科学生 " << name_ << " 的平均成绩: " << average_score_ << std::endl;
	}

private:
	std::vector<double> common_scores_;
	std::vector<double> science_scores_;
};

std::vector<std::string> SplitString(const std::string &str, char delimiter) {
	std::vector<std::string> result;
	std::stringstream ss(str);
	std::string item;

	while (std::getline(ss, item, delimiter)) {
		result.push_back(item);
	}

	return result;
}

std::vector<double> ParseScores(const std::vector<std::string> &score_strings) {
	std::vector<double> scores;
	for (const std::string &score_str : score_strings) {
		scores.push_back(std::stod(score_str));
	}
	return scores;
}

int main() {
	std::ifstream common_score_file("公共课成绩.csv");
	std::ifstream liberal_arts_score_file("文科成绩.csv");
	std::ifstream science_score_file("理科成绩.csv");

	std::vector<Student *> students;

	std::string line;
	while (std::getline(common_score_file, line)) {
		std::vector<std::string> items = SplitString(line, ',');
		std::string name = items[0];
		std::string id = items[1];
		std::vector<double> common_scores = ParseScores(std::vector<std::string>(items.begin() + 2, items.end()));

		std::getline(liberal_arts_score_file, line);
		items = SplitString(line, ',');
		std::vector<double> liberal_arts_scores = ParseScores(std::vector<std::string>(items.begin() + 2, items.end()));

		students.push_back(new LiberalArtsStudent(name, id, common_scores, liberal_arts_scores));

		std::getline(science_score_file, line);
		items = SplitString(line, ',');
		std::vector<double> science_scores = ParseScores(std::vector<std::string>(items.begin() + 2, items.end()));

		students.push_back(new ScienceStudent(name, id, common_scores, science_scores));
	}

	for (Student *student : students) {
		student->PrintAverageScore();
	}

	for (Student *student : students) {
		delete student;
	}

	return 0;
}