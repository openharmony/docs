# @ohos.hiviewdfx.hiRetrieval (应用灰度)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @lyj_love_code-->
<!--Designer: @jiangwenhao-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

本模块提供应用灰度故障维测能力，支持以下故障类型：RSS内存泄漏、ArkTS-OOM、FD内存泄漏、GPU内存泄漏。应用灰度特性是一种运维态功能，用于精准采集故障日志。开发者在端侧集成应用灰度功能后，该应用可参与应用灰度活动。通过云端平台发布应用灰度任务，可圈选部分设备开启故障日志精准采集，帮助开发者快速定位故障。

**起始版本：** 26.0.0

## 导入模块

```ts
import { hiRetrieval } from '@kit.PerformanceAnalysisKit';
```

## HiRetrievalConfig

应用灰度活动配置。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiRetrieval

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | ------ | -- | ---- | ------- |
| userType | string | 否 | 否 | 用户类型参数，用于标识用户群体特征，如'newUser'、'vipUser'等。参数值由开发者自定义，无格式和字符类型限制，最长支持128个字符，超出部分将被截断。这些参数将作为算法输入，影响灰度圈选策略。 |
| deviceType | string | 否 | 否 | 设备类型参数，用于标识设备分类特征（具体值由开发者根据业务需求定义）。参数值由开发者自定义，无格式和字符类型限制，最长支持128个字符，超出部分将被截断。这些参数将作为算法输入，影响灰度圈选策略。 |
| deviceModel | string | 否 | 否 | 设备型号参数，用于标识具体设备型号（具体值由开发者根据业务需求定义）。参数值由开发者自定义，无格式和字符类型限制，最长支持128个字符，超出部分将被截断。这些参数将作为算法输入，影响灰度圈选策略。 |

## hiRetrieval.init

init(): void

初始化应用灰度模块。多实例应用不支持调用此接口。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiRetrieval

**错误码：**

以下错误码的详细介绍请参见[应用灰度错误码](errorcode-hiviewdfx-hiretrieval.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| 36000002 | Multi-instance applications not supported error. Possibly caused by invoking this function in a multi-instance application.         |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hiRetrieval } from '@kit.PerformanceAnalysisKit';

try {
  // 初始化应用灰度模块
  hiRetrieval.init();
} catch (err) {
  // 捕获并打印错误信息
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
// 后续可以完成其他的灰度接口调用
```

## hiRetrieval.participate

participate(config: HiRetrievalConfig): void

设置此设备参与应用灰度活动。调用后向服务器发送参与灰度消息和应用灰度活动配置，服务器标记此设备为可圈选并记录该应用灰度活动配置作为算法参数。多次调用将更新为最新的应用灰度活动配置。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiRetrieval

**参数：**

| 参数名    | 类型                      | 必填 | 说明                     |
| --------- | ------------------------- | ---- | ---------------------- |
| config | [HiRetrievalConfig](#hiretrievalconfig) | 是 | 开发者指定的应用灰度活动配置。用于设置此设备参与应用灰度活动时的用户类型、设备类型和设备型号信息，服务器将记录这些配置作为算法参数，用于圈选设备。不同参数值会影响设备参与应用灰度活动的概率和采集的日志类型。 |

**错误码：**

以下错误码的详细介绍请参见[应用灰度错误码](errorcode-hiviewdfx-hiretrieval.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 36000001 | Initialization error. Possibly caused by invoking this function before invoking init function.                                                  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hiRetrieval } from '@kit.PerformanceAnalysisKit';

let config: hiRetrieval.HiRetrievalConfig = {
  'userType': "testUserType",
  'deviceType': "deviceType",
  'deviceModel': "deviceModel"
}
try {
  // 初始化应用灰度模块
  hiRetrieval.init();
  // 设置设备参与应用灰度活动
  hiRetrieval.participate(config);
} catch (err) {
  // 捕获并打印错误信息
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

## hiRetrieval.quit

quit(): void

设置此设备退出应用灰度活动，退出后此设备将无法在云端被圈选。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiRetrieval

**错误码：**

以下错误码的详细介绍请参见[应用灰度错误码](errorcode-hiviewdfx-hiretrieval.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------------------------------------------------------------------------- |
| 36000001 | Initialization error. Possibly caused by invoking this function before invoking init function.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hiRetrieval } from '@kit.PerformanceAnalysisKit';

try {
  // 初始化应用灰度模块
  hiRetrieval.init();
  // 设置设备退出应用灰度活动
  hiRetrieval.quit();
} catch (err) {
  // 捕获并打印错误信息
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

## hiRetrieval.isParticipant

isParticipant(): boolean

查询此设备是否正在参与应用灰度活动。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiRetrieval

**返回值：**

| 类型                | 说明                                                         |
| ------------------- | ----------------------------------------------------------- |
| boolean | 标识此设备现在是否正在参与应用灰度活动，true表示正在参与，false表示未参与。 |

**示例：**

```ts
import { hiRetrieval } from '@kit.PerformanceAnalysisKit';

let isParticipant = hiRetrieval.isParticipant();
```

## hiRetrieval.getLastParticipationTimestamp

getLastParticipationTimestamp(): number

查询此设备上次参与应用灰度活动的UNIX时间戳，如果此设备从未参与则返回0。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiRetrieval

**返回值：**

| 类型                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| number | 上一次参与应用灰度活动的UNIX时间戳，单位为毫秒。如果此设备从未参与则返回0。 |

**示例：**

```ts
import { hiRetrieval } from '@kit.PerformanceAnalysisKit';

// 查询设备上次参与应用灰度活动的时间戳
let ts = hiRetrieval.getLastParticipationTimestamp();
```

## hiRetrieval.run

run(): void

若此设备正在参与应用灰度活动（即已调用[participate](#hiretrievalparticipate)接口且未调用[quit](#hiretrievalquit)接口），则应用灰度模块开始工作，否则调用该接口不会产生任何效果。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiRetrieval

**错误码：**

以下错误码的详细介绍请参见[应用灰度错误码](errorcode-hiviewdfx-hiretrieval.md)。

| 错误码ID | 错误信息 |
| -------- | -------------------------------------------------------------------------------------------------- |
| 36000001 | Initialization error. Possibly caused by invoking this function before invoking init function.     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hiRetrieval } from '@kit.PerformanceAnalysisKit';

try {
  // 初始化应用灰度模块
  hiRetrieval.init();
  // 开始运行应用灰度模块
  hiRetrieval.run();
} catch (err) {
  // 捕获并打印错误信息
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

## hiRetrieval.getCurrentConfig

getCurrentConfig(): HiRetrievalConfig

获取当前应用灰度活动配置。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiRetrieval

**返回值：**

| 类型                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| [HiRetrievalConfig](#hiretrievalconfig) | 当前应用灰度活动配置，包含用户类型、设备类型、设备型号等参数，用于标识和圈选设备参与应用灰度活动。 |

**示例：**

```ts
import { hiRetrieval } from '@kit.PerformanceAnalysisKit';

// 获取当前应用灰度活动配置
let cfg = hiRetrieval.getCurrentConfig();
```
