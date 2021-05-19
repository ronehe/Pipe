#pragma once
#include "BasePipe.h"
#include "Textures.h"

class CurvedPipe : public BasePipe {
public:
	using BasePipe::BasePipe;
	CurvedPipe() { setTexture(Textures::instance().get_Textures(curvedPipe_t)); }//constarctor gets size and color
};