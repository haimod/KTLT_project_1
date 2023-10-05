#include<iostream>
#include<string>
using namespace std;
const int MAX = 100;
typedef struct student {
	int code;
	char name[30];
	float subject[3];//math,English,c++
	float dtb;
} SV;

typedef struct ArrayOneDimension {
	int n;
	SV list[MAX];
} A1D;
void createEmptyList(A1D& arr) {// tạo 1 danh sách rỗng
	arr.n = 0;
	cout << "Empty student list has been created." << endl;
}
void deleteList(A1D& arr) {	//xóa danh sách sinh viên
	arr.n = 0;
	cout << "Student list has been deleted." << endl;
}
void input_sv(SV& student) {
	cout << "Enter student code: ";
	cin >> student.code;
	cout << "Enter student name: ";
	cin.ignore();
	cin.getline(student.name, 30);
	cout << "Enter math score: ";
	cin >> student.subject[0];
	cout << "Enter English score: ";
	cin >> student.subject[1];
	cout << "Enter C++ score: ";
	cin >> student.subject[2];
}
void output_sv(SV sv) {
	cout << "code student: " << sv.code;
	cout << endl;
	cout <<"Student Name: "<< sv.name;
	cout << endl;
	cout << "math score: " << sv.subject[0];
	cout << endl;
	cout << "English score: " << sv.subject[1];
	cout << endl;
	cout << "C++ score: " << sv.subject[2];
	cout << endl;
}
void removeStudent(A1D& arr) {
	int x;
	int i = 0;
	cout << "\nEnter the code of the student to be removed: ";
	cin >> x;
	while (i < arr.n) {
		if (arr.list[i].code == x) {
			for (int j = i; j < arr.n; j++) {
				arr.list[j] = arr.list[j + 1];
			}
			arr.n--;
		}
		i++;
	}
}
void searchStudent(A1D arr) {
	int x;
	int i = 0;
	if (arr.n == 0) {
		cout << "Student list is empty. Cannot search for any student." << endl;
		return;
	}
	cout << "\n Enter the code of the student to search for: ";
	cin >> x;
	while (i < arr.n) {
		if (arr.list[i].code == x) {
			output_sv(arr.list[i]);
		}
		i++;
	}
}
void updateStudent(A1D& arr) {
	if (arr.n == 0) {
		cout << "Student list is empty. Cannot update any student." << endl;
		return;
	}
	int x;
	cout << "\nEnter the code of the student to update: ";
	cin >> x;
	for (int i = 0; i < arr.n; i++) {
		if (arr.list[i].code == x) {
			output_sv(arr.list[i]);
			cout << "Enter updated information for student with code :" << endl; 
			input_sv(arr.list[i]);
		}
	}
	cout << "\n list after update: ";
	for (int i = 0; i < arr.n; i++) {
		output_sv(arr.list[i]);
		cout << endl;
	}
}
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
void sortList(A1D& arr) {
	for (int i = 0; i < arr.n - 1; i++) {
		for (int j = 0; j < arr.n - i - 1; j++) {
			float avg1 = (arr.list[j].subject[0] + arr.list[j].subject[1] + arr.list[j].subject[2]) / 3;
			float avg2 = (arr.list[j + 1].subject[0] + arr.list[j + 1].subject[1] + arr.list[j + 1].subject[2]) / 3;
			if (avg1 > avg2) {
				swap(arr.list[j], arr.list[j + 1]);
			}
		}
	}
}
void output_dssv(A1D arr) {
	for (int i = 0; i < arr.n; i++) {
		cout << "\n sinh vien thu " << i + 1;
		cout << endl;
		output_sv(arr.list[i]);
		cout << endl;
	}
}
void removeDuplicates(A1D arr) {
	output_dssv(arr);
	cout << "\n List of students with duplicate codes: ";
	for (int i = 0; i < arr.n - 1; i++) {
		for (int j = i + 1; j < arr.n; j++) {
			if (arr.list[i].code == arr.list[j].code) {
				output_sv(arr.list[j]);
			}
		}
	}
}
void DeleteDuplicateCodes(A1D& arr) {
	for (int i = 0; i < arr.n - 1; i++) {
		for (int j = i + 1; j < arr.n; j++) {
			if (arr.list[i].code == arr.list[j].code) {
				for (int k = j; k < arr.n; k++)
					arr.list[j] = arr.list[j + 1];
			}
			arr.n--;
		}
	}
}
void mergeLists(A1D& arr, A1D& arr_1) {
	cout << "\n nhap danh sach sinh vien lop thu 2: ";
	SV a;
	input_sv(a);
	int i = 0, j = 0;
	while (j < arr_1.n) {
		arr.list[arr.n] = arr_1.list[j];
		arr.n++;
		j++;
	}
	for (int i = 0; i < arr.n - 1; i++) {
		if (arr.list[i].subject[0] > arr.list[i + 1].subject[0]) {
			swap(arr.list[i], arr.list[i + 1]);
		}
	}
	output_dssv(arr);
}
void searchStudentBinary(A1D arr) {
	int x;
	if (arr.n == 0) {
		cout << "\n Student list is empty.Cannot search for any student.";
		return;
	}
	cout << "\nEnter the math sorce of the student to search for: ";
	cin >> x;
	int left = 0;
	int right = arr.n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr.list[mid].subject[0] == x) {
			output_sv(arr.list[mid]);
			return;
		}
		else if (arr.list[mid].subject[0] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
}
bool isSortedAscending(A1D arr) {
	for (int i = 1; i < arr.n; i++) {
		if (arr.list[i].code < arr.list[i - 1].code) {
			return false;
		}
	}
	return true;
}
bool isSortedDescending(A1D arr) {
	for (int i = 1; i < arr.n; i++) {
		if (arr.list[i].code > arr.list[i - 1].code) {
			return false;
		}
	}
	return true;
}
bool checkPoint(SV &student) {
	
		float avg = (student.subject[0] + student.subject[1] + student.subject[2]) / 3;
		
			return avg>=8.0 ;
}
void checkGoodStudent(A1D& arr) {
	int mid = arr.n / 2;
	int left = 0;
	int right = 0;
	for (int i = 0; i < mid; i++) {
		if (checkPoint(arr.list[i]) == true) {
			left++;
		}
	}
	for (int j = mid; j < arr.n; j++) {
		if (checkPoint(arr.list[j]) == true) {
			right++;
		}
	}
	if (left > right) {
		cout << "\n The left side has a higher total number of excellent students";
	}
	else {
		cout << "\n The right side has a higher total number of excellent students";
	}
}
void mathSumIsLessThan_5(A1D arr) {
	for (int i = 1; i < arr.n; i++) {
		float diemtoan = arr.list[i].subject[0] + arr.list[i - 1].subject[0];
		if (diemtoan < 5) {
			output_sv(arr.list[i - 1]);
			output_sv(arr.list[i]);
			break;
		}
	}
}
void addStudentOthercode(A1D& arr) {
	if (arr.n == MAX) {
		cout << "Student list is full. Cannot add more students." << endl;
		return;
	}

	SV newStudent;
	cout << "\nNhap ma code: ";
	cin >> newStudent.code;

	for (int i = 0; i < arr.n; i++) {
		if (newStudent.code == arr.list[i].code) {
			cout << "code to be heard. Please enter again." << endl;
			cout << "\nEnter code: ";
			cin >> newStudent.code;
			i = -1; // Đặt i = -1 để kiểm tra lại từ đầu danh sách
		}
	}
	cin.ignore(); // Xóa bộ nhớ đệm của cin để getline hoạt động chính xác
	cout << "\nNhap ten sinh vien: ";
	cin.getline(newStudent.name, 30);
	cout << "Nhap diem mon toan: ";
	cin >> newStudent.subject[0];
	cout << "Nhap diem mon anh: ";
	cin >> newStudent.subject[1];
	cout << "Nhap diem mon C++: ";
	cin >> newStudent.subject[2];

	arr.list[arr.n] = newStudent;
	arr.n++;
	cout << "Student has been added to the list." << endl;
}
void SeparateTheSegment0fExcellentStudents(A1D& arr, A1D& arr_1) {
	arr_1.n = 0;
	for (int i = 0; i < arr.n; i++) {
		if (checkPoint(arr.list[i]) == true) {
			arr_1.list[arr_1.n] = arr.list[i];
			arr_1.n++;
		}
	}
	for (int i = 0; i < arr_1.n; i++) {
		output_sv(arr_1.list[i]);
	}
}
void printStudentList(A1D arr) {
	for (int i = 0; i < arr.n; i++) {
		cout << "Student " << i + 1 << ":" << endl;
		cout << "Code: " << arr.list[i].code << endl;
		cout << "Name: " << arr.list[i].name << endl;
		cout << "Subject 1: " << arr.list[i].subject[0] << endl;
		cout << "Subject 2: " << arr.list[i].subject[1] << endl;
		cout << "Subject 3: " << arr.list[i].subject[2] << endl;
		cout << endl;
	}
	
}
A1D filterTopStudents( A1D& studentList) {
	A1D topStudents;
	topStudents.n = 0;

	for (int i = 0; i < studentList.n; i++) {
		bool isTopStudent = true;
		for (int j = 0; j < 3; j++) {
			if (studentList.list[i].subject[j] <= 6.5) {
				isTopStudent = false;
				break;
			}
		}
		if (isTopStudent) {
			topStudents.list[topStudents.n] = studentList.list[i];
			topStudents.n++;
		}
	}

	return topStudents;
}
void printTopStudent(const A1D& studentList) {
	int maxIndex = 0;
	float maxAverage = (studentList.list[0].subject[0] + studentList.list[0].subject[1] + studentList.list[0].subject[2]) / 3.0;

	for (int i = 1; i < studentList.n; i++) {
		float average = (studentList.list[i].subject[0] + studentList.list[i].subject[1] + studentList.list[i].subject[2]) / 3.0;
		if (average > maxAverage) {
			maxAverage = average;
			maxIndex = i;
		}
	}

	cout << "Student with the highest academic performance:" << endl;
	cout << "Code: " << studentList.list[maxIndex].code << endl;
	cout << "Name: " << studentList.list[maxIndex].name << endl;
	cout << "Average Score: " << maxAverage << endl;
}
void menu() {
	cout << "========================MENU=======================" << endl;
	cout << "1. Create an empty student list" << endl;
	cout << "2. Delete the student list" << endl;
	cout << "3. Add a student to the list" << endl;
	cout << "4. Remove a student from the list" << endl;
	cout << "5. Search for a student in the list" << endl;
	cout << "6. Update information of a student" << endl;
	cout << "7. Sort the list in ascending order based on average score" << endl;
	cout << "8. Remove duplicate students with the same code" << endl;
	cout << "9. Merge two lists of students based on math score" << endl;
	cout << "10. Perform binary search on the sorted list from option 9" << endl;
	cout << "11. Check if the list is sorted in ascending order" << endl;
	cout << "12. Check if the list is sorted in descending order" << endl;
	cout << "13. Check if the first half of the list has more excellent students than the second half" << endl;
	cout << "14. Find the first pair of students whose math sum is less than 5" << endl;
	cout << "15. Add a student to the list with duplicate code check" << endl;
	cout << "16. Separate excellent students into a separate list" << endl;
	cout << "17. Print the student list" << endl;
	cout << "18. Separate top 3 students based on average score" << endl;
	cout << "19. Print the best student in the list" << endl;
	cout << "0. Exit" << endl;
	cout << "========================END=======================" << endl;
}
void getMenuChoice(A1D arr) {
	int choice;
	do {
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			createEmptyList(arr);
			menu();
			break;
		case 2:
			system("pause");
			deleteList(arr);
			menu();
			break;
		case 3:
			system("pause");
			if (arr.n == MAX) {
				cout << "Student list is full. Cannot add more students." << endl;
				return;
			}
			SV newStudent;
			input_sv(newStudent);
			arr.list[arr.n] = newStudent;
			arr.n++;
			cout << "Student has been added to the list." << endl;
			break;
			menu();
			break;
		case 4:
			system("pause");
			if (arr.n == 0) {
				cout << "Student list is empty. Cannot remove any student." << endl;
				return;
			}
			removeStudent(arr);
			menu();
			break;
		case 5:
			system("pause");
			searchStudent(arr);
			menu();
			break;
		case 6:
			system("pause");
			updateStudent(arr);
			menu();
			break;
		case 7:
			system("pause");
			sortList(arr);
			menu();
			break;
		case 8:
			system("pause");
			removeDuplicates(arr);
			menu();
			break;
		case 9:
			system("pause");
			DeleteDuplicateCodes(arr);
			menu();
			break;
		case 10:
			system("pause");
			A1D arr_1;
			mergeLists(arr, arr_1);
			menu();
			break;
		case 11:
			system("pause");
			searchStudentBinary(arr);
			menu();
			break;
		case 12:
			system("pause");
			cout<<isSortedAscending(arr);
			menu();
			break;
		case 13:
			system("pause");
			cout<<isSortedDescending(arr);
			menu();
			break;
		case 14:
			system("pause");
			checkGoodStudent(arr);
			menu();
			break;
		case 15:
			system("pause");
			mathSumIsLessThan_5(arr);
			menu();
			break;
		case 16:
			system("pause");
			addStudentOthercode(arr);
			menu();
			break;
		case 17:
			system("pause");
			SeparateTheSegment0fExcellentStudents(arr,arr_1);
			menu();
			break;
		case 18:
			system("pause");
			printStudentList(arr);
			menu();
			break;
		case 19:
			system("pause");
			filterTopStudents(arr);
			menu();
			break;
		case 20:
			system("pause");
			printTopStudent(arr);
			menu();
			break;
		default:
			break;
		}

	} while (choice!=0);
	
}
int main() {
	A1D arr,arr_1;
	/*input_sv(a);*/
	createEmptyList(arr);
	menu();
	getMenuChoice(arr);
	return 0;
}