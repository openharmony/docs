# @system.device (设备信息)
<!--Kit: Basic Services Kit-->
<!--Subsystem: Startup-->
<!--Owner: @chenjinxiang3-->
<!--Designer: @chenjinxiang3-->
<!--Tester: @liuhaonan2-->
<!--Adviser: @fang-jinxu-->

本模块提供当前设备的信息，通过读取系统配置获取设备品牌、型号、生产商、屏幕参数等基础信息，供开发者进行设备适配和功能判断。

> **说明：**
>
> - 模块维护策略
>
>    \- 对于Lite Wearable设备类型，该模块长期维护，正常使用。
>
>     \- 对于支持该模块的其他设备类型，该模块从API version 6开始不再维护，推荐使用新接口[@ohos.deviceInfo](js-apis-device-info.md)（从API version 6开始支持）进行设备信息查询。
>
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```typescript
import Device from '@system.device';
```
## Device
### Device.getInfo<sup>(deprecated)</sup>

getInfo(options?: GetDeviceOptions): void

获取当前设备的信息。该接口异步读取系统设备信息，通过回调函数返回设备品牌、型号、屏幕参数等数据。

> **说明：**<br>
> 在首页的onShow生命周期之前不建议调用Device.getInfo接口。

**系统能力：** SystemCapability.Startup.SystemInfo.Lite

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| void | 无返回值，设备信息通过回调函数返回。 |

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [GetDeviceOptions](#getdeviceoptionsdeprecated) | 否 | 定义设备信息获取的参数选项。省略时使用默认配置获取设备基本信息。 |

**示例：**

ArkTS（方舟编程语言）示例：

```typescript
interface DeviceData {
  brand: string;
}

export default class Page {
  getInfo() {
    try {
      Device.getInfo({
        success: (data: DeviceData) => {
          console.info(`Device information obtained successfully. Device brand: ${data.brand}`);
        },
        fail: (data: any, code: number) => {
          console.error(`Failed to obtain device information. Code: ${code}, message: ${data}`);
        },
      });
    } catch (error) {
      console.error('Failed to call device information API:', error);
    }
  }
}
```

JS示例：

```xml
<div class="container">
    <text class="title">Device Information</text>
    <input type="button" value="Get Device Brand" class="button" onclick="getDeviceInfo"></input>
    <text class="info">{{brandInfo}}</text>
</div>
```

```css
/* xxx.css */
.container {
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: center;
    left: 0px;
    top: 0px;
    width: 100%;
    height: 100%;
}

.title {
    font-size: 40px;
    text-align: center;
    width: 100%;
    height: 80px;
    margin-bottom: 50px;
}

.button {
    font-size: 30px;
    text-align: center;
    width: 240px;
    height: 80px;
    margin: 20px;
}

.info {
    font-size: 28px;
    text-align: center;
    width: 100%;
    height: 60px;
    margin-top: 50px;
    color: #007dff;
}
```

```js
// xxx.js
import Device from '@system.device';

export default {
  data: {
    brandInfo: 'Click the button to get device brand'
  },
  
  getDeviceInfo() {
    try {
      Device.getInfo({
        success: (data) => {
          console.info(`Device information obtained successfully. Device brand: ${data.brand}`);
          this.brandInfo = 'Device brand: ' + data.brand;
        },
        fail: (data, code) => {
          console.error(`Failed to obtain device information. Code: ${code}, message: ${data}`);
          this.brandInfo = 'Failed to obtain, error code: ' + code;
        },
      });
    } catch (error) {
      console.error('Failed to call device information API:', error);
      this.brandInfo = 'Current device does not support this API';
    }
  }
}
```

## GetDeviceOptions<sup>(deprecated)</sup>

定义设备信息获取的参数选项。

**系统能力：** SystemCapability.Startup.SystemInfo.Lite

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| success | (data: [DeviceResponse](#deviceresponsedeprecated)) => void | 否 | 接口调用成功的回调函数，在接口调用成功时执行。data 为成功返回的设备信息。不传入时无法获取设备信息，建议设置此回调。 |
| fail | (data: any, code: number) => void | 否 | 接口调用失败的回调函数，在接口调用失败时执行。data为失败时返回的错误信息对象或错误描述字符串，code为失败返回的错误码。<br>code:200，表示返回结果中存在无法获取的信息。建议设置此回调以处理错误情况。 |
| complete | () => void | 否 | 接口调用结束的回调函数，在接口调用完成后（无论成功或失败）执行，适用于需执行清理或收尾工作的场景。不传入时不执行结束回调。 |

**错误码**：

| 错误码ID | 错误信息 |
| --- | --- |
| 200 | 返回结果中存在无法获取的信息。可能原因包括：设备不支持部分信息字段、系统权限受限或设备配置缺失。解决措施：建议检查设备兼容性、确认应用权限配置，并设置此回调以处理错误情况。 |

## DeviceResponse<sup>(deprecated)</sup>

设备信息。

**系统能力：** SystemCapability.Startup.SystemInfo.Lite

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| brand | string | 品牌。 |
| manufacturer | string | 生产商。 |
| model | string | 型号。 |
| product | string | 产品代号。 |
| language<sup>4+</sup> | string | 系统语言。 |
| region<sup>4+</sup> | string | 系统地区。 |
| windowWidth | number | 可使用的窗口宽度，单位px。不同设备的可使用窗口尺寸存在差异。 |
| windowHeight | number | 可使用的窗口高度，单位px。不同设备的可使用窗口尺寸存在差异。 |
| screenDensity<sup>4+</sup> | number | 屏幕像素密度。表示屏幕每英寸的像素点数量，单位为dpi(dots per inch)。不同设备的屏幕像素密度存在差异。 |
| screenShape<sup>4+</sup> | string | 屏幕形状。可取值：<br>-&nbsp;rect：方形屏；<br>-&nbsp;circle：圆形屏。 |
| apiVersion<sup>4+</sup> | number | 系统API版本号。 |
| deviceType<sup>4+</sup> | string | 设备类型。常见取值：phone（手机）、tablet（平板）、tv（电视）、wearable（可穿戴设备）等。 |
| sdkMinorApiVersion | number  | 系统软件Minor API版本。从API 26.0.0 版本开始，系统API版本格式：apiVersion.sdkMinorApiVersion.sdkPatchApiVersion。该值获取失败时填充 -1，且不影响 getInfo 接口的整体返回状态。<br/>**模型约束：** 此接口仅可在FA模型下使用。<br/>**起始版本**：26.0.0<br/>示例：0 |
| sdkPatchApiVersion  | number  | 系统软件Patch API版本。从API 26.0.0 版本开始，系统API版本格式：apiVersion.sdkMinorApiVersion.sdkPatchApiVersion。该值获取失败时填充 -1，且不影响 getInfo 接口的整体返回状态。<br/>**模型约束：** 此接口仅可在FA模型下使用。<br/>**起始版本**：26.0.0<br/>示例：0 |