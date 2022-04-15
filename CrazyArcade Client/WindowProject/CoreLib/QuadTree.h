#pragma once
#include "Node.h"
#include "Tile.h"

class QuadTree
{
private:
	Node*			m_pRootNode;
	queue<Node*>	m_QuadTreeQueue;
	vector<RECT>	m_rtLeafNodePoint;
	int				m_iMaxDepth;			// �� ���� ����� ����( ���� ) ����
	int				m_iNodeCount;
	LONG			m_lWidth;
	LONG			m_lHeight;
public:
	//--------------------------------------------------------------------------------------
	// Create Node
	//--------------------------------------------------------------------------------------
	Node*			CreateNode(Node* pParent, RECT rect);
	//--------------------------------------------------------------------------------------
	// Delete Node
	//--------------------------------------------------------------------------------------
	bool			DeleteNode(Node* pNode);
	//--------------------------------------------------------------------------------------
	// Build
	//--------------------------------------------------------------------------------------
	bool			Build(LONG lWidth, LONG lHeight);
	//--------------------------------------------------------------------------------------
	// Create QuadTree
	//--------------------------------------------------------------------------------------
	bool			BuildTree(Node* pNode);
	//--------------------------------------------------------------------------------------
	// Divide space
	//--------------------------------------------------------------------------------------
	bool			SubDivide(Node* pNode);
	//--------------------------------------------------------------------------------------
	// Find node
	//--------------------------------------------------------------------------------------
	Node*			FindNodeInQuadTree(RECT rect);
	Node*			FindNodeInQuadTree(POINT_F vPos);
	//--------------------------------------------------------------------------------------
	// Set tile and item information in the map in the quadtree
	//--------------------------------------------------------------------------------------
	bool			SetMapTilesInfoToQuadtree(vector<Tile*> tileList, map<int, Item*> itemMap);
	//--------------------------------------------------------------------------------------
	// Transform the quad tree to match the tile characteristics of the map
	//--------------------------------------------------------------------------------------
	bool			ConvertQuadtreeToMapTileInfo();
	//--------------------------------------------------------------------------------------
	// Add object in quadtree
	//--------------------------------------------------------------------------------------
	bool			AddInQuadTree(Node* pNode, Object* pObject);
	//--------------------------------------------------------------------------------------
	// Delete an object from the list of objects in a node
	//--------------------------------------------------------------------------------------
	bool			DeleteObject(Node* pNode, Object* pObject);
	//--------------------------------------------------------------------------------------
	// Update
	//--------------------------------------------------------------------------------------
	Node*			UpdateQuadTree(Object* pObject, POINT_F vPrevPos);
	Node*			UpdateQuadTree(Object* pObject, RECT rtCurrent, RECT rtNext);
	//--------------------------------------------------------------------------------------
	// Release
	//--------------------------------------------------------------------------------------
	bool			Release();
	//--------------------------------------------------------------------------------------
	// Get Function
	//--------------------------------------------------------------------------------------
	Node*			GetRootNode();
	vector<RECT>	GetLeafNodePosition();	
public:
	QuadTree();
	~QuadTree();
};
