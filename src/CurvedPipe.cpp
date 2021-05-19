#include "CurvedPipe.h"
CurvedPipe::CurvedPipe(sf::Vector2f size, sf::Vector2u loc)
	: BasePipe(size, loc)
{
	setTexture(Textures::instance().get_Textures(curvedPipe_t));
}
