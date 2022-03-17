# 媒体查询


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```
import mediaquery from '@system.mediaquery';
```


## mediaquery.matchMedia

matchMedia(condition: string): &lt;MediaQueryList&gt;

根据媒体查询条件，创建MediaQueryList对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| condition | string | 是 | 用于查询的条件。 |

**返回值：**
**表1** MediaQueryList

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| MediaQueryList | Object | 表示创建MediaQueryList对象的属性，详情见下表 MediaQueryList说明。 |

**示例：**

```
export default {    
  matchMedia() {        
    var mMediaQueryList = mediaquery.matchMedia('(max-width: 466)');    
  },
}
```

  **表2** MediaQueryList说明

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| matches | boolean | 如果查询条件匹配成功则返回true，否则返回值为false。只读。 |
| media | string | 序列化的媒体查询条件，只读。 |
| onchange | Function | matches状态变化时的执行函数。 |


## MediaQueryList.addListener

addListener(Object): void

给MediaQueryList添加回调函数，回调函数应在onShow生命周期之前添加，即需要在onInit或onReady生命周期里添加。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Function | 是 | 匹配条件发生变化的响应函数。 |

**示例：**

```
export default {
  onReady() {
    var mMediaQueryList = mediaquery.matchMedia('(max-width: 466)');
    function maxWidthMatch(e) {
      if (e.matches) {
        // do something
      }
    }
    mMediaQueryList.addListener(maxWidthMatch);
  },
}
```


## MediaQueryList.removeListener

removeListener(Object): void

移除MediaQueryList中的回调函数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Function | 是 | 匹配条件发生变化的响应函数。 |

**示例：**

```
query.removeListener(minWidthMatch);
```