# ArkTS子系统JS API变更Changelog

## cl.arkts.1 URLParams类append接口添加的值中包含连续空格时行为变更

**访问级别**

公开接口

**变更原因**

URLParams类append接口添加的字符串中包含连续多个空格时，连续空格会被错误处理成只转换为一个'+'，该实现不符合URL的标准。

 **变更影响**

该变更为非兼容性变更。

**起始 API Level**
9

**变更发生版本**
从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

URLParams对象的append接口。

变更前：URLParams对象使用append()方法添加键值对时，若添加的字符串中存在连续多个空格时，接口表现为将连续多个空格只转换为一个'+'。
```ts
{
    const objectParams = new url.URLParams("key=abc")
    console.log(objectParams.toString())  // "key=abc"
    objectParams.append('key1', 'd   e   f');
    console.log(objectParams.toString())  // "key=abc&key1=d+e+f"
}
```

变更后：URLParams对象使用append()方法添加键值对时，若添加的字符串中存在连续多个空格时，接口表现为将连续多个空格转换为对应空格数量的'+'。
```ts
{
    const objectParams = new url.URLParams("key=abc")
    console.log(objectParams.toString())  // "key=abc"
    objectParams.append('key1', 'd   e   f');
    console.log(objectParams.toString())  // "key=abc&key1=d+++e+++f"
}
```

**适配指导**

开发者在涉及上面append的使用场景时，在变更生效前如果对append添加的键值对做后续处理操作，变更后需针对表现不同做针对性适配。

## cl.arkts.2 URLParams类在入参字符串中包含大小写不同编码值时，toString()接口表现结果不一致变更

**访问级别**

公开接口

**变更原因**

URLParams类在入参字符串中包含大小写不同编码值时toString()接口返回值有误，主要涉及："%2b"和"%2B"的表现不一致，"%2B"被处理为"%2B"是符合标准的，但"%2b"会被错误处理'+'。

 **变更影响**

该变更为非兼容性变更。

**起始 API Level**
9

**变更发生版本**
从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

URL模块URLParams类toString接口，

变更前：创建URLParams对象，如果入参字符串中存在"%2b"和"%2B"时，在toString()后返回的字符串分别表现为"+"和"%2B"。
```ts
{
    const objectParams = new url.URLParams("key%2b=abc%2B")
    console.log(objectParams.toString())  // "key+=abc%2B"
}
```

变更后：创建URLParams对象，如果入参字符串中存在"%2b"和"%2B"时，在toString()后返回的字符串均表现为"%2B";
```ts
{
    const objectParams = new url.URLParams("key%2b=abc%2B")
    console.log(objectParams.toString())  // "key%2B=abc%2B"
}
```

**适配指导**

开发者在涉及上述使用场景时，在变更生效前如果对toString()返回值做后续处理操作，变更后需针对表现不同做针对性适配。

## cl.arkts.3 URLParams类append接口行为变更

**访问级别**

公开接口

**变更原因**

URLParams使用append()方法时，对入参键值对中的特殊字符会错误进行encode，该行为与URL标准不一致，导致后续对键值对进行增删改查等操作出现异常。

 **变更影响**

该变更为非兼容性变更。

**起始 API Level**
9

**变更发生版本**
从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

URLParams类append接口。

变更前：URLParams使用append()方法添加键值对, 若想通过添加的key使用get、has、delete、set接口进行增删改查操作，需先对key进行额外encode。
```ts
{
    const objectParams = new url.URLParams('?fod=1&bard=2')
    objectParams.append("key&大", "abc");
    objectParams.has('key&大');  // false
    objectParams.has('%E5%A4%A7');  // true
    objectParams.get('key&大');  // undefined
    objectParams.get('%E5%A4%A7');  // abc
}
```

变更后: URLParams使用append()方法添加键值对,可直接使用添加的key拿到对应value进行增删改查操作。
```ts
{
    const objectParams = new url.URLParams('?fod=1&bard=2')
    objectParams.append("key&大", "abc");
    objectParams.has('key&大');  // true
    objectParams.has('%E5%A4%A7');  // false
    objectParams.get('key&大');  // abc
    objectParams.get('%E5%A4%A7');  // undefined
}
```

**适配指导**

开发者在涉及上述append的使用场景时，在变更生效前如果对append添加的键值对做后续处理操作，如使用encode过的key进行增删改查，变更后则需去除多余encode操作进行针对性适配。
