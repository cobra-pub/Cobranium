#pragma once

#include "Core.h"

namespace CobraniumEngine
{
	class COBRANIUM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}
