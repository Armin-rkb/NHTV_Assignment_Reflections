#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <list>
using namespace std;
using namespace sf;
class Textures
{
public:
	Textures();
	~Textures();
	string playerTexturePath;
	Texture playerTexture;
	list<Texture> texList;
};
