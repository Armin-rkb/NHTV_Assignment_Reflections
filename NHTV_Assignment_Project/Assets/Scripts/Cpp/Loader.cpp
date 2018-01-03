#include "../Header/Loader.h"
#include "../Header/Textures.h"
#include <iostream>

using namespace std;
void InitLoader() { 
	printf("Loader Called!");
	Textures tex = Textures();
	
	for (auto i : tex.texList) {
		i.loadFromFile(tex.playerTexturePath);
	}
}