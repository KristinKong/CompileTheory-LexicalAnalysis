
// MYLEXDlg.h : 头文件


#pragma once
#include<string>
#include"MAlex.h"
#include "afxwin.h"
using namespace std;
// CMYLEXDlg 对话框
class CMYLEXDlg : public CDialogEx
{
// 构造
public:
	CMYLEXDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MYLEX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnChangeInputedit();
//	afx_msg void OnChangeListedit();

//	afx_msg void OnChangeReservedit();
//	afx_msg void OnChangeResultedit();

	MAlex Lex_analyzer;
	// //源输入
	CString source;
	// 预处理后的
	CString cpreop;
	// 保留字
	CString relist;
	// 结果
	CString result;
	afx_msg void OnBnClickedYuan();
	afx_msg void OnBnClickedAlybutton();
//	afx_msg void OnEnChangeInputedit();
	// //源文件输出
	CEdit sour_edit;
	// 驱动预处理
	CEdit edit_list;
	// 驱动结果
	CEdit result_edit;
	// 保留字驱动
	CEdit res_edit;
};

