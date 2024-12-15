
ROOT_DIR 	= /home/suresh/workspace/TWM_Tank_water_level_monitoring
BUILD_DIR 	= $(ROOT_DIR)/build
OBJECT_DIR 	= $(BUILD_DIR)/objects
SOURCE_DIR 	= $(ROOT_DIR)/AVR_base_driver


DRIVER_OBJECTS += $(OBJECT_DIR)/d1.o
DRIVER_OBJECTS += $(OBJECT_DIR)/d2.o
DRIVER_OBJECTS += $(OBJECT_DIR)/d3.o
DRIVER_OBJECTS += $(OBJECT_DIR)/d4.o


DRIVER_TARGETS += entry_driver
DRIVER_TARGETS += $(DRIVER_OBJECTS)
DRIVER_TARGETS += exit_driver


driver_target: $(DRIVER_TARGETS)  

entry_driver:
	$(info |---driver make entry...)

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/Drivers/%.c 
	@if $(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $<; then 	\
		echo "|---|---$@...compiled";					\
	else 												\
		echo "|---|---$@...failed";						\
	fi

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/Drivers/test_d/%.c 
	@if $(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $<; then 	\
		echo "|---|---$@...compiled";					\
	else 												\
		echo "|---|---$@...failed";						\
	fi

exit_driver:
	$(info |---driver make exit...)