#include <iostream>
#include <memory> 
#include <string>
#include <vector>


class Teacher;
class Student
{
public:
	Student(std::string name)
	{
		m_student = name;
		std::cout << name << " constructor\n";
	}
	~Student()
	{
		std::cout << m_student << " destructor\n";
	}

	std::string nameStudent() { return m_student; }
	std::shared_ptr<Teacher> getTeacher() { m_teacher; }

	void addTeacher(std::shared_ptr<Teacher>& teacher)
	{
		m_teacher = teacher;
	}


	std::string m_student;
	std::weak_ptr<Teacher> m_teacher; 
};

class Teacher
{
public:
	Teacher(const std::string& name)
	{
		m_name = name;
		std::cout << name << " constructor\n";
	}
	~Teacher()
	{
		std::cout << m_name  << " destructor\n";
	}

	friend bool S_Teacher(std::shared_ptr<Teacher>& D, std::shared_ptr<Student>& S)
	{
		D->addStudent(S);
		S->addTeacher(D);
		std::cout << S->m_student << " is now  " << D->m_name<< " 's student \n";
		return true;
	
	}

	void addStudent(std::shared_ptr<Student>& student)
	{
		m_students.push_back(student);
	}

	void AllStudents()
	{
		if (!m_students.empty())
		{
			std::cout << m_name << " students: " << std::endl;

			for (const auto& student : m_students)
			{
				std::cout << student.lock()->nameStudent() << std::endl;
			}
		}
	}


	std::string m_name;
	std::vector<std::weak_ptr<Student>> m_students;

};

int main()
{
	
	auto teacher{ std::make_shared<Teacher>("Michael") };//создание учителя по имени Michael
	auto teacher2{ std::make_shared<Teacher>("Alex") };
	auto student1{ std::make_shared<Student>("Ann") };//создание студента по имени Ann
	auto student2{ std::make_shared<Student>("Maria") };//создание студента по имени Maria


	S_Teacher(teacher, student1);//заставляем Michael указывать на Ann и наоборот
	S_Teacher(teacher, student2);//заставляем Michael указывать на Maria и наоборот

	S_Teacher(teacher2, student1);
	S_Teacher(teacher2, student2);

	

	teacher->AllStudents();//получаем имена студентов Michael

	return 0;
}
