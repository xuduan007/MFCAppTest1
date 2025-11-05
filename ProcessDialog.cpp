#include "pch.h"
#include "ProcessDialog.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(CProcessDialog, CDialogEx)

CProcessDialog::CProcessDialog(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_PROCESS_DIALOG, pParent)
    , m_strProcessList(_T(""))
{}

CProcessDialog::~CProcessDialog()
{}

void CProcessDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_STATIC_PROCESS, m_strProcessList);
}

BEGIN_MESSAGE_MAP(CProcessDialog, CDialogEx)
END_MESSAGE_MAP()

BOOL CProcessDialog::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // 设置静态文本控件的内容为进程列表
    CWnd* pStatic = GetDlgItem(IDC_STATIC_PROCESS);
    if (pStatic != nullptr)
    {
        pStatic->SetWindowText(m_strProcessList);
    }

    return TRUE;  // return TRUE unless you set the focus to a control
                  // 异常: OCX 属性页应返回 FALSE
}