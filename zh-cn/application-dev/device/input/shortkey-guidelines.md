# 系统预置全局快捷键开发指导

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @Brilliantry_Rui-->

## 场景介绍

系统预置全局快捷键提供设置快捷键拉起Ability延迟时间的能力。使用场景例如：按下快捷键五秒后截屏。

## 导入模块

```js
import { shortKey } from '@kit.InputKit';
```

## 接口说明

事件注入常用接口如下表所示，接口详细介绍请参考[ohos.multimodalInput.shortKey文档](../../reference/apis-input-kit/js-apis-shortKey-sys.md)。

| 接口名称  | 描述 |
| ------------------------------------------------------------ | -------------------------- |
| setKeyDownDuration(businessKey: string, delay: number, callback: AsyncCallback&lt;void&gt;): void |设置快捷键拉起Ability的延迟时间。 |

## 开发步骤

开发步骤以按下快捷键五秒后截屏为例。

```js
import { shortKey } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            shortKey.setKeyDownDuration("screenshot", 500, (error: BusinessError) => { //设置截屏应用screenshot延迟时间为5秒（500毫秒）
              if (error) {
                console.error(`Set key down duration failed, error: ${JSON.stringify(error, ["code", "message"])}`);
                return;
              }
              console.info(`Set key down duration success`);
            });
          } catch (error) {
            console.error(`Set key down duration failed, error: ${JSON.stringify(error, ["code", "message"])}`);
          }
        })
    }
  }
}
```


