#pragma once

#include "afxwin.h"

class CProcessDialog : public CDialogEx
{
    DECLARE_DYNAMIC(CProcessDialog)

public:
    CProcessDialog(CWnd* pParent = nullptr);   // 标准构造函数
    virtual ~CProcessDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_PROCESS_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

    DECLARE_MESSAGE_MAP()
public:
    CString m_strProcessList; // 进程列表字符串
    virtual BOOL OnInitDialog();
};