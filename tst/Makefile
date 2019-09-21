PROJ_NAME=AppTest

SRCS=./main.c
#SRCS+=./ut_app.c
SRCS+=../app/src/app.c
SRCS+=./src/mock_pwm.c
SRCS+=./src/mock_adc.c
SRCS+=../Unity/unity.c

INC_DIRS=.
INC_DIRS=./inc
INC_DIRS+=../Unity
INC_DIRS+=../app/inc
INC_DIRS+=../hw/inc

CC=gcc

# Any compiler options you need to set
CFLAGS=-ggdb3
CFLAGS+=-O0
CFLAGS+=-Wall -Wextra -Warray-bounds

INCLUDE = $(addprefix -I,$(INC_DIRS))

.PHONY: $(PROJ_NAME)
$(PROJ_NAME): $(SRCS)
	$(CC) $(INCLUDE) $(DEFS) $(CFLAGS) $^ -o $@
#	$(CC) $(INCLUDE) $(DEFS) $(CFLAGS) $^ -o $@ $(LIBS) 
    
clean:
	rm -f *.o $(PROJ_NAME)
