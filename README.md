# pybind11_example
# pybind11教程
@[toc]
## 1. pybind11简介
pybind11 是一个轻量级的头文件库，用于在 Python 和 C++ 之间进行互操作。它允许 C++ 代码被 Python 调用，反之亦然。

pybind11 的优点包括：

- 易于使用：pybind11 的 API 简单易懂，即使是初学者也可以快速上手。
- 高性能：pybind11 使用 C++ 的编译器来生成 Python 的 C 扩展，因此性能非常高。
- 跨平台：pybind11 支持 Windows、Linux 和 macOS。

pybind11 的使用方法非常简单。只需在 C++ 代码中包含 pybind11 头文件，然后使用 pybind11 提供的 API 来将 C++ 类型和函数暴露给 Python。

## 2. cmake使用pybind11教程

这部分代码开源在：

```cmake
cmake_minimum_required(VERSION 3.6)
project(py11_t VERSION 0.1.0 LANGUAGES C CXX)

# 下载pybind11的代码
include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG v2.11.1
    )
FetchContent_MakeAvailable(pybind11)

# 设置pybind11绑定的python版本
set(PYBIND11_PYTHON_VERSION "3.10·")

# pybind11相关的代码将会写入到core文件夹内
add_subdirectory(core)
```


- 实现一个 `C++` 代码，然后通过 `pybind11` 包装给 `python`
```c++
#include"fun.hpp"
#include <pybind11/pybind11.h>
namespace py = pybind11;

PYBIND11_MODULE(cmake_example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    // 该方法在"fun.hpp"中实现
    m.def("add", &add, "A function that adds two numbers");
    // 该方法在"fun.hpp"中实现
    m.def("sayHi", &sayHi, "say hi");
    // 该方法由lamada表达式形成匿名函数实现
    m.def("hi", [](int i,int j) {return i + j;}, "xxx")
}
```

之后将上述代码进行编译，编译后会在`build`文件夹内生成python对应的库：
	![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/568617d4ed874d4db68b307848b7174c.png)

这个库就是python需要的,将库所在的路径，加入到系统环境变量中，这样就可以在python中间进行调用了。

```python
import os
import sys
sys.path.append("/Users/chendongsheng/github/py11/build/core")
sys.path.append("/Users/chendongsheng/github/py11/build/")
import cmake_example
cmake_example.sayHi()
print(cmake_example.hi(4,9))
print(cmake_example.add(1,2))

```

---
## 3. pybind11的历史


pybind11 诞生于 2017 年，由 Wenzel Jakob 开发。Wenzel Jakob 是一名来自德国的软件工程师，他曾在 Google 工作多年，参与开发了 TensorFlow 等项目。

Wenzel Jakob 在开发 TensorFlow 时，遇到了 C++ 和 Python 互操作的问题。当时，他尝试了各种 C++ 和 Python 互操作库，但都没有找到合适的。于是，他决定自己开发一个新的 C++ 和 Python 互操作库。

pybind11 的开发工作始于 2017 年 7 月，并于 2017 年 12 月发布了第一个版本。pybind11 的初始版本非常简单，只支持 C++ 基本类型和函数的互操作。

随着 pybind11 的不断开发，它逐渐支持了越来越多的 C++ 特性，包括：

- 类和对象
- 模板
- 继承
- 多态
- 异常处理
- 线程安全
- 动态类型

pybind11 的开发工作一直在进行中，Wenzel Jakob 和其他开发人员不断添加新的特性和功能。


pybind11 是一个非常强大的工具，可以用于各种任务。它可以用于将 C++ 代码与 Python 脚本集成，也可以用于创建 Python 的 C++ 扩展。**已经成为 C++ 和 Python 互操作领域的事实标准。**


## 关于与cmake结合的部分

无论是在cpp代码里设置的名字， 还是在cmake代码里设置的名字，都必须一致，否则python导包的时候就招不到包了。

```shell
PYBIND11_MODULE(cmake_example, m) {
pybind11_add_module(cmake_example fun_wrapper.cpp)
```

在 pybind11 中，一个 .cpp 文件中只能定义一个 PYBIND11_MODULE 模块。每个 PYBIND11_MODULE 宏定义了一个独立的 Python 模块，因此你不能在同一个 .cpp 文件中使用多个 PYBIND11_MODULE 宏来定义多个模块。

如果你需要定义多个 Python 模块，你应该将每个模块的实现放在不同的 .cpp 文件中，并在每个文件中使用 PYBIND11_MODULE 宏来定义相应的模块。

例如，如果你需要定义两个模块 module1 和 module2，你可以创建两个 .cpp 文件：
