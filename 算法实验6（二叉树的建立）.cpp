//构建二叉树，遍历二叉树
#include <iostream>
#include <queue>
using namespace std;

typedef struct BiTNode//二叉树的二叉链表存储表示
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree& T);//二叉链表的创建
void PreOrderTraverse(BiTree T);//先序DLR遍历
void InOrderTraverse(BiTree T);//中序LDR遍历
void PostOrderTraverse(BiTree T);//后序LRD遍历
void LevelOrderTraverse(BiTree &T);//层次遍历

int main()
{
	BiTree iT;
	CreateBiTree(iT);
	cout << "先序遍历结果为：" << endl;
	PreOrderTraverse(iT);
	cout <<endl<< "中序遍历结果为：" << endl;
	InOrderTraverse(iT);
	cout <<endl<< "后序遍历结果为：" << endl;
	PostOrderTraverse(iT);
	cout << endl << "层次遍历结果为：" << endl;
	LevelOrderTraverse(iT);
	return 0;
}

void CreateBiTree(BiTree& T)//先序DLR输入二叉树中结点的值（一个字符)
{                           //创建二叉链表表示二叉树T
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;//递归结束，建空树
	else
	{
		T = new BiTNode;//生成根结点
		T->data = ch;//将根结点数据域置为ch
		CreateBiTree(T->lchild);//递归创建左子树
		CreateBiTree(T->rchild);//递归创建右子树
	}
}

void PreOrderTraverse(BiTree T)//先序DLR遍历
{
	if(T)
	{
		cout << T->data;//根结点
		PreOrderTraverse(T->lchild);//左子树
		PreOrderTraverse(T->rchild);//右子树
	}
}

void InOrderTraverse(BiTree T)//中序LDR遍历
{
	if(T)
	{
		InOrderTraverse(T->lchild);//左子树
		cout << T->data;//根结点
		InOrderTraverse(T->rchild);//右子树
	}
}

void PostOrderTraverse(BiTree T)//后序LRD遍历
{
	if(T)
	{
		PostOrderTraverse(T->lchild);//左子树
		PostOrderTraverse(T->rchild);//右子树
		cout << T->data;//根结点
	}
}

void LevelOrderTraverse(BiTree &T)//层次遍历
{
	if (T != NULL) 
	{
		queue<BiTree> q;//初始队列
		q.push(T);//根结点入队
		while (!q.empty())//队列非空
		{
			BiTree p = q.front();//保存根结点
			q.pop();
			cout << p->data;
			if (p->lchild != NULL)
				q.push(p->lchild);
			if (p->rchild != NULL)
				q.push(p->rchild);
		}
	}
}


/*

测试代码：
ABDH###E##CF##G##
先序遍历结果为：
ABDHECFG
中序遍历结果为：
HDBEAFCG
后序遍历结果为：
HDEBFGCA
层次遍历结果为：
ABCDEFGH

*/