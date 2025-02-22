import os
import sys

from pathlib import Path

buid_path = Path(__file__).parent.parent / "build/core/python_wrapper"

sys.path.append(str(buid_path))
sys.path.append(str(buid_path.parent))


import cpp_py_example

cpp_py_example.sayHi()
print(cpp_py_example.hi(4, 9))
print(cpp_py_example.add(1, 2))


import obj_wrapper

p = obj_wrapper.Pet("cds")
print(p.getName())
p.setName("测试")
print(p.getName())
