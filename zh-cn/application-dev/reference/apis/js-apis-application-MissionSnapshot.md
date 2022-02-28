# MissionSnapshot


> **说明：**
> 本模块首批接口从API 8开始支持。


任务对应的任务快照。


## 导入模块

使用前需导入ElementName和image


```
import { ElementName } from '../bundle/elementName';
import { image } from '../@ohos.multimedia.image';
```


## MissionSnapshot

表示任务对应的任务快照的枚举。

  | 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| ability | ElementName | 是 | 是 | 表示Ability任务元素名称。 |
| snapshot | [image.PixelMap](js-apis-image.md) | 是 | 是 | 表示任务快照。 |
