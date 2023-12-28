# 图形子系统变更说明

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
