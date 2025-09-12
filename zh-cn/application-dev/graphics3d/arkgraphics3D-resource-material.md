# 创建并使用材质资源
<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--Designer: @zdustc-->
<!--Tester: @zhangyue283-->
<!--Adviser: @ge-yafang-->

材质（Material）：材质是用于定义物体表面视觉效果的重要资源。材质决定了物体如何与光线交互，从而影响其最终的渲染效果，如颜色、金属感、粗糙度等外观属性。

ArkGraphics 3D采用基于物理的渲染（PBR, Physically-Based Rendering）模型，其材质实现遵循通用的PBR原理。开发者既可以使用标准材质快速实现真实感效果，也可以通过自定义Shader材质灵活控制渲染逻辑。

## 基本概念

着色器（Shader）：着色器是GPU上可以执行的一段程序，可以控制GPU执行哪些并行计算操作。AGP引擎提供的默认着色器实现了PBR渲染，开发者只需要指定对应的参数就可以完成不同的PBR渲染。

ArkGraphics 3D支持开发者创建自定义的着色器，开发者可以通过自定义着色器自定义渲染计算过程，完全控制渲染计算流程，比如控制某物体不受某光源的影响、自定义边缘描边、高亮效果等个性化视觉呈现。

着色器通常配合MaterialType.SHADER材质使用，是实现个性化渲染的重要手段。其创建依赖名称及沙箱路径，创建后可绑定至材质上，替代默认的渲染行为。

