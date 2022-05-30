# MissionSnapshot


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


任务对应的任务快照。


## 导入模块

```
import MissionSnapshot from "@ohos.application.missionSnapshot";
```
## 使用说明

使用前需要提前引入对应模块。

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
