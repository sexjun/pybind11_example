#!/bin/bash

cpp_schema_gen="$(dirname $0)/../core/include/"
python_schema_gen="$(dirname $0)/../python/"

script_path=$(dirname "$0")/../ir/schema/cds.fbs

echo ${script_path}

# gen cpp header
flatc --cpp -o "${cpp_schema_gen}" ${script_path}

# gen python header
flatc --python -o "${python_schema_gen}" ${script_path}
