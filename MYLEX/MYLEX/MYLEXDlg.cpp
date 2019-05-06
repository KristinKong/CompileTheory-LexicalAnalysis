
// MYLEXDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MYLEX.h"
#include "MYLEXDlg.h"
#include "afxdialogex.h"
#include"MAlex.h"
#include<string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnYuan();
//	afx_msg void OnAlybutton();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMYLEXDlg 对话框



CMYLEXDlg::CMYLEXDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMYLEXDlg::IDD, pParent)
	, source(_T(""))
	, cpreop(_T(""))
	, relist(_T(""))
	, result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMYLEXDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INPUTEDIT, source);
	DDX_Text(pDX, IDC_LISTEDIT, cpreop);
	DDX_Text(pDX, IDC_RESERVEDIT, relist);
	DDX_Text(pDX, IDC_RESULTEDIT, result);
	DDX_Control(pDX, IDC_INPUTEDIT, sour_edit);
	DDX_Control(pDX, IDC_LISTEDIT, edit_list);
	DDX_Control(pDX, IDC_RESULTEDIT, result_edit);
	DDX_Control(pDX, IDC_RESERVEDIT, res_edit);
}

BEGIN_MESSAGE_MAP(CMYLEXDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_YUAN, &CMYLEXDlg::OnBnClickedYuan)
ON_BN_CLICKED(IDC_ALYBUTTON, &CMYLEXDlg::OnBnClickedAlybutton)
END_MESSAGE_MAP()


// CMYLEXDlg 消息处理程序

BOOL CMYLEXDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMYLEXDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMYLEXDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMYLEXDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMYLEXDlg::OnBnClickedYuan()
{
	CString filepathname;    //弹出对话框并读取文件
	CString filename;
	filepathname = "";
	filename = "";
	CFileDialog FileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, CString("ALL File (*.*)|*.*||"), AfxGetMainWnd());
	if (FileDlg.DoModal() == IDOK){
		filepathname = FileDlg.GetPathName();
		filename = FileDlg.GetFileName();
	}
	ifstream infile;
	infile.open(filepathname, ios::in);
	if (!infile){
		MessageBox(filepathname);
		return;
	} 
	Lex_analyzer.COPE(infile);    
	char buffer[256];
	infile.seekg(0);   //回到文件开头
	while (infile.getline(buffer, 256,'\n')){   //读取源文件到source中
		strcat_s(buffer, 256, "\r\n");
		source += buffer;
	}
	sour_edit.SetWindowTextW(source);
	ifstream prefile;
	prefile.open("preout.txt");
    while (prefile.getline(buffer, 256, '\n')){   //读取预处理后的文件到预处理框中
		strcat_s(buffer, 256, "\r\n");
		cpreop += buffer;
	}
	edit_list.SetWindowTextW(cpreop);
	infile.close();
	prefile.close();
}


void CMYLEXDlg::OnBnClickedAlybutton()
{
	ifstream resfile;
	resfile.open("resout.txt");
	char buffer[256];
	while (resfile.getline(buffer, 256, '\n')){   //读取处理后的文件到result中
		strcat_s(buffer, 256, "\r\n\r\n");
	    result += buffer;
	}
	result_edit.SetWindowTextW(result);
	Lex_analyzer.print_list(relist);
	res_edit.SetWindowTextW(relist);
	resfile.close();
}

