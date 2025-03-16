## Please use configure script
MAKEFLAGS += --silent

all	: do_configure

do_configure	:
	@./configure >/dev/null 2>&1

clean	:
	@./configure clean >/dev/null 2>&1

re	: clean all
