# 设置系统时间

本模块主要由时间、时区和定时三大功能组成。其中，定时服务用来管理和使用时间、时区。开发者可以通过对系统进行设置、获取等操作管理系统时间、时区，也可以通过定时功能实现定时服务如闹钟服务等。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```
import systemTime from '@ohos.systemTime';
```


## systemTime.setTime

setTime(time : number, callback : AsyncCallback&lt;void&gt;) : void

设置系统时间。

**需要权限：** ohos.permission.SET_TIME

**系统能力：** SystemCapability.Miscservices.Time

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                       |
| -------- | ------------------------- | ---- | ------------------------------------------ |
| time     | number                    | 是   | 目标时间戳（ms）。                         |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，可以在回调函数中处理接口返回值。 |

**示例：**

  ```js
  // time对应的时间为2021-01-20 02:36:25
  var time = 1611081385000;
  systemTime.setTime(time, (error, data) => {
      if (error) {
          console.error(`failed to systemTime.setTime because ` + JSON.stringify(error));
          return;
      }
      console.log(`systemTime.setTime success data : ` + JSON.stringify(data));
  });
  ```


## systemTime.setTime

setTime(time : number) : Promise&lt;void&gt;

设置系统时间。

**需要权限：** ohos.permission.SET_TIME

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| time   | number | 是   | 目标时间戳（ms）。 |

**返回值：**

| 类型                | 说明                 |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | 返回的异步回调函数。 |

**示例：**

  ```js
  // time对应的时间为2021-01-20 02:36:25
  var time = 1611081385000;
  systemTime.setTime(time).then((data) => {
      console.log(`systemTime.setTime success data : ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to systemTime.setTime because ` + JSON.stringify(error));
  });
  ```


## systemTime.getCurrentTime<sup>8+</sup>

getCurrentTime(isNano?: boolean, callback: AsyncCallback&lt;number&gt;): void

获取自 Unix 纪元以来经过的时间，使用callback形式返回结果。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| isNano   | boolean                     | 否   | 返回结果是否为纳秒数。                                                                                                                                                              - true：纳秒数。 <br>- false：毫秒数。 <br> |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，返回自&nbsp;Unix&nbsp;纪元以来经过的时间。         |

**示例：**

  ```js
  systemTime.getCurrentTime(true, (error, data) => {
      if (error) {
          console.error(`failed to systemTime.getCurrentTime because ` + JSON.stringify(error));
          return;
      }
      console.log(`systemTime.getCurrentTime success data : ` + JSON.stringify(data));
  });
  ```


## systemTime.getCurrentTime<sup>8+</sup>

getCurrentTime(isNano?: boolean): Promise&lt;number&gt;

获取自 Unix 纪元以来经过的时间，使用Promise形式返回结果。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| isNano | boolean | 否   | 返回结果是否为纳秒数。                                                                                                                                                              - true：纳秒数。 <br/>- false：毫秒数。 <br/> |

**返回值：**

| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | 以Promise形式返回结果，返回自&nbsp;Unix&nbsp;纪元以来经过的时间。 |

**示例：**

  ```js
  systemTime.getCurrentTime().then((data) => {
      console.log(`systemTime.getCurrentTime success data : ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to systemTime.getCurrentTime because ` + JSON.stringify(error));
  });
  ```


## systemTime.getRealActiveTime<sup>8+</sup>

getRealActiveTime(isNano?: boolean, callback: AsyncCallback&lt;number&gt;): void

获取自系统启动以来经过的时间，不包括深度睡眠时间，使用callback形式返回结果。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| isNano   | boolean                     | 否   | 返回结果是否为纳秒数。                                                                                                                                                              - true：纳秒数。 <br/>- false：毫秒数。 <br/> |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，返回自系统启动以来经过的时间，但不包括度睡眠时间。 |

