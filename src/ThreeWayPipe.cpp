#include "ThreeWayPipe.h"
ThreeWayPipe::ThreeWayPipe( sf::Vector2u loc)
	: BasePipe( loc)
{
	setTexture(Textures::instance().get_Textures(threeWayPipe_t));
}
