# SceneNode
The SceneNode module provides the types and operation methods of scene nodes in 3D graphics.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import
```ts
import { LayerMask, NodeType, Container, Node, Geometry, LightType, Light, SpotLight, DirectionalLight,
  Camera } from '@kit.ArkGraphics3D';
```
## LayerMask
Layer mask of a node.

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
| boolean | **true**: The layer mask is enabled.<br>**false**: The layer mask is disabled.|

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
| enabled | boolean | Yes| Enabled status to set. The value **true** means to enable the layer mask, and **false** means the opposite.|

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
| number | Number of nodes in the container.|

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
The 3D scene consists of nodes in a tree hierarchy, where each node implements a **Node** interface. This class inherits from [SceneResource](js-apis-inner-scene-resources.md#sceneresource).

### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| position | [Position3](js-apis-inner-scene-types.md#position3) | No| No| Position of the node.|
| rotation | [Quaternion](js-apis-inner-scene-types.md#quaternion) | No| No| Rotation angle of the node.|
| scale | [Scale3](js-apis-inner-scene-types.md#scale3) | No| No| Scale factor of the node.|
| visible | boolean | No| No| Whether the node is visible. The value **true** means that the node is visible, and **false** means the opposite.|
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
| [Node](#node) \| null | **Node** object.|

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
Geometry node, which inherits from [Node](#node).

### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| mesh | [Mesh](js-apis-inner-scene-resources.md#mesh) | Yes| No| Mesh attribute.|


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
| shadowEnabled | boolean | No| No| Whether the shadow effect is enabled. The value **true** means that the shadow effect is enabled, and **false** means the opposite.|
| enabled | boolean | No| No| Whether the light is used. The value **true** means that the light is used, and **false** means the opposite.|

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
| enabled | boolean | No| No| Whether the camera is enabled. The value **true** means that the camera is enabled, and **false** means the opposite.|
| postProcess | [PostProcessSettings](js-apis-inner-scene-post-process-settings.md#postprocesssettings) \| null | No| No| Post-processing settings.|
| clearColor | [Color](js-apis-inner-scene-types.md#color) \| null | No| No| Color after the render target is cleared.|
