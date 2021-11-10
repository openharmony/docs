# 传感器<a name="ZH-CN_TOPIC_0000001145015663"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version  7 开始支持。

## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import sensor from '@ohos.sensor';
```

## 权限列表<a name="section11257113618419"></a>

计步器：ohos.permission.ACTIVITY\_MOTION

心率：ohos.permission.READ\_HEALTH\_DATA

加速度：ohos.permission.ACCELEROMETER

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_ACCELEROMETER\)<a name="section18465193010412"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_ACCELEROMETER, callback: AsyncCallback<AccelerometerResponse\>,options?: Options\): void

监听加速度传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table1510122101017"></a>
<table><thead align="left"><tr id="row141172213109"><th class="cellrowborder" valign="top" width="9.94%" id="mcps1.1.5.1.1"><p id="p21102271013"><a name="p21102271013"></a><a name="p21102271013"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="34.98%" id="mcps1.1.5.1.2"><p id="p17111422161017"><a name="p17111422161017"></a><a name="p17111422161017"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.819999999999999%" id="mcps1.1.5.1.3"><p id="p7113228107"><a name="p7113228107"></a><a name="p7113228107"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="48.26%" id="mcps1.1.5.1.4"><p id="p1511112231012"><a name="p1511112231012"></a><a name="p1511112231012"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row81102271018"><td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.5.1.1 "><p id="p3459114382218"><a name="p3459114382218"></a><a name="p3459114382218"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="34.98%" headers="mcps1.1.5.1.2 "><p id="p1845964392217"><a name="p1845964392217"></a><a name="p1845964392217"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.819999999999999%" headers="mcps1.1.5.1.3 "><p id="p5459124312223"><a name="p5459124312223"></a><a name="p5459124312223"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.26%" headers="mcps1.1.5.1.4 "><p id="p1629093118124"><a name="p1629093118124"></a><a name="p1629093118124"></a>要订阅的加速度传感器类型为SENSOR_TYPE_ID_ACCELEROMETER。</p>
</td>
</tr>
<tr id="row712152214107"><td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.5.1.1 "><p id="p4460154362216"><a name="p4460154362216"></a><a name="p4460154362216"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="34.98%" headers="mcps1.1.5.1.2 "><p id="p10460154314227"><a name="p10460154314227"></a><a name="p10460154314227"></a>AsyncCallback&lt;<a href="#section965820576618">AccelerometerResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.819999999999999%" headers="mcps1.1.5.1.3 "><p id="p12460043162214"><a name="p12460043162214"></a><a name="p12460043162214"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.26%" headers="mcps1.1.5.1.4 "><p id="p15460843102212"><a name="p15460843102212"></a><a name="p15460843102212"></a>注册加速度传感器的回调函数，上报的数据类型为AccelerometerResponse。</p>
</td>
</tr>
<tr id="row15724175320317"><td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.5.1.1 "><p id="p44609435225"><a name="p44609435225"></a><a name="p44609435225"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="34.98%" headers="mcps1.1.5.1.2 "><p id="p046015436225"><a name="p046015436225"></a><a name="p046015436225"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="6.819999999999999%" headers="mcps1.1.5.1.3 "><p id="p34601243122216"><a name="p34601243122216"></a><a name="p34601243122216"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="48.26%" headers="mcps1.1.5.1.4 "><p id="p5460124320225"><a name="p5460124320225"></a><a name="p5460124320225"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);    
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
  },
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_LINEAR\_ACCELERATION\)<a name="section136091757133617"></a>

on\(type:SensorType.SENSOR\_TYPE\_ID\_LINEAR\_ACCELERATION,callback:AsyncCallback<LinearAccelerometerResponse\>, options?: Options\): void

监听线性加速度传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table1961125783610"></a>
<table><thead align="left"><tr id="row2612657153617"><th class="cellrowborder" valign="top" width="8.85%" id="mcps1.1.5.1.1"><p id="p5612105713366"><a name="p5612105713366"></a><a name="p5612105713366"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="37.81%" id="mcps1.1.5.1.2"><p id="p26149572361"><a name="p26149572361"></a><a name="p26149572361"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="5.36%" id="mcps1.1.5.1.3"><p id="p19614105713619"><a name="p19614105713619"></a><a name="p19614105713619"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="47.980000000000004%" id="mcps1.1.5.1.4"><p id="p9614957183611"><a name="p9614957183611"></a><a name="p9614957183611"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row9615195714369"><td class="cellrowborder" valign="top" width="8.85%" headers="mcps1.1.5.1.1 "><p id="p8615857143615"><a name="p8615857143615"></a><a name="p8615857143615"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="37.81%" headers="mcps1.1.5.1.2 "><p id="p14615125714366"><a name="p14615125714366"></a><a name="p14615125714366"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="5.36%" headers="mcps1.1.5.1.3 "><p id="p36151957123614"><a name="p36151957123614"></a><a name="p36151957123614"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="47.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p18616145716369"><a name="p18616145716369"></a><a name="p18616145716369"></a>要订阅的线性加速度传感器类型为SENSOR_TYPE_ID_LINEAR_ACCELERATION。</p>
</td>
</tr>
<tr id="row17616145723613"><td class="cellrowborder" valign="top" width="8.85%" headers="mcps1.1.5.1.1 "><p id="p7616125713615"><a name="p7616125713615"></a><a name="p7616125713615"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="37.81%" headers="mcps1.1.5.1.2 "><p id="p1361616577364"><a name="p1361616577364"></a><a name="p1361616577364"></a>AsyncCallback&lt;<a href="#section1151477447">LinearAccelerometerResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="5.36%" headers="mcps1.1.5.1.3 "><p id="p146168577366"><a name="p146168577366"></a><a name="p146168577366"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="47.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p1617105712366"><a name="p1617105712366"></a><a name="p1617105712366"></a>注册线性加速度传感器的回调函数，上报的数据类型为LinearAccelerometerResponse。</p>
</td>
</tr>
<tr id="row661711574369"><td class="cellrowborder" valign="top" width="8.85%" headers="mcps1.1.5.1.1 "><p id="p11617757193614"><a name="p11617757193614"></a><a name="p11617757193614"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="37.81%" headers="mcps1.1.5.1.2 "><p id="p166178578362"><a name="p166178578362"></a><a name="p166178578362"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="5.36%" headers="mcps1.1.5.1.3 "><p id="p106177576369"><a name="p106177576369"></a><a name="p106177576369"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p16178572361"><a name="p16178572361"></a><a name="p16178572361"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
  }
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_ACCELEROMETER\_UNCALIBRATED\)<a name="section146931430738"></a>

on\(type:SensorType.SENSOR\_TYPE\_ID\_ACCELEROMETER\_UNCALIBRATED,callback:AsyncCallback<AccelerometerUncalibratedResponse\>, options?: Options\): void

监听未校准加速度计传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数**：

<a name="table169433019317"></a>
<table><thead align="left"><tr id="row1769411301239"><th class="cellrowborder" valign="top" width="10.92%" id="mcps1.1.5.1.1"><p id="p176941730137"><a name="p176941730137"></a><a name="p176941730137"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="37.15%" id="mcps1.1.5.1.2"><p id="p26942307318"><a name="p26942307318"></a><a name="p26942307318"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.090000000000001%" id="mcps1.1.5.1.3"><p id="p26952305311"><a name="p26952305311"></a><a name="p26952305311"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="44.84%" id="mcps1.1.5.1.4"><p id="p1169515304316"><a name="p1169515304316"></a><a name="p1169515304316"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row96957309311"><td class="cellrowborder" valign="top" width="10.92%" headers="mcps1.1.5.1.1 "><p id="p106961330134"><a name="p106961330134"></a><a name="p106961330134"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="37.15%" headers="mcps1.1.5.1.2 "><p id="p12696930232"><a name="p12696930232"></a><a name="p12696930232"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.090000000000001%" headers="mcps1.1.5.1.3 "><p id="p116961301432"><a name="p116961301432"></a><a name="p116961301432"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.84%" headers="mcps1.1.5.1.4 "><p id="p166971130631"><a name="p166971130631"></a><a name="p166971130631"></a>要订阅的未校准加速度计传感器类型为SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED。</p>
</td>
</tr>
<tr id="row186970301937"><td class="cellrowborder" valign="top" width="10.92%" headers="mcps1.1.5.1.1 "><p id="p166970301635"><a name="p166970301635"></a><a name="p166970301635"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="37.15%" headers="mcps1.1.5.1.2 "><p id="p1969743015319"><a name="p1969743015319"></a><a name="p1969743015319"></a>AsyncCallback&lt;<a href="#section253082316457">AccelerometerUncalibratedResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.090000000000001%" headers="mcps1.1.5.1.3 "><p id="p106974308318"><a name="p106974308318"></a><a name="p106974308318"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.84%" headers="mcps1.1.5.1.4 "><p id="p1669753018319"><a name="p1669753018319"></a><a name="p1669753018319"></a>注册未校准加速度计传感器的回调函数，上报的数据类型为AccelerometerUncalibratedResponse。</p>
</td>
</tr>
<tr id="row76979301934"><td class="cellrowborder" valign="top" width="10.92%" headers="mcps1.1.5.1.1 "><p id="p1469783016319"><a name="p1469783016319"></a><a name="p1469783016319"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="37.15%" headers="mcps1.1.5.1.2 "><p id="p969853010314"><a name="p969853010314"></a><a name="p969853010314"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="7.090000000000001%" headers="mcps1.1.5.1.3 "><p id="p13698143016316"><a name="p13698143016316"></a><a name="p13698143016316"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.84%" headers="mcps1.1.5.1.4 "><p id="p17698130339"><a name="p17698130339"></a><a name="p17698130339"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
    //打印data在x,y,z轴坐标的偏移量
    console.info('X-coordinate bias: ' + data.biasX);
    console.info('Y-coordinate bias: ' + data.biasY);
    console.info('Z-coordinate bias: ' + data.biasZ);
  }
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_GRAVITY\)<a name="section61785238140"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_GRAVITY, callback: AsyncCallback<GravityResponse\>,options?: Options\): void

监听重力传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table917962311415"></a>
<table><thead align="left"><tr id="row1718042310144"><th class="cellrowborder" valign="top" width="12.19%" id="mcps1.1.5.1.1"><p id="p16181192381415"><a name="p16181192381415"></a><a name="p16181192381415"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="26.97%" id="mcps1.1.5.1.2"><p id="p91811523111419"><a name="p91811523111419"></a><a name="p91811523111419"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.68%" id="mcps1.1.5.1.3"><p id="p18181152331410"><a name="p18181152331410"></a><a name="p18181152331410"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.16%" id="mcps1.1.5.1.4"><p id="p818292316145"><a name="p818292316145"></a><a name="p818292316145"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row11823238141"><td class="cellrowborder" valign="top" width="12.19%" headers="mcps1.1.5.1.1 "><p id="p4182102313142"><a name="p4182102313142"></a><a name="p4182102313142"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="26.97%" headers="mcps1.1.5.1.2 "><p id="p81836239140"><a name="p81836239140"></a><a name="p81836239140"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.5.1.3 "><p id="p18183202321417"><a name="p18183202321417"></a><a name="p18183202321417"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.5.1.4 "><p id="p1318318232145"><a name="p1318318232145"></a><a name="p1318318232145"></a>要订阅的重力传感器类型为SENSOR_TYPE_ID_GRAVITY。</p>
</td>
</tr>
<tr id="row118314235143"><td class="cellrowborder" valign="top" width="12.19%" headers="mcps1.1.5.1.1 "><p id="p7183152314141"><a name="p7183152314141"></a><a name="p7183152314141"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="26.97%" headers="mcps1.1.5.1.2 "><p id="p91847236149"><a name="p91847236149"></a><a name="p91847236149"></a>AsyncCallback&lt;<a href="#section162913399453">GravityResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.5.1.3 "><p id="p11184112351418"><a name="p11184112351418"></a><a name="p11184112351418"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.5.1.4 "><p id="p21841323101418"><a name="p21841323101418"></a><a name="p21841323101418"></a>注册重力传感器的回调函数，上报的数据类型为GravityResponse。</p>
</td>
</tr>
<tr id="row2018552321412"><td class="cellrowborder" valign="top" width="12.19%" headers="mcps1.1.5.1.1 "><p id="p11185132351420"><a name="p11185132351420"></a><a name="p11185132351420"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="26.97%" headers="mcps1.1.5.1.2 "><p id="p11185192331413"><a name="p11185192331413"></a><a name="p11185192331413"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.5.1.3 "><p id="p2185923161414"><a name="p2185923161414"></a><a name="p2185923161414"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.5.1.4 "><p id="p19186152381418"><a name="p19186152381418"></a><a name="p19186152381418"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例**：

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_GRAVITY, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x); 
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
  }
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_GYROSCOPE\)<a name="section6189623151413"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_GYROSCOPE, callback: AsyncCallback<GyroscopeResponse\>, options?: Options\): void

监听陀螺仪传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table419015237148"></a>
<table><thead align="left"><tr id="row12190112310148"><th class="cellrowborder" valign="top" width="12.19%" id="mcps1.1.5.1.1"><p id="p1419017237144"><a name="p1419017237144"></a><a name="p1419017237144"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="29.909999999999997%" id="mcps1.1.5.1.2"><p id="p1419142321414"><a name="p1419142321414"></a><a name="p1419142321414"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.529999999999999%" id="mcps1.1.5.1.3"><p id="p201911023141411"><a name="p201911023141411"></a><a name="p201911023141411"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="51.370000000000005%" id="mcps1.1.5.1.4"><p id="p1619192312145"><a name="p1619192312145"></a><a name="p1619192312145"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row8191323131414"><td class="cellrowborder" valign="top" width="12.19%" headers="mcps1.1.5.1.1 "><p id="p11191172312141"><a name="p11191172312141"></a><a name="p11191172312141"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="29.909999999999997%" headers="mcps1.1.5.1.2 "><p id="p18192142317146"><a name="p18192142317146"></a><a name="p18192142317146"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.529999999999999%" headers="mcps1.1.5.1.3 "><p id="p1519282321414"><a name="p1519282321414"></a><a name="p1519282321414"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="51.370000000000005%" headers="mcps1.1.5.1.4 "><p id="p9193523151412"><a name="p9193523151412"></a><a name="p9193523151412"></a>要订阅的陀螺仪传感器类型为SENSOR_TYPE_ID_GYROSCOPE。</p>
</td>
</tr>
<tr id="row9193162301418"><td class="cellrowborder" valign="top" width="12.19%" headers="mcps1.1.5.1.1 "><p id="p119312237148"><a name="p119312237148"></a><a name="p119312237148"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="29.909999999999997%" headers="mcps1.1.5.1.2 "><p id="p6193023111417"><a name="p6193023111417"></a><a name="p6193023111417"></a>AsyncCallback&lt;<a href="#section3669131713463">GyroscopeResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.529999999999999%" headers="mcps1.1.5.1.3 "><p id="p01931023171410"><a name="p01931023171410"></a><a name="p01931023171410"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="51.370000000000005%" headers="mcps1.1.5.1.4 "><p id="p1519412312142"><a name="p1519412312142"></a><a name="p1519412312142"></a>注册陀螺仪传感器的回调函数，上报的数据类型为GyroscopeResponse。</p>
</td>
</tr>
<tr id="row21944234143"><td class="cellrowborder" valign="top" width="12.19%" headers="mcps1.1.5.1.1 "><p id="p1219412351412"><a name="p1219412351412"></a><a name="p1219412351412"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="29.909999999999997%" headers="mcps1.1.5.1.2 "><p id="p201941823151410"><a name="p201941823151410"></a><a name="p201941823151410"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="6.529999999999999%" headers="mcps1.1.5.1.3 "><p id="p01941123141415"><a name="p01941123141415"></a><a name="p01941123141415"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.370000000000005%" headers="mcps1.1.5.1.4 "><p id="p3194523111410"><a name="p3194523111410"></a><a name="p3194523111410"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x); 
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
  }
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_GYROSCOPE\_UNCALIBRATED\)<a name="section5203122341410"></a>

on\(type:SensorType.SENSOR\_TYPE\_ID\_GYROSCOPE\_UNCALIBRATED,callback:AsyncCallback<GyroscopeUncalibratedResponse\>, options?: Options\): void

监听未校准陀螺仪传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table7204723191416"></a>
<table><thead align="left"><tr id="row6204132381416"><th class="cellrowborder" valign="top" width="9.22%" id="mcps1.1.5.1.1"><p id="p10204162311141"><a name="p10204162311141"></a><a name="p10204162311141"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="39.58%" id="mcps1.1.5.1.2"><p id="p15204923131413"><a name="p15204923131413"></a><a name="p15204923131413"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6%" id="mcps1.1.5.1.3"><p id="p1820502316146"><a name="p1820502316146"></a><a name="p1820502316146"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="45.2%" id="mcps1.1.5.1.4"><p id="p12054235142"><a name="p12054235142"></a><a name="p12054235142"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row18205152318147"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p9206192351414"><a name="p9206192351414"></a><a name="p9206192351414"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.5.1.2 "><p id="p92061223121414"><a name="p92061223121414"></a><a name="p92061223121414"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="6%" headers="mcps1.1.5.1.3 "><p id="p1820612234142"><a name="p1820612234142"></a><a name="p1820612234142"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="45.2%" headers="mcps1.1.5.1.4 "><p id="p102061723201420"><a name="p102061723201420"></a><a name="p102061723201420"></a>要订阅的未校准陀螺仪传感器类型为SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED。</p>
</td>
</tr>
<tr id="row1520612319148"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p17207523161415"><a name="p17207523161415"></a><a name="p17207523161415"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.5.1.2 "><p id="p0207123161419"><a name="p0207123161419"></a><a name="p0207123161419"></a>AsyncCallback&lt;<a href="#section1041541413475">GyroscopeUncalibratedResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6%" headers="mcps1.1.5.1.3 "><p id="p1820792381418"><a name="p1820792381418"></a><a name="p1820792381418"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="45.2%" headers="mcps1.1.5.1.4 "><p id="p520782381414"><a name="p520782381414"></a><a name="p520782381414"></a>注册未校准陀螺仪传感器的回调函数，上报的数据类型为GyroscopeUncalibratedResponse。</p>
</td>
</tr>
<tr id="row2020772313145"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p1720820233140"><a name="p1720820233140"></a><a name="p1720820233140"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.5.1.2 "><p id="p2020812312143"><a name="p2020812312143"></a><a name="p2020812312143"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="6%" headers="mcps1.1.5.1.3 "><p id="p18208142301416"><a name="p18208142301416"></a><a name="p18208142301416"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.2%" headers="mcps1.1.5.1.4 "><p id="p10208122341410"><a name="p10208122341410"></a><a name="p10208122341410"></a>可选参数列表，设置上报频率。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);  
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
    //打印data的x,y,z轴坐标的偏移量
    console.info('X-coordinate bias: ' + data.biasX); 
    console.info('Y-coordinate bias: ' + data.biasY);
    console.info('Z-coordinate bias: ' + data.biasZ);
  }
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_SIGNIFICANT\_MOTION\)<a name="section1824612372145"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_SIGNIFICANT\_MOTION, callback: AsyncCallback<SignificantMotionResponse\>, options?: Options\): void

监听有效运动传感器数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table0246637171416"></a>
<table><thead align="left"><tr id="row224719377142"><th class="cellrowborder" valign="top" width="9.67%" id="mcps1.1.5.1.1"><p id="p12247137131416"><a name="p12247137131416"></a><a name="p12247137131416"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="37.1%" id="mcps1.1.5.1.2"><p id="p1124813716149"><a name="p1124813716149"></a><a name="p1124813716149"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.6000000000000005%" id="mcps1.1.5.1.3"><p id="p1624883711146"><a name="p1624883711146"></a><a name="p1624883711146"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="46.63%" id="mcps1.1.5.1.4"><p id="p7248103718149"><a name="p7248103718149"></a><a name="p7248103718149"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row0248113712146"><td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.5.1.1 "><p id="p13248437171417"><a name="p13248437171417"></a><a name="p13248437171417"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="37.1%" headers="mcps1.1.5.1.2 "><p id="p92481837171418"><a name="p92481837171418"></a><a name="p92481837171418"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.6000000000000005%" headers="mcps1.1.5.1.3 "><p id="p824816372145"><a name="p824816372145"></a><a name="p824816372145"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="46.63%" headers="mcps1.1.5.1.4 "><p id="p7252133716144"><a name="p7252133716144"></a><a name="p7252133716144"></a>要订阅的有效运动传感器类型为SENSOR_TYPE_ID_SIGNIFICANT_MOTION。</p>
</td>
</tr>
<tr id="row112521375148"><td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.5.1.1 "><p id="p1425333741416"><a name="p1425333741416"></a><a name="p1425333741416"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="37.1%" headers="mcps1.1.5.1.2 "><p id="p125303761417"><a name="p125303761417"></a><a name="p125303761417"></a>AsyncCallback&lt;<a href="#section1213143164712">SignificantMotionResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.6000000000000005%" headers="mcps1.1.5.1.3 "><p id="p825333714140"><a name="p825333714140"></a><a name="p825333714140"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="46.63%" headers="mcps1.1.5.1.4 "><p id="p132531837141413"><a name="p132531837141413"></a><a name="p132531837141413"></a>注册有效运动传感器的回调函数，上报的数据类型为SignificantMotionResponse。</p>
</td>
</tr>
<tr id="row20253183771420"><td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.5.1.1 "><p id="p1825463717144"><a name="p1825463717144"></a><a name="p1825463717144"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="37.1%" headers="mcps1.1.5.1.2 "><p id="p1825423761415"><a name="p1825423761415"></a><a name="p1825423761415"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="6.6000000000000005%" headers="mcps1.1.5.1.3 "><p id="p112543377143"><a name="p112543377143"></a><a name="p112543377143"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.63%" headers="mcps1.1.5.1.4 "><p id="p18254203751414"><a name="p18254203751414"></a><a name="p18254203751414"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    console.info('Scalar data: ' + data.scalar);
  }
  {interval: 10000000}      
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_PEDOMETER\_DETECTION\)<a name="section13257937131411"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_PEDOMETER\_DETECTION, callback: AsyncCallback<PedometerDetectResponse\>, options?: Options\): void

监听计步检测传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table025743713141"></a>
<table><thead align="left"><tr id="row225873711414"><th class="cellrowborder" valign="top" width="8.86%" id="mcps1.1.5.1.1"><p id="p13258113718147"><a name="p13258113718147"></a><a name="p13258113718147"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="39.79%" id="mcps1.1.5.1.2"><p id="p12258183710144"><a name="p12258183710144"></a><a name="p12258183710144"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.51%" id="mcps1.1.5.1.3"><p id="p12258137101410"><a name="p12258137101410"></a><a name="p12258137101410"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="43.84%" id="mcps1.1.5.1.4"><p id="p1425820379147"><a name="p1425820379147"></a><a name="p1425820379147"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row18259153711145"><td class="cellrowborder" valign="top" width="8.86%" headers="mcps1.1.5.1.1 "><p id="p152591837181416"><a name="p152591837181416"></a><a name="p152591837181416"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="39.79%" headers="mcps1.1.5.1.2 "><p id="p1025963716142"><a name="p1025963716142"></a><a name="p1025963716142"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.51%" headers="mcps1.1.5.1.3 "><p id="p92591437181417"><a name="p92591437181417"></a><a name="p92591437181417"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="43.84%" headers="mcps1.1.5.1.4 "><p id="p7259837101411"><a name="p7259837101411"></a><a name="p7259837101411"></a>要订阅的计步检测传感器类型为SENSOR_TYPE_ID_PEDOMETER_DETECTION。</p>
</td>
</tr>
<tr id="row20259183761419"><td class="cellrowborder" valign="top" width="8.86%" headers="mcps1.1.5.1.1 "><p id="p1926053712141"><a name="p1926053712141"></a><a name="p1926053712141"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="39.79%" headers="mcps1.1.5.1.2 "><p id="p1126003791412"><a name="p1126003791412"></a><a name="p1126003791412"></a>AsyncCallback&lt;<a href="#section145653910491">PedometerDetectResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.51%" headers="mcps1.1.5.1.3 "><p id="p1260103719145"><a name="p1260103719145"></a><a name="p1260103719145"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="43.84%" headers="mcps1.1.5.1.4 "><p id="p326083741417"><a name="p326083741417"></a><a name="p326083741417"></a>注册计步检测传感器的回调函数，上报的数据类型为PedometerDetectResponse。</p>
</td>
</tr>
<tr id="row1126123791420"><td class="cellrowborder" valign="top" width="8.86%" headers="mcps1.1.5.1.1 "><p id="p12611537121411"><a name="p12611537121411"></a><a name="p12611537121411"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="39.79%" headers="mcps1.1.5.1.2 "><p id="p2261437151412"><a name="p2261437151412"></a><a name="p2261437151412"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="7.51%" headers="mcps1.1.5.1.3 "><p id="p15261103791413"><a name="p15261103791413"></a><a name="p15261103791413"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.84%" headers="mcps1.1.5.1.4 "><p id="p2026273781417"><a name="p2026273781417"></a><a name="p2026273781417"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, function(error, data) {
    if (error) {
        console.error(""Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    console.info('Scalar data: ' + data.scalar);
  }
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_PEDOMETER\)<a name="section2266113791419"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_PEDOMETER, callback: AsyncCallback<PedometerResponse\>, options?: Options\): void

监听计步传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table1026673751411"></a>
<table><thead align="left"><tr id="row13267103781414"><th class="cellrowborder" valign="top" width="11.01%" id="mcps1.1.5.1.1"><p id="p3267193720144"><a name="p3267193720144"></a><a name="p3267193720144"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="32.76%" id="mcps1.1.5.1.2"><p id="p1267537101416"><a name="p1267537101416"></a><a name="p1267537101416"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.870000000000001%" id="mcps1.1.5.1.3"><p id="p112678378147"><a name="p112678378147"></a><a name="p112678378147"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="48.36%" id="mcps1.1.5.1.4"><p id="p132679370141"><a name="p132679370141"></a><a name="p132679370141"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row18267113791416"><td class="cellrowborder" valign="top" width="11.01%" headers="mcps1.1.5.1.1 "><p id="p1626883715145"><a name="p1626883715145"></a><a name="p1626883715145"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="32.76%" headers="mcps1.1.5.1.2 "><p id="p16268153741414"><a name="p16268153741414"></a><a name="p16268153741414"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.870000000000001%" headers="mcps1.1.5.1.3 "><p id="p2026810377145"><a name="p2026810377145"></a><a name="p2026810377145"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.36%" headers="mcps1.1.5.1.4 "><p id="p2026813781414"><a name="p2026813781414"></a><a name="p2026813781414"></a>要订阅的计步传感器类型为SENSOR_TYPE_ID_PEDOMETER。</p>
</td>
</tr>
<tr id="row1226803771414"><td class="cellrowborder" valign="top" width="11.01%" headers="mcps1.1.5.1.1 "><p id="p1626817374148"><a name="p1626817374148"></a><a name="p1626817374148"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="32.76%" headers="mcps1.1.5.1.2 "><p id="p13268133715141"><a name="p13268133715141"></a><a name="p13268133715141"></a>AsyncCallback&lt;<a href="#section1350145915489">PedometerResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.870000000000001%" headers="mcps1.1.5.1.3 "><p id="p82692378147"><a name="p82692378147"></a><a name="p82692378147"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.36%" headers="mcps1.1.5.1.4 "><p id="p1826963710141"><a name="p1826963710141"></a><a name="p1826963710141"></a>注册计步传感器的回调函数，上报的数据类型为PedometerResponse。</p>
</td>
</tr>
<tr id="row10269173731418"><td class="cellrowborder" valign="top" width="11.01%" headers="mcps1.1.5.1.1 "><p id="p1526916371145"><a name="p1526916371145"></a><a name="p1526916371145"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="32.76%" headers="mcps1.1.5.1.2 "><p id="p227023714147"><a name="p227023714147"></a><a name="p227023714147"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="7.870000000000001%" headers="mcps1.1.5.1.3 "><p id="p142701837181411"><a name="p142701837181411"></a><a name="p142701837181411"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="48.36%" headers="mcps1.1.5.1.4 "><p id="p132705374148"><a name="p132705374148"></a><a name="p132705374148"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的步数
    console.info('Steps: ' + data.steps);
  }
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_AMBIENT\_TEMPERATURE\)<a name="section14362204121410"></a>

on\(type:SensorType.SENSOR\_TYPE\_ID\_AMBIENT\_TEMPERATURE,callback:AsyncCallback<AmbientTemperatureResponse\>,  options?: Options\): void

监听环境温度传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table15362204119146"></a>
<table><thead align="left"><tr id="row163631841101419"><th class="cellrowborder" valign="top" width="8.76%" id="mcps1.1.5.1.1"><p id="p10363641191417"><a name="p10363641191417"></a><a name="p10363641191417"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="39.129999999999995%" id="mcps1.1.5.1.2"><p id="p6363164111142"><a name="p6363164111142"></a><a name="p6363164111142"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.01%" id="mcps1.1.5.1.3"><p id="p183642041161418"><a name="p183642041161418"></a><a name="p183642041161418"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="45.1%" id="mcps1.1.5.1.4"><p id="p12364184114143"><a name="p12364184114143"></a><a name="p12364184114143"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row6364104112149"><td class="cellrowborder" valign="top" width="8.76%" headers="mcps1.1.5.1.1 "><p id="p133641241141418"><a name="p133641241141418"></a><a name="p133641241141418"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="39.129999999999995%" headers="mcps1.1.5.1.2 "><p id="p16364194101416"><a name="p16364194101416"></a><a name="p16364194101416"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.01%" headers="mcps1.1.5.1.3 "><p id="p11365241171410"><a name="p11365241171410"></a><a name="p11365241171410"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="45.1%" headers="mcps1.1.5.1.4 "><p id="p183651141141417"><a name="p183651141141417"></a><a name="p183651141141417"></a>要订阅的环境温度传感器类型为SENSOR_TYPE_ID_AMBIENT_TEMPERATURE。</p>
</td>
</tr>
<tr id="row1236514414147"><td class="cellrowborder" valign="top" width="8.76%" headers="mcps1.1.5.1.1 "><p id="p836524181418"><a name="p836524181418"></a><a name="p836524181418"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="39.129999999999995%" headers="mcps1.1.5.1.2 "><p id="p836584171416"><a name="p836584171416"></a><a name="p836584171416"></a>AsyncCallback&lt;<a href="#section728281924920">AmbientTemperatureResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.01%" headers="mcps1.1.5.1.3 "><p id="p53657414142"><a name="p53657414142"></a><a name="p53657414142"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="45.1%" headers="mcps1.1.5.1.4 "><p id="p636684118142"><a name="p636684118142"></a><a name="p636684118142"></a>注册环境温度传感器的回调函数，上报的数据类型为AmbientTemperatureResponse。</p>
</td>
</tr>
<tr id="row93661641181417"><td class="cellrowborder" valign="top" width="8.76%" headers="mcps1.1.5.1.1 "><p id="p12366241101415"><a name="p12366241101415"></a><a name="p12366241101415"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="39.129999999999995%" headers="mcps1.1.5.1.2 "><p id="p3366154116144"><a name="p3366154116144"></a><a name="p3366154116144"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="7.01%" headers="mcps1.1.5.1.3 "><p id="p436624111416"><a name="p436624111416"></a><a name="p436624111416"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.1%" headers="mcps1.1.5.1.4 "><p id="p163675414149"><a name="p163675414149"></a><a name="p163675414149"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的温度值
    console.info('Temperature: ' + data.temperature);
  }
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_MAGNETIC\_FIELD\)<a name="section337584101411"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_MAGNETIC\_FIELD, callback: AsyncCallback<MagneticFieldResponse\>,options?: Options\): void

监听磁场传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table1376184111420"></a>
<table><thead align="left"><tr id="row837654181415"><th class="cellrowborder" valign="top" width="9.31%" id="mcps1.1.5.1.1"><p id="p2037774191414"><a name="p2037774191414"></a><a name="p2037774191414"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="34.4%" id="mcps1.1.5.1.2"><p id="p437714121412"><a name="p437714121412"></a><a name="p437714121412"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.36%" id="mcps1.1.5.1.3"><p id="p13377204181410"><a name="p13377204181410"></a><a name="p13377204181410"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.93%" id="mcps1.1.5.1.4"><p id="p133771341191413"><a name="p133771341191413"></a><a name="p133771341191413"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1737710415146"><td class="cellrowborder" valign="top" width="9.31%" headers="mcps1.1.5.1.1 "><p id="p43772041121410"><a name="p43772041121410"></a><a name="p43772041121410"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="34.4%" headers="mcps1.1.5.1.2 "><p id="p1437874131413"><a name="p1437874131413"></a><a name="p1437874131413"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.36%" headers="mcps1.1.5.1.3 "><p id="p9378441191415"><a name="p9378441191415"></a><a name="p9378441191415"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.93%" headers="mcps1.1.5.1.4 "><p id="p183789419144"><a name="p183789419144"></a><a name="p183789419144"></a>要订阅的磁场传感器类型为SENSOR_TYPE_ID_MAGNETIC_FIELD。</p>
</td>
</tr>
<tr id="row737854151420"><td class="cellrowborder" valign="top" width="9.31%" headers="mcps1.1.5.1.1 "><p id="p1237844114147"><a name="p1237844114147"></a><a name="p1237844114147"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="34.4%" headers="mcps1.1.5.1.2 "><p id="p637811414141"><a name="p637811414141"></a><a name="p637811414141"></a>AsyncCallback&lt;<a href="#section20218191813489">MagneticFieldResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.36%" headers="mcps1.1.5.1.3 "><p id="p33791841141419"><a name="p33791841141419"></a><a name="p33791841141419"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.93%" headers="mcps1.1.5.1.4 "><p id="p133792419146"><a name="p133792419146"></a><a name="p133792419146"></a>注册磁场传感器的回调函数，上报的数据类型为MagneticFieldResponse。</p>
</td>
</tr>
<tr id="row15379184113149"><td class="cellrowborder" valign="top" width="9.31%" headers="mcps1.1.5.1.1 "><p id="p937964101412"><a name="p937964101412"></a><a name="p937964101412"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="34.4%" headers="mcps1.1.5.1.2 "><p id="p1837944118145"><a name="p1837944118145"></a><a name="p1837944118145"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="6.36%" headers="mcps1.1.5.1.3 "><p id="p10379194118140"><a name="p10379194118140"></a><a name="p10379194118140"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.93%" headers="mcps1.1.5.1.4 "><p id="p1738084121418"><a name="p1738084121418"></a><a name="p1738084121418"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
  }
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_MAGNETIC\_FIELD\_UNCALIBRATED\)<a name="section1738444151414"></a>

on\(type:SensorType.SENSOR\_TYPE\_ID\_MAGNETIC\_FIELD\_UNCALIBRATED,callback:AsyncCallback<MagneticFieldUncalibratedResponse\>, options: Options\): void

监听未校准磁场传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table153864419148"></a>
<table><thead align="left"><tr id="row638744121418"><th class="cellrowborder" valign="top" width="9.22%" id="mcps1.1.5.1.1"><p id="p0387141101412"><a name="p0387141101412"></a><a name="p0387141101412"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="32.79%" id="mcps1.1.5.1.2"><p id="p16388154191418"><a name="p16388154191418"></a><a name="p16388154191418"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.41%" id="mcps1.1.5.1.3"><p id="p23881441201418"><a name="p23881441201418"></a><a name="p23881441201418"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="50.580000000000005%" id="mcps1.1.5.1.4"><p id="p13388104113146"><a name="p13388104113146"></a><a name="p13388104113146"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row638844112148"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p1038964191419"><a name="p1038964191419"></a><a name="p1038964191419"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.5.1.2 "><p id="p18389184118144"><a name="p18389184118144"></a><a name="p18389184118144"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.41%" headers="mcps1.1.5.1.3 "><p id="p163891241151413"><a name="p163891241151413"></a><a name="p163891241151413"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="50.580000000000005%" headers="mcps1.1.5.1.4 "><p id="p10389174112148"><a name="p10389174112148"></a><a name="p10389174112148"></a>要订阅的未校准磁场传感器类型为SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED。</p>
</td>
</tr>
<tr id="row17389134117147"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p123901741131412"><a name="p123901741131412"></a><a name="p123901741131412"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.5.1.2 "><p id="p939084120141"><a name="p939084120141"></a><a name="p939084120141"></a>AsyncCallback&lt;<a href="#section13749143113486">MagneticFieldUncalibratedResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.41%" headers="mcps1.1.5.1.3 "><p id="p1339013419141"><a name="p1339013419141"></a><a name="p1339013419141"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="50.580000000000005%" headers="mcps1.1.5.1.4 "><p id="p93909413142"><a name="p93909413142"></a><a name="p93909413142"></a>注册未校准磁场传感器的回调函数，上报的数据类型为MagneticFieldUncalibratedResponse。</p>
</td>
</tr>
<tr id="row3390164110146"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p43908418146"><a name="p43908418146"></a><a name="p43908418146"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.5.1.2 "><p id="p1839114417149"><a name="p1839114417149"></a><a name="p1839114417149"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="7.41%" headers="mcps1.1.5.1.3 "><p id="p203911241111412"><a name="p203911241111412"></a><a name="p203911241111412"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="50.580000000000005%" headers="mcps1.1.5.1.4 "><p id="p5391541101417"><a name="p5391541101417"></a><a name="p5391541101417"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);    
    console.info('Y-coordinate component: ' + data.y);    
    console.info('Z-coordinate component: ' + data.z);    
    //打印data的x,y,z轴坐标的偏移量
    console.info('X-coordinate bias: ' + data.biasX);    
    console.info('Y-coordinate bias: ' + data.biasY);
    console.info('Z-coordinate bias: ' + data.biasZ);
  }
  {interval: 10000000}   //设置数据的上报频率。
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_PROXIMITY\)<a name="section12931751101418"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_PROXIMITY, callback: AsyncCallback<ProximityResponse\>,options?: Options\): void

监听接近光传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table162945519145"></a>
<table><thead align="left"><tr id="row1294135117147"><th class="cellrowborder" valign="top" width="9.22%" id="mcps1.1.5.1.1"><p id="p7295155111147"><a name="p7295155111147"></a><a name="p7295155111147"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="33.14%" id="mcps1.1.5.1.2"><p id="p1729513511146"><a name="p1729513511146"></a><a name="p1729513511146"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.890000000000001%" id="mcps1.1.5.1.3"><p id="p82951651121411"><a name="p82951651121411"></a><a name="p82951651121411"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="50.74999999999999%" id="mcps1.1.5.1.4"><p id="p529585111410"><a name="p529585111410"></a><a name="p529585111410"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row12295351101420"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p529585113147"><a name="p529585113147"></a><a name="p529585113147"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="33.14%" headers="mcps1.1.5.1.2 "><p id="p1929535117144"><a name="p1929535117144"></a><a name="p1929535117144"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.890000000000001%" headers="mcps1.1.5.1.3 "><p id="p229655161411"><a name="p229655161411"></a><a name="p229655161411"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="50.74999999999999%" headers="mcps1.1.5.1.4 "><p id="p1329695116143"><a name="p1329695116143"></a><a name="p1329695116143"></a>要订阅的接近光传感器类型为SENSOR_TYPE_ID_PROXIMITY。</p>
</td>
</tr>
<tr id="row112961251121415"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p7296165181419"><a name="p7296165181419"></a><a name="p7296165181419"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="33.14%" headers="mcps1.1.5.1.2 "><p id="p729695171410"><a name="p729695171410"></a><a name="p729695171410"></a>AsyncCallback&lt;<a href="#section5275184313476">ProximityResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.890000000000001%" headers="mcps1.1.5.1.3 "><p id="p72968518149"><a name="p72968518149"></a><a name="p72968518149"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="50.74999999999999%" headers="mcps1.1.5.1.4 "><p id="p429765111417"><a name="p429765111417"></a><a name="p429765111417"></a>注册接近光传感器的回调函数，上报的数据类型为ProximityResponse。</p>
</td>
</tr>
<tr id="row1229715112141"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p3297195111412"><a name="p3297195111412"></a><a name="p3297195111412"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="33.14%" headers="mcps1.1.5.1.2 "><p id="p529785110147"><a name="p529785110147"></a><a name="p529785110147"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="6.890000000000001%" headers="mcps1.1.5.1.3 "><p id="p1229765151414"><a name="p1229765151414"></a><a name="p1229765151414"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="50.74999999999999%" headers="mcps1.1.5.1.4 "><p id="p1229735141410"><a name="p1229735141410"></a><a name="p1229735141410"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的距离值
    console.info('Distance: ' + data.distance);
  }
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_HUMIDITY\)<a name="section0302151141413"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_HUMIDITY, callback: AsyncCallback<HumidityResponse\>,options?: Options\): void

监听湿度传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table43021451141414"></a>
<table><thead align="left"><tr id="row6302185131417"><th class="cellrowborder" valign="top" width="10.12%" id="mcps1.1.5.1.1"><p id="p103026514148"><a name="p103026514148"></a><a name="p103026514148"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="31.830000000000002%" id="mcps1.1.5.1.2"><p id="p3302051131418"><a name="p3302051131418"></a><a name="p3302051131418"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.66%" id="mcps1.1.5.1.3"><p id="p11303195112144"><a name="p11303195112144"></a><a name="p11303195112144"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="50.39%" id="mcps1.1.5.1.4"><p id="p0303351181420"><a name="p0303351181420"></a><a name="p0303351181420"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1330320518149"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p19303115101414"><a name="p19303115101414"></a><a name="p19303115101414"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="31.830000000000002%" headers="mcps1.1.5.1.2 "><p id="p330325161417"><a name="p330325161417"></a><a name="p330325161417"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.66%" headers="mcps1.1.5.1.3 "><p id="p15303155113142"><a name="p15303155113142"></a><a name="p15303155113142"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="50.39%" headers="mcps1.1.5.1.4 "><p id="p13304165117144"><a name="p13304165117144"></a><a name="p13304165117144"></a>要订阅的湿度传感器类型为SENSOR_TYPE_ID_HUMIDITY。</p>
</td>
</tr>
<tr id="row143041751141413"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p1304185112143"><a name="p1304185112143"></a><a name="p1304185112143"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="31.830000000000002%" headers="mcps1.1.5.1.2 "><p id="p130495131419"><a name="p130495131419"></a><a name="p130495131419"></a>AsyncCallback&lt;<a href="#section20444511666">HumidityResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.66%" headers="mcps1.1.5.1.3 "><p id="p4304155121411"><a name="p4304155121411"></a><a name="p4304155121411"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="50.39%" headers="mcps1.1.5.1.4 "><p id="p1130435181416"><a name="p1130435181416"></a><a name="p1130435181416"></a>注册湿度传感器的回调函数，上报的数据类型为HumidityResponse。</p>
</td>
</tr>
<tr id="row14305145181415"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p20305951141410"><a name="p20305951141410"></a><a name="p20305951141410"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="31.830000000000002%" headers="mcps1.1.5.1.2 "><p id="p03055519147"><a name="p03055519147"></a><a name="p03055519147"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="7.66%" headers="mcps1.1.5.1.3 "><p id="p15305151141420"><a name="p15305151141420"></a><a name="p15305151141420"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="50.39%" headers="mcps1.1.5.1.4 "><p id="p16305451181418"><a name="p16305451181418"></a><a name="p16305451181418"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的湿度值
    console.info('Humidity: ' + data.humidity);
  }
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_BAROMETER\)<a name="section63108518141"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_BAROMETER, callback: AsyncCallback<BarometerResponse\>,options?: Options\): void

监听气压计传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table1431065181410"></a>
<table><thead align="left"><tr id="row173111517141"><th class="cellrowborder" valign="top" width="9.76%" id="mcps1.1.5.1.1"><p id="p15311165116148"><a name="p15311165116148"></a><a name="p15311165116148"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="31.94%" id="mcps1.1.5.1.2"><p id="p3311175151413"><a name="p3311175151413"></a><a name="p3311175151413"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.46%" id="mcps1.1.5.1.3"><p id="p43115516149"><a name="p43115516149"></a><a name="p43115516149"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="50.839999999999996%" id="mcps1.1.5.1.4"><p id="p531185115147"><a name="p531185115147"></a><a name="p531185115147"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1931111510141"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p331135171420"><a name="p331135171420"></a><a name="p331135171420"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="31.94%" headers="mcps1.1.5.1.2 "><p id="p93119518140"><a name="p93119518140"></a><a name="p93119518140"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.46%" headers="mcps1.1.5.1.3 "><p id="p7312751181415"><a name="p7312751181415"></a><a name="p7312751181415"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="50.839999999999996%" headers="mcps1.1.5.1.4 "><p id="p163121851101413"><a name="p163121851101413"></a><a name="p163121851101413"></a>要订阅的气压计传感器类型为SENSOR_TYPE_ID_BAROMETER。</p>
</td>
</tr>
<tr id="row9312351181417"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p4312145113147"><a name="p4312145113147"></a><a name="p4312145113147"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="31.94%" headers="mcps1.1.5.1.2 "><p id="p53126517148"><a name="p53126517148"></a><a name="p53126517148"></a>AsyncCallback&lt;<a href="#section143457303496">BarometerResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.46%" headers="mcps1.1.5.1.3 "><p id="p231295121412"><a name="p231295121412"></a><a name="p231295121412"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="50.839999999999996%" headers="mcps1.1.5.1.4 "><p id="p12312051101416"><a name="p12312051101416"></a><a name="p12312051101416"></a>注册气压计传感器的回调函数，上报的数据类型为BarometerResponse。</p>
</td>
</tr>
<tr id="row143129513144"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p183135518143"><a name="p183135518143"></a><a name="p183135518143"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="31.94%" headers="mcps1.1.5.1.2 "><p id="p0313125171415"><a name="p0313125171415"></a><a name="p0313125171415"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="7.46%" headers="mcps1.1.5.1.3 "><p id="p731305111416"><a name="p731305111416"></a><a name="p731305111416"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="50.839999999999996%" headers="mcps1.1.5.1.4 "><p id="p103131751111410"><a name="p103131751111410"></a><a name="p103131751111410"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的压强值
    console.info('Atmospheric pressure: ' + data.pressure);
  }
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_HALL\)<a name="section20525181564919"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_HALL, callback: AsyncCallback<HallResponse\>, options?: Options\): void

监听霍尔传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table1733554145"></a>
<table><thead align="left"><tr id="row84955101418"><th class="cellrowborder" valign="top" width="10.47%" id="mcps1.1.5.1.1"><p id="p14445511141"><a name="p14445511141"></a><a name="p14445511141"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="28.689999999999998%" id="mcps1.1.5.1.2"><p id="p10485551410"><a name="p10485551410"></a><a name="p10485551410"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.68%" id="mcps1.1.5.1.3"><p id="p9413554146"><a name="p9413554146"></a><a name="p9413554146"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.16%" id="mcps1.1.5.1.4"><p id="p114165514149"><a name="p114165514149"></a><a name="p114165514149"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row75855131417"><td class="cellrowborder" valign="top" width="10.47%" headers="mcps1.1.5.1.1 "><p id="p165655141418"><a name="p165655141418"></a><a name="p165655141418"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="28.689999999999998%" headers="mcps1.1.5.1.2 "><p id="p1051455161412"><a name="p1051455161412"></a><a name="p1051455161412"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.5.1.3 "><p id="p55175581415"><a name="p55175581415"></a><a name="p55175581415"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.5.1.4 "><p id="p115155513143"><a name="p115155513143"></a><a name="p115155513143"></a>要订阅的霍尔传感器类型为SENSOR_TYPE_ID_HALL。</p>
</td>
</tr>
<tr id="row175165515149"><td class="cellrowborder" valign="top" width="10.47%" headers="mcps1.1.5.1.1 "><p id="p1151155151417"><a name="p1151155151417"></a><a name="p1151155151417"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="28.689999999999998%" headers="mcps1.1.5.1.2 "><p id="p8515511142"><a name="p8515511142"></a><a name="p8515511142"></a>AsyncCallback&lt;<a href="#section18608467487">HallResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.5.1.3 "><p id="p14612557146"><a name="p14612557146"></a><a name="p14612557146"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.5.1.4 "><p id="p8645521420"><a name="p8645521420"></a><a name="p8645521420"></a>注册霍尔传感器的回调函数，上报的数据类型为 HallResponse。</p>
</td>
</tr>
<tr id="row1661555161416"><td class="cellrowborder" valign="top" width="10.47%" headers="mcps1.1.5.1.1 "><p id="p156125531418"><a name="p156125531418"></a><a name="p156125531418"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="28.689999999999998%" headers="mcps1.1.5.1.2 "><p id="p01016558147"><a name="p01016558147"></a><a name="p01016558147"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.5.1.3 "><p id="p51045531419"><a name="p51045531419"></a><a name="p51045531419"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.5.1.4 "><p id="p1811155510149"><a name="p1811155510149"></a><a name="p1811155510149"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HALL, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的状态值
    console.info('Status: ' + data.status);
  }
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_AMBIENT\_LIGHT\)<a name="section121685551415"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_AMBIENT\_LIGHT, callback: AsyncCallback<LightResponse\>, options?: Options\): void

监听环境光传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table1616135515141"></a>
<table><thead align="left"><tr id="row131715511142"><th class="cellrowborder" valign="top" width="9.22%" id="mcps1.1.5.1.1"><p id="p9171255171416"><a name="p9171255171416"></a><a name="p9171255171416"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.5.1.2"><p id="p81735541411"><a name="p81735541411"></a><a name="p81735541411"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.6%" id="mcps1.1.5.1.3"><p id="p51815551148"><a name="p51815551148"></a><a name="p51815551148"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="48.96%" id="mcps1.1.5.1.4"><p id="p61816553148"><a name="p61816553148"></a><a name="p61816553148"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row51885521415"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p19184551149"><a name="p19184551149"></a><a name="p19184551149"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.5.1.2 "><p id="p1618155511412"><a name="p1618155511412"></a><a name="p1618155511412"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.5.1.3 "><p id="p619955121418"><a name="p619955121418"></a><a name="p619955121418"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="p154574884417"><a name="p154574884417"></a><a name="p154574884417"></a>要订阅的环境光传感器类型为SENSOR_TYPE_ID_AMBIENT_LIGHT。</p>
</td>
</tr>
<tr id="row1919185515144"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p8201355191413"><a name="p8201355191413"></a><a name="p8201355191413"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.5.1.2 "><p id="p112025510141"><a name="p112025510141"></a><a name="p112025510141"></a>AsyncCallback&lt;<a href="#section195685404716">LightResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.5.1.3 "><p id="p42025581412"><a name="p42025581412"></a><a name="p42025581412"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="p132095511143"><a name="p132095511143"></a><a name="p132095511143"></a>注册环境光传感器的回调函数，上报的数据类型为LightResponse。</p>
</td>
</tr>
<tr id="row1720115531412"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p1921105517143"><a name="p1921105517143"></a><a name="p1921105517143"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.5.1.2 "><p id="p162165512140"><a name="p162165512140"></a><a name="p162165512140"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.5.1.3 "><p id="p1121105511148"><a name="p1121105511148"></a><a name="p1121105511148"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="p1821165511411"><a name="p1821165511411"></a><a name="p1821165511411"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的光强值
    console.info(''Illumination: ' + data.intensity);
  }
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_ORIENTATION\)<a name="section794801295516"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_ORIENTATION, callback: AsyncCallback<OrientationResponse\>, options?: Options\): void

监听方向传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table113235517149"></a>
<table><thead align="left"><tr id="row1533185512141"><th class="cellrowborder" valign="top" width="11.28%" id="mcps1.1.5.1.1"><p id="p6331255181419"><a name="p6331255181419"></a><a name="p6331255181419"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="31.869999999999997%" id="mcps1.1.5.1.2"><p id="p11331855101418"><a name="p11331855101418"></a><a name="p11331855101418"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.01%" id="mcps1.1.5.1.3"><p id="p113414550142"><a name="p113414550142"></a><a name="p113414550142"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="50.839999999999996%" id="mcps1.1.5.1.4"><p id="p23425511416"><a name="p23425511416"></a><a name="p23425511416"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row13341955131416"><td class="cellrowborder" valign="top" width="11.28%" headers="mcps1.1.5.1.1 "><p id="p1534105541412"><a name="p1534105541412"></a><a name="p1534105541412"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="31.869999999999997%" headers="mcps1.1.5.1.2 "><p id="p83515581417"><a name="p83515581417"></a><a name="p83515581417"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.01%" headers="mcps1.1.5.1.3 "><p id="p63515559143"><a name="p63515559143"></a><a name="p63515559143"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="50.839999999999996%" headers="mcps1.1.5.1.4 "><p id="p1635105581410"><a name="p1635105581410"></a><a name="p1635105581410"></a>要订阅的方向传感器类型为SENSOR_TYPE_ID_ORIENTATION</p>
</td>
</tr>
<tr id="row9355558146"><td class="cellrowborder" valign="top" width="11.28%" headers="mcps1.1.5.1.1 "><p id="p1735175514148"><a name="p1735175514148"></a><a name="p1735175514148"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="31.869999999999997%" headers="mcps1.1.5.1.2 "><p id="p13351155101413"><a name="p13351155101413"></a><a name="p13351155101413"></a>AsyncCallback&lt;<a href="#section128271514456">OrientationResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.01%" headers="mcps1.1.5.1.3 "><p id="p133595501413"><a name="p133595501413"></a><a name="p133595501413"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="50.839999999999996%" headers="mcps1.1.5.1.4 "><p id="p236205551414"><a name="p236205551414"></a><a name="p236205551414"></a>注册方向传感器的回调函数，上报的数据类型为OrientationResponse。</p>
</td>
</tr>
<tr id="row10361655151410"><td class="cellrowborder" valign="top" width="11.28%" headers="mcps1.1.5.1.1 "><p id="p1336115518144"><a name="p1336115518144"></a><a name="p1336115518144"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="31.869999999999997%" headers="mcps1.1.5.1.2 "><p id="p173645521419"><a name="p173645521419"></a><a name="p173645521419"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="6.01%" headers="mcps1.1.5.1.3 "><p id="p336165571416"><a name="p336165571416"></a><a name="p336165571416"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="50.839999999999996%" headers="mcps1.1.5.1.4 "><p id="p123635531419"><a name="p123635531419"></a><a name="p123635531419"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
  }
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_ROTATION\_VECTOR\)<a name="section4764201154"></a>

on\(type:SensorType.SENSOR\_TYPE\_ID\_ROTATION\_VECTOR,callback:AsyncCallback<RotationVectorResponse\>,options?: Options\): void

监听旋转矢量传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table37650016158"></a>
<table><thead align="left"><tr id="row176515012159"><th class="cellrowborder" valign="top" width="10.290000000000001%" id="mcps1.1.5.1.1"><p id="p147661204159"><a name="p147661204159"></a><a name="p147661204159"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="34.55%" id="mcps1.1.5.1.2"><p id="p18766502156"><a name="p18766502156"></a><a name="p18766502156"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.5600000000000005%" id="mcps1.1.5.1.3"><p id="p7767305150"><a name="p7767305150"></a><a name="p7767305150"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="48.6%" id="mcps1.1.5.1.4"><p id="p876720171510"><a name="p876720171510"></a><a name="p876720171510"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row97671100151"><td class="cellrowborder" valign="top" width="10.290000000000001%" headers="mcps1.1.5.1.1 "><p id="p10767508155"><a name="p10767508155"></a><a name="p10767508155"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="34.55%" headers="mcps1.1.5.1.2 "><p id="p1976815031519"><a name="p1976815031519"></a><a name="p1976815031519"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.5600000000000005%" headers="mcps1.1.5.1.3 "><p id="p676810001511"><a name="p676810001511"></a><a name="p676810001511"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.6%" headers="mcps1.1.5.1.4 "><p id="p117681101158"><a name="p117681101158"></a><a name="p117681101158"></a>要订阅的旋转矢量传感器类型为SENSOR_TYPE_ID_ROTATION_VECTOR。</p>
</td>
</tr>
<tr id="row67688016150"><td class="cellrowborder" valign="top" width="10.290000000000001%" headers="mcps1.1.5.1.1 "><p id="p1076813051518"><a name="p1076813051518"></a><a name="p1076813051518"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="34.55%" headers="mcps1.1.5.1.2 "><p id="p376819051510"><a name="p376819051510"></a><a name="p376819051510"></a>AsyncCallback&lt;<a href="#section13776194114611">RotationVectorResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.5600000000000005%" headers="mcps1.1.5.1.3 "><p id="p0769602150"><a name="p0769602150"></a><a name="p0769602150"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.6%" headers="mcps1.1.5.1.4 "><p id="p127696015154"><a name="p127696015154"></a><a name="p127696015154"></a>注册旋转矢量传感器的回调函数，上报的数据类型为RotationVectorResponse。</p>
</td>
</tr>
<tr id="row776950131510"><td class="cellrowborder" valign="top" width="10.290000000000001%" headers="mcps1.1.5.1.1 "><p id="p1576912041513"><a name="p1576912041513"></a><a name="p1576912041513"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="34.55%" headers="mcps1.1.5.1.2 "><p id="p12769110111513"><a name="p12769110111513"></a><a name="p12769110111513"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="6.5600000000000005%" headers="mcps1.1.5.1.3 "><p id="p4769100101514"><a name="p4769100101514"></a><a name="p4769100101514"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="48.6%" headers="mcps1.1.5.1.4 "><p id="p5769108157"><a name="p5769108157"></a><a name="p5769108157"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
  }
  {interval: 10000000}
);
```

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_WEAR\_DETECTION\)<a name="section9776110101518"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_WEAR\_DETECTION, callback: AsyncCallback<WearDetectionResponse\>,options?: Options\): void

