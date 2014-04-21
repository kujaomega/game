#include "meshmanager.h"

MeshManager *MeshManager::singleton=NULL;

MeshManager *MeshManager::getInst()
{
	if (!singleton) singleton=new MeshManager();

	return singleton;
}

void MeshManager::freeMemory()
{
	if (singleton)
	{
		delete singleton;
		singleton=NULL;
	}
}

MeshManager::~MeshManager()
{
	for (std::map<std::string,Mesh*>::iterator it=meshes.begin();
		it!=meshes.end();++it)
	delete (*it).second;
}

MeshManager::MeshManager()
{
};

void MeshManager::load(std::string filename)
{
	if (isLoaded(Mesh::getName(filename))) return;

	Mesh *mesh=new Mesh();
	bool found=mesh->loadMesh(filename);
	if (!found)
	{
		PRINTERROR("MeshManager::load(...)","Mesh "+filename+" not found!");
		exit(1);
	}
	else meshes[mesh->name]=mesh;
	PRINTINFO("MeshManager::load(...)","Mesh "+Mesh::getName(filename)+" loaded! ("+filename+")");
}

Mesh *MeshManager::fetch(std::string name)
{
	if (isLoaded(name)) return meshes[name];
	else return NULL;
}

bool MeshManager::isLoaded(std::string name)
{
	return meshes.count(name);
}
