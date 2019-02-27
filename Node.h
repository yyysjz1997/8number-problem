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
	//求取估价函数
	float Getevaluation(Node n_final);
	//求取估价函数的第一种方法
	int Node::GetevaluationM0(Node n_final);
	//求取估价函数的第二种方法
	int Node::GetevaluationM1(Node n_final);
	//求取估价函数的第三种方法
	int Node::GetevaluationM2( void );
	//求取估价函数的第四种方法
	int Node::GetevaluationM3(Node n_final);
	//求取估价函数值的第四种方法--作业要求自定义方法
	int Node::GetevaluationM4(Node n_final);
	//A*算法的估价函数值求取
	int Node::GetevaluationAstar(Node n_final);
	//求取当前的0的位置
	char Node::GetFreePos();
	//等于运算符重载
	Node operator=(const Node data);
	bool operator ==(const Node data);
	//比较运算符重载
	bool Node::operator>(const Node n);
	//比较运算符重载
	bool Node::operator<(const Node n);
	//拓展节点--8数码
	bool Node::CreateNewNode(int i);
	//拓展节点--一字棋，约定用0表示空白,1表示X,2表示O
	bool Node::OneWordCreateNewNode(int x,int y,int Chessman);
	
	//一些数据
	char m_data[3][3];			//表示棋子的数组
	int m_NodeNum;				//节点编号，根节点为0
	int m_FatherNodeNum;		//父节点编号，根节点父节点编号为自身
	int m_Depth;				//深度，根节点为0
	int m_evaluation;			//估价函数值
	int m_eva_h;				//A*中h，启发函数，取为求取估价函数的第二种方法
	int m_eva_g;				//A*中g，实际代价，取为深度
	char free_pos;				//记录空格的位置
};

