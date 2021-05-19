
#include "StraightPipe.h"
StraightPipe::StraightPipe( sf::Vector2u loc)
	: BasePipe( loc)
{
	setTexture(Textures::instance().get_Textures(straightPipe_t));
}
