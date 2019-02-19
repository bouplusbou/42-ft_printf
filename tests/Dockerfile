FROM debian

RUN apt update -y \
	&& apt upgrade -y \
	&& apt install apt-utils -y \
	&& apt install git -y \
	&& apt install vim -y \
	&& apt install gcc -y \
	&& apt install make -y \
	&& git clone https://github.com/bouplusbou/42-ft_printf.git \
	&& git clone https://github.com/bclaudios/Printester.git