监听佩戴检测传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**参数：**

<a name="table577650191511"></a>
<table><thead align="left"><tr id="row17777140171516"><th class="cellrowborder" valign="top" width="10.290000000000001%" id="mcps1.1.5.1.1"><p id="p197771901151"><a name="p197771901151"></a><a name="p197771901151"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="35.21%" id="mcps1.1.5.1.2"><p id="p15777102155"><a name="p15777102155"></a><a name="p15777102155"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.529999999999999%" id="mcps1.1.5.1.3"><p id="p1677720101519"><a name="p1677720101519"></a><a name="p1677720101519"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="47.97%" id="mcps1.1.5.1.4"><p id="p18777507152"><a name="p18777507152"></a><a name="p18777507152"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1477716011153"><td class="cellrowborder" valign="top" width="10.290000000000001%" headers="mcps1.1.5.1.1 "><p id="p117771705158"><a name="p117771705158"></a><a name="p117771705158"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="35.21%" headers="mcps1.1.5.1.2 "><p id="p17778160121515"><a name="p17778160121515"></a><a name="p17778160121515"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.529999999999999%" headers="mcps1.1.5.1.3 "><p id="p10778103152"><a name="p10778103152"></a><a name="p10778103152"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="47.97%" headers="mcps1.1.5.1.4 "><p id="p18778605151"><a name="p18778605151"></a><a name="p18778605151"></a>要订阅的佩戴检测传感器类型为SENSOR_TYPE_ID_WEAR_DETECTION。</p>
</td>
</tr>
<tr id="row1777819011154"><td class="cellrowborder" valign="top" width="10.290000000000001%" headers="mcps1.1.5.1.1 "><p id="p47781109152"><a name="p47781109152"></a><a name="p47781109152"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="35.21%" headers="mcps1.1.5.1.2 "><p id="p17778120171512"><a name="p17778120171512"></a><a name="p17778120171512"></a>AsyncCallback&lt;<a href="#section128278501495">WearDetectionResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.529999999999999%" headers="mcps1.1.5.1.3 "><p id="p18778100141516"><a name="p18778100141516"></a><a name="p18778100141516"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="47.97%" headers="mcps1.1.5.1.4 "><p id="p877916017151"><a name="p877916017151"></a><a name="p877916017151"></a>注册佩戴检测传感器的回调函数，上报的数据类型为WearDetectionResponse。</p>
</td>
</tr>
<tr id="row12779603155"><td class="cellrowborder" valign="top" width="10.290000000000001%" headers="mcps1.1.5.1.1 "><p id="p1677916013157"><a name="p1677916013157"></a><a name="p1677916013157"></a>Options</p>
</td>
<td class="cellrowborder" valign="top" width="35.21%" headers="mcps1.1.5.1.2 "><p id="p5779808151"><a name="p5779808151"></a><a name="p5779808151"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="6.529999999999999%" headers="mcps1.1.5.1.3 "><p id="p27791409150"><a name="p27791409150"></a><a name="p27791409150"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.97%" headers="mcps1.1.5.1.4 "><p id="p107791806151"><a name="p107791806151"></a><a name="p107791806151"></a>可选参数列表，设置上报频率，默认值为200000000ns。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的佩戴状态
    console.info('Wear status: ' + data.value);
  }
  {interval: 10000000}
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_ACCELEROMETER\)<a name="section19783707153"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_ACCELEROMETER, callback: AsyncCallback<AccelerometerResponse\>\): void

