#pragma once


// SeekDlg 对话框

class SeekDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SeekDlg)

public:
	SeekDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SeekDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SeekDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	afx_msg void OnBnClickedOk();
};
