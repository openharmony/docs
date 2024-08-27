# 使用 code cache 加速编译

## code cache 简介

JSVM 提供了生成并使用 code cache 加速编译过程的方法, 其获取和使用分为下面几个部分:

- 首先使用 compile 系列接口编译得到 JSVM_Script
- 使用 OH_JSVM_CreateCodeCache 接口, 传入编译完成后生成的 JSVM_Script
- 将 OH_JSVM_CreateCodeCache 生成的 code cache 保存, 等待下一次编译时, 作为参数传递给 compile 系列接口

通过上述流程, 将会在使用 code cache 的那次编译中, 极大减少编译时间, 其原理为将编译完成的 script 序列化, 然后使用 code cache 编译时就不再需要重新解析/编译已经被序列化的函数, 只需要进行一次反序列化即可, 编译就简化为了一次数据读取。

## 场景示例

下面的伪代码是一个典型的使用方法, 其中第二次编译, 如果 cacheRejected 的值没有被置为 true, 那么说明 code cache 使用成功, 这次运行将会极大加快。

其中使用到的 JSVM-API 可以参考 [JSVM-API 简介](../reference/common/_j_s_v_m.md), 这里仅展示调用的步骤。

```c++

JSVM_Env env;

...

using namespace std;
static string src = R"JS(
const concat = (...args) => args.reduce((a, b) => a + b);
throw new Error("exception triggered")
)JS";

// 编译参数准备
JSVM_Value jsSrc;
JSVM_Script script;
size_t length = 0;
const uint8_t* dataPtr = nullptr,
bool cacheRejected = false;

// 生成 code cache
{
	JSVM_HandleScope handleScope;
	OH_JSVM_OpenHandleScope(env, &handleScope);

	// 源码字符串转换为 js 字符串
	OH_JSVM_CreateStringUtf8(env, src.c_str(), src.size(), &jsSrc);

	// 编译js代码
	OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script);

	// 执行js代码
	JSVM_Value result;
	OH_JSVM_RunScript(env, script, &result);

	if (dataPtr && lengthPtr && *dataPtr == nullptr) {
	    // 将js源码编译出的脚本保存到 cache, 可以避免重复编译, 带来性能提升
	    OH_JSVM_CreateCodeCache(env, script, dataPtr, lengthPtr);
	}

	OH_JSVM_CloseHandleScope(env, handleScope);
}

// 使用 code cache
{
	JSVM_HandleScope handleScope;
	OH_JSVM_OpenHandleScope(env, &handleScope);

	// 源码字符串转换为 js 字符串
	OH_JSVM_CreateStringUtf8(env, src.c_str(), src.size(), &jsSrc);

	// 使用 code cache 编译js代码
	OH_JSVM_CompileScript(env, jsSrc, dataPtr, length, true, &cacheRejected, &script);

	// 执行js代码
	JSVM_Value result;
	OH_JSVM_RunScript(env, script, &result);

	OH_JSVM_CloseHandleScope(env, handleScope);
}
```
