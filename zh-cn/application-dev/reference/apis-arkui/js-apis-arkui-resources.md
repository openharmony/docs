# arkui.component.resource

传入对应的资源信息构造Resource对象

> **说明：**
>
> 从API version 20开始支持。后续版本的新增形状，采用上角标单独标记形状的起始版本。
>
> 该部分仅在ArkTS1.2版本支持使用，由ui-plugin生成，不建议主动调用

## _r

用于根据资源信息构造[Resource](../apis-localization-kit/js-apis-resource-manager.md#resourcemanager)对象。相关资源信息由UI-Plugin根据开发者的[$r](../../quick-start/resource-categories-and-access.md)调用解析获得。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填 | 说明                   |
| ---------- | -------- | ---- | ---------------------- |
| id         | number   | 是   | 资源ID。               |
| type       | number   | 是   | 资源类型。             |
| bundleName | string   | 是   | 资源所在包名。         |
| moduleName | string   | 是   | 资源所在模块名。       |
| params     | Object[] | 是   | 开发者传入的剩余参数。 |

**返回值：**

| 类型                                                                             | 说明                             |
| -------------------------------------------------------------------------------- | -------------------------------- |
| [Resource](../apis-localization-kit/js-apis-resource-manager.md#resourcemanager) | Resource对象，包含资源相关信息。 |

## _rawfile

用于根据资源信息构造[Resource](../apis-localization-kit/js-apis-resource-manager.md#resourcemanager)对象。相关资源信息由UI-Plugin根据开发者的[$rawfile](../../quick-start/resource-categories-and-access.md)调用解析获得。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填 | 说明                   |
| ---------- | -------- | ---- | ---------------------- |
| id         | number   | 是   | 资源ID。               |
| type       | number   | 是   | 资源类型。             |
| bundleName | string   | 是   | 资源所在包名。         |
| moduleName | string   | 是   | 资源所在模块名。       |
| params     | Object[] | 是   | 开发者传入的剩余参数。 |

**返回值：**

| 类型                                                                             | 说明                             |
| -------------------------------------------------------------------------------- | -------------------------------- |
| [Resource](../apis-localization-kit/js-apis-resource-manager.md#resourcemanager) | Resource对象，包含资源相关信息。 |

**示例：**

```ts
import {
  Text,
  TextAttribute,
  Column,
  Component,
  Button,
  ButtonAttribute,
  ClickEvent,
  UserView,
  $r,
  $rawfile,
  Entry,
  Image
} from "@ohos.arkui.component"
import hilog from '@ohos.hilog'

@Entry
@Component
struct MyStateSample {
  build() {
    Column(undefined) {
      Text($r('app.string.app_name'))
      // 需要在resources/rawfile目录下放置对应文件。
      Image($rawfile('startIcon.png'))
    }
  }
}

```
