# 分布式数据管理子系统Changelog

## cl.relationalStore.1 getRow、getValue 接口行为变更

**访问级别**

公开接口

**变更原因**

在变更之前，当欲插入的列类型是blob且数据为长度为0的u8数组时，错误地给数据库中写入了null值，导致使用该接口读取时，读出来的该列类型为null。

**变更影响**

该变更为非兼容性变更，开发者调用getRow/getValue接口时， 如果之前在blob类型的列里插入了长度为0的u8数组，获取出来的值由null变成了长度为0的u8数组。

**起始 API Level**

| 名称       | 起始 API Level |
|----------|--------------|
| getRow   | API 11       |
| getValue | API 12       |

**变更发生版本**

从OpenHarmony SDK 5.0.0.39版本开始。

**变更的接口/组件**

| 名称       | 描述     |
|----------|--------|
| getRow   | 获取当前行 |
| getValue | 获取当前行中指定列的值，值类型如果是ValueType指定的任意类型，则会以对应类型返回指定类的值 |

**适配指导**

变更后，该接口的调用方式没有发生变化，开发者需要关注，在对column类型为blob且插入时传入了长度为0的u8数组的列，获取的值类型发生了变化。
获取方式如下所示：
```TypeScript
if(resultSet != undefined) {
    const row = (resultSet as relationalStore.ResultSet).getRow();
    const codes = (resultSet as relationalStore.ResultSet).getValue((resultSet as relationalStore.ResultSet).getColumnIndex("BIGINT_COLUMN"));
}
```

