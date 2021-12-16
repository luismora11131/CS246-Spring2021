#ifndef TNODE_H
#define TNODE_H

namespace ds
{
	template<class T>
	struct TNode
	{
		T data;
		TNode<T>* p;
		TNode<T>* left;
		TNode<T>* right;
	};
	
	template<class T>
	TNode<T>* Create(const T& itm)
	{
		TNode<T>* t = new TNode<T>;
			
		t->data = itm;
		t->p = NULL;
		t->left = NULL;
		t->right = NULL;
		return t;
	}

	template<class T>
	TNode<T>* Copy(TNode<T>* rt,TNode<T> * p)
	{
		if(rt == NULL)
		{
			return NULL;
		}
		TNode<T>* hd = Create(rt->data);
		hd->p = p;
		hd->left = Copy(rt->left,hd);
		hd->right = Copy(rt->right,hd);
		return hd;
	} 
		
	template<class T>
	void Clear(TNode<T>*& rt)
	{
		if(rt != NULL)
		{
			Clear(rt->left);
			Clear(rt->right);
			delete rt;
			rt = NULL;
		}
	}
}

#endif
