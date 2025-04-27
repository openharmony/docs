# @ohos.vibrator \(振动\)<a name="ZH-CN_TOPIC_0000002206784304"></a>

-   [导入模块](#导入模块)
-   [vibrator.startVibration9+](#vibratorstartvibration9)
-   [vibrator.startVibration9+](#vibratorstartvibration9-1)
-   [vibrator.stopVibration9+](#vibratorstopvibration9)
-   [vibrator.stopVibration9+](#vibratorstopvibration9-1)
-   [vibrator.stopVibration10+](#vibratorstopvibration10)
-   [vibrator.stopVibration10+](#vibratorstopvibration10-1)
-   [vibrator.stopVibrationSync12+](#vibratorstopvibrationsync12)
-   [vibrator.isSupportEffect10+](#vibratorissupporteffect10)
-   [vibrator.isSupportEffect10+](#vibratorissupporteffect10-1)
-   [vibrator.isSupportEffectSync12+](#vibratorissupporteffectsync12)
-   [vibrator.isHdHapticSupported12+](#vibratorishdhapticsupported12)
-   [EffectId](#effectid)
-   [HapticFeedback12+](#hapticfeedback12)
-   [VibratorStopMode](#vibratorstopmode)
-   [VibrateEffect9+](#vibrateeffect9)
-   [VibrateTime9+](#vibratetime9)
-   [VibratePreset9+](#vibratepreset9)
-   [VibrateFromFile10+](#vibratefromfile10)
-   [HapticFileDescriptor10+](#hapticfiledescriptor10)
-   [VibrateAttribute9+](#vibrateattribute9)
-   [Usage9+](#usage9)
-   [vibrator.vibrate\(deprecated\)](#vibratorvibratedeprecated)
-   [vibrator.vibrate\(deprecated\)](#vibratorvibratedeprecated-1)
-   [vibrator.vibrate\(deprecated\)](#vibratorvibratedeprecated-2)
-   [vibrator.vibrate\(deprecated\)](#vibratorvibratedeprecated-3)
-   [vibrator.stop\(deprecated\)](#vibratorstopdeprecated)
-   [vibrator.stop\(deprecated\)](#vibratorstopdeprecated-1)

vibrator模块提供控制设备马达振动的能力。包括启动指定时长、预置效果、自定义文件等模式的振动；停止指定时长、预置效果或所有模式的振动。

>![](public_sys-resources/icon-note.gif) **说明：** 
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块<a name="导入模块"></a>

```
import { vibrator } from '@kit.SensorServiceKit';
```

## vibrator.startVibration<sup>9+</sup><a name="vibratorstartvibration9"></a>

startVibration\(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback<void\>\): void

根据指定的振动效果和振动属性触发马达振动。使用callback异步回调。

**需要权限**：ohos.permission.VIBRATE

**元服务API**：从API Version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

<a name="table1583399859172647"></a>
<table><thead align="left"><tr id="row1074428108172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry1793264859172647p0"><a name="entry1793264859172647p0"></a><a name="entry1793264859172647p0"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry203363940172647p0"><a name="entry203363940172647p0"></a><a name="entry203363940172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry1840746948172647p0"><a name="entry1840746948172647p0"></a><a name="entry1840746948172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry2105016191172647p0"><a name="entry2105016191172647p0"></a><a name="entry2105016191172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1201855309172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry90986689172647p0"><a name="entry90986689172647p0"></a><a name="entry90986689172647p0"></a>effect</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry271978689172647p0"><a name="entry271978689172647p0"></a><a name="entry271978689172647p0"></a><a href="#vibrateeffect9">VibrateEffect</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry1446285590172647p0"><a name="entry1446285590172647p0"></a><a name="entry1446285590172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p2121567780172647"><a name="p2121567780172647"></a><a name="p2121567780172647"></a>马达振动效果，支持三种：</p>
<p id="p1540475432172647"><a name="p1540475432172647"></a><a name="p1540475432172647"></a>1、<a href="#vibratetime9">VibrateTime</a>：按照指定持续时间触发马达振动，无起振/无刹车，不推荐使用此振动类型；</p>
<p id="p468977217172647"><a name="p468977217172647"></a><a name="p468977217172647"></a>2、<a href="#vibratepreset9">VibratePreset</a>：按照预置振动效果触发马达振动，适用于短振场景下调用；</p>
<p id="p900174939172647"><a name="p900174939172647"></a><a name="p900174939172647"></a>3、<a href="#vibratefromfile10">VibrateFromFile</a>：按照预置振动效果触发马达振动，适用于短振场景下调用；</p>
</td>
</tr>
<tr id="row1134128653172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry1561297179172647p0"><a name="entry1561297179172647p0"></a><a name="entry1561297179172647p0"></a>attribute</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry920333872172647p0"><a name="entry920333872172647p0"></a><a name="entry920333872172647p0"></a><a href="#vibrateattribute9">VibrateAttribute</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry2133737956172647p0"><a name="entry2133737956172647p0"></a><a name="entry2133737956172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p338712226536"><a name="p338712226536"></a><a name="p338712226536"></a>马达振动属性，用于指定振动的使用场景 (<a href="#usage9">Usage</a>) 等信息。usage 会影响系统层面的振动开关管控。</p>
</td>
</tr>
<tr id="row247335953172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry1145770235172647p0"><a name="entry1145770235172647p0"></a><a name="entry1145770235172647p0"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry498393573172647p0"><a name="entry498393573172647p0"></a><a name="entry498393573172647p0"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry138529385172647p0"><a name="entry138529385172647p0"></a><a name="entry138529385172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p883965121814"><a name="p883965121814"></a><a name="p883965121814"></a>回调函数。当马达振动成功，err为undefined；否则为错误对象，包含错误码和错误信息。</p>
</td>
</tr>
</tbody>
</table>

**错误码**：

以下错误码的详细介绍请参见[振动错误码](zh-cn_topic_0000002178215396.md)和[通用错误码](zh-cn_topic_0000002213534485.md)。

<a name="table1954945717172647"></a>
<table><thead align="left"><tr id="row1418871003172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry2019914886172647p0"><a name="entry2019914886172647p0"></a><a name="entry2019914886172647p0"></a>错误码ID</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry66510875172647p0"><a name="entry66510875172647p0"></a><a name="entry66510875172647p0"></a>错误信息</p>
</th>
</tr>
</thead>
<tbody><tr id="row1613063184172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1424467511172647p0"><a name="entry1424467511172647p0"></a><a name="entry1424467511172647p0"></a>201</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry333049400172647p0"><a name="entry333049400172647p0"></a><a name="entry333049400172647p0"></a>Permission denied.</p>
</td>
</tr>
<tr id="row824757900172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry116723653172647p0"><a name="entry116723653172647p0"></a><a name="entry116723653172647p0"></a>401</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p721940154514"><a name="p721940154514"></a><a name="p721940154514"></a>Parameter error.Possible causes:</p>
<p id="p898794284516"><a name="p898794284516"></a><a name="p898794284516"></a>1. Mandatory parameters are left unspecified;</p>
<p id="p185110444453"><a name="p185110444453"></a><a name="p185110444453"></a>2. Incorrect parameter types;</p>
<p id="entry983293279172647p0"><a name="entry983293279172647p0"></a><a name="entry983293279172647p0"></a>3. Parameter verification failed.</p>
</td>
</tr>
<tr id="row1670745466172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry898284004172647p0"><a name="entry898284004172647p0"></a><a name="entry898284004172647p0"></a>801</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry488790138172647p0"><a name="entry488790138172647p0"></a><a name="entry488790138172647p0"></a>Capability not supported.</p>
</td>
</tr>
<tr id="row850800342172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry484375868172647p0"><a name="entry484375868172647p0"></a><a name="entry484375868172647p0"></a>14600101</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1588195834172647p0"><a name="entry1588195834172647p0"></a><a name="entry1588195834172647p0"></a>Device operation failed.</p>
</td>
</tr>
</tbody>
</table>

**示例**：

1.  按照预置振动效果触发马达振动：

    ```
    import { vibrator } from '@kit.SensorServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    try {
      vibrator.startVibration({
        type: 'preset',
        effectId: 'haptic.clock.timer',
        count: 1, // 可选参数，自API9后支持自定义振动次数
      }, {
        id: 0,
        usage: 'alarm'
      }, (error: BusinessError) => {
        if (error) {
          console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
          return;
        }
        console.info('Succeed in starting vibration');
      });
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
    }
    ```

2.  按照自定义振动配置文件触发马达振动：

    ```
    import { vibrator } from '@kit.SensorServiceKit';
    import { resourceManager } from '@kit.LocalizationKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    const fileName: string = 'xxx.json';
    
    let rawFd: resourceManager.RawFileDescriptor = getContext().resourceManager.getRawFdSync(fileName);
    
    try {
      vibrator.startVibration({
        type: "file",
        hapticFd: { fd: rawFd.fd, offset: rawFd.offset, length: rawFd.length }
      }, {
        id: 0,
        usage: 'alarm'
      }, (error: BusinessError) => {
        if (error) {
          console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
          return;
        }
        console.info('Succeed in starting vibration');
      });
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
    }
    
    getContext().resourceManager.closeRawFdSync(fileName);
    ```

3.  按照指定持续时间触发马达振动：

    ```
    import { vibrator } from '@kit.SensorServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    try {
      vibrator.startVibration({
        type: 'time',
        duration: 1000,
      }, {
        id: 0,
        usage: 'alarm'
      }, (error: BusinessError) => {
        if (error) {
          console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
          return;
        }
        console.info('Succeed in starting vibration');
      });
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
    }
    ```

## vibrator.startVibration<sup>9+</sup><a name="vibratorstartvibration9-1"></a>

startVibration\(effect: VibrateEffect, attribute: VibrateAttribute\): Promise<void\>

根据指定的振动效果和振动属性触发马达振动。使用promise异步回调。

**需要权限**：ohos.permission.VIBRATE

**元服务API**：从API Version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

<a name="table1618939413172647"></a>
<table><thead align="left"><tr id="row1372950664172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry2109780301172647p0"><a name="entry2109780301172647p0"></a><a name="entry2109780301172647p0"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry60423358172647p0"><a name="entry60423358172647p0"></a><a name="entry60423358172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry109568471172647p0"><a name="entry109568471172647p0"></a><a name="entry109568471172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry326288917172647p0"><a name="entry326288917172647p0"></a><a name="entry326288917172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row892138009172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry812370119172647p0"><a name="entry812370119172647p0"></a><a name="entry812370119172647p0"></a>effect</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry254213319172647p0"><a name="entry254213319172647p0"></a><a name="entry254213319172647p0"></a><a href="#vibrateeffect9">VibrateEffect</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry339983847172647p0"><a name="entry339983847172647p0"></a><a name="entry339983847172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p1555884309172647"><a name="p1555884309172647"></a><a name="p1555884309172647"></a>马达振动效果，支持三种：</p>
<p id="p612956916172647"><a name="p612956916172647"></a><a name="p612956916172647"></a>1、<a href="#vibratetime9">VibrateTime</a>：按照指定持续时间触发马达振动，无起振/无刹车，不推荐使用此振动类型；</p>
<p id="p778713837172647"><a name="p778713837172647"></a><a name="p778713837172647"></a>2、<a href="#vibratepreset9">VibratePreset</a>：按照预置振动效果触发马达振动，适用于短振场景下调用；3、<a href="#vibratefromfile10">VibrateFromFile</a>：按照自定义振动配置文件触发马达振动，适用于短振场景下调用；</p>
</td>
</tr>
<tr id="row2040778305172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry1235188848172647p0"><a name="entry1235188848172647p0"></a><a name="entry1235188848172647p0"></a>attribute</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry866830888172647p0"><a name="entry866830888172647p0"></a><a name="entry866830888172647p0"></a><a href="#vibrateattribute9">VibrateAttribute</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry412695765172647p0"><a name="entry412695765172647p0"></a><a name="entry412695765172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry1341622293172647p0"><a name="entry1341622293172647p0"></a><a name="entry1341622293172647p0"></a>马达振动属性。</p>
</td>
</tr>
</tbody>
</table>

**返回值**：

<a name="table2028938869172647"></a>
<table><thead align="left"><tr id="row1151001548172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry725763894172647p0"><a name="entry725763894172647p0"></a><a name="entry725763894172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry1077532819172647p0"><a name="entry1077532819172647p0"></a><a name="entry1077532819172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1929148807172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2081409547172647p0"><a name="entry2081409547172647p0"></a><a name="entry2081409547172647p0"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1297017701172647p0"><a name="entry1297017701172647p0"></a><a name="entry1297017701172647p0"></a>无返回结果的Promise对象。</p>
</td>
</tr>
</tbody>
</table>

**错误码**：

以下错误码的详细介绍请参见[振动错误码](zh-cn_topic_0000002178215396.md)和[通用错误码](zh-cn_topic_0000002213534485.md)。

<a name="table574486526172647"></a>
<table><thead align="left"><tr id="row748883584172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry616275806172647p0"><a name="entry616275806172647p0"></a><a name="entry616275806172647p0"></a>错误码ID</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry366013945172647p0"><a name="entry366013945172647p0"></a><a name="entry366013945172647p0"></a>错误信息</p>
</th>
</tr>
</thead>
<tbody><tr id="row934562699172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry622450593172647p0"><a name="entry622450593172647p0"></a><a name="entry622450593172647p0"></a>201</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry339852083172647p0"><a name="entry339852083172647p0"></a><a name="entry339852083172647p0"></a>Permission denied.</p>
</td>
</tr>
<tr id="row1785932154172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1403667493172647p0"><a name="entry1403667493172647p0"></a><a name="entry1403667493172647p0"></a>401</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p7534713184615"><a name="p7534713184615"></a><a name="p7534713184615"></a>Parameter error.Possible causes:</p>
<p id="p25347130467"><a name="p25347130467"></a><a name="p25347130467"></a>1. Mandatory parameters are left unspecified;</p>
<p id="p175341713124617"><a name="p175341713124617"></a><a name="p175341713124617"></a>2. Incorrect parameter types;</p>
<p id="p16534141324613"><a name="p16534141324613"></a><a name="p16534141324613"></a>3. Parameter verification failed.</p>
</td>
</tr>
<tr id="row1537483743172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1311788046172647p0"><a name="entry1311788046172647p0"></a><a name="entry1311788046172647p0"></a>801</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1676910266172647p0"><a name="entry1676910266172647p0"></a><a name="entry1676910266172647p0"></a>Capability not supported.</p>
</td>
</tr>
<tr id="row1437572308172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1653990358172647p0"><a name="entry1653990358172647p0"></a><a name="entry1653990358172647p0"></a>14600101</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry457698030172647p0"><a name="entry457698030172647p0"></a><a name="entry457698030172647p0"></a>Device operation failed.</p>
</td>
</tr>
</tbody>
</table>

**示例**：

1.  按照预置振动效果触发马达振动：

    ```
    import { vibrator } from '@kit.SensorServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    try {
      vibrator.startVibration({
        type: 'preset',
        effectId: 'haptic.clock.timer',
        count: 1, // 可选参数，自API9后支持自定义振动次数
      }, {
        id: 0,
        usage: 'alarm'
      }).then(() => {
        console.info('Succeed in starting vibration');
      }, (error: BusinessError) => {
        console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
      });
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
    }
    ```

2.  按照自定义振动配置文件触发马达振动：

    ```
    import { vibrator } from '@kit.SensorServiceKit';
    import { resourceManager } from '@kit.LocalizationKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    const fileName: string = 'xxx.json';
    
    let rawFd: resourceManager.RawFileDescriptor = getContext().resourceManager.getRawFdSync(fileName);
    
    try {
      vibrator.startVibration({
        type: "file",
        hapticFd: { fd: rawFd.fd, offset: rawFd.offset, length: rawFd.length }
      }, {
        id: 0,
        usage: 'alarm'
      }).then(() => {
        console.info('Succeed in starting vibration');
      }, (error: BusinessError) => {
        console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
      });
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
    }
    
    getContext().resourceManager.closeRawFdSync(fileName);
    ```

3.  按照指定持续时间触发马达振动：

    ```
    import { vibrator } from '@kit.SensorServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    try {
      vibrator.startVibration({
        type: 'time',
        duration: 1000
      }, {
        id: 0,
        usage: 'alarm'
      }).then(() => {
        console.info('Succeed in starting vibration');
      }, (error: BusinessError) => {
        console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
      });
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
    }
    ```

## vibrator.stopVibration<sup>9+</sup><a name="vibratorstopvibration9"></a>

stopVibration\(stopMode: VibratorStopMode, callback: AsyncCallback<void\>\): void

按照指定模式停止马达振动。使用callback异步回调。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

<a name="table1416364967172647"></a>
<table><thead align="left"><tr id="row1554317385172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry86515493172647p0"><a name="entry86515493172647p0"></a><a name="entry86515493172647p0"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry1405681508172647p0"><a name="entry1405681508172647p0"></a><a name="entry1405681508172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry1645213933172647p0"><a name="entry1645213933172647p0"></a><a name="entry1645213933172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry1732063072172647p0"><a name="entry1732063072172647p0"></a><a name="entry1732063072172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row546190211172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry776363741172647p0"><a name="entry776363741172647p0"></a><a name="entry776363741172647p0"></a>stopMode</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry436199827172647p0"><a name="entry436199827172647p0"></a><a name="entry436199827172647p0"></a><a href="#vibratorstopmode">VibratorStopMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry1828402863172647p0"><a name="entry1828402863172647p0"></a><a name="entry1828402863172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p1984240784172647"><a name="p1984240784172647"></a><a name="p1984240784172647"></a>指定的停止振动模式，支持两种：</p>
<a name="ul84968378188"></a><a name="ul84968378188"></a><ul id="ul84968378188"><li>VIBRATOR_STOP_MODE_TIME：停止固定时长振动；</li><li>VIBRATOR_STOP_MODE_PRESET：停止预置振动。</li></ul>
<p id="p1616001171172647"><a name="p1616001171172647"></a><a name="p1616001171172647"></a>此接口无法停止自定义振动，请使用<a href="#vibratorstopvibration10">vibrator.stopVibration<sup id="sup88936797172647"><a name="sup88936797172647"></a><a name="sup88936797172647"></a>10+</sup></a>。</p>
</td>
</tr>
<tr id="row1811172392172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry115245042172647p0"><a name="entry115245042172647p0"></a><a name="entry115245042172647p0"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry382034473172647p0"><a name="entry382034473172647p0"></a><a name="entry382034473172647p0"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry1277528309172647p0"><a name="entry1277528309172647p0"></a><a name="entry1277528309172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry834789895172647p0"><a name="entry834789895172647p0"></a><a name="entry834789895172647p0"></a>回调函数，当马达停止振动成功，err为undefined，否则为错误对象，包含错误码和错误信息。</p>
</td>
</tr>
</tbody>
</table>

**错误码**：

以下错误码的详细介绍请参见[通用错误码](zh-cn_topic_0000002213534485.md)。

<a name="table1990867192172647"></a>
<table><thead align="left"><tr id="row2009398225172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry1549271889172647p0"><a name="entry1549271889172647p0"></a><a name="entry1549271889172647p0"></a>错误码ID</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry805176736172647p0"><a name="entry805176736172647p0"></a><a name="entry805176736172647p0"></a>错误信息</p>
</th>
</tr>
</thead>
<tbody><tr id="row1991822671172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry699667773172647p0"><a name="entry699667773172647p0"></a><a name="entry699667773172647p0"></a>201</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1135724467172647p0"><a name="entry1135724467172647p0"></a><a name="entry1135724467172647p0"></a>Permission denied.</p>
</td>
</tr>
<tr id="row2059884165172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry283986920172647p0"><a name="entry283986920172647p0"></a><a name="entry283986920172647p0"></a>401</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p11774161834620"><a name="p11774161834620"></a><a name="p11774161834620"></a>Parameter error.Possible causes:</p>
<p id="p117742188467"><a name="p117742188467"></a><a name="p117742188467"></a>1. Mandatory parameters are left unspecified;</p>
<p id="p977419181462"><a name="p977419181462"></a><a name="p977419181462"></a>2. Incorrect parameter types;</p>
<p id="p177481874616"><a name="p177481874616"></a><a name="p177481874616"></a>3. Parameter verification failed.</p>
</td>
</tr>
</tbody>
</table>

**示例**：

1.  停止固定时长振动：

    ```
    import { vibrator } from '@kit.SensorServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    try {
      // 按照固定时长振动
      vibrator.startVibration({
        type: 'time',
        duration: 1000,
      }, {
        id: 0,
        usage: 'alarm'
      }, (error: BusinessError) => {
        if (error) {
          console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
          return;
        }
        console.info('Succeed in starting vibration');
      });
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
    }
    
    try {
      // 按照VIBRATOR_STOP_MODE_TIME模式停止振动
      vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_TIME, (error: BusinessError) => {
        if (error) {
          console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
          return;
        }
        console.info('Succeed in stopping vibration');
      })
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
    }
    ```

2.  停止预置振动：

    ```
    import { vibrator } from '@kit.SensorServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    try {
      // 按照预置效果振动
      vibrator.startVibration({
        type: 'preset',
        effectId: 'haptic.clock.timer',
        count: 1, // 可选参数，自API9后支持自定义振动次数
      }, {
        id: 0,
        usage: 'alarm'
      }, (error: BusinessError) => {
        if (error) {
          console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
          return;
        }
        console.info('Succeed in starting vibration');
      });
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
    }
    
    try {
      // 按照VIBRATOR_STOP_MODE_PRESET模式停止振动
      vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET, (error: BusinessError) => {
        if (error) {
          console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
          return;
        }
        console.info('Succeed in stopping vibration');
      })
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
    }
    ```

## vibrator.stopVibration<sup>9+</sup><a name="vibratorstopvibration9-1"></a>

stopVibration\(stopMode: VibratorStopMode\): Promise<void\>

按照指定模式停止马达的振动。使用promise异步回调。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

<a name="table1636215260172647"></a>
<table><thead align="left"><tr id="row1523787908172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry393104873172647p0"><a name="entry393104873172647p0"></a><a name="entry393104873172647p0"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry1706396021172647p0"><a name="entry1706396021172647p0"></a><a name="entry1706396021172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry1132792447172647p0"><a name="entry1132792447172647p0"></a><a name="entry1132792447172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry778933205172647p0"><a name="entry778933205172647p0"></a><a name="entry778933205172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1579267877172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry470836239172647p0"><a name="entry470836239172647p0"></a><a name="entry470836239172647p0"></a>stopMode</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry512479593172647p0"><a name="entry512479593172647p0"></a><a name="entry512479593172647p0"></a><a href="#vibratorstopmode">VibratorStopMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry310040282172647p0"><a name="entry310040282172647p0"></a><a name="entry310040282172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p887012295172647"><a name="p887012295172647"></a><a name="p887012295172647"></a>指定的停止振动模式，支持两种：</p>
<a name="ul153124523182"></a><a name="ul153124523182"></a><ul id="ul153124523182"><li>VIBRATOR_STOP_MODE_TIME：停止固定时长振动；</li><li>VIBRATOR_STOP_MODE_PRESET：停止预置振动。</li></ul>
<p id="p1859562303172647"><a name="p1859562303172647"></a><a name="p1859562303172647"></a>此接口无法停止自定义振动，请使用<a href="#vibratorstopvibration10-1">vibrator.stopVibration<sup id="sup1119026807172647"><a name="sup1119026807172647"></a><a name="sup1119026807172647"></a>10+</sup></a>。</p>
</td>
</tr>
</tbody>
</table>

**返回值**：

<a name="table1527980723172647"></a>
<table><thead align="left"><tr id="row1697873424172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry2042535084172647p0"><a name="entry2042535084172647p0"></a><a name="entry2042535084172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry519055033172647p0"><a name="entry519055033172647p0"></a><a name="entry519055033172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row429604586172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry113313422172647p0"><a name="entry113313422172647p0"></a><a name="entry113313422172647p0"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2014737633172647p0"><a name="entry2014737633172647p0"></a><a name="entry2014737633172647p0"></a>Promise对象。</p>
</td>
</tr>
</tbody>
</table>

**错误码**：

以下错误码的详细介绍请参见[通用错误码](zh-cn_topic_0000002213534485.md)。

<a name="table1550640637172647"></a>
<table><thead align="left"><tr id="row1203314731172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry1724451914172647p0"><a name="entry1724451914172647p0"></a><a name="entry1724451914172647p0"></a>错误码ID</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry526439424172647p0"><a name="entry526439424172647p0"></a><a name="entry526439424172647p0"></a>错误信息</p>
</th>
</tr>
</thead>
<tbody><tr id="row933557231172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry780005839172647p0"><a name="entry780005839172647p0"></a><a name="entry780005839172647p0"></a>201</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry793795663172647p0"><a name="entry793795663172647p0"></a><a name="entry793795663172647p0"></a>Permission denied.</p>
</td>
</tr>
<tr id="row2118747256172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1246289409172647p0"><a name="entry1246289409172647p0"></a><a name="entry1246289409172647p0"></a>401</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1371717233462"><a name="p1371717233462"></a><a name="p1371717233462"></a>Parameter error.Possible causes:</p>
<p id="p13717323134613"><a name="p13717323134613"></a><a name="p13717323134613"></a>1. Mandatory parameters are left unspecified;</p>
<p id="p18717223194617"><a name="p18717223194617"></a><a name="p18717223194617"></a>2. Incorrect parameter types;</p>
<p id="p1871742344615"><a name="p1871742344615"></a><a name="p1871742344615"></a>3. Parameter verification failed.</p>
</td>
</tr>
</tbody>
</table>

**示例**：

1.  停止固定时长振动：

    ```
    import { vibrator } from '@kit.SensorServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    try {
      // 按照固定时长振动
      vibrator.startVibration({
        type: 'time',
        duration: 1000,
      }, {
        id: 0,
        usage: 'alarm'
      }).then(() => {
        console.info('Succeed in starting vibration');
      }, (error: BusinessError) => {
        console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
      });
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
    }
    
    try {
      // 按照VIBRATOR_STOP_MODE_TIME模式停止振动
      vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_TIME).then(() => {
        console.info('Succeed in stopping vibration');
      }, (error: BusinessError) => {
        console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
      });
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
    }
    ```

2.  停止预置振动：

    ```
    import { vibrator } from '@kit.SensorServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    try {
      // 按照预置效果振动
      vibrator.startVibration({
        type: 'preset',
        effectId: 'haptic.clock.timer',
        count: 1, // 可选参数，自API9后支持自定义振动次数
      }, {
        id: 0,
        usage: 'alarm'
      }).then(() => {
        console.info('Succeed in starting vibration');
      }, (error: BusinessError) => {
        console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
      });
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
    }
    
    try {
      // 按照VIBRATOR_STOP_MODE_PRESET模式停止振动
      vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET).then(() => {
        console.info('Succeed in stopping vibration');
      }, (error: BusinessError) => {
        console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
      });
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
    }
    ```

## vibrator.stopVibration<sup>10+</sup><a name="vibratorstopvibration10"></a>

stopVibration\(callback: AsyncCallback<void\>\): void

停止所有模式的马达振动。使用callback异步回调。

**需要权限**：ohos.permission.VIBRATE

**元服务API**：从API Version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

<a name="table1380602005172647"></a>
<table><thead align="left"><tr id="row59951204172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry1476855608172647p0"><a name="entry1476855608172647p0"></a><a name="entry1476855608172647p0"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry768159348172647p0"><a name="entry768159348172647p0"></a><a name="entry768159348172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry1481899183172647p0"><a name="entry1481899183172647p0"></a><a name="entry1481899183172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry813862188172647p0"><a name="entry813862188172647p0"></a><a name="entry813862188172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row374028708172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry847523244172647p0"><a name="entry847523244172647p0"></a><a name="entry847523244172647p0"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry2093613606172647p0"><a name="entry2093613606172647p0"></a><a name="entry2093613606172647p0"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry672578928172647p0"><a name="entry672578928172647p0"></a><a name="entry672578928172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry10337155172647p0"><a name="entry10337155172647p0"></a><a name="entry10337155172647p0"></a>回调函数，当马达停止振动成功，err为undefined，否则为错误对象，包含错误码和错误信息。</p>
</td>
</tr>
</tbody>
</table>

**错误码**：

以下错误码的详细介绍请参见[通用错误码](zh-cn_topic_0000002213534485.md)。

<a name="table415586495172647"></a>
<table><thead align="left"><tr id="row1298265124172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry205375702172647p0"><a name="entry205375702172647p0"></a><a name="entry205375702172647p0"></a>错误码ID</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry733330406172647p0"><a name="entry733330406172647p0"></a><a name="entry733330406172647p0"></a>错误信息</p>
</th>
</tr>
</thead>
<tbody><tr id="row1575945162172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1535375642172647p0"><a name="entry1535375642172647p0"></a><a name="entry1535375642172647p0"></a>201</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1908686938172647p0"><a name="entry1908686938172647p0"></a><a name="entry1908686938172647p0"></a>Permission denied.</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 停止所有模式的马达振动
  vibrator.stopVibration((error: BusinessError) => {
    if (error) {
      console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info('Succeed in stopping vibration');
  })
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.stopVibration<sup>10+</sup><a name="vibratorstopvibration10-1"></a>

stopVibration\(\): Promise<void\>

停止所有模式的马达振动。使用promise异步回调。

**需要权限**：ohos.permission.VIBRATE

**元服务API**：从API Version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Sensors.MiscDevice

**返回值**：

<a name="table1919427600172647"></a>
<table><thead align="left"><tr id="row1988190202172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry2095007911172647p0"><a name="entry2095007911172647p0"></a><a name="entry2095007911172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry279393562172647p0"><a name="entry279393562172647p0"></a><a name="entry279393562172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1441114876172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2093173439172647p0"><a name="entry2093173439172647p0"></a><a name="entry2093173439172647p0"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry122120195172647p0"><a name="entry122120195172647p0"></a><a name="entry122120195172647p0"></a>Promise对象。</p>
</td>
</tr>
</tbody>
</table>

**错误码**：

以下错误码的详细介绍请参见[通用错误码](zh-cn_topic_0000002213534485.md)。

<a name="table1105310870172647"></a>
<table><thead align="left"><tr id="row1846502663172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry2014288093172647p0"><a name="entry2014288093172647p0"></a><a name="entry2014288093172647p0"></a>错误码ID</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry2120255094172647p0"><a name="entry2120255094172647p0"></a><a name="entry2120255094172647p0"></a>错误信息</p>
</th>
</tr>
</thead>
<tbody><tr id="row1648762857172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry409954017172647p0"><a name="entry409954017172647p0"></a><a name="entry409954017172647p0"></a>201</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1911365292172647p0"><a name="entry1911365292172647p0"></a><a name="entry1911365292172647p0"></a>Permission denied.</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 停止所有模式的马达振动
  vibrator.stopVibration().then(() => {
    console.info('Succeed in stopping vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.stopVibrationSync<sup>12+</sup><a name="vibratorstopvibrationsync12"></a>

stopVibrationSync\(\): void

停止任何形式的马达振动。

**需要权限**：ohos.permission.VIBRATE

**元服务API**：从API Version 12开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Sensors.MiscDevice

**错误码**：

以下错误码的详细介绍请参见[振动错误码](zh-cn_topic_0000002178215396.md)和[通用错误码](zh-cn_topic_0000002213534485.md)。

<a name="table142415023172647"></a>
<table><thead align="left"><tr id="row2005588024172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry638708116172647p0"><a name="entry638708116172647p0"></a><a name="entry638708116172647p0"></a>错误码ID</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry56090850172647p0"><a name="entry56090850172647p0"></a><a name="entry56090850172647p0"></a>错误信息</p>
</th>
</tr>
</thead>
<tbody><tr id="row1514469806172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1713918708172647p0"><a name="entry1713918708172647p0"></a><a name="entry1713918708172647p0"></a>201</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1867643859172647p0"><a name="entry1867643859172647p0"></a><a name="entry1867643859172647p0"></a>Permission denied.</p>
</td>
</tr>
<tr id="row910080332172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry654560828172647p0"><a name="entry654560828172647p0"></a><a name="entry654560828172647p0"></a>14600101</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2059709849172647p0"><a name="entry2059709849172647p0"></a><a name="entry2059709849172647p0"></a>Device operation failed.</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 停止任何形式的马达振动
    vibrator.stopVibrationSync()
    console.info('Succeed in stopping vibration');
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.isSupportEffect<sup>10+</sup><a name="vibratorissupporteffect10"></a>

isSupportEffect\(effectId: string, callback: AsyncCallback<boolean\>\): void

查询传入的预的效果effectId是否支持。使用callback异步回调。

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

<a name="table114590339172647"></a>
<table><thead align="left"><tr id="row1939958620172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry585984249172647p0"><a name="entry585984249172647p0"></a><a name="entry585984249172647p0"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry1095928956172647p0"><a name="entry1095928956172647p0"></a><a name="entry1095928956172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry1890777570172647p0"><a name="entry1890777570172647p0"></a><a name="entry1890777570172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry1754136353172647p0"><a name="entry1754136353172647p0"></a><a name="entry1754136353172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1231152124172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry1318222086172647p0"><a name="entry1318222086172647p0"></a><a name="entry1318222086172647p0"></a>effectId</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry2101679996172647p0"><a name="entry2101679996172647p0"></a><a name="entry2101679996172647p0"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry1719296283172647p0"><a name="entry1719296283172647p0"></a><a name="entry1719296283172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry727338812172647p0"><a name="entry727338812172647p0"></a><a name="entry727338812172647p0"></a>预置的振动效果。</p>
</td>
</tr>
<tr id="row1310287768172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry978797859172647p0"><a name="entry978797859172647p0"></a><a name="entry978797859172647p0"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry1296513377172647p0"><a name="entry1296513377172647p0"></a><a name="entry1296513377172647p0"></a>AsyncCallback&lt;boolean&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry1681073224172647p0"><a name="entry1681073224172647p0"></a><a name="entry1681073224172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p1135334531"><a name="p1135334531"></a><a name="p1135334531"></a>回调函数，当返回true则表示支持该effectId，返回false不支持。</p>
</td>
</tr>
</tbody>
</table>

**错误码**：

以下错误码的详细介绍请参见[通用错误码](zh-cn_topic_0000002213534485.md)。

<a name="table1846252132172647"></a>
<table><thead align="left"><tr id="row255167485172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry1200171128172647p0"><a name="entry1200171128172647p0"></a><a name="entry1200171128172647p0"></a>错误码ID</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry616480923172647p0"><a name="entry616480923172647p0"></a><a name="entry616480923172647p0"></a>错误信息</p>
</th>
</tr>
</thead>
<tbody><tr id="row682482264172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2051370446172647p0"><a name="entry2051370446172647p0"></a><a name="entry2051370446172647p0"></a>201</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1430126534172647p0"><a name="entry1430126534172647p0"></a><a name="entry1430126534172647p0"></a>Permission denied.</p>
</td>
</tr>
<tr id="row1115600000172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry952178042172647p0"><a name="entry952178042172647p0"></a><a name="entry952178042172647p0"></a>401</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1267613044615"><a name="p1267613044615"></a><a name="p1267613044615"></a>Parameter error.Possible causes:</p>
<p id="p176761930124620"><a name="p176761930124620"></a><a name="p176761930124620"></a>1. Mandatory parameters are left unspecified;</p>
<p id="p10676113011461"><a name="p10676113011461"></a><a name="p10676113011461"></a>2. Incorrect parameter types;</p>
<p id="p19676173014619"><a name="p19676173014619"></a><a name="p19676173014619"></a>3. Parameter verification failed.</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 查询是否支持'haptic.clock.timer'
  vibrator.isSupportEffect('haptic.clock.timer', (err: BusinessError, state: boolean) => {
    if (err) {
      console.error(`Failed to query effect. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeed in querying effect');
    if (state) {
      try {
        // 使用startVibration需要添加ohos.permission.VIBRATE权限
        vibrator.startVibration({
          type: 'preset',
          effectId: 'haptic.clock.timer',
          count: 1, // 可选参数，自API9后支持自定义振动次数
        }, {
          usage: 'unknown'
        }, (error: BusinessError) => {
          if (error) {
            console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
          } else {
            console.info('Succeed in starting vibration');
          }
        });
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
      }
    }
  })
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.isSupportEffect<sup>10+</sup><a name="vibratorissupporteffect10-1"></a>

isSupportEffect\(effectId: string\): Promise<boolean\>

查询是否支持传入参数effectId。使用promise异步回调。

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

<a name="table1979426423172647"></a>
<table><thead align="left"><tr id="row73070237172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry2132767372172647p0"><a name="entry2132767372172647p0"></a><a name="entry2132767372172647p0"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry1422151914172647p0"><a name="entry1422151914172647p0"></a><a name="entry1422151914172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry58078080172647p0"><a name="entry58078080172647p0"></a><a name="entry58078080172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry1421717947172647p0"><a name="entry1421717947172647p0"></a><a name="entry1421717947172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1239201377172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry1884677768172647p0"><a name="entry1884677768172647p0"></a><a name="entry1884677768172647p0"></a>effectId</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry78277916172647p0"><a name="entry78277916172647p0"></a><a name="entry78277916172647p0"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry2002218613172647p0"><a name="entry2002218613172647p0"></a><a name="entry2002218613172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry565091770172647p0"><a name="entry565091770172647p0"></a><a name="entry565091770172647p0"></a>预置的振动效果。</p>
</td>
</tr>
</tbody>
</table>

**返回值**：

<a name="table2130222160172647"></a>
<table><thead align="left"><tr id="row660341213172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry1501595849172647p0"><a name="entry1501595849172647p0"></a><a name="entry1501595849172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry1667405747172647p0"><a name="entry1667405747172647p0"></a><a name="entry1667405747172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row889108267172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1129734408172647p0"><a name="entry1129734408172647p0"></a><a name="entry1129734408172647p0"></a>Promise&lt;boolean&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1992411955172647p0"><a name="entry1992411955172647p0"></a><a name="entry1992411955172647p0"></a>Promise对象。当返回true则表示支持该effectId，返回false不支持。</p>
</td>
</tr>
</tbody>
</table>

**错误码**：

以下错误码的详细介绍请参见[通用错误码](zh-cn_topic_0000002213534485.md)。

<a name="table930436600172647"></a>
<table><thead align="left"><tr id="row34218914172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry573585897172647p0"><a name="entry573585897172647p0"></a><a name="entry573585897172647p0"></a>错误码ID</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry84566189172647p0"><a name="entry84566189172647p0"></a><a name="entry84566189172647p0"></a>错误信息</p>
</th>
</tr>
</thead>
<tbody><tr id="row1753728107172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1054789342172647p0"><a name="entry1054789342172647p0"></a><a name="entry1054789342172647p0"></a>201</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2045229066172647p0"><a name="entry2045229066172647p0"></a><a name="entry2045229066172647p0"></a>Permission denied.</p>
</td>
</tr>
<tr id="row1735728323172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2097563318172647p0"><a name="entry2097563318172647p0"></a><a name="entry2097563318172647p0"></a>401</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1331233417468"><a name="p1331233417468"></a><a name="p1331233417468"></a>Parameter error.Possible causes:</p>
<p id="p4312173411467"><a name="p4312173411467"></a><a name="p4312173411467"></a>1. Mandatory parameters are left unspecified;</p>
<p id="p131203484615"><a name="p131203484615"></a><a name="p131203484615"></a>2. Incorrect parameter types;</p>
<p id="p14313434154617"><a name="p14313434154617"></a><a name="p14313434154617"></a>3. Parameter verification failed.</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 查询是否支持'haptic.clock.timer'
  vibrator.isSupportEffect('haptic.clock.timer').then((state: boolean) => {
    console.info(`The query result is ${state}`);
    if (state) {
      try {
        vibrator.startVibration({
          type: 'preset',
          effectId: 'haptic.clock.timer',
          count: 1, // 可选参数，自API9后支持自定义振动次数
        }, {
          usage: 'unknown'
        }).then(() => {
          console.info('Succeed in starting vibration');
        }).catch((error: BusinessError) => {
          console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
        });
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
      }
    }
  }, (error: BusinessError) => {
    console.error(`Failed to query effect. Code: ${error.code}, message: ${error.message}`);
  })
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.isSupportEffectSync<sup>12+</sup><a name="vibratorissupporteffectsync12"></a>

isSupportEffectSync\(effectId: string\): boolean

查询是否支持预设的振动效果。

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

<a name="table1604390296172647"></a>
<table><thead align="left"><tr id="row884969989172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry1741267785172647p0"><a name="entry1741267785172647p0"></a><a name="entry1741267785172647p0"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry1183533490172647p0"><a name="entry1183533490172647p0"></a><a name="entry1183533490172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry605416867172647p0"><a name="entry605416867172647p0"></a><a name="entry605416867172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry1445496675172647p0"><a name="entry1445496675172647p0"></a><a name="entry1445496675172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1801434625172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry2044606358172647p0"><a name="entry2044606358172647p0"></a><a name="entry2044606358172647p0"></a>effectId</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry1861103388172647p0"><a name="entry1861103388172647p0"></a><a name="entry1861103388172647p0"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry1895663997172647p0"><a name="entry1895663997172647p0"></a><a name="entry1895663997172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry1118143071172647p0"><a name="entry1118143071172647p0"></a><a name="entry1118143071172647p0"></a>是否预设的振动效果。</p>
</td>
</tr>
</tbody>
</table>

**返回值**：

<a name="table47639533172647"></a>
<table><thead align="left"><tr id="row1531231531172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry2070971514172647p0"><a name="entry2070971514172647p0"></a><a name="entry2070971514172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry772502387172647p0"><a name="entry772502387172647p0"></a><a name="entry772502387172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1759404728172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry490411067172647p0"><a name="entry490411067172647p0"></a><a name="entry490411067172647p0"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry39970460172647p0"><a name="entry39970460172647p0"></a><a name="entry39970460172647p0"></a>返回对象。当返回true则表示支持该effectId，返回false不支持。</p>
</td>
</tr>
</tbody>
</table>

**错误码**：

以下错误码的详细介绍请参见[振动错误码](zh-cn_topic_0000002178215396.md)和[通用错误码](zh-cn_topic_0000002213534485.md)。

<a name="table1855836572172647"></a>
<table><thead align="left"><tr id="row1747952473172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry1096512566172647p0"><a name="entry1096512566172647p0"></a><a name="entry1096512566172647p0"></a>错误码ID</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry1223981222172647p0"><a name="entry1223981222172647p0"></a><a name="entry1223981222172647p0"></a>错误信息</p>
</th>
</tr>
</thead>
<tbody><tr id="row605939295172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1330092850172647p0"><a name="entry1330092850172647p0"></a><a name="entry1330092850172647p0"></a>401</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1552113834611"><a name="p1552113834611"></a><a name="p1552113834611"></a>Parameter error.Possible causes:</p>
<p id="p252133814612"><a name="p252133814612"></a><a name="p252133814612"></a>1. Mandatory parameters are left unspecified;</p>
<p id="p552113884619"><a name="p552113884619"></a><a name="p552113884619"></a>2. Incorrect parameter types;</p>
<p id="p552138144613"><a name="p552138144613"></a><a name="p552138144613"></a>3. Parameter verification failed.</p>
</td>
</tr>
<tr id="row1822394001172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1099435024172647p0"><a name="entry1099435024172647p0"></a><a name="entry1099435024172647p0"></a>14600101</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry727222741172647p0"><a name="entry727222741172647p0"></a><a name="entry727222741172647p0"></a>Device operation failed.</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    // 查询是否支持预设'haptic.clock.timer'
    let ret = vibrator.isSupportEffectSync('haptic.clock.timer');
    console.info(`The query result is ${ret}`);
} catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.isHdHapticSupported<sup>12+</sup><a name="vibratorishdhapticsupported12"></a>

isHdHapticSupported\(\): boolean

查询是否支持高清振动。

**系统能力**：SystemCapability.Sensors.MiscDevice

**返回值**：

<a name="table999266945172647"></a>
<table><thead align="left"><tr id="row123529383172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry1112604740172647p0"><a name="entry1112604740172647p0"></a><a name="entry1112604740172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry1665549493172647p0"><a name="entry1665549493172647p0"></a><a name="entry1665549493172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row662422843172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1984519821172647p0"><a name="entry1984519821172647p0"></a><a name="entry1984519821172647p0"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2009672604172647p0"><a name="entry2009672604172647p0"></a><a name="entry2009672604172647p0"></a>返回对象。</p>
</td>
</tr>
</tbody>
</table>

**错误码**：

以下错误码的详细介绍请参见[振动错误码](zh-cn_topic_0000002178215396.md)。

<a name="table945274599172647"></a>
<table><thead align="left"><tr id="row1691413124172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry696905958172647p0"><a name="entry696905958172647p0"></a><a name="entry696905958172647p0"></a>错误码ID</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry90356363172647p0"><a name="entry90356363172647p0"></a><a name="entry90356363172647p0"></a>错误信息</p>
</th>
</tr>
</thead>
<tbody><tr id="row512653420172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry245903316172647p0"><a name="entry245903316172647p0"></a><a name="entry245903316172647p0"></a>14600101</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry787983341172647p0"><a name="entry787983341172647p0"></a><a name="entry787983341172647p0"></a>Device operation failed.</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    // 查询是否支持高清振动
    let ret = vibrator.isHdHapticSupported();
    console.info(`The query result is ${ret}`);
} catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## EffectId<a name="effectid"></a>

预置的振动效果。在调用[vibrator.startVibration9+](#vibratorstartvibration9)或[vibrator.stopVibration9+](#vibratorstopvibration9-1)接口下发[VibratePreset](#vibratepreset9)形式振动的时候需要使用此参数类型。此参数值种类多样，'haptic.clock.timer'为其中一种。

**系统能力**：SystemCapability.Sensors.MiscDevice

<a name="table1631311656172647"></a>
<table><thead align="left"><tr id="row366754289172647"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="entry1353794488172647p0"><a name="entry1353794488172647p0"></a><a name="entry1353794488172647p0"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="entry141137944172647p0"><a name="entry141137944172647p0"></a><a name="entry141137944172647p0"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="entry645405679172647p0"><a name="entry645405679172647p0"></a><a name="entry645405679172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row174823827172647"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="entry1814715474172647p0"><a name="entry1814715474172647p0"></a><a name="entry1814715474172647p0"></a>EFFECT_CLOCK_TIMER</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="entry1193660035172647p0"><a name="entry1193660035172647p0"></a><a name="entry1193660035172647p0"></a>'haptic.clock.timer'</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="entry799172177172647p0"><a name="entry799172177172647p0"></a><a name="entry799172177172647p0"></a>描述用户调整计时器时的振动效果。</p>
</td>
</tr>
</tbody>
</table>

## HapticFeedback<sup>12+</sup><a name="hapticfeedback12"></a>

简单而通用的振动效果。根据各设备的马达器件不同，同一振动效果的频率会有差异，但效果的频率趋向是统一的。

**系统能力**：SystemCapability.Sensors.MiscDevice

<a name="table587955172172647"></a>
<table><thead align="left"><tr id="row269172322172647"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="entry946618147172647p0"><a name="entry946618147172647p0"></a><a name="entry946618147172647p0"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="entry32535473172647p0"><a name="entry32535473172647p0"></a><a name="entry32535473172647p0"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="entry294461135172647p0"><a name="entry294461135172647p0"></a><a name="entry294461135172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1629314128172647"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="entry413093338172647p0"><a name="entry413093338172647p0"></a><a name="entry413093338172647p0"></a>EFFECT_SOFT</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="entry1721413790172647p0"><a name="entry1721413790172647p0"></a><a name="entry1721413790172647p0"></a>'haptic.effect.soft'</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="entry259911227172647p0"><a name="entry259911227172647p0"></a><a name="entry259911227172647p0"></a>较松散的振动效果，频率较低。</p>
</td>
</tr>
<tr id="row1716778386172647"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="entry2145058334172647p0"><a name="entry2145058334172647p0"></a><a name="entry2145058334172647p0"></a>EFFECT_HARD</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="entry1072136260172647p0"><a name="entry1072136260172647p0"></a><a name="entry1072136260172647p0"></a>'haptic.effect.hard'</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="entry1851994515172647p0"><a name="entry1851994515172647p0"></a><a name="entry1851994515172647p0"></a>较沉重的振动效果，频率适中。</p>
</td>
</tr>
<tr id="row1153766188172647"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="entry167830942172647p0"><a name="entry167830942172647p0"></a><a name="entry167830942172647p0"></a>EFFECT_SHARP</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="entry538431829172647p0"><a name="entry538431829172647p0"></a><a name="entry538431829172647p0"></a>'haptic.effect.sharp'</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="entry1090968087172647p0"><a name="entry1090968087172647p0"></a><a name="entry1090968087172647p0"></a>较尖锐的振动效果，频率较高。</p>
</td>
</tr>
</tbody>
</table>

## VibratorStopMode<a name="vibratorstopmode"></a>

停止振动的模式。在调用[vibrator.stopVibration9+](#vibratorstopvibration9)或[vibrator.stopVibration9+](#vibratorstopvibration9-1)接口时，需要使用此参数类型指定停止的振动模式。停止模式和[VibrateEffect9+](#vibrateeffect9)中下发的模式为对应关系。

**系统能力**：SystemCapability.Sensors.MiscDevice

<a name="table166300893172647"></a>
<table><thead align="left"><tr id="row235727854172647"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="entry211348983172647p0"><a name="entry211348983172647p0"></a><a name="entry211348983172647p0"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="entry632358677172647p0"><a name="entry632358677172647p0"></a><a name="entry632358677172647p0"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="entry129462517172647p0"><a name="entry129462517172647p0"></a><a name="entry129462517172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1806825594172647"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="entry1472007457172647p0"><a name="entry1472007457172647p0"></a><a name="entry1472007457172647p0"></a>VIBRATOR_STOP_MODE_TIME</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="entry1542749386172647p0"><a name="entry1542749386172647p0"></a><a name="entry1542749386172647p0"></a>'time'</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="entry654142172647p0"><a name="entry654142172647p0"></a><a name="entry654142172647p0"></a>停止duration模式的振动。</p>
</td>
</tr>
<tr id="row2060858490172647"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="entry1416997851172647p0"><a name="entry1416997851172647p0"></a><a name="entry1416997851172647p0"></a>VIBRATOR_STOP_MODE_PRESET</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="entry2036486404172647p0"><a name="entry2036486404172647p0"></a><a name="entry2036486404172647p0"></a>'preset'</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="entry1259241797172647p0"><a name="entry1259241797172647p0"></a><a name="entry1259241797172647p0"></a>停止预置EffectId的振动。</p>
</td>
</tr>
</tbody>
</table>

## VibrateEffect<sup>9+</sup><a name="vibrateeffect9"></a>

马达振动效果，支持以下三种。在调用[vibrator.startVibration9+](#vibratorstartvibration9)或[vibrator.startVibration9+](#vibratorstartvibration9-1)接口时，此参数的三种类型表示以三种不同的形式触发振动。

**系统能力**：SystemCapability.Sensors.MiscDevice

<a name="table326539483172647"></a>
<table><thead align="left"><tr id="row1317012706172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry1081944309172647p0"><a name="entry1081944309172647p0"></a><a name="entry1081944309172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry1491503041172647p0"><a name="entry1491503041172647p0"></a><a name="entry1491503041172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1545585810172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry808163423172647p0"><a name="entry808163423172647p0"></a><a name="entry808163423172647p0"></a><a href="#vibratetime9">VibrateTime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1255516474172647"><a name="p1255516474172647"></a><a name="p1255516474172647"></a>按照指定持续时间触发马达振动。</p>
<p id="p1259019192172647"><a name="p1259019192172647"></a><a name="p1259019192172647"></a><strong id="b1817852122172647"><a name="b1817852122172647"></a><a name="b1817852122172647"></a>元服务API：</strong> 从API Version 11开始，该接口支持在元服务中使用。</p>
</td>
</tr>
<tr id="row521747018172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry582507931172647p0"><a name="entry582507931172647p0"></a><a name="entry582507931172647p0"></a><a href="#vibratepreset9">VibratePreset</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry478497562172647p0"><a name="entry478497562172647p0"></a><a name="entry478497562172647p0"></a>按照预置振动类型触发马达振动。</p>
</td>
</tr>
<tr id="row1043007044172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry866466259172647p0"><a name="entry866466259172647p0"></a><a name="entry866466259172647p0"></a><a href="#vibratefromfile10">VibrateFromFile</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry322706680172647p0"><a name="entry322706680172647p0"></a><a name="entry322706680172647p0"></a>按照自定义振动配置文件触发马达振动。</p>
</td>
</tr>
</tbody>
</table>

## VibrateTime<sup>9+</sup><a name="vibratetime9"></a>

固定时长振动类型。当调用[vibrator.startVibration9+](#vibratorstartvibration9)或[vibrator.startVibration9+](#vibratorstartvibration9-1)时，[VibrateEffect9+](#vibrateeffect9)参数的类型为VibrateTime时，表示触发固定时长振动类型。

**元服务API**：从API Version 11开始，该接口在支持元服务中使用。

**系统能力**：SystemCapability.Sensors.MiscDevice

<a name="table2125199157172647"></a>
<table><thead align="left"><tr id="row1854435968172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry892194647172647p0"><a name="entry892194647172647p0"></a><a name="entry892194647172647p0"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry2107068099172647p0"><a name="entry2107068099172647p0"></a><a name="entry2107068099172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry187307431172647p0"><a name="entry187307431172647p0"></a><a name="entry187307431172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry589197240172647p0"><a name="entry589197240172647p0"></a><a name="entry589197240172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1002843696172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry1802892639172647p0"><a name="entry1802892639172647p0"></a><a name="entry1802892639172647p0"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry1426153500172647p0"><a name="entry1426153500172647p0"></a><a name="entry1426153500172647p0"></a>'time'</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry455588503172647p0"><a name="entry455588503172647p0"></a><a name="entry455588503172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry748534407172647p0"><a name="entry748534407172647p0"></a><a name="entry748534407172647p0"></a>值为'time'，按照指定持续时间触发马达振动。</p>
</td>
</tr>
<tr id="row911280848172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry1440406004172647p0"><a name="entry1440406004172647p0"></a><a name="entry1440406004172647p0"></a>duration</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry598443332172647p0"><a name="entry598443332172647p0"></a><a name="entry598443332172647p0"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry503608132172647p0"><a name="entry503608132172647p0"></a><a name="entry503608132172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry1710100261172647p0"><a name="entry1710100261172647p0"></a><a name="entry1710100261172647p0"></a>马达持续振动时长, 单位ms。</p>
</td>
</tr>
</tbody>
</table>

## VibratePreset<sup>9+</sup><a name="vibratepreset9"></a>

预置振动类型。当调用[vibrator.startVibration9+](#vibratorstartvibration9)或[vibrator.startVibration9+](#vibratorstartvibration9-1)时，[VibrateEffect9+](#vibrateeffect9)参数的值可以为VibratePreset，表示触发预置振动类型。

**系统能力**：SystemCapability.Sensors.MiscDevice

<a name="table1792467251172647"></a>
<table><thead align="left"><tr id="row578757545172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry1717399857172647p0"><a name="entry1717399857172647p0"></a><a name="entry1717399857172647p0"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry215702732172647p0"><a name="entry215702732172647p0"></a><a name="entry215702732172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry1522230193172647p0"><a name="entry1522230193172647p0"></a><a name="entry1522230193172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry1232424882172647p0"><a name="entry1232424882172647p0"></a><a name="entry1232424882172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1624184815172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry61136027172647p0"><a name="entry61136027172647p0"></a><a name="entry61136027172647p0"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry945743446172647p0"><a name="entry945743446172647p0"></a><a name="entry945743446172647p0"></a>'preset'</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry89370196172647p0"><a name="entry89370196172647p0"></a><a name="entry89370196172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry651736310172647p0"><a name="entry651736310172647p0"></a><a name="entry651736310172647p0"></a>值为'preset'，按照预置振动效果触发马达振动。</p>
</td>
</tr>
<tr id="row699813789172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry484897977172647p0"><a name="entry484897977172647p0"></a><a name="entry484897977172647p0"></a>effectId</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry889777416172647p0"><a name="entry889777416172647p0"></a><a name="entry889777416172647p0"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry87157981172647p0"><a name="entry87157981172647p0"></a><a name="entry87157981172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry1544854781172647p0"><a name="entry1544854781172647p0"></a><a name="entry1544854781172647p0"></a>预置的振动效果ID。</p>
</td>
</tr>
<tr id="row877048040172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry687374444172647p0"><a name="entry687374444172647p0"></a><a name="entry687374444172647p0"></a>count</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry825118818172647p0"><a name="entry825118818172647p0"></a><a name="entry825118818172647p0"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry1559853774172647p0"><a name="entry1559853774172647p0"></a><a name="entry1559853774172647p0"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry1471916241172647p0"><a name="entry1471916241172647p0"></a><a name="entry1471916241172647p0"></a>可选参数，振动的重复次数，默认值为1。</p>
</td>
</tr>
<tr id="row51695271172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry1036300067172647p0"><a name="entry1036300067172647p0"></a><a name="entry1036300067172647p0"></a>intensity<sup id="sup1143167395172647"><a name="sup1143167395172647"></a><a name="sup1143167395172647"></a>12+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry2034417870172647p0"><a name="entry2034417870172647p0"></a><a name="entry2034417870172647p0"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry197543925172647p0"><a name="entry197543925172647p0"></a><a name="entry197543925172647p0"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry996579946172647p0"><a name="entry996579946172647p0"></a><a name="entry996579946172647p0"></a>可选参数，振动调节强度，范围为0到100，默认值为100。若振动效果不支持强度调节或设备不支持时，则按默认强度振动。</p>
</td>
</tr>
</tbody>
</table>

## VibrateFromFile<sup>10+</sup><a name="vibratefromfile10"></a>

自定义振动类型。仅部分设备支持。当设备不支持此振动类型时，返回[设备不支持错误码](zh-cn_topic_0000002213534485.md)。当调用[vibrator.startVibration9+](#vibratorstartvibration9)或[vibrator.startVibration9+](#vibratorstartvibration9-1)时，[VibrateEffect9+](#vibrateeffect9)参数的值可以为VibrateFromFile，表示触发自定义振动类型。

**系统能力**：SystemCapability.Sensors.MiscDevice

<a name="table1466945672172647"></a>
<table><thead align="left"><tr id="row1769974343172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry845253626172647p0"><a name="entry845253626172647p0"></a><a name="entry845253626172647p0"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry923831402172647p0"><a name="entry923831402172647p0"></a><a name="entry923831402172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry497632393172647p0"><a name="entry497632393172647p0"></a><a name="entry497632393172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry809536772172647p0"><a name="entry809536772172647p0"></a><a name="entry809536772172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row258435730172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry1006366423172647p0"><a name="entry1006366423172647p0"></a><a name="entry1006366423172647p0"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry947186319172647p0"><a name="entry947186319172647p0"></a><a name="entry947186319172647p0"></a>'file'</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry1754988262172647p0"><a name="entry1754988262172647p0"></a><a name="entry1754988262172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry243179536172647p0"><a name="entry243179536172647p0"></a><a name="entry243179536172647p0"></a>值为'file'，按照振动配置文件触发马达振动。</p>
</td>
</tr>
<tr id="row611133701172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry1026868485172647p0"><a name="entry1026868485172647p0"></a><a name="entry1026868485172647p0"></a>hapticFd</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry555956310172647p0"><a name="entry555956310172647p0"></a><a name="entry555956310172647p0"></a><a href="#hapticfiledescriptor10">HapticFileDescriptor</a><sup id="sup1037282169172647"><a name="sup1037282169172647"></a><a name="sup1037282169172647"></a>10+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry834037090172647p0"><a name="entry834037090172647p0"></a><a name="entry834037090172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry31603884172647p0"><a name="entry31603884172647p0"></a><a name="entry31603884172647p0"></a>振动配置文件的描述符。</p>
</td>
</tr>
</tbody>
</table>

## HapticFileDescriptor<sup>10+</sup><a name="hapticfiledescriptor10"></a>

自定义振动配置文件的描述符。必须确认资源文件可用，其参数可通过[文件管理API](zh-cn_topic_0000002178055048.md#fsopen)从沙箱路径获取或者通过[资源管理API](zh-cn_topic_0000002213535525.md#getrawfd9)从HAP资源获取。使用场景：振动序列被存储在一个文件中，需要根据偏移量和长度进行振动。振动序列存储格式，请参考[自定义振动格式](zh-cn_topic_0000002178053620.md#自定义振动)。

**系统能力**：SystemCapability.Sensors.MiscDevice

<a name="table1943714904172647"></a>
<table><thead align="left"><tr id="row813933487172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry187534540172647p0"><a name="entry187534540172647p0"></a><a name="entry187534540172647p0"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry378301007172647p0"><a name="entry378301007172647p0"></a><a name="entry378301007172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry1553173933172647p0"><a name="entry1553173933172647p0"></a><a name="entry1553173933172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry1660848862172647p0"><a name="entry1660848862172647p0"></a><a name="entry1660848862172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1561969196172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry1260854059172647p0"><a name="entry1260854059172647p0"></a><a name="entry1260854059172647p0"></a>fd</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry2069094647172647p0"><a name="entry2069094647172647p0"></a><a name="entry2069094647172647p0"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry465954146172647p0"><a name="entry465954146172647p0"></a><a name="entry465954146172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry1081507666172647p0"><a name="entry1081507666172647p0"></a><a name="entry1081507666172647p0"></a>资源文件描述符。</p>
</td>
</tr>
<tr id="row1592151106172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry1233970612172647p0"><a name="entry1233970612172647p0"></a><a name="entry1233970612172647p0"></a>offset</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry848505390172647p0"><a name="entry848505390172647p0"></a><a name="entry848505390172647p0"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry1886653260172647p0"><a name="entry1886653260172647p0"></a><a name="entry1886653260172647p0"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry2100384410172647p0"><a name="entry2100384410172647p0"></a><a name="entry2100384410172647p0"></a>距文件起始位置的偏移量，单位为字节，默认为文件起始位置，不可超出文件有效范围。</p>
</td>
</tr>
<tr id="row748038912172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry1021288399172647p0"><a name="entry1021288399172647p0"></a><a name="entry1021288399172647p0"></a>length</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry1960272566172647p0"><a name="entry1960272566172647p0"></a><a name="entry1960272566172647p0"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry702894623172647p0"><a name="entry702894623172647p0"></a><a name="entry702894623172647p0"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry1085898274172647p0"><a name="entry1085898274172647p0"></a><a name="entry1085898274172647p0"></a>资源长度，单位为字节，默认值为从偏移位置至文件结尾的长度，不可超出文件有效范围。</p>
</td>
</tr>
</tbody>
</table>

## VibrateAttribute<sup>9+</sup><a name="vibrateattribute9"></a>

马达振动属性。

**元服务API**：从API Version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Sensors.MiscDevice

<a name="table245357304172647"></a>
<table><thead align="left"><tr id="row1030392007172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry2134489506172647p0"><a name="entry2134489506172647p0"></a><a name="entry2134489506172647p0"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry854518065172647p0"><a name="entry854518065172647p0"></a><a name="entry854518065172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry1768764789172647p0"><a name="entry1768764789172647p0"></a><a name="entry1768764789172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry1734746786172647p0"><a name="entry1734746786172647p0"></a><a name="entry1734746786172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1645714508172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry884130206172647p0"><a name="entry884130206172647p0"></a><a name="entry884130206172647p0"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry117367054172647p0"><a name="entry117367054172647p0"></a><a name="entry117367054172647p0"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry2051632324172647p0"><a name="entry2051632324172647p0"></a><a name="entry2051632324172647p0"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry46202425172647p0"><a name="entry46202425172647p0"></a><a name="entry46202425172647p0"></a>振动器id， 默认值为0。</p>
</td>
</tr>
<tr id="row1153398220172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry193590258172647p0"><a name="entry193590258172647p0"></a><a name="entry193590258172647p0"></a>usage</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry1931909811172647p0"><a name="entry1931909811172647p0"></a><a name="entry1931909811172647p0"></a><a href="#usage9">Usage</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry1772808460172647p0"><a name="entry1772808460172647p0"></a><a name="entry1772808460172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry647952549172647p0"><a name="entry647952549172647p0"></a><a name="entry647952549172647p0"></a>马达振动的使用场景。</p>
</td>
</tr>
</tbody>
</table>

## Usage<sup>9+</sup><a name="usage9"></a>

type Usage = 'unknown' | 'alarm' | 'ring' | 'notification' | 'communication' | 'touch' | 'media' | 'physicalFeedback' | 'simulateReality'

振动使用场景。

**元服务API**：从API Version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Sensors.MiscDevice

<a name="table607843026172647"></a>
<table><thead align="left"><tr id="row455048253172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry1563602584172647p0"><a name="entry1563602584172647p0"></a><a name="entry1563602584172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry1348548742172647p0"><a name="entry1348548742172647p0"></a><a name="entry1348548742172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1436925072172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry207166378172647p0"><a name="entry207166378172647p0"></a><a name="entry207166378172647p0"></a>'unknown'</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry899227131172647p0"><a name="entry899227131172647p0"></a><a name="entry899227131172647p0"></a>没有明确使用场景，最低优先级，值固定为'unknown'字符串。受触感开关管控，关闭时不振动。</p>
</td>
</tr>
<tr id="row165716145172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry541510203172647p0"><a name="entry541510203172647p0"></a><a name="entry541510203172647p0"></a>'alarm'</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry320124694172647p0"><a name="entry320124694172647p0"></a><a name="entry320124694172647p0"></a>用于警报场景，值固定为'alarm'字符串。受三态开关管控，静音时不振动。</p>
</td>
</tr>
<tr id="row167538219172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1064292124172647p0"><a name="entry1064292124172647p0"></a><a name="entry1064292124172647p0"></a>'ring'</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2109462579172647p0"><a name="entry2109462579172647p0"></a><a name="entry2109462579172647p0"></a>用于铃声场景，值固定为'ring'字符串。受三态开关管控，静音时不振动。</p>
</td>
</tr>
<tr id="row1451902545172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1958888707172647p0"><a name="entry1958888707172647p0"></a><a name="entry1958888707172647p0"></a>'notification'</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry592967478172647p0"><a name="entry592967478172647p0"></a><a name="entry592967478172647p0"></a>用于通知场景，值固定为'notification'字符串。受三态开关管控，静音时不振动。</p>
</td>
</tr>
<tr id="row1097283168172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1308560277172647p0"><a name="entry1308560277172647p0"></a><a name="entry1308560277172647p0"></a>'communication'</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry716400948172647p0"><a name="entry716400948172647p0"></a><a name="entry716400948172647p0"></a>用于通信场景，值固定为'communication'字符串。受三态开关管控，静音时不振动。</p>
</td>
</tr>
<tr id="row1541581960172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1781105673172647p0"><a name="entry1781105673172647p0"></a><a name="entry1781105673172647p0"></a>'touch'</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1869215382172647p0"><a name="entry1869215382172647p0"></a><a name="entry1869215382172647p0"></a>用于触摸场景，值固定为'touch'字符串。 受触感开关管控，关闭时不振动。</p>
</td>
</tr>
<tr id="row126763262172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry220662448172647p0"><a name="entry220662448172647p0"></a><a name="entry220662448172647p0"></a>'media'</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry6214921172647p0"><a name="entry6214921172647p0"></a><a name="entry6214921172647p0"></a>用于多媒体场景，值固定为'media'字符串。受触感开关管控，关闭时不振动。</p>
</td>
</tr>
<tr id="row1088752338172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry960560810172647p0"><a name="entry960560810172647p0"></a><a name="entry960560810172647p0"></a>'physicalFeedback'</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry769804094172647p0"><a name="entry769804094172647p0"></a><a name="entry769804094172647p0"></a>用于物理反馈场景，值固定为'physicalFeedback'字符串。受触感开关管控，关闭时不振动。</p>
</td>
</tr>
<tr id="row2066905193172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry807998763172647p0"><a name="entry807998763172647p0"></a><a name="entry807998763172647p0"></a>'simulateReality'</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry27566767172647p0"><a name="entry27566767172647p0"></a><a name="entry27566767172647p0"></a>用于模拟现实场景，值固定为'simulateReality'字符串。受触感开关管控，关闭时不振动。</p>
</td>
</tr>
</tbody>
</table>

## vibrator.vibrate<sup>\(deprecated\)</sup><a name="vibratorvibratedeprecated"></a>

vibrate\(duration: number\): Promise<void\>

按照指定持续时间触发马达振动。

从API version 9 开始不再维护，建议使用  [vibrator.startVibration](#vibratorstartvibration9-1)<sup>9+</sup>代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

<a name="table1429159517172647"></a>
<table><thead align="left"><tr id="row411930760172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry1715426415172647p0"><a name="entry1715426415172647p0"></a><a name="entry1715426415172647p0"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry1553522465172647p0"><a name="entry1553522465172647p0"></a><a name="entry1553522465172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry879077541172647p0"><a name="entry879077541172647p0"></a><a name="entry879077541172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry1169551674172647p0"><a name="entry1169551674172647p0"></a><a name="entry1169551674172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1896109688172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry458376515172647p0"><a name="entry458376515172647p0"></a><a name="entry458376515172647p0"></a>duration</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry1341888375172647p0"><a name="entry1341888375172647p0"></a><a name="entry1341888375172647p0"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry367958523172647p0"><a name="entry367958523172647p0"></a><a name="entry367958523172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry40828675172647p0"><a name="entry40828675172647p0"></a><a name="entry40828675172647p0"></a>马达振动时长, 单位ms。</p>
</td>
</tr>
</tbody>
</table>

**返回值**：

<a name="table1759457101172647"></a>
<table><thead align="left"><tr id="row1096919755172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry1471709222172647p0"><a name="entry1471709222172647p0"></a><a name="entry1471709222172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry1642862360172647p0"><a name="entry1642862360172647p0"></a><a name="entry1642862360172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row2005230473172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1985015478172647p0"><a name="entry1985015478172647p0"></a><a name="entry1985015478172647p0"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1550019868172647p0"><a name="entry1550019868172647p0"></a><a name="entry1550019868172647p0"></a>Promise对象。</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

vibrator.vibrate(1000).then(() => {
  console.info('Succeed in vibrating');
}, (error: BusinessError) => {
  console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
});
```

## vibrator.vibrate<sup>\(deprecated\)</sup><a name="vibratorvibratedeprecated-1"></a>

vibrate\(duration: number, callback?: AsyncCallback<void\>\): void

按照指定持续时间触发马达振动。

从API version 9 开始不再维护，建议使用  [vibrator.startVibration](#vibratorstartvibration9)<sup>9+</sup>代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

<a name="table144912881172647"></a>
<table><thead align="left"><tr id="row1788730592172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry1478184647172647p0"><a name="entry1478184647172647p0"></a><a name="entry1478184647172647p0"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry1618852867172647p0"><a name="entry1618852867172647p0"></a><a name="entry1618852867172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry1726746897172647p0"><a name="entry1726746897172647p0"></a><a name="entry1726746897172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry1893206617172647p0"><a name="entry1893206617172647p0"></a><a name="entry1893206617172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row920806259172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry106442036172647p0"><a name="entry106442036172647p0"></a><a name="entry106442036172647p0"></a>duration</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry390829095172647p0"><a name="entry390829095172647p0"></a><a name="entry390829095172647p0"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry1969303213172647p0"><a name="entry1969303213172647p0"></a><a name="entry1969303213172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry550375304172647p0"><a name="entry550375304172647p0"></a><a name="entry550375304172647p0"></a>马达振动时长, 单位ms。</p>
</td>
</tr>
<tr id="row1386077526172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry1136701279172647p0"><a name="entry1136701279172647p0"></a><a name="entry1136701279172647p0"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry294059253172647p0"><a name="entry294059253172647p0"></a><a name="entry294059253172647p0"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry246079760172647p0"><a name="entry246079760172647p0"></a><a name="entry246079760172647p0"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry711744872172647p0"><a name="entry711744872172647p0"></a><a name="entry711744872172647p0"></a>回调函数，当马达振动成功，err为undefined，否则为错误对象，包含错误码和错误信息。</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

vibrator.vibrate(1000, (error: BusinessError) => {
  if (error) {
    console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
  } else {
    console.info('Succeed in vibrating');
  }
})
```

## vibrator.vibrate<sup>\(deprecated\)</sup><a name="vibratorvibratedeprecated-2"></a>

vibrate\(effectId: EffectId\): Promise<void\>

按照预置振动效果触发马达振动。

从API version 9 开始不再维护，建议使用  [vibrator.startVibration](#vibratorstartvibration9-1)<sup>9+</sup>代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

<a name="table1483752183172647"></a>
<table><thead align="left"><tr id="row2045834008172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry406358024172647p0"><a name="entry406358024172647p0"></a><a name="entry406358024172647p0"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry2024053594172647p0"><a name="entry2024053594172647p0"></a><a name="entry2024053594172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry1519812467172647p0"><a name="entry1519812467172647p0"></a><a name="entry1519812467172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry30537484172647p0"><a name="entry30537484172647p0"></a><a name="entry30537484172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row997274082172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry899074071172647p0"><a name="entry899074071172647p0"></a><a name="entry899074071172647p0"></a>effectId</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry2023367520172647p0"><a name="entry2023367520172647p0"></a><a name="entry2023367520172647p0"></a><a href="#effectid">EffectId</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry745923831172647p0"><a name="entry745923831172647p0"></a><a name="entry745923831172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry2028727122172647p0"><a name="entry2028727122172647p0"></a><a name="entry2028727122172647p0"></a>预置的振动效果ID。</p>
</td>
</tr>
</tbody>
</table>

**返回值**：

<a name="table1807168222172647"></a>
<table><thead align="left"><tr id="row1680512883172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry711980333172647p0"><a name="entry711980333172647p0"></a><a name="entry711980333172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry1730936289172647p0"><a name="entry1730936289172647p0"></a><a name="entry1730936289172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1608707788172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1738458148172647p0"><a name="entry1738458148172647p0"></a><a name="entry1738458148172647p0"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1247453082172647p0"><a name="entry1247453082172647p0"></a><a name="entry1247453082172647p0"></a>Promise对象。</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER).then(() => {
  console.info('Succeed in vibrating');
}, (error: BusinessError) => {
  console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
});
```

## vibrator.vibrate<sup>\(deprecated\)</sup><a name="vibratorvibratedeprecated-3"></a>

vibrate\(effectId: EffectId, callback?: AsyncCallback<void\>\): void

按照指定振动效果触发马达振动。

从API version 9 开始不再维护，建议使用  [vibrator.startVibration](#vibratorstartvibration9)<sup>9+</sup>代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

<a name="table304825626172647"></a>
<table><thead align="left"><tr id="row520923890172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry2142348558172647p0"><a name="entry2142348558172647p0"></a><a name="entry2142348558172647p0"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry1554521893172647p0"><a name="entry1554521893172647p0"></a><a name="entry1554521893172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry1424113010172647p0"><a name="entry1424113010172647p0"></a><a name="entry1424113010172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry2002586613172647p0"><a name="entry2002586613172647p0"></a><a name="entry2002586613172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row925004408172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry683660746172647p0"><a name="entry683660746172647p0"></a><a name="entry683660746172647p0"></a>effectId</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry746223886172647p0"><a name="entry746223886172647p0"></a><a name="entry746223886172647p0"></a><a href="#effectid">EffectId</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry87478343172647p0"><a name="entry87478343172647p0"></a><a name="entry87478343172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry1872074751172647p0"><a name="entry1872074751172647p0"></a><a name="entry1872074751172647p0"></a>预置的振动效果ID。</p>
</td>
</tr>
<tr id="row139822703172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry693139656172647p0"><a name="entry693139656172647p0"></a><a name="entry693139656172647p0"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry1202427794172647p0"><a name="entry1202427794172647p0"></a><a name="entry1202427794172647p0"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry1518181422172647p0"><a name="entry1518181422172647p0"></a><a name="entry1518181422172647p0"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry856874262172647p0"><a name="entry856874262172647p0"></a><a name="entry856874262172647p0"></a>回调函数，当马达振动成功，err为undefined，否则为错误对象，包含错误码和错误信息。</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, (error: BusinessError) => {
  if (error) {
    console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
  } else {
    console.info('Succeed in vibrating');
  }
})
```

## vibrator.stop<sup>\(deprecated\)</sup><a name="vibratorstopdeprecated"></a>

stop\(stopMode: VibratorStopMode\): Promise<void\>

按照指定模式停止马达的振动。

从API version 9 开始不再维护，建议使用  [vibrator.stopVibration](#vibratorstopvibration9-1)<sup>9+</sup>代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

<a name="table370507299172647"></a>
<table><thead align="left"><tr id="row968618642172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry838079185172647p0"><a name="entry838079185172647p0"></a><a name="entry838079185172647p0"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry350843631172647p0"><a name="entry350843631172647p0"></a><a name="entry350843631172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry1674828685172647p0"><a name="entry1674828685172647p0"></a><a name="entry1674828685172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry1499346326172647p0"><a name="entry1499346326172647p0"></a><a name="entry1499346326172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row723333023172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry63393263172647p0"><a name="entry63393263172647p0"></a><a name="entry63393263172647p0"></a>stopMode</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry1805015347172647p0"><a name="entry1805015347172647p0"></a><a name="entry1805015347172647p0"></a><a href="#vibratorstopmode">VibratorStopMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry1744279520172647p0"><a name="entry1744279520172647p0"></a><a name="entry1744279520172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry953326977172647p0"><a name="entry953326977172647p0"></a><a name="entry953326977172647p0"></a>停止指定的马达振动模式</p>
</td>
</tr>
</tbody>
</table>

**返回值**：

<a name="table266200400172647"></a>
<table><thead align="left"><tr id="row431483516172647"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry1847057875172647p0"><a name="entry1847057875172647p0"></a><a name="entry1847057875172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry844658672172647p0"><a name="entry844658672172647p0"></a><a name="entry844658672172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row109362192172647"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1997716679172647p0"><a name="entry1997716679172647p0"></a><a name="entry1997716679172647p0"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry691742177172647p0"><a name="entry691742177172647p0"></a><a name="entry691742177172647p0"></a>Promise对象。</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 按照effectId类型启动振动
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, (error: BusinessError) => {
  if (error) {
    console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
  } else {
    console.info('Succeed in vibrating');
  }
})
// 使用VIBRATOR_STOP_MODE_PRESET模式停止振动
vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET).then(() => {
  console.info('Succeed in stopping');
}, (error: BusinessError) => {
  console.error(`Failed to stop. Code: ${error.code}, message: ${error.message}`);
});
```

## vibrator.stop<sup>\(deprecated\)</sup><a name="vibratorstopdeprecated-1"></a>

stop\(stopMode: VibratorStopMode, callback?: AsyncCallback<void\>\): void

按照指定模式停止马达的振动。

从API version 9 开始不再维护，建议使用  [vibrator.stopVibration](#vibratorstopvibration9)<sup>9+</sup>代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

<a name="table1752568182172647"></a>
<table><thead align="left"><tr id="row408647305172647"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="entry202932027172647p0"><a name="entry202932027172647p0"></a><a name="entry202932027172647p0"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="entry687195164172647p0"><a name="entry687195164172647p0"></a><a name="entry687195164172647p0"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="entry611797842172647p0"><a name="entry611797842172647p0"></a><a name="entry611797842172647p0"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="entry1033636738172647p0"><a name="entry1033636738172647p0"></a><a name="entry1033636738172647p0"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1152764245172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry422054490172647p0"><a name="entry422054490172647p0"></a><a name="entry422054490172647p0"></a>stopMode</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry414207606172647p0"><a name="entry414207606172647p0"></a><a name="entry414207606172647p0"></a><a href="#vibratorstopmode">VibratorStopMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry1784021568172647p0"><a name="entry1784021568172647p0"></a><a name="entry1784021568172647p0"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry753721508172647p0"><a name="entry753721508172647p0"></a><a name="entry753721508172647p0"></a>停止指定的马达振动模式。</p>
</td>
</tr>
<tr id="row1845502613172647"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="entry1729238757172647p0"><a name="entry1729238757172647p0"></a><a name="entry1729238757172647p0"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="entry1803249779172647p0"><a name="entry1803249779172647p0"></a><a name="entry1803249779172647p0"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="entry1829178120172647p0"><a name="entry1829178120172647p0"></a><a name="entry1829178120172647p0"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="entry1953066546172647p0"><a name="entry1953066546172647p0"></a><a name="entry1953066546172647p0"></a>回调函数，当马达停止振动成功，err为undefined，否则为错误对象，包含错误码和错误信息。</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 按照effectId类型启动振动
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, (error: BusinessError) => {
  if (error) {
    console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
  } else {
    console.info('Succeed in vibrating');
  }
})
// 使用VIBRATOR_STOP_MODE_PRESET模式停止振动
vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET, (error: BusinessError) => {
  if (error) {
    console.error(`Failed to stop. Code: ${error.code}, message: ${error.message}`);
  } else {
    console.info('Succeed in stopping');
  }
})
```

