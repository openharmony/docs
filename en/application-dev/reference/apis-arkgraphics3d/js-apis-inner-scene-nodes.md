# SceneNode
<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--SE: @zdustc-->
<!--TSE: @zhangyue283-->

The module provides the types and operation methods of scene nodes in 3D graphics.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { LayerMask, NodeType, Container, Node, Geometry, LightType, Light, SpotLight, DirectionalLight,
  Camera } from '@kit.ArkGraphics3D';
```

## LayerMask
Layer mask of the node.

### getEnabled
getEnabled(index: number): boolean

Checks whether the mask is enabled for a layer of a given index.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| index | number | Yes| Index of the layer. The value is an integer greater than or equal to 0.|

**Return value**
| Type| Description|
| ---- | ---- |
| boolean | Check result for whether the layer mask is enabled. **true** if enabled, **false** otherwise.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function layerMask() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let node : Node | null = result.getNodeByPath("rootNode_");
      if (node) {
          // Obtain the enabled status of the mask.
          let enabled: Boolean = node.layerMask.getEnabled(1);
      }
    }
  });
}
```

### setEnabled

setEnabled(index: number, enabled: boolean): void

Enables the mask of a layer of a given index.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| index | number | Yes| Index of the layer. The value is an integer greater than or equal to 0.|
| enabled | boolean | Yes| Whether to enable the layer mask. **true** to enable, **false** otherwise.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function layerMask() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let node : Node | null = result.getNodeByPath("rootNode/Scene/");
      if (node) {
          // Set the enabled status of the mask.
          node.layerMask.setEnabled(1, true);
      }
    }
  });
}
```

## NodeType
Enumerates the node types.

**System capability**: SystemCapability.ArkUi.Graphics3D
| Name| Value| Description|
| ---- | ---- | ---- |
| NODE | 1 | Empty node.|
| GEOMETRY | 2 | Geometry node.|
| CAMERA | 3 | Camera node.|
| LIGHT | 4 | Light node.|

## Container\<T>
Container for defining scene nodes. It provides a way to group scene nodes into a hierarchy.

### append
append(item: T): void

Appends a node to the container.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| item | T | Yes| Object of the T type.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function append() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let node : Node | null = result.getNodeByPath("rootNode/Scene/");
      // Call append to add a node.
      result.root?.children.get(0)?.children.append(node);
    }
  });
}
```

### insertAfter
insertAfter(item: T, sibling: T | null): void

Inserts a node after a sibling node.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| item | T | Yes| Node to insert.|
| sibling | T \| null | Yes| Sibling node.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function insertAfter() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let node : Node | null = result.getNodeByPath("rootNode/Scene/");
      // Call insertAfter to add a node.
      result.root?.children.get(0)?.children.insertAfter(node, null);
    }
  });
}
```

### remove
remove(item: T): void

Removes a node.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| item | T | Yes| Node to remove.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function remove() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let node : Node | null = result.getNodeByPath("rootNode/Scene/");
      // Call remove to remove a node.
      result.root?.children.remove(node);
    }
  });
}
```

### get
get(index: number): T | null

Obtains a node of a given index. If no node is obtained, null is returned.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| index | number | Yes| Index of the node. The value is an integer greater than or equal to 0.|

**Return value**
| Type| Description|
| ---- | ---- |
| T \| null | Object obtained. If no object is obtained, null is returned.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function get() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let node : Node | null = result.getNodeByPath("rootNode/Scene/");
      // Get node 0 from children.
      result.root?.children.get(0)?.children.insertAfter(node, null);
    }
  });
}
```

### clear
clear(): void

Clears all nodes in the container.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function clear() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let node : Node | null = result.getNodeByPath("rootNode/Scene/");
      // Clear the nodes in children.
      result.root?.children.clear();
    }
  });
}
```

### count
count(): number

Obtains the number of nodes in the container.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Return value**
| Type| Description|
| ---- | ---- |
| number | Number of nodes in the container. The value is a non-negative integer.|

