# Scene
The Scene module is the basic module of ArkGraphics 3D and provides common data types such as **SceneResourceParameters** and **SceneNodeParameters**. It also provides basic methods such as glTF model loading, scene creation, and resource creation.

> **NOTE**
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import
```ts
import { SceneResourceParameters, SceneNodeParameters, SceneResourceFactory, Scene } from '@kit.ArkGraphics3D';
```

## SceneResourceParameters
Describes the scene resource parameters (**name** and **uri**), which are used to provide the name of a scene resource and the path of the resource file required in the 3D scene.

**System capability**: SystemCapability.ArkUi.Graphics3D
| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| name | string | No| No| Name of the scene resource. It is customizable.|
| uri | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr) | No| Yes| Path of the resource file required in the 3D scene. The default value is undefined.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createShaderPromise() : Promise<Shader> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();

      // Create a variable of the SceneResourceParameters type and use it to create a shader.
      let sceneResourceParameter: SceneResourceParameters = { name: "shaderResource",
        uri: $rawfile("shaders/custom_shader/custom_material_sample.shader") };
      let shader: Promise<Shader> = sceneFactory.createShader(sceneResourceParameter);
      return shader;
    });
  });
}
```

## SceneNodeParameters
Describes the scene node parameters, which are used to provide the name and path in the scene node tree.

**System capability**: SystemCapability.ArkUi.Graphics3D
| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| name | string | No| No| Name of the scene node. It is customizable.
| path | string | No| Yes| Path in the scene node tree. It specifies the position of the created camera, light, or node in the scene node tree. Each layer is separated by a slash (/). If no path is provided, the node is set as a child node of the root node. The default value is undefined.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createNodePromise() : Promise<Node> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();

      // Create a variable of the SceneNodeParameters type and use it to create a node.
      let sceneNodeParameter: SceneNodeParameters = { name: "empty_node",
        path:"/rootNode_/empty_node" };
      let node: Promise<Node> = sceneFactory.createNode(sceneNodeParameter);
      return node;
    });
  });
}
```
## SceneResourceFactory
Provides APIs to create camera, light, and other resources required in the 3D scene.

### createCamera
createCamera(params: SceneNodeParameters): Promise\<Camera>

Creates a camera based on scene node parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| params | [SceneNodeParameters](#scenenodeparameters) | Yes| Scene node parameters.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[Camera](js-apis-inner-scene-nodes.md#camera)> | Promise used to return the **Camera** object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createCameraPromise() : Promise<Camera> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneCameraParameter: SceneNodeParameters = { name: "camera1" };
      // Create a camera.
      let camera: Promise<Camera> = sceneFactory.createCamera(sceneCameraParameter);
      return camera;
    });
  });
}
```

### createLight
createLight(params: SceneNodeParameters, lightType: LightType): Promise\<Light>

Creates a light based on the scene node parameters and light type. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| params | [SceneNodeParameters](#scenenodeparameters) | Yes| Scene node parameters.|
| lightType | [LightType](js-apis-inner-scene-nodes.md#lighttype) | Yes| Light type.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[Light](js-apis-inner-scene-nodes.md#light)> | Promise used to return the **Light** object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createLightPromise() : Promise<Light> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneLightParameter: SceneNodeParameters = { name: "light" };
      // Create directional light.
      let light: Promise<Light> = sceneFactory.createLight(sceneLightParameter, LightType.DIRECTIONAL);
      return light;
    });
  });
}
```

### createNode
createNode(params: SceneNodeParameters): Promise\<Node>

Creates a node. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| params | [SceneNodeParameters](#scenenodeparameters) | Yes| Scene node parameters.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[Node](js-apis-inner-scene-nodes.md#node)> | Promise used to return the **Node** object.|

**Example**
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
      // Create a node.
      let node: Promise<Node> = sceneFactory.createNode(sceneNodeParameter);
      return node;
    });
  });
}
```

### createMaterial
createMaterial(params: SceneResourceParameters, materialType: MaterialType): Promise\<Material>

Creates a material based on the scene resource parameters and material type. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | Yes| Scene resource parameters.|
| materialType | [MaterialType](js-apis-inner-scene-resources.md#materialtype) | Yes| Material type.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[Material](js-apis-inner-scene-resources.md#material)> | Promise used to return the **Material** object.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createMaterialPromise() : Promise<Material> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneMaterialParameter: SceneResourceParameters = { name: "material" };
      // Create a material.
      let material: Promise<Material> = sceneFactory.createMaterial(sceneMaterialParameter, MaterialType.SHADER);
      return material;
    });
  });
}
```