监听加速度传感器的数据变化一次。

**参数：**

<a name="table278390181519"></a>
<table><thead align="left"><tr id="row16783160171512"><th class="cellrowborder" valign="top" width="10.12%" id="mcps1.1.5.1.1"><p id="p19784180171514"><a name="p19784180171514"></a><a name="p19784180171514"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="34.589999999999996%" id="mcps1.1.5.1.2"><p id="p1278419031515"><a name="p1278419031515"></a><a name="p1278419031515"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.17%" id="mcps1.1.5.1.3"><p id="p87846081516"><a name="p87846081516"></a><a name="p87846081516"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.120000000000005%" id="mcps1.1.5.1.4"><p id="p1478460201515"><a name="p1478460201515"></a><a name="p1478460201515"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row18784160101515"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p197851100155"><a name="p197851100155"></a><a name="p197851100155"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="34.589999999999996%" headers="mcps1.1.5.1.2 "><p id="p1178510121515"><a name="p1178510121515"></a><a name="p1178510121515"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.17%" headers="mcps1.1.5.1.3 "><p id="p19785308153"><a name="p19785308153"></a><a name="p19785308153"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.120000000000005%" headers="mcps1.1.5.1.4 "><p id="p4785204158"><a name="p4785204158"></a><a name="p4785204158"></a>加速度传感器类型为SENSOR_TYPE_ID_ACCELEROMETER。</p>
</td>
</tr>
<tr id="row778512041510"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p87861207153"><a name="p87861207153"></a><a name="p87861207153"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="34.589999999999996%" headers="mcps1.1.5.1.2 "><p id="p19786702150"><a name="p19786702150"></a><a name="p19786702150"></a>AsyncCallback&lt;<a href="#section965820576618">AccelerometerResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.17%" headers="mcps1.1.5.1.3 "><p id="p18786807158"><a name="p18786807158"></a><a name="p18786807158"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.120000000000005%" headers="mcps1.1.5.1.4 "><p id="p7786190141511"><a name="p7786190141511"></a><a name="p7786190141511"></a>注册一次加速度传感器的回调函数，上报的数据类型为AccelerometerResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_LINEAR\_ACCELERATION\)<a name="section18010433133"></a>

