# 文件访问规则
应用代码中文件访问方法主要有下面两种：

- **相对路径**：使用相对路径引用代码文件，以"../"访问上一级目录，以"./"访问当前目录，也可以省略不写。

- **绝对路径**：使用当前模块根路径引用代码文件，比如：common/utils/utils。



## 示例
示例页面位于pages目录中，在pages同级目录common中存放utils，从示例xxx.ets访问utils.ets文件方法如下：
```ts
// xxx.ets
import { FoodData, FoodList } from "../common/utils/utils";

@Entry
@Component
struct FoodCategoryList {  
  private foodItems: FoodData[] = [    
    new FoodData("Tomato"),    
    new FoodData("Strawberry"),    
    new FoodData("Cucumber")  
  ]  
  build() {    
    Column() {      
      FoodList({ foodItems: this.foodItems })    
    }  
  }
}
```

被导入文件utils.ets：

```ts
//common/utils/utils.ets
export class FoodData {  
  name: string;  
  constructor(name: string) {    
    this.name = name;  
  }
}

@Component
export struct FoodList {  
  private foodItems: FoodData[]

  build() {    
    Column() {      
      Flex({justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center}) {        
        Text('Food List')          
          .fontSize(20)      
      }      
      .width(200)      
      .height(56)      
      .backgroundColor('#FFf1f3f5')      
      List() {        
        ForEach(this.foodItems, item => {          
          ListItem() {            
            Text(item.name)              
              .fontSize(14)          
          }        
        }, item => item.toString())      
      }    
    }  
  }
}
```