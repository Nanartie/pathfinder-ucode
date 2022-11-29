NAME = pathfinder

CFLG = -std=c11 $(addprefix -W, all extra error pedantic) -gdwarf-4

SRCDIR	= src
INCDIR	= inc
OBJDIR	= obj

INCSOURCE = $(wildcard $(INCDIR)/*.h)
SRCSOURCE = $(wildcard $(SRCDIR)/*.c)
OBJSOURCE = $(addprefix $(OBJDIR)/, $(notdir $(SRCSOURCE:%.c=%.o)))

LMXDIR	= libmx
LMXA:=	$(LMXDIR)/libmx.a
LMXINC:= $(LMXDIR)/inc

all: install

install: $(LMXA) $(NAME)

$(NAME): $(OBJSOURCE)
	@clang $(CFLG) $(OBJSOURCE) -L$(LMXDIR) -lmx -o $@
	@printf "\r\33[2K$@ \033[32;1mcreated\033[0m\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCSOURCE)
	@clang $(CFLG) -c $< -o $@ -I$(INCDIR) -I$(LMXINC)
	@printf "\r\33[2K$(NAME) \033[33;1mcompile \033[0m$(<:$(SRCDIR)/%.c=%) "

$(OBJSOURCE): | $(OBJDIR)

$(OBJDIR):
	@mkdir -p $@

$(LMXA):
	@make -sC $(LMXDIR)
	
clean:
	@rm -rf $(OBJDIR)
	@printf "$(OBJDIR) in $(NAME) \033[31;1mdeleted\033[0m\n"

uninstall:
	@make -sC $(LMXDIR) $@
	@rm -rf $(OBJDIR)
	@rm -rf $(NAME)
	@printf "$(NAME) \033[31;1muninstalled\033[0m\n"

reinstall: uninstall all
