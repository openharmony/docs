# 输入法框架子系统-输入法框架ChangeLog

## cl.imf.1 @ohos.InputMethodEngine中，InputClient新增同步接口

新增同步接口如下：

| 接口                                           | 说明                     |
| ---------------------------------------------- | ------------------------ |
| getForwardSync(length:number): string          | 获取光标前固定长度的文本 |
| getBackwardSync(length:number): string         | 获取光标后固定长度的文本 |
| deleteForwardSync(length:number): void         | 删除光标前固定长度的文本 |
| deleteBackwardSync(length:number): void        | 删除光标后固定长度的文本 |
| insertTextSync(text: string): void             | 插入文本                 |
| getEditorAttributeSync(): EditorAttribute      | 获取编辑框属性值         |
| moveCursorSync(direction: number): void        | 移动光标                 |
| selectByRangeSync(range: Range): void          | 根据索引范围选中文本     |
| selectByMovementSync(movement: Movement): void | 根据光标移动方向选中文本 |
| getTextIndexAtCursorSync(): number             | 获取光标所在处的文本索引 |

**变更影响**

以上接口的调用，均为同步接口。

**适配指导**

请参考接口说明：[@ohos.inputMethodEngine.d.ts](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-inputmethodengine.md)
