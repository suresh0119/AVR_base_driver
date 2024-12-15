
ROOT_DIR 	= /home/suresh/workspace/TWM_Tank_water_level_monitoring
BUILD_DIR 	= $(ROOT_DIR)/build
OBJECT_DIR 	= $(BUILD_DIR)/objects
SOURCE_DIR 	= $(ROOT_DIR)/AVR_base_driver

HEADER1		= -I $(SOURCE_DIR)/Drivers
HEADER2		= -I $(SOURCE_DIR)/Drivers/test_d


DRIVER_OBJECTS += $(OBJECT_DIR)/io.o
DRIVER_OBJECTS += $(OBJECT_DIR)/uart.o
DRIVER_OBJECTS += $(OBJECT_DIR)/init.o
DRIVER_OBJECTS += $(OBJECT_DIR)/interrupt.o
DRIVER_OBJECTS += $(OBJECT_DIR)/ring_buf.o


DRIVER_TARGETS += entry_driver
DRIVER_TARGETS += $(DRIVER_OBJECTS)
DRIVER_TARGETS += exit_driver


driver_target: $(DRIVER_TARGETS)  

entry_driver:
	$(info |---driver make entry...)

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/Drivers/%.c 
	@if $(CC) $(CFLAGS) $(CPU_HZ) $(LDFLAGS) $(HEADER1) -c -o $@ $<; then 	\
		echo "|---|---$@...compiled";										\
	else 																	\
		echo "|---|---$@...failed";											\
	fi

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/Drivers/test_d/%.c 
	@if $(CC) $(CFLAGS) $(CPU_HZ) $(LDFLAGS) $(HEADER2) -c -o $@ $<; then 	\
		echo "|---|---$@...compiled";										\
	else 																	\
		echo "|---|---$@...failed";											\
	fi

exit_driver:
	$(info |---driver make exit...)
	$(info |)