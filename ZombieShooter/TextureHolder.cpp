#include "TexureHolder.h"
#include <assert.h>
TextureHolder* TextureHolder::m_s_Instance = nullptr;
TextureHolder::TextureHolder() {
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}
Texture& TextureHolder::GetTexture(string const& filename) {
	//get a reference to m_Textures using m_s_Instance
	auto& m = m_s_Instance->m_Textures;
	//auto is the equivalent of map...
	//create an interator to hold a key-value-pair(kvp)
	//and seach requaired kvp
	//using the passes in the file name
	auto keyValuePair = m.find(filename);
	// auto is equivalent of map<string, Texture>::iterator

	// did we find a match
	if (keyValuePair != m.end()) {
		return keyValuePair->second;
	}
	else {
	//if file not found
		//create anew key value pair using filename
		auto& texture = m[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}