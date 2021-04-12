#include <Cobranium.h>


class Sandbox : public CobraniumEngine::Application
{
public:
	Sandbox()
	{}
	~Sandbox()
	{}
};

CobraniumEngine::Application* CobraniumEngine::CreateApplication()
{
	return new Sandbox();
}