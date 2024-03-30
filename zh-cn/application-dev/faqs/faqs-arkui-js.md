# ArkUI框架开发常见问题(JS)


## input组件是否支持设置文本居中对齐(API 9)

适用于FA模型。

**问题现象**

input组件中输入的文本如何实现文本居中对齐格式，使用text-align没有效果。

**解决措施**

input组件属于类web范式组件，不_支_持设置文本对齐方式，text-align样式只针对text组件生效。

**参考链接**

[input组件](../reference/apis-arkui/arkui-js/js-components-basic-input.md)，[text组件](../reference/apis-arkui/arkui-js/js-components-basic-text.md)


## 如何判断JS对象中是否存在某个值(API 9)

**解决措施**

Object.values(对象名).indexOf(想要判断的值)，若返回-1表示不包含对应值，返回值不等于-1则表示包含。


## 用数组变量控制组件属性不生效(API 8)

目前类web范式对数组中元素的修改不会被监听，因此不会触发页面刷新，需要产生数组对象的修改才可以触发页面刷新。所以，使用test1\(\)对修改数组的引用时，button组件会被禁用，使用test2\(\)修改数组中某个元素，对控制button组件disabled属性的数组单元赋值，button组件并不会被禁用。除了test1\(\)中对数组整体赋值，我们还可以使用修改数组的方法，如splice\(\)，也可以达到页面刷新的效果。

```
test1() {this.isDisabled = [true, true, true, true, true]; //该语句可实现对button组件的禁用
test2() {this.isDisabled[0] = true; //该语句对button组件的禁用不生效
```

## 系统兼容TS语言进行开发，目前是哪个TS版本？后续会更新TS和JS的新特性吗？(API 11)

**规格澄清**

目前在API 11支持到TS 4.9.5版本，支持ECMAScript 2017；未来会持续升级TS以及JS版本。
