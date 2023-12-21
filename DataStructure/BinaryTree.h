#pragma once

#include <unordered_map>

namespace DataStructure
{
	struct BinaryTreeNode
	{
		friend class BinaryTree;
	private:
		//BinaryTreeNode *Parent;
		BinaryTreeNode *LeftChild;
		BinaryTreeNode *RightChild;
		char Data;
	};

	enum  TraverseType
	{
		PreOrder = 0,
		InOrder = 1,
		PostOrder = 2,
	};

	class BinaryTree
	{
	public:
		BinaryTree();
		~BinaryTree();

		bool CreateByPreOrderAndInOrder( const std::string &preOrder, const std::string &inOrder );
		bool GetRoot( BinaryTreeNode *pRoot );
		void DFSTraverse( TraverseType traverseType );
		void BFSTraverse();

	private:
		void DFSTraverse( BinaryTreeNode *node, TraverseType traverseType );
		BinaryTreeNode *ConstructTree( const std::string &preOrder, const std::string &inOrder,
			int leftLimit, int rightLimit, int &preIndex,
			const std::unordered_map<char, int> &indexMap );

		BinaryTreeNode *m_pRoot;
	};
}
