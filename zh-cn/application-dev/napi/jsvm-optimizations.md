# JSVM 通用调优实践

## JSVM 调用结构

小程序使用 JSVM 执行 JS 代码的过程大概可以分为 native, JSVM-API, JSVM 三层:

- native: 小程序运行 JS 的逻辑层, 使用 JSVM 提供的接口完成 JS 代码编译, 运行, code cache 生成等操作的逻辑排布和组合
- JSVM-API: 连接 native 和 v8 的接口兼容层, 保持对不同版本 JS 引擎的兼容, 提供 JS 引擎标准化的使用实践
- JSVM: JS 引擎层, 负责 JS 代码实际的编译运行

使用 JSVM 的过程中, 可能由于各种原因产生一些不必要的开销导致启动变慢, 其中的原因可以从以上三层的角度进行拆分。

## 提升启动速度

对于使用 JSVM 的应用启动场景，我们可以区分冷热启动用于分别进行不同的优化。
首先是冷启动，是没有任何 profile 或者 cache 可以用于优化的场景，通常是首次启动；
热启动则是已经充分预热，在多次启动之后获取了足量用于优化的 cache 的场景。

### 减少 JS 引擎层的开销

引擎层的开销很大的一部分来源于编译, 通过合理调整调用 JSVM-API 时传入的选项, 可以减少主线程上 JS 引擎的编译开销，
以下面的编译接口为例，其中 eagerCompile 这个参数的开关可以调控编译行为，通过在不同的启动场景打开这个选项可以实现优化效果。

```cpp
/**
 * ...
 * @param eagerCompile: Whether to compile the script eagerly.
 * ...
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CompileScript(JSVM_Env env,
                                              JSVM_Value script,
                                              const uint8_t* cachedData,
                                              size_t cacheDataLength,
                                              bool eagerCompile, // 开启全量编译
                                              bool* cacheRejected,
                                              JSVM_Script* result);
```

同时 code cache 的生成和使用也会对编译产生影响，这部分可以参考 [使用 code cache 加速编译](use-jsvm-about-code-cache.md)

#### 热启动: 生成足够多的 code cache

热启动场景下, 我们会在热启动前生成 code cache 以减少编译带来的开销. 这个时候生成的 code cache 的覆盖率会影响 code cache 对热启动的优化效果。

有一个简单的策略可以生成足量的 code cache, 就是在生成 code cache 前的那次编译打开 `eager compile` 选项, 这样 v8 会在编译时进行全量的编译, 这样生成 code cache 一定是全量的。

这个方法会带来额外的编译时间开销, 可能影响冷启动的时间, 这一点会在下面对 native 层的冷启动优化方法中提到。

#### 冷启动: 使用 lazy compile 代替 eager compile

在冷启动时, `eager compile` 会增加不必要的编译时间. 这其中主要的原因是没有拿到 v8 lazy compile 优化效果: v8 会将不在必经路径上的函数推迟编译, 在实际运行到的时候才进行编译, 这样会减少一些不被运行到函数的编译, 从而优化冷启动的时间。

因此在冷启动时, 会阻塞主线程的部分可以关闭 `eager compile` 选项, 从而拿到足够的冷启动优化效果。

### 在 native 层减少时间开销
#### 冷启动: 减少 code cache 的影响

上面在考虑减少 v8 层开销的时候, 提到了为了热启动的性能可以开启 `eager compile` 进行编译, 而为了冷启动性能却又需要关闭 `eager compile` 选项, 看起来是矛盾的. 为了解决这个矛盾, 避免在冷热启动性能上的权衡, 关键点是在 code cache 生成本身。

首先 code cache 的生成是需要前置的编译的, 其次生成 code cache 本身也存在开销；

那么在 native 层, 要解决冷启动和生成 code cache 之间的矛盾, 首先我们可以另起一个线程用于生成 code cache, 这样避免了生成 code cache 这个操作本身对冷启动的影响；

然后, 有两个方法可以参考:

- 将生成 code cache 必需的前置编译也放到新增的线程上, 这样编译选项可以分开使用: 生成 code cache 打开 `eager compile`, 冷启动运行则关闭, 这样做的缺点是可能进一步提高运行时的峰值资源占用, 优点是 code cache 生成和运行可以完全解耦, 不再需要考虑生成 code cache 的时间点. 这个流程的伪代码如下所示

