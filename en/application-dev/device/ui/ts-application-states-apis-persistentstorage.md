# PersistentStorage


ArkUI provides some static methods in the PersistentStorage class for managing persistent data of applications. Persistent data with specific tags can be linked to the AppStorage, and then the persistent data can be accessed through the AppStorage APIs. Alternatively, the @StorageLink decorator can be used to access the variable of the specific key.


| Name | Type | Return Value | Definition |
| -------- | -------- | -------- | -------- |
| PersistProp | key : string<br/>defaultValue: T | void | Changes the associated named attribute to persistent data in the AppStorage. The value overwriting sequence is as follows:<br/>- If the attribute exists in the AppStorage, use it to overwrite the value in Persistent.<br/>- If Persistent contains the specified attribute, use the attribute value in Persistent.<br/>- If the preceding conditions are not met, use defaultValue. The values null and undefined are not supported. |
| DeleteProp | key: string | void | Cancels two-way binding. The value of this attribute will be deleted from the persistent storage. |
| PersistProps | keys: {<br/>key: string,<br/>defaultValue: any<br/>}[] | void | Associates multiple named attribute bindings. |
| Keys | void | Array &lt;string&gt; | Returns the flags of all persistent attributes. |


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**:
> - When using PersistProp, ensure that the input key exists in the AppStorage.
> 
> - DeleteProp takes effect only for the data that has been linked during the current startup.



```
PersistentStorage.PersistProp("highScore", "0");

@Entry
@Component
struct PersistentComponent {
    @StorageLink('highScore') highScore: string = '0'
    @State currentScore: number = 0
    build() {
        Column() {
            if (this.currentScore === Number(this.highScore)) {
                Text(`new highScore : ${this.highScore}`)
            }
            Button() {
                Text(`goal!, currentScore : ${this.currentScore}`)
                    .fontSize(10)
            }.onClick(() => {
                this.currentScore++
                if (this.currentScore > Number(this.highScore)) {
                    this.highScore = this.currentScore.toString()
                }
            })
        }
    }
}
```
