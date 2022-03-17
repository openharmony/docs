# 页面路由

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```
import router from '@system.router';
```

## router.push

push(Object): void

跳转到应用内的指定页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 表示目标页面的uri，可以用以下两种格式：<br/>-&nbsp;页面绝对路径，由配置文件中pages列表提供，例如：<br/>&nbsp;&nbsp;-&nbsp;pages/index/index<br/>&nbsp;&nbsp;-&nbsp;pages/detail/detail<br/>-&nbsp;特殊值，如果uri的值是"/"，则跳转到首页。 |
| params | Object | 否 | 跳转时要同时传递到目标页面的数据，跳转到目标页面后，参数可以在页面中直接使用，如this.data1(data1为跳转时params参数中的key值)。如果目标页面中已有该字段，则其值会被传入的字段值覆盖。 |

**示例：**

```
// 在当前页面中
export default {
  pushPage() {
    router.push({
      uri: 'pages/routerpage2/routerpage2',
      params: {
        data1: 'message',
        data2: {
          data3: [123, 456, 789]
	},
      },
    });
  }
}
```


```
// 在routerpage2页面中
export default {
  data: {
    data1: 'default',
    data2: {
      data3: [1, 2, 3]
    }
  },
  onInit() {
    console.info('showData1:' + this.data1);
    console.info('showData3:' + this.data2.data3);
  }
}
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 页面路由栈支持的最大Page数量为32。


## router.replace

replace(Object): void

用应用内的某个页面替换当前页面，并销毁被替换的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 目标页面的uri，可以是以下的两种格式：<br/>-&nbsp;页面绝对路径，由配置文件中pages列表提供，例如：<br/>&nbsp;&nbsp;-&nbsp;pages/index/index<br/>&nbsp;&nbsp;-&nbsp;pages/detail/detail<br/>-&nbsp;特殊值，如果uri的值是"/"，则跳转到首页。 |
| params | Object | 否 | 跳转时要同时传递到目标页面的数据，跳转到目标页面后，参数可以在页面中直接使用，如this.data1(data1为跳转时params参数中的key值)。如果目标页面中已有该字段，则其值会被传入的字段值覆盖。 |

**示例：**

```
// 在当前页面中
export default {
  replacePage() {
    router.replace({
      uri: 'pages/detail/detail',
      params: {
        data1: 'message',
      },
    });
  }
}
```


```
// 在detail页面中
export default {
  data: {
    data1: 'default'
  },
  onInit() {
    console.info('showData1:' + this.data1)
  }
}
```

## router.back

back(Object): void

返回上一页面或指定的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 否 | 返回到指定uri的界面，如果页面栈上没有uri页面，则不响应该情况。如果uri未设置，则返回上一页。 |
| params | Object | 否 | 跳转时要同时传递到目标页面的数据 |

**示例：**

```
// index页面
export default {    
  indexPushPage() {        
    router.push({            
      uri: 'pages/detail/detail',        
    });        
  }
}
```


```
// detail页面
export default {    
  detailPushPage() {        
    router.push({            
      uri: 'pages/mall/mall',        
    });    
  }
}
```


```
// mall页面通过back，将返回detail页面
export default {    
  mallBackPage() {        
    router.back();    
  }
}
```


```
// detail页面通过back，将返回index页面
export default {    
  defaultBack() {        
    router.back();    
  }
}
```


```
// 通过back，返回到detail页面
export default {    
  backToDetail() {        
    router.back({uri:'pages/detail/detail'});    
  }
}
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 示例中的uri字段是页面路由，由配置文件中的pages列表指定。

## router.clear

clear(): void

清空页面栈中的所有历史页面，仅保留当前页面作为栈顶页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```
export default {    
  clearPage() {        
    router.clear();    
  }
}
```

## router.getLength

getLength(): string

获取当前在页面栈内的页面数量。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 页面数量，页面栈支持最大数值是32。 |

**示例：**

```
export default {     
  getLength() {        
    var size = router.getLength();        
    console.log('pages stack size = ' + size);    
  }
}
```

## router.getState

getState(): &lt;RouterState&gt;

获取当前页面的状态信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**
**表1** RouterState

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| index | number | 表示当前页面在页面栈中的索引。<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**说明：**<br/>>&nbsp;从栈底到栈顶，index从1开始递增。 |
| name | string | 表示当前页面的名称，即对应文件名。 |
| path | string | 表示当前页面的路径。 |

**示例：**

```
export default {     
  getState() {        
    var page = router.getState();
    console.log('current index = ' + page.index);
    console.log('current name = ' + page.name);
    console.log('current path = ' + page.path);
  }
}
```

## router.enableAlertBeforeBackPage<sup>6+</sup>

enableAlertBeforeBackPage(Object): void

开启页面返回询问对话框。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| message | string | 是 | 询问对话框内容。 |
| success | ()&nbsp;=&gt;&nbsp;void | 否 | 接口调用成功的回调函数。 |
| fail | ()&nbsp;=&gt;&nbsp;void | 否 | 接口调用失败的回调函数。 |
| complete | ()&nbsp;=&gt;&nbsp;void | 否 | 接口调用结束的回调函数。 |

**示例：**

```
export default {    
  enableAlertBeforeBackPage() {        
    router.enableAlertBeforeBackPage({            
      message: 'Message Info',            
      success: function() {                
        console.log('success');            
      },            
      fail: function() {                
        console.log('fail');            
      },        
    });    
  }
}
```

## router.disableAlertBeforeBackPage<sup>6+</sup>

disableAlertBeforeBackPage(Object): void

禁用页面返回询问对话框。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| success | ()&nbsp;=&gt;&nbsp;void | 否 | 接口调用成功的回调函数。 |
| fail | ()&nbsp;=&gt;&nbsp;void | 否 | 接口调用失败的回调函数。 |
| complete | ()&nbsp;=&gt;&nbsp;void | 否 | 接口调用结束的回调函数。 |

**示例：**

```
export default {    
  disableAlertBeforeBackPage() {        
    router.disableAlertBeforeBackPage({            
      success: function() {                
        console.log('success');            
      },            
      fail: function() {                
        console.log('fail');            
      },        
    });    
  }
}
```

