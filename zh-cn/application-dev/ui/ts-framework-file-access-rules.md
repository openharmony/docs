# 应用代码文件访问规则

应用代码文件可通过如下方式访问：


- 使用相对路径引用代码文件，比如：上一级目录：../common/utils/utils.ets，当前目录：./common/utils/utils.ets。

- 使用当前模块根路径引用代码文件，比如：common/utils/utils.ets。

- 公共代码文件推荐放在**common**目录下。


## 示例

```
import { FoodData, FoodList } from "../common/utils/utils.ets";

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

导入文件示例：

```
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
