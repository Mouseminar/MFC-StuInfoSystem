
// StuInfoSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "StuInfoSystem.h"
#include "StuInfoSystemDlg.h"
#include "afxdialogex.h"

#include "InfoDlg.h"
#include "SeekDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CStuInfoSystemDlg 对话框



CStuInfoSystemDlg::CStuInfoSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUINFOSYSTEM_DIALOG, pParent)
	, m_max(0)
	, m_min(0)
	, m_av(_T(""))
	, m_pass(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStuInfoSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_class);
	DDX_Control(pDX, IDC_COMBO2, m_subject);
	//  DDX_Text(pDX, IDC_EDIT1, m_av);
	DDX_Text(pDX, IDC_EDIT2, m_max);
	DDX_Text(pDX, IDC_EDIT3, m_min);
	//  DDX_Text(pDX, IDC_EDIT4, m_pass);
	DDX_Text(pDX, IDC_EDIT1, m_av);
	DDX_Text(pDX, IDC_EDIT4, m_pass);
	DDX_Control(pDX, IDC_COMBO3, m_rule1);
	DDX_Control(pDX, IDC_COMBO4, m_rule2);
}

BEGIN_MESSAGE_MAP(CStuInfoSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CStuInfoSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CStuInfoSystemDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CStuInfoSystemDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CStuInfoSystemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CStuInfoSystemDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CStuInfoSystemDlg::OnBnClickedButton7)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CStuInfoSystemDlg::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CStuInfoSystemDlg::OnCbnSelchangeCombo4)
	ON_BN_CLICKED(IDC_BUTTON6, &CStuInfoSystemDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CStuInfoSystemDlg 消息处理程序

BOOL CStuInfoSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// TODO: 在此添加额外的初始化代码

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	// 整行选择、网格线
	m_list.InsertColumn(0, _T("姓名"), LVCFMT_LEFT, 140);	// 插入第2列的列名
	m_list.InsertColumn(1, _T("性别"), LVCFMT_LEFT, 140);	// 插入第3列的列名
	m_list.InsertColumn(2, _T("班级"), LVCFMT_LEFT, 140);	// 插入第4列的列名
	m_list.InsertColumn(3, _T("语文"), LVCFMT_LEFT, 140);	// 插入第5列的列名
	m_list.InsertColumn(4, _T("数学"), LVCFMT_LEFT, 140);	// 插入第6列的列名
	m_list.InsertColumn(5, _T("英语"), LVCFMT_LEFT, 140);	// 插入第7列的列名

	m_class.AddString(TEXT("1班"));
	m_class.AddString(TEXT("2班"));
	m_class.AddString(TEXT("3班"));
	m_class.AddString(TEXT("全部"));
	m_class.SetCurSel(3);

	m_subject.AddString(TEXT("语文"));
	m_subject.AddString(TEXT("数学"));
	m_subject.AddString(TEXT("英语"));
	m_subject.SetCurSel(0);

	m_rule1.AddString(TEXT("班级"));
	m_rule1.AddString(TEXT("语文"));
	m_rule1.AddString(TEXT("数学"));
	m_rule1.AddString(TEXT("英语"));
	m_rule1.SetCurSel(0);

	m_rule2.AddString(TEXT("升序"));
	m_rule2.AddString(TEXT("倒序"));
	m_rule2.SetCurSel(0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


bool CStuInfoSystemDlg::flag = false;

void CStuInfoSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CStuInfoSystemDlg::OnPaint()
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
HCURSOR CStuInfoSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CStuInfoSystemDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	if (SQL.Connect_MySQL())
	{
		Info = SQL.Get_All_Info();
		UpdateList();
	}
	else
	{
		return;
	}
}


void CStuInfoSystemDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	InfoDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		if (SQL.Add_Info(StuInfo(dlg.m_name.GetBuffer(), dlg.m_sex.GetBuffer(), dlg.m_class, dlg.m_score1, dlg.m_score2, dlg.m_score3)))
		{
			MessageBox(TEXT("添加成功！"), TEXT("提示"));
			Info.push_back(StuInfo(dlg.m_name.GetBuffer(), dlg.m_sex.GetBuffer(), dlg.m_class, dlg.m_score1, dlg.m_score2, dlg.m_score3));
			UpdateList();
		}
	}

}

