# ArkUI子系统changelog

## NavPathStack navigation.d.ts内NavPathStack类中非兼容性变更

**关键的接口/组件变更**

方法名称从push，pushName，popTo变更为pushPath，pushPathByName，popToName

**变更影响**

更新4.0.10.x sdk之后，如果代码未变更方法名称，将出现编译报错。   
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