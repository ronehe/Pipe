#include "CurvedPipe.h"
CurvedPipe::CurvedPipe( sf::Vector2u loc)
	: BasePipe( loc)
{
	setTexture(Textures::instance().get_Textures(curvedPipe_t));
}
