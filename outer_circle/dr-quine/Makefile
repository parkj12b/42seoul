NAME: dr-quine

all : $(NAME)

MAKEFLAGS += --no-print-directory

$(NAME):
	$(MAKE) -C ./C
	$(MAKE) -C ./ASM

clean:
	$(MAKE) clean -C ./C 
	$(MAKE) clean -C ./ASM 

fclean:
	$(MAKE) fclean -C ./C
	$(MAKE) fclean -C ./ASM

re:
	$(MAKE) re -C ./C
	$(MAKE) re -C ./ASM

test:
	$(MAKE) -C ./C test
	$(MAKE) -C ./ASM test

.PHONY: all clean fclean re test $(NAME)
