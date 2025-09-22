# Resource
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @fangzhiyuan1-->
<!--Designer: @fangzhiyuan1-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

Provides APIs for accessing application and system resource information. For details about resource types and usage, see [Resource Classification and Access](../../quick-start/resource-categories-and-access.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 

## $r

$r(value: string, ...params: any[]): Resource

Obtains application or system resource information. During compilation, the toolchain converts $r into a [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) object. For details about how to access application or system resources using \$r, see [Resource Categories and Access](../../quick-start/resource-categories-and-access.md).

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| **Description**                                                                                                                                                                                                                                                                                                                                                                                             |
| ------ | ------ | ---- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| value  | string | Yes  | Resource identifier in the format *belonging.type.name*.<br>**belonging**: resource type. The value can be sys, app, or [hsp_name].<br>**type**: resource type. The value can be boolean, color, float, intarray, integer, pattern, plural, strarray, string, or media.<br>**name**: resource name. Application resource names are defined in the project's **resources** directory. For details about system resource names, see [Resource Categories and Access](../../quick-start/resource-categories-and-access.md).|
| ...params | any[]  | No  | Additional parameters passed by you.                                                                                                                                                                                                                                                                                                                                                                           |

**Return value**

| Type                             | Description                                                      |
| --------------------------------- | ---------------------------------------------------------- |
| [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) | Resource object containing the package name, module name, resource ID, and more.|

**Example**:

```ts
@Entry
@Component
struct Page {
  build() {
    Row() {
      Column() {
        Text($r('app.string.app_name'))
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

For details about how to access resources in the HSP package, see [Cross-HAP/HSP Resources](../../quick-start/resource-categories-and-access.md#cross-haphsp-resources).

## $rawfile

$rawfile(value: string): Resource

Obtains resource information in the rawfile directory of a project. $rawfile is converted into a [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) object by the toolchain during compilation. For details about how to access application resources or system resources through \$rawfile, see [Resource Categories and Access](../../quick-start/resource-categories-and-access.md).

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                                                                                                                                                                                                                                                                                                                                                             |
| ------ | ------ | ---- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| value  | string | Yes  | Relative path in the rawfile directory. The file name must contain an extension, and the path cannot start with a slash (/).|

**Return value**

| Type                             | Description                                                      |
| --------------------------------- | ---------------------------------------------------------- |
| [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) | Resource object containing the package name, module name, resource ID, and more.|

```ts
// Add startIcon.png to the src/main/resources/rawfile directory.

@Entry
@Component
struct Page {
  build() {
    Row() {
      Column() {
        Image($rawfile("startIcon.png"))
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

For details about how to access resources in an HSP package, see [Cross-HAP/HSP Resources](../../quick-start/resource-categories-and-access.md#cross-haphsp-resources).
