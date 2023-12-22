# arkui子系统ChangeLog

## cl.arkui.1 Image组件的draggable接口不支持在ArkTS卡片上使用

**变更级别**

公开接口

**变更原因**

根据ArkTS卡片能力范围跟限制说明，Image组件的draggable接口不支持在ArkTS卡片上使用，应该去掉@form标签。

**变更影响**

该变更为非兼容性变更。删除Image组件的draggable接口标记的@form标签后，开发者不能在ArkTS卡片上使用Image组件的draggable接口。

**API级别**

从API9开始。

**变更的接口/组件**

修改前，Image组件的draggable接口有@form标签。

修改后，Image组件的draggable接口去掉@form标签不支持在ArkTS上使用。

**适配指导**

变更前后，Image组件的draggable接口均不支持在ArkTS卡片上使用，开发者无需适配。