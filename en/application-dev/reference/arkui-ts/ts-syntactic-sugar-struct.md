# struct<a name="EN-US_TOPIC_0000001157388847"></a>

Components can be implemented based on  **structs**. Components cannot inherit from each other. The  **struct**  implemented components can be created and destroyed more quickly than  **class**  implemented components.

```
@Component
struct MyComponent {
    @State data: string = ''

    build() {
    }
}
```

