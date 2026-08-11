# 使用扩展的Node-API接口创建和销毁临界区作用域及访问字符串内容

<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

Node-API扩展接口`napi_open_critical_scope`用于打开临界区作用域，`napi_close_critical_scope`用于关闭临界区作用域。

> **注意**：
>
> 非临界接口不能在临界区作用域使用，且同一执行环境中只能打开一个临界区作用域。建议仅在需要临界接口时打开临界区作用域，使用后应及时关闭。

## 场景介绍

调用临界接口前，必须通过`napi_open_critical_scope`打开临界区作用域，并在临界区作用域内进行调用。

关闭临界区作用域后，请勿使用临界接口及其返回结果，否则可能导致程序崩溃或数据损坏。

## 临界区作用域的打开、关闭及临界接口的使用

| 接口                                           | 描述                                      | 临界区作用域外执行的状态码 |
| ---------------------------------------------- | ----------------------------------------- | -------------------------- |
| napi_open_critical_scope                       | 打开临界区作用域                          | NA                         |
| napi_close_critical_scope                      | 关闭临界区作用域                          | napi_generic_failure       |
| napi_get_buffer_string_utf16_in_critical_scope | 获取ArkTS String的UTF-16编码内存缓冲区数据 | napi_generic_failure       |

>**注意：**  
>
>1.当ArkTS String以UTF-16编码存储时，`napi_get_buffer_string_utf16_in_critical_scope`才能正确获取其内存缓冲区，否则该函数返回错误。
>  
>2.`napi_create_string_utf16`和`napi_create_string_utf8`的功能是将输入数据以指定编码传递给虚拟机。这些函数不控制字符串在虚拟机的内部存储编码方式。

## 示例代码

- 模块注册

   ```c++
   // napi_init.cpp
   #include <string>
   #include <string_view>
   #include <vector>

   #include "napi/native_api.h"

      // 使用C++的RAII机制管理临界区作用域，避免遗漏关闭
      // 仅用作示例，也可以通过其他方式进行封装，或直接使用原始接口
      class MyCriticalScope
   {
      napi_env env_{};
      napi_critical_scope scope_{};

   public:
      explicit MyCriticalScope(napi_env env) : env_(env)
      {
         if (napi_open_critical_scope(env, &scope_) != napi_ok)
         {
               // 失败时，进行一些必要的错误处理，或维护信息补充，此处省略。
               // 常见失败原因：env不是有效的Node-API执行上下文（如：env参数为nullptr）
         }
      }
      ~MyCriticalScope()
      {
         Close();
      }
      inline void Close()
      {
         if (scope_ == nullptr)
         {
               return;
         }
         // 在析构函数中，关闭临界区作用域
         if (napi_close_critical_scope(env_, scope_) != napi_ok)
         {
               // 失败时，进行一些必要的错误处理，或维护信息补充，此处省略。
               // 常见失败原因：
               // 1. 重复关闭临界区作用域。
               // 2. env不是有效的Node-API执行上下文（如：空指针）。
               // 3. scope不是有效的临界区作用域句柄（如：空指针）。
         }
         scope_ = nullptr;
      }
   };

   // 二次封装的方法，用于在获取ArkTS字符串底层缓冲区失败时，回落到拷贝
   static std::vector<char16_t> GetValueStringUtf16(napi_env env, napi_value value)
   {
      size_t strLength{};
      if (napi_get_value_string_utf16(env, value, nullptr, 0, &strLength) != napi_ok) {
         return {};
      }
      /* Node-API接口要求缓冲区长度大于字符串内容长度，用于写入C字符串结束标记。
       * 因此，需要获取完整字符串内容时，缓冲区大小应为字符串长度 + 1。
       */
      std::vector<char16_t> result(strLength + 1);
      if (napi_get_value_string_utf16(env, value, result.data(), result.size(), &strLength) != napi_ok) {
         return {};
      }
      return result;
   }

   static napi_value NAPI_Global_getBufferStringUtf16(napi_env env, napi_callback_info info)
   {
      napi_value args[1]{};
      size_t argc = 1;
      napi_get_cb_info(env, info, &argc, args, /* thisVar */ nullptr, /* data */ nullptr);
      // 传入参数小于要求的最低参数数量
      if (argc < 1) {
         return nullptr;
      }
      napi_valuetype argType;

      // 传入参数类型不是字符串
      if (napi_typeof(env, args[0], &argType) != napi_ok || argType != napi_string) {
         return nullptr;
      }

      uint32_t returnCode = 0;
      {
         [[maybe_unused]] MyCriticalScope scope(env);
         size_t bufSize{};
         const char16_t *buf{};
         std::vector<char16_t> copied{}; // 预留，用以获取缓冲区失败时回落
         std::u16string_view str;

         if (napi_get_buffer_string_utf16_in_critical_scope(env, args[0], &buf, &bufSize) == napi_ok)
         {
               str = std::u16string_view(buf, bufSize);
         } else {
               scope.Close();
               copied = GetValueStringUtf16(env, args[0]);
               str = std::u16string_view(copied.data(), copied.size());
               returnCode |= (1 << 1);
         }

         // do something with str
         if (str == u"测试字符串") {
               returnCode |= 1;
         }
      }

      napi_value returnResult{};
      napi_create_int32(env, returnCode, &returnResult);
      return returnResult;
   }

   // 模块注册
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
      std::vector<napi_property_descriptor> desc{{"getBufferStringUtf16", nullptr, NAPI_Global_getBufferStringUtf16,
                                                   nullptr, nullptr, nullptr, napi_default, nullptr}};
      napi_define_properties(env, exports, desc.size(), desc.data());
      return exports;
   }
   EXTERN_C_END

   static napi_module demoModule = {
      .nm_version = 1,
      .nm_flags = 0,
      .nm_filename = nullptr,
      .nm_register_func = Init,
      .nm_modname = "entry",
      .nm_priv = ((void *)0),
      .reserved = {0},
   };

   extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
   {
      napi_module_register(&demoModule);
   }
   ```

- 接口声明

   ```ts
   // index.d.ts
   export const getBufferStringUtf16: (str: string) => number;
   ```

- ArkTS代码示例

   ```ts
   // index.ets
   import testNapi from "libentry.so"

   const makeTest = (str: string) => {
      console.info(`status code of get buffer on "${str}": ${testNapi.getBufferStringUtf16(str)}`);
   }
   
   makeTest("hello world"); // 预期结果: 2或0
   makeTest("你好");        // 预期结果: 0或2
   makeTest("测试字符串");   // 预期结果: 1或3
   ```
