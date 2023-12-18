#ifndef CLRWARPPER_H
#define CLRWARPPER_H

#include "nethost.h"
#include "coreclr_delegates.h"
#include "hostfxr.h"



//再额外导入一些之后会用到的头文件
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#ifdef WINDOWS 
#include <Windows.h>

#define STR(s) L ## s
#define CH(c) L ## c
#define DIR_SEPARATOR L'\\'

#define string_compare wcscmp

#else 
#include <dlfcn.h>
#include <limits.h>

#define STR(s) s
#define CH(c) c
#define DIR_SEPARATOR '/'
#define MAX_PATH PATH_MAX
#define string_compare strcmp

#endif


using string_t = std::basic_string<char_t>;

namespace
{
	// 保存hostfxr导出的全局参数
	hostfxr_initialize_for_dotnet_command_line_fn init_for_cmd_line_fptr;
	hostfxr_initialize_for_runtime_config_fn init_for_config_fptr;
	hostfxr_get_runtime_delegate_fn get_delegate_fptr;
	hostfxr_run_app_fn run_app_fptr;
	hostfxr_close_fn close_fptr;
	bool loaded_hostfxr = false;
	// 提前声明
	bool load_hostfxr(const char_t* app); //用于加载hostfxr
	//加载程序集
	load_assembly_and_get_function_pointer_fn get_dotnet_load_assembly(const char_t* assembly);

	void* load_library(const char_t*);
	void* get_export(void*, const char*);
}

namespace
{
	struct DllInfo
	{
		string_t runtimeConfigPath;  //xxx.runtimeConfig.json
		string_t dllPath;         //xxx/xx/xxx.dll
		string_t dotnetType;     //Namespace.class , AssemblyName
		string_t dotnetTypeMethod;  //MethodName
	};

	void InitCLRAndGetFunc(const DllInfo& info, component_entry_point_fn& func);

}

#endif // !CLRWARPPER_H
