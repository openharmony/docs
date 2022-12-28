# 时间时区子系统ChangeLog

## cl.time.1 接口异常抛出变更

时间时区子系统定时器接口异常抛出：202非系统应用异常和401参数无效异常。

**变更影响**

该接口变更前向兼容，基于此前版本开发的应用可继续使用接口，增加相应的异常处理，原有功能不受影响。

**关键接口/组件变更**

变更前：
  - 接口异常抛出message，无错误码。

变更后：
  - 接口异常抛出message和code，包括202非系统应用异常和401参数无效异常。

    | 模块名            | 类名        | 方法/属性/枚举/常量                                          | 变更类型 |
    | ----------------- | ----------- | ------------------------------------------------------------ | -------- |
    | @ohos.systemTimer | systemTimer | function createTimer(options: TimerOptions, callback: AsyncCallback<number>): void | 变更     |
    | @ohos.systemTimer | systemTimer | function createTimer(options: TimerOptions): Promise<number> | 变更     |
    | @ohos.systemTimer | systemTimer | function startTimer(timer: number, triggerTime: number, callback: AsyncCallback<void>): void | 变更     |
    | @ohos.systemTimer | systemTimer | function startTimer(timer: number, triggerTime: number): Promise<void> | 变更     |
    | @ohos.systemTimer | systemTimer | function stopTimer(timer: number, callback: AsyncCallback<void>): void | 变更     |
    | @ohos.systemTimer | systemTimer | function stopTimer(timer: number): Promise<void>             | 变更     |
    | @ohos.systemTimer | systemTimer | function destroyTimer(timer: number, callback: AsyncCallback<void>): void | 变更     |
    | @ohos.systemTimer | systemTimer | function destroyTimer(timer: number): Promise<void>          | 变更     |

    

