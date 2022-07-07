# 页面路由

本模块提供通过不同的url访问不同的页面，包括跳转到应用内的指定页面、用应用内的某个页面替换当前页面、返回上一页面或指定的页面等。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明**
>
> - 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 页面路由需要在页面渲染完成之后才能调用，在onInit和onReady生命周期中页面还处于渲染阶段，禁止调用页面路由方法。

## 导入模块

```
import router from '@ohos.router'
```

## 权限列表

无

## router.push

push(options: RouterOptions): void

跳转到应用内的指定页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [RouterOptions](#routeroptions) | 是 | 跳转页面描述信息。 |
| mode<sup>9+</sup> | [RouterMode](#routermode9) | 否 | 跳转页面使用的模式。 |


**示例：**
  ```js
  // 在当前页面中
  export default {
    pushPage() {
      router.push({
        url: 'pages/routerpage2/routerpage2',
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
  ```js
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


## router.replace

replace(options: RouterOptions): void

用应用内的某个页面替换当前页面，并销毁被替换的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [RouterOptions](#routeroptions) | 是 | 替换页面描述信息。 |
| mode<sup>9+</sup> | [RouterMode](#routermode9) | 否 | 跳转页面使用的模式。 |

**示例：**

  ```js
  // 在当前页面中
  export default {
    replacePage() {
      router.replace({
        url: 'pages/detail/detail',
        params: {
          data1: 'message',
        },
      }, router.RouterMode.Standard);
    }
  }
  ```

  ```js
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

back(options?: RouterOptions ): void

返回上一页面或指定的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [RouterOptions](#routeroptions) | 是 | 返回页面描述信息，其中参数url指路由跳转时会返回到指定url的界面，如果页面栈上没有url页面，则不响应该情况。如果url未设置，则返回上一页。 |

**示例：**
  ```js
  // index页面
  export default {    
    indexPushPage() {        
      router.push({            
        url: 'pages/detail/detail',        
      });        
    }
  }
  ```

  ```js
  // detail页面
  export default {    
    detailPushPage() {        
      router.push({            
        url: 'pages/mall/mall',        
      });    
    }
  }
  ```

  ```js
  // mall页面通过back，将返回detail页面
  export default {    
    mallBackPage() {        
      router.back();    
    }
  }
  ```

  ```js
  // detail页面通过back，将返回index页面
  export default {    
    defaultBack() {        
      router.back();    
    }
  }
  ```

  ```js
  // 通过back，返回到detail页面
  export default {    
    backToDetail() {        
      router.back({uri:'pages/detail/detail'});    
    }
  }
  ```

## router.clear

clear(): void

清空页面栈中的所有历史页面，仅保留当前页面作为栈顶页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**
  ```js
  export default {    
    clearPage() {        
      router.clear();    
    }
  }js
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
  ```js
  export default {     
    getLength() {        
      var size = router.getLength();        
      console.log('pages stack size = ' + size);    
    }
  }
  ```

## router.getState

getState(): RouterState

获取当前页面的状态信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| [RouterState](#routerstate) | 页面状态信息。 |
## RouterState
页面状态信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.ArkUI.ArkUI.Full。

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| index | number | 表示当前页面在页面栈中的索引。<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**说明：**<br/>>&nbsp;从栈底到栈顶，index从1开始递增。 |
| name | string | 表示当前页面的名称，即对应文件名。 |
| path | string | 表示当前页面的路径。 |

**示例：**
  ```js
  export default {     
    getState() {        
      var page = router.getState();
      console.log('current index = ' + page.index);
      console.log('current name = ' + page.name);
      console.log('current path = ' + page.path);
    }
  }
  ```

## router.enableAlertBeforeBackPage

enableAlertBeforeBackPage(options: EnableAlertOptions): void

开启页面返回询问对话框。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [EnableAlertOptions](#enablealertoptions) | 是 | 文本弹窗信息描述。 |

**示例：**

  ```js
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
## EnableAlertOptions

页面返回询问对话框选项。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.ArkUI.ArkUI.Full。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| message | string | 是 | 询问对话框内容。 |

## router.disableAlertBeforeBackPage

disableAlertBeforeBackPage(): void

禁用页面返回询问对话框。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**
  ```js
  export default {    
    disableAlertBeforeBackPage() {        
      router.disableAlertBeforeBackPage();    
    }
  }
  ```

##  router.getParams

getParams(): Object

获取发起跳转的页面往当前页传入的参数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型   | 说明                               |
| ------ | ---------------------------------- |
| Object | 发起跳转的页面往当前页传入的参数。 |

**示例：**

- 类Web范示例
  ```js
  // 在当前页面中
  export default {
    pushPage() {
      router.push({
        url: 'pages/detail/detail',
        params: {
          data1: 'message',
        },
      });
    }
  }
  ```
  ```js
  // 在detail页面中
  export default {
    onInit() {
      console.info('showData1:' + router.getParams().data1);
    }
  }
  ```

- 声明式示例

  ```ts
  //通过router.push跳转至目标页携带params参数
  import router from '@ohos.router'
  
  @Entry
  @Component
  struct Index {
    async  routePage() {
      let options = {
        url: 'pages/second',
        params: {
          text: '这是第一页的值',
          data: {
            array: [12, 45, 78]
          },
        }
      }
      try {
        await router.push(options)
      } catch (err) {
        console.info(` fail callback, code: ${err.code}, msg: ${err.msg}`)
      }
    }
  
    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Text('这是第一页')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        Button() {
          Text('next page')
            .fontSize(25)
            .fontWeight(FontWeight.Bold)
        }.type(ButtonType.Capsule)
            .margin({ top: 20 })
            .backgroundColor('#ccc')
            .onClick(() => {
              this.routePage()
        })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ```ts
  //在second页面中接收传递过来的参数
  import router from '@ohos.router'
  
  @Entry
  @Component
  struct Second {
    private content: string = "这是第二页"
    @State text: string = router.getParams()['text']
    @State data: any = router.getParams()['data']
    @State secondData : string = ''
    
    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Text(`${this.content}`)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Text(this.text)
          .fontSize(30)
          .onClick(()=>{
            this.secondData = (this.data.array[1]).toString()
          })
        .margin({top:20})
        Text('第一页传来的数值' + '  ' + this.secondData)
          .fontSize(20)
          .margin({top:20})
          .backgroundColor('red')      
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

## RouterOptions

路由跳转选项。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.ArkUI.ArkUI.Lite。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| url | string | 是 | 表示目标页面的uri，可以用以下两种格式：<br/>-&nbsp;页面绝对路径，由配置文件中pages列表提供，例如：<br/>&nbsp;&nbsp;-&nbsp;pages/index/index<br/>&nbsp;&nbsp;-&nbsp;pages/detail/detail<br/>-&nbsp;特殊值，如果uri的值是"/"，则跳转到首页。 |
| params | Object | 否 | 跳转时要同时传递到目标页面的数据，跳转到目标页面后，参数可以在页面中直接使用，如this.data1(data1为跳转时params参数中的key值)。如果目标页面中已有该字段，则其值会被传入的字段值覆盖。 |


  > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
  > 页面路由栈支持的最大Page数量为32。

## RouterMode<sup>9+</sup>

路由跳转模式。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.ArkUI.ArkUI.Lite。

| 名称 | 描述 |
| -------- | -------- |
| Standard | 标准模式。 |
| Single | 单实例模式。<br/>如果目标页面的url在页面栈中已经存在同url页面，离栈顶最近的页面会被移动到栈顶，移动后的页面为新建页。<br/>如目标页面的url在页面栈中不存在同url页面，按标准模式跳转。 |
