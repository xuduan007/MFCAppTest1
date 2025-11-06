// RandomDialog.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "RandomDialog.h"
#include "afxdialogex.h"
#include <cstdlib>
#include <ctime>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRandomDialog 对话框

CRandomDialog::CRandomDialog(CMFCApplication2Dlg* pMainDlg, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RANDOM_DIALOG, pParent)
	, m_strRandomNumber(_T(""))
	, m_pMainDlg(pMainDlg)
{
}

void CRandomDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RANDOM_NUMBER, m_strRandomNumber);
}

BEGIN_MESSAGE_MAP(CRandomDialog, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CRandomDialog::OnBnClickedClose)
END_MESSAGE_MAP()


// CRandomDialog 消息处理程序

BOOL CRandomDialog::OnInitDialog()
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
	SetIcon(m_hIcon, FALSE);			// 设置小图标

	// 生成随机5位数字
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int randomNumber = 10000 + std::rand() % 90000;
	m_strRandomNumber.Format(_T("%d"), randomNumber);
	UpdateData(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CRandomDialog::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRandomDialog::OnPaint()
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
HCURSOR CRandomDialog::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CRandomDialog::OnBnClickedClose()
{
	// TODO: 在此添加控件通知处理程序代码
	DestroyWindow();
}

void CRandomDialog::PostNcDestroy()
{
	CDialogEx::PostNcDestroy();
	if (m_pMainDlg != nullptr)
	{
		m_pMainDlg->SetRandomDialogPtrToNull();
	}
	delete this;
}