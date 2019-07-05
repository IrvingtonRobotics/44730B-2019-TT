CSRCS += hello_world.c

DEPPATH += --dep-path $(LVGL_DIR)C:\Users\sande\44730B-2019-TT\src
VPATH += :$(LVGL_DIR)/lv_examples/lv_tutorial/1_hello_world

CFLAGS += "-I$(LVGL_DIR)/lv_examples/lv_tutorial/1_hello_world"
