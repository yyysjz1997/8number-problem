#pragma once

#define evaluation_MAX (1000000)

class Node
{
public:
	Node();
	Node(char data[3][3]);
	Node(char data[3][3], float e);
	Node(float e);

	~Node();
	//��ȡ���ۺ���
	float Getevaluation(Node n_final);
	//��ȡ���ۺ����ĵ�һ�ַ���
	int Node::GetevaluationM0(Node n_final);
	//��ȡ���ۺ����ĵڶ��ַ���
	int Node::GetevaluationM1(Node n_final);
	//��ȡ���ۺ����ĵ����ַ���
	int Node::GetevaluationM2( void );
	//��ȡ���ۺ����ĵ����ַ���
	int Node::GetevaluationM3(Node n_final);
	//��ȡ���ۺ���ֵ�ĵ����ַ���--��ҵҪ���Զ��巽��
	int Node::GetevaluationM4(Node n_final);
	//A*�㷨�Ĺ��ۺ���ֵ��ȡ
	int Node::GetevaluationAstar(Node n_final);
	//��ȡ��ǰ��0��λ��
	char Node::GetFreePos();
	//�������������
	Node operator=(const Node data);
	bool operator ==(const Node data);
	//�Ƚ����������
	bool Node::operator>(const Node n);
	//�Ƚ����������
	bool Node::operator<(const Node n);
	//��չ�ڵ�--8����
	bool Node::CreateNewNode(int i);
	//��չ�ڵ�--һ���壬Լ����0��ʾ�հ�,1��ʾX,2��ʾO
	bool Node::OneWordCreateNewNode(int x,int y,int Chessman);
	
	//һЩ����
	char m_data[3][3];			//��ʾ���ӵ�����
	int m_NodeNum;				//�ڵ��ţ����ڵ�Ϊ0
	int m_FatherNodeNum;		//���ڵ��ţ����ڵ㸸�ڵ���Ϊ����
	int m_Depth;				//��ȣ����ڵ�Ϊ0
	int m_evaluation;			//���ۺ���ֵ
	int m_eva_h;				//A*��h������������ȡΪ��ȡ���ۺ����ĵڶ��ַ���
	int m_eva_g;				//A*��g��ʵ�ʴ��ۣ�ȡΪ���
	char free_pos;				//��¼�ո��λ��
};

