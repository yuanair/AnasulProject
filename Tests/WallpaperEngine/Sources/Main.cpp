#include "./WallpaperEngineProgram.hpp"

Anasul::Program &AnasulMain()
{
	static WallpaperEngineProgram program;
	return program;
}

#include <Anasul/Main.hpp>