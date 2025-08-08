# SceneNode
<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--SE: @zdustc-->
<!--TSE: @zhangyue283-->

本模块提供3D图形中场景资源结点的类型及操作方法。

> **说明：** 
>
> 本模块首批接口从API version 12开始支持，后续版本的新增接口，采用上角标标记接口的起始版本。

## 导入模块

```ts
import { LayerMask, NodeType, Container, Node, Geometry, LightType, Light, SpotLight, DirectionalLight,
  Camera } from '@kit.ArkGraphics3D';
```

## LayerMask
用于定义结点的图层掩码。

### getEnabled
getEnabled(index: number): boolean

获取指定图层下标图层掩码的使能状态。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| index | number | 是 | 要使能图层的下标，值域为大于等于0的整数。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| boolean | 返回特定下标的图层是否使能。true表示使用图层掩码，false表示不使用。 |

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function layerMask() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let node : Node | null = result.getNodeByPath("rootNode_");
      if (node) {
          // 获取掩码的使能状态
          let enabled: Boolean = node.layerMask.getEnabled(1);
      }
    }
  });
}
```

### setEnabled

setEnabled(index: number, enabled: boolean): void

将特定下标的图层掩码使能。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| index | number | 是 | 要使能图层的下标，值域为大于等于0的整数。 |
| enabled | boolean | 是 | 要设置的使能状态。true表示使用图层掩码，false表示不使用。 |

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function layerMask() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let node : Node | null = result.getNodeByPath("rootNode/Scene/");
      if (node) {
          // 设置掩码状态
          node.layerMask.setEnabled(1, true);
      }
    }
  });
}
```

## NodeType
结点类型枚举。

**系统能力：** SystemCapability.ArkUi.Graphics3D
| 名称 | 值 | 说明 |
| ---- | ---- | ---- |
| NODE | 1 | 结点是空结点。 |
| GEOMETRY | 2 | 几何类型结点。 |
| CAMERA | 3 | 相机类型结点。 |
| LIGHT | 4 | 灯光类型结点。 |

## Container\<T>
定义场景对象的容器。容器提供了一种将场景对象分组到层次结构中的方法。

### append
append(item: T): void

追加一个对象到容器。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| item | T | 是 | T类型对象。 |

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function append() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let node : Node | null = result.getNodeByPath("rootNode/Scene/");
      // append 节点
      result.root?.children.get(0)?.children.append(node);
    }
  });
}
```

### insertAfter
insertAfter(item: T, sibling: T | null): void

在兄弟结点后面插入对象。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| item | T | 是 | 要插入结点。 |
| sibling | T \| null | 是 | 兄弟结点。 |

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function insertAfter() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let node : Node | null = result.getNodeByPath("rootNode/Scene/");
      // insertAfter 节点
      result.root?.children.get(0)?.children.insertAfter(node, null);
    }
  });
}
```

### remove
remove(item: T): void

移除指定对象。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| item | T | 是 | 要移除的对象。 |

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function remove() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let node : Node | null = result.getNodeByPath("rootNode/Scene/");
      // remove 节点
      result.root?.children.remove(node);
    }
  });
}
```

### get
get(index: number): T | null

获取特定下标对象，获取不到则返回空。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| index | number | 是 | 要获取对象的下标，取值范围是大于等于0的整数。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| T \| null | 返回获取到的对象，获取不到则返回空值。 |

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function get() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let node : Node | null = result.getNodeByPath("rootNode/Scene/");
      // 从children中get 0号节点
      result.root?.children.get(0)?.children.insertAfter(node, null);
    }
  });
}
```

### clear
clear(): void

清空容器内的所有对象。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function clear() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let node : Node | null = result.getNodeByPath("rootNode/Scene/");
      // 清空children节点
      result.root?.children.clear();
    }
  });
}
```

### count
count(): number

获取容器中对象的数量。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| number | 返回容器中对象个数，取值范围是非负整数。 |

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function count() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let node : Node | null = result.getNodeByPath("rootNode_");
      if (node) {
        let container: Container<Node> = node.children;
        // 获取children中的节点数
        let count: number = container.count();
      }
    }
  });
}
```

