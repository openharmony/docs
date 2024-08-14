# ArkUI子系统Changelog

## component3d获取资源的路径格式由Resource类型兼容性变更到ResourceStr类型

**访问级别**

公开接口

**变更原因**

component3D组件需具备获取系统路径资源能力。

**变更影响**

该变更为非兼容性变更

变更前：component3D资源获取通过Resource方式，只支持从rawfile路径读取。
变更后：component3D资源获取修改为通过ResourceStr方式，既支持从rayfile路径读取也支持从磁盘路径读取。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.43开始

**变更的接口/组件**

Component3D获取资源的方式由Resource变更为ResourceStr。

**适配指导**

```ts
import scene3d from `@ohos.graphics.scene`

const params1: scene3d.SceneResourceParameters = { name: "name1", uri: $rawfile("default_path") }
// 变更前
const test_uri: Resource = params1.uri;
// 变更后适配为
const test_uri: ResourceStr = params1.uri;

@Entry
@Component
struct node_geometry {
    scene: scene3d.Scene | null = null;
    @State sceneOpt: SceneOptions | null = null;
    envImg: scene3d.Image | null = null;

    onPageShow(): void {
        this.Init();
    }

    onPageHide(): void {
        if (this.scene) {
            this.scene.destroy();
        }
    }

    Init(): void {
        if (this.scene == null) {
            scene3d.Scene.load($rawfile("default_path"))
            .then(async (result: scene3d.Scene) => {
                this.scene = result;
                this.sceneOpt = { scene: this.scene, modelType: ModelType.USRFACE } as SceneOptions;
                let rf: scene3d.SceneResourceFactory = this.scene.getResourceFactory();

                this.envImg = await rf.createImage({ name: "image1", uri: test_uri });
            });
        }
    }

    build() {
        Column() {
            Component3D(this.sceneOpt)
                .renderWidth('100%')
                .renderHeight('100%')
                .width('100%')
                .height('100%')
        }
    }
}
```