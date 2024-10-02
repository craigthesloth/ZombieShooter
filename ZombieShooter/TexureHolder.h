#pragma once
#ifndef TEXTURE_HOLDER_H

#define TEXURE_HOLDER_H
#include <SFML/Graphics.hpp>
#include <map>
using namespace sf;
using namespace std;
class TextureHolder {
private:
	//map container from STL
	//it holds related pairs of string and texre
	map<string, Texture> m_Textures;
	//a pointer pf the same type as the class itself
	//the one and only instance
	static TextureHolder* m_s_Instance;
public:
	TextureHolder();
	static Texture& GetTexture(string const& filename);
};
#endif 