if ! [ -e "$1.c" ]; then
	echo "$1.c is no exist."
	exit 1
fi
filename="$1.c"
gcc $filename
./a.out
rm a.out
