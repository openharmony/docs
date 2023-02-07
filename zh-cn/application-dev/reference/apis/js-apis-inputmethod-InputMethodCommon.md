# InputMethodCommon

> **说明：**
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

输入法框架接口定义的公共属性信息。

## Direction

光标移动方向类型枚举。

 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework

| 名称         | 值   | 说明       |
| ------------ | ---- | ---------- |
| CURSOR_UP    | 1    | 光标上移。 |
| CURSOR_DOWN  | 2    | 光标下移。 |
| CURSOR_LEFT  | 3    | 光标左移。 |
| CURSOR_RIGHT | 4    | 光标右移。 |

## Range

描述选中文本的范围。

 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework

| 名称  | 类型   | 可读 | 可写 | 说明                               |
| ----- | ------ | ---- | ---- | ---------------------------------- |
| start | string | 是   | 是   | 选中文本的首字符在编辑框的索引值。 |
| end   | string | 是   | 是   | 选中文本的末字符在编辑框的索引值。 |

## Movement

描述进行选中文本动作时光标移动的方向。

 **系统能力:** SystemCapability.MiscServices.InputMethodFramework

| 名称      | 类型                    | 可读 | 可写 | 说明                               |
| --------- | ----------------------- | ---- | ---- | ---------------------------------- |
| direction | [Direction](#direction) | 是   | 是   | 进行选中文本动作时光标移动的方向。 |

