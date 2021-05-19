#include "CurvedPipe.h"
CurvedPipe::CurvedPipe(sf::Vector2f size, sf::Vector2f pos)
	: BasePipe(size, pos)
{
	setTexture(Textures::instance().get_Textures(curvedPipe_t));
}
