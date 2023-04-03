# Building a Food Data Model

In real-world development, it is impractical to describe all aspects of food in code, including the food name and nutrition facts. This is where the food data model comes into the picture. With the food data model, you can store and manage data in a unified manner.


![en-us_image_0000001267767897](figures/en-us_image_0000001267767897.png)


1. Create a folder named **model** and create a file named **FoodData.ets** therein.

   ![en-us_image_0000001223127760](figures/en-us_image_0000001223127760.png)

2. Define a food data storage model, **FoodData**, and an enum variable, **Category**. The **FoodData** class contains **id**, **name**, **category**, **image**, **calories**, **protein**, **fat**, **carbohydrates**, and **vitaminC** attributes.
   The ArkTS programming language is an extension of the TS language and also supports the TS syntax.

   ```ts
   enum Category  {
     Fruit,
     Vegetable,
     Nut,
     Seafood,
     Dessert
   }

   let NextId = 0;
   class FoodData {
     id: string;
     name: string;
     image: Resource;
     category: Category;
     calories: number;
     protein: number;
     fat: number;
     carbohydrates: number;
     vitaminC: number;

     constructor(name: string, image: Resource, category: Category, calories: number, protein: number, fat: number, carbohydrates: number, vitaminC: number) {
       this.id = `${ NextId++ }`;
       this.name = name;
       this.image = image;
       this.category = category;
       this.calories = calories;
       this.protein = protein;
       this.fat = fat;
       this.carbohydrates = carbohydrates;
       this.vitaminC = vitaminC;
     }
   }
   ```

3. Store food images in the **resources** > **base** > **media** directory. Use food names as the image names.

4. Create food resource data. Create **FoodDataModels.ets** in the **model** folder and declare the food composition array **FoodComposition** on the page. The following example creates two pieces of food data.

   ```ts
   const FoodComposition: any[] = [
     { 'name': 'Tomato', 'image': $r('app.media.Tomato'), 'category': Category.Vegetable, 'calories': 17, 'protein': 0.9, 'fat': 0.2, 'carbohydrates': 3.9, 'vitaminC': 17.8 },
     { 'name': 'Walnut', 'image': $r('app.media.Walnut'), 'category': Category.Nut, 'calories': 654 , 'protein': 15, 'fat': 65, 'carbohydrates': 14, 'vitaminC': 1.3 }
     ]
   ```

   In real-world development, you can customize more data resources when needed. Use [Lazy Loading](../quick-start/arkts-rendering-control.md#lazy-loading) to load data if a large amount of food data is involved. 

5. Create the **initializeOnStartUp** method to initialize the **FoodData** array. Export the **FoodData** class from **FoodData.ets**, and import **FoodData** and **Category** in **FoodDataModels.ets**.
   ```ts
   // FoodData.ets
   export enum Category {
    ......
   }
   export class FoodData {
     ......
   }
   // FoodDataModels.ets
   import { Category, FoodData } from './FoodData'

   export function initializeOnStartup(): Array<FoodData> {
     let FoodDataArray: Array<FoodData> = []
     FoodComposition.forEach(item => {
       FoodDataArray.push(new FoodData(item.name, item.image, item.category, item.calories, item.protein, item.fat, item.carbohydrates, item.vitaminC ));
     })
     return FoodDataArray;
   }
   ```


The data resources for the diet application are now ready. You can continue to create a food category list by loading the data.
