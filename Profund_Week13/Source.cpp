#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
struct List {
public:
	string name = "_None";
	long ID = 0, score = 0;

	void operator = (List In) {
		name = In.name;
		ID = In.ID;
		score = In.score;
	}
	void clear() {
		name = "_None";
		ID = 0, score = 0;
	}
	bool isEmpty() {
		return name == "_None";
	}
};
struct record {
	List table[20];
	int len = 0;
	void Register(long ID, string name, long score) {
		if (len <= 20) {
			table[len].name = name;
			table[len].ID = ID;
			table[len].score = score;
			len++;
		}
		else {
			cout << "Record is full" << endl;
		}
	}
	void editScore(long ID, long score) {
		bool find = false;
		int i;
		for (i = 0; i < 20; i++) {
			if (table[i].ID == ID) {
				find = true;
			}
		}
		if (find) {
			table[i].score = score;
		}
	}
	void fit() {
		for (int i = 1; i < 20; i++) {
			if (table[i-1].isEmpty()) {
				table[i - 1] = table[i];
				table[i].clear();
			}
		}
	}
	List* get(string name) {
		bool find = false;
		int i;
		for (i = 0; i < 20; i++) {
			if (table[i].name == name) {
				find = true;
			}
		}
		if (find) {
			return &table[i];
		}
	}
	void show() {
		for (int i = 0; i < 20; i++) {
			if (table[i].isEmpty()) {
				break;
			}
			cout << "ID : " << table[i].ID << "   Name : " << table[i].name << "   Score : " << table[i].score << endl;
		}
	}
};
int main() {
	record Record;
	cout << "Command available :" << endl;
	cout << "   reg : Use to register a new data" << endl;
	cout << "   list : Use to show all data" << endl;
	cout << "   analyze : Use to show analytic data" << endl << endl;
	cout << "-------------------" << endl;
	while (true) {
		string Command;
		cout << ">>> ";
		cin >> Command;
		if (Command == "reg") {
			string Name;
			long ID, score;
			cout << "-------------------" << endl << endl;
			cout << "Enter ID : ";
			scanf("%ld", &ID);
			cout << "Enter name : ";
			cin >> Name;
			cout << "Enter score : ";
			scanf("%ld", &score);
			Record.Register(ID, Name, score);
			cout << endl << "-------------------" << endl;
		}
		else if (Command == "list") {
			cout << "-------------------" << endl << endl;
			Record.show();
			cout << endl << "-------------------" << endl << endl;
		}
		else if (Command == "analyze") {
			long Index, maxScore = -1;
			for (int i = 0; i < Record.len; i++) {
				if (Record.table[i].score > maxScore) {
					Index = i;
					maxScore = Record.table[i].score;
				}
			}
			cout << "-------------------" << endl << endl;
			cout << "Max Score : " << endl;
			cout << "ID : " << Record.table[Index].ID << "   Name : " << Record.table[Index].name << "   Score : " << Record.table[Index].score << endl << endl;
			Index = -1;
			long minScore = 0;
			for (int i = 0; i < Record.len; i++) {
				if ( i == 0 || Record.table[i].score < minScore) {
					Index = i;
					minScore = Record.table[i].score;
				}
			}
			cout << "Min Score : " << endl;
			cout << "ID : " << Record.table[Index].ID << "   Name : " << Record.table[Index].name << "   Score : " << Record.table[Index].score << endl << endl;
			float mean = 0;
			for (int i = 0; i < Record.len; i++) {
				mean += float(Record.table[i].score);
			}
			mean /= Record.len;
			cout << "Mean : " << mean << endl;

			cout << endl << "-------------------" << endl << endl;
		}
	}
	return 0;
}