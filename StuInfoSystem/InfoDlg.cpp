// InfoDlg.cpp: 实现文件
//

#include "pch.h"
#include "StuInfoSystem.h"
#include "InfoDlg.h"
#include "afxdialogex.h"


// InfoDlg 对话框

IMPLEMENT_DYNAMIC(InfoDlg, CDialogEx)

InfoDlg::InfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_InfoDlg, pParent)
	, m_name(_T(""))
	, m_sex(_T(""))
	, m_class(1)
	, m_score1(60)
	, m_score2(60)
	, m_score3(60)
{

}

InfoDlg::~InfoDlg()
{
}

void InfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_sex);
	DDX_Text(pDX, IDC_EDIT3, m_class);
	DDX_Text(pDX, IDC_EDIT4, m_score1);
	DDX_Text(pDX, IDC_EDIT5, m_score2);
	DDX_Text(pDX, IDC_EDIT6, m_score3);
}


BEGIN_MESSAGE_MAP(InfoDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &InfoDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// InfoDlg 消息处理程序


void InfoDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	if (m_name == TEXT("") || m_sex == TEXT(""))
	{
		MessageBox(TEXT("您有输入为空！"), TEXT("提示"));
		return;
	}

	if (m_score1 < 0 || m_score1 > 100 || m_score2 < 0 || m_score2 > 100 || m_score3 < 0 || m_score3 > 100)
	{
		MessageBox(TEXT("您的成绩输入有误！"), TEXT("提示"));
		return;
	}

	CDialogEx::OnOK();
}