void CStuInfoSystemDlg::UpdateList()
{
	m_list.DeleteAllItems();
	CString str;
	for (int i = 0; i < Info.size(); i++)
	{
		m_list.InsertItem(i, Info[i].m_name.c_str());
		m_list.SetItemText(i, 1, Info[i].m_sex.c_str());
		str.Format(TEXT("%d"), Info[i].m_class_);
		m_list.SetItemText(i, 2, str);
		str.Format(TEXT("%.1lf"), Info[i].m_score1);
		m_list.SetItemText(i, 3, str);				// 设置第4列(性别)
		str.Format(TEXT("%.1lf"), Info[i].m_score2);
		m_list.SetItemText(i, 4, str);			// 设置第5列(语文)
		str.Format(TEXT("%.1lf"), Info[i].m_score3);
		m_list.SetItemText(i, 5, str);				// 设置第6列(数学)
	}
}


void CStuInfoSystemDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = m_list.GetSelectionMark();   //获取选中行的行号
	if (nIndex == -1)
	{
		MessageBox(TEXT("请先选择要删除的数据！"), TEXT("提示"));
		return;
	}
	else
	{
		UINT i;
		i = MessageBox(_T("确定要删除这条信息吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			//你自己的代码
			if (SQL.Del_Info(Info[nIndex]))
			{
				MessageBox(TEXT("删除成功！"), TEXT("提示"));
				Info.erase(Info.begin() + nIndex);
				UpdateList();
			}
		}
	}
}


void CStuInfoSystemDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = m_list.GetSelectionMark();   //获取选中行的行号
	if (nIndex == -1)
	{
		MessageBox(TEXT("请先选择要修改的数据！"), TEXT("提示"));
		return;
	}
	else
	{
		InfoDlg dlg;
		dlg.m_name = Info[nIndex].m_name.c_str();
		dlg.m_sex = Info[nIndex].m_sex.c_str();
		dlg.m_class = Info[nIndex].m_class_;
		dlg.m_score1 = Info[nIndex].m_score1;
		dlg.m_score2 = Info[nIndex].m_score2;
		dlg.m_score3 = Info[nIndex].m_score3;
		if (dlg.DoModal() == IDOK)
		{
			if (SQL.Update_info(Info[nIndex], StuInfo(dlg.m_name.GetBuffer(), dlg.m_sex.GetBuffer(), dlg.m_class, dlg.m_score1, dlg.m_score2, dlg.m_score3)))
			{
				MessageBox(TEXT("修改成功！"), TEXT("提示"));
				Info[nIndex] = StuInfo(dlg.m_name.GetBuffer(), dlg.m_sex.GetBuffer(), dlg.m_class, dlg.m_score1, dlg.m_score2, dlg.m_score3);
				UpdateList();
			}
		}
	}
}


void CStuInfoSystemDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	SeekDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		vector<StuInfo> result = SQL.Seek_info(dlg.m_name);

		if (result.empty())
		{
			MessageBox(TEXT("查无此人！"), TEXT("提示"));
			return;
		}

		m_list.DeleteAllItems();
		CString str;
		for (int i = 0; i < result.size(); i++)
		{
			m_list.InsertItem(i, result[i].m_name.c_str());
			m_list.SetItemText(i, 1, result[i].m_sex.c_str());
			str.Format(TEXT("%d"), result[i].m_class_);
			m_list.SetItemText(i, 2, str);
			str.Format(TEXT("%.1lf"), result[i].m_score1);
			m_list.SetItemText(i, 3, str);				// 设置第4列(性别)
			str.Format(TEXT("%.1lf"), result[i].m_score2);
			m_list.SetItemText(i, 4, str);			// 设置第5列(语文)
			str.Format(TEXT("%.1lf"), result[i].m_score3);
			m_list.SetItemText(i, 5, str);				// 设置第6列(数学)
		}
	}
}


void CStuInfoSystemDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码

	int num = 0;
	double sum = 0;
	double max = 0;
	double min = 100;
	int pass = 0;

	int current_class = m_class.GetCurSel();
	int current_subject = m_subject.GetCurSel();

	vector<double> selected_score;

	for (int i = 0; i < Info.size(); i++)
	{
		if (Info[i].m_class_ == current_class + 1 || current_class == 3)
		{
			switch (current_subject)
			{
			case 0:
				selected_score.push_back(Info[i].m_score1);
				break;
			case 1:
				selected_score.push_back(Info[i].m_score2);
				break;
			case 2:
				selected_score.push_back(Info[i].m_score3);
				break;
			default:
				break;
			}
		}
	}

	for (int i = 0; i < selected_score.size(); i++)
	{
		sum += selected_score[i];
		max = max(max, selected_score[i]);
		min = min(min, selected_score[i]);
		if (selected_score[i] >= 60) pass++;
	}
	num = selected_score.size();

	m_av.Format(TEXT("%.2lf"), sum / num);
	m_pass.Format(TEXT("%.2lf"), pass * 1.0 / num);
	m_max = max;
	m_min = min;

	UpdateData(FALSE);
}

bool CStuInfoSystemDlg::cmp_by_class (StuInfo a, StuInfo b) {
	if(flag == false) return a.m_class_ < b.m_class_;
	else return a.m_class_ > b.m_class_;
}

bool CStuInfoSystemDlg::cmp_by_score1(StuInfo a, StuInfo b) {
	if (flag == false) return a.m_score1 < b.m_score1;
	else return a.m_score1 > b.m_score1;
}

bool CStuInfoSystemDlg::cmp_by_score2(StuInfo a, StuInfo b) {
	if (flag == false) return a.m_score2 < b.m_score2;
	else return a.m_score2 > b.m_score2;
}

bool CStuInfoSystemDlg::cmp_by_score3(StuInfo a, StuInfo b) {
	if (flag == false) return a.m_score3 < b.m_score3;
	else return a.m_score3 > b.m_score3;
}

void CStuInfoSystemDlg::OnCbnSelchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码
	int rule1 = m_rule1.GetCurSel();
	if (rule1 == 0) sort(Info.begin(), Info.end(), cmp_by_class);
	if (rule1 == 1) sort(Info.begin(), Info.end(), cmp_by_score1);
	if (rule1 == 2) sort(Info.begin(), Info.end(), cmp_by_score2);
	if (rule1 == 3) sort(Info.begin(), Info.end(), cmp_by_score3);
	UpdateList();
}


void CStuInfoSystemDlg::OnCbnSelchangeCombo4()
{
	// TODO: 在此添加控件通知处理程序代码
	int rule2 = m_rule2.GetCurSel();
	if (rule2 == 0) flag = false;	//升序
	else flag = true;	//倒序

	int rule1 = m_rule1.GetCurSel();
	if (rule1 == 0) sort(Info.begin(), Info.end(), cmp_by_class);
	if (rule1 == 1) sort(Info.begin(), Info.end(), cmp_by_score1);
	if (rule1 == 2) sort(Info.begin(), Info.end(), cmp_by_score2);
	if (rule1 == 3) sort(Info.begin(), Info.end(), cmp_by_score3);
	UpdateList();
}


void CStuInfoSystemDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT i;
	i = MessageBox(_T("确定要退出吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
	if (i == IDYES)
	{
		SQL.Close_MySQL();
		exit(0);
	}
}
