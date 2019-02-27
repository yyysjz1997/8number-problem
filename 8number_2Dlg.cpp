
// 8number_2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "8number_2.h"
#include "8number_2Dlg.h"
#include "afxdialogex.h"
#include <string>
#include <afxtempl.h>

//����һ����Ƚ���--���������������
#define MaxDepth (5)
//����һ����������
#define MaxStep (200)



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//using namespace std;

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnXButtonDown(UINT nFlags, UINT nButton, CPoint point);
	afx_msg void OnXButtonDblClk(UINT nFlags, UINT nButton, CPoint point);
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
	afx_msg void OnVScrollClipboard(CWnd* pClipAppWnd, UINT nSBCode, UINT nPos);
	afx_msg int OnVKeyToItem(UINT nKey, CListBox* pListBox, UINT nIndex);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnUserChanged();
	afx_msg void OnUnInitMenuPopup(CMenu *pPopupMenu, UINT nFlags);
	afx_msg void OnUpdateUIState(UINT /*nAction*/, UINT /*nUIElement*/);
	afx_msg void OnUniChar(UINT Char, UINT nRepCnt, UINT nFlags);
	afx_msg void OnWinIniChange(LPCTSTR lpszSection);
	afx_msg void OnSessionChange(UINT nSessionState, UINT nId);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_XBUTTONDOWN()
	ON_WM_XBUTTONDBLCLK()
	ON_WM_WINDOWPOSCHANGED()
	ON_WM_WINDOWPOSCHANGING()
	ON_WM_VSCROLLCLIPBOARD()
	ON_WM_VKEYTOITEM()
	ON_WM_VSCROLL()
	ON_WM_USERCHANGED()
	ON_WM_UNINITMENUPOPUP()
	ON_WM_UPDATEUISTATE()
	ON_WM_UNICHAR()
	ON_WM_WININICHANGE()
	ON_WM_WTSSESSION_CHANGE()
END_MESSAGE_MAP()


// CMy8number_2Dlg dialog



CMy8number_2Dlg::CMy8number_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy8number_2Dlg::IDD, pParent)

	, msg_output(_T(""))

	, final_data11(_T("1"))
	, final_data12(_T("2"))
	, final_data13(_T("3"))
	, final_data21(_T("8"))
	, final_data22(_T(""))
	, final_data23(_T("4"))
	, final_data31(_T("7"))
	, final_data32(_T("6"))
	, final_data33(_T("5"))
	, init_data11(_T("1"))
	, init_data12(_T("2"))
	, init_data13(_T("3"))
	, init_data21(_T("8"))
	, init_data22(_T(""))
	, init_data23(_T("4"))
	, init_data31(_T("7"))
	, init_data32(_T("6"))
	, init_data33(_T("5"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy8number_2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_OUTPUT, msg_output);

	DDX_Text(pDX, IDC_EDIT_FINAL_11, final_data11);
	DDX_Text(pDX, IDC_EDIT_FINAL_12, final_data12);
	DDX_Text(pDX, IDC_EDIT_FINAL_13, final_data13);
	DDX_Text(pDX, IDC_EDIT_FINAL_21, final_data21);
	DDX_Text(pDX, IDC_EDIT_FINAL_22, final_data22);
	DDX_Text(pDX, IDC_EDIT_FINAL_23, final_data23);
	DDX_Text(pDX, IDC_EDIT_FINAL_31, final_data31);
	DDX_Text(pDX, IDC_EDIT_FINAL_32, final_data32);
	DDX_Text(pDX, IDC_EDIT_FINAL_33, final_data33);
	DDX_Text(pDX, IDC_EDIT_INIT_11, init_data11);
	DDX_Text(pDX, IDC_EDIT_INIT_12, init_data12);
	DDX_Text(pDX, IDC_EDIT_INIT_13, init_data13);
	DDX_Text(pDX, IDC_EDIT_INIT_21, init_data21);
	DDX_Text(pDX, IDC_EDIT_INIT_22, init_data22);
	DDX_Text(pDX, IDC_EDIT_INIT_23, init_data23);
	DDX_Text(pDX, IDC_EDIT_INIT_31, init_data31);
	DDX_Text(pDX, IDC_EDIT_INIT_32, init_data32);
	DDX_Text(pDX, IDC_EDIT_INIT_33, init_data33);
}

BEGIN_MESSAGE_MAP(CMy8number_2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy8number_2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy8number_2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy8number_2Dlg::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT_INIT_11, &CMy8number_2Dlg::OnEnChangeEditInit11)
	ON_BN_CLICKED(IDC_Quit, &CMy8number_2Dlg::OnBnClickedQuit)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BFS,IDC_DFS_Search, OnBnClickedChoose)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_8Number, IDC_OneWord, OnBnClickedEightOneChoose)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_ShowSP, IDC_ShowAll, OnBnClickedNodeShowChoose)
	ON_WM_SIZE()
	//OnBnClickedEightOneChoose(UINT nID);
	//ON_BN_CLICKED(IDC_RADIO1, &CMy8number_2Dlg::OnBnClickedRadio1)
	//ON_COMMAND(IDC_DFS_Search, &CMy8number_2Dlg::OnDfsSearch)
	ON_BN_CLICKED(IDC_OneWord, &CMy8number_2Dlg::OnBnClickedOneword)
	ON_EN_CHANGE(IDC_EDIT_FINAL_11, &CMy8number_2Dlg::OnEnChangeEditFinal11)
	ON_EN_CHANGE(IDC_EDIT_OUTPUT, &CMy8number_2Dlg::OnEnChangeEditOutput)
END_MESSAGE_MAP()


// CMy8number_2Dlg message handlers