```
async_create_code_cache() {
  compile_with_eager_compile();
  create_code_cache();
  save_code_cache();
}

...

if (has_code_cache) {
  evaluate_script_with_code_cache();
} else {
  start_thread(async_create_code_cache());
  evaluate_script_without_code_cache();
}
```


- 在启动过程中的所有路径运行完之后, 再启动新线程生成 code cache, 这样不必使用 `eager compile` 也能获取足量的 code cache, 同时保证热启动性能不受影响, 这样做的缺点是生成 code cache 的时间点受限, 优点是峰值资源占用相对更少, 且不必生成过量的 code cache 导致 io 变慢。这个流程可以用如下所示的伪代码来表示

```
async_create_code_cache() {
  compile_with_out_eager_compile();
  create_code_cache();
  save_code_cache();
}

...

if (has_code_cache) {
  evaluate_script_with_code_cache();
} else {
  evaluate_script_without_code_cache();
}

...

if (script_run_completed) {
  start_thread(async_create_code_cache());
}
```


### 使用更高效的 JSVM-API

在能达到相同效果时, 使用更高效的 JSVM-API 是简单有效的性能优化方法, 以下实践是在优化实践过程中发现的一些例子

#### 使用 IsXXX 代替 TypeOf

过去发现, 针对仅需要判断对象原生类型的场景, 存在一种相对低效的使用方法:

从 OH_JSVM_TypeOf 接口获取对象类型后，再判断是否与某个类型相同。

这种方法需要先查询 object 的类型, 这种方法相对于直接使用 is 方法会更慢, 因此我们新增了针对基础类型的 IsXXX 系列方法, 用更高效的接口代替了相对低效的接口。

- 低效用例


```cpp
bool Test::IsFunction() const {
    HandleScopeInit(*env);
    JSVM_Value jsvmValue;
    ObjectWrappingGet(*env, jsvmRef, jsvmValue);
    // type judement start
    bool result;
    JSVM_ValueType valueType;
    OH_JSVM_TypeOf(*env, jsvmValue, &valueType);
    OH_JSVM_CloseHandleScope(*env, scope);
    result = (valueType == JSVM_FUNCTION)
    // type judement end
    return result;
}
```

- 高效用例


```cpp
bool Test::IsFunction() const {
    HandleScopeInit(*env);
    JSVM_Value jsvmValue;
    ObjectWrappingGet(*env, jsvmRef, jsvmValue);
    // type judement start
    bool result;
    OH_JSVM_IsFunction(*env, jsvmValue, &result); // 可直接判断是否为Function类型
    OH_JSVM_CloseHandleScope(*env, scope);
    // type judement end
    return result;
}
```

以某生态应用小程序场景为例, 这个优化可以带来的性能收益端到端有 150ms, 总占比约 5%。

#### 直接使用 OH_JSVM_CreateReference, 避免创建冗余的 object

过去存在这样一种创建 reference 的路径:

创建一个新的 object -> 设置 object 的值 -> 创建 object 的 reference。

这种在已经有值的情况下创建一个新的 object 的操作是冗余的, 直接创建对值的引用即可。

- 低效用例

```cpp
// (1) open handle scope
JSVM_HandleScope scope;
OH_JSVM_OpenHandleScope(*env, &scope);
// (2) get JSVM_Value
JSVM_Value jsvmValue;
OH_JSVM_GetNull(*env, &jsvmValue);
// (3) create and store Reference for JSVM_Value
JSVM_Value wrappingObject;
OH_JSVM_CreateObject(*env, &wrappingObject);
OH_JSVM_SetElement(*env, wrappingObject, 1, jsvmValue);
OH_JSVM_CreateReference(*env, wrappingObject, 1, &result->p_member->jsvmRef);
// (4) close handle scope
OH_JSVM_CloseHandleScope(*env, scope);
```

- 高效用例

```cpp
// (1) open handle scope
JSVM_HandleScope scope;
OH_JSVM_OpenHandleScope(*env, &scope);
// (2) get JSVM_Value
JSVM_Value jsvmValue;
OH_JSVM_GetNull(*env, &jsvmValue);
// (3) create and store Reference for JSVM_Value
OH_JSVM_CreateReference(*env, jsvmValue, 1, &result->p_member->jsvmRef); // 可从任意对象类型直接创建Reference，代码更为简洁高效
// (4) close handle scope
OH_JSVM_CloseHandleScope(*env, scope);
```

同样以某生态应用小程序场景为例, 这个改动减少了大量冗余的接口调用，最终带来的端到端时间收益有 100+ms, 约 3%。
