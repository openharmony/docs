# 必选参数构造配置


如果组件的接口定义中包含必选构造参数，则在组件后面的“()”中必须配置参数，参数可以使用常量进行赋值。


例如：


- Image组件的必选参数src：
  ```
  Image('http://xyz/a.jpg')
  ```


- Text组件的必选参数content：
  ```
  Text('123')
  ```


变量或表达式也可以用于参数赋值，其中表达式返回的结果类型必须满足参数类型要求。例如，传递变量或表达式来构造Image和Text组件的参数：


```
// imagePath, where imageUrl is a private data variable defined in the component.
Image(this.imagePath)
Image('http://' + this.imageUrl)
// count is a private data variable defined in the component.
// (``) and (${}) are the template character string features supported by the TS language and comply with the
// features of the corresponding language. This specification is not limited.
Text(`count: ${this.count}`)
```