BOOL CMy8number_2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//�ڳ�ʼ�Ի����ʱ��Ͷ�Ŀ��̬��ֵ
	//�Գ�ʼֵ̬��Ŀ��̬����ֵ
	UpdateData(1);
	init_data11 = "1";
	init_data12 = "2";
	init_data13 = "3";
	init_data21 = "8";
	init_data22 = "";
	init_data23 = "4";
	init_data31 = "7";
	init_data32 = "6";
	init_data33 = "5";

	final_data11 = "1";
	final_data12 = "2";
	final_data13 = "3";
	final_data21 = "8";
	final_data22 = "";
	final_data23 = "4";
	final_data31 = "7";
	final_data32 = "6";
	final_data33 = "5";

	UpdateData(0);

	//CRect rect;
	GetClientRect(&m_rect);					//ȡ�ͻ�����С    
	m_old.x = m_rect.right - m_rect.left;
	m_old.y = m_rect.bottom - m_rect.top;

	//GetClientRect(&m_rect);  

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy8number_2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy8number_2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy8number_2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//Ϊ�򵥼ƣ�����ʹ���˼���ȫ�ֱ���
//8���뻹��һ�����ģʽѡ��->0--8����
int EightOneChoose = 0;
//������ʽѡ���ȫ�ֱ���
int ModeChoose = 0;
//��¼����������ȫ�ֱ���
int SearchTimes = 0;
//��¼�ڵ���ʾ��ʽ��ѡ��
int NodeShowMode = 0;


void CMy8number_2Dlg::OnBnClickedChoose(UINT nID)
{
	switch (nID - IDC_BFS)
	{
		case 0:
			ModeChoose = 1;
			break;
		case 1:
			ModeChoose = 2;
			break;
		case 2:
			ModeChoose = 3;
			break;
		case 3:
			ModeChoose = 4;
			break;
		case 4:
			ModeChoose = 5;
			break;
		case 5:
			ModeChoose = 6;
			break;
		case 6:
			ModeChoose = 7;
		default:
			break;
	}
}


/*
**@brief ѡ����8�������� EightOneChoose=0,������
*/

void CMy8number_2Dlg::OnBnClickedEightOneChoose(UINT nID)
{

	switch (nID - IDC_8Number)
	{
		case 0:
			EightOneChoose = 0;
			UpdateData(1);
			init_data11 = "1";
			init_data12 = "2";
			init_data13 = "3";
			init_data21 = "8";
			init_data22 = "";
			init_data23 = "4";
			init_data31 = "7";
			init_data32 = "6";
			init_data33 = "5";
			final_data11 = "1";
			final_data12 = "2";
			final_data13 = "3";
			final_data21 = "8";
			final_data22 = "";
			final_data23 = "4";
			final_data31 = "7";
			final_data32 = "6";
			final_data33 = "5";
			msg_output.Empty();
			UpdateData(0);
			break;
		default:
			break;
	}
}
/*
**@brief �ڵ���ʾ��ʽѡ��
*/
void CMy8number_2Dlg::OnBnClickedNodeShowChoose( UINT nID )
{
	switch (nID - IDC_ShowSP)
	{
		case 0:
			NodeShowMode = 0;
			break;
		case 1:
			NodeShowMode = 1;
			break;
		default:
			NodeShowMode = 0;
			break;
	}
}
/*
**@brief �ڳ�ʼ״̬���Ŀ��״̬������ʾ��Ӧ���ַ���
*/
void CMy8number_2Dlg::InitFinalTextBlockShow(char init_data[3][3], char final_data[3][3])
{
	init_data11 = init_data[0][0];
	init_data12 = init_data[0][1];
	init_data13 = init_data[0][2];
	init_data21 = init_data[1][0];
	init_data22 = init_data[1][1];
	init_data23 = init_data[1][2];
	init_data31 = init_data[2][0];
	init_data32 = init_data[2][1];
	init_data33 = init_data[2][2];
	final_data11 = final_data[0][0];
	final_data12 = final_data[0][1];
	final_data13 = final_data[0][2];
	final_data21 = final_data[1][0];
	final_data22 = final_data[1][1];
	final_data23 = final_data[1][2];
	final_data31 = final_data[2][0];
	final_data32 = final_data[2][1];
	final_data33 = final_data[2][2];
	UpdateData(0);
	return;
}




//stack<Node> s_ans;//ȫ�ֱ���
/*
**@brief	����ʼ��⡱��ť
*/
void CMy8number_2Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	char init_data[3][3];
	char final_data[3][3];
	//Node node_temp;
	char CheckRes = 0;
	char Solvable = 0;


	if (EightOneChoose == 0)
	{
		//���
		CheckRes = InputCheck(init_data, final_data);
		if (CheckRes == 0)
			return;
		Solvable = JudgeSolvable(init_data, final_data);
		if (Solvable == 0)
			return;
		switch (ModeChoose)
		{
			case 1:
				msg_output += "���ۺ���=λ�ò���������Ŀ \r\n";
				UpdateData(0);
				INFO_Search(init_data, final_data);
				break;
			case 2:
				msg_output += "���ۺ���=�����Ƶ�Ŀ��λ�þ����ܺ� \r\n";
				UpdateData(0);
				INFO_Search(init_data, final_data);
				break;
			case 3:
				msg_output += "���ۺ���=��ת������Ŀ \r\n";
				INFO_Search(init_data, final_data);
				UpdateData(0);
				break;
			case 4:
				msg_output += "���ۺ���=λ�ò���������Ŀ+��ת������Ŀ*3\r\n";
				INFO_Search(init_data, final_data);
				UpdateData(0);
				break;
			case 5:
				msg_output += "�Զ������� \r\n";
				msg_output += "���ۺ���=�����Ƶ�Ŀ��λ�þ����ܺ�+�������*3\r\n";
				INFO_Search(init_data, final_data);
				UpdateData(0);
				break;
			case 6:
				msg_output += "����������� \r\n";
				BFS_Search(init_data, final_data);
				UpdateData(0);
				break;
			case 7:
				msg_output += "A*�㷨 \r\n";
				Astar_Search(init_data, final_data);
				UpdateData(0);
				break;
			default:
				msg_output += "����������� \r\n";
				INFO_Search(init_data, final_data);
				UpdateData(0);
				break;

		}
	}
}




