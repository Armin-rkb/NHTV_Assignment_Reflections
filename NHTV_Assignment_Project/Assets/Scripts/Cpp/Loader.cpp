#include "../Header/Loader.h"
#include "../Header/Textures.h"
#include <iostream>

using namespace std;
void InitLoader() { 
	printf("Init Called!");
	Textures tex = Textures();
	for (int i = 0; i < tex.texList.size(); i++) {
		cout << i+1 << endl;
	}
}