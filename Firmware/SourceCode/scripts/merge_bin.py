output_filename = 'walking.bin'
num = 31
input_filenames = ['walking_{}.bin'.format(i) for i in range(num)]

with open(output_filename, 'wb') as outfile:
    for input_filename in input_filenames:
        with open(input_filename, 'rb') as infile:
            outfile.write(infile.read())
