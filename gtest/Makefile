# Test suites directories
SUBDIRS = $(shell ls -d */ | grep TEST_)

.PHONY: test testclean

test: make_dirs
	$(info gtest::test...)
# Iterate through components folders and make test target
	list='$(SUBDIRS)'; \
	for subdir in $$list; do \
		$(MAKE) -C $$subdir test; \
	done;


testclean:
	list='$(SUBDIRS)'; \
	for subdir in $$list; do \
		$(MAKE) -C $$subdir testclean; \
	done;
	rm -rf stubs/obj
	rm -rf mocks/obj
	rm -rf object_mocks/obj
