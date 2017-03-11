/*
 * Tree_implement.h
 *
 *  Created on: Dec 23, 2015
 *      Author: eranpel
 *      implements template
 */

// Implementation of a template Tree
template <class T>
Tree<T>& Tree<T>::operator=(const Tree<T>& t)
{
	if(&t==this)
	return *this;
	clear();
	this->head = t.head;
	this->counter = t.counter;
	this->id_counter = t.id_counter;
	return *this;
}

template <class T>
void Tree<T>::Insert(T *pData)
{
	++id_counter;
	++counter;
	if(head == NULL)
	{
		head = new BSTNode<T>(pData,id_counter);
	}
	else{

		//insert data and ID number
		head->Insert(head,new BSTNode<T>(pData,id_counter)); //calling node insert function
	}
}
/* Given a non-empty binary search tree,
return the maximum data value found in that
tree. Note that the entire tree does not need
to be searched. */
template <class T>
BSTNode<T>* Tree<T>::getMax()const{
	BSTNode<T>* current = head;

	/* loop down to find the rightmost leaf */
	while (current->getRight() != 0) {
		current = current->getRight();
	}
	return(current);
}
/* Given a non-empty binary search tree,
	return the minimum data value found in that
	tree. Note that the entire tree does not need
	to be searched. */
template <class T>
BSTNode<T>* Tree<T>::getMin()const{
	BSTNode<T>* current = head;

	/* loop down to find the leftmost leaf */
	while (current->getLeft() != 0) {
		current = current->getLeft();
	}
	return(current);
}

//get the max node in sub-tree
template <class T>
BSTNode<T>* Tree<T>::getMaxHLP(BSTNode<T>* get)const
		{
	BSTNode<T>* current = get;

		/* loop down to find the rightmost leaf */
		while (current->getRight() != 0) {
			current = current->getRight();
		}
		return(current);
	}

template <class T>
BSTNode<T>* Tree<T>::getMinHLP(BSTNode<T>* get)const
		{
	BSTNode<T>* current = get;

		/* loop down to find the rightmost leaf */
		while (current->getLeft() != 0) {
			current = current->getRight();
		}
		return(current);
	}

//*Deletes the entire tree*//
template <class T>
void Tree<T>::clear()
{
	BSTNode<T> *h = head;
	counter = 0;
	recDeleteTree(h->getLeft());
	recDeleteTree(h->getRight());
	delete (h);
	this->head = 0;
}

/* Clearing the tree: a recursive free function */
template <class T>
void Tree<T>::recDeleteTree(BSTNode<T>* t)
{
	if (!t) return;
	if(t->getLeft()!=NULL)recDeleteTree(t->getLeft());
	if(t->getRight()!=NULL)recDeleteTree(t->getRight());
	delete t;
	}


//*prints in ascending order*//
template <class T>
void Tree<T>::print(BSTNode<T> *p)
{
	if(!head)cout << "The Tree is empty!";
	//*assuming << operator is defined in class*//
	if(p == 0)return;
	if(p)
	{
		print(p->getLeft());
		cout << *p->getData();
		print(p->getRight());
	}
}

template <class T>
void Tree<T>::filePrint(ofstream& output,BSTNode<T> *p)
{
		if(p == 0)return;
		if(p)
		{
			filePrint(output,p->getLeft());
			output << **p->getData();
			filePrint(output,p->getRight());
		}
}




/*helping function for deletion*/
template <class T>
BSTNode<T>*  Tree<T>::DeleteHLP(BSTNode<T> *root,const T& d)
{
  if(root == NULL) return root;
  else if(d < *(root->getData())) root->setLeft((DeleteHLP(root->getLeft(),d)));
  else if(d > *(root->getData())) root->setRight((DeleteHLP(root->getRight(),d)));
  else {
    // Case 1: No Child
    if(root->getLeft() == NULL && root->getRight() == NULL)
    {
      delete(root);
      root = NULL;
    // Case 2: one child
    } else if(root->getLeft() == NULL){
      T *tmp = root->getData();
      root = root->getRight();
      delete tmp;//deletes the node from memory!
    } else if(root->getRight() == NULL){
      T *tmp = root->getData();
      root = root->getLeft();
      delete tmp; //deletes the node from memory!
      // Case 2: two child
    } else
    {
      BSTNode<T> *temp = getMinHLP(root->getRight());
      root->setData(*temp->getData());
      BSTNode<T> *right =DeleteHLP(root->getRight(),*temp->getData());
      root->setRight(right);
    }
  }
  return root;
}
/* Given a non-empty binary search tree,
//	deletes a specific Node. */
template <class T>
bool Tree<T>::Delete(const T& d){
	head = DeleteHLP(head,d);
	if(head == NULL) return head;
	return true;
}


