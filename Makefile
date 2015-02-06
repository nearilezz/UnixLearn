TAG = a.out
SOURCES = $(wildcard *.c)
OBJS := $(patsubst %.c, %.o, $(SOURCES))

$(TAG): $(OBJS)
	@echo "source files:" $(SOURCES)
	@echo "object files:" $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(TAG)

sinclude $(SOURCES:.c=.d)

%d: %c
	@echo "create depend"
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ ,g' < $@.$$$$ > $@; \
	$(RM) $@.$$$$

.PHONY : clean
clean:
	rm -rf $(OBJS)
	rm -f $(TAG)