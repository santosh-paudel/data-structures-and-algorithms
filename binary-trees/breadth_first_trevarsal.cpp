/*Please refer to tree_implementation.cpp for full implementation*/
bfs()
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

