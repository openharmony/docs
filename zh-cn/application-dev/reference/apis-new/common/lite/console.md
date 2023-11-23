# console    
本模块提供了一个简单的调试控制台，类似于浏览器提供的JavaScript控制台机制。  
> **说明**   
>本模块首批接口从API version -1开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## console    
### debug    
以格式化输出方式打印调试信息。从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **调用形式：**     
- static debug(message: string): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message | string | true | 表示要打印的文本信息。 |  
    
 **示例代码：**   
```js    
const number = 5;console.debug('count: %d', number);  // 格式化输出替换message中的文本。// count: 5 console.debug('count:', number);  // 打印message以及其余信息// count: 5 console.debug('count:'); // 仅打印message// count:    
```    
  
    
### log    
以格式化输出方式打印日志信息。从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **调用形式：**     
- static log(message: string): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message | string | true | 表示要打印的文本信息。 |  
    
 **示例代码：**   
```js    
const number = 5;console.log('count: %d', number);  // 格式化输出替换message中的文本。// count: 5 console.log('count:', number);  // 打印message以及其余信息// count: 5 console.log('count:'); // 仅打印message// count:    
```    
  
    
### info    
以格式化输出方式打印日志信息。(console.log()的别名）。从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **调用形式：**     
- static info(message: string): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message | string | true | 表示要打印的文本信息。 |  
    
 **示例代码：**   
```js    
const number = 5;console.info('count: %d', number);  // 格式化输出替换message中的文本。// count: 5 console.info('count:', number);  // 打印message以及其余信息// count: 5 console.info('count:'); // 仅打印message// count:    
```    
  
    
### warn    
以格式化输出方式打印警告信息。从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **调用形式：**     
- static warn(message: string): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message | string | true | 表示要打印的警告信息。 |  
    
 **示例代码：**   
```js    
const str = "name should be string";console.warn('warn: %d', str);  // 格式化输出替换message中的文本。// warn: name should be stringconsole.warn('warn:', str);  // 打印message以及其余信息// warn: name should be stringconsole.warn('warn:'); // 仅打印message// warn:    
```    
  
    
### error    
以格式化输出方式打印错误信息。从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **调用形式：**     
- static error(message: string): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message | string | true | 表示要打印的错误信息。 |  
    
 **示例代码：**   
```js    
const str = "value is not defined";console.error('error: %d', str);  // 格式化输出替换message中的文本。// error: value is not definedconsole.error('error:', str);  // 打印message以及其余信息// error: value is not definedconsole.error('error:'); // 仅打印message// error:    
```    
  
