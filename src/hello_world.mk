CSRCS += hello_world.c

DEPPATH += --dep-path $(LVGL_DIR)\44730B-2019-TT\src
VPATH += :$(LVGL_DIR)\44730B-2019-TT\src

CFLAGS += "-I$(LVGL_DIR)\44730B-2019-TT\src"
