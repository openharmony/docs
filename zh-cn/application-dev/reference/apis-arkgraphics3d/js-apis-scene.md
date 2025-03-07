# @ohos.graphics.scene (ArkGraphics 3D模块)

Scene将自定义的二级模块API组织在一起，方便开发者进行导出使用。
- [Scene](js-apis-inner-scene.md)：ArkGraphics 3D基础模块，提供SceneResourceParamters、SceneNodeParamters等通用数据类型。同时提供glTF模型加载，场景元素、资源创建等基础方法。
- [SceneNode](js-apis-inner-scene-nodes.md)：3D场景是以树状结构进行组织的，通过操作结点属性以及结点树结构可以改变3D场景。本模块提供3D图形中场景资源结点的类型及操作方法。
- [SceneType](js-apis-inner-scene-types.md)：本模块覆盖3D图形中的数据类型，包括向量、四元数等。
- [SceneResources](js-apis-inner-scene-resources.md)：本模块提供3D图形中常用的基本资源类型，包括材质、图片、着色器等。
- [ScenePostProcessSettings](js-apis-inner-scene-post-process-settings.md)：本模块提供3D图形中的色调映射等图像后处理方法。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块
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
  Scene,
  BloomSettings,
  MeshResource,
  RenderParameters,
  GeometryType,
  GeometryDefinition,
  PrimitiveTopology,
  CustomGeometry,
  CubeGeometry,
  PlaneGeometry,
  SphereGeometry
} from '@kit.ArkGraphics3D';
```