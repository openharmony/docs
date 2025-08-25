# Scene
<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--SE: @zdustc-->
<!--TSE: @zhangyue283-->

The module is the basic module of ArkGraphics 3D and provides common data types such as **SceneResourceParameters** and **SceneNodeParameters**. It also provides basic methods such as glTF model loading, scene creation, and resource creation.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import
```ts
import { SceneResourceParameters, SceneNodeParameters, RaycastResult, RaycastParameters,RenderResourceFactory,
  SceneResourceFactory, SceneComponent, RenderContext, RenderParameters, Scene } from '@kit.ArkGraphics3D';
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
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
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
| name | string | No| No| Name of the scene node. It is customizable.|
| path | string | No| Yes| Path in the scene node tree. It specifies the position of the created camera, light, or node in the scene node tree. Each layer is separated by a slash (/). If no path is provided, the node is set as a child node of the root node. The default value is undefined.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createNodePromise() : Promise<Node> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
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

## RaycastResult<sup>20+</sup>
Describes a result object from raycasting, containing details about the 3D object hit by the ray.

**System capability**: SystemCapability.ArkUi.Graphics3D
| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | Yes| No| 3D scene node hit by the ray. You can use this node to manipulate the target object (for example, moving, rotating, or hiding the object).|
| centerDistance | number | Yes| No| Distance from the center of the bounding box of the hit object to the center of the camera. The value must be greater than 0.|
| hitPosition | [Position3](js-apis-inner-scene-types.md#position3) | Yes| No| Precise world coordinates ({x: number, y: number, z: number}) of the point where the ray hit the object.|


## RaycastParameters<sup>20+</sup>
Describes the configuration parameters for raycasting, defining the behavior of raycasting.

**System capability**: SystemCapability.ArkUi.Graphics3D
| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| rootNode | [Node](js-apis-inner-scene-nodes.md#node) | No| Yes| Limits the detection scope to this node and its child nodes. If this parameter is not specified, the entire scene is detected.|


## RenderResourceFactory<sup>20+</sup>
Provides APIs to create rendering resources that can be shared among multiple scenes with a shared RenderContext.

### createShader
createShader(params: SceneResourceParameters): Promise\<Shader>

Creates a shader based on the scene resource parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | Yes| Parameters for creating the shader.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[Shader](js-apis-inner-scene-resources.md#shader)> | Promise used to return the Shader object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, RenderContext, RenderResourceFactory } from '@kit.ArkGraphics3D';

function createShaderResource(): Promise<Shader> {
  const renderContext: RenderContext | null = Scene.getDefaultRenderContext();
  if (!renderContext) {
    return Promise.reject(new Error("RenderContext is null"));
  }
  const renderResourceFactory: RenderResourceFactory = renderContext.getRenderResourceFactory();
  let shaderParams: SceneResourceParameters = {
    name: "custom_shader",
    uri: $rawfile("shaders/custom_shader/custom_material_sample.shader")
  };
  return renderResourceFactory.createShader(shaderParams);
}
```
### createImage
createImage(params: SceneResourceParameters): Promise\<Image>

