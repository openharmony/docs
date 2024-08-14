# ArkUI子系统Changelog

## component3d获取资源的路径格式由Resource类型兼容性变更到ResourceStr类型

**访问级别**

公开接口

**变更原因**

component3D组件兼容性增加获取系统路径上的资源

**变更影响**

该变更为非兼容性变更

变更前：component3D资源获取只支持从rawfile路径读取
变更后：component3D资源获取既支持从rayfile路径读取也支持从磁盘路径读取

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.43开始

**适配指导**

```ts
@Component
export default struct Component3DView {
    build() { 
        Column(){
            Component3D({scene: undefined, modelType:ModelType.SURFACE})
            // 变更前
            .shader($rawfile(`assets/app/shaders/shader/demo.shader`))
            // 变更后 下面两种形式都支持
            .shader($rawfile(`assets/app/shaders/shader/demo.shader`))
            .customRender(`/data/storage/el2/base/files/` + `assets/app/shaders/shader/demo.shader`)
        }
    }
}
```

以下类型赋值需要做兼容性修改

1. SceneOptions修改适配
```ts
// SDK
declare interface SceneOptions {
    scene?: ResourceStr | Scene; // 新版本由Resource变更为ResourceStr类型
    modelType?: ModelType;
}

// 开发者侧代码
const item: SceneOptions = { scene: this.scene, modelType: ModelType.SURFACE }
// 变更后下面这行会导致编译错误
const scene: Resource = item.scene;
// 需要修改为：
const scene: ResourceStr = item.scene;
```

2. SceneResourceParameters修改适配
```ts
// SDK
export interface SceneResourceParameters修改适配 {
    name: string;
    uri?: ResourceStr;  // 新版本由Resource变更为ResourceStr类型
}

// 开发者侧代码
const params1: SceneResourceParameters = { name: "name1", uri: $rawfile("default_path") }
// 变更后下面这行会导致编译错误
const uri: Resource = params1.uri;
// 需要修改为：
const uri: ResourceStr = params1.uri;
```