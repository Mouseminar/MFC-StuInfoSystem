// SeekDlg.cpp: 实现文件
//

#include "pch.h"
#include "StuInfoSystem.h"
#include "SeekDlg.h"
#include "afxdialogex.h"


// SeekDlg 对话框

IMPLEMENT_DYNAMIC(SeekDlg, CDialogEx)

SeekDlg::SeekDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SeekDlg, pParent)
	, m_name(_T(""))
{

}

SeekDlg::~SeekDlg()
{
}

void SeekDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
}


BEGIN_MESSAGE_MAP(SeekDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SeekDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SeekDlg 消息处理程序


void SeekDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	if (m_name == TEXT(""))
	{
		MessageBox(TEXT("您的输入为空！"), TEXT("提示"));
		return;
	}

	CDialogEx::OnOK();
}
