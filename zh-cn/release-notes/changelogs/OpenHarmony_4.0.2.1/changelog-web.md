# web子系统ChangeLog

OpenHarmony 4.0.2.1 版本相较于OpenHarmony 之前的版本，web的API变更如下。

## cl.web.1 postMessageEvent参数类型变更

该接口postMessageEvent原先仅支持string类型，从4.0.2.1版本开始新增支持ArrayBuffer类型。

**变更影响**

该接口变更前向兼容，基于此前版本开发的应用可继续使用接口，原有功能不受影响。

**关键的接口/组件变更**

- 涉及接口

  postMessageEvent(message: string): void

- 变更前：

  ```ts
  postMessageEvent(message: string): void
  ```

- 变更后：

  ```ts
  type WebMessage = ArrayBuffer | string
  postMessageEvent(message: WebMessage): void
  ```

**适配指导**

该接口变更前向兼容，基于此前版本开发的应用可继续使用接口，原有功能不受影响。

## cl.web.2 onMessageEvent参数类型变更

该接口onMessageEvent原先仅支持string类型，从4.0.2.1版本开始新增支持ArrayBuffer类型。

**变更影响**

该接口变更前向兼容，基于此前版本开发的应用可继续使用接口，增加相应的逻辑处理，原有功能不受影响。

**关键的接口/组件变更**

- 涉及接口

  onMessageEvent(callback: (result: string) => void): void

- 变更前：

  ```ts
  onMessageEvent(callback: (result: string) => void): void
  ```

- 变更后：

  ```ts
  type WebMessage = ArrayBuffer | string
  onMessageEvent(callback: (result: WebMessage) => void): void
  ```

**适配指导**

该接口变更前向兼容，基于此前版本开发的应用可继续使用接口，增加相应的逻辑处理，原有功能不受影响。