/*
**@brief	���������飬��ȷ����1�����󷵻�0
*/
bool CMy8number_2Dlg::InputCheck(char init_data[3][3], char final_data[3][3])
{
	//char init_data[3][3];
	//char final_data[3][3];
	char current_data[3][4];
	char flag[9] = { 0 }, i = 0, j = 0, k = 0;
	char InputWrong = 0;

	UpdateData(1);
	//�������Ƿ�Ϸ�
	//����Ƿ��в��Ϸ��ַ�
	if (init_data11.GetLength() > 1 || init_data12.GetLength() > 1 || init_data13.GetLength() > 1
		|| init_data21.GetLength() > 1 || init_data22.GetLength() > 1 || init_data23.GetLength() > 1
		|| init_data31.GetLength() > 1 || init_data32.GetLength() > 1 || init_data33.GetLength() > 1)
	{
		OutputWrongMsg( );
		return(0);
	}
	if (final_data11.GetLength() > 1 || final_data12.GetLength() > 1 || final_data13.GetLength() > 1
		|| final_data21.GetLength() > 1 || final_data22.GetLength() > 1 || final_data23.GetLength() > 1
		|| final_data31.GetLength() > 1 || final_data32.GetLength() > 1 || final_data33.GetLength() > 1)
	{
		OutputWrongMsg();
		return(0);
	}
	//��ʼ״̬��ֵ
	//11��״̬�ж�
	if (init_data11.IsEmpty())
	{
		init_data[0][0] = 0;
	}
	else
	{
		if (init_data11[0]<'1' || init_data11[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			init_data[0][0] = init_data11[0] - '0';
		}
	}
	//12��״̬�ж�
	if (init_data12.IsEmpty())
	{
		init_data[0][1] = 0;
	}
	else
	{
		if (init_data12[0]<'1' || init_data12[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			init_data[0][1] = init_data12[0] - '0';
		}
	}
	//13��״̬�ж�
	if (init_data13.IsEmpty())
	{
		init_data[0][2] = 0;
	}
	else
	{
		if (init_data13[0]<'1' || init_data13[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			init_data[0][2] = init_data13[0] - '0';
		}
	}
	//21��
	if (init_data21.IsEmpty())
	{
		init_data[1][0] = 0;
	}
	else
	{
		if (init_data21[0]<'1' || init_data21[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			init_data[1][0] = init_data21[0] - '0';
		}
	}
	//22��
	if (init_data22.IsEmpty())
	{
		init_data[1][1] = 0;
	}
	else
	{
		if (init_data22[0]<'1' || init_data22[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			init_data[1][1] = init_data22[0] - '0';
		}
	}
	//23��
	if (init_data23.IsEmpty())
	{
		init_data[1][2] = 0;
	}
	else
	{
		if (init_data23[0]<'1' || init_data23[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			init_data[1][2] = init_data23[0] - '0';
		}
	}
	//31��
	if (init_data31.IsEmpty())
	{
		init_data[2][0] = 0;
	}
	else
	{
		if (init_data31[0]<'1' || init_data31[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			init_data[2][0] = init_data31[0] - '0';
		}
	}
	//32��
	if (init_data32.IsEmpty())
	{
		init_data[2][1] = 0;
	}
	else
	{
		if (init_data32[0]<'1' || init_data32[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			init_data[2][1] = init_data32[0] - '0';
		}
	}
	//33��
	if (init_data33.IsEmpty())
	{
		init_data[2][2] = 0;
	}
	else
	{
		if (init_data33[0]<'1' || init_data33[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			init_data[2][2] = init_data33[0] - '0';
		}
	}
	//Ŀ��״̬
	//Ŀ��״̬��ֵ
	if (final_data11.IsEmpty())
	{
		final_data[0][0] = 0;
	}
	else
	{
		if (final_data11[0]<'1' || final_data11[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			final_data[0][0] = final_data11[0] - '0';
		}
	}
	//12��
	if (final_data12.IsEmpty())
	{
		final_data[0][1] = 0;
	}
	else
	{
		if (final_data12[0]<'1' || final_data12[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			final_data[0][1] = final_data12[0] - '0';
		}
	}
	//13��
	if (final_data13.IsEmpty())
	{
		final_data[0][2] = 0;
	}
	else
	{
		if (final_data13[0]<'1' || final_data13[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			final_data[0][2] = final_data13[0] - '0';
		}
	}
	//21��
	if (final_data21.IsEmpty())
	{
		final_data[1][0] = 0;
	}
	else
	{
		if (final_data21[0]<'1' || final_data21[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			final_data[1][0] = final_data21[0] - '0';
		}
	}
	//22��
	if (final_data22.IsEmpty())
	{
		final_data[1][1] = 0;
	}
	else
	{
		if (final_data22[0]<'1' || final_data22[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			final_data[1][1] = final_data22[0] - '0';
		}
	}
	//23��
	if (final_data23.IsEmpty())
	{
		final_data[1][2] = 0;
	}
	else
	{
		if (final_data23[0]<'1' || final_data23[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			final_data[1][2] = final_data23[0] - '0';
		}
	}
	//31��
	if (final_data31.IsEmpty())
	{
		final_data[2][0] = 0;
	}
	else
	{
		if (final_data31[0]<'1' || final_data31[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			final_data[2][0] = final_data31[0] - '0';
		}
	}
	//32��
	if (final_data32.IsEmpty())
	{
		final_data[2][1] = 0;
	}
	else
	{
		if (final_data32[0]<'1' || final_data32[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			final_data[2][1] = final_data32[0] - '0';
		}
	}
	//33��
	if (final_data33.IsEmpty())
	{
		final_data[2][2] = 0;
	}
	else
	{
		if (final_data33[0]<'1' || final_data33[0]>'8')
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			final_data[2][2] = final_data33[0] - '0';
		}
	}
	//��������Ƿ���1~8,��һ���ո�
	//��ʼ���ݼ��
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			flag[init_data[i][j]] = 1;
		}
	}
	for (i = 0; i < 9; i++)
	{
		if (!flag[i])
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			flag[i] = 0;//���㣬Ϊ������Ŀ��״̬������׼��
		}
	}
	//Ŀ�����ݼ��
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			flag[final_data[i][j]] = 1;
		}
	}
	for (i = 0; i < 9; i++)
	{
		if (!flag[i])
		{
			OutputWrongMsg();
			return(0);
		}
		else
		{
			flag[i] = 0;//���㣬Ϊ������Ŀ��״̬������׼��
		}
	}
	return(1);

}


/*
**@brief ���������ʾ
*/
void CMy8number_2Dlg::OutputWrongMsg(void)
{
	MessageBox(_T("������Ϸ���Ŀ��״̬"));
	//UpdateData(1);
	msg_output += "����Ŀ��״̬�Ƿ� \r\n";
	UpdateData(0);
	return;

}

/*
**@brief �жϳ�ʼ״̬��״̬��Ŀ��״̬���Ƿ�ɽ⡣�ɽⷵ��1�����ɽⷵ��0��
*/
bool CMy8number_2Dlg::JudgeSolvable(char init_data[3][3], char final_data[3][3])
{
	char i = 0, j = 0;
	char InitOddEven = 0, FinalOddEven = 0;
	char InitData[9] = { 0 };
	char FinalData[9] = { 0 };

	//�����жϵ�ǰ8���������Ƿ��н�
	//��תΪ1ά����
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			InitData[i * 3 + j] = init_data[i][j];
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			FinalData[i * 3 + j] = final_data[i][j];
		}
	}
	//������Ե�������
	for (i = 0; i < 9; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			if ((InitData[i] != 0) && (InitData[j] != 0))
			{
				if (InitData[i]>InitData[j])
				{
					InitOddEven++;
				}
			}
			else
			{
			}
		}
	}
	for (i = 0; i < 9; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			if ((FinalData[i] != 0) && (FinalData[j] != 0))
			{
				if (FinalData[i]>FinalData[j])
				{
					FinalOddEven++;
				}
			}
			else
			{
			}
		}
	}
	//�ж��Ƿ��н�
	if ((InitOddEven % 2) != (FinalOddEven % 2))
	{
		OutputWrongMsg( );
		msg_output += "��ʼ״̬��Ŀ��״̬��������ͬ \r\n";
		UpdateData(0);
		return(0);
	}
	else
		return(1);
}


/*
**@brief �жϵ�ǰ��չ�Ľڵ��Ƿ���֮ǰ�Ľڵ��ظ����ظ�����1�����ظ�����0��
*/
bool CMy8number_2Dlg::NodeRepeat(Node NodeTemp, CList<Node, Node&>&ClosedList, POSITION &RepeatX)
{
	int ListNum;
	int i = 0;
	POSITION x = 0;
	RepeatX = x;
	Node NodeBefore;
	ListNum = ClosedList.GetCount();					//������������Ŀ
	for (i = 0; i < ListNum; i++)
	{
		x = ClosedList.FindIndex(i);					//POSITION�࣬��λ
		
		NodeBefore = ClosedList.GetAt(x);
		if (NodeTemp == NodeBefore)
		{
			RepeatX = x;
			return(1);
		}
	}
	return(0);
}

/*
**@brief ����н�Ļ�,��ʾ����·��,
**
**@note  ����CLOSED��Ĭ�ϱ�β�ڵ���Ŀ��ڵ㣬�����������ڵ�		
*/
void CMy8number_2Dlg::ResultOutput(CList<Node, Node&>&ClosedList)
{
	CList<Node, Node&>ResultList;
	Node NodeTemp;
	Node NodeFather;
	int FatherNodeNum = 0;
	int i = 0, j = 0, k = 0;
	int ResNum;
	char ExitFlag = 1;
	//����Ŀ��ڵ�
	NodeTemp = ClosedList.RemoveTail();
	ResultList.AddHead(NodeTemp);
	if (NodeShowMode == 0)
	{
		if (ClosedList.IsEmpty() == 0)
			NodeFather = ClosedList.RemoveTail();
		else
			ExitFlag = 0;
	}
	if (NodeShowMode == 1)
	{
		if (ClosedList.IsEmpty() == 1)
			ExitFlag = 0;
	}

	//��Ѱ·��
	///*
	while (ExitFlag)
	{
		if (NodeShowMode == 0)											//��ʾ���·��
		{

			if (NodeFather.m_NodeNum == NodeTemp.m_FatherNodeNum)		//���Ϊ���ڵ�
			{
				ResultList.AddHead(NodeFather);
				NodeTemp = NodeFather;
				if (ClosedList.IsEmpty() == 0)
					NodeFather = ClosedList.RemoveTail();				//����������Ѱ
			}
			else
			{
				if (ClosedList.IsEmpty() == 0)
					NodeFather = ClosedList.RemoveTail();				//����������Ѱ
			}
			if (ClosedList.IsEmpty() == 1)
			{
				ResultList.AddHead(NodeFather);
				ExitFlag = 0;
			}
		}
		else if (NodeShowMode == 1)
		{
			if (ClosedList.IsEmpty() == 0)
			{
				NodeTemp = ClosedList.RemoveTail();
				ResultList.AddHead(NodeTemp);
			}
			if (ClosedList.IsEmpty() == 1)
			{
				//ResultList.AddHead(NodeFather);
				ExitFlag = 0;
			}
		}
		else
			ExitFlag = 0;

	}
	//
	msg_output += "���ɹ�\r\n";
	msg_output.Format(msg_output + "�ܹ�������%d��\r\n", SearchTimes);
	if (NodeShowMode == 0)
		msg_output += "���·����ʾ����\r\n";
	else if (NodeShowMode == 1)
		msg_output += "ȫ���ڵ���ʾ����\r\n";
	else
		;
	//�ҵ�·��֮����ʾ
	//ExitFlag = 1;
	ResNum = ResultList.GetCount();

	for (i = 0; i < ResNum; i++)
	{
		if (ResultList.IsEmpty() ==0 )
			NodeTemp = ResultList.RemoveHead();

		msg_output.Format(msg_output+"��%d��\r\n", i);
		msg_output.Format(msg_output + "����%d,", NodeTemp.m_Depth);
		msg_output.Format(msg_output + "�ڵ���%d,", NodeTemp.m_NodeNum);
		msg_output.Format(msg_output + "���ڵ���%d\r\n", NodeTemp.m_FatherNodeNum);
		msg_output.Format(msg_output + "���ۺ���ֵ=%d\r\n", NodeTemp.m_evaluation);
		for (j = 0; j < 3; j++)
		{
			msg_output += "\r\n";
			msg_output += "       ";
			for (k = 0; k < 3; k++)
			{
				msg_output.Insert(msg_output.GetLength() - 1, '0' + NodeTemp.m_data[j][k]);
				msg_output += "       ";
			}
			msg_output += "\r\n";
		}
		msg_output += "\r\n";
	}
	//*/
	msg_output += "\r\n";
	UpdateData(0);
	ResultList.RemoveAll();
	return;
}


/*
**@brief ������������㷨
*/
bool CMy8number_2Dlg::BFS_Search(char init_data[3][3], char final_data[3][3])
{
	CList<Node,Node&>OpenList;
	CList<Node,Node&>ClosedList;
	POSITION RepeatX = 0;
	int i = 0, j = 0;
	char ExitFlag = 1;
	char Solvable = 0;
	int NodeID = 1;
	//��ʼ�����ڵ��Ŀ��ڵ�
	Node FinalNode(final_data), CurrentNode(init_data), FatherNode, SonNode;
	Node NodeTemp;
	CurrentNode.m_FatherNodeNum = 0;
	CurrentNode.m_Depth = 1;
	CurrentNode.m_NodeNum = NodeID;				//���ID
	NodeID++;									//ID����Լ�
	SearchTimes = 0;

	OpenList.AddHead(CurrentNode);				//�����ڵ�ѹ��OPEN��
	//�����������
	while ( ExitFlag )
	{
		if (OpenList.IsEmpty() == 1)			//OPEN��Ϊ��
		{
			ExitFlag = 0;
			Solvable = 1;
		}
		else
			NodeTemp = OpenList.RemoveHead();	//ɾ��OPEN���ͷ���	

		if (NodeTemp == FinalNode)				//ΪĿ��ڵ����Ŀ��ڵ�ѹ��CLOSED��ĩβ���˳�
		{
			ExitFlag = 0;
			Solvable = 1;
			ClosedList.AddTail(NodeTemp);		//����չ�Ľڵ�ѹ��OPEN����
		}
		else                                    
		{
			SearchTimes++;
			ClosedList.AddTail(NodeTemp);		//��ΪĿ��ڵ㣬���˽ڵ�ѹ��CLOSED��β��������չ
			for (i = 0; i < 4; i++)				//�ķ�����չ
			{
				SonNode = NodeTemp;				//ע������ԭ���ڵ���ֱ�Ӹı�
				//����չ���Ҳ���CLOSED���нڵ��ظ�
				if( SonNode.CreateNewNode(i) == 1 )
				{
					if (NodeRepeat(SonNode, ClosedList, RepeatX) == 0)
					{
						SonNode.m_NodeNum = NodeID;					//��ż�1
						NodeID++;
						SonNode.m_FatherNodeNum = NodeTemp.m_NodeNum;
						SonNode.m_Depth = NodeTemp.m_Depth + 1;
						SonNode.m_evaluation = SonNode.m_Depth;
						OpenList.AddTail(SonNode);					//ѹ��OPEN��
					}
				}				
			}
			if (NodeTemp.m_NodeNum > MaxStep)
			{
				ExitFlag = 0;
				Solvable = 0;
			}
		}
	}
	
	
	//�н�����ʾ���
	if (Solvable == 1)
	{
		ResultOutput(ClosedList);
		OpenList.RemoveAll();
		ClosedList.RemoveAll();
		return(1);
	}
	else
	{
		msg_output += "���ʧ�ܣ��������޽�\r\n";
		OpenList.RemoveAll();
		ClosedList.RemoveAll();
		return(0);
	}
}

/*
**@brief ������������㷨
*/
bool CMy8number_2Dlg::DFS_Search(char init_data[3][3], char final_data[3][3])
{
	CList<Node, Node&>OpenList;
	CList<Node, Node&>ClosedList;
	POSITION RepeatX = 0;
	int i = 0, j = 0;
	char ExitFlag = 1;
	char Solvable = 0;
	int NodeID = 1;
	int DepthID = 0;
	char Extensible = 0;
	//��ʼ�����ڵ��Ŀ��ڵ�
	Node FinalNode(final_data), CurrentNode(init_data), FatherNode, SonNode;
	Node NodeTemp;
	CurrentNode.m_FatherNodeNum = 0;
	CurrentNode.m_Depth = DepthID;
	CurrentNode.m_NodeNum = NodeID;					//���ID
	NodeID++;										//ID����Լ�
	SearchTimes = 0;
	//
	OpenList.AddHead(CurrentNode);					//�����ڵ�ѹ��OPEN��
	//�����������
	while (ExitFlag)
	{
		Extensible = 0;
		if (OpenList.IsEmpty() == 1)				//OPEN��Ϊ��
		{
			ExitFlag = 0;
			Solvable = 0;
		}
		else
			NodeTemp = OpenList.RemoveHead();		//ɾ��OPEN���ͷ���	


		if (NodeTemp == FinalNode)					//ΪĿ��ڵ����Ŀ��ڵ�ѹ��CLOSED��ĩβ���˳�
		{
			ExitFlag = 0;
			Solvable = 1;
			ClosedList.AddTail(NodeTemp);			
		}
		else
		{
			SearchTimes++;
			if (NodeTemp.m_Depth > MaxDepth)		//��Ƚ����ж�
			{	
				OpenList.AddHead(CurrentNode);		//��OPEN��ͷ������Ϊ���ڵ㣬���±���
			}
			else
			{
				if (NodeRepeat(NodeTemp, ClosedList, RepeatX) == 0)			//��һ���ظ��ж�
					ClosedList.AddTail(NodeTemp);	

				for (i = 0; i < 4; i++)										//�ķ�����չ
				{
					SonNode = NodeTemp;										//ע������ԭ���ڵ���ֱ�Ӹı�
					if (SonNode.CreateNewNode(i) == 1)
					{
						if (NodeRepeat(SonNode, ClosedList, RepeatX) == 0)
						{
							SonNode.m_NodeNum = NodeID;
							NodeID++;
							SonNode.m_FatherNodeNum = NodeTemp.m_NodeNum;	//��չ�ڵ�༭
							OpenList.AddHead(SonNode);						//ѹ��OPEN��ͷ
							Extensible = 1;
						}													
					}
				}
			}
			//
			if (NodeTemp.m_NodeNum > MaxStep)
			{
				ExitFlag = 0;
				Solvable = 0;
			}
		}
	}
	//�н�����ʾ���
	if ( Solvable == 1 )
	{
		ResultOutput(ClosedList);
		OpenList.RemoveAll();
		ClosedList.RemoveAll();
		return(1);
	}
	else
	{
		msg_output += "���ʧ�ܣ��������޽�\r\n";
		OpenList.RemoveAll();
		ClosedList.RemoveAll();
		return(0);
	}

}

/*
**@brief	�������е����ݽ������򣬹��ۺ�������ǰ��ã������ۺ�����С�Ľڵ���ڱ�ͷ������������
**	
**@note		�����ж�����������������������,����ð������ķ���	
*/
void CMy8number_2Dlg::SortListByEva( CList<Node, Node&>&OpenList )
{
	int i = 0, j = 0, k = 0;
	int NodeNum = 0;
	POSITION x,y;
	//Node NodeMinEva;
	Node NodeTemp;
	Node NodeNext;
	//Ϊ���˳�
	if (OpenList.IsEmpty() == 1)
		return;
	NodeNum = OpenList.GetCount();
	//ð������
	for (i = 0; i < NodeNum; i++ )
	{
		for (j = 0; j < NodeNum - 1; j++)
		{
			x = OpenList.FindIndex(j);
			NodeTemp = OpenList.GetAt(x);
			y = OpenList.FindIndex(j + 1);
			NodeNext = OpenList.GetAt(y);
			if ( NodeTemp.m_evaluation > NodeNext.m_evaluation )
			{
				OpenList.SetAt(y, NodeTemp);
				OpenList.SetAt(x, NodeNext);
			}
		}
	}
	return;
}



/*
**@brief ����ʽ����--���ֹ��ۺ���
*/
bool CMy8number_2Dlg::INFO_Search(char init_data[3][3], char final_data[3][3])
{
	CList<Node, Node&>OpenList;
	CList<Node, Node&>ClosedList;
	POSITION RepeatX = 0;
	int i = 0, j = 0;
	char ExitFlag = 1;
	char Solvable = 0;
	int NodeID = 1;
	int DepthID = 0;
	char Extensible = 0;
	//��ʼ�����ڵ��Ŀ��ڵ�
	Node FinalNode(final_data), CurrentNode(init_data), FatherNode, SonNode;
	Node NodeTemp;
	CurrentNode.m_FatherNodeNum = 0;
	CurrentNode.m_Depth = DepthID;
	CurrentNode.m_NodeNum = NodeID;					//���ID
	CurrentNode.m_evaluation = GetEvaTemp(CurrentNode, FinalNode);
	NodeID++;										//ID����Լ�
	SearchTimes = 0;
	//
	OpenList.AddHead(CurrentNode);					//�����ڵ�ѹ��OPEN��
	//��������
	while ( ExitFlag )
	{
		
		if (OpenList.IsEmpty() == 1)				//OPEN��Ϊ��
		{
			ExitFlag = 0;
			Solvable = 0;
		}
		else
			NodeTemp = OpenList.RemoveHead();		//ɾ��OPEN���ͷ���	

		SearchTimes++;
		if (NodeTemp == FinalNode)					//ΪĿ��ڵ����Ŀ��ڵ�ѹ��CLOSED��ĩβ���˳�
		{
			ExitFlag = 0;
			Solvable = 1;
			ClosedList.AddTail(NodeTemp);
		}
		else
		{
			
			ClosedList.AddTail(NodeTemp);								//���ڵ�ѹ��CLOSED��

			for (i = 0; i < 4; i++)										//�ķ�����չ
			{
				SonNode = NodeTemp;										//ע������ԭ���ڵ���ֱ�Ӹı�
				if (SonNode.CreateNewNode(i) == 1)
				{
					if (NodeRepeat(SonNode, ClosedList, RepeatX) == 0)
					{

						SonNode.m_NodeNum = NodeID;						//��չ�ڵ�༭
						NodeID++;
						SonNode.m_FatherNodeNum = NodeTemp.m_NodeNum;	
						SonNode.m_Depth = NodeTemp.m_Depth + 1;
						SonNode.m_evaluation=GetEvaTemp(SonNode, FinalNode);
						OpenList.AddTail(SonNode);						//ѹ��OPEN��β
						Extensible = 1;
					}
				}
			}
			//if (Extensible == 1)										//����չ�½ڵ㣬�ض�OPEN������
			//{
				SortListByEva(OpenList);
			//	Extensible = 0;
			//}
		}
		//������������
		if (NodeTemp.m_NodeNum > MaxStep)
		{
			ExitFlag = 0;
			Solvable = 0;
		}
	}
	//�н�����ʾ���
	if (Solvable == 1)
	{
		ResultOutput(ClosedList);
		OpenList.RemoveAll();
		ClosedList.RemoveAll();
		return(1);
	}
	else
	{
		msg_output += "���ʧ�ܣ��������޽�\r\n";
		OpenList.RemoveAll();
		ClosedList.RemoveAll();
		return(0);
	}

}



/*
**@brief	����ѡ�����������ۺ���
*/
int CMy8number_2Dlg::GetEvaTemp(Node NodeTemp,Node NodeFinal)
{
	int eva = 0;
	//����ۺ���
	switch (ModeChoose)
	{
	case 1:
		eva=NodeTemp.GetevaluationM0(NodeFinal);
		break;
	case 2:
		eva=NodeTemp.GetevaluationM1(NodeFinal);			//����ۺ���
		break;
	case 3:
		eva = NodeTemp.GetevaluationM2();
		break;
	case 4:
		eva = NodeTemp.GetevaluationM3(NodeFinal);
		break;
	case 5:
		eva = NodeTemp.GetevaluationM4(NodeFinal);
		break;
	default:												//�޼�����ۺ���ֵ����Ϊ�������
		break;

	}
	return(eva);
}



/*
**@brief A*�㷨
*/
bool CMy8number_2Dlg::Astar_Search(char init_data[3][3], char final_data[3][3])
{
	CList<Node, Node&>OpenList;
	CList<Node, Node&>ClosedList;
	static POSITION Repeatx = 0;
	Node RepeatNode;
	int i = 0, j = 0;
	char ExitFlag = 1;
	char Solvable = 0;
	int NodeID = 1;
	int DepthID = 0;
	char Extensible = 0;
	int RepeatFlag = 0;
	//��ʼ�����ڵ��Ŀ��ڵ�
	Node FinalNode(final_data), CurrentNode(init_data), FatherNode, SonNode;
	Node NodeTemp;
	CurrentNode.m_FatherNodeNum = 0;				//���ڵ��ʼ��
	CurrentNode.m_Depth = DepthID;
	CurrentNode.m_NodeNum = NodeID;				
	CurrentNode.m_eva_g = CurrentNode.m_Depth;
	CurrentNode.m_eva_h = CurrentNode.GetevaluationM1(FinalNode);
	CurrentNode.m_evaluation = CurrentNode.GetevaluationAstar(FinalNode);
	NodeID++;										//ID����Լ�
	SearchTimes = 0;
	OpenList.AddHead(CurrentNode);					//�����ڵ�ѹ��OPEN��
	//��������
	while (ExitFlag)
	{

		if (OpenList.IsEmpty() == 1)				//OPEN��Ϊ��
		{
			ExitFlag = 0;
			Solvable = 0;
		}
		else
			NodeTemp = OpenList.RemoveHead();		//ɾ��OPEN���ͷ���	

		SearchTimes++;
		if (NodeTemp == FinalNode)					//ΪĿ��ڵ����Ŀ��ڵ�ѹ��CLOSED��ĩβ���˳�
		{
			ExitFlag = 0;
			Solvable = 1;
			ClosedList.AddTail(NodeTemp);
		}
		else
		{

			ClosedList.AddTail(NodeTemp);								//���ڵ�ѹ��CLOSED��

			for (i = 0; i < 4; i++)										//�ķ�����չ
			{
				SonNode = NodeTemp;										//ע������ԭ���ڵ���ֱ�Ӹı�
				if (SonNode.CreateNewNode(i) == 1)
				{
					SonNode.m_NodeNum = NodeID;							//��չ�ڵ�༭
					NodeID++;
					SonNode.m_FatherNodeNum = NodeTemp.m_NodeNum;
					SonNode.m_Depth = NodeTemp.m_Depth + 1;
					SonNode.m_eva_g = SonNode.m_Depth;
					SonNode.m_eva_h = SonNode.GetevaluationM1(FinalNode);
					SonNode.m_evaluation = SonNode.m_eva_g + SonNode.m_eva_h;
					SonNode.m_evaluation = SonNode.GetevaluationAstar(FinalNode);
					if (NodeRepeat(SonNode, ClosedList, Repeatx) == 1)//��CLOSED����
					{
						RepeatNode = ClosedList.GetAt(Repeatx);
						if (SonNode.m_eva_g < RepeatNode.m_eva_g)
						{
							ClosedList.RemoveAt(Repeatx);			 //�Ƴ�CLOSED�����OPEN��
							OpenList.AddTail(SonNode);
						}
					}
					else if (NodeRepeat(SonNode, OpenList, Repeatx) == 1)	//��OPEN����
					{
						RepeatNode = OpenList.GetAt(Repeatx);
						if (SonNode.m_eva_g < RepeatNode.m_eva_g)
						{
							OpenList.SetAt(Repeatx, SonNode);			//���ظ�λ��ֱ�Ӹ��ǽڵ�
						}
					}
					else												//���ظ�������OPEN��β
					{
						OpenList.AddTail(SonNode);						//ѹ��OPEN��β
					}
				}
			}															//����չ�½ڵ㣬�ض�OPEN������
			SortListByEva(OpenList);
		}
		//������������
		if (NodeTemp.m_NodeNum > MaxStep)
		{
			ExitFlag = 0;
			Solvable = 0;
		}
	}
	//�н�����ʾ���
	if (Solvable == 1)
	{
		ResultOutput(ClosedList);
		OpenList.RemoveAll();
		ClosedList.RemoveAll();
		return(1);
	}
	else
	{
		msg_output += "���ʧ�ܣ��������޽�\r\n";
		OpenList.RemoveAll();
		ClosedList.RemoveAll();
		return(0);
	}

}

/*
**@brief	��������ť
*/
void CMy8number_2Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	msg_output.Empty();
	UpdateData(0);
}

/*
**@brief	���ڰ�ť
*/
void CMy8number_2Dlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	MessageBox(_T("��ʵ1501�� ����Զ  U201514417\r\r\n\r\nָ����ʦ������ϲ"));
}


void CAboutDlg::OnXButtonDown(UINT nFlags, UINT nButton, CPoint point)
{
	// �ù���Ҫ��ʹ�� Windows 2000 ����߰汾��
	// ���� _WIN32_WINNT �� WINVER ���� >= 0x0500��
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnXButtonDown(nFlags, nButton, point);
}


void CAboutDlg::OnXButtonDblClk(UINT nFlags, UINT nButton, CPoint point)
{
	// �ù���Ҫ��ʹ�� Windows 2000 ����߰汾��
	// ���� _WIN32_WINNT �� WINVER ���� >= 0x0500��
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnXButtonDblClk(nFlags, nButton, point);
}


void CAboutDlg::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO:  �ڴ˴������Ϣ����������
}


void CAboutDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanging(lpwndpos);

	// TODO:  �ڴ˴������Ϣ����������
}


void CAboutDlg::OnVScrollClipboard(CWnd* pClipAppWnd, UINT nSBCode, UINT nPos)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnVScrollClipboard(pClipAppWnd, nSBCode, nPos);
}


int CAboutDlg::OnVKeyToItem(UINT nKey, CListBox* pListBox, UINT nIndex)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	return CDialogEx::OnVKeyToItem(nKey, pListBox, nIndex);
}


void CAboutDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CAboutDlg::OnUserChanged()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnUserChanged();
}


