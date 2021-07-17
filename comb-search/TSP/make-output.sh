input_files=($(find . -name "input*txt"))
for file in ${input_files[@]};
do
	./dpdp ${file} ${file/input/output}
done