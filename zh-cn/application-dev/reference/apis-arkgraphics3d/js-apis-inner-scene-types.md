# SceneType
本模块提供3D图形中常用的数据类型。

> **说明：** 
> - 本模块首批接口从API version 12开始支持，后续版本的新增接口，采用上角标标记接口的起始版本。

## 导入模块
```ts
import { Vec2, Vec3, Vec4, Color, Rect, Quaternion, Aabb, Position3, Rotation3,
  Scale3 } from '@kit.ArkGraphics3D';
```

## Vec2
二维向量，通常用于表示2D空间中的点或方向，由x和y两个分量组成。

**系统能力：** SystemCapability.ArkUi.Graphics3D
| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| x | number | 否 | 否 | x轴分量，取值范围是实数。 |
| y | number | 否 | 否 | y轴分量，取值范围是实数。|

## Vec3
三维向量，通常用于表示3D空间中的点、方向或向量变换，由x、y和z三个分量组成。

**系统能力：** SystemCapability.ArkUi.Graphics3D
| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| x | number | 否 | 否 | x轴分量，取值范围是实数。 |
| y | number | 否 | 否 | y轴分量，取值范围是实数。 |
| z | number | 否 | 否 | z轴分量，取值范围是实数。 |

## Vec4
四维向量，通常用于表示4D空间中的点、方向或向量变换，由x、y、z和w四个分量组成，增加第四个分量为各种计算和变换增加了规整性和便捷性。

**系统能力：** SystemCapability.ArkUi.Graphics3D
| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| x | number | 否 | 否 | x轴分量，取值范围是实数。 |
| y | number | 否 | 否 | y轴分量，取值范围是实数。 |
| z | number | 否 | 否 | z轴分量，取值范围是实数。 |
| w | number | 否 | 否 | w轴分量，取值范围是实数。 |

## Quaternion
用于表示3D空间中旋转的数学结构。与传统的欧拉角相比，四元数在数值稳定性和避免万向节锁方面具有优势。

**系统能力：** SystemCapability.ArkUi.Graphics3D
| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| x | number | 否 | 否 | x轴分量，取值范围是实数。 |
| y | number | 否 | 否 | y轴分量，取值范围是实数。 |
| z | number | 否 | 否 | z轴分量，取值范围是实数。 |
| w | number | 否 | 否 | w轴分量，取值范围是实数。 |

## Aabb
轴对齐边界盒，主要用于判断空间中的物体是否重叠。

**系统能力：** SystemCapability.ArkUi.Graphics3D
| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| aabbMin | [Vec3](#vec3) | 否 | 否 | 轴对齐边界盒的小值点。 |
| aabbMax | [Vec3](#vec3) | 否 | 否 | 轴对齐边界盒的大值点。 |

## Color
用于表示RGBA格式的颜色，包含四个分量，依次为红色、绿色、蓝色和透明度。

**系统能力：** SystemCapability.ArkUi.Graphics3D
| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| r | number | 否 | 否 | 红色分量，取值范围是[0, 1]。 |
| g | number | 否 | 否 | 绿色分量，取值范围是[0, 1]。 |
| b | number | 否 | 否 | 蓝色分量，取值范围是[0, 1]。 |
| a | number | 否 | 否 | 透明度分量，取值范围是[0, 1]。 |

## Rect
用于表示平面中的矩形。

**系统能力：** SystemCapability.ArkUi.Graphics3D
| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| x | number | 否 | 否 | 矩形左下角x轴分量，取值范围是实数。 |
| y | number | 否 | 否 | 矩形左下角y轴分量，取值范围是实数。 |
| width | number | 否 | 否 | 矩形宽度，有效取值范围大于0。 |
| height | number | 否 | 否 | 矩形高度，有效取值范围大于0。 |

## Position3
type Position3 = Vec3

用于表示3维空间中物体的位置，是[Vec3](#vec3)类型。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 类型  | 说明 |
| ---- | ---- |
| [Vec3](#vec3) | 类型为三维向量，可取任意值。 |

## Rotation3
type Rotation3 = Vec3

用于表示3维空间中物体的旋转，是[Vec3](#vec3)类型。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 类型  | 说明 |
| ---- | ---- |
| [Vec3](#vec3) | 类型为三维向量，可取任意值。 |

## Scale3
type Scale3 = Vec3

用于表示3维空间中物体的缩放，是[Vec3](#vec3)类型。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 类型 | 说明 |
| ---- | ---- |
| [Vec3](#vec3) | 类型为三维向量，可取任意值。 |
