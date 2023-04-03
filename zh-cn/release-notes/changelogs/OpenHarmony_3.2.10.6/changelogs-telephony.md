# 电话子系统ChangeLog



## cl.telephony.1 radio模块接口变更


### 电话子系统radio模块 `isNrSupported` 接口存在变更：

NR是专有名词，需要全部大写。

开发者需要根据以下说明对应用进行适配。



**变更影响**

基于此前版本开发的应用，需适配变更的js接口，变更前的接口已经不能正常使用了，否则会影响原有功能。



**关键的接口/组件变更**

- 涉及接口

  isNrSupported(): boolean;
  isNrSupported(slotId: number): boolean;

- 变更前：

```js
function isNrSupported(): boolean;
function isNrSupported(slotId: number): boolean;
```

- 变更后：

```js
function isNRSupported(): boolean;
function isNRSupported(slotId: number): boolean;
```



**适配指导**

使用变更后的接口，示例代码如下：

```js
let result = radio.isNrSupported();
console.log("Result: "+ result);
```


```js
let slotId = 0;
let result = radio.isNRSupported(slotId);
console.log("Result: "+ result);
```
