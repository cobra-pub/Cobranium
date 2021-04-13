#pragma once



#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace CobraniumEngine
{
	class COBRANIUM_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};


}

// Core log macros
#define CE_CORE_TRACE(...)   ::CobraniumEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CE_CORE_ERROR(...)   ::CobraniumEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CE_CORE_WARN(...)    ::CobraniumEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CE_CORE_INFO(...)    ::CobraniumEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CE_CORE_FATAL(...)   ::CobraniumEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CE_TRACE(...)   ::CobraniumEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CE_ERROR(...)   ::CobraniumEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CE_WARN(...)    ::CobraniumEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CE_INFO(...)    ::CobraniumEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CE_FATAL(...)   ::CobraniumEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
