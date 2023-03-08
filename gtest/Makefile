#########################################################
# Copyright (C) 2021 Continental AG and subsidiaries
# All rights reserved.
#########################################################

export COVERAGE_LOCAL_REPORT_DIRECTORY := $(shell pwd)/reports/
COVERAGE_PROJECT_REPORT_DIRECTORY = $(COVERAGE_REPORT_DIRECTORY)/

# Test suites directories
SUBDIRS = $(shell ls -d */ | grep TEST_)

.PHONY: test testclean

test: make_dirs
	$(info gtest::test...)
# Remove global coverage file
	\rm -f $(COVERAGE_LOCAL_REPORT_DIRECTORY)coverage.info
# Iterate through components folders and make test target
	list='$(SUBDIRS)'; \
	for subdir in $$list; do \
		$(MAKE) -C $$subdir test; \
	done;
# Copy python scripts into local report directory
	\cp -f *.py $(COVERAGE_LOCAL_REPORT_DIRECTORY)
# Call script
	cd $(COVERAGE_LOCAL_REPORT_DIRECTORY) && python3 gen-coverage.py && cd ..
# Copy tests summary from local to project report directory
	\cp -f $(COVERAGE_LOCAL_REPORT_DIRECTORY)*.json $(COVERAGE_PROJECT_REPORT_DIRECTORY)
# Copy coverage page from local to project report directory
	\cp -R $(COVERAGE_LOCAL_REPORT_DIRECTORY)/coverage_html $(COVERAGE_PROJECT_REPORT_DIRECTORY)

make_dirs:
	mkdir -p $(COVERAGE_LOCAL_REPORT_DIRECTORY)
	mkdir -p $(COVERAGE_PROJECT_REPORT_DIRECTORY)

testclean:
	list='$(SUBDIRS)'; \
	for subdir in $$list; do \
		$(MAKE) -C $$subdir testclean; \
	done;
	rm -rf stubs/obj
	rm -rf mocks/obj
	rm -rf object_mocks/obj
	rm -rf $(COVERAGE_LOCAL_REPORT_DIRECTORY)
	rm -rf $(COVERAGE_PROJECT_REPORT_DIRECTORY)
