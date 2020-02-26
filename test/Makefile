TEST_BUILD_PATH := \
	./alib_test
	#./proto\
	#./test_server\
	#./testcases

.PHONY: build_test run_test

build_test:
	#make build_proto
	@for mod in $(TEST_BUILD_PATH); do\
		cd $$mod && make && cd -;\
	done

run_test:
	#../build/apps/Test
	../build/apps/AlibTest
