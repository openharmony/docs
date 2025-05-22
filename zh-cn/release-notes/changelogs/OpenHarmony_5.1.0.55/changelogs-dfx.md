# DFX子系统Changelog

## cl.dfx.1 用户态trace打点格式变更

**访问级别**

公开接口

**变更原因**

优化调整原有用户态trace打点格式，提高用户态trace打点格式的前向兼容性。

**变更影响**

此变更不涉及应用适配。

此变更涉及自研Trace解析工具适配，具体变更内容如表中所示。

变更前：taskId和count字段前的分隔符为空格。

变更后：各字段均使用竖线作为分隔符。

| 打点类型          | API_C接口                                                    | API_JS接口                                                   | 变更前打点格式        | 变更后打点格式         |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | --------------------- | ---------------------- |
| 开启异步Trace打点 | [OH_HiTrace_StartAsyncTrace](../../../application-dev/reference/apis-performance-analysis-kit/_hitrace.md#oh_hitrace_startasynctrace) | [startTrace](../../../application-dev/reference/apis-performance-analysis-kit/js-apis-hitracemeter.md#hitracemeterstarttrace) | S\|PID\|H:name taskId | S\|PID\|H:name\|taskId |
| 结束异步Trace打点 | [OH_HiTrace_FinshAsyncTrace](../../../application-dev/reference/apis-performance-analysis-kit/_hitrace.md#oh_hitrace_finishasynctrace) | [finshTrace](../../../application-dev/reference/apis-performance-analysis-kit/js-apis-hitracemeter.md#hitracemeterfinishtrace) | F\|PID\|H:name taskId | F\|PID\|H:name\|taskId |
| 整数Trace打点     | [OH_HiTrace_CountTrace](../../../application-dev/reference/apis-performance-analysis-kit/_hitrace.md#oh_hitrace_counttrace) | [traceByValue](../../../application-dev/reference/apis-performance-analysis-kit/js-apis-hitracemeter.md#hitracemetertracebyvalue) | C\|PID\|H:name count  | C\|PID\|H:name\|count  |

**用户态trace格式拓展规则**

对后续新增字段，将以**竖线+字段**的方式，追加在当前打点格式的末尾。

假设 `S|PID|H:name|taskId` 新增字段args1和args2，用户态trace格式变化如下所示。

- 原格式

  ```text
  S|PID|H:name|taskId
  ```

- 新增args1和args2字段后格式

  ```text
  S|PID|H:name|taskId|args1|args2
  ```

  **特殊场景说明**：因为后续新增字段并不是所有场景都会使用，所以实际字段值可能为空字符串，当有字段为空字符串时，trace格式变化如下所示。

  - args1为空字符串，args2不为空字符串

    ```text
    S|PID|H:name|taskId||args2
    ```

  - args1不为空字符串，args2为空字符串

    ```text
    S|PID|H:name|taskId|args1
    ```

  - args1和args2均为空字符串

    ```text
    S|PID|H:name|taskId
    ```

详细的用户态trace格式说明参考文档[hitracemeter-view](../../../application-dev/dfx/hitracemeter-view.md)。

**起始API Level**

- [OH_HiTrace_StartAsyncTrace](../../../application-dev/reference/apis-performance-analysis-kit/_hitrace.md#oh_hitrace_startasynctrace)：API 10

- [OH_HiTrace_FinshAsyncTrace](../../../application-dev/reference/apis-performance-analysis-kit/_hitrace.md#oh_hitrace_finishasynctrace)：API 10

- [OH_HiTrace_CountTrace](../../../application-dev/reference/apis-performance-analysis-kit/_hitrace.md#oh_hitrace_counttrace)：API 10
- [startTrace](../../../application-dev/reference/apis-performance-analysis-kit/js-apis-hitracemeter.md#hitracemeterstarttrace)：API 12
- [finshTrace](../../../application-dev/reference/apis-performance-analysis-kit/js-apis-hitracemeter.md#hitracemeterfinishtrace)：API 12
- [traceByValue](../../../application-dev/reference/apis-performance-analysis-kit/js-apis-hitracemeter.md#hitracemetertracebyvalue)：API 12

**变更发生版本**

从OpenHarmony SDK 5.1.0.55版本开始。

**变更的接口/组件**

- [OH_HiTrace_StartAsyncTrace](../../../application-dev/reference/apis-performance-analysis-kit/_hitrace.md#oh_hitrace_startasynctrace)

- [OH_HiTrace_FinshAsyncTrace](../../../application-dev/reference/apis-performance-analysis-kit/_hitrace.md#oh_hitrace_finishasynctrace)

- [OH_HiTrace_CountTrace](../../../application-dev/reference/apis-performance-analysis-kit/_hitrace.md#oh_hitrace_counttrace)
- [startTrace](../../../application-dev/reference/apis-performance-analysis-kit/js-apis-hitracemeter.md#hitracemeterstarttrace)
- [finshTrace](../../../application-dev/reference/apis-performance-analysis-kit/js-apis-hitracemeter.md#hitracemeterfinishtrace)
- [traceByValue](../../../application-dev/reference/apis-performance-analysis-kit/js-apis-hitracemeter.md#hitracemetertracebyvalue)

**适配指导**

默认行为变更，无需适配。

自研Trace解析工具可根据前述**变更影响**中对打点格式变更的介绍自行适配。