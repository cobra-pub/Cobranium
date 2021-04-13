#pragma once

#include "Log.h"

#ifdef CE_PLATFORM_WINDOWS

extern CobraniumEngine::Application* CobraniumEngine::CreateApplication();


int main(int argc, char** argv)
{
	CobraniumEngine::Log::Init();
	CE_CORE_WARN("Intitialized Log!");
	int a = 5;
	CE_INFO("Intitialized Client Log! {0}", a);
	auto app = CobraniumEngine::CreateApplication();
	app->Run();
	delete app;

}

#endif