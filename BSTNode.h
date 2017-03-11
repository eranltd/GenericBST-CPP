/*
 * BSTBSTNode.h
 *
 *  Created on: Dec 23, 2015
 *      Author: eranpel
 */

#ifndef BSTNode_H_
#define BSTNode_H_
#include <iostream>
using namespace std;
template<class T>
class BSTNode
{
	BSTNode<T> *left, *right, *parent;
	T* pData;
	int item_id;
	BSTNode(const BSTNode<T>&);
	BSTNode<T>& operator=(BSTNode<T> &v);
public:
	BSTNode():left(0),right(0),parent(0),item_id(0),pData(new T){}
	BSTNode(T* pd, int id,BSTNode<T>* p=0):left(0),right(0),parent(p),item_id(id) {pData = new T; *pData = *pd;}
	~BSTNode(){delete pData;}//delete left; delete right; }
	BSTNode<T>* getLeft(){return left;}
	BSTNode<T>* getRight(){return right;}
	BSTNode<T>* getParent(){return parent;}
	T* getData(){return pData;}
	int getID()const{return item_id;}
	void setID(int id){item_id=id;}
	void setLeft(BSTNode<T>* l){left=l;}
	void setRight(BSTNode<T>* r){right=r;}
	void setParent(BSTNode<T>* p){parent=p;}
	void setData(const T& d){*pData = d;}
	void Insert(BSTNode<T>* head,BSTNode<T>* newNode);
	void Search(const T&d,BSTNode<T>** ret);
};

#include "BST_Node_implement.h"
#endif /* BSTNode_H_ */