**Example**
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
        // Obtain the number of nodes in children.
        let count: number = container.count();
      }
    }
  });
}
```

## Node
The 3D scene consists of nodes in a tree hierarchy, where each node implements a **Node** interface. This class inherits from [SceneResource](js-apis-inner-scene-resources.md#sceneresource-1).

### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| position | [Position3](js-apis-inner-scene-types.md#position3) | No| No| Position of the node.|
| rotation | [Quaternion](js-apis-inner-scene-types.md#quaternion) | No| No| Rotation angle of the node.|
| scale | [Scale3](js-apis-inner-scene-types.md#scale3) | No| No| Scale factor of the node.|
| visible | boolean | No| No| Whether the node is visible. **true** if visible, **false** otherwise.|
| nodeType | [NodeType](#nodetype) | Yes| No| Type of the node.|
| layerMask | [LayerMask](#layermask) | Yes| No| Layer mask of the node.|
| path | string | Yes| No| Path of the node.|
| parent | [Node](#node) \| null | Yes| No| Parent node of the node. If the parent node does not exist, the value is null.|
| children | [Container](js-apis-inner-scene-nodes.md#containert)\<[Node](#node)> | Yes| No| Children of the node. If the node does not have a child, the value is null.|

### getNodeByPath
getNodeByPath(path: string): Node | null

Obtains a node by path. If no node is obtained, null is returned.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Path in the scene node hierarchy. Each layer is separated by a slash (/).|

**Return value**
| Type| Description|
| ---- | ---- |
| [Node](#node) \| null | Node object.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function getNode() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result && result.root) {
      // Search for a node.
      let geo : Node | null = result.root.getNodeByPath("scene/node");
    }
  });
}
```

## Geometry
Geometric node type that holds renderable mesh data and supports optional deformation features. It inherits from [Node](#node).

### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| mesh | [Mesh](js-apis-inner-scene-resources.md#mesh) | Yes| No| Mesh property.|
| morpher<sup>20+</sup> | [Morpher](js-apis-inner-scene-resources.md#morpher20) | Yes| Yes| Optional morpher that adds vertex-based deformation or animation effects to the geometry. If this parameter is not specified, the geometry does not support deformation.|

## LightType
Enumerates the light types.

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Value| Description|
| ---- | ---- | ---- |
| DIRECTIONAL | 1 | Directional light.|
| SPOT | 2 | Spot light.|

## Light
Light node, which inherits from [Node](#node).

### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| lightType | [LightType](#lighttype) | Yes| No| Light type.|
| color | [Color](js-apis-inner-scene-types.md#color) | No| No| Color.|
| intensity | number | No| No| Light intensity. The value is a real number greater than 0.|
| shadowEnabled | boolean | No| No| Whether the shadow effect is enabled. **true** if enabled, **false** otherwise.|
| enabled | boolean | No| No| Whether the light is used. **true** if used, **false** otherwise.|

## SpotLight
Spot light, which inherits from [Light](#light).

**System capability**: SystemCapability.ArkUi.Graphics3D

## DirectionalLight
Directional light, which inherits from [Light](#light).

**System capability**: SystemCapability.ArkUi.Graphics3D


## Camera
Camera node, which inherits from [Node](#node).

### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| fov | number | No| No| Field of view. The value ranges from 0 to π radians.|
| nearPlane | number | No| No| Near plane. The value is greater than 0.|
| farPlane | number | No| No| Remote plane. The value must be greater than that of **nearPlane**.|
| enabled | boolean | No| No| Whether the camera is enabled. **true** if enabled, **false** otherwise.|
| postProcess | [PostProcessSettings](js-apis-inner-scene-post-process-settings.md#postprocesssettings) \| null | No| No| Post-processing settings.|
| clearColor | [Color](js-apis-inner-scene-types.md#color) \| null | No| No| Color after the render target is cleared.|

### raycast<sup>20+</sup>
raycast(viewPosition: Vec2, params: RaycastParameters): Promise<RaycastResult[]>

Casts a ray from a specific position on the screen to detect and retrieve information about all hit 3D objects. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| viewPosition | [Vec2](js-apis-inner-scene-types.md#vec2) | Yes| Standardized Device Coordinates (NDC). The value range is [-1, 1]. The bottom-left corner of the screen is (-1, -1), and the top-right corner is (1, 1).|
| params | [RaycastParameters](js-apis-inner-scene.md#raycastparameters20) | Yes| Configuration parameters for raycasting, such as detection range and filtered nodes.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise<[RaycastResult](js-apis-inner-scene.md#raycastresult20)[]> | An array of hit objects sorted by distance (from nearest to farthest). If no objects are hit, an empty array is returned.|

**Example**
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
      // Create a camera.
      let camera: Camera = await sceneFactory.createCamera(sceneCameraParameter);
      camera.enabled = true;
      // Set the camera view.
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
