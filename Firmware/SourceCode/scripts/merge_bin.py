output_filename = 'walking.bin'
input_filenames = ['walking_{}.bin'.format(i) for i in range(27)]

with open(output_filename, 'wb') as outfile:
    for input_filename in input_filenames:
        with open(input_filename, 'rb') as infile:
            outfile.write(infile.read())
