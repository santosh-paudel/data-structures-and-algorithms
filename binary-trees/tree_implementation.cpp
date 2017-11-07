#include <iostream>
#include <string>
#include <queue>

struct Node
{
	int data;
	Node *left = NULL;
	Node *right = NULL;
};

class Tree
{
private:
	Node *root;
	void _insert(Node *node, int value);
	void _preorder(Node *node);
	void _postorder(Node *node);
	void _inorder(Node *node);
	int _height(Node *node);


public:
	Tree(){root = NULL;}
	void insert(int value);
	void preorder();
	void postorder();
	void inorder();
	void bfs(); //breadth first traversal
	int height();
};

void Tree::_insert(Node * node, int value)
{
	if(value <= node->data)
	{
		if(node->left == NULL)
		{
			Node *temp = new Node;
			temp -> data = value;
			node -> left = temp;
		}
		else
		{
			_insert(node->left, value);
		}
	}
	else
	{
		if(node->right == NULL)
		{
			Node *temp = new Node;
			temp -> data = value;
			node -> right = temp;
		}
		else
		{
			_insert(node->right, value);
		}
	}
}

void Tree::insert(int value)
{
	if(root == NULL)
	{
		root = new Node;
		root -> data = value;
	}
	else
	{
		_insert(root, value);
	}
}

void Tree::preorder()
{
	_preorder(root);
}

void Tree::_preorder(Node *node)
{
	if (node != NULL)
	{
		std::cout<<node->data<<" ";
		_preorder(node->left);
		_preorder(node->right);
	}
}

void Tree::postorder()
{
	_postorder(root);
}

void Tree::_postorder(Node *node)
{
	if(node != NULL)
	{
		_postorder(node->left);
		_postorder(node->right);
		std::cout<<node->data<<" ";
	}
}

void Tree::inorder()
{
	_inorder(root);
}

void Tree::_inorder(Node *node)
{
	if(node != NULL)
	{
		_inorder(node -> left);
		std::cout<<node->data<<" ";
		_inorder(node -> right);

	}
}

void Tree::bfs()
{
	Node  *temp;
	std::queue<Node *> q;
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		std::cout<<temp->data<<" ";
		if(temp->left != NULL)
		{
			q.push(temp->left);
		}
		if(temp->right != NULL)
		{
			q.push(temp->right);
		}
	}
}

int Tree::height()
{
	return _height(root);
}

int Tree::_height(Node *node)
{
	if (node == NULL)
	{
		return -1;
	}

	int leftHeight = _height(node ->left);
	int rightHeight = _height(node ->right);

	if(leftHeight > rightHeight)
	{
		return leftHeight + 1;
	}
	else
	{
		return rightHeight + 1;
	}
}


int main()
{
	Tree tree;
	tree.insert(20);
	tree.insert(15);
	tree.insert(30);
	tree.insert(10);
	tree.insert(18);
	tree.insert(25);


	std::cout<<"Preorder Traversal"<<std::endl;
	tree.preorder();

	std::cout << std::endl;
	std::cout<<"Postorder Traversal"<<std::endl;
	tree.postorder();

	std::cout<< std::endl;
	std::cout<<"Inorder Traversal"<<std::endl;
	tree.inorder();

	std::cout<<std::endl;
	std::cout<<"Breadth First Search Traversal"<<std::endl;
	tree.bfs();


	std::cout<< std::endl << std::endl;
	std::cout<<"The height of the tree is "<<tree.height()<<std::endl;
	return 0;
}


