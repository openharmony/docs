# UI框架（JS）开发常见问题



## 如何取出xml文件中对应的字段

适用于：OpenHarmony SDK 3.2.3.5版本， API9 Stage模型

convertxml中convert方法提供了转换xml文本为JavaScript对象的能力。

示例：

  
```
import convertxml from '@ohos.convertxml';
// xml格式的字符串
let xml =
  '<?xml version="1.0" encoding="utf-8"?>' +
  '<note importance="high" logged="true">' +
  '    <title>Happy</title>' +
  '    <todo>Work</todo>' +
  '    <todo>Play</todo>' +
  '</note>';
let conv = new convertxml.ConvertXML();
// 转换选项, 参考文档使用
let options = {
  trim: false,
  declarationKey: "_declaration",
  instructionKey: "_instruction",
  attributesKey: "_attributes",
  textKey: "_text",
  cdataKey: "_cdata",
  doctypeKey: "_doctype",
  commentKey: "_comment",
  parentKey: "_parent",
  typeKey: "_type",
  nameKey: "_name",
  elementsKey: "_elements"
}
let result: any = conv.convert(xml, options) // 将xml文本转为JS对象
console.log('Test: ' + JSON.stringify(result))
console.log('Test: ' + result._declaration._attributes.version) // xml字符串中version字段信息console.log('Test: ' + result._elements[0]._elements[0]._elements[0]._text) // xml字符串中title字段内容
```

参考文档：[xml转换JavaScript](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-convertxml.md)

## JS、TS和eTS的区别

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

- JS：Web 的编程语言。具有轻量级，弱类型等特点。

- TS：TS是JS的超集，拓展了JS的语法。有明确的类型与更多面向对象的内容如接口，枚举等。

- eTS：OpenHarmony UI开发框架语言，是对TS的扩展，通过声明式开发范式实现UI界面。

## 如何将时间转为时分秒格式

示例：

  
```
export default class DateTimeUtil{
  /**
  * 时分秒
  */
  getTime() {
    const DATETIME = new Date()
    return this.concatTime(DATETIME.getHours(),DATETIME.getMinutes(),DATETIME.getSeconds())
  }
  /**
  * 年月日
  */
  getDate() {
    const DATETIME = new Date()
    return this.concatDate(DATETIME.getFullYear(),DATETIME.getMonth()+1,DATETIME.getDate())
  }
  /**
  * 日期不足两位补充0
  * @param value-数据值
  */
  fill(value:number) {
    return (value> 9 ? '' : '0') + value
  }
  /**
  * 年月日格式修饰
  * @param year
  * @param month
  * @param date
  */
  concatDate(year: number, month: number, date: number){
    return `${year}${this.fill(month)}${this.fill(date)}`
  }
  /**
  * 时分秒格式修饰
  * @param hours
  * @param minutes
  * @param seconds
  */
  concatTime(hours:number,minutes:number,seconds:number){
    return `${this.fill(hours)}${this.fill(minutes)}${this.fill(seconds)}`
  }
}
```
