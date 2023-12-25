#include <iostream>
#include <unordered_map>
#include "TypeDefine.h"

#include "BinaryTree.h"

namespace DataStructure
{

	BinaryTree::BinaryTree()
	{
		m_pRoot = nullptr;
	}

	BinaryTree::~BinaryTree()
	{
		Clear( m_pRoot );
	}

	bool BinaryTree::CreateByPreOrderAndInOrder( const std::string &preOrder, const std::string &inOrder )
	{

		if( preOrder.length() == 0 || preOrder.length() != inOrder.length() ) {
			return false;
		}

		// Map to store indices of inorder traversal elements
		std::unordered_map<char, int> indexMap;
		for( int i = 0; i < inOrder.length(); ++i ) {
			indexMap[ inOrder[ i ] ] = i;
		}

		int preIndex = 0; // To keep track of the current index in preorder traversal
		m_pRoot = ConstructTree( preOrder, inOrder, 0, inOrder.length() - 1, preIndex, indexMap );

		return true;
	}

	BinaryTreeNode *BinaryTree::ConstructTree( const std::string &preOrder, const std::string &inOrder,
		int leftLimit, int rightLimit, int &preIndex,
		const std::unordered_map<char, int> &indexMap )
	{
		if( leftLimit > rightLimit ) {
			return nullptr;
		}

		// Create a new node with the current data from preorder traversal
		BinaryTreeNode *pNode = new BinaryTreeNode();
		pNode->Data = preOrder[ preIndex++ ];

		// Find the index of the current node in inorder traversal
		int inIndex = indexMap.at( pNode->Data );

		// Recursively construct left and right subtrees
		pNode->LeftChild = ConstructTree( preOrder, inOrder, leftLimit, inIndex - 1, preIndex, indexMap );
		pNode->RightChild = ConstructTree( preOrder, inOrder, inIndex + 1, rightLimit, preIndex, indexMap );

		return pNode;
	}

	bool BinaryTree::GetRoot( BinaryTreeNode *pRoot )
	{
		if( !m_pRoot ) {
			return false;
		}
		pRoot = m_pRoot;
		return true;
	}

	void BinaryTree::DFSTraverse( TraverseType traverseType )
	{
		DFSTraverse( m_pRoot, traverseType );
	}

	void BinaryTree::DFSTraverse( BinaryTreeNode *node, TraverseType traverseType )
	{
		if( node == nullptr ) {
			return;
		}

		if( traverseType == TraverseType::PreOrder ) {
			std::cout << node->Data << ",";
		}
		DFSTraverse( node->LeftChild, traverseType );
		if( traverseType == TraverseType::InOrder ) {
			std::cout << node->Data << ",";
		}
		DFSTraverse( node->RightChild, traverseType );
		if( traverseType == TraverseType::PostOrder ) {
			std::cout << node->Data << ",";
		}
	}

	void BinaryTree::BFSTraverse()
	{
		// TODO: BFS
	}

	void BinaryTree::Clear( BinaryTreeNode *node )
	{
		if( node == nullptr ) {
			return;
		}
		Clear( node->LeftChild );
		Clear( node->RightChild );
		delete node;
	}
}
