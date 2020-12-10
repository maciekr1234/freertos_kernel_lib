
import os,sys

from os.path import sep, join, realpath, isdir, isfile, dirname
from string import Template


root_dir = realpath(join(dirname(realpath(__file__)), ".."))
include_dir = join(root_dir, "include")

freertos_root_dir = join(root_dir, "freertos")
freertos_portable_dir = join(freertos_root_dir, "portable")


freertos_header_tpl = Template('#pragma once\n#include "../freertos/include/$name"\n')
freertos_src_tpl = Template('#include "../freertos/$name"\n')


freertos_include_names = [
"FreeRTOS.h",
"StackMacros.h",
"atomic.h",
"croutine.h",
"deprecated_definitions.h",
"event_groups.h",
"list.h",
"message_buffer.h",
"mpu_prototypes.h",
"mpu_wrappers.h",
"portable.h",
"projdefs.h",
"queue.h",
"semphr.h",
"stack_macros.h",
"stream_buffer.h",
"task.h",
"timers.h",
]

freertos_src_names = [
    "croutine.c",
"event_groups.c",
"list.c",
"queue.c",
"stream_buffer.c",
"tasks.c",
"timers.c",
]

def generate_freertos_header(name):
    file_path =  join(include_dir, name)
    if os.path.exists(file_path):
        os.remove(file_path)

    with open(file_path,"w") as header_file:
        header_file.write(freertos_header_tpl.substitute(name=name))

def generate_freertos_src(name):
    file_path =  join(root_dir, "src", name)
    if os.path.exists(file_path):
        os.remove(file_path)

    with open(file_path,"w") as f:
        f.write(freertos_src_tpl.substitute(name=name))


def main():
    for header in freertos_include_names:
        generate_freertos_header(header)

    for f in freertos_src_names:
        generate_freertos_src(f)

if __name__ == "__main__":
    sys.exit(main())
