import os
import sys

sys.path.append("/Users/chendongsheng/github/py11/build/core")
sys.path.append("/Users/chendongsheng/github/py11/build/")

import cmake_example

cmake_example.sayHi()
print(cmake_example.hi(4,9))
print(cmake_example.add(1,2))



# import example
# p = example.Pet("Molly")
# print(p.getName())
