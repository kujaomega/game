#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "includes.h"
#include "texture.h"

class TextureManager
{

	typedef struct
	{
		void *context;
		char *file;
	} arg;

public:
	~TextureManager();
	static TextureManager* getInst();
	static void freeMemory();
	Texture* fetch(std::string name);
	void load(std::string file);
	bool isLoaded(std::string name);
	std::map<std::string,Texture*> textures;

private:
	static TextureManager *singleton;
	TextureManager();
	TextureManager(TextureManager const&){};
	TextureManager& operator=(TextureManager const&){};
};
 
#endif
