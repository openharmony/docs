# Scene
<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--Designer: @zdustc-->
<!--Tester: @zhangyue283-->
<!--Adviser: @ge-yafang-->

本模块作为ArkGraphics 3D基础模块，提供SceneResourceParameters、SceneNodeParameters等通用数据类型。同时提供glTF模型加载，场景元素、资源创建等基础方法。

> **说明：** 
> - 本模块首批接口从API version 12开始支持，后续版本的新增接口，采用上角标标记接口的起始版本。
> - 关于`.shader`资源文件，具体请见[.shader资源文件格式要求](../../graphics3d/arkgraphics3D-shader-resource.md)。

## 导入模块
```ts
import { SceneResourceParameters, SceneNodeParameters, RaycastResult, RaycastParameters,RenderResourceFactory,
  SceneResourceFactory, SceneComponent, RenderContext, RenderParameters, Scene } from '@kit.ArkGraphics3D';
```

## SceneResourceParameters
场景资源参数对象，包含name和uri，用于提供场景资源的名称以及3D场景所需的资源文件路径。

**系统能力：** SystemCapability.ArkUi.Graphics3D
| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| name | string | 否 | 否 | 要创建资源的名称，可由开发者自定填写，用于标识该场景资源。|
| uri | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr) | 否 | 是 | 3D场景所需的资源文件路径。默认值为undefined。|

**示例：**
```ts
import { Shader, SceneResourceParameters, SceneResourceFactory, Scene } from '@kit.ArkGraphics3D';

function createShaderPromise(): Promise<Shader> {
  return new Promise((resolve, reject) => {
    // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();

      // 创建shader资源（通过SceneResourceParameters配置），路径和文件名可根据项目实际资源自定义
      let sceneResourceParameter: SceneResourceParameters = { name: "shaderResource",
        uri: $rawfile("shaders/custom_shader/custom_material_sample.shader") };
      let shader: Shader = await sceneFactory.createShader(sceneResourceParameter);
      resolve(shader);
    }).catch((error: Error) => {
      console.error('Scene load failed:', error);
      reject(error);
    });
  });
}
```

## SceneNodeParameters
场景结点参数对象，它用于提供场景结点层次中的名称和路径。

**系统能力：** SystemCapability.ArkUi.Graphics3D
| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| name | string | 否 | 否 | 要创建的结点名称，可由开发者自定义填写，用于标识场景结点。|
| path | string | 否 | 是 | 场景结点层次中的路径。用于指定创建的摄影机、灯光或结点在场景结点层次中的放置位置。每层之间使用'/'符号进行分割。如果未提供，则将其设置为根结点的子结点。默认值为undefined。|

**示例：**
```ts
import { SceneNodeParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createNodePromise() : Promise<Node> {
  return new Promise((resolve, reject) => {
    // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();

      // 创建SceneNodeParameters类型变量并以此创建node
      let sceneNodeParameter: SceneNodeParameters = { name: "empty_node",
        path:"/rootNode_/empty_node" };
      let node: Node = await sceneFactory.createNode(sceneNodeParameter);
      resolve(node);
    }).catch((error: Error) => {
      console.error('Scene load failed:', error);
      reject(error);
    });
  });
}
```

## RaycastResult<sup>20+</sup>
射线检测命中结果对象，包含被射线击中的3D物体详细信息。

