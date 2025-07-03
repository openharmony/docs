# 开发说明

API参考主要用于开发者查阅应用开发相关的各类API说明。为了方便开发者使用API文档，对文档描述中的常用字段进行说明。

## 版本说明

API参考采用两种方式标记组件或接口开始支持的版本号：

- 对于新增组件或接口，会在章节开头进行说明，如：本模块首批接口从API version 7开始支持。
- 对于某个已有组件或接口的新增特性，会在对应特性后进行标注，如：“uid<sup>8+</sup>”表示从API Version 8开始支持属性uid。

## 系统能力说明

系统能力（SystemCapability，简称SysCap），指操作系统中每一个相对独立的特性。不同的设备对应不同的系统能力集，每个系统能力对应多个接口。开发者可根据系统能力来判断是否可以使用某接口。具体可参考[系统能力SystemCapability使用指南](syscap.md)。

文档在每一个接口描述中说明了接口的系统能力，如：**系统能力**：SystemCapability.xxx.xxx

<!--Del-->
- 通过[系统能力SystemCapability列表](phone-syscap-list.md)，可以速查具体能力集支持的设备。<!--DelEnd-->
- 系统提供了canIUse接口，可用于[判断API是否可以使用](syscap.md#判断-api-是否可以使用)。
- 相同的系统能力，在不同的设备下，也会有能力的差异。开发者可以进行[不同设备相同能力的差异检查](syscap.md#不同设备相同能力的差异检查)。
<!--RP2--><!--RP2End-->

<!--RP1--><!--RP1End-->

## 服务卡片说明

将应用/元服务的重要信息或操作前置到[服务卡片](../form/formkit-overview.md)（简称“卡片”），可达到服务直达、减少跳转层级的体验效果。
- 对于支持在ArkTS服务卡片中使用的接口，将会添加“**卡片能力**”的标记： 从API version x开始，该接口支持在ArkTS卡片中使用。
- 如果接口不支持在ArkTS服务卡片中使用，则不做特殊说明。

## 权限说明

默认情况下，应用只能访问有限的系统资源。但某些情况下，应用为了扩展功能的诉求，需要访问额外的系统或其他应用的数据（包括用户个人数据）、功能。具体可参考[访问控制开发概述](../security/AccessToken/app-permission-mgmt-overview.md)。

当调用接口访问这些资源时，需要申请对应的权限。申请方式可参考[访问控制开发指导](../security/AccessToken/determine-application-mode.md)。

- 如果应用需要具备某个权限才能调用该接口，会在具体的接口描述中说明：**需要权限**：ohos.permission.xxxx
- 如果应用不需要任何权限即可调用该接口，则不做特殊说明。

## 错误码使用说明

ArkTS API在使用过程中，可能会遇到错误。

在可能出现错误的各个接口处，开发者可参考文档中提供的**错误码**部分，了解对应接口可能出现的错误码ID及错误信息，并根据需要进行处理。

当前ArkTS API分为异步接口和同步接口，以下为对应的错误处理方式：

- 针对同步接口，错误统一通过异常形式抛出，开发者需要通过try-catch的方式处理可能抛出的异常。

- 针对异步接口，错误可能包括异常和rejection，开发者若使用await/async方式，需要通过try-catch的方式处理可能抛出的异常和rejection。

- 针对异步接口，错误可能包括异常和rejection，开发者若使用Promise方式，需要通过try-catch的方式处理同步抛出的异常（一般为401异常），并通过Promise的catch()方法或then()方法中的onrejected回调函数处理rejection。

- 针对callback形式的异步接口（不推荐使用），错误可能包括异常和回调返回的错误，开发者若使用callback方式，需要通过try-catch的方式处理同步抛出的异常（一般为401异常），并处理通过回调参数呈现的错误（即BusinessError对象）。

## 应用模型说明

随着系统的演进发展，先后提供了两种应用模型，FA模型和Stage模型。

- 如果某个模块的接口仅支持其中一种模型，会在文档开头说明：本模块接口仅可在FA模型/Stage模型下使用。
- 如果某个接口仅支持其中一种模型，会在具体的接口描述中说明：此接口仅可在FA模型/Stage模型下使用。
- 如两种框架模型均支持，则不做特殊说明。

<!--Del-->
## 系统接口说明

OpenHarmony中提供的接口，部分是仅供OEM厂商使用的system api，普通应用无法使用。

针对这种情况，在文档中会进行系统接口的声明：

- 如果某个模块的接口均为system api，会在文档开头说明：该模块接口为系统接口。
- 如果某个接口为system api，会在具体的接口描述中说明：此接口为系统接口。

普通应用即在HarmonyAppProvision配置文件中应用程序类型为hos_normal_app的应用。工程新建时，该字段默认为hos_normal_app。

随DevEco下载的SDK为public-SDK，不包括系统接口。如需使用系统接口，需要：

- 参考[full-SDK替换指南](../faqs/full-sdk-switch-guide.md)将SDK替换为full-SDK。
- 参考[HarmonyAppProvision配置文件的说明](../security/app-provision-structure.md)修改HarmonyAppProvision配置文件中的app-feature字段为hos_system_app（系统应用）。
<!--DelEnd-->

## 废弃接口说明

废弃接口会使用上标“<sup>deprecated</sup>”标注，表示该接口不再推荐使用。

废弃接口均会标注废弃起始版本，从废弃版本起的5个API level仍可以兼容使用，但不推荐此行为。

- 对于有标注替代接口的，建议开发者查看新接口的文档，尽早适配。
- 如果没有替代接口，建议开发者参考废弃说明和变更说明（changelog）更换实现方式。
