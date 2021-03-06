#### 2.3.1 引用

**引用(reference)** 等于给对象起了另外一个名字。`&d` 定义一个引用类型，`d` 是声明的变量名。

**引用并非对象**，它只是为一个已经存在的对象所起的另外一个名字。定义引用时，引用将和它的初始值对象**绑定**在一起，因为无法令引用重新绑定到另外一个对象，所以引用**必须初始化**。

因为引用本身不是对象，所以不能定义引用的引用。

除*特殊情况*外，引用的类型要与绑定的对象严格匹配，而且，引用只能**绑定在对象**上，而**不能与某个字面值或某个表达式的运算结果绑定在一起**。

**特殊情况：**

1. 在初始化常量引用时允许用任意表达式作为初始值，只要该表达式的结果能转换成引用类型即可。尤其，允许常量引用绑定非常量的对象，字面值，一般表达式。

#### 2.3.2 指针

与引用类似，实现对其他对象的间接访问。但也有不同点:

- 指针本身是一个对象: 允许对指针赋值和拷贝
- 指针初始化可以不用赋值

- **指针值:** 指针存放某个对象的地址，用取址运算符`&`获取

  ```c++
  int ival = 32;
  int *p = &ival;
  ```

  `p` 存放变量`ival`的地址，也称作指向变量`ival`的指针。(`&`在这里是**取址**--引用不是对象，没有实际地址，所以不能定义指向引用的指针)

- **访问对象:** 解引用符 `*`

- **空指针:**

  - C++ 11: `nullptr` 初始化指针

### 2.4 const 限定符

const 类型的对象：只能执行不改变其内容的操作

- 拷贝

```c++
const int i = get_size(); # 正确：运行时初始化
```

```c++
int i = 42;
const int ci = i; # i的值被拷贝给了ci，用作ci的初始化
int j = ci; # 拷贝ci的值初始化j
```

拷贝一个对象并不会改变它，当拷贝完成，新的对象和原来的对象就没什么关系了。



如果想在多个文件之间共享 const 对象，必须在变量的定义之前添加 `extern` 关键字

```c++
extern const int bufSize
```



#### 2.4.1 const 引用

对常量的引用不能被用作修改它所绑定的对象。

```c++
const int ci = 2014;
const int &r1 = ci; // 引用及其对应的对象都是常量
r1 = 42; // 错误！是对常量的引用
int &r2 = ci; //错误！将一个非常量引用指向常量 -> 初始化错误
```

特殊情况

```c++
int i = 42;
const int &r1 = i; //允许常量引用绑定到普通int对象上
const int &r2 = 42; // 允许
const int &r3 = r1 * 2; // 允许
int &r4 = r1 * 2; // 不允许非常量引用绑定引用
```

对于 const 引用绑定到并非 const 的对象:

```c++
int i = 42;
int &r1 = i; //引用r1绑定i
const int &r2 = i;//引用r2也绑定i, 但是不允许通过r2修改i的值
r1 = 0;
r2 = 0; // 错误
```

