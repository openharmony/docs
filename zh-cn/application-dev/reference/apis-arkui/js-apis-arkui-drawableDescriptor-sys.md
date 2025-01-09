# @ohos.arkui.drawableDescriptor (DrawableDescriptor)(系统接口)

本模块提供获取pixelMap的能力，包括前景、背景、蒙版和分层图标。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.arkui.drawableDescriptor (DrawableDescriptor)](js-apis-arkui-drawableDescriptor.md)

## 导入模块

```ts
import { DrawableDescriptor, LayeredDrawableDescriptor } from '@kit.ArkUI';
```

## DrawableDescriptor

### constructor

constructor()

创建DrawableDescriptor或LayeredDrawableDescriptor对象。对象构造需要使用全球化接口[getDrawableDescriptor](../apis-localization-kit/js-apis-resource-manager.md#getdrawabledescriptor)或[getDrawableDescriptorByName](../apis-localization-kit/js-apis-resource-manager.md#getdrawabledescriptorbyname)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

