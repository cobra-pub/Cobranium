workspace "Cobranium"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Cobranium"
	location "Cobranium"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "CEpch.h"
	pchsource "Cobranium/src/CEpch.cpp"

	files
	{
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"	
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"CE_PLATFORM_WINDOWS",
			"CE_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "CE_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "CE_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "CE_DIST"
		symbols "On"
		
	
	

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"	
	}
	
	includedirs
	{
		"Cobranium/vendor/spdlog/include",
		"Cobranium/src"
	}
	
	links
	{
		"Cobranium"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"CE_PLATFORM_WINDOWS",
		}
		
		
	filter "configurations:Debug"
		defines "CE_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "CE_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "CE_DIST"
		symbols "On"