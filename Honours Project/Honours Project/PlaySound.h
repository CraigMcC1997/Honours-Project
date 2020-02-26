#ifndef SOUND
#define SOUND
#ifndef NOMINMAX
#define NOMINMAX

#pragma once
#include "bass.h"
#include <mmsystem.h>
#include <GL/glew.h>

namespace Sound {
	HSAMPLE loadSample(const char*, HSAMPLE);	//	load sound files
	void playSample(HSAMPLE sample);
};
#endif
#endif