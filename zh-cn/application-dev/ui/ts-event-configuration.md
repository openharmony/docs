# 事件配置

通过事件方法可以配置组件支持的事件。


- 使用lambda表达式配置组件的事件方法：
  ```
  // Counter is a private data variable defined in the component.
  Button('add counter')
      .onClick(() => {
          this.counter += 2
      })
  ```


- 使用匿名函数表达式配置组件的事件方法，要求使用bind，以确保函数体中的this引用包含的组件：
  ```
  // Counter is a private data variable defined in the component.
  Button('add counter')
      .onClick(function () {
          this.counter += 2
      }.bind(this))
  ```


- 使用组件的成员函数配置组件的事件方法：
  ```
  myClickHandler(): void {
      // do something
  }
  
  ...
  
  Button('add counter')
    .onClick(this.myClickHandler)
  ```
