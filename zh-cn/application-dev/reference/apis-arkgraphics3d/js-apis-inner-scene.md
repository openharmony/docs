# Scene
本模块作为ArkGraphics 3D基础模块，提供SceneResourceParamters、SceneNodeParamters等通用数据类型。同时提供glTF模型加载，场景元素、资源创建等基础方法。

> **说明：** 
> - 本模块首批接口从API version 12开始支持，后续版本的新增接口，采用上角标标记接口的起始版本。

## 导入模块
```ts
import { SceneResourceParameters, SceneNodeParameters, SceneResourceFactory, Scene } from '@kit.ArkGraphics3D';
```

## SceneResourceParameters
场景资源参数对象。包含name和uri。用于提供场景资源的名称以及3D场景所需的资源文件路径。

**系统能力：** SystemCapability.ArkUi.Graphics3D
| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| name | string | 否 | 否 | 要创建资源的名称，可由开发者自定填写。|
| uri | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr) | 否 | 是 | 3D场景所需的资源文件路径。默认值为undefined。|

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createShaderPromise() : Promise<Shader> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();

      // 创建SceneResourceParameters类型变量并以此创建shader
      let sceneResourceParameter: SceneResourceParameters = { name: "shaderResource",
        uri: $rawfile("shaders/custom_shader/custom_material_sample.shader") };
      let shader: Promise<Shader> = sceneFactory.createShader(sceneResourceParameter);
      return shader;
    });
  });
}
```

## SceneNodeParameters
场景结点参数对象，它用于提供场景结点层次中的名称和路径。

**系统能力：** SystemCapability.ArkUi.Graphics3D
| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| name | string | 否 | 否 | 要创建的结点名称，可由开发者自定义填写。
| path | string | 否 | 是 | 场景结点层次中的路径。用于指定创建的摄影机、灯光或结点在场景结点层次中的放置位置。每层之间使用'/'符号进行分割。如果未提供，则将其设置为根结点的子结点。默认值为undefined。|

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createNodePromise() : Promise<Node> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();

      // 创建SceneNodeParameters类型变量并以此创建node
      let sceneNodeParameter: SceneNodeParameters = { name: "empty_node",
        path:"/rootNode_/empty_node" };
      let node: Promise<Node> = sceneFactory.createNode(sceneNodeParameter);
      return node;
    });
  });
}
```
## SceneResourceFactory
用于创建3D场景中资源的接口，例如相机、光源等。

### createCamera
createCamera(params: SceneNodeParameters): Promise\<Camera>

根据结点参数创建相机, 使用Promise异步回调。

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
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createCameraPromise() : Promise<Camera> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneCameraParameter: SceneNodeParameters = { name: "camera1" };
      // 创建相机
      let camera: Promise<Camera> = sceneFactory.createCamera(sceneCameraParameter);
      return camera;
    });
  });
}
```

### createLight
createLight(params: SceneNodeParameters, lightType: LightType): Promise\<Light>

根据结点参数和灯光类型创建灯光, 使用Promise异步回调。

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
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createLightPromise() : Promise<Light> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneLightParameter: SceneNodeParameters = { name: "light" };
      // 创建平行光
      let light: Promise<Light> = sceneFactory.createLight(sceneLightParameter, LightType.DIRECTIONAL);
      return light;
    });
  });
}
```

### createNode
createNode(params: SceneNodeParameters): Promise\<Node>

创建结点, 使用Promise异步回调。

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
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createNodePromise() : Promise<Node> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneNodeParameter: SceneNodeParameters = { name: "empty_node",
        path:"/rootNode_/empty_node" };
      // 创建节点
      let node: Promise<Node> = sceneFactory.createNode(sceneNodeParameter);
      return node;
    });
  });
}
```

### createMaterial
createMaterial(params: SceneResourceParameters, materialType: MaterialType): Promise\<Material>

根据场景资源参数和材质类型创建材质, 使用Promise异步回调。

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
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createMaterialPromise() : Promise<Material> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneMaterialParameter: SceneResourceParameters = { name: "material" };
      // 创建材质
      let material: Promise<Material> = sceneFactory.createMaterial(sceneMaterialParameter, MaterialType.SHADER);
      return material;
    });
  });
}
```

### createShader
createShader(params: SceneResourceParameters): Promise\<Shader>

根据场景资源参数创建着色器, 使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | 是 | 场景资源参数。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<[Shader](js-apis-inner-scene-resources.md#shader)> | Promise对象，返回着色器对象。 |

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createShaderPromise() : Promise<Shader> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneResourceParameter: SceneResourceParameters = { name: "shaderResource",
        uri: $rawfile("shaders/custom_shader/custom_material_sample.shader") };
      // 创建shader
      let shader: Promise<Shader> = sceneFactory.createShader(sceneResourceParameter);
      return shader;
    });
  });
}
```


### createImage
createImage(params: SceneResourceParameters): Promise\<Image>

创建图片资源, 使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | 是 | 场景资源参数。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<[Image](js-apis-inner-scene-resources.md#image)> | Promise对象，返回图片对象。 |

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createImagePromise() : Promise<Image> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneImageParameter: SceneResourceParameters = { name: "image", uri: $rawfile("bricks.jpg") };
      // 创建Image
      let image: Promise<Image> = sceneFactory.createImage(sceneImageParameter);
      return image;
    });
  });
}
```

### createEnvironment
createEnvironment(params: SceneResourceParameters): Promise\<Environment>

根据场景资源参数创建环境, 使用Promise异步回调。

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
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createEnvironmentPromise() : Promise<Environment> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneEnvironmentParameter: SceneResourceParameters = { name: "env", uri: $rawfile("bricks.ktx") };
      // 创建Environment
      let env: Promise<Environment> = sceneFactory.createEnvironment(sceneEnvironmentParameter);
      return env;
    });
  });
}
```

## Scene
用于设置场景。

### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| environment | [Environment](js-apis-inner-scene-resources.md#environment) | 否 | 否 | 环境对象。 |
| animations | [Animation](js-apis-inner-scene-resources.md#animation)[] | 是 | 否 | 动画数组。 用于保存3D场景中的动画对象。|
| root | [Node](js-apis-inner-scene-nodes.md#node) \| null | 是 | 否 | 3D场景树根结点。 |

### load
static load(uri?: ResourceStr): Promise\<Scene>

通过传入的资源路径加载资源。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| uri | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr) | 否 | 待加载的模型文件资源路径，默认值为undefined。|

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise\<[Scene](#scene)> | Promise对象，返回场景对象。|

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function loadModel() : void {
  // 加载模型
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
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
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function getNode() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
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
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function getFactory() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
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
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function destroy() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
         // 销毁scene
        result.destroy();
    }
  });
}
```
