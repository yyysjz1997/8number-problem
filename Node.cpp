#include "stdafx.h"
#include "Node.h"
#include <afxtempl.h>

Node::Node()
{
	char i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			m_data[i][j] = 0;
		}
	}
	//m_evaluation = evaluation_MAX;
	free_pos = 1;
}

Node::Node(char data[3][3])
{
	char i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			m_data[i][j] = data[i][j];
		}
	}
	//m_evaluation = evaluation_MAX;
	GetFreePos();
}

Node::Node(char data[3][3],float e)
{
	char i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			m_data[i][j] = data[i][j];
		}
	}
	//m_evaluation = e;
	GetFreePos();
}

Node::Node(float e)
{
	char i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			m_data[i][j] = 0;
		}
	}

	//m_evaluation = e; 
	GetFreePos();
}


Node::~Node()
{
}
//complex complex::operator +(const complex &c)
//��ֵ���������
Node Node::operator=(const Node n)
{
	char i,j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			m_data[i][j] = n.m_data[i][j];
		}
	}
	m_NodeNum = n.m_NodeNum;
	m_FatherNodeNum = n.m_FatherNodeNum;
	m_Depth = n.m_Depth;
	m_evaluation = n.m_evaluation;
	free_pos = n.free_pos;
	m_eva_g = n.m_eva_g;
	m_eva_h = n.m_eva_h;

	return n;
}

//��������� ����
bool Node:: operator ==(const Node n)
{
	char i,j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (!(m_data[i][j] == n.m_data[i][j]))
				return false;
		}
	}
	return true;
}
//�Ƚ����������
bool Node::operator>(const Node n)
{
	if (m_evaluation>n.m_evaluation)
		return true;
	else
		return false;
}

//�Ƚ����������
bool Node::operator<(const Node n)
{
	if (m_evaluation<n.m_evaluation)
		return true;
	else
		return false;
}

//��ȡ���ۺ���ֵ
float Node::Getevaluation(Node n_final)
{
	return 0;
}

/*
**@brief	��ȡ���ۺ����ĵ�һ�ַ���
**@note		����ǰ�ڵ���Ŀ��ڵ����Աȣ�λ�ò��������Ӹ�����3*3��
*/
int Node::GetevaluationM0(Node n_final)
{
	char i = 0, j = 0;
	//int result = 0;
	m_evaluation = 0;
	//��ȡλ�ò��������Ӹ���
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if ( m_data[i][j] != n_final.m_data[i][j] )
			{
				//result++;
				m_evaluation++;
			}
		}
	}
	//m_evaluation = result;
	return (m_evaluation);
}



//�����--0��1��2��3��4��5��6��7��8�ڸ���λ���ϵ�0��1��2��3��4��5��6��7��8
char DistanceTable[9][9] = {
	{ 0, 2, 1, 2, 1, 2, 1, 2, 1 },			//0��0��1��2��3��4��5��6��7��8
	{ 2, 0, 1, 2, 3, 4, 3, 2, 1 },			//1
	{ 1, 1, 0, 1, 2, 3, 2, 3, 2 },			//2
	{ 2, 2, 1, 0, 1, 2, 3, 4, 3 },			//3
	{ 1, 3, 2, 1, 0, 1, 2, 3, 2 },			//4
	{ 2, 4, 3, 2, 1, 0, 1, 2, 3 },			//5
	{ 1, 3, 2, 3, 2, 1, 0, 1, 2 },			//6
	{ 2, 2, 3, 4, 3, 2, 1, 0, 1 },			//7
	{ 1, 1, 2, 3, 2, 3, 2, 1, 0 }			//8
};

/*
**@brief	��ȡ���ۺ����ĵڶ��ַ���
**@note		�����ӵ�Ŀ��λ�������ƶ��ľ���
**			���Գ������̾���
*/
int Node::GetevaluationM1(Node n_final)
{
	char i = 0, j = 0;
	//int result = 0;
	m_evaluation = 0;
	//�����ӵ�Ŀ��λ�������ƶ��ľ���
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			//result = result + DistanceTable[(m_data[i][j])][(n_final.m_data[i][j])];
			m_evaluation = m_evaluation + DistanceTable[(m_data[i][j])][(n_final.m_data[i][j])];
		}
	}
	//m_evaluation = result;
	return (m_evaluation);
}