once\(type:SensorType.SENSOR\_TYPE\_ID\_LINEAR\_ACCELERATION,callback:AsyncCallback<LinearAccelerometerResponse\>\): void

监听线性加速度传感器数据变化一次。

**参数：**

<a name="table1111430136"></a>
<table><thead align="left"><tr id="row6294311318"><th class="cellrowborder" valign="top" width="9.04%" id="mcps1.1.5.1.1"><p id="p63124315137"><a name="p63124315137"></a><a name="p63124315137"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="38.940000000000005%" id="mcps1.1.5.1.2"><p id="p193104301316"><a name="p193104301316"></a><a name="p193104301316"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.36%" id="mcps1.1.5.1.3"><p id="p65114371313"><a name="p65114371313"></a><a name="p65114371313"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="45.660000000000004%" id="mcps1.1.5.1.4"><p id="p651743181319"><a name="p651743181319"></a><a name="p651743181319"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row14534321316"><td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.1.5.1.1 "><p id="p1614351318"><a name="p1614351318"></a><a name="p1614351318"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="38.940000000000005%" headers="mcps1.1.5.1.2 "><p id="p961743171319"><a name="p961743171319"></a><a name="p961743171319"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.36%" headers="mcps1.1.5.1.3 "><p id="p97184318133"><a name="p97184318133"></a><a name="p97184318133"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="45.660000000000004%" headers="mcps1.1.5.1.4 "><p id="p7774351312"><a name="p7774351312"></a><a name="p7774351312"></a>线性加速度传感器类型为SENSOR_TYPE_ID_LINEAR_ACCELERATION。</p>
</td>
</tr>
<tr id="row17104318131"><td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.1.5.1.1 "><p id="p38154315133"><a name="p38154315133"></a><a name="p38154315133"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="38.940000000000005%" headers="mcps1.1.5.1.2 "><p id="p158443111317"><a name="p158443111317"></a><a name="p158443111317"></a>AsyncCallback&lt;<a href="#section1151477447">LinearAccelerometerResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.36%" headers="mcps1.1.5.1.3 "><p id="p128134315137"><a name="p128134315137"></a><a name="p128134315137"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="45.660000000000004%" headers="mcps1.1.5.1.4 "><p id="p19914319134"><a name="p19914319134"></a><a name="p19914319134"></a>注册一次线性加速度传感器的回调函数，上报的数据类型为LinearAccelerometerResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_ACCELEROMETER\_UNCALIBRATED\)<a name="section3897145813147"></a>

once\(type:SensorType.SENSOR\_TYPE\_ID\_ACCELEROMETER\_UNCALIBRATED,callback:AsyncCallback<AccelerometerUncalibratedResponse\>\): void

监听未校准加速度传感器的数据变化一次。

**参数：**

<a name="table16898358121414"></a>
<table><thead align="left"><tr id="row889995816147"><th class="cellrowborder" valign="top" width="8.32%" id="mcps1.1.5.1.1"><p id="p989919584148"><a name="p989919584148"></a><a name="p989919584148"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="45.269999999999996%" id="mcps1.1.5.1.2"><p id="p10900155811415"><a name="p10900155811415"></a><a name="p10900155811415"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="5.96%" id="mcps1.1.5.1.3"><p id="p89001580146"><a name="p89001580146"></a><a name="p89001580146"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.45%" id="mcps1.1.5.1.4"><p id="p209001585149"><a name="p209001585149"></a><a name="p209001585149"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row209011858141413"><td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.5.1.1 "><p id="p199011958161417"><a name="p199011958161417"></a><a name="p199011958161417"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="45.269999999999996%" headers="mcps1.1.5.1.2 "><p id="p9901458161410"><a name="p9901458161410"></a><a name="p9901458161410"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="5.96%" headers="mcps1.1.5.1.3 "><p id="p990211584149"><a name="p990211584149"></a><a name="p990211584149"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="40.45%" headers="mcps1.1.5.1.4 "><p id="p11902145821417"><a name="p11902145821417"></a><a name="p11902145821417"></a>未校准加速度传感器类型为SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED。</p>
</td>
</tr>
<tr id="row6902145815141"><td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.5.1.1 "><p id="p159031858121418"><a name="p159031858121418"></a><a name="p159031858121418"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="45.269999999999996%" headers="mcps1.1.5.1.2 "><p id="p1590395810147"><a name="p1590395810147"></a><a name="p1590395810147"></a>AsyncCallback&lt;<a href="#section253082316457">AccelerometerUncalibratedResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="5.96%" headers="mcps1.1.5.1.3 "><p id="p8904758121412"><a name="p8904758121412"></a><a name="p8904758121412"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="40.45%" headers="mcps1.1.5.1.4 "><p id="p4904125812149"><a name="p4904125812149"></a><a name="p4904125812149"></a>注册一次未校准加速度传感器的回调函数，上报的数据类型为AccelerometerUncalibratedResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
    //打印data的x,y,z轴坐标的偏移量
    console.info('X-coordinate bias: ' + data.biasX);
    console.info('Y-coordinate bias: ' + data.biasY);
    console.info('Z-coordinate bias: ' + data.biasZ);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_GRAVITY\)<a name="section79121058181416"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_GRAVITY, callback: AsyncCallback<GravityResponse\>\): void

监听重力传感器的数据变化一次。

**参数：**

<a name="table10915158181411"></a>
<table><thead align="left"><tr id="row11915105815143"><th class="cellrowborder" valign="top" width="10.38%" id="mcps1.1.5.1.1"><p id="p159166586145"><a name="p159166586145"></a><a name="p159166586145"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="31.619999999999997%" id="mcps1.1.5.1.2"><p id="p1491675841416"><a name="p1491675841416"></a><a name="p1491675841416"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.16%" id="mcps1.1.5.1.3"><p id="p1291614580146"><a name="p1291614580146"></a><a name="p1291614580146"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="50.839999999999996%" id="mcps1.1.5.1.4"><p id="p1191718580146"><a name="p1191718580146"></a><a name="p1191718580146"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row3917135881411"><td class="cellrowborder" valign="top" width="10.38%" headers="mcps1.1.5.1.1 "><p id="p0917145816140"><a name="p0917145816140"></a><a name="p0917145816140"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="31.619999999999997%" headers="mcps1.1.5.1.2 "><p id="p9917958151415"><a name="p9917958151415"></a><a name="p9917958151415"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.16%" headers="mcps1.1.5.1.3 "><p id="p179181058151415"><a name="p179181058151415"></a><a name="p179181058151415"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="50.839999999999996%" headers="mcps1.1.5.1.4 "><p id="p59181458181413"><a name="p59181458181413"></a><a name="p59181458181413"></a>重力传感器类型为SENSOR_TYPE_ID_GRAVITY。</p>
</td>
</tr>
<tr id="row1291835816148"><td class="cellrowborder" valign="top" width="10.38%" headers="mcps1.1.5.1.1 "><p id="p16919175831413"><a name="p16919175831413"></a><a name="p16919175831413"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="31.619999999999997%" headers="mcps1.1.5.1.2 "><p id="p0919858101412"><a name="p0919858101412"></a><a name="p0919858101412"></a>AsyncCallback&lt;<a href="#section162913399453">GravityResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.16%" headers="mcps1.1.5.1.3 "><p id="p991945817142"><a name="p991945817142"></a><a name="p991945817142"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="50.839999999999996%" headers="mcps1.1.5.1.4 "><p id="p8920205811145"><a name="p8920205811145"></a><a name="p8920205811145"></a>注册一次重力传感器的回调函数，上报的数据类型为GravityResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GRAVITY, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_GYROSCOPE\)<a name="section12419351519"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_GYROSCOPE, callback: AsyncCallback<GyroscopeResponse\>\): void

监听陀螺仪传感器的数据变化一次。

**参数：**

<a name="table17719316155"></a>
<table><thead align="left"><tr id="row18953161510"><th class="cellrowborder" valign="top" width="10.12%" id="mcps1.1.5.1.1"><p id="p1695311511"><a name="p1695311511"></a><a name="p1695311511"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="30.95%" id="mcps1.1.5.1.2"><p id="p29143111519"><a name="p29143111519"></a><a name="p29143111519"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.64%" id="mcps1.1.5.1.3"><p id="p15916310158"><a name="p15916310158"></a><a name="p15916310158"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="51.29%" id="mcps1.1.5.1.4"><p id="p31010371513"><a name="p31010371513"></a><a name="p31010371513"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row111083201510"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p41014318154"><a name="p41014318154"></a><a name="p41014318154"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="30.95%" headers="mcps1.1.5.1.2 "><p id="p8108319157"><a name="p8108319157"></a><a name="p8108319157"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.64%" headers="mcps1.1.5.1.3 "><p id="p7111038150"><a name="p7111038150"></a><a name="p7111038150"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="51.29%" headers="mcps1.1.5.1.4 "><p id="p611837155"><a name="p611837155"></a><a name="p611837155"></a>陀螺仪传感器类型为SENSOR_TYPE_ID_GYROSCOPE。</p>
</td>
</tr>
<tr id="row6111530152"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p141211314154"><a name="p141211314154"></a><a name="p141211314154"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="30.95%" headers="mcps1.1.5.1.2 "><p id="p612230156"><a name="p612230156"></a><a name="p612230156"></a>AsyncCallback&lt;<a href="#section3669131713463">GyroscopeResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.64%" headers="mcps1.1.5.1.3 "><p id="p16120351516"><a name="p16120351516"></a><a name="p16120351516"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="51.29%" headers="mcps1.1.5.1.4 "><p id="p712833154"><a name="p712833154"></a><a name="p712833154"></a>注册一次陀螺仪传感器的回调函数，上报的数据类型为GyroscopeResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_GYROSCOPE\_UNCALIBRATED\)<a name="section02033181520"></a>

once\(type:SensorType.SENSOR\_TYPE\_ID\_GYROSCOPE\_UNCALIBRATED,callback:AsyncCallback<GyroscopeUncalibratedResponse\>\): void

监听未校准陀螺仪传感器的数据变化一次。

**参数：**

<a name="table16216312154"></a>
<table><thead align="left"><tr id="row423173121510"><th class="cellrowborder" valign="top" width="9.76%" id="mcps1.1.5.1.1"><p id="p023113121513"><a name="p023113121513"></a><a name="p023113121513"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="41.05%" id="mcps1.1.5.1.2"><p id="p1924034159"><a name="p1924034159"></a><a name="p1924034159"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.829999999999999%" id="mcps1.1.5.1.3"><p id="p1024183161516"><a name="p1024183161516"></a><a name="p1024183161516"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="41.36%" id="mcps1.1.5.1.4"><p id="p152443161517"><a name="p152443161517"></a><a name="p152443161517"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row17255320151"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p92533201517"><a name="p92533201517"></a><a name="p92533201517"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="41.05%" headers="mcps1.1.5.1.2 "><p id="p1826033152"><a name="p1826033152"></a><a name="p1826033152"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.829999999999999%" headers="mcps1.1.5.1.3 "><p id="p92611315159"><a name="p92611315159"></a><a name="p92611315159"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="41.36%" headers="mcps1.1.5.1.4 "><p id="p16261732153"><a name="p16261732153"></a><a name="p16261732153"></a>未校准陀螺仪传感器类型为SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED。</p>
</td>
</tr>
<tr id="row18271934152"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p19286318157"><a name="p19286318157"></a><a name="p19286318157"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="41.05%" headers="mcps1.1.5.1.2 "><p id="p16288312154"><a name="p16288312154"></a><a name="p16288312154"></a>AsyncCallback&lt;<a href="#section1041541413475">GyroscopeUncalibratedResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.829999999999999%" headers="mcps1.1.5.1.3 "><p id="p4292316157"><a name="p4292316157"></a><a name="p4292316157"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="41.36%" headers="mcps1.1.5.1.4 "><p id="p17307320156"><a name="p17307320156"></a><a name="p17307320156"></a>注册一次未校准陀螺仪传感器的回调函数，上报的数据类型为GyroscopeUncalibratedResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
    //打印data的x,y,z轴坐标的偏移量
    console.info('X-coordinate bias: ' + data.biasX);
    console.info('Y-coordinate bias: ' + data.biasY);
    console.info('Z-coordinate bias: ' + data.biasZ);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_SIGNIFICANT\_MOTION\)<a name="section046513810156"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_SIGNIFICANT\_MOTION,callback:AsyncCallback<SignificantMotionResponse\>\): void

监听有效运动传感器的数据变化一次。

**参数：**

<a name="table18465787158"></a>
<table><thead align="left"><tr id="row1746678151511"><th class="cellrowborder" valign="top" width="9.13%" id="mcps1.1.5.1.1"><p id="p246710831510"><a name="p246710831510"></a><a name="p246710831510"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="38.72%" id="mcps1.1.5.1.2"><p id="p1746728101513"><a name="p1746728101513"></a><a name="p1746728101513"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.5600000000000005%" id="mcps1.1.5.1.3"><p id="p104671684153"><a name="p104671684153"></a><a name="p104671684153"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="44.59%" id="mcps1.1.5.1.4"><p id="p124681285152"><a name="p124681285152"></a><a name="p124681285152"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row646858191518"><td class="cellrowborder" valign="top" width="9.13%" headers="mcps1.1.5.1.1 "><p id="p546810815151"><a name="p546810815151"></a><a name="p546810815151"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="38.72%" headers="mcps1.1.5.1.2 "><p id="p154697818152"><a name="p154697818152"></a><a name="p154697818152"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.5600000000000005%" headers="mcps1.1.5.1.3 "><p id="p84696812154"><a name="p84696812154"></a><a name="p84696812154"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.59%" headers="mcps1.1.5.1.4 "><p id="p1847020818159"><a name="p1847020818159"></a><a name="p1847020818159"></a>有效运动传感器类型为SENSOR_TYPE_ID_SIGNIFICANT_MOTION。</p>
</td>
</tr>
<tr id="row11470168111516"><td class="cellrowborder" valign="top" width="9.13%" headers="mcps1.1.5.1.1 "><p id="p447038181517"><a name="p447038181517"></a><a name="p447038181517"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="38.72%" headers="mcps1.1.5.1.2 "><p id="p104701089150"><a name="p104701089150"></a><a name="p104701089150"></a>AsyncCallback&lt;<a href="#section1213143164712">SignificantMotionResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.5600000000000005%" headers="mcps1.1.5.1.3 "><p id="p1347168151518"><a name="p1347168151518"></a><a name="p1347168151518"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.59%" headers="mcps1.1.5.1.4 "><p id="p6471178161513"><a name="p6471178161513"></a><a name="p6471178161513"></a>注册一次有效运动传感器的回调函数，上报的数据类型为SignificantMotionResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    console.info('Scalar data: ' + data.scalar);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_PEDOMETER\_DETECTION\)<a name="section84801280158"></a>

once\(type:SensorType.SENSOR\_TYPE\_ID\_PEDOMETER\_DETECTION,callback:AsyncCallback<PedometerDetectResponse\>\): void

监听计步检测传感器数据变化一次。

**参数：**

<a name="table12481286156"></a>
<table><thead align="left"><tr id="row44828820158"><th class="cellrowborder" valign="top" width="8.95%" id="mcps1.1.5.1.1"><p id="p74823861512"><a name="p74823861512"></a><a name="p74823861512"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="40.1%" id="mcps1.1.5.1.2"><p id="p1548311811150"><a name="p1548311811150"></a><a name="p1548311811150"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.539999999999999%" id="mcps1.1.5.1.3"><p id="p2048318819151"><a name="p2048318819151"></a><a name="p2048318819151"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="43.41%" id="mcps1.1.5.1.4"><p id="p11483686152"><a name="p11483686152"></a><a name="p11483686152"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1048414881516"><td class="cellrowborder" valign="top" width="8.95%" headers="mcps1.1.5.1.1 "><p id="p6484178111514"><a name="p6484178111514"></a><a name="p6484178111514"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="40.1%" headers="mcps1.1.5.1.2 "><p id="p124841089154"><a name="p124841089154"></a><a name="p124841089154"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.539999999999999%" headers="mcps1.1.5.1.3 "><p id="p14841885157"><a name="p14841885157"></a><a name="p14841885157"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="43.41%" headers="mcps1.1.5.1.4 "><p id="p416856122717"><a name="p416856122717"></a><a name="p416856122717"></a>计步检测传感器类型为SENSOR_TYPE_ID_PEDOMETER_DETECTION。</p>
</td>
</tr>
<tr id="row8485118111514"><td class="cellrowborder" valign="top" width="8.95%" headers="mcps1.1.5.1.1 "><p id="p1548518821518"><a name="p1548518821518"></a><a name="p1548518821518"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="40.1%" headers="mcps1.1.5.1.2 "><p id="p64861787152"><a name="p64861787152"></a><a name="p64861787152"></a>AsyncCallback&lt;<a href="#section145653910491">PedometerDetectResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.539999999999999%" headers="mcps1.1.5.1.3 "><p id="p11486383155"><a name="p11486383155"></a><a name="p11486383155"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="43.41%" headers="mcps1.1.5.1.4 "><p id="p124875821518"><a name="p124875821518"></a><a name="p124875821518"></a>注册一次计步检测传感器的回调函数，上报的数据类型为PedometerDetectResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    console.info('Scalar data: ' + data.scalar);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_PEDOMETER\)<a name="section7781212101520"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_PEDOMETER, callback: AsyncCallback<PedometerResponse\>\): void

