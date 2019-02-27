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
//赋值运算符重载
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

//操作运算符 重载
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
//比较运算符重载
bool Node::operator>(const Node n)
{
	if (m_evaluation>n.m_evaluation)
		return true;
	else
		return false;
}

//比较运算符重载
bool Node::operator<(const Node n)
{
	if (m_evaluation<n.m_evaluation)
		return true;
	else
		return false;
}

//获取估价函数值
float Node::Getevaluation(Node n_final)
{
	return 0;
}

/*
**@brief	求取估价函数的第一种方法
**@note		将当前节点与目标节点作对比，位置不符的棋子个数，3*3格
*/
int Node::GetevaluationM0(Node n_final)
{
	char i = 0, j = 0;
	//int result = 0;
	m_evaluation = 0;
	//求取位置不符的棋子个数
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



//距离表--0，1，2，3，4，5，6，7，8在各自位置上到0，1，2，3，4，5，6，7，8
char DistanceTable[9][9] = {
	{ 0, 2, 1, 2, 1, 2, 1, 2, 1 },			//0到0，1，2，3，4，5，6，7，8
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
**@brief	求取估价函数的第二种方法
**@note		各棋子到目的位置所需移动的距离
**			可以尝试棋盘距离
*/
int Node::GetevaluationM1(Node n_final)
{
	char i = 0, j = 0;
	//int result = 0;
	m_evaluation = 0;
	//各棋子到目的位置所需移动的距离
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
**@brief	求取估价函数的第三种方法
**@note		逆转棋子数--这里逆转棋子数可能有问题
*/
int Node::GetevaluationM2( void )
{
	char i = 0, j = 0;
	char InitData[9];
	//char InvNum = 0;
	m_evaluation = 0;
	//顺时针的九个数
	InitData[0] = m_data[0][0];
	InitData[1] = m_data[0][1];
	InitData[2] = m_data[0][2];
	InitData[3] = m_data[1][2];
	InitData[4] = m_data[2][2];
	InitData[5] = m_data[2][1];
	InitData[6] = m_data[2][0];
	InitData[7] = m_data[1][0];
	InitData[8] = m_data[1][1];
	//这里的逆转棋子定义，存疑？
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
**@brief	求取估价函数的第三种方法
**@note		位置不符棋子数+逆转棋子数*3
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
**@brief	求取估价函数的第四种方法
**@note		各棋子到目的位置所需移动的距离+棋子深度*3
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
**@brief	A*算法求取估价函数值
**@note		棋子深度+各棋子到目的位置所需移动的距离
*/
int Node::GetevaluationAstar(Node n_final)
{
	m_eva_h = 4*GetevaluationM1(n_final );
	m_eva_g = m_Depth;
	m_evaluation = m_eva_g + m_eva_h;
	return(m_evaluation);
}

/*
**@brief 第11格位置为0
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
**@brief 以i为空格移动方向进行节点的拓展 0，1，2，3分别代表右，下，左，上
**		对应的，当前的值分别加上 1，3，-1，-3	
*/
bool Node:: CreateNewNode( int i )
{
	char temp = 0;
	char x = 0, y = 0;
	char j = 0, k = 0;
	char dxy[4] = { 1, 3, -1, -3 };
	//int OldNum = 0;
	//参数检查
	if (i > 3)
		return 0;
	//更新空格的位置
	GetFreePos();
	//判断是否可移动
	if ( (i == 0 && free_pos%3 == 2) || (i == 1 && free_pos>5)
		|| (i == 2 && free_pos % 3 == 0) || (i == 3 && free_pos<3) )
		return(0);
	else								//创建新的节点，并更新其父节点编号，深度
	{
		temp = free_pos;				//记录原来来空格位置
		j = temp / 3;
		k = temp % 3;
		free_pos += dxy[i];				//更新空格位置
		x = free_pos / 3;
		y = free_pos % 3;
		m_data[j][k] = m_data[x][y];	//互换位置
		m_data[x][y] = 0;
		//m_FatherNodeNum = m_NodeNum;	//父节点为原节点编号
		m_Depth++;
		return(1);
	}
	//return(1);
}


