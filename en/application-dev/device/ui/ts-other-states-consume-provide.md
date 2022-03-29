# @Consume and @Provide


As the data provider, @Provide can update the data of child nodes and trigger page rendering. After @Consume detects that the @Provide data is updated, it will initiate re-rendering of the current view.


  Table1 @Provide

| Name | Description | 
| -------- | -------- |
| Decorator parameter | A constant of the string type, which is used to set an alias for a decorated variable. If an alias is specified, implement the data update for this alias. If there is no alias, use the variable name as the alias. @Provide("_alias_") is recommended. | 
| Synchronization mechanism | The @Provide decorated variable is similar to the @state variable. You can modify the variable to re-render the page. You can also modify the @Consume decorated variable to modify the @State decorated variable reversely. | 
| Initial value | The initial value must be set. | 
| Page re-rendering scenarios | The following will trigger page re-rendering:<br/>- Changes of variables in primitive types (boolean, string, and number)<br/>- Changes of the @Observed decorated classes or their attributes<br/>- Adding, deleting, or updatingelements in an array | 


  Table2 @Consume

| Type | Description | 
| -------- | -------- |
| Initial value | No default value can be set. | 


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**:
> To avoid infinite loops caused by circular reference, exercise caution when using @Provide and @Consume.


The description of other attributes is the same as that of @Provide.


  
```
@Entry
@Component
struct CompA {
    @Provide("reviewVote") reviewVotes : number = 0;

    build() {
        Column() {
            CompB()
            Button() {
                Text(`${this.reviewVotes}`)
                    .fontSize(30)
            }
            .onClick(() => {
                this.reviewVotes += 1;
            })
        }
    }
}

@Component
struct CompB {
    build() {
        Column() {
            CompC()
        }
    }
}

@Component
struct CompC {
    @Consume("reviewVote") reviewVotes : number;
    build() {
        Column() {
            Button() {
                Text(`${this.reviewVotes}`)
                    .fontSize(30)
            }
            .onClick(() => {
                this.reviewVotes += 1;
            })
        }
    }
}
```