监听计步器传感器数据变化一次。

**参数：**

<a name="table1479121212154"></a>
<table><thead align="left"><tr id="row180412191515"><th class="cellrowborder" valign="top" width="11.1%" id="mcps1.1.5.1.1"><p id="p1080141201512"><a name="p1080141201512"></a><a name="p1080141201512"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="33.06%" id="mcps1.1.5.1.2"><p id="p1181151219154"><a name="p1181151219154"></a><a name="p1181151219154"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.22%" id="mcps1.1.5.1.3"><p id="p128161241515"><a name="p128161241515"></a><a name="p128161241515"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="48.620000000000005%" id="mcps1.1.5.1.4"><p id="p208141213156"><a name="p208141213156"></a><a name="p208141213156"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row682111271512"><td class="cellrowborder" valign="top" width="11.1%" headers="mcps1.1.5.1.1 "><p id="p68281218151"><a name="p68281218151"></a><a name="p68281218151"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="33.06%" headers="mcps1.1.5.1.2 "><p id="p484812191510"><a name="p484812191510"></a><a name="p484812191510"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.1.5.1.3 "><p id="p1585121241517"><a name="p1585121241517"></a><a name="p1585121241517"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.620000000000005%" headers="mcps1.1.5.1.4 "><p id="p1385712111515"><a name="p1385712111515"></a><a name="p1385712111515"></a>计步传感器类型为SENSOR_TYPE_ID_PEDOMETER。</p>
</td>
</tr>
<tr id="row148631212155"><td class="cellrowborder" valign="top" width="11.1%" headers="mcps1.1.5.1.1 "><p id="p1586141215158"><a name="p1586141215158"></a><a name="p1586141215158"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="33.06%" headers="mcps1.1.5.1.2 "><p id="p8875126157"><a name="p8875126157"></a><a name="p8875126157"></a>AsyncCallback&lt;<a href="#section1350145915489">PedometerResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.1.5.1.3 "><p id="p187912121518"><a name="p187912121518"></a><a name="p187912121518"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.620000000000005%" headers="mcps1.1.5.1.4 "><p id="p887812101512"><a name="p887812101512"></a><a name="p887812101512"></a>注册一次计步传感器的回调函数，上报的数据类型为PedometerResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的步数
    console.info('Steps: ' + data.steps);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_AMBIENT\_TEMPERATURE\)<a name="section1595121217155"></a>

once\(type:SensorType.SENSOR\_TYPE\_ID\_AMBIENT\_TEMPERATURE,callback:AsyncCallback<AmbientTemperatureResponse\>\): void

监听环境温度传感器数据变化一次。

**参数：**

<a name="table796812171520"></a>
<table><thead align="left"><tr id="row2992122157"><th class="cellrowborder" valign="top" width="9.31%" id="mcps1.1.5.1.1"><p id="p99951218154"><a name="p99951218154"></a><a name="p99951218154"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="38.75%" id="mcps1.1.5.1.2"><p id="p1110091215155"><a name="p1110091215155"></a><a name="p1110091215155"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.920000000000001%" id="mcps1.1.5.1.3"><p id="p13100191221511"><a name="p13100191221511"></a><a name="p13100191221511"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="44.019999999999996%" id="mcps1.1.5.1.4"><p id="p1610019121156"><a name="p1610019121156"></a><a name="p1610019121156"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row310021291512"><td class="cellrowborder" valign="top" width="9.31%" headers="mcps1.1.5.1.1 "><p id="p910171201519"><a name="p910171201519"></a><a name="p910171201519"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="38.75%" headers="mcps1.1.5.1.2 "><p id="p31011912111510"><a name="p31011912111510"></a><a name="p31011912111510"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.920000000000001%" headers="mcps1.1.5.1.3 "><p id="p1610131221519"><a name="p1610131221519"></a><a name="p1610131221519"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p1030401572915"><a name="p1030401572915"></a><a name="p1030401572915"></a>环境温度传感器类型为SENSOR_TYPE_ID_AMBIENT_TEMPERATURE。</p>
</td>
</tr>
<tr id="row18102161212152"><td class="cellrowborder" valign="top" width="9.31%" headers="mcps1.1.5.1.1 "><p id="p5102201215152"><a name="p5102201215152"></a><a name="p5102201215152"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="38.75%" headers="mcps1.1.5.1.2 "><p id="p15103112101514"><a name="p15103112101514"></a><a name="p15103112101514"></a>AsyncCallback&lt;<a href="#section728281924920">AmbientTemperatureResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.920000000000001%" headers="mcps1.1.5.1.3 "><p id="p121031412171514"><a name="p121031412171514"></a><a name="p121031412171514"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p41031112111516"><a name="p41031112111516"></a><a name="p41031112111516"></a>注册一次环境温度传感器的回调函数，上报的数据类型为AmbientTemperatureResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的温度值
    console.info('Temperature: ' + data.temperature);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_MAGNETIC\_FIELD\)<a name="section20209715181517"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_MAGNETIC\_FIELD, callback: AsyncCallback<MagneticFieldResponse\>\): void

监听磁场传感器数据变化一次。

**参数：**

<a name="table1421021511514"></a>
<table><thead align="left"><tr id="row202101615151512"><th class="cellrowborder" valign="top" width="9.49%" id="mcps1.1.5.1.1"><p id="p321116151154"><a name="p321116151154"></a><a name="p321116151154"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="34.300000000000004%" id="mcps1.1.5.1.2"><p id="p1021131571518"><a name="p1021131571518"></a><a name="p1021131571518"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.430000000000001%" id="mcps1.1.5.1.3"><p id="p5211715111517"><a name="p5211715111517"></a><a name="p5211715111517"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="48.78%" id="mcps1.1.5.1.4"><p id="p7212315121516"><a name="p7212315121516"></a><a name="p7212315121516"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1221221511513"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.5.1.1 "><p id="p621261510158"><a name="p621261510158"></a><a name="p621261510158"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.1.5.1.2 "><p id="p172125156157"><a name="p172125156157"></a><a name="p172125156157"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.430000000000001%" headers="mcps1.1.5.1.3 "><p id="p721211581511"><a name="p721211581511"></a><a name="p721211581511"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.78%" headers="mcps1.1.5.1.4 "><p id="p112131215201519"><a name="p112131215201519"></a><a name="p112131215201519"></a>磁场传感器类型为SENSOR_TYPE_ID_MAGNETIC_FIELD。</p>
</td>
</tr>
<tr id="row162133158154"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.5.1.1 "><p id="p521319157159"><a name="p521319157159"></a><a name="p521319157159"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.1.5.1.2 "><p id="p19214115191517"><a name="p19214115191517"></a><a name="p19214115191517"></a>AsyncCallback&lt;<a href="#section20218191813489">MagneticFieldResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.430000000000001%" headers="mcps1.1.5.1.3 "><p id="p8214131521511"><a name="p8214131521511"></a><a name="p8214131521511"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.78%" headers="mcps1.1.5.1.4 "><p id="p1721411511513"><a name="p1721411511513"></a><a name="p1721411511513"></a>注册一次磁场传感器的回调函数，上报的数据类型为MagneticFieldResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_MAGNETIC\_FIELD\_UNCALIBRATED\)<a name="section42211015191510"></a>

once\(type:SensorType.SENSOR\_TYPE\_ID\_MAGNETIC\_FIELD\_UNCALIBRATED,callback:AsyncCallback<MagneticFieldUncalibratedResponse\>\): void

监听未校准磁场传感器数据变化一次。

**参数：**

<a name="table1022151591516"></a>
<table><thead align="left"><tr id="row322201561511"><th class="cellrowborder" valign="top" width="9.76%" id="mcps1.1.5.1.1"><p id="p10222121513154"><a name="p10222121513154"></a><a name="p10222121513154"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="38.01%" id="mcps1.1.5.1.2"><p id="p1022311155152"><a name="p1022311155152"></a><a name="p1022311155152"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.950000000000001%" id="mcps1.1.5.1.3"><p id="p8223215161510"><a name="p8223215161510"></a><a name="p8223215161510"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="45.28%" id="mcps1.1.5.1.4"><p id="p15224131541510"><a name="p15224131541510"></a><a name="p15224131541510"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row13224215121515"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p1722571513150"><a name="p1722571513150"></a><a name="p1722571513150"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="38.01%" headers="mcps1.1.5.1.2 "><p id="p18225715121511"><a name="p18225715121511"></a><a name="p18225715121511"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.950000000000001%" headers="mcps1.1.5.1.3 "><p id="p1422516156153"><a name="p1422516156153"></a><a name="p1422516156153"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="45.28%" headers="mcps1.1.5.1.4 "><p id="p1226191513154"><a name="p1226191513154"></a><a name="p1226191513154"></a>未校准磁场传感器类型为SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED。</p>
</td>
</tr>
<tr id="row2226815181517"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p622741516151"><a name="p622741516151"></a><a name="p622741516151"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="38.01%" headers="mcps1.1.5.1.2 "><p id="p152277151154"><a name="p152277151154"></a><a name="p152277151154"></a>AsyncCallback&lt;<a href="#section13749143113486">MagneticFieldUncalibratedResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.950000000000001%" headers="mcps1.1.5.1.3 "><p id="p10227131581516"><a name="p10227131581516"></a><a name="p10227131581516"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="45.28%" headers="mcps1.1.5.1.4 "><p id="p722814154158"><a name="p722814154158"></a><a name="p722814154158"></a>注册一次未校准磁场传感器的回调函数，上报的数据类型为MagneticFieldUncalibratedResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
    //打印data的x,y,z轴坐标的偏移量
    console.info('X-coordinate bias: ' + data.biasX);
    console.info('Y-coordinate bias: ' + data.biasY);
    console.info('Z-coordinate bias: ' + data.biasZ);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_PROXIMITY\)<a name="section569171821513"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_PROXIMITY, callback: AsyncCallback<ProximityResponse\>\): void

监听接近光传感器数据变化一次。

**参数：**

<a name="table671418141510"></a>
<table><thead align="left"><tr id="row4721518121519"><th class="cellrowborder" valign="top" width="10.12%" id="mcps1.1.5.1.1"><p id="p17721118171512"><a name="p17721118171512"></a><a name="p17721118171512"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="32.57%" id="mcps1.1.5.1.2"><p id="p573191881517"><a name="p573191881517"></a><a name="p573191881517"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.2%" id="mcps1.1.5.1.3"><p id="p1673718181517"><a name="p1673718181517"></a><a name="p1673718181517"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="51.11%" id="mcps1.1.5.1.4"><p id="p3735189151"><a name="p3735189151"></a><a name="p3735189151"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row157321861517"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p13741518191511"><a name="p13741518191511"></a><a name="p13741518191511"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="32.57%" headers="mcps1.1.5.1.2 "><p id="p14743181152"><a name="p14743181152"></a><a name="p14743181152"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.2%" headers="mcps1.1.5.1.3 "><p id="p9741918111514"><a name="p9741918111514"></a><a name="p9741918111514"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="51.11%" headers="mcps1.1.5.1.4 "><p id="p117501821514"><a name="p117501821514"></a><a name="p117501821514"></a>接近光传感器类型为SENSOR_TYPE_ID_PROXIMITY。</p>
</td>
</tr>
<tr id="row1075201817152"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p1175101861515"><a name="p1175101861515"></a><a name="p1175101861515"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="32.57%" headers="mcps1.1.5.1.2 "><p id="p1375161818157"><a name="p1375161818157"></a><a name="p1375161818157"></a>AsyncCallback&lt;<a href="#section5275184313476">ProximityResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.2%" headers="mcps1.1.5.1.3 "><p id="p15752184150"><a name="p15752184150"></a><a name="p15752184150"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="51.11%" headers="mcps1.1.5.1.4 "><p id="p4761182152"><a name="p4761182152"></a><a name="p4761182152"></a>注册一次接近光传感器的回调函数，上报的数据类型为ProximityResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的距离值
    console.info('Distance: ' + data.distance);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_HUMIDITY\)<a name="section481181811512"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_HUMIDITY, callback: AsyncCallback<HumidityResponse\>\): void

监听湿度传感器数据变化一次。

**参数：**

<a name="table382131891512"></a>
<table><thead align="left"><tr id="row3841318121515"><th class="cellrowborder" valign="top" width="9.030000000000001%" id="mcps1.1.5.1.1"><p id="p148414185151"><a name="p148414185151"></a><a name="p148414185151"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="34.86%" id="mcps1.1.5.1.2"><p id="p13841718191514"><a name="p13841718191514"></a><a name="p13841718191514"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.79%" id="mcps1.1.5.1.3"><p id="p168513181152"><a name="p168513181152"></a><a name="p168513181152"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.32%" id="mcps1.1.5.1.4"><p id="p18851189151"><a name="p18851189151"></a><a name="p18851189151"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row19851618141517"><td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.5.1.1 "><p id="p148681810156"><a name="p148681810156"></a><a name="p148681810156"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="34.86%" headers="mcps1.1.5.1.2 "><p id="p158611871514"><a name="p158611871514"></a><a name="p158611871514"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.79%" headers="mcps1.1.5.1.3 "><p id="p118661811511"><a name="p118661811511"></a><a name="p118661811511"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.32%" headers="mcps1.1.5.1.4 "><p id="p086171881520"><a name="p086171881520"></a><a name="p086171881520"></a>湿度传感器类型为SENSOR_TYPE_ID_HUMIDITY。</p>
</td>
</tr>
<tr id="row887918111515"><td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.5.1.1 "><p id="p11876183153"><a name="p11876183153"></a><a name="p11876183153"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="34.86%" headers="mcps1.1.5.1.2 "><p id="p198715189153"><a name="p198715189153"></a><a name="p198715189153"></a>AsyncCallback&lt;<a href="#section20444511666">HumidityResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.79%" headers="mcps1.1.5.1.3 "><p id="p1487131818154"><a name="p1487131818154"></a><a name="p1487131818154"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.32%" headers="mcps1.1.5.1.4 "><p id="p188881821513"><a name="p188881821513"></a><a name="p188881821513"></a>注册一次湿度传感器的回调函数，上报的数据类型为HumidityResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的湿度值
    console.info('Humidity: ' + data.humidity);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_BAROMETER\)<a name="section178111120201520"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_BAROMETER, callback: AsyncCallback<BarometerResponse\>\): void

监听气压计传感器数据变化一次。

**参数：**

<a name="table10812152011516"></a>
<table><thead align="left"><tr id="row6813132091516"><th class="cellrowborder" valign="top" width="9.76%" id="mcps1.1.5.1.1"><p id="p1981319203152"><a name="p1981319203152"></a><a name="p1981319203152"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="34.13%" id="mcps1.1.5.1.2"><p id="p081392091514"><a name="p081392091514"></a><a name="p081392091514"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.07%" id="mcps1.1.5.1.3"><p id="p138161220161516"><a name="p138161220161516"></a><a name="p138161220161516"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.04%" id="mcps1.1.5.1.4"><p id="p1981642051515"><a name="p1981642051515"></a><a name="p1981642051515"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row17817172013154"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p10817820111515"><a name="p10817820111515"></a><a name="p10817820111515"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="34.13%" headers="mcps1.1.5.1.2 "><p id="p781712010154"><a name="p781712010154"></a><a name="p781712010154"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.07%" headers="mcps1.1.5.1.3 "><p id="p1681712091513"><a name="p1681712091513"></a><a name="p1681712091513"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.04%" headers="mcps1.1.5.1.4 "><p id="p5818172016159"><a name="p5818172016159"></a><a name="p5818172016159"></a>气压计传感器类型为SENSOR_TYPE_ID_BAROMETER。</p>
</td>
</tr>
<tr id="row281811206158"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p4818720131512"><a name="p4818720131512"></a><a name="p4818720131512"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="34.13%" headers="mcps1.1.5.1.2 "><p id="p3819220171519"><a name="p3819220171519"></a><a name="p3819220171519"></a>AsyncCallback&lt;<a href="#section143457303496">BarometerResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.07%" headers="mcps1.1.5.1.3 "><p id="p1819820141515"><a name="p1819820141515"></a><a name="p1819820141515"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.04%" headers="mcps1.1.5.1.4 "><p id="p2820162016154"><a name="p2820162016154"></a><a name="p2820162016154"></a>注册一次气压计传感器的回调函数，上报的数据类型为BarometerResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的压强值
    console.info('Atmospheric pressure: ' + data.pressure);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_HALL\)<a name="section6826920141517"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_HALL, callback:   AsyncCallback<HallResponse\>\): void

监听霍尔传感器数据变化一次。

**参数：**

<a name="table1982710203152"></a>
<table><thead align="left"><tr id="row1482812051514"><th class="cellrowborder" valign="top" width="9.49%" id="mcps1.1.5.1.1"><p id="p16828192021510"><a name="p16828192021510"></a><a name="p16828192021510"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="32.15%" id="mcps1.1.5.1.2"><p id="p382815200158"><a name="p382815200158"></a><a name="p382815200158"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.340000000000001%" id="mcps1.1.5.1.3"><p id="p6829142017154"><a name="p6829142017154"></a><a name="p6829142017154"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="51.019999999999996%" id="mcps1.1.5.1.4"><p id="p482913206152"><a name="p482913206152"></a><a name="p482913206152"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row382912021511"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.5.1.1 "><p id="p158301020111519"><a name="p158301020111519"></a><a name="p158301020111519"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="32.15%" headers="mcps1.1.5.1.2 "><p id="p18301420181517"><a name="p18301420181517"></a><a name="p18301420181517"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.340000000000001%" headers="mcps1.1.5.1.3 "><p id="p118301920191519"><a name="p118301920191519"></a><a name="p118301920191519"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="51.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p1683152011516"><a name="p1683152011516"></a><a name="p1683152011516"></a>霍尔传感器类型为SENSOR_TYPE_ID_HALL。</p>
</td>
</tr>
<tr id="row183172019157"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.5.1.1 "><p id="p0831112031517"><a name="p0831112031517"></a><a name="p0831112031517"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="32.15%" headers="mcps1.1.5.1.2 "><p id="p14831132061512"><a name="p14831132061512"></a><a name="p14831132061512"></a>AsyncCallback&lt;<a href="#section18608467487">HallResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.340000000000001%" headers="mcps1.1.5.1.3 "><p id="p78321520161513"><a name="p78321520161513"></a><a name="p78321520161513"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="51.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p683282018159"><a name="p683282018159"></a><a name="p683282018159"></a>注册一次霍尔传感器的回调函数，上报的数据类型为HallResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HALL, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的状态值
    console.info('Status: ' + data.status);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_AMBIENT\_LIGHT\)<a name="section449943418257"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_AMBIENT\_LIGHT, callback: AsyncCallback<LightResponse\>\): void

监听环境光传感器数据变化一次。

**参数：**