Creates an image based on the scene resource parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | Yes| Parameters for creating the image.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[Image](js-apis-inner-scene-resources.md#image)> | Promise used to return the Image object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, RenderContext, RenderResourceFactory } from '@kit.ArkGraphics3D';

function createImageResource(): Promise<Image> {
  const renderContext: RenderContext | null = Scene.getDefaultRenderContext();
  if (!renderContext) {
    return Promise.reject(new Error("RenderContext is null"));
  }
  const renderResourceFactory: RenderResourceFactory = renderContext.getRenderResourceFactory();
  let imageParams: SceneResourceParameters = {
    name: "sampleImage",
    uri: $rawfile("image/Cube_BaseColor.png")
  };
  return renderResourceFactory.createImage(imageParams);
}
```

### createMesh
createMesh(params: SceneResourceParameters, geometry: GeometryDefinition): Promise\<MeshResource>

Creates a mesh based on the scene resource parameters and geometry definition. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | Yes| Parameters for creating the mesh.|
| geometry | [GeometryDefinition](js-apis-inner-scene-types.md#geometrydefinition18) | Yes| Geometry of the mesh to create.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[MeshResource](js-apis-inner-scene-resources.md#meshresource18)> | Promise used to return the Mesh object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node }  from '@kit.ArkGraphics3D';
import { CustomGeometry, PrimitiveTopology, RenderContext, RenderResourceFactory,
  MeshResource } from '@ohos.graphics.scene';

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
  let sceneResourceParameter: SceneResourceParameters = {
    name: "cubeMesh",
    uri: $rawfile("image/Cube_BaseColor.png")
  };
  return renderResourceFactory.createMesh(sceneResourceParameter, geometry);
}
```

### createSampler
createSampler(params:SceneResourceParameters): Promise\<Sampler>

Creates a sampler based on the scene resource parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| params | [SceneResourceParameters](#sceneresourceparameters) | Yes| Parameters for creating the sampler.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[Sampler](js-apis-inner-scene-resources.md#sampler20)> | Promise used to return the Sampler object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, RenderContext, RenderResourceFactory,
  Sampler } from '@kit.ArkGraphics3D';

function createSamplerResource(): Promise<Sampler> {
  const renderContext: RenderContext | null = Scene.getDefaultRenderContext();
  if (!renderContext) {
    return Promise.reject(new Error("RenderContext is null"));
  }
  const renderResourceFactory: RenderResourceFactory = renderContext.getRenderResourceFactory();
  let samplerParams: SceneResourceParameters = {
    name: "sampler1",
    uri: $rawfile("image/Cube_BaseColor.png")
  };
  return renderResourceFactory.createSampler(samplerParams);
}
```

### createScene
createScene(uri?: ResourceStr): Promise\<Scene>

Creates a scene from the specified resource URI. If no URI is specified, an empty scene is created. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| uri | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr) | No| Resource path used for creating the scene. If no resource path is passed, an empty scene is created.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[Scene](#scene-1)> | Promise used to return the Scene object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';
import { RenderContext, RenderResourceFactory } from '@ohos.graphics.scene';

// fromFile=true: loads a scene from the specified GLB file. fromFile=false: creates an empty scene. This parameter illustrates two typical methods for creating scenes.
function createScenePromise(fromFile: boolean = false): Promise<Scene> {
  const renderContext: RenderContext | null = Scene.getDefaultRenderContext();
  if (!renderContext) {
    return Promise.reject(new Error("RenderContext is null"));
  }

  const renderResourceFactory: RenderResourceFactory = renderContext.getRenderResourceFactory();
  if (fromFile) {
    // Create a scene from a file.
    return renderResourceFactory.createScene($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
  } else {
    // Create an empty scene.
    return renderResourceFactory.createScene();
  }
}
```

## SceneResourceFactory
Provides APIs for creating resources, such as cameras and light sources, used in 3D scenes. This class inherits from [RenderResourceFactory](#renderresourcefactory20).

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
| Promise\<[Camera](js-apis-inner-scene-nodes.md#camera)> | Promise used to return the Camera object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createCameraPromise() : Promise<Camera> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
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
| Promise\<[Light](js-apis-inner-scene-nodes.md#light)> | Promise used to return the Light object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createLightPromise() : Promise<Light> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
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
| Promise\<[Node](js-apis-inner-scene-nodes.md#node)> | Promise used to return the Node object.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createNodePromise() : Promise<Node> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
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
| Promise\<[Material](js-apis-inner-scene-resources.md#material)> | Promise used to return the Material object.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createMaterialPromise() : Promise<Material> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
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
| Promise\<[Environment](js-apis-inner-scene-resources.md#environment)> | Promise used to return the Environment object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createEnvironmentPromise() : Promise<Environment> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneEnvironmentParameter: SceneResourceParameters = { name: "env", uri: $rawfile("KTX/quarry_02_2k_radiance.ktx") };
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
| Promise\<[Geometry](js-apis-inner-scene-nodes.md#geometry)> | Promise used to return the Geometry object created.|

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

## SceneComponent<sup>20+</sup>
Represents a basic scene component, which is used to describe the component information of a scene node, including the component name and its properties.

### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| name | string | No| No| Name of the scene component, which is customizable.|
| property | Record<string, string \| number \| Vec2 \| Vec3 \| Vec4 \| Image \| boolean \| number[] \| string[] \| Image[]> | Yes| No| A set of component properties stored in key-value pairs. It supports various basic and complex types to describe various properties of the scene component.|

## RenderContext<sup>20+</sup>
Defines the context of all rendering resources. Multiple scenes created within the same render context can share rendering resources.

### getRenderResourceFactory
getRenderResourceFactory() : RenderResourceFactory

Obtains the rendering resource factory, which provides APIs for creating different rendering resources.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Return value**
| Type| Description|
| ---- | ---- |
| [RenderResourceFactory](#renderresourcefactory20) | RenderResourceFactory instance for creating rendering resources.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, RenderContext,
  RenderResourceFactory } from '@kit.ArkGraphics3D';

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

### loadPlugin
loadPlugin(name: string): Promise\<boolean>

Loads a plugin by name. The API locates and loads the corresponding plugin resource using the provided plugin name. It uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| name | string | Yes| Name of the plugin to load, which must be a system predefined or registered and available plugin name, and follow the naming conventions.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<boolean> | Promise used to return a Boolean value, indicating whether the plugin is loaded. The value **true** means that the plugin is loaded, and **false** means the opposite.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, RenderContext,
  RenderResourceFactory } from '@kit.ArkGraphics3D';

function loadPlugin(): Promise<boolean> {
  const renderContext: RenderContext | null = Scene.getDefaultRenderContext();
  if (!renderContext) {
    console.error("RenderContext is null");
    return Promise.resolve(false);
  }
  return renderContext.loadPlugin("pluginName");
}
```

### registerResourcePath<sup>20+</sup>
registerResourcePath(protocol: string, uri: string): boolean

Registers the directory path and retrieval name for asset files, such as shaders. It allows the system to find and replace the path descriptions of related files within the shaders using the retrieval name. This ensures that the correct paths for assets and their associated files are located and loaded properly.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| protocol | string | Yes| Retrieval name for the path. It must be a non-empty string that is not already predefined or registered by the system.|
| uri | string | Yes| Directory path of the assets, which corresponds to the retrieval name. It must be the path to the folder containing the asset files.|

**Return value**
| Type| Description|
| ---- | ---- |
| boolean | Result indicating whether the registration is successful. **true** if successful, and **false** otherwise. The possible cause of a registration failure is that the retrieval name has been registered or an input parameter is invalid.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, RenderContext,
  RenderResourceFactory } from '@kit.ArkGraphics3D';

function registerResourcePath(): void {
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
Describes the rendering parameters.

**System capability**: SystemCapability.ArkUi.Graphics3D
| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| alwaysRender<sup>15+</sup> | boolean | No| Yes| Whether to render every frame. The value **true** means to render every frame, and **false** means to render frames on demand. The default value is **true**.|


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

Loads a resource by path. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| uri | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr) | No| Path of the model file resource to load. The default value is undefined.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[Scene](#scene-1)> | Promise used to return the Scene object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function loadModel() : void {
  // Load the model.
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
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
| [Node](js-apis-inner-scene-nodes.md#node) \| null | Returns the Node object requested. If no node is found in the specified path or the found node type does not match the expected type, null is returned.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function getNode() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
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
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
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
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
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
    let content = await result.getResourceFactory().createScene($rawfile("gltf/DamagedHelmet/glTF/DamagedHelmet.glb"))
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

Creates a component and attaches it to a node. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | Yes| Node to which the component will be attached.|
| name | string | Yes| Name of the component to create, which is defined by individual plugins.|

**Return value**
| Type| Description|
| ---- | ---- |
| Promise\<[SceneComponent](#scenecomponent20)> | Promise used to return the SceneComponent object created.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';
import { SceneComponent } from '@ohos.graphics.scene';


function createComponentTest(): Promise<SceneComponent> {
  return Scene.load($rawfile("gltf/DamagedHelmet/glTF/DamagedHelmet.glb"))
    .then(scene => {
      if (!scene) {
        return Promise.reject(new Error("Scene load failed"));
      }
      // RenderConfigurationComponent is an internal component of the engine. You do not need to install plugins when creating the component.
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

Obtains the component instance from a node based on the component name.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | Yes| Node to which the component is attached.|
| name | string | Yes| Name of the component to obtain. The value must be a system predefined or registered custom component name, and follow the naming conventions.|

**Return value**
| Type| Description|
| ---- | ---- |
| [SceneComponent](#scenecomponent20) \| null | SceneComponent object corresponding to the given name, or **null** if not found.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, Geometry, CubeGeometry, MeshResource, SceneComponent } from '@kit.ArkGraphics3D';

function getComponentTest() {
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

Obtains the rendering context associated with the current graphics object.

**Return value**
| Type| Description|
| ---- | ---- |
| [RenderContext](#rendercontext20) \| null | Rendering context associated with the current object, or **null** if no rendering context is associated.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, Geometry, CubeGeometry, MeshResource, SceneComponent, RenderContext } from '@kit.ArkGraphics3D';

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
