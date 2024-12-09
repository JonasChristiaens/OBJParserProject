#pragma once

//-----------------------------------------------------
// Include Files
//-----------------------------------------------------


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



private: 
	//-------------------------------------------------
	// Private member functions								
	//-------------------------------------------------


	//-------------------------------------------------
	// Datamembers								
	//-------------------------------------------------

	
};

 
