# web子系统ChangeLog

OpenHarmony 4.0.6.1 版本相较于OpenHarmony 之前的版本，web的API变更如下。

## cl.web.1 createWebMessagePorts接口参数

由于WebMessagePort需要新增支持更多数据类型，因此在该接口增加一个可选参数来区分新老接口。

**变更影响**

无，可选参数，可前向兼容。

**关键的接口/组件变更**

- 涉及接口

  createWebMessagePorts(): Array<WebMessagePort>;

- 变更前：

  ```ts
  createWebMessagePorts(): Array<WebMessagePort>;
  ```

- 变更后：

  ```ts
  createWebMessagePorts(isExtentionType?: boolean): Array<WebMessagePort>;
  ```

**适配指导**

已有应用无需适配。