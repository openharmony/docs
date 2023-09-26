# Best Practices for Application Performance

This topic outlines some best practices for improving your application performance to live up to user expectations for quick startup, timely response, and no frame freezing.

Following these practices, you can reduce your application's startup time, response time, and frame loss.

- Improving application startup and response time

  - [Speeding Up Application Cold Start](../performance/improve-application-startup-and-response/improve-application-cold-start-speed.md)

      Application startup latency is a key factor that affects user experience. To speed up the application cold start, you are advised to perform optimization in the following four phases:

      ​	1. Application process creation and initialization

      ​	2. Application and ability initialization

      ​	3. Ability lifecycle

      ​	4. Home page loading and drawing

  - [Speeding Up Application Response](../performance/improve-application-startup-and-response/improve-application-response.md)

     A premium interaction experience requires quick response to user input. To improve your application's response time, you are advised to prevent the main thread from being blocked by non-UI tasks and reduce the number of component to be refreshed.

- Reducing frame loss

  - [Reducing Nesting](../performance/reduce-frame-loss-and-frame-freezing/reduce-view-nesting-levels.md)

     The smoothness of rendering the layout to the screen affects the user perceived quality. It is recommended that you minimize nesting in your code to shorten the render time.

  - [Reducing Frame Loss](../performance/reduce-frame-loss-and-frame-freezing/reduce-animation-frame-loss.md)
  
      Whether animations in your application run smoothly is a key factor that affects user experience. You are advised to use the system-provided animation APIs to reduce frame loss.
