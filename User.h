#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

class User {
	char PlayerName[22];
	char account[22];
	char password[22];
	bool vip;
	bool isInitial;
	bool isAllPassed;
	bool isFirstPassed;
	int Num_Of_isPassed_Level;
	long long History_Score;
	void setAll(const char PlayerName[22], const char account[22], const char password[22], int Num_Of_isPassed_Level, long long History_Score, bool vip, bool isInitial, bool isAllPassed, bool isFirstPassed);
public:
	User();
	const std::string get_PlayerName();
	const std::string get_account();
	void set_Num_Of_isPassed_Level(int Num_Of_isPassed_Level);
	int get_Num_Of_isPassed_Level();
	void set_vip(bool vip);
	bool get_vip();
	void set_isAllPassed(bool isAllPassed);
	bool get_isAllPassed();
	void set_History_Score(long long History_Score);
	long long get_History_Score();
	void set_isInitial(bool isInitial);
	bool get_isInitial();
	void set_isFirstPassed(bool isFirstPassed);
	bool get_isFirstPassed();
	void show();
	int isLogin(std::string input[]);
	int Register(std::string input[]);
	bool save();
};