## 材质类型（MaterialType）
ArkGraphics 3D中的材质类型通过[MaterialType](../reference/apis-arkgraphics3d/js-apis-inner-scene-resources.md#materialtype)枚举指定，目前支持以下两种类型：

- MaterialType.SHADER：基于Shader（着色器）的材质类型，支持绑定自定义着色器，开发者可通过自定义渲染程序实现个性化的视觉表现，适用于高级图形渲染需求。

- MaterialType.METALLIC_ROUGHNESS：基于金属-粗糙度模型的标准PBR材质类型，符合glTF材质规范，适合快速构建真实感渲染效果，支持设置基础色、金属度、粗糙度、法线贴图等常见属性。

材质的创建一般通过[SceneResourceFactory.createMaterial()](../reference/apis-arkgraphics3d/js-apis-inner-scene.md#creatematerial)方法完成，需指定材质名称和类型。不同类型的材质支持不同的参数配置，开发者可按需选择以实现预期的渲染效果。


## 材质的属性
材质的属性定义了其在渲染时的视觉表现行为，例如颜色、金属感、粗糙度、光照响应以及透明度控制等。通过设置这些属性，开发者可以精准控制物体在场景中的外观效果。

在ArkGraphics 3D中，材质属性设计既提供了统一的基础能力，也根据材质类型提供了差异化扩展，满足从基础场景搭建到高级视觉定制的多样需求。


### 通用属性
所有材质均具备以下基础属性（如materialType、shadowReceiver、blend等）可通过设置[Material](../reference/apis-arkgraphics3d/js-apis-inner-scene-resources.md#material)类型对象实现，用于控制材质的类型及其渲染基础行为：

- materialType：材质类型，标识该材质是标准PBR材质还是基于Shader的自定义材质。

  适用场景：当需要快速使用预设真实感材质时选择PBR材质，需实现个性化或特殊渲染效果时选择Shader材质。

- shadowReceiver：材质是否可以接收场景中的阴影投射，true表示可以接收，false表示不能接收，默认为false。

  适用场景：需要表现阴影效果的物体，如地面、墙体、角色等开启；纯发光物体或不参与阴影计算的可关闭以优化性能。

- cullMode：剔除模式，决定是否剔除背面几何体，默认值为BACK，即剔除背面。

  适用场景：普通实体模型一般开启剔除背面提升渲染效率；透明或双面材质（如树叶、布料）需要禁用剔除以显示完整模型。

- blend：是否启用材质的透明效果模式。true表示开启透明，false表示关闭透明，默认值为false。

  适用场景：表现透明或半透明材质时开启，如玻璃、水面、烟雾、透明塑料等。

- alphaCutoff：透明度阈值，取值范围[0,1]，默认值为1。像素的alpha值低于该阈值时不进行渲染，用于实现透明裁剪效果。

  适用场景：需要硬透明裁剪的材质，比如树叶、铁丝网、布料边缘等带有透明区域但无半透明渐变的模型。通过设置阈值，可以快速裁剪掉透明部分像素。

- renderSort：渲染排序设置，用于控制材质在渲染队列中的渲染顺序，确保透明或特殊效果材质正确叠加显示。

  适用场景：多重透明材质、叠加特效、UI元素等需要严格渲染顺序的场景。

### PBR材质属性
符合glTF标准的基于物理渲染（PBR）的金属-粗糙度材质，通过设置[MetallicRoughnessMaterial](../reference/apis-arkgraphics3d/js-apis-inner-scene-resources.md#metallicroughnessmaterial20)实现，其中各项属性采用[MaterialProperty](../reference/apis-arkgraphics3d/js-apis-inner-scene-resources.md#materialproperty20)类型封装，支持绑定纹理和设置因子（factor）值。具体属性包括：

- baseColor：基础颜色和透明度，包含纹理及对应因子，用于定义材质表面的主色调。

  适用场景：所有材质的基本颜色设置，适用于任何物体表面，尤其是需要表现颜色和透明度的模型。

- normal：法线贴图，用于模拟表面细节凹凸，增强光照效果的真实感。

  适用场景：需要表现表面细节如石材纹理、皮肤毛孔、木纹凹凸等，提升真实感的模型。

- material：金属度、粗糙度与反射率参数，描述材质表面的光学特性。

  适用场景：区分金属和非金属表面，控制材质的光滑或粗糙程度，常用于金属件、塑料、橡胶等多种材质。

- ambientOcclusion：环境光遮蔽贴图，提升材质细节处的阴影层次和真实感。

  适用场景：增强模型细节阴影效果，适合复杂结构或细节丰富的物体，如建筑物裂缝、机械零件缝隙。

- emissive：自发光颜色及纹理，表达材质自发光的效果。

  适用场景：灯光、屏幕、发光标志、荧光材料等需要表现光源或自发光效果的材质。

- clearCoat：清漆层强度，模拟车漆等具有透明反光层的材质。

  适用场景：汽车车身、家具表面等有光泽涂层的材质，表现透明光泽和反射。

- clearCoatRoughness：清漆层的粗糙度，控制清漆层的反光细节。

  适用场景：配合clearCoat使用，调节涂层表面的光滑度或粗糙感。

- clearCoatNormal：清漆层法线贴图，增强清漆层的光照变化。

  适用场景：清漆层带有细节纹理时使用，增加涂层的真实光照反馈。

- sheen：微纤维漫反射层，用于表现布料、织物的光泽感。

  适用场景：衣物、窗帘、沙发等纺织品，表现柔和的光泽和细腻质感。

- specular：镜面反射属性，控制非金属材质的高光反射强度。

  适用场景：玻璃、水面、塑料等非金属材质的高光表现，增强材质的镜面反射效果。


## 开发步骤
  1. 获取资源工厂。

     使用场景对象Scene或其他接口，获取资源工厂SceneResourceFactory实例，用于创建材质资源。

       ```ts
     // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
     let scenePromise: Promise<Scene> = Scene.load($rawfile("gltf/ExampleModel.glb"));
     scenePromise.then(async (scene: Scene) => {
     if (!scene.root) {
         return;
     }
     let rf: SceneResourceFactory = scene.getResourceFactory();
     // 后续操作可基于rf进行
     });
       ```

  2. 创建材质并指定材质类型。

     调用createMaterial()接口，指定材质类型（如MaterialType.METALLIC_ROUGHNESS或MaterialType.SHADER），异步创建材质对象。

     - 可创建基于Shader的材质，当开发者需要自定义渲染效果时，可通过自定义Shader实现。示例代码如下：

       ```ts
       let shaderMaterialPromise = await rf.createMaterial({ name: "shaderMat" }, MaterialType.SHADER);
       let shaderMat = shaderMaterialPromise as ShaderMaterial;
       // 绑定自定义Shader代码示例（创建shader资源，路径和文件名可根据项目实际资源自定义）
       let shader = await rf.createShader({ name: "MyShader", uri: $rawfile("shaders/my_shader.shader") });
       shaderMat.colorShader = shader;
       ```

     - 也可创建基于PBR的材质，当开发者需要快速构建真实感渲染效果时，可使用预设的参数快速实现。示例代码如下：

       ```ts
       let pbrMaterialPromise = await rf.createMaterial({ name: "pbrMat" }, MaterialType.METALLIC_ROUGHNESS);
       let pbrMat = pbrMaterialPromise as MetallicRoughnessMaterial;
       // 设置基础颜色贴图和因子
       // 加载图片资源，路径和文件名可根据项目实际资源自定义，但PBR材质贴图类型必须与材质属性匹配
       let baseColorImage = await rf.createImage({ name: "baseColorTex", uri: $rawfile("textures/baseColor.png") });
       pbrMat.baseColor.image = baseColorImage;
       pbrMat.baseColor.factor = { x: 1, y: 1, z: 1, w: 1 };
       ```

  3. 设置材质属性。

     - 设置材质通用属性。示例代码如下：

       ```ts
       material.shadowReceiver = true;  // 启用阴影接收
       material.cullMode = CullMode.BACK;  // 剔除背面
       material.blend = { enabled: true };  // 启用透明混合
       material.alphaCutoff = 0.5;  // 透明裁剪阈值
       material.renderSort = { renderSortLayer: 32, renderSortLayerOrder: 1 };  // 渲染排序
       ```

     - 当创建的材质类型为PBR材质时，还可以设置PBR材质属性。示例代码如下：

       不同属性的贴图内容通常不同，需分别创建；如多个材质共用相同贴图，可复用同一个Image实例以节省内存。所有材质属性中的factor各分量取值范围均为[0, 1]。

       ```ts
       // 图片路径和文件名可根据项目实际资源自定义，但PBR材质贴图类型必须与材质属性匹配
       // 设置基础颜色贴图和颜色因子（支持透明通道）
       let baseColorImage = await rf.createImage({ name: "baseColorTex", uri: $rawfile("textures/baseColor.png") });
       pbrMat.baseColor.image = baseColorImage;
       pbrMat.baseColor.factor = { x: 1, y: 1, z: 1, w: 1 }; // xyz分量控制颜色，w为透明度（0~1）
       // 设置法线贴图（控制细节凹凸感）
       let normalImage = await rf.createImage({ name: "normalTex", uri: $rawfile("textures/normal.png") });
       pbrMat.normal.image = normalImage;
       pbrMat.normal.factor.x = 0.6; // x分量：法线强度（0~1）
       // 设置金属度、粗糙度和反射率属性（可共享一张贴图），通常使用y, z, w分量分别控制
       let metallicRoughnessImage = await rf.createImage({ name: "materialTex", uri: $rawfile("textures/material_texture.png") });
       pbrMat.material.image = metallicRoughnessImage;
       pbrMat.material.factor.y = 1.0;  // y 分量：粗糙度（Roughness, 0~1），0表示光滑，1表示粗糙
       pbrMat.material.factor.z = 0.5;  // z 分量：金属度（Metallic, 0~1），0表示非金属，1表示金属
       pbrMat.material.factor.w = 0.5;  // w 分量：反射率（Specular, 0~1）
       // 设置环境光遮蔽贴图，常用x分量控制遮蔽强度
       let ambientOcclusionImage = await rf.createImage({ name: "ambientOcclusionTex", uri: $rawfile("textures/ambientOcclusion.png") });
       pbrMat.ambientOcclusion.image = ambientOcclusionImage;
       pbrMat.ambientOcclusion.factor.x = 1.0; // 遮蔽强度（0~1）
       // 设置自发光贴图和颜色因子（用于夜光效果）
       let emissiveImage = await rf.createImage({ name: "emissiveTex", uri: $rawfile("textures/emissive.png") });
       pbrMat.emissive.image = emissiveImage;
       pbrMat.emissive.factor = { x: 1.0, y: 1.0, z: 0.8, w: 1 }; // xyz分量控制发光颜色，w为强度（0~1）
       // 设置clearCoat强度与粗糙度
       pbrMat.clearCoat.factor.x = 1.0; // x分量：clearCoat强度（0~1）
       pbrMat.clearCoatRoughness.factor.y = 0.5; // y分量：clearCoat粗糙度（0~1）
       // 设置clearCoat法线贴图,常用x，y，z控制方向
       let clearCoatNormalImage = await rf.createImage({ name: "clearCoatNormalTex", uri: $rawfile("textures/clearCoatNormal.png") });
       pbrMat.clearCoatNormal.image = clearCoatNormalImage;
       pbrMat.clearCoatNormal.factor.x = 1.0;
       pbrMat.clearCoatNormal.factor.y = 1.0;
       pbrMat.clearCoatNormal.factor.z = 1.0;
       // 更多PBR属性可按需设置，如sheen、specular等。
       // sheen：控制光泽强度
       // pbrMat.sheen.factor = { x: 1.0, y: 0.5, z: 0.3, w: 1.0 }; // xyz控制光泽的颜色，w为强度（0~1）

       // specular：控制高光
       // pbrMat.specular.factor = { x: 1.0, y: 1.0, z: 1.0, w: 0.7 }; // xyz为高光颜色，w为高光强度（0~1）
       ```

     - 针对Shader材质，需绑定自定义Shader资源以实现个性化渲染效果。具体使用方式可参考[创建Shader材质并设置属性](#创建shader材质并设置属性)。

  4. 绑定材质到网格。

     将创建的材质赋值给几何体（Geometry）的material或subMeshes[i].material字段，使其生效。常见绑定方式有两种：

       - 通过资源工厂新建网格和几何体，再绑定材质（适用于创建新几何体的情况）。示例代码如下：

         ```ts
         let mesh = await resourceFactory.createMesh({ name: "mesh" }, geometry);
         let geometryInstance = await resourceFactory.createGeometry({ name: "geometry" }, mesh);
         geometryInstance.mesh.subMeshes[0].material = pbrMat;  // 绑定材质
         ```

       - 通过scene.root.getNodeByPath直接获取已有几何节点，修改绑定材质（适用于加载场景后修改材质）。示例代码如下：

         ```ts
         let pbrNode = scene.root.getNodeByPath("path/to/node");
         if (pbrNode) {
           let geometry = pbrNode as Geometry;
           if (geometry.mesh?.subMeshes?.[0]) {
             geometry.mesh.subMeshes[0].material = pbrMat;  // 绑定材质
           }
         }
         ```

  5. 渲染并观察效果。运行渲染流程，观察材质的最终视觉表现。


## 完整代码

  ### 创建Shader材质并设置属性

   ```ts
   import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
     LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, Geometry,
     CullMode } from '@ohos.graphics.scene';

   function createAndApplyShaderMaterial(): Promise<void> {
     // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
     let scenePromise: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
     return scenePromise.then(async (scene: Scene) => {
       if (!scene.root) {
         return;
       }
       // 获取资源工厂
       let rf: SceneResourceFactory = scene.getResourceFactory();
       // 创建Shader材质
       let materialParams: SceneResourceParameters = { name: "material" };
       let material = await rf.createMaterial(materialParams, MaterialType.SHADER);
       let shaderMat = material as ShaderMaterial;
       // 加载并绑定自定义Shader代码（创建shader资源，路径和文件名可根据项目实际资源自定义）
       let shader = await rf.createShader({
         name: "shaderResource",
         uri: $rawfile("shaders/custom_shader/custom_material_sample.shader")
       });
       shaderMat.colorShader = shader;
       // 设置通用属性
       shaderMat.shadowReceiver = true;
       shaderMat.cullMode = CullMode.BACK;
       shaderMat.blend = { enabled: true }; // 例如启用透明混合
       shaderMat.alphaCutoff = 0.5;
       // 绑定材质到已有网格节点
       let shaderNode = scene.root.getNodeByPath("rootNode_/Unnamed Node 1/AnimatedCube");
       if (shaderNode) {
         let geometry = shaderNode as Geometry;
         if (geometry.mesh?.subMeshes?.[0]) {
           geometry.mesh.subMeshes[0].material = shaderMat;
         }
       }
       // 后续执行渲染观察效果
     });
   }
   ```

  ### 创建PBR材质并设置属性
  
  不同模型支持的PBR属性可能有所不同，设置材质前建议根据模型内容进行适配。本例使用CompareClearcoat模型作为示例，设置其支持的PBR属性，开发者可根据需要使用对应模型并设置相关属性。

   ```ts
   import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
     LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, MetallicRoughnessMaterial,
     Geometry, CullMode } from '@ohos.graphics.scene';

   function createAndApplyPBRMaterial(): Promise<void> {
     // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
     // 不同模型支持的PBR属性可能有所不同，设置材质前建议根据模型内容进行适配，本例使用CompareClearcoat模型作为示例。
     let scenePromise: Promise<Scene> = Scene.load($rawfile("CompareClearcoat.glb"));
     return scenePromise.then(async (scene: Scene) => {
       if (!scene.root) {
         return;
       }
       // 获取资源工厂
       let rf: SceneResourceFactory = scene.getResourceFactory();
       // 创建PBR材质
       let materialParams: SceneResourceParameters = { name: "MyPBRMaterial" };
       let material = await rf.createMaterial(materialParams, MaterialType.METALLIC_ROUGHNESS);
       let pbrMat = material as MetallicRoughnessMaterial;

       // 加载共享的metallic-roughness贴图（可复用，节省资源），图片路径和文件名可根据项目实际资源自定义，但贴图类型必须与材质属性匹配
       let metallicImage = await rf.createImage({
         name: "materialTex",
         uri: $rawfile("gltf/DamagedHelmet/glTF/Default_metalRoughness.jpg")
       });
       pbrMat.material.image = metallicImage;
       // 配置y，z，w分量控制粗糙度、金属度、反射率
       pbrMat.material.factor = { x: 0, y: 0.8, z: 0.4, w: 0.6 };
       // 配置环境光遮蔽贴图
       pbrMat.ambientOcclusion.factor.x = 1.0;
       // 配置clearCoat强度与粗糙度
       pbrMat.clearCoat.factor.x = 1.0;
       pbrMat.clearCoatRoughness.factor.y = 0.5;
       // 配置sheen光泽属性
       pbrMat.sheen.factor = { x: 1.0, y: 0.2, z: 0.2, w: 0.8 };

       // 设置通用属性
       pbrMat.shadowReceiver = true;
       pbrMat.cullMode = CullMode.BACK;
       pbrMat.blend = { enabled: false };
       pbrMat.alphaCutoff = 0.5;
       // 绑定材质到已有网格节点
       let pbrNode = scene.root.getNodeByPath("Unnamed Node 1/GeoSphere002");
       if (pbrNode) {
         let geometry = pbrNode as Geometry;
         geometry.mesh.subMeshes[0].material = pbrMat;
       }
       // 运行渲染流程，观察材质的最终视觉表现
     });
   }
   ```


<!--RP1-->
## 相关实例

对于3D资源更加综合的使用可以参考以下实例：
- [3D引擎接口示例（ArkTS）（API12）](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Graphics/Graphics3d)
<!--RP1End-->