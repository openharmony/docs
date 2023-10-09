# 上传下载子系统ChangeLog

OpenHarmony 4.1.2.3版本相较于OpenHarmony 4.0 版本，request子系统的API变更如下

## cl.request.1 部分接口移除错误码 21900005 task mode error

- 对于 on('progress'), on('complete'), on('failed'), off('progress'), off('complete'), off('failed'), pause, resume 这几个接口，之前仅对前台任务生效，现在这些接口对于前后台任务都可以生效了，调用这些接口不再可能会返回错误码 21900005 task mode error。

**变更影响**

基于此前版本开发的应用，可能需要适配变更后的错误码，否则可能会影响原有业务逻辑。

**关键的接口/组件变更**

| 模块名          | 类名           | 方法/属性/枚举/常量                                                                                                           | 变更类型      |
|--------------|--------------|--------------------------------------------------------------------------------------------------|--------------|
| ohos.request | Task      | on(event: 'progress', callback: (progress: Progress) => void): void;                                         | 修改 |
| ohos.request | Task      | off(event: 'progress', callback?: (progress: Progress) => void): void;                                       | 修改 |
| ohos.request | Task      | on(event: 'completed', callback: (progress: Progress) => void): void;                                      | 修改 |
| ohos.request | Task      | off(event: 'completed', callback?: (progress: Progress) => void): void;                                    | 修改 |
| ohos.request | Task      | on(event: 'failed', callback: (progress: Progress) => void): void;                                              | 修改 |
| ohos.request | Task      | off(event: 'failed', callback?: (progress: Progress) => void): void;                                            | 修改 |
| ohos.request | Task      | pause(callback: AsyncCallback<void>): void;                                                                         | 修改 |
| ohos.request | Task      | pause(): Promise<void>;                                                                                                       | 修改 |
| ohos.request | Task      | resume(callback: AsyncCallback<void>): void;                                                                       | 修改 |
| ohos.request | Task      | resume(): Promise<void>;                                                                                                     | 修改 |

**适配指导**

本次修改仅涉及错误码修改，其余行为不变。