# SceneType
The SceneType module provides common data types in 3D graphics.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import
```ts
import { Vec2, Vec3, Vec4, Color, Rect, Quaternion, Aabb, Position3, Rotation3,
  Scale3 } from '@kit.ArkGraphics3D';
```

## Vec2
A two-dimensional vector used to represent a point or a direction in 2D space. It consists of two components: x and y.

**System capability**: SystemCapability.ArkUi.Graphics3D
| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| x | number | No| No| Component on the X axis. The value is a real number.|
| y | number | No| No| Component on the Y axis. The value is a real number.|

## Vec3
A three-dimensional vector used to represent a point, a direction, or a vector transformation in 3D space. It consists of three components: x, y, and z.

**System capability**: SystemCapability.ArkUi.Graphics3D
| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| x | number | No| No| Component on the X axis. The value is a real number.|
| y | number | No| No| Component on the Y axis. The value is a real number.|
| z | number | No| No| Component on the Z axis. The value is a real number.|

## Vec4
A four-dimensional vector used to represent a point, a direction, or a vector transformation in 4D space. It consists of four components: x, y, z, and w. The fourth component (w) enhances normalization and convenience for various calculations and transformations.

**System capability**: SystemCapability.ArkUi.Graphics3D
| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| x | number | No| No| Component on the X axis. The value is a real number.|
| y | number | No| No| Component on the Y axis. The value is a real number.|
| z | number | No| No| Component on the Z axis. The value is a real number.|
| w | number | No| No| Component on the W axis. The value is a real number.|

## Quaternion
A mathematical notation for representing spatial rotations of elements in 3D space. Compared with Euler angles, a quaternion has advantages in numerical stability and avoiding the gimbal lock problem.

**System capability**: SystemCapability.ArkUi.Graphics3D
| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| x | number | No| No| Component on the X axis. The value is a real number.|
| y | number | No| No| Component on the Y axis. The value is a real number.|
| z | number | No| No| Component on the Z axis. The value is a real number.|
| w | number | No| No| Component on the W axis. The value is a real number.|

## Aabb
Axis aligned boundary box used to determine whether two objects in space are overlapping.

**System capability**: SystemCapability.ArkUi.Graphics3D
| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| aabbMin | [Vec3](#vec3) | No| No| Minimum bounds of the AABB.|
| aabbMax | [Vec3](#vec3) | No| No| Maximum bounds of the AABB.|

## Color
Color in RGBA format. It consists of four components: red, green, blue, and alpha.

**System capability**: SystemCapability.ArkUi.Graphics3D
| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| r | number | No| No| Red component. The value range is [0, 1].|
| g | number | No| No| Green component. The value range is [0, 1].|
| b | number | No| No| Blue component. The value range is [0, 1].|
| a | number | No| No| Alpha component. The value range is [0, 1].|

## Rect
Rectangle in a plane.

**System capability**: SystemCapability.ArkUi.Graphics3D
| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| x | number | No| No| X axis component in the lower left corner of the rectangle. The value is a real number.|
| y | number | No| No| Y axis component in the lower left corner of the rectangle. The value is a real number.|
| width | number | No| No| Width of the rectangle. The value must be greater than 0.|
| height | number | No| No| Height of the rectangle. The value must be greater than 0.|

## Position3
type Position3 = Vec3

Position of an object in 3D space. The value is of the [Vec3](#vec3) type.

**System capability**: SystemCapability.ArkUi.Graphics3D

| Type | Description|
| ---- | ---- |
| [Vec3](#vec3) | Any 3D vector.|

## Rotation3
type Rotation3 = Vec3

Rotation of an object in 3D space. It is of the [Vec3](#vec3) type.

**System capability**: SystemCapability.ArkUi.Graphics3D

| Type | Description|
| ---- | ---- |
| [Vec3](#vec3) | Any 3D vector.|

## Scale3
type Scale3 = Vec3

Scaling of an object in 3D space. The type is [Vec3](#vec3).

**System capability**: SystemCapability.ArkUi.Graphics3D

| Type| Description|
| ---- | ---- |
| [Vec3](#vec3) | Any 3D vector.|
