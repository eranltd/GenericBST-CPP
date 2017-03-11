/*
 * Tree.h
 *
 *  Created on: Dec 23, 2015
 *      Author: eranpel
 */

#ifndef TREE_H_
#define TREE_H_
#include <stddef.h>
#include "BSTNode.h"
template<class T>
class Tree
{
	BSTNode <T>* head; //head to the specific tree
	int counter;
	// counts the nodes in the tree
	int id_counter;
	// counts nodes, including those deleted

public:
	Tree():head(0),counter(0),id_counter(0){}
	~Tree(){delete(head);} /*check*//*the tree is empty but the first node is alive :) fix me!*/
	int GetID_counter(){return id_counter ;}
	int GetCounter(){return counter;}
	BSTNode <T>* GetHead(){return head;}
	void Insert(T* pData); //insert a new node to tree
	void clear(); //delete the entire tree //assuming there is a d'tor for every object
	BSTNode<T>* getMax()const; //get the max node
	BSTNode<T>* getMin()const; //get the min node
	BSTNode<T>* getMaxHLP(BSTNode<T>* get)const; //get the max node in sub-tree
	BSTNode<T>* getMinHLP(BSTNode<T>* get)const; //get the min node in sub-tree
	void print(BSTNode<T> *p);//*prints in ascending order*//
	bool Delete(const T& d); //delete a node
	BSTNode<T>* DeleteHLP(BSTNode<T> *root,const T& d); //helping method
	Tree(const Tree<T>& t); //needs to be implement
	Tree<T>& operator=(const Tree<T>& t);
	void recDeleteTree(BSTNode<T>* t); //helping method
	void filePrint(ofstream& output,BSTNode<T> *p);
};

#include "Tree_implement.h"
#endif /* TREE_H_ */
