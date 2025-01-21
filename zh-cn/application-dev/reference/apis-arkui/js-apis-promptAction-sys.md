# @ohos.promptAction (弹窗)(系统接口)

创建并显示文本提示框、对话框和操作菜单。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.promptAction (弹窗)](js-apis-promptAction.md)。

## 导入模块

```ts
import { promptAction } from '@kit.ArkUI';
```

### ToastShowMode

设置弹窗显示模式，默认显示在应用内，支持显示在应用之上。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full。

| 名称     | 值   | 说明                   |
| -------- | ---- | ---------------------- |
| SYSTEM_TOP_MOST | 2    | Toast 显示在TYPE_SYSTEM_TOAST类型窗口中。 |
