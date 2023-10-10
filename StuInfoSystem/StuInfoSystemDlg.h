
// StuInfoSystemDlg.h: 头文件
//

#include "SQLInterface.h"

#pragma once


// CStuInfoSystemDlg 对话框
class CStuInfoSystemDlg : public CDialogEx
{
// 构造
public:
	CStuInfoSystemDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUINFOSYSTEM_DIALOG };
#endif

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
	SQLInterface SQL;
	afx_msg void OnBnClickedButton1();
	vector<StuInfo> Info;
	CListCtrl m_list;
	afx_msg void OnBnClickedButton2();
	void UpdateList();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	CComboBox m_class;
	CComboBox m_subject;
//	double m_av;
	double m_max;
	double m_min;
//	double m_pass;
	afx_msg void OnBnClickedButton7();
	CString m_av;
	CString m_pass;
	CComboBox m_rule1;
	afx_msg void OnCbnSelchangeCombo3();
	CComboBox m_rule2;
	static bool flag;
	afx_msg void OnCbnSelchangeCombo4();

	static bool cmp_by_class(StuInfo a, StuInfo b);
	static bool cmp_by_score1(StuInfo a, StuInfo b);
	static bool cmp_by_score2(StuInfo a, StuInfo b);
	static bool cmp_by_score3(StuInfo a, StuInfo b);
	afx_msg void OnBnClickedButton6();
};