**系统能力：** SystemCapability.ArkUi.Graphics3D
| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | 否 | 否 | 被射线击中的3D场景节点，可通过该节点操作目标物体（如移动、旋转、隐藏）。 |
| centerDistance | number | 否 | 否 | 命中物体包围盒中心到摄像机中心的距离，取值范围大于0。 |
| hitPosition | [Position3](js-apis-inner-scene-types.md#position3) | 否 | 否 | 射线与物体碰撞点的精确世界坐标（{x: number, y: number, z: number}）。 |


## RaycastParameters<sup>20+</sup>
射线检测参数配置，用于定义射线检测的行为。

**系统能力：** SystemCapability.ArkUi.Graphics3D
| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| rootNode | [Node](js-apis-inner-scene-nodes.md#node) | 否 | 是 | 限定检测范围：仅检测该节点及其子节点。未设置时检测全场景。 |


## RenderResourceFactory<sup>20+</sup>
用于创建可在共享RenderContext的多个场景（Scene）中共享的渲染资源。

### createShader<sup>20+</sup>
createShader(params: SceneResourceParameters): Promise\<Shader>

根据指定场景资源参数创建一个着色器，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | 是 | 创建着色器的参数。详细`.shader`文件格式请参考[.shader资源文件格式要求](../../graphics3d/arkgraphics3D-shader-resource.md)。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<[Shader](js-apis-inner-scene-resources.md#shader)> | Promise对象，返回创建的着色器对象。 |

**示例：**
```ts
import { Shader, SceneResourceParameters, Scene, RenderContext, RenderResourceFactory } from '@kit.ArkGraphics3D';

function createShaderResource(): Promise<Shader> {
  const renderContext: RenderContext | null = Scene.getDefaultRenderContext();
  if (!renderContext) {
    return Promise.reject(new Error("RenderContext is null"));
  }
  const renderResourceFactory: RenderResourceFactory = renderContext.getRenderResourceFactory();
  // 创建shader资源，路径和文件名可根据项目实际资源自定义
  let shaderParams: SceneResourceParameters = {
    name: "custom_shader",
    uri: $rawfile("shaders/custom_shader/custom_material_sample.shader")
  };
  return renderResourceFactory.createShader(shaderParams);
}
```

### createImage<sup>20+</sup>
createImage(params: SceneResourceParameters): Promise\<Image>

根据指定场景资源参数创建一个图像资源，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | 是 | 创建图像的参数。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<[Image](js-apis-inner-scene-resources.md#image)> | Promise对象，返回创建的图像对象。 |

**示例：**
```ts
import { Image, SceneResourceParameters, Scene, RenderContext, RenderResourceFactory } from '@kit.ArkGraphics3D';

function createImageResource(): Promise<Image> {
  const renderContext: RenderContext | null = Scene.getDefaultRenderContext();
  if (!renderContext) {
    return Promise.reject(new Error("RenderContext is null"));
  }
  const renderResourceFactory: RenderResourceFactory = renderContext.getRenderResourceFactory();
  // 加载图片资源，路径和文件名可根据项目实际资源自定义
  let imageParams: SceneResourceParameters = {
    name: "sampleImage",
    uri: $rawfile("image/Cube_BaseColor.png")
  };
  return renderResourceFactory.createImage(imageParams);
}
```

### createMesh<sup>20+</sup>
createMesh(params: SceneResourceParameters, geometry: GeometryDefinition): Promise\<MeshResource>

根据指定场景资源参数和几何体定义（GeometryDefinition）创建一个网格资源（MeshResource），使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | 是 | 创建网格资源的参数。 |
| geometry | [GeometryDefinition](js-apis-inner-scene-types.md#geometrydefinition18) | 是 | 几何形状定义，描述要创建的网格形状。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<[MeshResource](js-apis-inner-scene-resources.md#meshresource18)> | Promise对象，返回创建的网格资源对象。 |

**示例：**
```ts
import { SceneResourceParameters, Scene, CustomGeometry, PrimitiveTopology, RenderContext, RenderResourceFactory,
  MeshResource }  from '@kit.ArkGraphics3D';

function createMeshResource(): Promise<MeshResource> {
  const renderContext: RenderContext | null = Scene.getDefaultRenderContext();
  if (!renderContext) {
    return Promise.reject(new Error("RenderContext is null"));
  }
  const renderResourceFactory: RenderResourceFactory = renderContext.getRenderResourceFactory();
  const geometry = new CustomGeometry();
  geometry.vertices = [
    { x: 0, y: 0, z: 0 },
    { x: 1, y: 0, z: 0 },
    { x: 1, y: 1, z: 0 },
    { x: 0, y: 1, z: 0 },
    { x: 0, y: 0, z: 1 },
    { x: 1, y: 0, z: 1 },
    { x: 1, y: 1, z: 1 },
    { x: 0, y: 1, z: 1 }
  ];
  geometry.indices = [
    0, 1, 2, 2, 3, 0,     // front
    4, 5, 6, 6, 7, 4,     // back
    0, 4, 5, 5, 1, 0,     // bottom
    1, 5, 6, 6, 2, 1,     // right
    3, 2, 6, 6, 7, 3,     // top
    3, 7, 4, 4, 0, 3      // left
  ];
  geometry.topology = PrimitiveTopology.TRIANGLE_LIST;
  geometry.normals = [
    { x: 0, y: 0, z: 1 },
    { x: 0, y: 0, z: 1 },
    { x: 0, y: 0, z: 1 },
    { x: 0, y: 0, z: 1 },
    { x: 0, y: 0, z: 1 },
    { x: 0, y: 0, z: 1 },
    { x: 0, y: 0, z: 1 },
    { x: 0, y: 0, z: 1 }
  ];
  geometry.uvs = [
    { x: 0, y: 0 },
    { x: 1, y: 0 },
    { x: 1, y: 1 },
    { x: 0, y: 1 },
    { x: 0, y: 0 },
    { x: 1, y: 0 },
    { x: 1, y: 1 },
    { x: 0, y: 1 }
  ];
  geometry.colors = [
    { r: 1, g: 0, b: 0, a: 1 },
    { r: 0, g: 1, b: 0, a: 1 },
    { r: 0, g: 0, b: 1, a: 1 },
    { r: 1, g: 1, b: 0, a: 1 },
    { r: 1, g: 0, b: 1, a: 1 },
    { r: 0, g: 1, b: 1, a: 1 },
    { r: 1, g: 1, b: 1, a: 1 },
    { r: 0, g: 0, b: 0, a: 1 }
  ];
  // 加载图片资源，路径和文件名可根据项目实际资源自定义
  let sceneResourceParameter: SceneResourceParameters = {
    name: "cubeMesh",
    uri: $rawfile("image/Cube_BaseColor.png")
  };
  return renderResourceFactory.createMesh(sceneResourceParameter, geometry);
}
```

### createSampler<sup>20+</sup>
createSampler(params:SceneResourceParameters): Promise\<Sampler>

根据指定场景资源参数创建一个采样器资源，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | 是 | 创建采样器的参数。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<[Sampler](js-apis-inner-scene-resources.md#sampler20)> | Promise对象，返回创建的采样器对象。 |

**示例：**
```ts
import { SceneResourceParameters, Scene, RenderContext, RenderResourceFactory, Sampler } from '@kit.ArkGraphics3D';

function createSamplerResource(): Promise<Sampler> {
  const renderContext: RenderContext | null = Scene.getDefaultRenderContext();
  if (!renderContext) {
    return Promise.reject(new Error("RenderContext is null"));
  }
  const renderResourceFactory: RenderResourceFactory = renderContext.getRenderResourceFactory();
  // 加载图片资源，路径和文件名可根据项目实际资源自定义
  let samplerParams: SceneResourceParameters = {
    name: "sampler1",
    uri: $rawfile("image/Cube_BaseColor.png")
  };
  return renderResourceFactory.createSampler(samplerParams);
}
```

### createScene<sup>20+</sup>
createScene(uri?: ResourceStr): Promise\<Scene>

从指定的资源URI创建一个新的场景。如果不指定URI，则创建一个空场景，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| uri | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr) | 否 | 创建场景使用的资源路径，如果未传入资源路径，则默认创建一个空场景。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<[Scene](#scene-1)> | Promise对象，返回创建的场景对象。 |

**示例：**
```ts
import { Scene, RenderContext, RenderResourceFactory } from '@kit.ArkGraphics3D';

// fromFile=true：从指定glb文件加载场景，fromFile=false：创建一个空场景，此参数是为了示例展示两种常见场景创建方式
function createScenePromise(fromFile: boolean = false): Promise<Scene> {
  const renderContext: RenderContext | null = Scene.getDefaultRenderContext();
  if (!renderContext) {
    return Promise.reject(new Error("RenderContext is null"));
  }

  const renderResourceFactory: RenderResourceFactory = renderContext.getRenderResourceFactory();
  if (fromFile) {
    // 创建场景并加载.gltf或.glb文件作为初始内容，路径和名称可根据项目实际资源自定义
    return renderResourceFactory.createScene($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
  } else {
    // 创建空场景
    return renderResourceFactory.createScene();
  }
}
```

## SceneResourceFactory
用于创建3D场景中资源的接口，例如相机、光源等，继承自[RenderResourceFactory](#renderresourcefactory20)。

### createCamera
createCamera(params: SceneNodeParameters): Promise\<Camera>

根据结点参数创建相机，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| params | [SceneNodeParameters](#scenenodeparameters) | 是 | 场景结点参数。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<[Camera](js-apis-inner-scene-nodes.md#camera)> | Promise对象，返回相机对象。 |

**示例：**
```ts
import { SceneNodeParameters, Camera, SceneResourceFactory, Scene } from '@kit.ArkGraphics3D';

function createCameraPromise(): Promise<Camera> {
  return new Promise((resolve, reject) => {
    // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneCameraParameter: SceneNodeParameters = { name: "camera1" };
      // 创建相机
      let camera: Camera = await sceneFactory.createCamera(sceneCameraParameter);
      resolve(camera);
    }).catch((error: Error) => {
      console.error('Scene load failed:', error);
      reject(error);
    });
  });
}
```

### createLight
createLight(params: SceneNodeParameters, lightType: LightType): Promise\<Light>

根据结点参数和灯光类型创建灯光，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| params | [SceneNodeParameters](#scenenodeparameters) | 是 | 场景结点参数。 |
| lightType | [LightType](js-apis-inner-scene-nodes.md#lighttype) | 是 | 灯光类型。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<[Light](js-apis-inner-scene-nodes.md#light)> | Promise对象，返回灯光对象。 |

**示例：**
```ts
import { SceneNodeParameters, LightType, Light, SceneResourceFactory, Scene } from '@kit.ArkGraphics3D';

function createLightPromise() : Promise<Light> {
  return new Promise((resolve, reject) => {
    // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneLightParameter: SceneNodeParameters = { name: "light" };
      // 创建平行光
      let light: Light = await sceneFactory.createLight(sceneLightParameter, LightType.DIRECTIONAL);
      resolve(light);
    }).catch((error: Error) => {
      console.error('Scene load failed:', error);
      reject(error);
    });
  });
}
```

### createNode
createNode(params: SceneNodeParameters): Promise\<Node>

创建结点，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| params | [SceneNodeParameters](#scenenodeparameters) | 是 | 场景结点参数。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<[Node](js-apis-inner-scene-nodes.md#node)> | Promise对象，返回结点对象。 |

**示例：**
```ts
import { SceneNodeParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createNodePromise(): Promise<Node> {
  return new Promise((resolve, reject) => {
    // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneNodeParameter: SceneNodeParameters = { name: "empty_node",
        path:"/rootNode_/empty_node" };
      // 创建节点
      let node: Node = await sceneFactory.createNode(sceneNodeParameter);
      resolve(node);
    }).catch((error: Error) => {
      console.error('Scene load failed:', error);
      reject(error);
    });
  });
}
```

### createMaterial
createMaterial(params: SceneResourceParameters, materialType: MaterialType): Promise\<Material>

根据场景资源参数和材质类型创建材质，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | 是 | 场景资源参数。 |
| materialType | [MaterialType](js-apis-inner-scene-resources.md#materialtype) | 是 | 材质类型。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<[Material](js-apis-inner-scene-resources.md#material)> | Promise对象，返回材质对象。|

**示例：**
```ts
import { MaterialType, Material, SceneResourceParameters, SceneResourceFactory, Scene } from '@kit.ArkGraphics3D';

function createMaterialPromise() : Promise<Material> {
  return new Promise((resolve, reject) => {
    // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneMaterialParameter: SceneResourceParameters = { name: "material" };
      // 创建材质
      let material: Material = await sceneFactory.createMaterial(sceneMaterialParameter, MaterialType.SHADER);
      resolve(material);
    }).catch((error: Error) => {
      console.error('Scene load failed:', error);
      reject(error);
    });
  });
}
```

### createEnvironment
createEnvironment(params: SceneResourceParameters): Promise\<Environment>

根据场景资源参数创建环境，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | 是 | 场景资源参数。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<[Environment](js-apis-inner-scene-resources.md#environment)> | Promise对象，返回环境对象。 |

**示例：**
```ts
import { Environment, SceneResourceParameters, SceneResourceFactory, Scene } from '@kit.ArkGraphics3D';

function createEnvironmentPromise(): Promise<Environment> {
  return new Promise((resolve, reject) => {
    // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      // 加载环境贴图资源，路径和文件名可根据项目实际资源自定义
      let sceneEnvironmentParameter: SceneResourceParameters = { name: "env", uri: $rawfile("KTX/quarry_02_2k_radiance.ktx") };
      // 创建Environment
      let env: Environment = await sceneFactory.createEnvironment(sceneEnvironmentParameter);
      resolve(env);
    }).catch((error: Error) => {
      console.error('Scene load failed:', error);
      reject(error);
    });
  });
}
```

### createGeometry<sup>18+</sup>
createGeometry(params: SceneNodeParameters, mesh:MeshResource): Promise\<Geometry>

根据场景结点参数和网格数据创建几何对象，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| params | [SceneNodeParameters](#scenenodeparameters) | 是 | 场景结点参数。 |
| mesh | [MeshResource](js-apis-inner-scene-resources.md#meshresource18) | 是 | 网格数据参数。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<[Geometry](js-apis-inner-scene-nodes.md#geometry)> | Promise对象，返回几何对象。 |

**示例：**
```ts
import { SceneResourceFactory, Scene, Geometry, CubeGeometry } from '@kit.ArkGraphics3D';

function createGeometryPromise() : Promise<Geometry> {
  return new Promise((resolve, reject) => {
    let scene: Promise<Scene> = Scene.load();
    scene.then(async (result: Scene | undefined) => {
      if (!result) {
        return;
      }
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let cubeGeom = new CubeGeometry();
      cubeGeom.size = { x: 1, y: 1, z: 1 };
      let meshRes = await sceneFactory.createMesh({ name: "MeshName" }, cubeGeom);
      console.info("TEST createGeometryPromise");
      let geometry: Geometry = await sceneFactory.createGeometry({ name: "GeometryName" }, meshRes);
      resolve(geometry);
    }).catch((error: Error) => {
      console.error('Scene load failed:', error);
      reject(error);
    });
  });
}
```

## SceneComponent<sup>20+</sup>
表示基础场景组件，用于描述场景节点的组件信息，包括组件名称及其对应的属性集合。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| name | string | 否 | 否 | 要创建场景组件的名称，可由开发者自定填写，用于标识场景组件。|
| property | Record<string, string \| number \| [Vec2](js-apis-inner-scene-types.md#vec2) \| [Vec3](js-apis-inner-scene-types.md#vec3) \| [Vec4](js-apis-inner-scene-types.md#vec4) \| [SceneResource](js-apis-inner-scene-resources.md#sceneresource-1) \| boolean \| number[] \| string[] \| [SceneResource](js-apis-inner-scene-resources.md#sceneresource-1)[] \| [Vec2](js-apis-inner-scene-types.md#vec2)[] \| [Vec3](js-apis-inner-scene-types.md#vec3)[] \| [Vec4](js-apis-inner-scene-types.md#vec4)[] \| null \| undefined> | 是 | 否 | 组件的属性集合，以键值对形式存储。支持多种基础类型和复杂类型，用于描述场景组件的各种属性。|

## RenderContext<sup>20+</sup>
定义了所有渲染资源的上下文。在同一渲染上下文中创建的多个场景之间，可以共享渲染资源。

### getRenderResourceFactory<sup>20+</sup>
getRenderResourceFactory() : RenderResourceFactory

获取渲染资源工厂，提供创建不同渲染资源的功能。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| [RenderResourceFactory](#renderresourcefactory20) | 返回一个RenderResourceFactory实例，用于创建渲染资源。 |

**示例：**
```ts
import { Scene, RenderContext, RenderResourceFactory } from '@kit.ArkGraphics3D';

function getRenderResourceFactory(): void {
  const renderContext: RenderContext | null = Scene.getDefaultRenderContext();
  if (!renderContext) {
    console.error("RenderContext is null");
    return;
  }
  const renderResourceFactory: RenderResourceFactory = renderContext.getRenderResourceFactory();
  console.info("TEST getRenderResourceFactory");
}
```

### loadPlugin<sup>20+</sup>
loadPlugin(name: string): Promise\<boolean>

用于加载指定名称的插件，通过插件名称查找并加载对应的插件资源，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| name | string | 是 | 要加载的插件名称，必须是系统预定义或已注册且可用的插件名称，且符合命名规范。|

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<boolean> | 返回一个Promise对象，解析结果为boolean类型，表示插件加载是否成功。true表示加载成功，false表示加载失败。 |

**示例：**
```ts
import { Scene, RenderContext } from '@kit.ArkGraphics3D';

function loadPlugin(): Promise<boolean> {
  const renderContext: RenderContext | null = Scene.getDefaultRenderContext();
  if (!renderContext) {
    console.error("RenderContext is null");
    return Promise.reject(new Error("RenderContext is null"));
  }
  return renderContext.loadPlugin("pluginName");
}
```

### registerResourcePath<sup>20+</sup>
registerResourcePath(protocol: string, uri: string): boolean

注册shader等资产文件所在的路径目录及其检索名，通过检索名查找并替换shader内部关联文件的路径描述，找到对应的资产路径目录，实现资产及其关联文件的正确加载。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| protocol | string | 是 | 要注册的路径检索名，必须是系统未预定义或未注册且非空的检索名称。|
| uri | string | 是 | 要注册的资产路径目录，与检索名对应，必须是资产文件所在文件夹路径。|

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| boolean | 返回资产文件路径是否注册成功。true表示注册成功；false表示注册失败，可能原因为检索名已被注册或输入参数不可用。 |

**示例：**
```ts
import { Scene, RenderContext } from '@kit.ArkGraphics3D';

function registerResourcePath(): void {
  // 创建shader资源，路径和文件名可根据项目实际资源自定义
  Scene.load($rawfile("shaders/custom_shader/custom_material_sample.shader"))
    .then(scene => {
      const renderContext: RenderContext | null = Scene.getDefaultRenderContext();
      if (!renderContext) {
        console.error("RenderContext is null");
        return false;
      }
      return renderContext.registerResourcePath("protocol", "OhosRawFile://uri");
    })
    .then(result => {
      if (result) {
        console.info("resource path registration success");
      } else {
        console.error("resource path registration failed");
      }
    });
}
```

## RenderParameters<sup>15+</sup>
渲染参数接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D
| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| alwaysRender<sup>15+</sup> | boolean | 否 | 是 | 表示是否每一帧都渲染。true表示每一帧都渲染，false表示按需渲染。默认值为true。 |


## Scene
用于设置场景。

### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| environment | [Environment](js-apis-inner-scene-resources.md#environment) | 否 | 否 | 环境对象。 |
| animations | [Animation](js-apis-inner-scene-resources.md#animation)[] | 是 | 否 | 动画数组，用于保存3D场景中的动画对象。|
| root | [Node](js-apis-inner-scene-nodes.md#node) \| null | 是 | 否 | 3D场景树根结点。 |

### load
static load(uri?: ResourceStr): Promise\<Scene>

通过传入的资源路径加载资源，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| uri | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr) | 否 | 待加载的模型文件资源路径，默认值为undefined。|

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<[Scene](#scene-1)> | Promise对象，返回场景对象。|

**示例：**
```ts
import { Scene } from '@kit.ArkGraphics3D';

function loadModel(): void {
  // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
  scene.then(async (result: Scene) => {});
}
```

### getNodeByPath
getNodeByPath(path: string, type?: NodeType): Node | null

通过路径获取结点。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 场景结点层次中的路径。每层之间使用'/'符号进行分割。|
| type | [NodeType](js-apis-inner-scene-nodes.md#nodetype) | 否 | 预期返回的结点类型。默认值为空。|

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| [Node](js-apis-inner-scene-nodes.md#node) \| null | 返回请求结点的实例，如果没有找到或者找到的节点类型与传入的参数不相符则返回空。 |

**示例：**
```ts
import { Scene, Node } from '@kit.ArkGraphics3D';

function getNode(): void {
  // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
  scene.then(async (result: Scene) => {
    if (result) {
         // 寻找指定路径的节点
        let node : Node | null = result.getNodeByPath("rootNode_");
    }
  });
}
```

### getResourceFactory
getResourceFactory(): SceneResourceFactory

获取场景资源工厂对象。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| [SceneResourceFactory](js-apis-inner-scene.md#sceneresourcefactory)| 返回场景资源工厂对象。 |

**示例：**
```ts
import { SceneResourceFactory, Scene } from '@kit.ArkGraphics3D';

function getFactory(): void {
  // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
  scene.then(async (result: Scene) => {
    if (result) {
         // 获得SceneResourceFactory对象
        let sceneFactory: SceneResourceFactory = result.getResourceFactory();
    }
  });
}
```

### destroy
destroy(): void

销毁场景，释放所有的场景资源。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**示例：**
```ts
import { Scene } from '@kit.ArkGraphics3D';

function destroy(): void {
  // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
  scene.then(async (result: Scene) => {
    if (result) {
         // 销毁scene
        result.destroy();
    }
  });
}
```

### importNode<sup>18+</sup>
importNode(name: string, node: Node, parent: Node | null): Node

一般用于从其他场景导入结点。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| name | string | 是 | 导入结点后的名称，由开发者自定义，无特殊要求。|
| node | [Node](js-apis-inner-scene-nodes.md#node) | 是 | 被导入的结点。|
| parent | [Node](js-apis-inner-scene-nodes.md#node) \| null | 是 | 被导入结点在新场景中的父结点。|

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| [Node](js-apis-inner-scene-nodes.md#node) | 被导入的结点。|

**示例：**
```ts
import { Scene } from '@kit.ArkGraphics3D';

function ImportNodeTest() {
  Scene.load().then(async (result: Scene | undefined) => {
    if (!result) {
      return;
    }
    // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
    Scene.load($rawfile("gltf/AnimatedCube/glTF/AnimatedCube.glb"))
      .then(async (extScene: Scene) => {
        let extNode = extScene.getNodeByPath("rootNode_/Unnamed Node 1/AnimatedCube");
        console.info("TEST ImportNodeTest");
        let node = result.importNode("scene", extNode, result.root);
        if (node) {
          node.position.x = 5;
        }
      });
  });
}
```

### importScene<sup>18+</sup>
importScene(name: string, scene: Scene, parent: Node | null): Node

在当前场景中导入其他场景。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| name | string | 是 | 导入场景的根结点名称，由开发者自定义，无特殊要求。|
| scene | [Scene](#scene-1) | 是 | 被导入的场景。|
| parent | [Node](js-apis-inner-scene-nodes.md#node) \| null | 是 | 被导入场景在新场景中的父结点。|

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| [Node](js-apis-inner-scene-nodes.md#node) | 被导入场景的根结点。|

**示例：**
```ts
import { Scene } from '@kit.ArkGraphics3D';

function ImportSceneTest() {
  Scene.load().then(async (result: Scene | undefined) => {
    if (!result) {
      return;
    }
    // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
    let content = await result.getResourceFactory().createScene($rawfile("gltf/DamagedHelmet/glTF/DamagedHelmet.glb"))
    console.info("TEST ImportSceneTest");
    result.importScene("helmet", content, null);
  });
}
```

### renderFrame<sup>15+</sup>
renderFrame(params?: RenderParameters): boolean

通过该接口可以实现按需渲染，例如控制渲染帧率。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| params | [RenderParameters](#renderparameters15) | 否 | 渲染参数，默认值为undefined。|

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| boolean | 渲染被成功调度返回true，否则返回false。|

**示例：**
```ts
import { Scene } from '@kit.ArkGraphics3D';

function RenderFrameTest() {
  // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
  Scene.load($rawfile("gltf/DamagedHelmet/glTF/DamagedHelmet.glb"))
    .then(async (result: Scene | undefined) => {
      if (!result) {
        return;
      }
      console.info("TEST RenderFrameTest");
      result.renderFrame({ alwaysRender: true });
  });
}
```

### createComponent<sup>20+</sup>
createComponent(node: Node, name: string): Promise\<SceneComponent>

在指定节点上创建新的组件，根据组件名称异步创建并附加到节点上，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | 是 | 组件需要附加到的节点。|
| name | string | 是 | 要创建的组件名称，由各插件定义有效名称。|

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<[SceneComponent](#scenecomponent20)> | Promise对象，返回新创建的场景组件。|

**示例：**
```ts
import { Scene, SceneComponent } from '@kit.ArkGraphics3D';

function createComponentTest(): Promise<SceneComponent> {
  // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
  return Scene.load($rawfile("gltf/DamagedHelmet/glTF/DamagedHelmet.glb"))
    .then(scene => {
      if (!scene) {
        return Promise.reject(new Error("Scene load failed"));
      }
      // RenderConfigurationComponent为引擎内置组件，创建时无需依赖插件
      return scene.createComponent(scene.root, "RenderConfigurationComponent");
    })
    .then(component => {
      if (!component) {
        return Promise.reject(new Error("createComponent failed"));
      }
      return component;
    });
}
```

### getComponent<sup>20+</sup>
getComponent(node: Node, name: string): SceneComponent | null

根据指定的组件名称，从给定节点上获取对应的组件实例。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | 是 | 组件附加的节点。|
| name | string | 是 | 需要获取的组件名称，必须为系统预定义或已注册的自定义组件名称，且需符合命名规范。|

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| [SceneComponent](#scenecomponent20) \| null | 返回对应名称的组件对象，若未找到则返回null。|

**示例：**
```ts
import { Scene } from '@kit.ArkGraphics3D';

function getComponentTest() {
  // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
  Scene.load($rawfile("gltf/DamagedHelmet/glTF/DamagedHelmet.glb"))
    .then(async (result: Scene | undefined) => {
      if (!result) {
        console.error("Scene load failed");
        return;
      }
      console.info("TEST getComponentTest");
      let component = result.getComponent(result.root, "myComponent");
      if (component) {
        console.info("getComponent success");
      } else {
        console.warn("Component not found");
      }
    });
}
```

### getDefaultRenderContext<sup>20+</sup>
static getDefaultRenderContext(): RenderContext | null

获取当前图形对象所关联的渲染环境信息。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| [RenderContext](#rendercontext20) \| null | 返回当前对象关联的渲染上下文，若对象尚未关联任何渲染上下文，则返回null。|

**示例：**
```ts
import { Scene, RenderContext } from '@kit.ArkGraphics3D';

function getDefaultRenderContextTest() {
  console.info("TEST getDefaultRenderContextTest");
  const renderContext: RenderContext | null = Scene.getDefaultRenderContext();
  if (renderContext) {
    console.info("getDefaultRenderContext success");
  } else {
    console.error("RenderContext is null");
  }
}
```
