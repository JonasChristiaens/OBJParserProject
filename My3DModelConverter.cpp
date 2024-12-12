//---------------------------
// Include Files
//---------------------------
#include "My3DModelConverter.h"
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;
//---------------------------
// Constructor & Destructor
//---------------------------
My3DModelConverter::My3DModelConverter():
	m_filePath{},
	m_Comments{},
	m_Vertices{},
	m_Faces{}
{
	// nothing to create
}

My3DModelConverter::~My3DModelConverter()
{
	// nothing to destroy
}

//---------------------------
// Member functions
//---------------------------

// Write member functions here

void My3DModelConverter::SetString(tstring filePath)
{
	m_filePath = filePath;
}

void My3DModelConverter::OBJFileParser()
{
	std::ifstream tempOBJ;
	tempOBJ.open(m_filePath, std::ios::in);
	

	if (!tempOBJ.is_open())
	{
		std::cout << "Could not open file: " << m_filePath.c_str() << std::endl;
	}
	else
	{
		std::string line;
		
		while (getline(tempOBJ, line))
		{
			if (line._Starts_with("#"))
			{
				m_Comments.push_back(std::filesystem::path(line).wstring());
			}
			else if (line._Starts_with("v"))
			{
				std::istringstream iss(line.substr(2));
				float x, y, z;

				iss >> x >> y >> z;
				m_Vertices.push_back({ x, y, z });
			}
			else if (line._Starts_with("f"))
			{
				std::istringstream iss(line.substr(2));
				int v1, v2, v3;

				iss >> v1 >> v2 >> v3;
				m_Faces.push_back({ v1, v2, v3 });
			}
		}
	}
}

void My3DModelConverter::CreateBinaryFile()
{
	std::ofstream binFile;
	binFile.open("Resources/BinaryBunny.bin", std::ios::out | std::ios::binary);

	if (!binFile.is_open())
	{
		std::cout << "Could not open binary file" << std::endl;
		return;
	}
	else
	{
		// writing comments to file
		for (const tstring& ts : m_Comments)
		{
			// write string content
			binFile.write(reinterpret_cast<const char*>(ts.c_str()), sizeof(ts));
			binFile.put(0xFF);
		}

		// writing  model vertices to file
		for (const Vertex& v : m_Vertices)
		{
			binFile.write(reinterpret_cast<const char*>(&v), sizeof(Vertex));
		}

		// writing model faces to file
		for (const Face& f : m_Faces)
		{
			binFile.write(reinterpret_cast<const char*>(&f), sizeof(Face));
		}

		binFile.close();
	}
}

void My3DModelConverter::ReadBinaryFile()
{
	std::ifstream binFile;
	binFile.open("Resources/BinaryBunny.bin", std::ios::binary);

	if (!binFile.is_open())
	{
		std::cout << "Could not open binary file" << std::endl;
		return;
	}
	else
	{
		m_Comments.clear();
		m_Vertices.clear();
		m_Faces.clear();

		// reading comments
		while (!binFile.eof())
		{

		}

		//reading vertices

		//reading faces
	}
}