<a name="table6500934132512"></a>
<table><thead align="left"><tr id="row55011034132510"><th class="cellrowborder" valign="top" width="9.39%" id="mcps1.1.5.1.1"><p id="p5502934132515"><a name="p5502934132515"></a><a name="p5502934132515"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="35.449999999999996%" id="mcps1.1.5.1.2"><p id="p135022340256"><a name="p135022340256"></a><a name="p135022340256"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.64%" id="mcps1.1.5.1.3"><p id="p115041534162518"><a name="p115041534162518"></a><a name="p115041534162518"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="47.52%" id="mcps1.1.5.1.4"><p id="p7505153452519"><a name="p7505153452519"></a><a name="p7505153452519"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row15505234122513"><td class="cellrowborder" valign="top" width="9.39%" headers="mcps1.1.5.1.1 "><p id="p1150523472510"><a name="p1150523472510"></a><a name="p1150523472510"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="35.449999999999996%" headers="mcps1.1.5.1.2 "><p id="p16506203413253"><a name="p16506203413253"></a><a name="p16506203413253"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.64%" headers="mcps1.1.5.1.3 "><p id="p6506934112517"><a name="p6506934112517"></a><a name="p6506934112517"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="47.52%" headers="mcps1.1.5.1.4 "><p id="p1507173432518"><a name="p1507173432518"></a><a name="p1507173432518"></a>环境光传感器类型为SENSOR_TYPE_ID_AMBIENT_LIGHT。</p>
</td>
</tr>
<tr id="row150719349254"><td class="cellrowborder" valign="top" width="9.39%" headers="mcps1.1.5.1.1 "><p id="p150763472515"><a name="p150763472515"></a><a name="p150763472515"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="35.449999999999996%" headers="mcps1.1.5.1.2 "><p id="p1950843419252"><a name="p1950843419252"></a><a name="p1950843419252"></a>AsyncCallback&lt;<a href="#section195685404716">LightResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.64%" headers="mcps1.1.5.1.3 "><p id="p4508133418255"><a name="p4508133418255"></a><a name="p4508133418255"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="47.52%" headers="mcps1.1.5.1.4 "><p id="p16509203422511"><a name="p16509203422511"></a><a name="p16509203422511"></a>注册一次环境光传感器的回调函数，上报的数据类型为LightResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的光强值
    console.info(''Illumination: ' + data.intensity);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_ORIENTATION\)<a name="section438833732512"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_ORIENTATION, callback: AsyncCallback<OrientationResponse\>\): void

监听方向传感器数据变化一次。

**参数：**

<a name="table13890373254"></a>
<table><thead align="left"><tr id="row639073714252"><th class="cellrowborder" valign="top" width="9.94%" id="mcps1.1.5.1.1"><p id="p183916372257"><a name="p183916372257"></a><a name="p183916372257"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="34.300000000000004%" id="mcps1.1.5.1.2"><p id="p1139143710254"><a name="p1139143710254"></a><a name="p1139143710254"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.959999999999999%" id="mcps1.1.5.1.3"><p id="p1039173715251"><a name="p1039173715251"></a><a name="p1039173715251"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="46.800000000000004%" id="mcps1.1.5.1.4"><p id="p7392173717253"><a name="p7392173717253"></a><a name="p7392173717253"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row73921337152510"><td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.5.1.1 "><p id="p14393137192512"><a name="p14393137192512"></a><a name="p14393137192512"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.1.5.1.2 "><p id="p8393173792514"><a name="p8393173792514"></a><a name="p8393173792514"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.959999999999999%" headers="mcps1.1.5.1.3 "><p id="p1939493792520"><a name="p1939493792520"></a><a name="p1939493792520"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="46.800000000000004%" headers="mcps1.1.5.1.4 "><p id="p19476192814011"><a name="p19476192814011"></a><a name="p19476192814011"></a>方向传感器类型为SENSOR_TYPE_ID_ORIENTATION。</p>
</td>
</tr>
<tr id="row1239583782511"><td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.5.1.1 "><p id="p439543716250"><a name="p439543716250"></a><a name="p439543716250"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.1.5.1.2 "><p id="p19395137132520"><a name="p19395137132520"></a><a name="p19395137132520"></a>AsyncCallback&lt;<a href="#section128271514456">OrientationResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.959999999999999%" headers="mcps1.1.5.1.3 "><p id="p43951837102517"><a name="p43951837102517"></a><a name="p43951837102517"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="46.800000000000004%" headers="mcps1.1.5.1.4 "><p id="p133961037202515"><a name="p133961037202515"></a><a name="p133961037202515"></a>注册一次方向传感器的回调函数，上报的数据类型为OrientationResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_ROTATION\_VECTOR\)<a name="section25391940192520"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_ROTATION\_VECTOR, callback: AsyncCallback<RotationVectorResponse\>\): void

监听旋转矢量传感器数据变化一次。

**参数：**

<a name="table1854074062517"></a>
<table><thead align="left"><tr id="row195415403256"><th class="cellrowborder" valign="top" width="9.85%" id="mcps1.1.5.1.1"><p id="p9542040192519"><a name="p9542040192519"></a><a name="p9542040192519"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="38.629999999999995%" id="mcps1.1.5.1.2"><p id="p154234092512"><a name="p154234092512"></a><a name="p154234092512"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.85%" id="mcps1.1.5.1.3"><p id="p1054211407256"><a name="p1054211407256"></a><a name="p1054211407256"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="43.669999999999995%" id="mcps1.1.5.1.4"><p id="p754354014253"><a name="p754354014253"></a><a name="p754354014253"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1754310409250"><td class="cellrowborder" valign="top" width="9.85%" headers="mcps1.1.5.1.1 "><p id="p1543174052519"><a name="p1543174052519"></a><a name="p1543174052519"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="38.629999999999995%" headers="mcps1.1.5.1.2 "><p id="p1354484062511"><a name="p1354484062511"></a><a name="p1354484062511"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.5.1.3 "><p id="p1954419408253"><a name="p1954419408253"></a><a name="p1954419408253"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="43.669999999999995%" headers="mcps1.1.5.1.4 "><p id="p9544154016257"><a name="p9544154016257"></a><a name="p9544154016257"></a>旋转矢量传感器类型为SENSOR_TYPE_ID_ROTATION_VECTOR。</p>
</td>
</tr>
<tr id="row9544140192515"><td class="cellrowborder" valign="top" width="9.85%" headers="mcps1.1.5.1.1 "><p id="p13545154092515"><a name="p13545154092515"></a><a name="p13545154092515"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="38.629999999999995%" headers="mcps1.1.5.1.2 "><p id="p5545740122515"><a name="p5545740122515"></a><a name="p5545740122515"></a>AsyncCallback&lt;<a href="#section13776194114611">RotationVectorResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.5.1.3 "><p id="p175459408258"><a name="p175459408258"></a><a name="p175459408258"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="43.669999999999995%" headers="mcps1.1.5.1.4 "><p id="p1654694082511"><a name="p1654694082511"></a><a name="p1654694082511"></a>注册一次旋转矢量传感器的回调函数，上报的数据类型为RotationVectorResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的x,y,z轴坐标的分量
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_HEART\_RATE\)<a name="section1345034310258"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_HEART\_RATE, callback: AsyncCallback<HeartRateResponse\>\): void

监听心率传感器数据变化一次。

**参数：**

<a name="table11451154392517"></a>
<table><thead align="left"><tr id="row10452043112519"><th class="cellrowborder" valign="top" width="9.31%" id="mcps1.1.5.1.1"><p id="p12453143112514"><a name="p12453143112514"></a><a name="p12453143112514"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="32.690000000000005%" id="mcps1.1.5.1.2"><p id="p1545434332512"><a name="p1545434332512"></a><a name="p1545434332512"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.51%" id="mcps1.1.5.1.3"><p id="p19454184372515"><a name="p19454184372515"></a><a name="p19454184372515"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.49%" id="mcps1.1.5.1.4"><p id="p1945524312254"><a name="p1945524312254"></a><a name="p1945524312254"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row04566434251"><td class="cellrowborder" valign="top" width="9.31%" headers="mcps1.1.5.1.1 "><p id="p445674310252"><a name="p445674310252"></a><a name="p445674310252"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="32.690000000000005%" headers="mcps1.1.5.1.2 "><p id="p16457443172515"><a name="p16457443172515"></a><a name="p16457443172515"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.51%" headers="mcps1.1.5.1.3 "><p id="p64571543132515"><a name="p64571543132515"></a><a name="p64571543132515"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.49%" headers="mcps1.1.5.1.4 "><p id="p127118044310"><a name="p127118044310"></a><a name="p127118044310"></a>心率传感器类型为SENSOR_TYPE_ID_HEART_RATE。</p>
</td>
</tr>
<tr id="row144588439259"><td class="cellrowborder" valign="top" width="9.31%" headers="mcps1.1.5.1.1 "><p id="p445818437259"><a name="p445818437259"></a><a name="p445818437259"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="32.690000000000005%" headers="mcps1.1.5.1.2 "><p id="p8459043102518"><a name="p8459043102518"></a><a name="p8459043102518"></a>AsyncCallback&lt;<a href="#section95011341124915">HeartRateResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.51%" headers="mcps1.1.5.1.3 "><p id="p8459543122514"><a name="p8459543122514"></a><a name="p8459543122514"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.49%" headers="mcps1.1.5.1.4 "><p id="p13459144352515"><a name="p13459144352515"></a><a name="p13459144352515"></a>注册一次心率传感器的回调函数，上报的数据类型为HeartRateResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HEART_RATE, function(error, data) {
    if (error) {
        console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    //打印data的心率值
    console.info("Heart rate: " + data.heartRate);
  }
);
```

## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_WEAR\_DETECTION\)<a name="section2288135016254"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_WEAR\_DETECTION, callback: AsyncCallback<WearDetectionResponse\>\): void

监听佩戴检测传感器数据变化一次。

**参数：**

<a name="table10289165032512"></a>
<table><thead align="left"><tr id="row1129075062513"><th class="cellrowborder" valign="top" width="9.13%" id="mcps1.1.5.1.1"><p id="p6293155017256"><a name="p6293155017256"></a><a name="p6293155017256"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="38.22%" id="mcps1.1.5.1.2"><p id="p929310501252"><a name="p929310501252"></a><a name="p929310501252"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.61%" id="mcps1.1.5.1.3"><p id="p14294135042511"><a name="p14294135042511"></a><a name="p14294135042511"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="44.04%" id="mcps1.1.5.1.4"><p id="p829425042520"><a name="p829425042520"></a><a name="p829425042520"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row11294125018256"><td class="cellrowborder" valign="top" width="9.13%" headers="mcps1.1.5.1.1 "><p id="p11295145011259"><a name="p11295145011259"></a><a name="p11295145011259"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="38.22%" headers="mcps1.1.5.1.2 "><p id="p13295195010258"><a name="p13295195010258"></a><a name="p13295195010258"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.61%" headers="mcps1.1.5.1.3 "><p id="p2295145011256"><a name="p2295145011256"></a><a name="p2295145011256"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.04%" headers="mcps1.1.5.1.4 "><p id="p72961950142511"><a name="p72961950142511"></a><a name="p72961950142511"></a>佩戴检测传感器类型为SENSOR_TYPE_ID_WEAR_DETECTION。</p>
</td>
</tr>
<tr id="row729685092510"><td class="cellrowborder" valign="top" width="9.13%" headers="mcps1.1.5.1.1 "><p id="p229613502257"><a name="p229613502257"></a><a name="p229613502257"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="38.22%" headers="mcps1.1.5.1.2 "><p id="p92969502257"><a name="p92969502257"></a><a name="p92969502257"></a>AsyncCallback&lt;<a href="#section128278501495">WearDetectionResponse</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.61%" headers="mcps1.1.5.1.3 "><p id="p1029845016255"><a name="p1029845016255"></a><a name="p1029845016255"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.04%" headers="mcps1.1.5.1.4 "><p id="p6299150152519"><a name="p6299150152519"></a><a name="p6299150152519"></a>注册一次穿戴检测传感器的回调函数，上报的数据类型为WearDetectionResponse。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, function(error, data) {
    if (error) {
        console.error("Failed to register data, error code is" + error.code + ", message: " + error.message);
        return;
    }
    //打印data的佩戴状态
    console.info("Wear status: "+ data.value);
  }
);
```

## sensor.off<a name="section359005312519"></a>

off\(type: SensorType, callback?: AsyncCallback<void\>\): void

取消订阅传感器数据。

**参数：**

<a name="table9590753112516"></a>
<table><thead align="left"><tr id="row165911539252"><th class="cellrowborder" valign="top" width="12.19%" id="mcps1.1.5.1.1"><p id="p1592125310253"><a name="p1592125310253"></a><a name="p1592125310253"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="26.97%" id="mcps1.1.5.1.2"><p id="p13592175314250"><a name="p13592175314250"></a><a name="p13592175314250"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.68%" id="mcps1.1.5.1.3"><p id="p2592195316250"><a name="p2592195316250"></a><a name="p2592195316250"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.16%" id="mcps1.1.5.1.4"><p id="p13593195310251"><a name="p13593195310251"></a><a name="p13593195310251"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row4594145313255"><td class="cellrowborder" valign="top" width="12.19%" headers="mcps1.1.5.1.1 "><p id="p1359485313252"><a name="p1359485313252"></a><a name="p1359485313252"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="26.97%" headers="mcps1.1.5.1.2 "><p id="p6594653112513"><a name="p6594653112513"></a><a name="p6594653112513"></a><a href="#section02298004614">SensorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.5.1.3 "><p id="p75957536250"><a name="p75957536250"></a><a name="p75957536250"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.5.1.4 "><p id="p58564711371"><a name="p58564711371"></a><a name="p58564711371"></a>要取消订阅的传感器类型。</p>
</td>
</tr>
<tr id="row12596155302516"><td class="cellrowborder" valign="top" width="12.19%" headers="mcps1.1.5.1.1 "><p id="p4596175312514"><a name="p4596175312514"></a><a name="p4596175312514"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="26.97%" headers="mcps1.1.5.1.2 "><p id="p459895315257"><a name="p459895315257"></a><a name="p459895315257"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.5.1.3 "><p id="p7598155312518"><a name="p7598155312518"></a><a name="p7598155312518"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.5.1.4 "><p id="p5599135317251"><a name="p5599135317251"></a><a name="p5599135317251"></a>取消订阅的传感器的回调函数，表示接口调用是否成功。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER, function(error) {
    if (error) {
        console.error("Failed to unsubscribe from acceleration sensor data. Error code: " + error.code + "; message: " + error.message);
        return;
    }
    console.info("Succeeded in unsubscribing from acceleration sensor data.");
  }
);

