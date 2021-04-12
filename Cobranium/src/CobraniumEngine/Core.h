#pragma once


#ifdef CE_PLATFORM_WINDOWS
	#ifdef CE_BUILD_DLL
		#define COBRANIUM_API __declspec(dllexport)
	#else
		#define COBRANIUM_API __declspec(dllimport)
	#endif
#else
	#error CobraniumEngine only supports Windows!
#endif