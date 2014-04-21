#include "texturemanager.h"

TextureManager *TextureManager::singleton=NULL;

TextureManager *TextureManager::getInst()
{
	if (!singleton) singleton=new TextureManager();
	return singleton;
}

void TextureManager::freeMemory()
{
	if (singleton)
	{
		delete singleton;
		singleton=NULL;
	}
}

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

Texture *TextureManager::fetch(std::string name)
{
	if (isLoaded(name)) return textures[name];
	else return NULL;
}

void TextureManager::load(std::string file)
{
	Texture *t=new Texture();
	if (t->load(file.c_str())==false)
	{
		//PRINTERROR("TextureManager::load(...)","texture "+t->filename+" not found!");
		exit(1);
	}
	
	//textures[t->name]=t;
	//PRINTINFO("TextureManager::load(...)","texture "+t->filename+" loaded!");
}

bool TextureManager::isLoaded(std::string name)
{
	return textures.count(name);
}