```

## SensorType<a name="section02298004614"></a>

表示要订阅或取消订阅的传感器类型。

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="44.01%" id="mcps1.1.4.1.1"><p id="a3d0fc780cc904c1cbab7991251622f65"><a name="a3d0fc780cc904c1cbab7991251622f65"></a><a name="a3d0fc780cc904c1cbab7991251622f65"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="9.030000000000001%" id="mcps1.1.4.1.2"><p id="aace9cae4ba0d4939bfa048460f61c3c7"><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="46.96%" id="mcps1.1.4.1.3"><p id="afec895de33f94e3c87ee7acc20190a17"><a name="afec895de33f94e3c87ee7acc20190a17"></a><a name="afec895de33f94e3c87ee7acc20190a17"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row064618971411"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p136471951415"><a name="p136471951415"></a><a name="p136471951415"></a>SENSOR_TYPE_ID_ACCELEROMETER</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p1464711912145"><a name="p1464711912145"></a><a name="p1464711912145"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p5647196143"><a name="p5647196143"></a><a name="p5647196143"></a>加速度传感器。</p>
</td>
</tr>
<tr id="row8392113631410"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p133931836181416"><a name="p133931836181416"></a><a name="p133931836181416"></a>SENSOR_TYPE_ID_GYROSCOPE</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p11393123691420"><a name="p11393123691420"></a><a name="p11393123691420"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p15393193681419"><a name="p15393193681419"></a><a name="p15393193681419"></a>陀螺仪传感器。</p>
</td>
</tr>
<tr id="row162951728141419"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p7295202817141"><a name="p7295202817141"></a><a name="p7295202817141"></a>SENSOR_TYPE_ID_AMBIENT_LIGHT</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p132965287145"><a name="p132965287145"></a><a name="p132965287145"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p1929612812149"><a name="p1929612812149"></a><a name="p1929612812149"></a>环境光传感器。</p>
</td>
</tr>
<tr id="row106781231111417"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p1567893101419"><a name="p1567893101419"></a><a name="p1567893101419"></a>SENSOR_TYPE_ID_MAGNETIC_FIELD</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p967818319146"><a name="p967818319146"></a><a name="p967818319146"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p867814310146"><a name="p867814310146"></a><a name="p867814310146"></a>磁场传感器。</p>
</td>
</tr>
<tr id="row637811621412"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p3378316101413"><a name="p3378316101413"></a><a name="p3378316101413"></a>SENSOR_TYPE_ID_BAROMETER</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p14378316141412"><a name="p14378316141412"></a><a name="p14378316141412"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p437814165145"><a name="p437814165145"></a><a name="p437814165145"></a>气压计传感器。</p>
</td>
</tr>
<tr id="row75221141151414"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p16522541171410"><a name="p16522541171410"></a><a name="p16522541171410"></a>SENSOR_TYPE_ID_HALL</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p1252264131415"><a name="p1252264131415"></a><a name="p1252264131415"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p2052210412145"><a name="p2052210412145"></a><a name="p2052210412145"></a>霍尔传感器。</p>
</td>
</tr>
<tr id="row1971824111418"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p1597213247148"><a name="p1597213247148"></a><a name="p1597213247148"></a>SENSOR_TYPE_ID_PROXIMITY</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p097214243147"><a name="p097214243147"></a><a name="p097214243147"></a>12</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p9972724111413"><a name="p9972724111413"></a><a name="p9972724111413"></a>接近光传感器。</p>
</td>
</tr>
<tr id="row3110162111416"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p3111132117140"><a name="p3111132117140"></a><a name="p3111132117140"></a>SENSOR_TYPE_ID_HUMIDITY</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p8111162151412"><a name="p8111162151412"></a><a name="p8111162151412"></a>13</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p181111821111415"><a name="p181111821111415"></a><a name="p181111821111415"></a>湿度传感器。</p>
</td>
</tr>
<tr id="row193052617161"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p2031152615166"><a name="p2031152615166"></a><a name="p2031152615166"></a>SENSOR_TYPE_ID_ORIENTATION</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p031142619162"><a name="p031142619162"></a><a name="p031142619162"></a>256</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p73112651616"><a name="p73112651616"></a><a name="p73112651616"></a>方向传感器。</p>
</td>
</tr>
<tr id="row168151840191617"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p118151640201616"><a name="p118151640201616"></a><a name="p118151640201616"></a>SENSOR_TYPE_ID_GRAVITY</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p98161540121614"><a name="p98161540121614"></a><a name="p98161540121614"></a>257</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p12816164021620"><a name="p12816164021620"></a><a name="p12816164021620"></a>重力传感器。</p>
</td>
</tr>
<tr id="row2070783741615"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p8707163781612"><a name="p8707163781612"></a><a name="p8707163781612"></a>SENSOR_TYPE_ID_LINEAR_ACCELERATION</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p207071337121611"><a name="p207071337121611"></a><a name="p207071337121611"></a>258</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p570713771613"><a name="p570713771613"></a><a name="p570713771613"></a>线性加速度传感器。</p>
</td>
</tr>
<tr id="row090719290166"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p199071629161617"><a name="p199071629161617"></a><a name="p199071629161617"></a>SENSOR_TYPE_ID_ROTATION_VECTOR</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p109071529141617"><a name="p109071529141617"></a><a name="p109071529141617"></a>259</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p8907729111618"><a name="p8907729111618"></a><a name="p8907729111618"></a>旋转矢量传感器。</p>
</td>
</tr>
<tr id="row1288811329164"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p4888143271613"><a name="p4888143271613"></a><a name="p4888143271613"></a>SENSOR_TYPE_ID_AMBIENT_TEMPERATURE</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p1488913231613"><a name="p1488913231613"></a><a name="p1488913231613"></a>260</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p1188953211163"><a name="p1188953211163"></a><a name="p1188953211163"></a>环境温度传感器。</p>
</td>
</tr>
<tr id="row18979121141613"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p897992110164"><a name="p897992110164"></a><a name="p897992110164"></a>SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p997922111160"><a name="p997922111160"></a><a name="p997922111160"></a>261</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p1998082121616"><a name="p1998082121616"></a><a name="p1998082121616"></a>未校准磁场传感器。</p>
</td>
</tr>
<tr id="row1916017051816"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p11603018184"><a name="p11603018184"></a><a name="p11603018184"></a>SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p416012016182"><a name="p416012016182"></a><a name="p416012016182"></a>263</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p1716015091819"><a name="p1716015091819"></a><a name="p1716015091819"></a>未校准陀螺仪传感器。</p>
</td>
</tr>
<tr id="row1498016881817"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p20980118171818"><a name="p20980118171818"></a><a name="p20980118171818"></a>SENSOR_TYPE_ID_SIGNIFICANT_MOTION</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p49801082181"><a name="p49801082181"></a><a name="p49801082181"></a>264</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p698112810187"><a name="p698112810187"></a><a name="p698112810187"></a>有效运动传感器。</p>
</td>
</tr>
<tr id="row844712141815"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p745812131817"><a name="p745812131817"></a><a name="p745812131817"></a>SENSOR_TYPE_ID_PEDOMETER_DETECTION</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p34571210188"><a name="p34571210188"></a><a name="p34571210188"></a>265</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p64516125181"><a name="p64516125181"></a><a name="p64516125181"></a>计步检测传感器。</p>
</td>
</tr>
<tr id="row34989517184"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p34986510181"><a name="p34986510181"></a><a name="p34986510181"></a>SENSOR_TYPE_ID_PEDOMETER</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p14989512183"><a name="p14989512183"></a><a name="p14989512183"></a>266</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p249875161814"><a name="p249875161814"></a><a name="p249875161814"></a>计步传感器。</p>
</td>
</tr>
<tr id="row21931456151818"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p3193356161813"><a name="p3193356161813"></a><a name="p3193356161813"></a>SENSOR_TYPE_ID_HEART_RATE</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p9193115613181"><a name="p9193115613181"></a><a name="p9193115613181"></a>278</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p101935569185"><a name="p101935569185"></a><a name="p101935569185"></a>心率传感器。</p>
</td>
</tr>
<tr id="row199353526181"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p493517526185"><a name="p493517526185"></a><a name="p493517526185"></a>SENSOR_TYPE_ID_WEAR_DETECTION</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p209351852111814"><a name="p209351852111814"></a><a name="p209351852111814"></a>280</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p593520524181"><a name="p593520524181"></a><a name="p593520524181"></a>佩戴检测传感器。</p>
</td>
</tr>
<tr id="row1059723319196"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p259893318199"><a name="p259893318199"></a><a name="p259893318199"></a>SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p1059853351915"><a name="p1059853351915"></a><a name="p1059853351915"></a>281</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p159810334197"><a name="p159810334197"></a><a name="p159810334197"></a>未校准加速度计传感器。</p>
</td>
</tr>
</tbody>
</table>

## AccelerometerResponse<a name="section965820576618"></a>

加速度传感器数据。

<a name="table1459620431636"></a>
<table><thead align="left"><tr id="row25971143435"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p1559716434320"><a name="p1559716434320"></a><a name="p1559716434320"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p3597743539"><a name="p3597743539"></a><a name="p3597743539"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p15971343131"><a name="p15971343131"></a><a name="p15971343131"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1459715436311"><a name="p1459715436311"></a><a name="p1459715436311"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p75975439316"><a name="p75975439316"></a><a name="p75975439316"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row15385227276"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p1738112213273"><a name="p1738112213273"></a><a name="p1738112213273"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p23862218272"><a name="p23862218272"></a><a name="p23862218272"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p53932216277"><a name="p53932216277"></a><a name="p53932216277"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p33922216274"><a name="p33922216274"></a><a name="p33922216274"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1739192217279"><a name="p1739192217279"></a><a name="p1739192217279"></a>x轴坐标分量。</p>
</td>
</tr>
<tr id="row118521130192720"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p128521830162718"><a name="p128521830162718"></a><a name="p128521830162718"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1853193014272"><a name="p1853193014272"></a><a name="p1853193014272"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p148537305275"><a name="p148537305275"></a><a name="p148537305275"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p385373092713"><a name="p385373092713"></a><a name="p385373092713"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1785383092711"><a name="p1785383092711"></a><a name="p1785383092711"></a>y轴坐标分量。</p>
</td>
</tr>
<tr id="row18838162692714"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p68391326202713"><a name="p68391326202713"></a><a name="p68391326202713"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p18839182632712"><a name="p18839182632712"></a><a name="p18839182632712"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p9839112622714"><a name="p9839112622714"></a><a name="p9839112622714"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p12839172620273"><a name="p12839172620273"></a><a name="p12839172620273"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p7839826112711"><a name="p7839826112711"></a><a name="p7839826112711"></a>z轴坐标分量。</p>
</td>
</tr>
</tbody>
</table>

## LinearAccelerometerResponse<a name="section1151477447"></a>

线性加速度传感器数据。

<a name="table99069363387"></a>
<table><thead align="left"><tr id="row1990711362388"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p990873633810"><a name="p990873633810"></a><a name="p990873633810"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p12908836193815"><a name="p12908836193815"></a><a name="p12908836193815"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p49091436193816"><a name="p49091436193816"></a><a name="p49091436193816"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1990911361383"><a name="p1990911361383"></a><a name="p1990911361383"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p179101436193815"><a name="p179101436193815"></a><a name="p179101436193815"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row991083683819"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p59117367383"><a name="p59117367383"></a><a name="p59117367383"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p391143617382"><a name="p391143617382"></a><a name="p391143617382"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p169111936153810"><a name="p169111936153810"></a><a name="p169111936153810"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1691233633818"><a name="p1691233633818"></a><a name="p1691233633818"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p11912103617383"><a name="p11912103617383"></a><a name="p11912103617383"></a>x轴坐标分量。</p>
</td>
</tr>
<tr id="row29131936123819"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p291333615386"><a name="p291333615386"></a><a name="p291333615386"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p891318369387"><a name="p891318369387"></a><a name="p891318369387"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p10914113619386"><a name="p10914113619386"></a><a name="p10914113619386"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p69141136143812"><a name="p69141136143812"></a><a name="p69141136143812"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p59141136163810"><a name="p59141136163810"></a><a name="p59141136163810"></a>y轴坐标分量。</p>
</td>
</tr>
<tr id="row18915123683818"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p1291543614384"><a name="p1291543614384"></a><a name="p1291543614384"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p11915036143816"><a name="p11915036143816"></a><a name="p11915036143816"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p14917143653811"><a name="p14917143653811"></a><a name="p14917143653811"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1391713366382"><a name="p1391713366382"></a><a name="p1391713366382"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p18918036123816"><a name="p18918036123816"></a><a name="p18918036123816"></a>z轴坐标分量。</p>
</td>
</tr>
</tbody>
</table>

## AccelerometerUncalibratedResponse<a name="section253082316457"></a>

未校准加速度计传感器数据。

<a name="table166899304014"></a>
<table><thead align="left"><tr id="row8696133194017"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p166962334015"><a name="p166962334015"></a><a name="p166962334015"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p1669718317405"><a name="p1669718317405"></a><a name="p1669718317405"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p369713314011"><a name="p369713314011"></a><a name="p369713314011"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p36981034405"><a name="p36981034405"></a><a name="p36981034405"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p15698632407"><a name="p15698632407"></a><a name="p15698632407"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1269810316406"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p7699113144011"><a name="p7699113144011"></a><a name="p7699113144011"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1070043114017"><a name="p1070043114017"></a><a name="p1070043114017"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p470123164018"><a name="p470123164018"></a><a name="p470123164018"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p18702133104020"><a name="p18702133104020"></a><a name="p18702133104020"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p16702132409"><a name="p16702132409"></a><a name="p16702132409"></a>x轴坐标分量。</p>
</td>
</tr>
<tr id="row87038315401"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p870313384011"><a name="p870313384011"></a><a name="p870313384011"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1670316318407"><a name="p1670316318407"></a><a name="p1670316318407"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p67041931400"><a name="p67041931400"></a><a name="p67041931400"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p17704163134013"><a name="p17704163134013"></a><a name="p17704163134013"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1870543144016"><a name="p1870543144016"></a><a name="p1870543144016"></a>y轴坐标分量。</p>
</td>
</tr>
<tr id="row177051433405"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p207054354014"><a name="p207054354014"></a><a name="p207054354014"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p970513354010"><a name="p970513354010"></a><a name="p970513354010"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p3706939401"><a name="p3706939401"></a><a name="p3706939401"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p177062314406"><a name="p177062314406"></a><a name="p177062314406"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p16707432406"><a name="p16707432406"></a><a name="p16707432406"></a>z轴坐标分量。</p>
</td>
</tr>
<tr id="row14176111210404"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p1117620129404"><a name="p1117620129404"></a><a name="p1117620129404"></a>biasX</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p6176812124016"><a name="p6176812124016"></a><a name="p6176812124016"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p1517761220402"><a name="p1517761220402"></a><a name="p1517761220402"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p16177131214010"><a name="p16177131214010"></a><a name="p16177131214010"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1617721210403"><a name="p1617721210403"></a><a name="p1617721210403"></a>x轴坐标偏移量。</p>
</td>
</tr>
<tr id="row538415193407"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p83852019194011"><a name="p83852019194011"></a><a name="p83852019194011"></a>biasY</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p133851519154015"><a name="p133851519154015"></a><a name="p133851519154015"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p153851819184014"><a name="p153851819184014"></a><a name="p153851819184014"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p738571916407"><a name="p738571916407"></a><a name="p738571916407"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p163861319124014"><a name="p163861319124014"></a><a name="p163861319124014"></a>y轴坐标偏移量。</p>
</td>
</tr>
<tr id="row197261815104013"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p117261515154018"><a name="p117261515154018"></a><a name="p117261515154018"></a>biasZ</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p167271115114018"><a name="p167271115114018"></a><a name="p167271115114018"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p137271215154015"><a name="p137271215154015"></a><a name="p137271215154015"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p10727215124012"><a name="p10727215124012"></a><a name="p10727215124012"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p072721512406"><a name="p072721512406"></a><a name="p072721512406"></a>z轴坐标偏移量。</p>
</td>
</tr>
</tbody>
</table>

## GravityResponse<a name="section162913399453"></a>

重力传感器数据。

<a name="table84391131164311"></a>
<table><thead align="left"><tr id="row16441831154317"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p1244153112439"><a name="p1244153112439"></a><a name="p1244153112439"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p2441331144316"><a name="p2441331144316"></a><a name="p2441331144316"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p144219312435"><a name="p144219312435"></a><a name="p144219312435"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1744243134319"><a name="p1744243134319"></a><a name="p1744243134319"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p15443113111432"><a name="p15443113111432"></a><a name="p15443113111432"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row184431831154312"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p64449312431"><a name="p64449312431"></a><a name="p64449312431"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p204441131174318"><a name="p204441131174318"></a><a name="p204441131174318"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p144515312431"><a name="p144515312431"></a><a name="p144515312431"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p04452315433"><a name="p04452315433"></a><a name="p04452315433"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p11446431114315"><a name="p11446431114315"></a><a name="p11446431114315"></a>x轴坐标分量。</p>
</td>
</tr>
<tr id="row844618311437"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p144463319438"><a name="p144463319438"></a><a name="p144463319438"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1344623118439"><a name="p1344623118439"></a><a name="p1344623118439"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p1447173134315"><a name="p1447173134315"></a><a name="p1447173134315"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p54472313438"><a name="p54472313438"></a><a name="p54472313438"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p134481731194311"><a name="p134481731194311"></a><a name="p134481731194311"></a>y轴坐标分量。</p>
</td>
</tr>
<tr id="row54481831114316"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p1448163119437"><a name="p1448163119437"></a><a name="p1448163119437"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p94491631134315"><a name="p94491631134315"></a><a name="p94491631134315"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p134496314439"><a name="p134496314439"></a><a name="p134496314439"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p174491231164313"><a name="p174491231164313"></a><a name="p174491231164313"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p2450531104319"><a name="p2450531104319"></a><a name="p2450531104319"></a>z轴坐标分量。</p>
</td>
</tr>
</tbody>
</table>

## OrientationResponse<a name="section128271514456"></a>

方向传感器数据。

<a name="table1897717534447"></a>
<table><thead align="left"><tr id="row1297895311441"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p1597818531448"><a name="p1597818531448"></a><a name="p1597818531448"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p2979145314410"><a name="p2979145314410"></a><a name="p2979145314410"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p9979253134417"><a name="p9979253134417"></a><a name="p9979253134417"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1297975324410"><a name="p1297975324410"></a><a name="p1297975324410"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p3980653194420"><a name="p3980653194420"></a><a name="p3980653194420"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row698015533445"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p1598155314411"><a name="p1598155314411"></a><a name="p1598155314411"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p11981653144411"><a name="p11981653144411"></a><a name="p11981653144411"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p169822053164420"><a name="p169822053164420"></a><a name="p169822053164420"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p198218531448"><a name="p198218531448"></a><a name="p198218531448"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p199831253144413"><a name="p199831253144413"></a><a name="p199831253144413"></a>x轴坐标分量。</p>
</td>
</tr>
<tr id="row698365394417"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p898375317447"><a name="p898375317447"></a><a name="p898375317447"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p109841253134412"><a name="p109841253134412"></a><a name="p109841253134412"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p2985175314449"><a name="p2985175314449"></a><a name="p2985175314449"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p20985145324415"><a name="p20985145324415"></a><a name="p20985145324415"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p15985155313447"><a name="p15985155313447"></a><a name="p15985155313447"></a>y轴坐标分量。</p>
</td>
</tr>
<tr id="row9987853194410"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p10987135312440"><a name="p10987135312440"></a><a name="p10987135312440"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p4988105312445"><a name="p4988105312445"></a><a name="p4988105312445"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p1698885354411"><a name="p1698885354411"></a><a name="p1698885354411"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p09883534446"><a name="p09883534446"></a><a name="p09883534446"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p10989753104412"><a name="p10989753104412"></a><a name="p10989753104412"></a>z轴坐标分量。</p>
</td>
</tr>
</tbody>
</table>

## RotationVectorResponse<a name="section13776194114611"></a>

旋转矢量传感器数据。

<a name="table936012224464"></a>
<table><thead align="left"><tr id="row1536162218466"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p93621222184610"><a name="p93621222184610"></a><a name="p93621222184610"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p73641422174614"><a name="p73641422174614"></a><a name="p73641422174614"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p936413225462"><a name="p936413225462"></a><a name="p936413225462"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1436515220462"><a name="p1436515220462"></a><a name="p1436515220462"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p163653222464"><a name="p163653222464"></a><a name="p163653222464"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row17366722174611"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p43670221462"><a name="p43670221462"></a><a name="p43670221462"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p14367822164613"><a name="p14367822164613"></a><a name="p14367822164613"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p133681722114611"><a name="p133681722114611"></a><a name="p133681722114611"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p17368162211468"><a name="p17368162211468"></a><a name="p17368162211468"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p16368172213460"><a name="p16368172213460"></a><a name="p16368172213460"></a>x轴坐标分量。</p>
</td>
</tr>
<tr id="row1736952234619"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p2369122214464"><a name="p2369122214464"></a><a name="p2369122214464"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p17369112244616"><a name="p17369112244616"></a><a name="p17369112244616"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p4370202254614"><a name="p4370202254614"></a><a name="p4370202254614"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p2037012216463"><a name="p2037012216463"></a><a name="p2037012216463"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p16371022144615"><a name="p16371022144615"></a><a name="p16371022144615"></a>y轴坐标分量。</p>
</td>
</tr>
<tr id="row10371142284612"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p337262284611"><a name="p337262284611"></a><a name="p337262284611"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p6372322164613"><a name="p6372322164613"></a><a name="p6372322164613"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p53721522154614"><a name="p53721522154614"></a><a name="p53721522154614"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p3373922144618"><a name="p3373922144618"></a><a name="p3373922144618"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p537319223469"><a name="p537319223469"></a><a name="p537319223469"></a>z轴坐标分量。</p>
</td>
</tr>
</tbody>
</table>

## GyroscopeResponse<a name="section3669131713463"></a>

陀螺仪传感器数据。

<a name="table102754418482"></a>
<table><thead align="left"><tr id="row132777414481"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p142771946487"><a name="p142771946487"></a><a name="p142771946487"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p1827816417489"><a name="p1827816417489"></a><a name="p1827816417489"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p16278945480"><a name="p16278945480"></a><a name="p16278945480"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p112794464817"><a name="p112794464817"></a><a name="p112794464817"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p1927919411483"><a name="p1927919411483"></a><a name="p1927919411483"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row82804419487"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p9280164114818"><a name="p9280164114818"></a><a name="p9280164114818"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p12811748489"><a name="p12811748489"></a><a name="p12811748489"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p1328184124815"><a name="p1328184124815"></a><a name="p1328184124815"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1028214134817"><a name="p1028214134817"></a><a name="p1028214134817"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p82831648484"><a name="p82831648484"></a><a name="p82831648484"></a>x轴坐标分量。</p>
</td>
</tr>
<tr id="row1628316411487"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p4283194194814"><a name="p4283194194814"></a><a name="p4283194194814"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p102843418489"><a name="p102843418489"></a><a name="p102843418489"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p20284124134812"><a name="p20284124134812"></a><a name="p20284124134812"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p2285174164816"><a name="p2285174164816"></a><a name="p2285174164816"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p52904454817"><a name="p52904454817"></a><a name="p52904454817"></a>y轴坐标分量。</p>
</td>
</tr>
<tr id="row529014124817"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p17290204144811"><a name="p17290204144811"></a><a name="p17290204144811"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p12913414486"><a name="p12913414486"></a><a name="p12913414486"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p142911147480"><a name="p142911147480"></a><a name="p142911147480"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p13292194104814"><a name="p13292194104814"></a><a name="p13292194104814"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p172923411480"><a name="p172923411480"></a><a name="p172923411480"></a>z轴坐标分量。</p>
</td>
</tr>
</tbody>
</table>

## GyroscopeUncalibratedResponse<a name="section1041541413475"></a>

未校准陀螺仪传感器数据。

<a name="table13573121419491"></a>
<table><thead align="left"><tr id="row1257531411492"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p357541412492"><a name="p357541412492"></a><a name="p357541412492"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p1157571411492"><a name="p1157571411492"></a><a name="p1157571411492"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p357691434915"><a name="p357691434915"></a><a name="p357691434915"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p65767140498"><a name="p65767140498"></a><a name="p65767140498"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p7576814124913"><a name="p7576814124913"></a><a name="p7576814124913"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row957710147490"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p2577191419497"><a name="p2577191419497"></a><a name="p2577191419497"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p4578101413498"><a name="p4578101413498"></a><a name="p4578101413498"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p257861411497"><a name="p257861411497"></a><a name="p257861411497"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p85781141490"><a name="p85781141490"></a><a name="p85781141490"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1757971418492"><a name="p1757971418492"></a><a name="p1757971418492"></a>x轴坐标分量。</p>
</td>
</tr>
<tr id="row4579914134916"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p115791014104911"><a name="p115791014104911"></a><a name="p115791014104911"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p9580714144912"><a name="p9580714144912"></a><a name="p9580714144912"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p14581514134911"><a name="p14581514134911"></a><a name="p14581514134911"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1658281410492"><a name="p1658281410492"></a><a name="p1658281410492"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p05821144494"><a name="p05821144494"></a><a name="p05821144494"></a>y轴坐标分量。</p>
</td>
</tr>
<tr id="row8582214174913"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p458331410497"><a name="p458331410497"></a><a name="p458331410497"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p5583171484918"><a name="p5583171484918"></a><a name="p5583171484918"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p10583131434918"><a name="p10583131434918"></a><a name="p10583131434918"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p258451484917"><a name="p258451484917"></a><a name="p258451484917"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p18584514204911"><a name="p18584514204911"></a><a name="p18584514204911"></a>z轴坐标分量。</p>
</td>
</tr>
<tr id="row8585111414498"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p20585111454910"><a name="p20585111454910"></a><a name="p20585111454910"></a>biasX</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p858541411498"><a name="p858541411498"></a><a name="p858541411498"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p6586914104920"><a name="p6586914104920"></a><a name="p6586914104920"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p958612145494"><a name="p958612145494"></a><a name="p958612145494"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p165871614104919"><a name="p165871614104919"></a><a name="p165871614104919"></a>x轴坐标偏移量。</p>
</td>
</tr>
<tr id="row1158718145494"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p13587514124919"><a name="p13587514124919"></a><a name="p13587514124919"></a>biasY</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p058811424915"><a name="p058811424915"></a><a name="p058811424915"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p165881414134913"><a name="p165881414134913"></a><a name="p165881414134913"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p458841411491"><a name="p458841411491"></a><a name="p458841411491"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p10589171413495"><a name="p10589171413495"></a><a name="p10589171413495"></a>y轴坐标偏移量。</p>
</td>
</tr>
<tr id="row15589514174920"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p558912143499"><a name="p558912143499"></a><a name="p558912143499"></a>biasZ</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1059051415498"><a name="p1059051415498"></a><a name="p1059051415498"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p18590171484915"><a name="p18590171484915"></a><a name="p18590171484915"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p3590191434919"><a name="p3590191434919"></a><a name="p3590191434919"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p114335613132"><a name="p114335613132"></a><a name="p114335613132"></a>z轴坐标偏移量。</p>
</td>
</tr>
</tbody>
</table>

## SignificantMotionResponse<a name="section1213143164712"></a>

有效运动传感器数据。

<a name="table4948240175015"></a>
<table><thead align="left"><tr id="row139500400502"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p17950104035012"><a name="p17950104035012"></a><a name="p17950104035012"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p1595014402501"><a name="p1595014402501"></a><a name="p1595014402501"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p0951144015010"><a name="p0951144015010"></a><a name="p0951144015010"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p19951184015506"><a name="p19951184015506"></a><a name="p19951184015506"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p1795217408508"><a name="p1795217408508"></a><a name="p1795217408508"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row195264075013"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p49531340145019"><a name="p49531340145019"></a><a name="p49531340145019"></a>scalar</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p59531940145017"><a name="p59531940145017"></a><a name="p59531940145017"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p13953184045010"><a name="p13953184045010"></a><a name="p13953184045010"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p13954174045015"><a name="p13954174045015"></a><a name="p13954174045015"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p783151465110"><a name="p783151465110"></a><a name="p783151465110"></a>表示剧烈运动程度。测量三个物理轴（x、y 和 z）上，设备是否存在大幅度运动；如果取值为1则代表存在大幅度运动，取值为0则代表没有大幅度运动。</p>
</td>
</tr>
</tbody>
</table>

## ProximityResponse<a name="section5275184313476"></a>

接近光传感器数据。

<a name="table202672057205220"></a>
<table><thead align="left"><tr id="row126955713526"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p226985716524"><a name="p226985716524"></a><a name="p226985716524"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p9270195716524"><a name="p9270195716524"></a><a name="p9270195716524"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p112707570523"><a name="p112707570523"></a><a name="p112707570523"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p19271115717528"><a name="p19271115717528"></a><a name="p19271115717528"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p17271957135218"><a name="p17271957135218"></a><a name="p17271957135218"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1827275715524"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p1327312575521"><a name="p1327312575521"></a><a name="p1327312575521"></a>distance</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p6274155713523"><a name="p6274155713523"></a><a name="p6274155713523"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p12758576525"><a name="p12758576525"></a><a name="p12758576525"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p2275155735217"><a name="p2275155735217"></a><a name="p2275155735217"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1827511579525"><a name="p1827511579525"></a><a name="p1827511579525"></a>可见物体与设备显示器的接近程度。0表示接近，1表示远离。</p>
</td>
</tr>
</tbody>
</table>

## LightResponse<a name="section195685404716"></a>

环境光传感器数据。

<a name="table9943111745715"></a>
<table><thead align="left"><tr id="row69451176576"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p4946117165719"><a name="p4946117165719"></a><a name="p4946117165719"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p5946131718576"><a name="p5946131718576"></a><a name="p5946131718576"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p1947141775714"><a name="p1947141775714"></a><a name="p1947141775714"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1594791795712"><a name="p1594791795712"></a><a name="p1594791795712"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p19481817105717"><a name="p19481817105717"></a><a name="p19481817105717"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row179481617155718"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p494931755718"><a name="p494931755718"></a><a name="p494931755718"></a>intensity</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p294951712577"><a name="p294951712577"></a><a name="p294951712577"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p6950417135718"><a name="p6950417135718"></a><a name="p6950417135718"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1995011710574"><a name="p1995011710574"></a><a name="p1995011710574"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1395001713579"><a name="p1395001713579"></a><a name="p1395001713579"></a>光强（单位：勒克斯）。</p>
</td>
</tr>
</tbody>
</table>

## HallResponse<a name="section18608467487"></a>

霍尔传感器数据。

<a name="table1911424985916"></a>
<table><thead align="left"><tr id="row111171049205916"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p1511713492592"><a name="p1511713492592"></a><a name="p1511713492592"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p16117144918595"><a name="p16117144918595"></a><a name="p16117144918595"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p16118144915592"><a name="p16118144915592"></a><a name="p16118144915592"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p9118149165915"><a name="p9118149165915"></a><a name="p9118149165915"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p101191149185918"><a name="p101191149185918"></a><a name="p101191149185918"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row0119184918596"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p1112084919593"><a name="p1112084919593"></a><a name="p1112084919593"></a>status</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p51211149105919"><a name="p51211149105919"></a><a name="p51211149105919"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p19121164915911"><a name="p19121164915911"></a><a name="p19121164915911"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p312224918597"><a name="p312224918597"></a><a name="p312224918597"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1612224918598"><a name="p1612224918598"></a><a name="p1612224918598"></a>显示霍尔状态。测量设备周围是否存在磁力吸引，0表示有，1表示没有。</p>
</td>
</tr>
</tbody>
</table>

## MagneticFieldResponse<a name="section20218191813489"></a>

磁场传感器数据。

<a name="table730517551096"></a>
<table><thead align="left"><tr id="row113071551994"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p1630817551591"><a name="p1630817551591"></a><a name="p1630817551591"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p1030885517919"><a name="p1030885517919"></a><a name="p1030885517919"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p1309125516917"><a name="p1309125516917"></a><a name="p1309125516917"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p730935511910"><a name="p730935511910"></a><a name="p730935511910"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p430916559916"><a name="p430916559916"></a><a name="p430916559916"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row531015552910"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p63101155298"><a name="p63101155298"></a><a name="p63101155298"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p13311145518913"><a name="p13311145518913"></a><a name="p13311145518913"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p103119551916"><a name="p103119551916"></a><a name="p103119551916"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p731216558917"><a name="p731216558917"></a><a name="p731216558917"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p931218554920"><a name="p931218554920"></a><a name="p931218554920"></a>x轴坐标分量。</p>
</td>
</tr>
<tr id="row153134551696"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p183135551397"><a name="p183135551397"></a><a name="p183135551397"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1231313553915"><a name="p1231313553915"></a><a name="p1231313553915"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p03148551490"><a name="p03148551490"></a><a name="p03148551490"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p193142551292"><a name="p193142551292"></a><a name="p193142551292"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p931516551293"><a name="p931516551293"></a><a name="p931516551293"></a>y轴坐标分量。</p>
</td>
</tr>
<tr id="row93154551999"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p8315105516911"><a name="p8315105516911"></a><a name="p8315105516911"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p531625514919"><a name="p531625514919"></a><a name="p531625514919"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p33162055892"><a name="p33162055892"></a><a name="p33162055892"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p3317455991"><a name="p3317455991"></a><a name="p3317455991"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p13318145517919"><a name="p13318145517919"></a><a name="p13318145517919"></a>z轴坐标分量。</p>
</td>
</tr>
</tbody>
</table>

## MagneticFieldUncalibratedResponse<a name="section13749143113486"></a>

未校准磁场传感器数据。

<a name="table131661533141019"></a>
<table><thead align="left"><tr id="row14167103381016"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p171687333103"><a name="p171687333103"></a><a name="p171687333103"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p1168173351011"><a name="p1168173351011"></a><a name="p1168173351011"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p10168433181013"><a name="p10168433181013"></a><a name="p10168433181013"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p191691933171018"><a name="p191691933171018"></a><a name="p191691933171018"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p6169113311107"><a name="p6169113311107"></a><a name="p6169113311107"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row11170633141011"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p131707336105"><a name="p131707336105"></a><a name="p131707336105"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p8170203341018"><a name="p8170203341018"></a><a name="p8170203341018"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p8171113311014"><a name="p8171113311014"></a><a name="p8171113311014"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p151717334108"><a name="p151717334108"></a><a name="p151717334108"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1117216339104"><a name="p1117216339104"></a><a name="p1117216339104"></a>x轴坐标分量。</p>
</td>
</tr>
<tr id="row617283341012"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p1217210333103"><a name="p1217210333103"></a><a name="p1217210333103"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p13173193312104"><a name="p13173193312104"></a><a name="p13173193312104"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p71731433191015"><a name="p71731433191015"></a><a name="p71731433191015"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p2174933151015"><a name="p2174933151015"></a><a name="p2174933151015"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1717413317103"><a name="p1717413317103"></a><a name="p1717413317103"></a>y轴坐标分量。</p>
</td>
</tr>
<tr id="row617443319105"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p13175433181015"><a name="p13175433181015"></a><a name="p13175433181015"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p11175173301019"><a name="p11175173301019"></a><a name="p11175173301019"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p171761233101019"><a name="p171761233101019"></a><a name="p171761233101019"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p817623301020"><a name="p817623301020"></a><a name="p817623301020"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p5176113311100"><a name="p5176113311100"></a><a name="p5176113311100"></a>z轴坐标分量。</p>
</td>
</tr>
<tr id="row1117713391016"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p617703319103"><a name="p617703319103"></a><a name="p617703319103"></a>biasX</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1417710332105"><a name="p1417710332105"></a><a name="p1417710332105"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p15178833171015"><a name="p15178833171015"></a><a name="p15178833171015"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p7178203310105"><a name="p7178203310105"></a><a name="p7178203310105"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p14179933111017"><a name="p14179933111017"></a><a name="p14179933111017"></a>x轴坐标偏移量。</p>
</td>
</tr>
<tr id="row3179103312100"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p16179163351015"><a name="p16179163351015"></a><a name="p16179163351015"></a>biasY</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p51801033191015"><a name="p51801033191015"></a><a name="p51801033191015"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p171811433101014"><a name="p171811433101014"></a><a name="p171811433101014"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p14181833101013"><a name="p14181833101013"></a><a name="p14181833101013"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1318213318105"><a name="p1318213318105"></a><a name="p1318213318105"></a>y轴坐标偏移量。</p>
</td>
</tr>
<tr id="row5182113361010"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p61831033201011"><a name="p61831033201011"></a><a name="p61831033201011"></a>biasZ</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1918423311102"><a name="p1918423311102"></a><a name="p1918423311102"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p9184173320105"><a name="p9184173320105"></a><a name="p9184173320105"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1718593371011"><a name="p1718593371011"></a><a name="p1718593371011"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1418563321020"><a name="p1418563321020"></a><a name="p1418563321020"></a>z轴坐标偏移量。</p>
</td>
</tr>
</tbody>
</table>

## PedometerResponse<a name="section1350145915489"></a>

计步传感器数据。

<a name="table1221161131216"></a>
<table><thead align="left"><tr id="row132312114128"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p923811191215"><a name="p923811191215"></a><a name="p923811191215"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p192415116127"><a name="p192415116127"></a><a name="p192415116127"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p5240115123"><a name="p5240115123"></a><a name="p5240115123"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p32531110121"><a name="p32531110121"></a><a name="p32531110121"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p102551116129"><a name="p102551116129"></a><a name="p102551116129"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row826511151216"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p6276119120"><a name="p6276119120"></a><a name="p6276119120"></a>steps</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1227511161210"><a name="p1227511161210"></a><a name="p1227511161210"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p102716117128"><a name="p102716117128"></a><a name="p102716117128"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p62891114129"><a name="p62891114129"></a><a name="p62891114129"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p930101114120"><a name="p930101114120"></a><a name="p930101114120"></a>计数的步骤数。每次设备重新启动时，该值将从0重新计算。</p>
</td>
</tr>
</tbody>
</table>

## HumidityResponse<a name="section20444511666"></a>

湿度传感器数据。

<a name="table1938504321317"></a>
<table><thead align="left"><tr id="row7387134310134"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p838784331318"><a name="p838784331318"></a><a name="p838784331318"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p73888439139"><a name="p73888439139"></a><a name="p73888439139"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p4390843161311"><a name="p4390843161311"></a><a name="p4390843161311"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p53901743131312"><a name="p53901743131312"></a><a name="p53901743131312"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p8391104381315"><a name="p8391104381315"></a><a name="p8391104381315"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row18391154314131"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p17392043191317"><a name="p17392043191317"></a><a name="p17392043191317"></a>humidity</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p183928439135"><a name="p183928439135"></a><a name="p183928439135"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p539354361312"><a name="p539354361312"></a><a name="p539354361312"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p153931943141316"><a name="p153931943141316"></a><a name="p153931943141316"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p2394124391310"><a name="p2394124391310"></a><a name="p2394124391310"></a>湿度值。测量环境的相对湿度，以百分比 (%) 表示。</p>
</td>
</tr>
</tbody>
</table>

## PedometerDetectResponse<a name="section145653910491"></a>

计步检测传感器数据。

<a name="table1344548131418"></a>
<table><thead align="left"><tr id="row847124841419"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p184784811412"><a name="p184784811412"></a><a name="p184784811412"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p748184871417"><a name="p748184871417"></a><a name="p748184871417"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p0481948101412"><a name="p0481948101412"></a><a name="p0481948101412"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p154915487141"><a name="p154915487141"></a><a name="p154915487141"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p149174819147"><a name="p149174819147"></a><a name="p149174819147"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row124994881417"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p350148161411"><a name="p350148161411"></a><a name="p350148161411"></a>scalar</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p15115487149"><a name="p15115487149"></a><a name="p15115487149"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p155194821414"><a name="p155194821414"></a><a name="p155194821414"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p4521148171413"><a name="p4521148171413"></a><a name="p4521148171413"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p152148131413"><a name="p152148131413"></a><a name="p152148131413"></a>计步器检测。检测用户的计步动作，如果取值为1则代表用户产生了计步行走的动作，取值为0则代表用户没有发生运动。</p>
</td>
</tr>
</tbody>
</table>

## AmbientTemperatureResponse<a name="section728281924920"></a>

温度传感器数据。

<a name="table125671838181519"></a>
<table><thead align="left"><tr id="row1656803818158"><th class="cellrowborder" valign="top" width="17.41%" id="mcps1.1.6.1.1"><p id="p145691638161517"><a name="p145691638161517"></a><a name="p145691638161517"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.200000000000001%" id="mcps1.1.6.1.2"><p id="p1656923871512"><a name="p1656923871512"></a><a name="p1656923871512"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.31%" id="mcps1.1.6.1.3"><p id="p857033813151"><a name="p857033813151"></a><a name="p857033813151"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="10.32%" id="mcps1.1.6.1.4"><p id="p7570103821513"><a name="p7570103821513"></a><a name="p7570103821513"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="48.76%" id="mcps1.1.6.1.5"><p id="p75717386158"><a name="p75717386158"></a><a name="p75717386158"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row55718388151"><td class="cellrowborder" valign="top" width="17.41%" headers="mcps1.1.6.1.1 "><p id="p25713386150"><a name="p25713386150"></a><a name="p25713386150"></a>temperature</p>
</td>
<td class="cellrowborder" valign="top" width="13.200000000000001%" headers="mcps1.1.6.1.2 "><p id="p85729383152"><a name="p85729383152"></a><a name="p85729383152"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.31%" headers="mcps1.1.6.1.3 "><p id="p1757213388153"><a name="p1757213388153"></a><a name="p1757213388153"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="10.32%" headers="mcps1.1.6.1.4 "><p id="p55734383154"><a name="p55734383154"></a><a name="p55734383154"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.76%" headers="mcps1.1.6.1.5 "><p id="p1557313811513"><a name="p1557313811513"></a><a name="p1557313811513"></a>环境温度（单位：摄氏度）。</p>
</td>
</tr>
</tbody>
</table>

## BarometerResponse<a name="section143457303496"></a>

气压计传感器数据。

<a name="table1846831851619"></a>
<table><thead align="left"><tr id="row646931812166"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p124703182168"><a name="p124703182168"></a><a name="p124703182168"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p194702185166"><a name="p194702185166"></a><a name="p194702185166"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p1147117181161"><a name="p1147117181161"></a><a name="p1147117181161"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p16471191811619"><a name="p16471191811619"></a><a name="p16471191811619"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p1447212181164"><a name="p1447212181164"></a><a name="p1447212181164"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row164721418161614"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p64729187163"><a name="p64729187163"></a><a name="p64729187163"></a>pressure</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p047361810165"><a name="p047361810165"></a><a name="p047361810165"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p11474151831612"><a name="p11474151831612"></a><a name="p11474151831612"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p10474131812168"><a name="p10474131812168"></a><a name="p10474131812168"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p947510186168"><a name="p947510186168"></a><a name="p947510186168"></a>压力值（单位：帕斯卡）。</p>
</td>
</tr>
</tbody>
</table>

## HeartRateResponse<a name="section95011341124915"></a>

心率传感器数据。

<a name="table47331264174"></a>
<table><thead align="left"><tr id="row473519651714"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p37351611718"><a name="p37351611718"></a><a name="p37351611718"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p273611610170"><a name="p273611610170"></a><a name="p273611610170"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p13736565175"><a name="p13736565175"></a><a name="p13736565175"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p073719691711"><a name="p073719691711"></a><a name="p073719691711"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p127377611172"><a name="p127377611172"></a><a name="p127377611172"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row07380617174"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p147388671710"><a name="p147388671710"></a><a name="p147388671710"></a>heartRate</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p167381063177"><a name="p167381063177"></a><a name="p167381063177"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p177391641717"><a name="p177391641717"></a><a name="p177391641717"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1173911661720"><a name="p1173911661720"></a><a name="p1173911661720"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p11740176131712"><a name="p11740176131712"></a><a name="p11740176131712"></a>心率值。测量用户的心率数值，单位是次/分。</p>
</td>
</tr>
</tbody>
</table>

## WearDetectionResponse<a name="section128278501495"></a>

佩戴检测传感器数据。

<a name="table64111853121720"></a>
<table><thead align="left"><tr id="row4413135314174"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p174131653181715"><a name="p174131653181715"></a><a name="p174131653181715"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p5414145312174"><a name="p5414145312174"></a><a name="p5414145312174"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p14144533171"><a name="p14144533171"></a><a name="p14144533171"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p134140535176"><a name="p134140535176"></a><a name="p134140535176"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p16415165319173"><a name="p16415165319173"></a><a name="p16415165319173"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row19415155321710"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p7416153191713"><a name="p7416153191713"></a><a name="p7416153191713"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1341695351714"><a name="p1341695351714"></a><a name="p1341695351714"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p14171153201710"><a name="p14171153201710"></a><a name="p14171153201710"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p041716530173"><a name="p041716530173"></a><a name="p041716530173"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p11418135318172"><a name="p11418135318172"></a><a name="p11418135318172"></a>表示设备是否被穿戴（true 表示已穿戴，false表示未穿戴）。</p>
</td>
</tr>
</tbody>
</table>

