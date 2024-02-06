# 支持单复数

翻译过程中，不同语言，对于名词或单位表达式的单复数格式要求有所不用，有些语言不区分单复数，有些语言有两种形式，有些语言有多种形式。例如，在英语中，名词支持单复数两种形式；在中文，名词不分单复数，通过量词表达数量的不同。

国际上常通过如下类别区分单复数：

- zero ：0或者0结尾

- one：单数或者1结尾

- two：2结尾

- few：数值较小的数

- many：数值较大的数

- other：其他情况

举例，在阿拉伯语中，单复规则如下：

- zero ：0

- one：1

- two：2

- few：3 ~ 10、103 ~ 110，1003...

- many：11 ~ 26、111，1011...

- other：100 ~ 102、200 ~ 202、1000、10000...

## 开发步骤

接口具体使用方法请参考[getPluralStringValueSync](../reference/apis-localization-kit/js-apis-resource-manager.md#getpluralstringvaluesync10)的API接口文档。

```ts
import { BusinessError } from '@ohos.base'; 

try {  
  this.context.resourceManager.getPluralStringByNameSync("test", 1);} 
catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getPluralStringByNameSync failed, error code: ${code}, message: ${message}.`);
}
```