void CAboutDlg::OnUnInitMenuPopup(CMenu *pPopupMenu, UINT nFlags)
{
	// �ù���Ҫ��ʹ�� Windows 2000 ����߰汾��
	// ���� _WIN32_WINNT �� WINVER ���� >= 0x0500��
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnUnInitMenuPopup(pPopupMenu, nFlags);
}


void CAboutDlg::OnUpdateUIState(UINT /*nAction*/, UINT /*nUIElement*/)
{
	// �ù���Ҫ��ʹ�� Windows 2000 ����߰汾��
	// ���� _WIN32_WINNT �� WINVER ���� >= 0x0500��
	// TODO:  �ڴ˴������Ϣ����������
}


void CAboutDlg::OnUniChar(UINT Char, UINT nRepCnt, UINT nFlags)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnUniChar(Char, nRepCnt, nFlags);
}


void CAboutDlg::OnWinIniChange(LPCTSTR lpszSection)
{
	CDialogEx::OnWinIniChange(lpszSection);

	// TODO:  �ڴ˴������Ϣ����������
}


void CAboutDlg::OnSessionChange(UINT nSessionState, UINT nId)
{
	// �ù���Ҫ��ʹ�� Windows XP ����߰汾��
	// ���� _WIN32_WINNT ���� >= 0x0501��
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnSessionChange(nSessionState, nId);
}


