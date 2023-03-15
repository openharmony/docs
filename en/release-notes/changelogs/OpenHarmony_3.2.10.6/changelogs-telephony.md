# Telephony Subsystem Changelog



## cl.telephony.1 Radio Module API Change


### Changed the `isNrSupported` API in the radio module of the telephone subsystem:

NR is a proper noun and must be capitalized.

You need to adapt your application.



**Change Impacts**

The JS API needs to be adapted for applications developed based on earlier versions. Otherwise, relevant functions will be affected.



**Key API/Component Changes**

- Involved APIs:

  isNrSupported(): boolean;
  isNrSupported(slotId: number): boolean;

- Before change:

```js
function isNrSupported(): boolean;
function isNrSupported(slotId: number): boolean;
```

- After change:

```js
function isNRSupported(): boolean;
function isNRSupported(slotId: number): boolean;
```



**Adaptation Guide**

Use the new API. The sample code is as follows:

```js
let result = radio.isNrSupported();
console.log("Result: "+ result);
```


```js
let slotId = 0;
let result = radio.isNRSupported(slotId);
console.log("Result: "+ result);
```
