#pragma once

#ifdef CE_PLATFORM_WINDOWS

extern CobraniumEngine::Application* CobraniumEngine::CreateApplication();


int main(int argc, char** argv)
{
	auto app = CobraniumEngine::CreateApplication();
	app->Run();
	delete app;

}

#endif