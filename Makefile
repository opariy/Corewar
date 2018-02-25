NAME = asm corewar
vm_dir = vm/
asm_dir = asmbl/

all:
	@make $(NAME)

corewar::
	@make -C $(vm_dir)
	@cp $(vm_dir)/corewar .

asm:
	@make -C $(asm_dir)
	@cp $(asm_dir)/asm .

clean:
	@make -C $(asm_dir) clean
	@make -C $(vm_dir) clean

fclean:
	@make -C $(asm_dir) fclean
	@make -C $(vm_dir) fclean
	@rm -f asm
	@rm -f corewar

re: fclean all

