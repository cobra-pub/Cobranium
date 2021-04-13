#include "CEpch.h"
#include "Application.h"

#include "CobraniumEngine/Events/ApplicationEvent.h"
#include "CobraniumEngine/Log.h"

namespace CobraniumEngine
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		CE_TRACE(e);
		while (true);
	}
}