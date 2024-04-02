# 图形图像变更说明

## cl.graphic.1  effectkit getPixelMap 同步接口替换为 getEffectPixelMap 异步接口

**访问级别**

公开接口

**废弃原因**

getPixelMap 耗时较长，在主线程调用会阻塞其余代码执行，故废弃，用异步接口替代

**废弃影响**

该变更为非兼容性变更，需要开发者适配。

**API Level**
9

**废弃发生版本**

从OpenHarmony SDK 4.1.5.5开始。

**废弃的接口**

| 接口声明                                                     | 废弃说明                                                     | 替代接口                                                     |
| ------------------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| getPixelMap():image.PixelMap; | 该接口耗时长，废弃后统一替换成异步接口   | getEffectPixelMap():Promise<image.PixelMap>; |

**适配指导**
类似以下调用方式
```ts
import image from "@ohos.multimedia.image";
import effectKit from "@ohos.effectKit";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
};
image.createPixelMap(color, opts).then((pixelMap) => {
  let pixel = effectKit.createEffect(pixelMap).grayscale().getPixelMap();
  console.log('getPixelBytesNumber = ', pixel.getPixelBytesNumber());
})
```
将
```ts
let pixel = effectKit.createEffect(pixelMap).grayscale().getPixelMap();
```
替换为
```ts
effectKit.createEffect(pixelMap).grayscale().getEffectPixelMap().then(data => {
    let pixel = data;
}).catch(ex => console.log("getEffectPixelMap error: " + ex.toString()));
```
即将 getPixelMap 替换为 getEffectPixelMap ，用 promise 的方式接收回调回来的 pixelMap 对象


## cl.blendMode.1 blendMode接口变更

**访问级别**

公开接口

**变更原因**

之前接口行为不够通用，难以满足三方应用多场景需求实现。当前有三方场景无法满足, 诉求进行变更。

**变更影响**

该变更为不兼容变更。<br>
1、使用blendMode接口时，开发者调用接口枚举发生变化。枚举NORMAL变为NONE，SOURCE_IN变为SRC_IN, DESTINATION_IN变为DST_IN。<br>
2、接口行为由当前控件背景与子节点内容进行混合改为当前控件内容（含子节点内容）与下方画布（可能为离屏画布）已有内容进行混合。

**API Level**

11

**变更发生版本**

从Openharmony SDK 4.1.6.3 开始

**变更的接口/组件**

blendMode接口枚举和接口行为进行非兼容性变更。

**适配指导**

1、开发者需将原先调用枚举由NORMAL改为NONE，SOURCE_IN改为SRC_IN，DESTINATION_IN改为DST_IN。<br>
2、由于接口行为发生改变，之前的接口内含两次离屏，第一次离屏用来绘制控件背景，第二次离屏用来绘制子节点内容。当前接口仅可支持一次离屏，需调用BlendApplyType.OFFSCREEN来触发离屏，接口默认无离屏。若想与原有接口行为保持一致，接口需调用两次来保持两次离屏。其中第一次离屏用来绘制控件背景，第二次离屏用来绘制子节点内容。<br>
示例代码：
```ts
// xxx.ets 新接口，可通过调用BlendApplyType.OFFSCREEN触发一次离屏
@Entry
@Component
struct Index {
  build() {
    Column() {
      // 第二次离屏用来绘制子节点内容
      Text("test")
        .fontSize(144)
        .fontWeight(FontWeight.Bold)
        .fontColor('#ffff0101')
        .blendMode(BlendMode.SRC_IN, BlendApplyType.OFFSCREEN)
    }
   // 第一次离屏用来绘制控件背景
    .blendMode(BlendMode.SRC_OVER, BlendApplyType.OFFSCREEN)
    .height('100%')
    .width('100%')
    .backgroundColor('#ff08ff00')
  }
}

// xxx.ets 旧接口，内部默认触发两次离屏
@Entry
@Component
struct Index {
  build() {
    Column() {
      // 第二次离屏用来绘制子节点内容
      Text("test")
        .fontSize(144)
        .fontWeight(FontWeight.Bold)
        .fontColor('#ffff0101')
    }
    // 第一次离屏用来绘制控件背景
    .blendMode(BlendMode.SRC_IN)
    .height('100%')
    .width('100%')
    .backgroundColor('#ff08ff00')
  }
}
```