# ArkUI (JavaScript) Development

## How do I convert the fields in an XML file into JavaScript objects?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

To convert fields in an XML file into JavaScript objects, call the **convert** API in the **convertxml** module.

Example:


```
import convertxml from '@ohos.convertxml';
// XML strings
let xml =
  '<?xml version="1.0" encoding="utf-8"?>' +
  '<note importance="high" logged="true">' +
  '    <title>Happy</title>' +
  '    <todo>Work</todo>' +
  '    <todo>Play</todo>' +
  '</note>';
let conv = new convertxml.ConvertXML();
// Options for conversion. For details, see the reference document.
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
let result: any = conv.convert(xml, options) // Convert fields in the XML file into JavaScript objects.
console.log('Test: ' + JSON.stringify(result))
console.log('Test: ' + result._declaration._attributes.version) // version field in the XML file
console.log('Test: ' + result._elements[0]._elements[0]._elements[0]._text) // title field in the XML file
```

For details, see [XML-to-JavaScript Conversion](../reference/apis/js-apis-convertxml.md).

## How do I convert the time to the HHMMSS format?

Example:


```
export default class DateTimeUtil{
  /**
  * HHMMSS
  */
  getTime() {
    const DATETIME = new Date()
    return this.concatTime(DATETIME.getHours(),DATETIME.getMinutes(),DATETIME.getSeconds())
  }
  /**
  * YYYYMMDD
  */
  getDate() {
    const DATETIME = new Date()
    return this.concatDate(DATETIME.getFullYear(),DATETIME.getMonth()+1,DATETIME.getDate())
  }
  /**
  * If the date is less than 10, add a leading zero, for example, **07**.
  * @param value Indicates the value.
  */
  fill(value:number) {
    return (value> 9 ? '' : '0') + value
  }
  /**
  * Concatenate year, month, and date fields.
  * @param year
  * @param month
  * @param date
  */
  concatDate(year: number, month: number, date: number){
    return `${year}${this.fill(month)}${this.fill(date)}`
  }
  /**
  Concatenate hours, minutes, and seconds fields.
  * @param hours
  * @param minutes
  * @param seconds
  */
  concatTime(hours:number,minutes:number,seconds:number){
    return `${this.fill(hours)}${this.fill(minutes)}${this.fill(seconds)}`
  }
}

```
