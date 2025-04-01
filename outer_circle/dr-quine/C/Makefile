include ../common/makefile.mk

CFLAGS = -Wall -Wextra -Werror

COLLEEN_SRC = Colleen.c

GRACE_SRC = Grace.c

SULLY_SRC = Sully.c

COLLEEN_SRCS = $(addprefix $(SRC_DIR), $(COLLEEN_SRC))

GRACE_SRCS = $(addprefix $(SRC_DIR), $(GRACE_SRC))

SULLY_SRCS = $(addprefix $(SRC_DIR), $(SULLY_SRC))

COLLEEN_OBJ = $(COLLEEN_SRCS:.c=.o)

GRACE_OBJ = $(GRACE_SRCS:.c=.o)

SULLY_OBJ = $(SULLY_SRCS:.c=.o)

all: $(COLLEEN_NAME) $(GRACE_NAME) $(SULLY_NAME)

$(COLLEEN_NAME): $(COLLEEN_OBJ)
	$(CC) $(CFLAGS) $(COLLEEN_OBJ) -o $(COLLEEN_NAME)

$(GRACE_NAME) : $(GRACE_OBJ)
	$(CC) $(CFLAGS) $(GRACE_OBJ) -o $(GRACE_NAME)

$(SULLY_NAME) : $(SULLY_OBJ)
	$(CC) $(CFLAGS) $(SULLY_OBJ) -o $(SULLY_NAME)

$(SRC_DIR)/%.o : $(SRC_DIR)/%.c 
	$(CC) $(CFLAGS) -c $< -o $@

test:
	make test_colleen
	make test_grace
	make test_sully

test_colleen: $(COLLEEN_NAME)
	@echo -e "$(YELLOW)$(BOLD)<-- Testing C_Colleen -->$(NC)"
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
	@if diff $(GRACE_KID_C) $(GRACE_SRCS) > /dev/null 2>&1; then \
		echo -e "$(GREEN)Files are equal$(NC) 😎\n"; \
	else \
		echo -e "$(RED)Files are different$(NC) 👎\n";\
		diff $(GRACE_KID_C) $(GRACE_SRCS); \
	fi

test_sully: $(SULLY_NAME)
	@$(SULLY_NAME)
	diff ./src/Sully.c Sully_0.c || true
	diff Sully_3.c Sully_2.c || true

clean:
	rm -rf ./src/*.o

fclean:
	make clean
	rm -rf $(COLLEEN_NAME) diff_file tmp_Colleen
	rm -rf $(GRACE_NAME) $(GRACE_KID_C)
	rm -rf $(SULLY_NAME)
	rm -rf Sully_*

re:
	make fclean
	make all

.PHONY: all test clean fclean re test_colleen test_grace