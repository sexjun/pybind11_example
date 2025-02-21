import os
import sys

from pathlib import Path

buid_path = Path(__file__).parent.parent / "build/core"

sys.path.append(str(buid_path))
sys.path.append(str(buid_path.parent))


import cmake_example

cmake_example.sayHi()
print(cmake_example.hi(4, 9))
print(cmake_example.add(1, 2))
