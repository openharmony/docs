# Resource

传入对应的资源信息构造Resource对象。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块仅适用于ArkTS 1.2。
>
> _r和_rawfile由UI-Plugin生成，不建议主动调用。

## _r

_r(id: number, type: number, bundleName: string, moduleName: string, ...params: Object[]): Resource

用于根据资源信息构造[Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9)对象。相关资源信息由UI-Plugin根据开发者的[（$r）](../../quick-start/resource-categories-and-access.md#资源访问)调用解析获得。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填 | 说明                   |
| ---------- | -------- | ---- | ---------------------- |
| id         | number   | 是   | 资源ID。               |
| type       | number   | 是   | 资源类型。             |
| bundleName | string   | 是   | 资源所在包名。         |
| moduleName | string   | 是   | 资源所在模块名。       |
| ...params  | Object[] | 否   | 开发者传入的剩余参数。 |

**返回值：**

| 类型                                                                             | 说明                             |
| -------------------------------------------------------------------------------- | -------------------------------- |
| [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) | Resource对象，包含资源相关信息。 |

## _rawfile

_rawfile(id: number, type: number, bundleName: string, moduleName: string, ...params: Object[]): Resource

用于根据资源信息构造[Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9)对象。相关资源信息由UI-Plugin根据开发者的[（$rawfile）](../../quick-start/resource-categories-and-access.md#资源访问)调用解析获得。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填 | 说明                   |
| ---------- | -------- | ---- | ---------------------- |
| id         | number   | 是   | 资源ID。               |
| type       | number   | 是   | 资源类型。             |
| bundleName | string   | 是   | 资源所在包名。         |
| moduleName | string   | 是   | 资源所在模块名。       |
| ...params     | Object[] | 否   | 开发者传入的剩余参数。 |

**返回值：**

| 类型                                                                             | 说明                             |
| -------------------------------------------------------------------------------- | -------------------------------- |
| [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) | Resource对象，包含资源相关信息。 |

**示例：**

```ts
import {
  Text,
  Column,
  Component,
  $r,
  $rawfile,
  Entry,
  Image
} from '@kit.ArkUI';

@Entry
@Component
struct MyStateSample {
  build() {
    Column() {
      Text($r('app.string.app_name'))
      // 需要在resources/rawfile目录下放置对应文件。
      Image($rawfile('startIcon.png'))
    }
  }
}

```
