# 测试子系统ChangeLog

## cl.testfwk_arkxtest.1 WindowFilter窗口标志属性信息类接口名称变更

**访问级别**

公开接口

**变更原因**

该变更为兼容性变更，单词拼写错误整改。

**变更影响**

此变更影响@ohos.uitest提供的WindowFilter接口。用户此前在测试用例开发中使用了@ohos.uitest-api9 中WindowFilter接口的，需要进行适配才可以在新版本SDK环境正常编译通过。

**变更发生版本**

从OpenHarmony SDK 4.1.5.3开始。

**变更的接口/组件**

WindowFilter<sup>9+</sup>

变更前：

| 名称       | 类型    | 可读 | 可写 | 说明                       |
| ---------- | ------- | ---- | ---- | -------------------------- |
| bundleName | string  | 是   | 否   | 窗口归属应用的包名。       |
| title      | string  | 是   | 否   | 窗口的标题信息。           |
| focused    | boolean | 是   | 否   | 窗口是否处于获焦状态。     |
| actived    | boolean | 是   | 否   | 窗口是否正与用户进行交互。 |

变更后：

| 名称       | 类型    | 可读 | 可写 | 说明                       |
| ---------- | ------- | ---- | ---- | -------------------------- |
| bundleName | string  | 是   | 否   | 窗口归属应用的包名。       |
| title      | string  | 是   | 否   | 窗口的标题信息。           |
| focused    | boolean | 是   | 否   | 窗口是否处于获焦状态。     |
| active     | boolean | 是   | 否   | 窗口是否正与用户进行交互。 |

**适配指导**

需要使用active来替换actived.

## cl.testfwk_arkxtest.2 UiWindow.isActived接口废弃

**访问级别**

公开接口

**废弃原因**

接口能力增强。

**废弃影响**

此变更影响@ohos.uitest提供的UiWindow.isActived接口。用户此前在测试用例开发中使用了@ohos.uitest-api9 中UiWindow.isActived接口的，需要进行适配才可以在新版本SDK环境正常编译通过。

**废弃发生版本**

从OpenHarmony SDK 4.1.5.3开始。

**废弃的接口/组件**

|            接口声明            |               废弃说明               |           代替接口            |
| :----------------------------: | :----------------------------------: | :---------------------------: |
| isActived(): Promise<boolean>; | 使用isActive来判断窗口是否为交互窗口 | isActive(): Promise<boolean>; |

**适配指导**

需要使用isActive()来替换isActived().