void CMy8number_2Dlg::OnEnChangeEditInit11()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

/*
**@brief �˳�����
*/
void CMy8number_2Dlg::OnBnClickedQuit()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//�˳�
	SendMessage(WM_CLOSE, 0, 0);
}


void CMy8number_2Dlg::OnBnClickedRadio1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}



void CMy8number_2Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	// TODO: Add your message handler code here  
	if (nType == SIZE_RESTORED || nType == SIZE_MAXIMIZED)
	{
		ReSize();
	}
}

void CMy8number_2Dlg::ReSize( void )
{
	float fsp[2];
	POINT Newp; //��ȡ���ڶԻ���Ĵ�С  
	CRect recta;
	GetClientRect(&recta);     //ȡ�ͻ�����С    
	Newp.x = recta.right - recta.left;
	Newp.y = recta.bottom - recta.top;
	fsp[0] = (float)Newp.x / m_old.x;
	fsp[1] = (float)Newp.y / m_old.y;
	CRect Rect;
	int woc;
	CPoint OldTLPoint, TLPoint; //���Ͻ�  
	CPoint OldBRPoint, BRPoint; //���½�  
	HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);  //�г����пؼ�    
	while (hwndChild)
	{
		woc = ::GetDlgCtrlID(hwndChild);//ȡ��ID  
		GetDlgItem(woc)->GetWindowRect(Rect);
		ScreenToClient(Rect);
		OldTLPoint = Rect.TopLeft();
		TLPoint.x = long(OldTLPoint.x*fsp[0]);
		TLPoint.y = long(OldTLPoint.y*fsp[1]);
		OldBRPoint = Rect.BottomRight();
		BRPoint.x = long(OldBRPoint.x *fsp[0]);
		BRPoint.y = long(OldBRPoint.y *fsp[1]);
		Rect.SetRect(TLPoint, BRPoint);
		GetDlgItem(woc)->MoveWindow(Rect, TRUE);
		hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);
	}
	m_old = Newp;
}

void CMy8number_2Dlg::OnBnClickedOneword()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMy8number_2Dlg::OnEnChangeEditFinal11()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMy8number_2Dlg::OnEnChangeEditOutput()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
