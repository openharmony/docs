# @ohos.graphics.scene (ArkGraphics 3D)

The **Scene** module houses all the APIs provided by the custom level-2 modules so that you can export and use them more easily.
- [Scene](js-apis-inner-scene.md): basic module of ArkGraphics 3D. It provides common data types such as **SceneResourceParamters** and **SceneNodeParamters**. It also provides basic methods such as glTF model loading, scene creation, and resource creation.
- [SceneNode](js-apis-inner-scene-nodes.md): A 3D scene adopts a tree structure. You can change the 3D scene by operating the node attributes and the node tree structure. This module provides the types and operation methods of scene nodes in 3D graphics.
- [SceneType](js-apis-inner-scene-types.md): provides the data types in 3D graphics, including vectors and quaternions.
- [SceneResources](js-apis-inner-scene-resources.md): provides basic resource types, such as materials, images, and shaders, which are commonly used in 3D graphics.
- [ScenePostProcessSettings](js-apis-inner-scene-post-process-settings.md): provides image post-processing methods (for example, tone mapping) in 3D graphics.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import
```ts
import {
  ToneMappingType,
  ToneMappingSettings,
  PostProcessSettings,
  Vec2,
  Vec3,
  Vec4,
  Color,
  Rect,
  Quaternion,
  Aabb,
  Position3,
  Rotation3,
  Scale3,
  SceneResourceType,
  SceneResource,
  Shader,
  MaterialType,
  Material,
  ShaderMaterial,
  SubMesh,
  Mesh,
  Animation,
  EnvironmentBackgroundType,
  Environment,
  Image,
  LayerMask,
  NodeType,
  Container,
  Node,
  Geometry,
  LightType,
  Light,
  SpotLight,
  DirectionalLight,
  Camera,
  SceneResourceParameters,
  SceneNodeParameters,
  SceneResourceFactory,
  Scene
} from '@kit.ArkGraphics3D';
```
