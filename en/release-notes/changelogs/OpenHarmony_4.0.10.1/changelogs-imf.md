# Input Method Framework Subsystem – Input Method Framework Service Changelog

## cl.imf.1 Addition of Synchronous APIs for InputClient

The synchronous APIs listed below are added.

| API                                          | Description                    |
| ---------------------------------------------- | ------------------------ |
| getForwardSync(length:number): string          | Obtains the specific-length text before the cursor.|
| getBackwardSync(length:number): string         | Obtains the specific-length text after the cursor.|
| deleteForwardSync(length:number): void         | Deletes the fixed-length text before the cursor.|
| deleteBackwardSync(length:number): void        | Deletes the fixed-length text after the cursor.|
| insertTextSync(text: string): void             | Inserts text.                |
| getEditorAttributeSync(): EditorAttribute      | Obtains the attribute of the edit box.        |
| moveCursorSync(direction: number): void        | Moves the cursor.                |
| selectByRangeSync(range: Range): void          | Selects text based on the specified range.    |
| selectByMovementSync(movement: Movement): void | Selects text based on the cursor movement direction.|
| getTextIndexAtCursorSync(): number             | Obtains the index of the text where the cursor is located.|

**Change Impact**

The preceding APIs are synchronous APIs.

**Adaptation Guide**

Follow the description in [@ohos.inputMethodEngine.d.ts](../../../application-dev/reference/apis/js-apis-inputmethodengine.md)
