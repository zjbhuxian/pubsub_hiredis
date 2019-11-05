CC=gcc
CFLAGS=-Wall -O -g
DFLAGS=-lhiredis -levent -lpthread
OBJS_SUB=sub.o redis_subscriber.o
OBJS_PUB=pub.o redis_publisher.o
TARGET_SUB=sub
TARGET_PUB=pub

all:$(TARGET_SUB) $(TARGET_PUB)

$(TARGET_SUB):$(OBJS_SUB)
	$(CC) $^ $(DFLAGS) -o $@

$(TARGET_PUB):$(OBJS_PUB)
	$(CC) $^ $(DFLAGS) -o $@

$(OBJS_SUB):%.o:%.c
	$(CC) -c $< $(CFLAGS) 

$(OBJS_PUB):%.o:%.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf *.o

clean_all:clean
	rm -rf $(TARGET_SUB) $(TARGET_PUB)
