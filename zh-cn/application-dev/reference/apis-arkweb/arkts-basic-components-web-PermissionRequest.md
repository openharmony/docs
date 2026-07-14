# Class (PermissionRequest)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @qq_42700029-->
<!--Designer: @gzweioh-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

PermissionRequest 是 Web 组件用于授权或拒绝权限请求的对象。当网页尝试访问受保护的系统资源（如摄像头、麦克风、地理位置等）时，ArkWeb 内核会通过[onPermissionRequest](./arkts-basic-components-web-events.md#onpermissionrequest9)事件回调向应用发送权限请求，应用通过 PermissionRequest 对象来决定是否授权这些请求。该对象适用于需要在应用中管理网页对敏感资源的访问权限、保护用户隐私、确保资源访问安全可控等场景，帮助开发者灵活处理网页权限请求。

> **说明：**
>
> - 该组件首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本Class首批接口从API version 9开始支持。
>
> - 示例效果请以真机运行为准。

## constructor<sup>9+</sup>

constructor()

PermissionRequest的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## deny<sup>9+</sup>

deny(): void

拒绝网页所请求的权限。

**系统能力：** SystemCapability.Web.Webview.Core

## getOrigin<sup>9+</sup>

getOrigin(): string

获取网页来源。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明           |
| ------ | ------------ |
| string | 当前请求权限网页的来源。 |

## getAccessibleResource<sup>9+</sup>

getAccessibleResource(): Array\<string\>

获取网页所请求的权限资源列表，类型参考[ProtectedResourceType](./arkts-basic-components-web-e.md#protectedresourcetype9)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型              | 说明            |
| --------------- | ------------- |
| Array\<string\> | 网页所请求的权限资源列表。 |

## grant<sup>9+</sup>

grant(resources: Array\<string\>): void

对网页所请求的权限进行授权。

**互斥制约：**
- grant() 与 deny() 方法互斥，对于同一个 PermissionRequest 对象，只能调用其中一个方法。
- 调用 grant() 或 deny() 后，该 PermissionRequest 对象已完成响应，不允许重复调用。
- 未调用任何方法响应的 PermissionRequest 对象会导致权限请求超时。

**使用说明：**
- grant() 方法的 resources 参数通常使用 getAccessibleResource() 方法的返回值。
- 典型使用流程：调用 getAccessibleResource() 获取请求的资源列表，选择需要授权的资源后调用 grant() 进行授权。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名       | 类型            | 必填   | 说明            |
| --------- | --------------- | ---- | --------------- |
| resources | Array\<string\> | 是   | 网页被授予的权限资源列表，需通过 getAccessibleResource() 获取，类型参考[ProtectedResourceType](./arkts-basic-components-web-e.md#protectedresourcetype9)。传入该参数后，网页将获得对指定资源的访问权限，若传入空列表，则表示拒绝所有权限请求。 |