## Node
3D场景由树状层次结构的结点组成，其中每个结点都实现了Node接口。继承自[SceneResource](js-apis-inner-scene-resources.md#sceneresource-1)。

### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| position | [Position3](js-apis-inner-scene-types.md#position3) | 否 | 否 | 结点位置。 |
| rotation | [Quaternion](js-apis-inner-scene-types.md#quaternion) | 否 | 否 | 结点旋转角度。 |
| scale | [Scale3](js-apis-inner-scene-types.md#scale3) | 否 | 否 | 结点缩放。 |
| visible | boolean | 否 | 否 | 结点是否可见。true表示该节点可见，false表示不可见。 |
| nodeType | [NodeType](#nodetype) | 是 | 否 | 结点类型。 |
| layerMask | [LayerMask](#layermask) | 是 | 否 | 结点的图层掩码。 |
| path | string | 是 | 否 | 结点路径。 |
| parent | [Node](#node) \| null | 是 | 否 | 结点的父结点，不存在则为空值。 |
| children | [Container](js-apis-inner-scene-nodes.md#containert)\<[Node](#node)> | 是 | 否 | 结点的结点，不存在则为空值。 |

### getNodeByPath
getNodeByPath(path: string): Node | null

根据路径获取结点，如果获取不到则返回空。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 场景结点层次中的路径。每层之间使用'/'符号进行分割。|

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| [Node](#node) \| null | 返回结点对象。 |

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function getNode() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result && result.root) {
      // 查找节点
      let geo : Node | null = result.root.getNodeByPath("scene/node");
    }
  });
}
```

## Geometry
几何节点类型，用于承载可渲染的网格数据，并支持可选的形变功能，继承自[Node](#node)。

### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| mesh | [Mesh](js-apis-inner-scene-resources.md#mesh) | 是 | 否 | 网格属性。 |
| morpher<sup>20+</sup> | [Morpher](js-apis-inner-scene-resources.md#morpher20) | 是 | 是 | 可选的形变器，用于为几何体添加基于顶点的形变或动画效果。若未设置，则该几何体不支持形变功能。 |

## LightType
光源类型枚举。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 值 | 说明 |
| ---- | ---- | ---- |
| DIRECTIONAL | 1 | 平行光类型。 |
| SPOT | 2 | 点光源类型。 |

## Light
光源，继承自[Node](#node)。

### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| lightType | [LightType](#lighttype) | 是 | 否 | 光源类型。 |
| color | [Color](js-apis-inner-scene-types.md#color) | 否 | 否 | 颜色。 |
| intensity | number | 否 | 否 | 光照密度，取值范围是大于0的实数。 |
| shadowEnabled | boolean | 否 | 否 | 是否使能阴影。true表示添加阴影，false表示没有阴影效果。 |
| enabled | boolean | 否 | 否 | 是否使能光源。true表示使用光源，false表示不使用。 |

## SpotLight
点光源类型，继承自[Light](#light)。

**系统能力：** SystemCapability.ArkUi.Graphics3D

## DirectionalLight
平行光类型，继承自[Light](#light)。

**系统能力：** SystemCapability.ArkUi.Graphics3D


## Camera
相机类型，Camera继承自[Node](#node)。

### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| fov | number | 否 | 否 | 视场，取值在0到π弧度之间。 |
| nearPlane | number | 否 | 否 | 近平面，取值大于0。 |
| farPlane | number | 否 | 否 | 远平面，取值大于nearPlane。 |
| enabled | boolean | 否 | 否 | 是否使能相机。true表示使用相机，false表示不使用相机。 |
| postProcess | [PostProcessSettings](js-apis-inner-scene-post-process-settings.md#postprocesssettings) \| null | 否 | 否 | 后处理设置。 |
| clearColor | [Color](js-apis-inner-scene-types.md#color) \| null | 否 | 否 | 将渲染目标（render target）清空后的特定颜色。 |

### raycast<sup>20+</sup>
raycast(viewPosition: Vec2, params: RaycastParameters): Promise<RaycastResult[]>

从屏幕指定位置发射射线，检测并返回所有命中的3D物体信息。使用Promise异步回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| viewPosition | [Vec2](js-apis-inner-scene-types.md#vec2) | 是 | 标准化设备坐标(NDC)，范围[-1, 1]。(-1, -1)为屏幕左下角，(1, 1)为屏幕右上角。|
| params | [RaycastParameters](js-apis-inner-scene.md#raycastparameters20) | 是 | 射线检测的配置参数（如检测范围、过滤节点等）。|

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| Promise<[RaycastResult](js-apis-inner-scene.md#raycastresult20)[]> | 返回命中的结果数组（按距离从近到远排序），若无命中则返回空数组。 |

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, Vec2, Vec3,
  Quaternion } from '@kit.ArkGraphics3D';
import { RaycastParameters } from '@ohos.graphics.scene';

function Raycast(): void {
  Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"))
    .then(async (result: Scene) => {
      if (!result.root) {
        return;
      }
      let node: Node | null | undefined = result.root.getNodeByPath("rootNode_/Unnamed Node 1/AnimatedCube");
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneCameraParameter: SceneNodeParameters = { name: "camera1" };
      // 创建相机
      let camera: Camera = await sceneFactory.createCamera(sceneCameraParameter);
      camera.enabled = true;
      // 设置相机视角
      lookAt(camera, { x: 0, y: 0, z: -3 }, { x: 0, y: 0, z: 0 }, { x: 0, y: 1, z: 0 });

      let viewPos: Vec2 = { x: 0.5, y: 0.5 };
      let raycastParams: RaycastParameters = {};
      if (node) {
        raycastParams.rootNode = node;
      }
      return camera.raycast(viewPos, raycastParams);
    });
}

function Sub(l: Vec3, r: Vec3): Vec3 {
  return { x: l.x - r.x, y: l.y - r.y, z: l.z - r.z };
}
function Dot(l: Vec3, r: Vec3): number {
  return l.x * r.x + l.y * r.y + r.z * l.z;
}
function Normalize(l: Vec3): Vec3 {
  let d = Math.sqrt(Dot(l, l));
  return { x: l.x / d, y: l.y / d, z: l.z / d };
}
function Cross(l: Vec3, r: Vec3): Vec3 {
  return { x: (l.y * r.z - l.z * r.y), y: (l.z * r.x - l.x * r.z), z: (l.x * r.y - l.y * r.x) };
}
function Mul(l: Quaternion, d: number): Quaternion {
  return {
    x: l.x * d,
    y: l.y * d,
    z: l.z * d,
    w: l.w * d
  };
}
function lookAt(node: Node, eye: Vec3, center: Vec3, up: Vec3) {

  let t: number;

  let q: Quaternion = {
    x: 0.0,
    y: 0.0,
    z: 0.0,
    w: 0.0
  };
  let f = Normalize(Sub(center, eye));
  let m0 = Normalize(Cross(f, up));
  let m1 = Cross(m0, f);
  let m2: Vec3 = { x: -f.x, y: -f.y, z: -f.z };
  if (m2.z < 0) {
    if (m0.x > m1.y) {
      t = 1.0 + m0.x - m1.y - m2.z;
      q = {
        x: t,
        y: m0.y + m1.x,
        z: m2.x + m0.z,
        w: m1.z - m2.y
      };
    } else {
      t = 1.0 - m0.x + m1.y - m2.z;
      q = {
        x: m0.y + m1.x,
        y: t,
        z: m1.z + m2.y,
        w: m2.x - m0.z
      };
    }
  } else {
    if (m0.x < -m1.y) {
      t = 1.0 - m0.x - m1.y + m2.z;
      q = {
        x: m2.x + m0.z,
        y: m1.z + m2.y,
        z: t,
        w: m0.y - m1.x
      };
    } else {
      t = 1.0 + m0.x + m1.y + m2.z;
      q = {
        x: m1.z - m2.y,
        y: m2.x - m0.z,
        z: m0.y - m1.x,
        w: t
      }
    }
  }
  node.position = eye;
  node.rotation = Mul(q, 0.5 / Math.sqrt(t));
}
```