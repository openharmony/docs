# ArkUI子系统Changelog

## component3d获取资源的路径格式由Resource类型兼容性变更到ResourceStr类型

**访问级别**

公开接口

**变更原因**

component3D组件兼容性增加获取系统路径上的资源

**变更影响**

该变更为前向兼容

变更前：component3D资源获取只支持从rawfile路径获取
变更后：component3D资源获取既支持从rayfile路径获取也支持从系统ROM路径获取

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