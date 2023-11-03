# LazyForEach Usage

**LazyForEach** iterates over provided data sources and creates corresponding components during each iteration. When **LazyForEach** is used in a scrolling container, the framework creates components as required within the visible area of the scrolling container. When a component is out of the visible area, the framework destroys and reclaims the component to reduce memory usage. Proper use of **LazyForEach** can effectively improve page load speeds, by shortening the length of data loaded at once and minimizing resource usage.

For details about how to use **LazyForEach** to optimize application performance, see [LazyForEach: Lazy Data Loading](../quick-start/arkts-rendering-control-lazyforeach.md).