### createShader
createShader(params: SceneResourceParameters): Promise\<Shader>

Creates a shader based on the scene resource parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | Yes| Scene resource parameters.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[Shader](js-apis-inner-scene-resources.md#shader)> | Promise used to return the **Shader** object created.|

**Example**
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
      // Create a shader.
      let shader: Promise<Shader> = sceneFactory.createShader(sceneResourceParameter);
      return shader;
    });
  });
}
```


### createImage
createImage(params: SceneResourceParameters): Promise\<Image>

Creates an image. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | Yes| Scene resource parameters.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[Image](js-apis-inner-scene-resources.md#image)> | Promise used to return the **Image** object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createImagePromise() : Promise<Image> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneImageParameter: SceneResourceParameters = { name: "image", uri: $rawfile("bricks.jpg") };
      // Create an image.
      let image: Promise<Image> = sceneFactory.createImage(sceneImageParameter);
      return image;
    });
  });
}
```

### createEnvironment
createEnvironment(params: SceneResourceParameters): Promise\<Environment>

Creates an environment based on the scene resource parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | Yes| Scene resource parameters.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[Environment](js-apis-inner-scene-resources.md#environment)> | Promise used to return the **Environment** object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createEnvironmentPromise() : Promise<Environment> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneEnvironmentParameter: SceneResourceParameters = { name: "env", uri: $rawfile("bricks.ktx") };
      // Create an environment.
      let env: Promise<Environment> = sceneFactory.createEnvironment(sceneEnvironmentParameter);
      return env;
    });
  });
}
```

### createGeometry<sup>18+</sup>
createGeometry(params: SceneNodeParameters, mesh:MeshResource): Promise\<Geometry>

Creates a geometry object based on the scene node parameters and mesh data. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| params | [SceneNodeParameters](#scenenodeparameters) | Yes| Scene node parameters.|
| mesh | [MeshResource](js-apis-inner-scene-resources.md#meshresource18) | Yes| Mesh data parameters.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[Geometry](js-apis-inner-scene-nodes.md#geometry)> | Promise used to return the **Geometry** object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, Geometry, CubeGeometry, MeshResource} from '@kit.ArkGraphics3D';

function createGeometryPromise() : Promise<Geometry> {
  return new Promise(() => {
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
      let geometry: Promise<Geometry> = sceneFactory.createGeometry({ name: "GeometryName" }, meshRes);
      return geometry;
    });
  });
}
```

### createMesh<sup>18+</sup>
createMesh(params: SceneResourceParameters, geometry: GeometryDefinition): Promise\<MeshResource>

Creates a mesh based on the scene resource parameters and geometry definition. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | Yes| Scene resource parameters.|
| geometry | [GeometryDefinition](js-apis-inner-scene-types.md#geometrydefinition18) | Yes| Geometry instance parameters.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[MeshResource](js-apis-inner-scene-resources.md#meshresource18)> | Promise used to return the **Mesh** object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, Geometry, CubeGeometry, MeshResource} from '@kit.ArkGraphics3D';

function createMeshPromise() : Promise<MeshResource> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load();
    scene.then(async (result: Scene | undefined) => {
      if (!result) {
        return;
      }
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let cubeGeom = new CubeGeometry();
      cubeGeom.size = { x: 1, y: 1, z: 1 };
      console.info("TEST createMeshPromise");
      let meshRes = await sceneFactory.createMesh({ name: "MeshName" }, cubeGeom);
      return meshRes;
    });
  });
}
```

### createScene<sup>18+</sup>
createScene(uri?: ResourceStr): Promise\<Scene>

Creates a scene based on the resource parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| uri | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr) | No| Resource path. The default value is undefined.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[Scene](#scene-1)> | Promise used to return the **Scene** object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, Geometry, CubeGeometry, MeshResource} from '@kit.ArkGraphics3D';

function createScenePromise() : Promise<Scene> {
  return new Promise(() => {
    Scene.load().then(async (result: Scene | undefined) => {
      if (!result) {
        return;
      }
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      console.info("TEST createScenePromise");
      let scene = sceneFactory.createScene($rawfile("gltf/DamagedHelmet/glTF/DamagedHelmet.gltf"));
      return scene;
    });
  });
}
```

## RenderParameters<sup>15+</sup>
Describes the rendering parameters.

**System capability**: SystemCapability.ArkUi.Graphics3D
| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| alwaysRender | boolean | No| Yes| Whether to render every frame. The value **true** means to render every frame, and **false** means to render frames on demand. The default value is **true**.|


## Scene
Describes a scene.

### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| environment | [Environment](js-apis-inner-scene-resources.md#environment) | No| No| Environment object.|
| animations | [Animation](js-apis-inner-scene-resources.md#animation)[] | Yes| No| Animation objects in the 3D scene.|
| root | [Node](js-apis-inner-scene-nodes.md#node) \| null | Yes| No| Root node in the 3D scene tree.|

### load
static load(uri?: ResourceStr): Promise\<Scene>

Loads a resource by path.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| uri | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr) | No| Path of the model file resource to load. The default value is undefined.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[Scene](#scene)> | Promise used to return the **Scene** object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function loadModel() : void {
  // Load the model.
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {});
}
```

### getNodeByPath
getNodeByPath(path: string, type?: NodeType): Node | null

Obtains a node by path.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| path | string | Yes| Path in the scene node tree. Each layer is separated by a slash (/).|
| type | [NodeType](js-apis-inner-scene-nodes.md#nodetype) | No| Type of the node expected. The default value is null.|

**Return value**
| Type| Description|
| ---- | ---- |
| [Node](js-apis-inner-scene-nodes.md#node) \| null | Returns the **Node** object requested. If no node is found in the specified path or the found node type does not match the expected type, null is returned.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function getNode() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
         // Search for a node in the specified path.
        let node : Node | null = result.getNodeByPath("rootNode_");
    }
  });
}
```

### getResourceFactory
getResourceFactory(): SceneResourceFactory

Obtains the scene resource factory.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Return value**
| Type| Description|
| ---- | ---- |
| [SceneResourceFactory](js-apis-inner-scene.md#sceneresourcefactory)| Scene resource factory.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function getFactory() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
         // Obtain a SceneResourceFactory object.
        let sceneFactory: SceneResourceFactory = result.getResourceFactory();
    }
  });
}
```

### destroy
destroy(): void

Destroys this scene and releases all scene resources.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function destroy() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
         // Destroy the scene.
        result.destroy();
    }
  });
}
```

### importNode<sup>18+</sup>
importNode(name: string, node: Node, parent: Node | null): Node

Imports a node from another scene.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| name | string | Yes| Name of the imported node, which can be customized without specific constraints.|
| node | [Node](js-apis-inner-scene-nodes.md#node) | Yes| Node to import.|
| parent | [Node](js-apis-inner-scene-nodes.md#node) \| null | Yes| Parent node of the imported node in the new scene.|

**Return value**
| Type| Description|
| ---- | ---- |
| [Node](js-apis-inner-scene-nodes.md#node) | Node imported.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, Geometry, CubeGeometry, MeshResource} from '@kit.ArkGraphics3D';

function ImportNodeTest() {
  Scene.load().then(async (result: Scene | undefined) => {
    if (!result) {
      return;
    }
    Scene.load($rawfile("gltf/AnimatedCube/glTF/AnimatedCube.gltf"))
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

Imports another scene into the current one.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| name | string | Yes| Root node name of the imported scene, which can be customized without specific constraints.|
| scene | [Scene](#scene-1) | Yes| Scene to import.|
| parent | [Node](js-apis-inner-scene-nodes.md#node) \| null | Yes| Parent node of the imported scene in the new scene.|

**Return value**
| Type| Description|
| ---- | ---- |
| [Node](js-apis-inner-scene-nodes.md#node) | Root node of the imported scene.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, Geometry, CubeGeometry, MeshResource} from '@kit.ArkGraphics3D';

function ImportSceneTest() {
  Scene.load().then(async (result: Scene | undefined) => {
    if (!result) {
      return;
    }
    let content = await result.getResourceFactory().createScene($rawfile("gltf/DamagedHelmet/glTF/DamagedHelmet.gltf"))
    console.info("TEST ImportSceneTest");
    result.importScene("helmet", content, null);
  });
}
```

### renderFrame<sup>15+</sup>
renderFrame(params?: RenderParameters): boolean

Renders frames on demand, such as controlling the frame rate.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| params | [RenderParameters](#renderparameters15) | No| Rendering parameters. The default value is undefined.|

**Return value**
| Type| Description|
| ---- | ---- |
| boolean | Rendering result. The value **true** is returned if rendering is successfully scheduled; returns **false** otherwise.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, Geometry, CubeGeometry, MeshResource} from '@kit.ArkGraphics3D';

function RenderFrameTest() {
  Scene.load($rawfile("gltf/DamagedHelmet/glTF/DamagedHelmet.gltf"))
    .then(async (result: Scene | undefined) => {
      if (!result) {
        return;
      }
      console.info("TEST RenderFrameTest");
      result.renderFrame({ alwaysRender: true });
  });
}
```
