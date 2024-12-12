#pragma once

//-----------------------------------------------------
// Include Files
//-----------------------------------------------------
#include "GameEngine.h"

//-----------------------------------------------------
// MyClass Class									
//-----------------------------------------------------
class My3DModelConverter final
{
public:
	My3DModelConverter();				// Constructor
	~My3DModelConverter();				// Destructor

	// -------------------------
	// Copy/move constructors and assignment operators
	// -------------------------    
	My3DModelConverter(const My3DModelConverter& other)						= delete;
	My3DModelConverter(My3DModelConverter&& other) noexcept					= delete;
	My3DModelConverter& operator=(const My3DModelConverter& other)			= delete;
	My3DModelConverter& operator=(My3DModelConverter&& other)	noexcept	= delete;

	//-------------------------------------------------
	// Member functions						
	//-------------------------------------------------
	void SetString(tstring filePath);
	void OBJFileParser();
	void CreateBinaryFile();
	void ReadBinaryFile();

	struct Vertex
	{
		float xCoord, yCoord, zCoord;
	};
	struct Face
	{
		int idx1, idx2, idx3;
	};

private: 
	//-------------------------------------------------
	// Private member functions								
	//-------------------------------------------------


	//-------------------------------------------------
	// Datamembers								
	//-------------------------------------------------
	tstring m_filePath;

	std::vector<tstring> m_Comments{};
	std::vector<Vertex> m_Vertices{};
	std::vector<Face> m_Faces{};
};

 
