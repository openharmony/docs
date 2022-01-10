# 后台任务管理

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import backgroundTaskManager from '@ohos.backgroundTaskManager';  
```


## 权限

无


## backgroundTaskManager.requestSuspendDelay

requestSuspendDelay(reason: string, callback: Callback&lt;void&gt;): DelaySuspendInfo

后台应用申请延迟挂起。

延迟挂起时间一般情况下默认值为180000，低电量（依据系统低电量广播）时默认值为60000。

- **参数**：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | reason | string | 是 | 延迟挂起申请的原因。 |
  | callback | Callback&lt;void&gt; | 是 | 延迟即将超时的回调函数，一般在超时前6秒通过此回调通知应用。 |

- **返回值**：
  | 类型 | 说明 |
  | -------- | -------- |
  | [DelaySuspendInfo](#delaysuspendinfo) | 返回延迟挂起信息。 |

- **示例**：
  ```
  let myReason = 'test requestSuspendDelay';
  let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, (val) => {
      console.info("Request suspend delay will time out.");
  })
  ```


## backgroundTaskManager.getRemainingDelayTime

getRemainingDelayTime(requestId: number, callback: AsyncCallback&lt;number&gt;): void

获取应用程序进入挂起状态前的剩余时间，使用callback形式返回。

- **参数**：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | requestId | number | 是 | 延迟挂起的请求ID。 |
  | callback | AsyncCallback&lt;number&gt; | 是 | 指定的callback回调方法。用于返回应用程序进入挂起状态之前的剩余时间，以毫秒为单位。 |

- **示例**：
  ```
  let id = 1;
  backgroundTaskManager.getRemainingDelayTime(id, (err, res) => {
      if(err.data === 0) {
          console.log('promise => Operation succeeded. Data: ' + JSON.stringify(res));
      } else {
          console.log('promise => Operation failed. Cause: ' + err.data);
      }
  })
  ```


## backgroundTaskManager.getRemainingDelayTime

getRemainingDelayTime(requestId: number): Promise&lt;number&gt;

获取应用程序进入挂起状态前的剩余时间，使用Promise形式返回。

- **参数**：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | requestId | number | 是 | 延迟挂起的请求ID。 |

- **返回值**：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;number&gt; | 指定的Promise回调方法。返回应用程序进入挂起状态之前的剩余时间，以毫秒为单位。 |

- **示例**：
  ```
  let id = 1;
  backgroundTaskManager.getRemainingDelayTime(id).then( res => {
      console.log('promise => Operation succeeded. Data: ' + JSON.stringify(res));
  }).catch( err => {
      console.log('promise => Operation failed. Cause: ' + err.data);
  })
  ```


## backgroundTaskManager.cancelSuspendDelay

cancelSuspendDelay(requestId: number): void

取消延迟挂起。

- **参数**：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | requestId | number | 是 | 延迟挂起的请求ID。 |

- **示例**：
  ```
  backgroundTaskManager.cancelSuspendDelay(id);
  ```


#### DelaySuspendInfo

延迟挂起信息。

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| requestId | number | 是 | 延迟挂起的请求ID。 |
| actualDelayTime | number | 是 | 应用的实际挂起延迟时间，以毫秒为单位。<br/>一般情况下默认值为180000，低电量（依据系统低电量广播）时默认值为60000。 |