**示例：**

  ```js
  systemTime.getRealActiveTime(true, (error, data) => {
      if (error) {
          console.error(`failed to systemTime.getRealActiveTimebecause ` + JSON.stringify(error));
          return;
      }
      console.log(`systemTime.getRealActiveTime success data : ` + JSON.stringify(data));
  });
  ```


## systemTime.getRealActiveTime<sup>8+</sup>

getRealActiveTime(isNano?: boolean): Promise&lt;number&gt;

获取自系统启动以来经过的时间，不包括深度睡眠时间，使用Promise形式返回结果。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| isNano | boolean | 否   | 返回结果是否为纳秒数。                                                                                                                                                              - true：纳秒数。 <br/>- false：毫秒数。 <br/> |

**返回值：**

| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | 以Promise形式返回结果，返回自系统启动以来经过的时间，但不包括深度睡眠时间。 |

**示例：**

  ```js
  systemTime.getRealActiveTime().then((data) => {
      console.log(`systemTime.getRealActiveTime success data : ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to systemTime.getRealActiveTime because ` + JSON.stringify(error));
  });
  ```


## systemTime.getRealTime<sup>8+</sup>

getRealTime(callback: AsyncCallback&lt;number&gt;): void

获取自系统启动以来经过的时间，包括深度睡眠时间，使用callback形式返回结果。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| isNano   | boolean                     | 否   | 返回结果是否为纳秒数。                                                                                                                                                              - true：纳秒数。 <br/>- false：毫秒数。 <br/> |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，返回自系统启动以来经过的时间，包括深度睡眠时间。   |

**示例：**

  ```js
  systemTime.getRealTime(true, (error, data) => {
      if (error) {
          console.error(`failed to systemTime.getRealTime because ` + JSON.stringify(error));
          return;
      }
      console.log(`systemTime.getRealTime success data: ` + JSON.stringify(data));
  });
  ```


## systemTime.getRealTime<sup>8+</sup>

getRealTime(): Promise&lt;number&gt;

获取自系统启动以来经过的时间，包括深度睡眠时间，使用Promise形式返回结果。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| isNano | boolean | 否   | 返回结果是否为纳秒数。                                                                                                                                                                            - true：纳秒数。 <br/>- false：毫秒数。 <br/> |

**返回值：**

| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | 以Promise形式返回结果，返回自系统启动以来经过的时间，包括深度睡眠时间。 |

**示例：**

  ```js
  systemTime.getRealTime().then((data) => {
      console.log(`systemTime.getRealTime success data: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to systemTime.getRealTime because ` + JSON.stringify(error));
  });
  ```


## systemTime.setDate

setDate(date: Date, callback: AsyncCallback&lt;void&gt;): void

设置系统日期，使用callback形式返回结果。

**需要权限：** ohos.permission.SET_TIME

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                       |
| -------- | ------------------------- | ---- | ------------------------------------------ |
| date     | Date                      | 是   | 目标日期。                                 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，可以在回调函数中处理接口返回值。 |

**示例：**

  ```js
  var data = new Date("October 13, 2020 11:13:00");
  systemTime.setDate(data,(error, data) => {       
      if (error) {            
      console.error('failed to systemTime.setDate because ' + JSON.stringify(error));           
      return;       
  }        
      console.info('systemTime.setDate success data : ' + JSON.stringify(data));    
  });
  ```


## systemTime.setDate

setDate(date: Date): Promise&lt;void&gt;

设置系统日期，使用Promise形式返回结果。

**需要权限：** ohos.permission.SET_TIME

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型 | 必填 | 说明       |
| ------ | ---- | ---- | ---------- |
| date   | Date | 是   | 目标日期。 |

**返回值：**

| 类型                | 说明                 |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | 返回的异步回调函数。 |

**示例：**

  ```js
  var data = new Date("October 13, 2020 11:13:00"); 
  systemTime.setDate(data).then((value) => {        
      console.log(`systemTime.setDate success data : ` + JSON.stringify(value));    
  }).catch((error) => {        
      console.error(`failed to systemTime.setDate because: ` + JSON.stringify(error));
  });
  ```


