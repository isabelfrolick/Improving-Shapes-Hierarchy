# Improved Shapes Hierarchy (C++)

The goal is to enable elegant iteration over a collection of shapes without large conditional blocks, while preserving the same output as the original test program.

---

### Base Shape Class
- All shapes have:
  - `length` (int)  
  - `width` (int)  
  - `borderColor` (string)  
- Public virtual destructor ensures proper cleanup
- Pure virtual `drawOutline()` function implemented in derived classes

### Specialized Traits via Multiple Inheritance
- **Fillable** — adds `fillColor` (string) and `fill()` method  
- **Labelable** — adds `text` (string) and `drawText()` method  
- Only shapes that support filling or labels inherit from these classes

### Concrete Shape Classes
- Examples: `Square`, `Rectangle`, `TextBox`  
- Each class:
  - Implements `drawOutline()`  
  - Implements `fill()` if fillable  
  - Implements `drawText()` if labelable  
  - Provides its own destructor (empty implementation)

### Polymorphic Drawing
- `TestGoodShapes.cpp` iterates over `Shape*` objects:  

```cpp
for (Shape* shape : shapes) {
    shape->drawOutline();
    shape->fill();     // only if Fillable
    shape->drawText(); // only if Labelable
}
```
---

### To run:
```bash
g++ -std=c++11 ShapesGood.cpp TestGoodShapes.cpp -o shapes
./shapes
```
