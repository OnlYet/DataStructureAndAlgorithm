#pragma once

template<typename T>
struct BSTNode {
	T data;
	BSTNode *lchild, rchild, parent;
	BSTNode(const T& data_, BSTNode* lchild_ = nullptr,
		BSTNode* rchild_ = nullptr, BSTNode* parent_ = nullptr) : 
		data(data_), lchild(lchild_), rchild(rchild_), parent(parent_) {}
};

template<typename T>
using BSTPtr = BSTNode<T>*;

template<typename T>
class BSTree {
private:
	BSTPtr root;
public:
	BSTree() : root(nullptr) {}
	~BSTree() { Destory(); }

	BSTPtr Search_Recursive(T data)
	{

	}

	BSTPtr Search_Iterator(T data)
	{

	}

	T MaxVal()
	{

	}

	T MinVal()
	{

	}

	void Insert(const T& e)
	{
		BSTPtr<T> pre = nullptr, cur = root;
		while (cur) {
			pre = cur;
			if (e < cur->data) {
				cur = cur->lchild;
			}
			else if(e > cur->data){
				cur = cur->rchild;
			}
			else {
				return;
			}
		}
		cur = new BSTNode<T>(e);

		if (!root) {
			root = cur;
		}
		else {
			if (e < pre->data) {
				pre->lchild = cur;
			}
			else {
				pre->rchild = cur;
			}
		}
		cur->parent = pre;
	}

	void Remove(const T& e)
	{

	}

	void Destory()
	{
		Destroy(root);
	}

	void Print()
	{

	}

private:

	BSTPtr<T> Search(BSTPtr<T> root, const T& e)
	{
		BSTPtr<T> cur = root;
		while (cur) {
			if (e < cur->data) {
				cur = cur->lchild;
			}
			else if (e > cur->data) {
				cur = cur->rchild;
			}
			else (e == cur->data) {
				return cur;
			}
		}
		return nullptr;
	}

	//ɾ������ʱ��Ҫ���丸�����ӽ��Ϊ�գ�������ֱ���øý��Ϊ��
	void Remove(BSTPtr root, const T& e)
	{
		BSTPtr<T> cur = Search(root, e);
		if (cur) {
			return;
		}
		//��ɾ�������Ҷ�ӽ��
		if (nullptr == cur->lchild && nullptr == cur->rchild) {
			//�����root��㣬ֱ��ɾ������root���Ҫ���丸����childΪnullptr
			if (cur == root) {
				if (cur == cur->parent->lchild) {
					cur->parent->lchild = nullptr;
				}
				else {
					cur->parent->rchild = nullptr;
				}
			}
			delete cur;
			cur = nullptr;
		}
		//��ɾ�����ֻ��������
		else if (nullptr == cur->lchild) {
			//���cur�Ǹ����
			if (cur == root) {
				root = cur->rchild;
			}
			else {
				if (cur == cur->parent->lchild) {
					cur->parent->lchild = cur->rchild;
				}
				else {
					cur->parent->rchild = cur->rchild;
				}
			}
			delete cur;
			cur = nullptr;
		}
		//��ɾ�����ֻ��������
		else if (nullptr == cur->rchild) {
			if (cur == root) {
				root = cur->lchild;
			}
			else {
				if (cur == cur->parent->lchild) {
					cur->parent->lchild = cur->lchild;
				}
				else {
					cur->parent->lchild = cur->rchild;
				}
			}
			delete cur;
			cur = nullptr;
		}
		//��ɾ���������������������
		else {
			//��Ҫ��ɾ���Ľ���øý�������������С���ֵ���
			BSTPtr<T> rmin = MinNode(cur->rchild);
			cur->data = rmin->data;
			//rmin��cur���Һ���
			if (rmin->parent == cur) {
				cur->rchild = nullptr;
			}
			//rmin��������ĳ��������
			else {
				rmin->parent->lchild = nullptr;
			}
			delete rmin;
		}
	}

	BSTPtr<T> DeleteNode(BSTPtr<T> root, const T& key)
	{
		if (nullptr == root) {
			return nullptr;
		}
		if (key < root->data) {
			root->lchild = DeleteNode(root->lchild, key);
		}
		else if (key > root->data) {
			root->rchild = DeleteNode(root->rchild, key);
		}
		else {
			//��Ҫ��ɾ������ֵ������������С����ֵ�滻
			if (nullptr != root->rchild) {
				root->data = MinVal(root->rchild);
				root->rchild = DeleteNode(root->rchild, root->data);
			}
			//������Ϊ�գ�������������
			else {
				BSTPtr<T> tmp = root->lchild;
				delete root;
				root = tmp;
			}
		}
		return root;
	}

	T MaxVal(BSTPtr<T> root)
	{

	}

	T MinVal(BSTPtr<T> root)
	{
		if (nullptr == root) {
			return 0;
		}
		return (nullptr != root->lchild) ? MinVal(root->lchild) : root->data;
	}

	BSTPtr<t> MinNode(BSTPtr<T> root)
	{
		//���׺���rootΪnullptr�����
		if (nullptr == root) {
			return nullptr;
		}
		return (nullptr != root->lchild) ? MinNode(root->lchild) : root;
	}

	void Destroy(BSTPtr<T>& root)
	{
		if (root) {
			Destory(root->lchild);
			Destory(root->rchild);
			delete root;
			root = nullptr;
		}
	}

};