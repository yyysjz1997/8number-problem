
// 8number_2Dlg.h : header file
//

#pragma once

#include <iostream>
//#include <stack>
//#include <queue>
//#include <vector>
#include <afxtempl.h>
#include "Node.h"

//这是一个主对话框类，此应用程序运行后显示的主要界面。
// CMy8number_2Dlg dialog
class CMy8number_2Dlg : public CDialogEx
{
// Construction
public:
	CMy8number_2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MY8NUMBER_2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	//保存对话框大小
	CRect	m_rect;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void CMy8number_2Dlg::ReSize( void );
	POINT m_old;
	//

	CString msg_output;

	afx_msg void OnBnClickedButton1();
	CString final_data11;
	CString final_data12;
	CString final_data13;
	CString final_data21;
	CString final_data22;
	CString final_data23;
	CString final_data31;
	CString final_data32;
	CString final_data33;
	CString init_data11;
	CString init_data12;
	CString init_data13;
	CString init_data21;
	CString init_data22;
	CString init_data23;
	CString init_data31;
	CString init_data32;
	CString init_data33;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeEditInit11();
	//选择按钮
	afx_msg void OnBnClickedChoose(UINT nID);
	afx_msg void OnBnClickedEightOneChoose(UINT nID);
	afx_msg void OnBnClickedNodeShowChoose(UINT nID);

	//在初始状态框和目的状态框上显示对应的字符串
	void CMy8number_2Dlg::InitFinalTextBlockShow(char init_data[3][3], char final_data[3][3]);
	//输入参数检查
	bool CMy8number_2Dlg::InputCheck(char init_data[3][3], char final_data[3][3]);
	//输出错误提示
	void CMy8number_2Dlg::OutputWrongMsg(void);
	//判断初始状态和状态和目标状态间是否可解
	bool CMy8number_2Dlg::JudgeSolvable(char init_data[3][3], char final_data[3][3]);
	//判断是否与之前出现过的节点重复
	bool CMy8number_2Dlg::NodeRepeat(Node NodeTemp, CList<Node, Node&>&ClosedList,POSITION &RepeatX);
	//如果有解的话,显示求解的路径
	void CMy8number_2Dlg::ResultOutput(CList<Node, Node&>&ClosedList);
	//广度优先搜索算法
	bool CMy8number_2Dlg::BFS_Search(char init_data[3][3], char final_data[3][3]);
	//深度优先搜索算法
	bool CMy8number_2Dlg::DFS_Search(char init_data[3][3], char final_data[3][3]);
	//对链表按估价函数进行排序
	void CMy8number_2Dlg::SortListByEva(CList<Node, Node&>&OpenList);
	//启发式搜索
	bool CMy8number_2Dlg::INFO_Search(char init_data[3][3], char final_data[3][3]);
	//A*算法
	bool CMy8number_2Dlg::Astar_Search(char init_data[3][3], char final_data[3][3]);
	//根据选择算估价函数
	int CMy8number_2Dlg::GetEvaTemp(Node NodeTemp, Node NodeFinal);


	//退出按键操作
	afx_msg void OnBnClickedQuit();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnDfsSearch();
	afx_msg void OnBnClickedOneword();
	afx_msg void OnEnChangeEditFinal11();
	afx_msg void OnEnChangeEditOutput();
};

//搜索算法
//bool search(char init_data[3][3], char final_data[3][3]);
//由父节点创建一个新的节点并将其压入OPEN表中



