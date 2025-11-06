// RandomDialog.h: 头文件
//

#pragma once


// 前向声明
class CMFCApplication2Dlg;

// CRandomDialog 对话框
class CRandomDialog : public CDialogEx
{
// 构造
public:
	CRandomDialog(CMFCApplication2Dlg* pMainDlg, CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RANDOM_DIALOG };
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
	afx_msg void OnBnClickedClose();
	CString m_strRandomNumber;
private:
	CMFCApplication2Dlg* m_pMainDlg;

protected:
	virtual void PostNcDestroy();
};