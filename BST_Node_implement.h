/*
 * BST_Node_implement.h
 *
 *  Created on: Dec 23, 2015
 *      Author: eranpel
 *      implements template of node
 */

// Implementation of a template Node
template <class T>
BSTNode<T>::BSTNode(const BSTNode<T>&v)
{
	left = right = parent= NULL;
	pData = NULL;  // enabling deletion
	*this = v; // uses overloaded operator=
}
template <class T>
BSTNode<T>& BSTNode<T>::operator=(BSTNode<T> &v)
{
	if(&v==this)return*this;
	delete left;
	delete right;
	delete parent;
	delete pData;
	left = v.left;
	right = v.right;
	parent = v.parent;
	pData = v.pData;
	return*this;

}
template <class T>
void BSTNode<T>::Insert(BSTNode<T>* head,BSTNode<T>* newNode)
{
	if(*newNode->pData == *head->pData)return;
	if(*newNode->pData < *head->pData){
		if(head->left!=NULL)
			Insert(head->left,newNode);
		else
			head->left = new BSTNode<T>(newNode->pData,newNode->item_id,head);
	}
	else
	{
		if(head->right!=NULL)
			Insert(head->right,newNode);
		else
			head->right = new BSTNode<T>(newNode->pData,newNode->item_id,head);
	}
	return;
}
/*Search Specfic T on Tree return as argument*/
		/*precondition : (class we want to search,return pointer set to zero(if nothing is found)*/
template<class T>
void BSTNode<T>::Search(const T&d,BSTNode<T>** ret )
{

	if(this == NULL)return;
	if(this!=NULL)
	{
		if(d == *this->getData())*ret = this;
		if(d < *this->getData())
		{

			if(this->getLeft() == NULL)return ;
			this->getLeft()->Search(d,ret);
		}
		else
		{

			if(this->getRight() == NULL)return ;
			this->getRight()->Search(d,ret);
		}
	}
}

