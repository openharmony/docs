# if/else<a name="EN-US_TOPIC_0000001110948888"></a>

Use  **if/else**  for conditional rendering.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The  **if**  conditional statement can use state variables.
>-   You can use  **if**  to make the rendering of a child component depend on the conditional statement.
>-   The  **if**  conditional statement must be used in container components.
>-   Some container components limit the type or number of child components. When  **if**  is placed in these components, the limitation applies to components created in  **if**  and  **else**  statements. For example, when  **if**  is used in the  **<Grid\>**  component, only the  **<GridItem\>**  component can be used in the  **if**  conditional statement, and only the  **<ListItem\>**  component can be used in the  **<List\>**  component.

## Example<a name="section917781203210"></a>

Sample code for using the  **if**  conditional statement:

```
Column() {
    if (this.count > 0) {
        Text('count is positive')
    }
}
```

Sample code for using the  **if**,  **else if**, and  **else**  conditional statements:

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

