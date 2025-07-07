# compatibleComponent (ArkTS1.2)(系统接口)

compatibleComponent是用于在ArkTS1.2中引用ArkTS1.1自定义组件的占位组件。

>**说明：**
>
>compatibleComponent模块首批接口从API version 20开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>当前页面仅包含compatibleComponent模块的系统接口，无公开接口。

## compatibleComponent

compatibleComponent(init: CompatibleInitCallback, update: CompatibleUpdateCallback): void

在ArkTS1.2中引用ArkTS1.1自定义组件的占位组件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|init     | [CompatibleInitCallback](#compatibleinitcallback)   |是   |初始化占位组件的回调函数。    |
|update   | [CompatibleUpdateCallback](#compatibleupdatecallback)  |是   |更新占位组件的回调函数。   |



## CompatibleInitCallback

type CompatibleInitCallback = () => CompatibleComponentInfo

初始化占位组件的回调函数类型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

|类型   |说明       |
|-----------|--------------|
|[CompatibleComponentInfo](#compatiblecomponentinfo)  |占位组件的信息。 |



## CompatibleUpdateCallback

type CompatibleUpdateCallback = (component: ESValue) => void

更新占位组件的回调函数类型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|component   |[ESValue](../../../quick-start/arkts-interop-overview.md#esvalue)   |是   |在ArkTS1.1上下文创建的自定义组件对象。    |



## CompatibleComponentInfo

interface CompatibleComponentInfo {
  name: string;
  component: ESValue;
}

在ArkTS1.1中创建的自定义组件对象的信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

|名称   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|name     |string   |是   |在ArkTS1.1中创建的自定义组件对象的名称。    |
|component   |[ESValue](../../../quick-start/arkts-interop-overview.md#esvalue)   |是   |在ArkTS1.1中创建的自定义组件对象。    |


