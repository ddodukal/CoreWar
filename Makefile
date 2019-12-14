# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykliek <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 17:19:06 by ykliek            #+#    #+#              #
#    Updated: 2019/10/22 17:19:11 by ykliek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C asembler
	make -C vm

clean:
	make clean -C asembler
	make clean -C vm


fclean:
	make fclean -C asembler
	make fclean -C vm

re: fclean all

.PHONY:all clean fclean re
