# struct<a name="EN-US_TOPIC_0000001157388847"></a>

Components can be implemented based on  **struct**s. Components cannot inherit from each other. The  **struct**s implemented components can be created and destroyed more quickly than  **class**  implemented components.

```
@Component
struct MyComponent {
    @State data: string = ''

    build() {
    }
}
```

