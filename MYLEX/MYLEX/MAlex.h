#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#define BUFFER 256      //定义缓冲区大小
class MAlex{
public:
	char range[12];  //12个界符
	char opn[19][3]; //19个运算符
	string key[20]; //20个保留字
	char line[256]; //读取一行字符串
	ifstream infile;//定义文件操作
	ofstream preout, resout;
public:
	void Init();//初始化
	bool is_digit(char c); //判断是否是数字
	bool is_alpbat(char c); //判断是否字母
	int is_oprator(int &i);//判断是否操作符
	int is_range(int &i);//判断是否界符
	int alpbat_c(int &i);//判断首字母是c
	int alpbat_i(int &i);//判断首字母是i
	int alpbat_s(int &i);//判断首字母是s
	int alpbat_e(int &i);//判断首字母是e
	void recog_reserve(int &i, int &num); //识别保留字
	void cope_firsrtaph(int &i);//处理首字符是字母
	void cope_firsrtnum(int &i);//处理首字符是数字
	void cope_range(int num, int &i);//处理首字符是界符
	void cope_operaor(int &i);//处理首字符是操作符
	int COPE(ifstream &inflie);//总处理程序
	void print_list(CString &s1);
};

