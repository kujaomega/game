#ifndef MESHMANAGER_H
#define MESHMANAGER_H

#include "includes.h"
#include "mesh.h"

class MeshManager
{

public:
	~MeshManager();
	static MeshManager *getInst();
	static void freeMemory();
	void load(std::string filename);
	Mesh *fetch(std::string name);
	bool isLoaded(std::string name);

private:
	static MeshManager *singleton;
	std::map<std::string,Mesh*> meshes;

	MeshManager();
	MeshManager(MeshManager const&){};
	MeshManager& operator=(MeshManager const&){};
};

#endif
