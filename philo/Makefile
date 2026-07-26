NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INC_FILES = philo.h
INC = $(addprefix $(INC_DIR), $(INC_FILES))

OBJ_DIR = obj/
SRC_DIR = src/
INC_DIR = inc/
PHILO_DIR := philo/
UTILS_DIR := utils/

SRC_FILES := $(SRC_DIR)main.c \
			 $(SRC_DIR)$(UTILS_DIR)utils.c \
			 $(SRC_DIR)$(UTILS_DIR)utils_philo.c \
			 $(SRC_DIR)$(PHILO_DIR)philo_routine.c \
			 $(SRC_DIR)$(PHILO_DIR)philo_monitoring.c \
			 $(SRC_DIR)$(PHILO_DIR)philo_struct.c \
			 $(SRC_DIR)$(PHILO_DIR)error_manager.c \

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))


all : $(OBJ_DIR).compiled $(NAME)

$(OBJ_DIR).compiled:
	@echo ""
	@printf "%s\n" "   ___ _     _ _                       _                    "
	@printf "%s\n" "  / _ \ |__ (_) | ___  ___  ___  _ __ | |__   ___ _ __ ___  "
	@printf "%s\n" " / /_)/ '_ \| | |/ _ \/ __|/ _ \| '_ \| '_ \ / _ \ '__/ __| "
	@printf "%s\n" "/ ___/| | | | | | (_) \__ \ (_) | |_) | | | |  __/ |  \__ \ "
	@printf "%s\n" "\/    |_| |_|_|_|\___/|___/\___/| .__/|_| |_|\___|_|  |___/ "
	@printf "%s\n" "                                |_|                         "
	@echo ""
	@echo ""

$(OBJ_DIR).running:
	@mkdir -p $(OBJ_DIR)
	@touch $(OBJ_DIR).running
	@echo ""
	@printf "%s\n" "   ___ _     _ _                       _                    "
	@printf "%s\n" "  / _ \ |__ (_) | ___  ___  ___  _ __ | |__   ___ _ __ ___  "
	@printf "%s\n" " / /_)/ '_ \| | |/ _ \/ __|/ _ \| '_ \| '_ \ / _ \ '__/ __| "
	@printf "%s\n" "/ ___/| | | | | | (_) \__ \ (_) | |_) | | | |  __/ |  \__ \ "
	@printf "%s\n" "\/    |_| |_|_|_|\___/|___/\___/| .__/|_| |_|\___|_|  |___/ "
	@printf "%s\n" "                                |_|                         "
	@echo ""
	@echo ""


$(NAME) : $(OBJ)
	@touch $(OBJ_DIR).compiled
	@echo "🍝 Compilation of Philo finished !"
	@${CC} ${CFLAGS} -I ${INC} -o ${NAME} ${OBJ}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

clean : $(OBJ_DIR).running
	@echo "👉🗑️ Cleaning all .o files !"
	@rm -rf $(OBJ_DIR)

fclean : $(OBJ_DIR).running clean
	@echo "💥 Deleting Minishell"
	@rm -rf $(NAME)

re : $(OBJ_DIR).running fclean $(NAME)
	@rm -f $(OBJ_DIR).running

.PHONY : all clean fclean re
