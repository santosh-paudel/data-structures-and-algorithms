/*Please refer to tree_implementation.cpp for full implementation*/

_height(Node *node)
{
	if(node == NULL)
	{
		return -1;
	}

	int leftHeight = _height(node->left);
	int rightHeight = _height(node->right);

	if (leftHeight < rightHeight)
	{
		return rightHeight+1;
	}
	else
	{
		return leftHeight+1;
	}
}

