#pragma once
#include "Tile.h"
#include "QuadTree.h"

class Map :public Object
{
private:
	vector<Tile*>		m_pTileList;
	map<int, Item*>		m_ItemMap;
	//map<int, eItemType>	m_ItemSpawnInfo;
	Tile*				m_pPostRenderTile;
	QuadTree			m_QuadTree;
public:
	//--------------------------------------------------------------------------------------
	// Create Map Function
	//--------------------------------------------------------------------------------------
	bool				CreateMap();
	//--------------------------------------------------------------------------------------
	// Create Tile Map Function
	//--------------------------------------------------------------------------------------
	bool				CreateTileMap();
	//--------------------------------------------------------------------------------------
	// Create QuadTree Function
	//--------------------------------------------------------------------------------------
	bool				CreateQuadTree();
	//--------------------------------------------------------------------------------------
	// Create item
	//--------------------------------------------------------------------------------------
	bool				CreateItemInMap();
	//--------------------------------------------------------------------------------------
	// Create Wireframe Function
	//--------------------------------------------------------------------------------------
	bool				CreateWireframe();
	//--------------------------------------------------------------------------------------
	// Update map
	//--------------------------------------------------------------------------------------
	void				UpdateMap();
	//--------------------------------------------------------------------------------------
	// Update tile
	//--------------------------------------------------------------------------------------
	void				UpdateTile();
	//--------------------------------------------------------------------------------------
	// Update item
	//--------------------------------------------------------------------------------------
	void				UpdateItem();
	//--------------------------------------------------------------------------------------
	// Update render map
	//--------------------------------------------------------------------------------------
	void				UpdateRenderMap();
	//--------------------------------------------------------------------------------------
	// Update render tile
	//--------------------------------------------------------------------------------------
	void				UpdateRenderTile();
	//--------------------------------------------------------------------------------------
	// Update render item
	//--------------------------------------------------------------------------------------
	void				UpdateRenderItem();
	//--------------------------------------------------------------------------------------
	// Update render position
	//--------------------------------------------------------------------------------------
	void				UpdateRenderPosition() override;
	//--------------------------------------------------------------------------------------
	// Delete tile
	//--------------------------------------------------------------------------------------
	bool				DeleteTile(int index);
	//--------------------------------------------------------------------------------------
	// Activate item
	//--------------------------------------------------------------------------------------
	void				ActivateItem(int index);
	//--------------------------------------------------------------------------------------
	// Set function
	//--------------------------------------------------------------------------------------
	void				InsertItemSpawnInfo(const int index, const eItemType itemType);
	//--------------------------------------------------------------------------------------
	// Get function
	//--------------------------------------------------------------------------------------
	vector<Tile*>&		GetTileList();
	QuadTree&			GetQuadTree();
	//--------------------------------------------------------------------------------------
	// Developer Redefinition Function
	//--------------------------------------------------------------------------------------
	bool				Init();
	bool				Frame();
	bool				PreRender();
	bool				PostRender();
	bool				Release();
	//--------------------------------------------------------------------------------------
	// Network
	//--------------------------------------------------------------------------------------
	bool				NetworkCreateItemInMap();
public:
	Map();
	~Map();
};