/*
**@brief	��ȡ���ۺ����ĵ����ַ���
**@note		��ת������--������ת����������������
*/
int Node::GetevaluationM2( void )
{
	char i = 0, j = 0;
	char InitData[9];
	//char InvNum = 0;
	m_evaluation = 0;
	//˳ʱ��ľŸ���
	InitData[0] = m_data[0][0];
	InitData[1] = m_data[0][1];
	InitData[2] = m_data[0][2];
	InitData[3] = m_data[1][2];
	InitData[4] = m_data[2][2];
	InitData[5] = m_data[2][1];
	InitData[6] = m_data[2][0];
	InitData[7] = m_data[1][0];
	InitData[8] = m_data[1][1];
	//�������ת���Ӷ��壬���ɣ�
	for (i = 0; i < 8; i++)
	{
		if ( (InitData[i + 1]+1) == InitData[i])
		{
			//InvNum++;
			m_evaluation++;
		}
	}
	//m_evaluation = InvNum;
	return(m_evaluation);
}


/*
**@brief	��ȡ���ۺ����ĵ����ַ���
**@note		λ�ò���������+��ת������*3
*/
int Node::GetevaluationM3(Node n_final)
{
	int WrongNum = 0;
	int InvNum = 0;
	m_evaluation = 0;
	WrongNum	= GetevaluationM0(n_final);
	InvNum = GetevaluationM2();
	m_evaluation = WrongNum + 3 * InvNum;
	return(m_evaluation);
}

/*
**@brief	��ȡ���ۺ����ĵ����ַ���
**@note		�����ӵ�Ŀ��λ�������ƶ��ľ���+�������*3
*/
int Node::GetevaluationM4(Node n_final)
{
	int MoveDistance = 0;
	int NodeDepth = 0;
	m_evaluation = 0;
	MoveDistance = GetevaluationM1(n_final);
	NodeDepth = m_Depth;
	m_evaluation = MoveDistance + NodeDepth * 3;
	return(m_evaluation);
}

/*
**@brief	A*�㷨��ȡ���ۺ���ֵ
**@note		�������+�����ӵ�Ŀ��λ�������ƶ��ľ���
*/
int Node::GetevaluationAstar(Node n_final)
{
	m_eva_h = 4*GetevaluationM1(n_final );
	m_eva_g = m_Depth;
	m_evaluation = m_eva_g + m_eva_h;
	return(m_evaluation);
}

/*
**@brief ��11��λ��Ϊ0
*/
char Node:: GetFreePos()
{
	char i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if ( m_data[i][j] == 0 )
			{
				free_pos = i * 3 + j;
			}
		}
	}
	return(free_pos);
}

/*
**@brief ��iΪ�ո��ƶ�������нڵ����չ 0��1��2��3�ֱ�����ң��£�����
**		��Ӧ�ģ���ǰ��ֵ�ֱ���� 1��3��-1��-3	
*/
bool Node:: CreateNewNode( int i )
{
	char temp = 0;
	char x = 0, y = 0;
	char j = 0, k = 0;
	char dxy[4] = { 1, 3, -1, -3 };
	//int OldNum = 0;
	//�������
	if (i > 3)
		return 0;
	//���¿ո��λ��
	GetFreePos();
	//�ж��Ƿ���ƶ�
	if ( (i == 0 && free_pos%3 == 2) || (i == 1 && free_pos>5)
		|| (i == 2 && free_pos % 3 == 0) || (i == 3 && free_pos<3) )
		return(0);
	else								//�����µĽڵ㣬�������丸�ڵ��ţ����
	{
		temp = free_pos;				//��¼ԭ�����ո�λ��
		j = temp / 3;
		k = temp % 3;
		free_pos += dxy[i];				//���¿ո�λ��
		x = free_pos / 3;
		y = free_pos % 3;
		m_data[j][k] = m_data[x][y];	//����λ��
		m_data[x][y] = 0;
		//m_FatherNodeNum = m_NodeNum;	//���ڵ�Ϊԭ�ڵ���
		m_Depth++;
		return(1);
	}
	//return(1);
}


