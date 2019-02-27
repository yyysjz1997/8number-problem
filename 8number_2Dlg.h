
// 8number_2Dlg.h : header file
//

#pragma once

#include <iostream>
//#include <stack>
//#include <queue>
//#include <vector>
#include <afxtempl.h>
#include "Node.h"

//����һ�����Ի����࣬��Ӧ�ó������к���ʾ����Ҫ���档
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

	//����Ի����С
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
	//ѡ��ť
	afx_msg void OnBnClickedChoose(UINT nID);
	afx_msg void OnBnClickedEightOneChoose(UINT nID);
	afx_msg void OnBnClickedNodeShowChoose(UINT nID);

	//�ڳ�ʼ״̬���Ŀ��״̬������ʾ��Ӧ���ַ���
	void CMy8number_2Dlg::InitFinalTextBlockShow(char init_data[3][3], char final_data[3][3]);
	//����������
	bool CMy8number_2Dlg::InputCheck(char init_data[3][3], char final_data[3][3]);
	//���������ʾ
	void CMy8number_2Dlg::OutputWrongMsg(void);
	//�жϳ�ʼ״̬��״̬��Ŀ��״̬���Ƿ�ɽ�
	bool CMy8number_2Dlg::JudgeSolvable(char init_data[3][3], char final_data[3][3]);
	//�ж��Ƿ���֮ǰ���ֹ��Ľڵ��ظ�
	bool CMy8number_2Dlg::NodeRepeat(Node NodeTemp, CList<Node, Node&>&ClosedList,POSITION &RepeatX);
	//����н�Ļ�,��ʾ����·��
	void CMy8number_2Dlg::ResultOutput(CList<Node, Node&>&ClosedList);
	//������������㷨
	bool CMy8number_2Dlg::BFS_Search(char init_data[3][3], char final_data[3][3]);
	//������������㷨
	bool CMy8number_2Dlg::DFS_Search(char init_data[3][3], char final_data[3][3]);
	//���������ۺ�����������
	void CMy8number_2Dlg::SortListByEva(CList<Node, Node&>&OpenList);
	//����ʽ����
	bool CMy8number_2Dlg::INFO_Search(char init_data[3][3], char final_data[3][3]);
	//A*�㷨
	bool CMy8number_2Dlg::Astar_Search(char init_data[3][3], char final_data[3][3]);
	//����ѡ������ۺ���
	int CMy8number_2Dlg::GetEvaTemp(Node NodeTemp, Node NodeFinal);


	//�˳���������
	afx_msg void OnBnClickedQuit();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnDfsSearch();
	afx_msg void OnBnClickedOneword();
	afx_msg void OnEnChangeEditFinal11();
	afx_msg void OnEnChangeEditOutput();
};

//�����㷨
//bool search(char init_data[3][3], char final_data[3][3]);
//�ɸ��ڵ㴴��һ���µĽڵ㲢����ѹ��OPEN����



