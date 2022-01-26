# 设置系统时间

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import systemTime from '@ohos.systemTime';
```


## systemTime.setTime

setTime(time : number, callback : AsyncCallback&lt;void&gt;) : void

设置系统时间，需要ohos.permission.SET_TIME权限。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | time | number | 是 | 目标时间戳（毫秒）。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，可以在回调函数中处理接口返回值。 |

- 示例：
  ```
  // time对应的时间为2021-01-20 02:36:25
  var time = 1611081385000;
  systemTime.setTime(time, (error, data) => {
      if (error) {
          console.error(`failed to systemTime.setTime because ` + JSON.stringify(error));
          return;
      }
      console.log(`success to systemTime.setTime: ` + JSON.stringify(data));
  });
  ```


## systemTime.setTime

setTime(time : number) : Promise&lt;void&gt;

设置系统时间，需要ohos.permission.SET_TIME权限。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | time | number | 是 | 目标时间戳（毫秒）。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | 返回的异步回调函数。 |

- 示例：
  ```
  // time对应的时间为2021-01-20 02:36:25
  var time = 1611081385000;
  systemTime.setTime(time).then((data) => {
      console.log(`success to systemTime.setTime: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to systemTime.setTime because ` + JSON.stringify(error));
  });
  ```


## systemTime.setDate

setDate(date: Date, callback: AsyncCallback&lt;void&gt;): void

设置系统日期，需要ohos.permission.SET_TIME权限。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | date | Date | 是 | 目标日期。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，可以在回调函数中处理接口返回值。 |

- 示例：
  ```
  var data = new Date("October 13, 2020 11:13:00");
  systemTime.setDate(data,(error, data) => {       
      if (error) {            
      console.error('SystemTimePlugin setDate failed because ' + JSON.stringify(error));           
      return;       
  }        
      console.info('SystemTimePlugin setDate success data : ' + JSON.stringify(data));    
  });
  ```


## systemTime.setDate

setDate(date: Date): Promise&lt;void&gt;

设置系统日期，需要ohos.permission.SET_TIME权限。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | date | Date | 是 | 目标日期。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | 返回的异步回调函数。 |

- 示例：
  ```
  var data = new Date("October 13, 2020 11:13:00"); 
  systemTime.setDate(data).then((value) => {        
      console.log(`SystemTimePlugin success to systemTime.setDate: ` + JSON.stringify(value));    
  }).catch((error) => {        
      console.error(`SystemTimePlugin failed to systemTime.setDate because: ` + JSON.stringify(error));
  });
  ```


## systemTime.setTimezone

setTimezone(timezone: string, callback: AsyncCallback&lt;void&gt;): void

设置系统时区，需要ohos.permission.SET_TIME_ZONE权限。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | timezone | string | 是 | 系统时区。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，可以在回调函数中处理接口返回值。 |

- 示例：
  ```
  systemTime.setTimezone('Asia/Shanghai', (error, data) => {       
      if (error) {          
          console.error('SystemTimePlugin setTimezone failed because ' + JSON.stringify(error));          
          return;       
      }       
      console.info('SystemTimePlugin setTimezone success data : ' + JSON.stringify(data)); 
  });
  ```


## systemTime.setTimezone

setTimezone(timezone: string): Promise&lt;void&gt;

设置系统时区，需要ohos.permission.SET_TIME_ZONE权限。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | timezone | string | 是 | 系统时区。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | 返回的异步回调函数。 |

- 示例：
  ```
  systemTime.setTimezone('Asia/Shanghai').then((data) => {        
      console.log(`SystemTimePlugin success to systemTime.setTimezone: ` + JSON.stringify(data));     
  }).catch((error) => {        
      console.error(`SystemTimePlugin failed to systemTime.setTimezone because: ` + JSON.stringify(error));    
  });
  ```
