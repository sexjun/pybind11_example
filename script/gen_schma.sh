#!/bin/bash

cpp_schema_gen="$(dirname $0)/../core/include/"
python_schema_gen="$(dirname $0)/../python/"

# gen cpp header
flatc --cpp -o "${cpp_schema_gen}" /Users/chendongsheng/github/py11/ir/schema/cds.fbs

# gen python header
flatc --python -o "${python_schema_gen}" /Users/chendongsheng/github/py11/ir/schema/cds.fbs
