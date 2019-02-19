docker build -t printester-img . \
&& docker run -it --name=printester-cont printester-img bash \