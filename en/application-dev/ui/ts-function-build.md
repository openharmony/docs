# build Function


The build function meets the definition of the **Builder** API and is used to define the declarative UI description of components. Components must comply with the preceding **Builder** API constraints. Custom or preset components are combined in declarative mode in the build method. The **build** API is called when a component is created or updated.


```ts
interface Builder {
    build: () => void
}
```


> **NOTE**
>
> The build method supports only composite components and uses the rendering control syntax.
