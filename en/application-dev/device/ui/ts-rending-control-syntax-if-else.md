# if/else


Use if/else for conditional rendering.


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**:
> - State variables can be used in the if conditional statement.
> 
> - You can use the if conditional statement to implement rendering of child components.
> 
> - The if conditional statement must be used in container components.
> 
> - Some container components limit the type or number of child components. When if is placed in these components, the limitation applies to components created in if and else statements. For example, when if is used in the &lt;Grid&gt; component, whose child components can only be &lt;GridItem&gt;, only the &lt;GridItem> component can be used in the if conditional statement.


## Example

Example of using the if conditional statement:


```
Column() {
    if (this.count > 0) {
        Text('count is positive')
    }
}
```


Example of using the if, else if, and else conditional statements:



```
Column() {
    if (this.count < 0) {
        Text('count is negative')
    } else if (this.count % 2 === 0) {
        Divider()
        Text('even')
    } else {
        Divider()
        Text('odd')
    }
}
```
