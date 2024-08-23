//
// Created by admin on 2024/8/23.
//

#pragma once

#include "WindowBase.hpp"

class TrayMenuWindow : public WindowBase
{
public:
	
	explicit TrayMenuWindow(WallpaperEngineProgram &program, Anasul::Icon *icon, Anasul::Icon *iconSm);

public:
	
	void Tick() override;
	
};
	

