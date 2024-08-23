//
// Created by admin on 2024/8/23.
//

#pragma once

#include "WindowBase.hpp"

class WallpaperWindow : public WindowBase
{
public:
	
	explicit WallpaperWindow(WallpaperEngineProgram &program, Anasul::Icon *icon, Anasul::Icon *iconSm);

public:
	
	void Tick() override;
	
};

