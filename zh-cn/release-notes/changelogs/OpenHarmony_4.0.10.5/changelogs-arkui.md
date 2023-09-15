# arkui子系统ChangeLog

## cl.arkui.1 NavPathStack类中的方法名称变更

**关键接口/组件变更**

[NavPathStack](../../../application-dev/reference/arkui-ts/ts-basic-components-navigation.md#navpathstack10)  
|  变更前   | 变更后  |
|  ----  | ----  |
| push  | pushPath |
| pushName  | pushNameByPath |
| popTo| PopToName |

**变更影响**

更新4.0.10.x SDK之后，如果代码未变更方法名称，将出现编译报错。   
Property 'push' does not exist on type 'NavPathStack'.   
Property 'pushName' does not exist on type 'NavPathStack'.   
Property 'pop' does not exist on type 'NavPathStack'.   

**适配指导**   

需更新应用代码

```ts
navPathStack = new NavPathStack();
this.navPathStack.push(...)
this.navPathStack.pushPath(...)

this.navPathStack.pushName('navidesnation_add',this.value)
this.navPathStack.pushPathByName('navidesnation_add',this.value) 

this.navPathStack.pop('navidesnation_add')
this.navPathStack.popToName('navidesnation_add')
```