## systemTime.getDate<sup>8+</sup>

getDate(callback: AsyncCallback&lt;Date&gt;): void

获取当前系统日期，使用callback形式返回结果。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                      | 必填 | 说明                         |
| -------- | ------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback&lt;Date&gt; | 是   | 回调函数，返回当前系统日期。 |

**示例：**

  ```js
  systemTime.getDate((error, data) => {
      if (error) {
          console.error(`failed to systemTime.getDate because ` + JSON.stringify(error));
          return;
      }
      console.log(`systemTime.getDate success data : ` + JSON.stringify(data));
  });
  ```


## systemTime.getDate<sup>8+</sup>

getDate(): Promise&lt;Date&gt;

获取当前系统日期，使用Promise形式返回结果。

**系统能力：** SystemCapability.MiscServices.Time

**返回值：**

| 类型                | 说明                                      |
| ------------------- | ----------------------------------------- |
| Promise&lt;Date&gt; | 以Promise形式返回结果，返回当前系统日期。 |

**示例：**

  ```js
  systemTime.getDate().then((data) => {
      console.log(`systemTime.getDate success data : ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to systemTime.getDate because ` + JSON.stringify(error));
  });
  ```


## systemTime.setTimezone

setTimezone(timezone: string, callback: AsyncCallback&lt;void&gt;): void

设置系统时区。

**需要权限：** ohos.permission.SET_TIME_ZONE

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                       |
| -------- | ------------------------- | ---- | ------------------------------------------ |
| timezone | string                    | 是   | 系统时区。                                 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，可以在回调函数中处理接口返回值。 |

**示例：**

  ```js
  systemTime.setTimezone('Asia/Shanghai', (error, data) => {       
      if (error) {          
          console.error('failed to systemTime.setTimezone because ' + JSON.stringify(error));         
          return;       
      }       
      console.info('SystemTimePlugin systemTime.setTimezone success data : ' + JSON.stringify(data)); 
  });
  ```


## systemTime.setTimezone

setTimezone(timezone: string): Promise&lt;void&gt;

设置系统时区。

**需要权限：** ohos.permission.SET_TIME_ZONE

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型   | 必填 | 说明       |
| -------- | ------ | ---- | ---------- |
| timezone | string | 是   | 系统时区。 |

**返回值：**

| 类型                | 说明                 |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | 返回的异步回调函数。 |

**示例：**

  ```js
  systemTime.setTimezone('Asia/Shanghai').then((data) => {        
      console.log(`systemTime.setTimezone success data : ` + JSON.stringify(data));     
  }).catch((error) => {        
      console.error(`failed to systemTime.setTimezone because: ` + JSON.stringify(error));    
  });
  ```


## systemTime.getTimezone<sup>8+</sup>

getTimezone(callback: AsyncCallback&lt;string&gt;): void

获取系统时区，使用callback形式返回结果。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                        | 必填 | 说明                     |
| -------- | --------------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数，返回系统时区。 |

**示例：**

  ```js
  systemTime.getTimezone((error, data) => {
      if (error) {
          console.error(`failed to systemTime.getTimezone because ` + JSON.stringify(error));
          return;
      }
      console.log(`systemTime.getTimezone success data : ` + JSON.stringify(data));
  });
  ```


## systemTime.getTimezone<sup>8+</sup>

getTimezone(): Promise&lt;string&gt;

获取系统时区，使用Promise形式返回结果。

**系统能力：** SystemCapability.MiscServices.Time

**返回值：**

| 类型                  | 说明                                  |
| --------------------- | ------------------------------------- |
| Promise&lt;string&gt; | 以Promise形式返回结果，返回系统时区。 |

**示例：**

  ```js
  systemTime.getTimezone().then((data) => {
      console.log(`systemTime.getTimezone success data : ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to systemTime.getTimezone because ` + JSON.stringify(error));
  });
  ```