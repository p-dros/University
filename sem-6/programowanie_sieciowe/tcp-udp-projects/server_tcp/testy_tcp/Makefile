.PHONY: all clean

all: $(basename $(wildcard *.test))

%:
	@socat -t 0.1 stdio tcp4:127.0.0.1:2020 < $@.test > $@.result
	@diff -q $@.result $@.expected
	@echo "$@ - success"

clean:
	rm $(wildcard *.result)
