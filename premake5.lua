
workspace "ImGui"-- 工作区
	architecture "x86_64"
	startproject "ImGuiCode"

	configurations{"Debug","Release"}-- 编译配置

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"-- 输出的文件名

-- 存放以后将要引用的include文件位置
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/thirdparty/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/thirdparty/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/thirdparty/imgui"
IncludeDir["glm"] = "%{wks.location}/thirdparty/glm"
IncludeDir["stb_image"] = "%{wks.location}/thirdparty/stb_image"
IncludeDir["ImGuizmo"] = "%{wks.location}/thirdparty/ImGuizmo"

group "Dependencies"
    include "thirdparty/GLFW"
    include "thirdparty/Glad"
    include "thirdparty/imgui"
group ""

project "ImGuiCode"
	kind "ConsoleApp"-- 静态库
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	-- 设置编译后二进制目标的目标目录
	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	-- 设置构建项目时放置对象和其他中间文件的目录
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp",
        "thirdparty/stb_image/**.h",
		"thirdparty/stb_image/**.cpp",
		"thirdparty/glm/glm/**.hpp",
		"thirdparty/glm/glm/**.inl",
        "thirdparty/ImGuizmo/ImGuizmo.h",
		"thirdparty/ImGuizmo/ImGuizmo.cpp"
	}

	defines
	{
        "_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"src",
        "%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.ImGuizmo}"
	}

    links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}