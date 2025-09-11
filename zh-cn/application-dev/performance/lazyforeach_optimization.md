# 正确使用LazyForEach优化

LazyForEach懒加载从提供的数据源中按需迭代数据，并在每次迭代过程中创建相应的组件。当LazyForEach在滚动容器中使用时，框架会根据滚动容器可视区域按需创建组件，当组件划出可视区域外时，框架会进行组件销毁回收以降低内存占用。LazyForEach提供列表数据按需加载能力，解决一次性加载长列表数据耗时长、占用过多资源的问题，可以提升页面响应速度。

如何正确使用LazyForEach优化应用性能，请参考：[LazyForEach：数据懒加载](../ui/rendering-control/arkts-rendering-control-lazyforeach.md)