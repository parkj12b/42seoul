include ../common/makefile.mk

COLLEEN_SRC = Colleen.s

GRACE_SRC = Grace.s

SULLY_SRC = Sully.s

COLLEEN_SRCS = $(addprefix $(SRC_DIR), $(COLLEEN_SRC))

GRACE_SRCS = $(addprefix $(SRC_DIR), $(GRACE_SRC))

SULLY_SRCS = $(addprefix $(SRC_DIR), $(SULLY_SRC))

COLLEEN_OBJ = $(COLLEEN_SRCS:.s=.o)

GRACE_OBJ = $(GRACE_SRCS:.s=.o)

SULLY_OBJ = $(SULLY_SRCS:.s=.o)

CFLAGS = -Wall -Wextra -Werror -z noexecstack -lc

ASM_FLAGS = -g -f elf64

ASMC = nasm

all : $(COLLEEN_NAME) $(GRACE_NAME) $(SULLY_NAME)

$(COLLEEN_NAME) : $(COLLEEN_OBJ)
	$(CC) $(CFLAGS) $(COLLEEN_OBJ) -o $(COLLEEN_NAME)

$(GRACE_NAME) : $(GRACE_OBJ)
	$(CC) $(CFLAGS) $(GRACE_OBJ) -o $(GRACE_NAME)

$(SULLY_NAME) : $(SULLY_OBJ)
	$(CC) $(CFLAGS) $(SULLY_OBJ) -o $(SULLY_NAME)

%.o: %.s
	$(ASMC) $(ASM_FLAGS) $< -o $@

test: 
	make test_colleen
	make test_grace

test_colleen: $(COLLEEN_NAME)
	@echo -e "$(YELLOW)$(BOLD)<-- Testing ASM_Colleen -->$(NC)"
	./$(COLLEEN_NAME) > $(COLLEEN_STDOUT)
	@if diff $(COLLEEN_STDOUT) $(COLLEEN_SRCS) > /dev/null 2>&1; then \
		echo -e "$(GREEN)Files are equal$(NC) 😎\n"; \
	else \
		echo -e "$(RED)Files are different$(NC) 👎\n";\
		diff $(COLLEEN_STDOUT) $(COLLEEN_SRCS); \
	fi

test_grace: $(GRACE_NAME)
	@./$(GRACE_NAME)
	@echo -e "$(YELLOW)$(BOLD)<-- Testing C_Grace -->$(NC)"
	@if diff $(GRACE_KID_ASM) $(GRACE_SRCS) > /dev/null 2>&1; then \
		echo -e "$(GREEN)Files are equal$(NC) 😎\n"; \
	else \
		echo -e "$(RED)Files are different$(NC) 👎\n";\
		diff $(GRACE_KID_ASM) $(GRACE_SRCS); \
	fi

test_sully: $(SULLY_NAME)
	@$(SULLY_NAME)
	diff ./src/Sully.s Sully_0.s || true
	diff Sully_3.s Sully_2.s || true

re:
	make fclean
	make all

clean:
	rm -rf $(SRC_DIR)/*.o

fclean:
	make clean
	rm -rf $(COLLEEN_NAME) diff_file tmp_Colleen
	rm -rf $(GRACE_NAME) $(GRACE_KID_ASM)
	rm -rf $(SULLY_NAME) Sully*

.PHONY: all clean fclean re test