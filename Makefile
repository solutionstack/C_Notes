CC = gcc
CFLAGS = -O1 -fhardened -Wpedantic -Wall -Wextra -fsanitize=address
LDFLAGS = -fsanitize=address

DIN_PHIL_DIR = ./Threads/din_ph
DIN_PHIL_EXEC = $(addprefix $(DIN_PHIL_DIR)/, din_phil)
din_ph : $(DIN_PHIL_EXEC)
DIN_PHIL_OBJECTS= $(patsubst $(DIN_PHIL_DIR)/%.c, $(DIN_PHIL_DIR)/%.o, $(wildcard $(DIN_PHIL_DIR)/*.c))
$(DIN_PHIL_EXEC):$(DIN_PHIL_OBJECTS)
	@echo Building.. ${DIN_PHIL_OBJECTS}
	$(CC)  -o $@ $^ $(LDFLAGS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(DIN_PHIL_EXEC) $(DIN_PHIL_OBJECTS)
