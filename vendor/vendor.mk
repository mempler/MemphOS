BUILD=bin
TMP_BUILD=build

all : clean make_dirs 

clean :
	@rm -rf $(BUILD)
	@rm -rf $(TMP_BUILD)

make_dirs : clean
	@mkdir $(BUILD)
	@mkdir $(TMP_BUILD)

