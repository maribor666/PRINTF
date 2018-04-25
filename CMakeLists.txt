cmake_minimum_required(VERSION 3.9)
project(PRINTF)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall  -Wextra")
file(GLOB INC_LIB ./libft/*.h)
file(GLOB INC_PRO ./*.h)
file(GLOB SRC ./print_d.c ./print_o.c ./print_x.c ./print_u.c ./print_p.c ./main.c )
file(GLOB SRCS_LIB ./libft/*.c)
set(INC ${INC_LIB} ${INC_PRO})
set(LIBFT ${SRCS_LIB} ft_printf.h ft_printf.h print_d.c libft/ft_count_num.c print_o.c print_x.c print_u.c)
include_directories("./libft/" "./")

add_executable(PRINTF ${INC} ${LIBFT} ${SRC})

#cmake_minimum_required(VERSION 3.9)
#project(GNL)INTF_CLION main.c)