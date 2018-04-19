cmake_minimum_required(VERSION 3.9)
project(PRINTF)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ")
file(GLOB INC_LIB ./libft/*.h)
file(GLOB INC_PRO ./*.h)
file(GLOB SRC ./*.c)
file(GLOB SRCS_LIB ./libft/*.c)
set(INC ${INC_LIB} ${INC_PRO})
set(LIBFT ${SRCS_LIB} ft_printf.h ft_printf.h print_d.c libft/ft_count_num.c)
include_directories("./libft/" "./")

add_executable(PRINTF ${INC} ${LIBFT} ${SRC})

#cmake_minimum_required(VERSION 3.9)
#project(GNL)INTF_CLION main.c)