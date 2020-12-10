import os
from os.path import sep, join, realpath, isdir, isfile

Import("env")

env.Append(CPPPATH=[
    realpath(join("include", "freertos"))
])
