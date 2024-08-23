//
// Created by admin on 2024/8/23.
//

#include "IconFactory.hpp"

#include "Windows/WindowsIcon.hpp"

namespace Anasul
{
	Icon *IconFactory::Create(IconType type)
	{
		switch (type)
		{
			case IconType::Default:
			case IconType::Windows:
				return new WindowsIcon();
			default:
				return nullptr;
		}
	}
} // Anasul